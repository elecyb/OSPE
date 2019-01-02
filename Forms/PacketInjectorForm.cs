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
using System.Text;
using System.Windows.Forms;

namespace OSPE.Forms
{
    public partial class PacketInjectorForm : Form
    {
        byte[] buf = new byte[65539];
        ushort socketId = 0;

        public PacketInjectorForm(int editIndex = -1)
        {
            InitializeComponent();
            hexBox1.ByteProvider = new DynamicByteProvider(new byte[0]);
            if (editIndex != -1)
            {
                SendInfo si = SendManager.GetSendInfoAtListIndex(editIndex);
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
            chkEnabled.Enabled = active;
            txtData.Text = p.GetBufferAsText();
            numPacketSize.Value = p.Size;
            txtOpenedSocketId.Text = p.SocketId.ToString();
            txtNewSocketIp.Text = p.RemoteIp.ToString();
            txtNewSocketPort.Text = p.RemotePort.ToString();
            hexBox1.ByteProvider = new DynamicByteProvider(p.Data);
            buf = p.Data;
        }


        private void btnStart_Click(object sender, EventArgs e)
        {
            timerSender.Interval = (int) numDelay.Value;
            timerSender.Enabled = true;
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            timerSender.Enabled = false;
            btnStart.Enabled = true;
            btnStop.Enabled = false;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            Packet packet = new Packet(Functions.CODE_NOP, UInt16.Parse(txtOpenedSocketId.Text), 0, 0, UInt16.Parse(txtNewSocketIp.Text), UInt16.Parse(txtNewSocketPort.Text), Encoding.ASCII.GetBytes(txtData.Text), Packet.Directions.None);
            SendInfo si = new SendInfo(txtItemName.Text, chkEnabled.Enabled, packet);
            SendManager.AddToList(si);
            Program.mainForm.LoadSendListItems();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void timerSender_Tick(object sender, EventArgs e)
        {
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_INJECTPACKET, buf, (ushort) numPacketSize.Value, socketId);
        }

        private void rad_CheckedChanged(object sender, EventArgs e)
        {
            txtOpenedSocketId.Enabled = !radNewSocket.Checked;
            txtNewSocketIp.Enabled = radNewSocket.Checked;
            txtNewSocketPort.Enabled = radNewSocket.Checked;
        }

        private void txtData_TextChanged(object sender, EventArgs e)
        {
            hexBox1.ByteProvider = new DynamicByteProvider(Encoding.ASCII.GetBytes(txtData.Text));
        }

        private void hexBox1_Paint(object sender, PaintEventArgs e)
        {
            var bp = hexBox1.ByteProvider;
            System.Text.StringBuilder strBuilder = new System.Text.StringBuilder((int)bp.Length);
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
