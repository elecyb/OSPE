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
using System.Windows.Forms;
using OSPE;

namespace OSPE
{
    [Serializable]
    public class SendInfo
    {
        public bool Active;
        public string Name;
        public int Times;
        public Packet Packet;


        public SendInfo(string nam, bool act, Packet pkt)
        {
            Name = nam;
            Active = act;
            Packet = pkt;
        }
    }
    static class SendManager
    {
        private static List<SendInfo> _sendList = new List<SendInfo>();

        public static List<SendInfo> GetSendList()
        {
            return _sendList;
        }
        public static SendInfo GetSendInfoAtListIndex(int index)
        {
            return _sendList.ElementAt(index);
        }

        public static void AddToList(string name, bool active, Packet packet)
        {
            SendInfo si = new SendInfo(name, active, packet);
            AddToList(si);
        }
        public static void AddToList(SendInfo si)
        {
            _sendList.Add(si);
            Program.mainForm.LoadSendListItems();
        }
        public static void ReplaceFromList(int index, SendInfo si)
        {
            _sendList.RemoveAt(index);
            AddToList(si);
        }

        public static void SetSendListItemActive(int index, bool active)
        {
            _sendList.ElementAt(index).Active = active;
            Program.mainForm.LoadSendListItems();
        }
        public static void DeleteSendListItem(int index)
        {
            _sendList.RemoveAt(index);
            Program.mainForm.LoadSendListItems();
        }
        public static void SaveSendList()
        {
            var sfd = new SaveFileDialog
            {
                Title = "Save OSPE send list",
                Filter = "OSPE filter files (*.ospesl)|*.ospesl|All files (*.*)|*.*"
            };
            var result = sfd.ShowDialog();
            if (result == DialogResult.OK)
            {
                Serializer.SerializeOspeSendList(sfd.FileName, _sendList);
            }
        }
        public static void LoadSendList()
        {
            var ofd = new OpenFileDialog
            {
                Title = "Open OSPE send list",
                Filter = "OSPE send list files (*.ospesl)|*.ospesl|All files (*.*)|*.*"
            };
            var result = ofd.ShowDialog();
            if (result == DialogResult.OK)
            {
                _sendList = Serializer.DeSerializeOspeSendList(ofd.FileName);
            }
        }
        public static void ClearSendList()
        {
            _sendList.Clear();
        }
    }
}
