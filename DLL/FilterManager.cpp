/*
* OSPE - Open Source Packet Editor
* Copyright(C) 2018  Javier Pereda <https://github.com/elecyb>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stdafx.h"
#include "FilterManager.h"

Filter _filterList[50];
UINT8 filterCount = 0;

void CovertBytesToFilterList(char * readData)
{
	/*
	| SCODE   |  FilterCount  |            filter Data                |
	|  1-byte |      1-byte   |--------   3010-bytes -----------------|
	| -------------------------- readData ----------------------------|

	Filter data representation:

	| enabled |  Mode  | captureFuncsFlags | actions | lenMin  | lenMax  | numApply | searchCount |         search       | replacesCount |        replace       |
	|  1-byte | 1-byte |       2-bytes     |  1-bye  |  2-byes |  2-byes |  2-bytes |  2-bytes    | ----- 1500-bytes ----|     2-bytes   | ----  1500-bytes ----|
	| ---------------------------------------- filterData ------------------------------------------------------------------------------------------------------|
	*/
	// Maximo 50 filtros
	filterCount = readData[1];
	int pos = 2; // el byte 0 era el ServerCode y el 1 al filtercount
	for (int i = 0; i < filterCount; i++) {
		_filterList[i].Active = readData[pos]; // enabled
		_filterList[i].Mode = (FilterModes)readData[pos + 1]; // Mode
		memcpy(&_filterList[i].Functions, &readData[pos + 2], 2); // captureFuncsFlags
		_filterList[i].Actions = (FilterActions)readData[pos + 4]; // actions
		memcpy(&_filterList[i].PacketLengthMin, &readData[pos + 5], 2); // lenMin
		memcpy(&_filterList[i].PacketLengthMax, &readData[pos + 7], 2); // lenMax
		memcpy(&_filterList[i].NumTimesApply, &readData[pos + 9], 2); // numApply
		int count, key; char val;
		_filterList[i].searches.clear();
		count = (((UINT8)readData[pos + 12] << 8) | (UINT8)readData[pos + 11]); // searchCount
		for (int j = 0; j < count; j++) {
			key = (((UINT8)readData[pos + 14 + (j * 3)] << 8) | (UINT8)readData[pos + 13 + (j * 3)]); // search key
			val = readData[pos + 15 + (j * 3)]; // search val
			_filterList[i].searches.insert(std::make_pair(key, val));
		}
		_filterList[i].replaces.clear();
		count = (((UINT8)readData[pos + 1514] << 8) | (UINT8)readData[pos + 1513]); // replaceCount
		for (int j = 0; j < count; j++) {
			key = (((UINT8)readData[pos + 1516 + (j * 3)] << 8) | (UINT8)readData[pos + 1515 + (j * 3)]); // search key
			val = readData[pos + 1517 + (j * 3)]; // search val
			_filterList[i].replaces.insert(std::make_pair(key, val));
		}
		pos = pos + FILTERINBYTESSIZE;
	}
}

bool CheckIfBetweenLength(Filter f, UINT16 pSize)
{
	if (f.PacketLengthMax != 0)
		return (pSize >= f.PacketLengthMin && pSize <= f.PacketLengthMax);
	return true;
}

bool FilterMeetConditions(Filter filter, UINT16 packetSize, FilterCaptureFuncs functionFlag)
{
	if ((filter.Active) &&
		(CheckIfBetweenLength(filter, packetSize)) && // El filtro tiene length y tiene que estar dentro del lengthMin y lengthMax
		(filter.Functions&(functionFlag) != 0) && // Debe ser alguna de las funciones del filtro
		(filter.searches.size() == 0 || filter.searches.crbegin()->first < packetSize)) // El ultimo offset se pasa del tamaño del packet
		return true;
	return false;
}

bool AllSearchOffsetMatch(char * data, UINT16 len, Filter filter, int * pos)
{
	if (filter.Mode == FilterModes::SearchAndReplaceFromBegin)
	{
		for (auto rit = filter.searches.begin(); rit != filter.searches.end(); ++rit)
		{
			if (rit->second != data[rit->first])
				return false;
		}
		return true;
	}
	if (filter.Mode == FilterModes::SearchOcurrenceReplaceFromBegin || filter.Mode == FilterModes::SearchOcurrenceReplaceFromPosition)
	{
		for (int i = 0; i<len; i++)
		{
			bool shouldContinue = false;
			for (auto rit = filter.searches.begin(); rit != filter.searches.end(); ++rit)
			{
				if (rit->first + i > len - 1) // El offset actual de search se pasa del len del packet, NO HAY MATCH
					return false;
				if (data[rit->first + i] != rit->second) // Los datos del offset no coinciden
				{
					shouldContinue = true; // Debemos continuar, hay q incrementar i y probar desde el siguiente valor de i
					break; // Break foreach, uno de los offsets no coincide, no hace falta ver los demas
				}
			}
			if (shouldContinue) continue;
			(*pos) = i;
			return true;
		}
		return false; // No hubo coincidentas, tampoco se paso de len...
	}
	throw;
}

