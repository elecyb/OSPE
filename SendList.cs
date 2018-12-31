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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace OSPE
{
    class SendListItem
    {
        public ushort socketId = 0;
        public ushort length = 0;
        public byte[] data;
        public string text;


        public SendListItem(ushort sid, ushort len, byte[] dat, string txt)
        {
            socketId = sid;
            length = len;
            data = dat;
            text = txt;
        }
    }


    class SendList
    {
        private List<SendListItem> listItems;

        public List<SendListItem> GetSendList()
        {
            return listItems;
        }

        public void AddToList(ushort sid, ushort len, byte[] data, string text)
        {
            SendListItem sli = new SendListItem(sid, len, data, text);
            listItems.Add(sli);
        }



    }
}
