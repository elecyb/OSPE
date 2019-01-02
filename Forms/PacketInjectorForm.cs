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

using Be.Windows.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;

namespace OSPE.Forms
{
    public partial class PacketInjectorForm : Form
    {
        private ushort _socketId = 0;
        private int _editingIndex;
        private int _repeats;

        public PacketInjectorForm(int edit = -1)
        {
            _editingIndex = edit;
            InitializeComponent();
            hexBox1.ByteProvider = new DynamicByteProvider(new byte[0]);
            if (_editingIndex != -1)
            {
                SendInfo si = SendManager.GetSendInfoAtListIndex(_editingIndex);
                LoadFormData(si.Name, si.Active, si.Packet);
            }

        }
        public PacketInjectorForm(string name, bool active, Packet p)
        {
            InitializeComponent();
            LoadFormData(name, active, p);
        }

        private void LoadFormData(string name, bool active, Packet p)
        {
            txtItemName.Text = name;
            chkEnabled.Checked = active;
            txtData.Text = p.GetBufferAsText();
            numPacketSize.Value = p.Size;
            numOpenedSocketId.Value = p.SocketId;
            txtNewSocketIp.Text = p.RemoteIp.ToString();
            numNewSocketPort.Value = p.RemotePort;
            hexBox1.ByteProvider = new DynamicByteProvider(p.Data);
        }


        private void btnStart_Click(object sender, EventArgs e)
        {
            timerSender.Interval = (int) numDelay.Value;
            _repeats = 0;
            timerSender.Enabled = true;

            if (radNewSocket.Checked)
            {
                Socket s = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                //_socketId = s.; // TODO
            }
            else
                _socketId = (ushort)numOpenedSocketId.Value;

            btnStart.Enabled = false;
            btnStop.Enabled = true;
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            timerSender.Enabled = false;
            btnStart.Enabled = true;
            btnStop.Enabled = false;
            _repeats = 0;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            Packet packet = new Packet(Functions.CODE_NOP, 
                (ushort) numOpenedSocketId.Value, 0, 0, 
                BitConverter.ToUInt16(System.Net.IPAddress.Parse(txtNewSocketIp.Text).GetAddressBytes(), 0), 
                (ushort) numNewSocketPort.Value, 
                Encoding.ASCII.GetBytes(txtData.Text), Packet.Directions.None);
            SendInfo si = new SendInfo(txtItemName.Text, chkEnabled.Enabled, packet);
            if (_editingIndex != -1)
                SendManager.ReplaceFromList(_editingIndex, si);
            else
                SendManager.AddToList(si);
            Program.mainForm.LoadSendListItems();
            Close();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void timerSender_Tick(object sender, EventArgs e)
        {
            if (!radContinously.Checked && _repeats >= (int)numSendTimes.Value)
            {
                btnStop_Click(null, null);
                return;
            }
                
            _repeats++;
            var bp = hexBox1.ByteProvider;
            byte[] bytes = new byte[bp.Length];
            for (int i = 0; i < bp.Length; i++)
            {
                bytes[i] = bp.ReadByte(i);
            }
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_INJECTPACKET, bytes, (ushort) numPacketSize.Value, _socketId);
            
        }

        private void rad_CheckedChanged(object sender, EventArgs e)
        {
            numOpenedSocketId.Enabled = !radNewSocket.Checked;
            txtNewSocketIp.Enabled = radNewSocket.Checked;
            numNewSocketPort.Enabled = radNewSocket.Checked;
        }

        private void txtData_TextChanged(object sender, EventArgs e)
        {
            hexBox1.ByteProvider = new DynamicByteProvider(Encoding.ASCII.GetBytes(txtData.Text));
            numPacketSize.Value = txtData.Text.Length;
        }

        private void hexBox1_Paint(object sender, PaintEventArgs e)
        {
            var bp = hexBox1.ByteProvider;
            StringBuilder strBuilder = new System.Text.StringBuilder((int)bp.Length);
            for (int i = 0; i < bp.Length; i++)
            {
                strBuilder.Insert(i, (char)bp.ReadByte(i));
            }
            txtData.TextChanged -= txtData_TextChanged;
            txtData.Text = strBuilder.ToString();
            txtData.TextChanged += txtData_TextChanged;
        }
    }
}
