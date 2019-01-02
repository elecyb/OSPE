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
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OSPE
{
    [Serializable]
    class CaptureRecord
    {
        private List<Packet> _packetList;
        private List<int> _both;
        private List<int> _sent;
        private List<int> _received;
        private List<int> _watch;
        private DateTime _date;

        public CaptureRecord(List<Packet> pl, List<int> b, List<int> s, List<int> r, List<int> w)
        {
            _packetList = pl;
            _both = b;
            _sent = s;
            _received = r;
            _watch = w;
            _date = DateTime.Now;
        }

        public List<Packet> GetPacketList()
        {
            return _packetList;
        }

        public List<int> GetBothList()
        {
            return _both;
        }

        public List<int> GetSentList()
        {
            return _sent;
        }

        public List<int> GetReceivedList()
        {
            return _received;
        }

        public List<int> GetWatchList()
        {
            return _watch;
        }

        public DateTime GetCaptureDateTime()
        {
            return _date;
        }

        public int GetPacketCount()
        {
            return _packetList.Count;
        }


    }
}
