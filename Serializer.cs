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
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace OSPE
{
    class Serializer
    {
        /// <summary>
        /// Saves the filter list in the specified directory
        /// </summary>
        /// <param name="filename"></param>
        /// <param name="filterList"></param>
        public static void SerializeOspeFilterList(string filename, List<FilterManager.Filter> filterList)
        {
            Stream stream = File.Open(filename, FileMode.Create);
            var bFormatter = new BinaryFormatter();
            bFormatter.Serialize(stream, filterList);
            stream.Close();
        }

        public static List<FilterManager.Filter> DeSerializeOspeFilterList(string filename)
        {
            Stream stream = File.Open(filename, FileMode.Open);
            var bFormatter = new BinaryFormatter();
            var filterList = (List<FilterManager.Filter>)bFormatter.Deserialize(stream);
            stream.Close();
            return filterList;
        }

        /// <summary>
        /// Saves the current filter list in the program's directory. This list is auto-loaded when program starts
        /// </summary>
        /// <param name="filterList"></param>
        public static void SerializeTempFilterList(List<FilterManager.Filter> filterList)
        {
            Stream stream = File.Open(AppDomain.CurrentDomain.BaseDirectory + "\\filterdata.bin", FileMode.OpenOrCreate);
            var bFormatter = new BinaryFormatter();
            bFormatter.Serialize(stream, filterList);
            stream.Close();
        }

        public static List<FilterManager.Filter> DeSerializeTempFilterList()
        {
            if (!File.Exists(AppDomain.CurrentDomain.BaseDirectory + "\\filterdata.bin"))
                return new List<FilterManager.Filter>();

            Stream stream = File.Open(AppDomain.CurrentDomain.BaseDirectory + "\\filterdata.bin", FileMode.Open);
            var bFormatter = new BinaryFormatter();
            var filterList = (List<FilterManager.Filter>)bFormatter.Deserialize(stream);
            stream.Close();
            return filterList;
        }

        /// <summary>
        /// Saves the capture list in the specified directory
        /// </summary>
        /// <param name="filename"></param>
        /// <param name="captureList"></param>
        public static void SerializeOspeCaptureList(string filename, List<CaptureRecord> captureList)
        {
            Stream stream = File.Open(filename, FileMode.Create);
            var bFormatter = new BinaryFormatter();
            bFormatter.Serialize(stream, captureList);
            stream.Close();
        }

        public static List<CaptureRecord> DeSerializeOspeCaptureList(string filename)
        {
            Stream stream = File.Open(filename, FileMode.Open);
            var bFormatter = new BinaryFormatter();
            var captureList = (List<CaptureRecord>)bFormatter.Deserialize(stream);
            stream.Close();
            return captureList;
        }

        /// <summary>
        /// Saves the send list in the specified directory
        /// </summary>
        /// <param name="filename"></param>
        /// <param name="sendList"></param>
        public static void SerializeOspeSendList(string filename, List<SendInfo> sendList)
        {
            Stream stream = File.Open(filename, FileMode.Create);
            var bFormatter = new BinaryFormatter();
            bFormatter.Serialize(stream, sendList);
            stream.Close();
        }

        public static List<SendInfo> DeSerializeOspeSendList(string filename)
        {
            Stream stream = File.Open(filename, FileMode.Open);
            var bFormatter = new BinaryFormatter();
            var sendList = (List<SendInfo>)bFormatter.Deserialize(stream);
            stream.Close();
            return sendList;
        }

    }
}