bool CheckBlockIgnoreWatchBreak(char * data, UINT16 size, FilterCaptureFuncs functionFlag, FilterActions checkType)
{

	for (int i = 0; i<filterCount; i++)
	{
		Filter filter = _filterList[i];
		switch (checkType)
		{
			case FilterActions::Block:
				if (!(filter.Actions & FilterActions::Block))
					continue;
				break;
			case FilterActions::Ignore:
				if (!(filter.Actions & FilterActions::Ignore))
					continue;
				break;
			case FilterActions::Watch:
				if (!(filter.Actions & FilterActions::Watch))
					continue;
				break;
			case FilterActions::Break:
				if (!(filter.Actions & FilterActions::Break))
					continue;
				break;
			default:
				throw;
		}
		if (filter.searches.size() == 0) // Filtro sin search? No vamos a blockear, watchear o ignorar todoo...
			continue;
		if (!FilterMeetConditions(filter, size, functionFlag))
			continue;
		int pos = 0;
		bool allOffsetMatch = AllSearchOffsetMatch(data, size, filter, &pos);
		if (allOffsetMatch)
			return true; // Todos los offset de search machean con el valor en data, la accion del filtro se aplica
	}

	return false;
}

bool DoFilteringForPacket(char * data, UINT16 size, FilterCaptureFuncs functionFlag)
{
	bool dataModified = false;
	for (int i = 0; i<filterCount; i++)
	{
		Filter filter = _filterList[i];
		if (filter.replaces.size() == 0) // Nada que filtrar
			continue;
		if (!FilterMeetConditions(filter, size, functionFlag))
			continue;
		int pos = 0;
		bool allOffsetMatch = AllSearchOffsetMatch(data, size, filter, &pos);
		if (allOffsetMatch) // Todos los offset de search machean, hacemos los reemplazos
		{
			if (filter.Mode == FilterModes::SearchAndReplaceFromBegin || filter.Mode == FilterModes::SearchOcurrenceReplaceFromBegin)
				for (auto rit = filter.replaces.begin(); rit != filter.replaces.end() && rit->first <= size; ++rit)
					data[rit->first] = rit->second;
			else
			{
				for (auto rit = filter.replaces.begin(); rit != filter.replaces.end(); ++rit)
				{
					if (rit->first - 250 + pos > size - 1 || rit->first - 250 + pos < 0) continue;
					data[rit->first - 250 + pos] = rit->second;
				}
			}
			dataModified = true;
		}
	}
	return dataModified;
}

bool CheckPacketBlock(char * data, UINT16 size, FilterCaptureFuncs functionFlag)
{
	for (int i = 0; i<filterCount; i++)
	{
		Filter filter = _filterList[i];
		if (!(filter.Actions & FilterActions::Block))
			continue;

		if (filter.searches.size() == 0) // Filtro sin search? No vamos a blockear, watchear o ignorar todoo...
			continue;
		if (!FilterMeetConditions(filter, size, functionFlag))
			continue;
		int pos = 0;
		bool allOffsetMatch = AllSearchOffsetMatch(data, size, filter, &pos);
		if (allOffsetMatch)
			return true; // Todos los offset de search machean con el valor en data, la accion del filtro se aplica
	}

	return false;
}

bool CheckPacketBreak(char * data, UINT16 size, FilterCaptureFuncs functionFlag)
{
	for (int i = 0; i<filterCount; i++)
	{
		Filter filter = _filterList[i];
		if (!(filter.Actions & FilterActions::Break))
			continue;

		if (!FilterMeetConditions(filter, size, functionFlag))
			continue;
		int pos = 0;
		bool allOffsetMatch = AllSearchOffsetMatch(data, size, filter, &pos);
		if (allOffsetMatch)
			return true; // Todos los offset de search machean con el valor en data, la accion del filtro se aplica
	}

	return false;
}