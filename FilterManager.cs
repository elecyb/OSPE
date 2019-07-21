/*
* OSPE - Open Source Packet Editor
* Copyright(C) 2018-2019 Javier Pereda <https://github.com/elecyb>
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

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using OSPE;

namespace OSPE
{
    public enum FilterModes : uint
    {
        SearchAndReplaceFromBegin,
        SearchOcurrenceReplaceFromBegin,
        SearchOcurrenceReplaceFromPosition
    }
    [Flags]
    public enum FilterCaptureFuncs : uint
    {
        None = 0x0,
        WSSend = 0x1,
        WSSendTo = 0x2,
        WSRecv = 0x4,
        WSRecvFrom = 0x8,
        WS2Send = 0x10,
        WS2SendTo = 0x20,
        WS2Recv = 0x40,
        WS2RecvFrom = 0x80,
        WSASend = 0x100,
        WSASendTo = 0x200,
        WSARecv = 0x400,
        WSARecvFrom = 0x800,
        PRSend = 0x1000,
        PRRecv = 0x2000,
        PRRead = 0x4000,
        PRWrite = 0x8000,
        SSLEncryptPacket = 0x10000,
        SSLDecryptPacket = 0x20000,
        EncryptMessage = 0x40000,
        DecryptMessage = 0x80000,
        SSLRead = 0x100000,
        SSLWrite = 0x200000,
    }
    [Flags]
    public enum FilterActions : uint
    {
        None = 0x0,
        Block = 0x1,
        Ignore = 0x2,
        Watch = 0x4,
        Break = 0x8
    }

    class FilterManager
    {
        [Serializable]
        public class Filter
        {
            public bool Active;
            public FilterModes Mode;
            public FilterCaptureFuncs Functions;
            public FilterActions Actions;
            public string Name;
            public uint PacketLengthMin;
            public uint PacketLengthMax;
            public uint NumTimesApply;
            public Dictionary<int, byte> Searches;
            public Dictionary<int, byte> Replaces;

            public Filter(bool ac, FilterModes m, FilterCaptureFuncs f, FilterActions a, string n, uint plMin, uint plMax, uint nta, Dictionary<int, byte> s, Dictionary<int, byte> r)
            {
                Active = ac;
                Mode = m;
                Functions = f;
                Actions = a;
                Name = n;
                PacketLengthMin = plMin;
                PacketLengthMax = plMax;
                NumTimesApply = nta;
                Searches = s;
                Replaces = r;
            }
        }

        public const short FILTERINBYTESSIZE = 3015;

        private static List<Filter> _filterList = new List<Filter>();
        private static T BytesToStruct<T>(byte[] bytes) where T : struct
        {
          //  AssertUtilities.ArgumentNotNull(bytes, "bytes");

            var structSize = Marshal.SizeOf(typeof(T));
            var pointer = IntPtr.Zero;
            try
            {
                pointer = Marshal.AllocHGlobal(structSize);
                Marshal.Copy(bytes, 0, pointer, structSize);
                return (T)Marshal.PtrToStructure(pointer, typeof(T));
            }
            finally
            {
                if (pointer != IntPtr.Zero)
                    Marshal.FreeHGlobal(pointer);
            }
        }
        public static byte[] StructToBytes<T>(T structObject) where T : struct
        {
            var structSize = Marshal.SizeOf(typeof(T));
            var bytes = new byte[structSize];
            var pointer = IntPtr.Zero;
            try
            {
                pointer = Marshal.AllocHGlobal(structSize);
                Marshal.StructureToPtr(structObject, pointer, true);
                Marshal.Copy(pointer, bytes, 0, structSize);
                return bytes;
            }
            finally
            {
                if (pointer != IntPtr.Zero)
                    Marshal.FreeHGlobal(pointer);
            }
        }
        private static byte[] DictionaryToBytes(Dictionary<int, byte> dic)
        {
            var bytes = new byte[1500];
            int i = 0;
            foreach (KeyValuePair<int, byte> pair in dic)
            {
                Array.Copy(StructToBytes(pair.Key), 0, bytes, i, 2);
                bytes[i+2] = pair.Value;
                i = i + 3;
            }
            return bytes;
        }

        public static byte[] ConvertFilterListToBytes()
        {
            /*
            Filter data representation:

            | enabled |  Mode  | captureFuncsFlags | actions | lenMin  | lenMax  | numApply | searchCount |         search       | replacesCount |        replace       |
            |  1-byte | 1-byte |-----2-bytes ------|  1-bye  |  2-byes |  2-byes |  2-bytes |  2-bytes    | ----- 1500-bytes ----|  2-bytes      | ----  1500-bytes ----|
            | ---------------------------------------- filterData ------------------------------------------------------------------------------------------------------|
            */
            byte[] bytesToTranfer = new byte[FILTERINBYTESSIZE * GetActiveFilterCount()];
            int pos = 0;
            foreach (Filter f in _filterList)
            {
                if (f.Active == false) continue;
                Array.Copy(StructToBytes(f.Active), 0, bytesToTranfer, pos+0, 1);
                Array.Copy(StructToBytes((byte)f.Mode), 0, bytesToTranfer, pos+1, 1);
                Array.Copy(StructToBytes((UInt16)f.Functions), 0, bytesToTranfer, pos+2, 2);
                Array.Copy(StructToBytes((byte)f.Actions), 0, bytesToTranfer, pos+4, 1);
                Array.Copy(StructToBytes(f.PacketLengthMin), 0, bytesToTranfer, pos+5, 2);
                Array.Copy(StructToBytes(f.PacketLengthMax), 0, bytesToTranfer, pos+7, 2);
                Array.Copy(StructToBytes(f.NumTimesApply), 0, bytesToTranfer, pos+9, 2);
                Array.Copy(StructToBytes(f.Searches.Count), 0, bytesToTranfer, pos+11, 2);
                Array.Copy(DictionaryToBytes(f.Searches), 0, bytesToTranfer, pos+13, 1500);
                Array.Copy(StructToBytes(f.Replaces.Count), 0, bytesToTranfer, pos+1513, 2);
                Array.Copy(DictionaryToBytes(f.Replaces), 0, bytesToTranfer, pos+1515, 1500);
                pos = pos + FILTERINBYTESSIZE;
            }

            return bytesToTranfer;

        }

        public static int GetActiveFilterCount()
        {
            return _filterList.Count(item => item.Active == true);
        }

        private static bool CheckIfBetweenLength(Filter f, ushort pSize)
        {
            if (f.PacketLengthMin != 0 || f.PacketLengthMax != 0)
                return (pSize >= f.PacketLengthMin && pSize <= f.PacketLengthMax);
            return true;
        }

        public static void NewFilter(bool active, FilterModes mode, FilterCaptureFuncs functions, FilterActions actions, string name, uint maxPacketLeghtMin, uint maxPacketLeghtMax, uint numTimesApply, Dictionary<int, byte> searches, Dictionary<int, byte> replaces)
        {
            var filter = new Filter(active, mode, functions, actions, name, maxPacketLeghtMin, maxPacketLeghtMax, numTimesApply, searches, replaces);
            _filterList.Add(filter);
        }

        public static void EditFilter(int index, bool active, FilterModes mode, FilterCaptureFuncs functions, FilterActions actions, string name, uint packetLenghtMin, uint packetLengthMax, uint numTimesApply, Dictionary<int, byte> searches, Dictionary<int, byte> replaces)
        {
            var filter = _filterList.ElementAt(index);
            filter.Active = active;
            filter.Mode = mode;
            filter.Functions = functions;
            filter.Actions = actions;
            filter.Name = name;
            filter.PacketLengthMin = packetLenghtMin;
            filter.PacketLengthMax = packetLengthMax;
            filter.NumTimesApply = numTimesApply;
            filter.Searches = searches;
            filter.Replaces = replaces;
        }

        public static void DeleteFilter(int index)
        {
            _filterList.RemoveAt(index);
        }

        public static List<Filter> GetFilterList()
        {
            return _filterList;
        }

        public static Filter GetFilterAtListIndex(int index)
        {
            return _filterList.ElementAt(index);
        }

        public static int GetNumberOfFiltersInList()
        {
            return _filterList.Count;
        }

        public static void ClearFilterList()
        {
            _filterList.Clear();
        }

        public static void SetFilterActive(int index, bool active)
        {
            _filterList.ElementAt(index).Active = active;
        }

        public static void SaveFilterList()
        {
            var sfd = new SaveFileDialog 
                            {
                                Title = "Save OSPE filter",
                                Filter = "OSPE filter files (*.ospef)|*.ospef|All files (*.*)|*.*"
                            };
            var result = sfd.ShowDialog();
            if (result == DialogResult.OK)
            {
                Serializer.SerializeOspeFilterList(sfd.FileName, _filterList);
            }  
        }

        public static void LoadFilterList()
        {
            var ofd = new OpenFileDialog
                          {
                              Title = "Open OSPE filter",
                              Filter = "OSPE filter files (*.ospef)|*.ospef|All files (*.*)|*.*"
                          };
            var result = ofd.ShowDialog();
            if (result == DialogResult.OK)
            {
                _filterList = Serializer.DeSerializeOspeFilterList(ofd.FileName);
            }
        }

        public static void LoadTempFilterList()
        {
            _filterList = Serializer.DeSerializeTempFilterList();
        }
        public static void SaveTempFilterList()
        {
            Serializer.SerializeTempFilterList(_filterList);
        }

        public static FilterCaptureFuncs GetFilterActionFlagForFunction(Functions func)
        {
            Debug.Assert(func != 0);
            int flag = 1 << (int)func-1;
            return (FilterCaptureFuncs) flag;
        }

        // Not used for now (implemented in the DLL)
        public static bool DoFilteringForPacket(ref byte[] data, UInt16 size, FilterCaptureFuncs functionFlag)
        {
            bool dataModified = false;
            foreach (var filter in _filterList)
            {
                if (filter.Replaces.Count == 0) // Nothing to filer
                    continue;
                if (!FilterMeetConditions(filter, size, functionFlag))
                    continue;
                int pos = 0;
                bool allOffsetMatch = AllSearchOffsetMatch(data, size, filter, ref pos);
                if (allOffsetMatch) // All search offsets match, let's do the edits 
                {
                    if (filter.Mode == FilterModes.SearchAndReplaceFromBegin || filter.Mode == FilterModes.SearchOcurrenceReplaceFromBegin)
                        foreach (KeyValuePair<int, byte> pair in filter.Replaces.TakeWhile(pair => pair.Key <= size - 1))
                            data[pair.Key] = pair.Value;
                    else
                    {
                        foreach (KeyValuePair<int, byte> pair in filter.Replaces)
                        {
                            if (pair.Key - 250 + pos > size - 1 || pair.Key - 250 + pos < 0) continue;
                            data[pair.Key - 250 + pos] = pair.Value;
                        }
                    }
                    dataModified = true;
                }
            }
            return dataModified;
        }

        private static bool FilterMeetConditions(Filter filter, UInt16 packetSize, FilterCaptureFuncs functionFlag)
        {
            if ((filter.Active) &&
             (CheckIfBetweenLength(filter, packetSize)) && // If the filter has length, it must be between lengthMin and lengthMax
             (filter.Functions.HasFlag(functionFlag)) && // The packet's function flag must be actived in the filter
             (filter.Searches.Count == 0 || filter.Searches.Last().Key < packetSize)) // Latest search offset position must be less than packet Size
                return true;
            return false;
        }

        private static bool AllSearchOffsetMatch(byte[] data, UInt16 len, Filter filter, ref int pos)
        {
            if (filter.Mode == FilterModes.SearchAndReplaceFromBegin)
                return filter.Searches.All(pair => pair.Value == data[pair.Key]);
            if (filter.Mode == FilterModes.SearchOcurrenceReplaceFromBegin || filter.Mode == FilterModes.SearchOcurrenceReplaceFromPosition)
            {
                for (int i=0; i<len; i++)
                {
                    bool shouldContinue = false;
                    foreach (KeyValuePair<int, byte> pair in filter.Searches)
                    {
                        if (pair.Key + i > len-1) // Next search offset position is greather than packet length, NO MATCH
                            return false;
                        if (data[pair.Key+i]!=pair.Value) // Offset data is different?
                        {
                            shouldContinue = true; // We must continue, increment i and try from the next value of i
                            break; // Break foreach, one of the offsets are not equal, no need to check the rest
                        }
                    }
                    if (shouldContinue) continue;
                    pos = i;
                    return true;
                }
                return false; // No matches, neither we past the len...
            }
            throw new IndexOutOfRangeException();
        }

        private static bool CheckBlockIgnoreWatchBreak(byte[] data, UInt16 size, FilterCaptureFuncs functionFlag, FilterActions checkType)
        {
            foreach (var filter in _filterList)
            {
                switch (checkType)
                {
                    case FilterActions.Block:
                        if (!filter.Actions.HasFlag(FilterActions.Block))
                            continue;
                        break;
                    case FilterActions.Ignore:
                        if (!filter.Actions.HasFlag(FilterActions.Ignore))
                            continue;
                        break;
                    case FilterActions.Watch:
                        if (!filter.Actions.HasFlag(FilterActions.Watch))
                            continue;
                        break;
                    case FilterActions.Break:
                        if (!filter.Actions.HasFlag(FilterActions.Break))
                            continue;
                        break;
                    default:
                        throw new IndexOutOfRangeException();
                }
                if (filter.Searches.Count == 0) // Filtro sin search? No vamos a blockear, watchear o ignorar todoo...
                    continue;
                if (!FilterMeetConditions(filter, size, functionFlag))
                    continue;
                int pos = 0;
                bool allOffsetMatch = AllSearchOffsetMatch(data, size, filter, ref pos);
                if (allOffsetMatch)
                    return true; // Todos los offset de search machean con el valor en data, la accion del filtro se aplica
            }

            return false;
        }

        public static bool CheckPacketBlock(byte[] data, UInt16 size, FilterCaptureFuncs functionFlag)
        {
            return CheckBlockIgnoreWatchBreak(data, size, functionFlag, FilterActions.Block);
        }
        public static bool CheckPacketIgnore(byte[] data, UInt16 size, FilterCaptureFuncs functionFlag)
        {
            return CheckBlockIgnoreWatchBreak(data, size, functionFlag, FilterActions.Ignore);
        }
        public static bool CheckPacketWatch(byte[] data, UInt16 size, FilterCaptureFuncs functionFlag)
        {
            return CheckBlockIgnoreWatchBreak(data, size, functionFlag, FilterActions.Watch);
        }
        public static bool CheckPacketBreak(byte[] data, UInt16 size, FilterCaptureFuncs functionFlag)
        {
            return CheckBlockIgnoreWatchBreak(data, size, functionFlag, FilterActions.Break);
        }


    }
}
