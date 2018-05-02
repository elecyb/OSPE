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
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace OSPE.Forms
{
    public partial class InjectForm : Form
    {
        byte[] buf = new byte[65539];

        public InjectForm()
        {
            InitializeComponent();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {

            // Buffer data representation
            /*
                |   SocketId    |   PacketSize  |             Packet Data                     |
                |    2-bytes    |   2-bytes     |-----------------Data------------------------|
            */
            
            Array.Copy(BitConverter.GetBytes(Int16.Parse(txtOpenedSocketId.Text)), buf, 2); // SocketId
            Array.Copy(BitConverter.GetBytes((Int16)numPacketSize.Value), buf, 2); // PacketSize
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

        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void timerSender_Tick(object sender, EventArgs e)
        {
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_INJECTPACKET, buf, (ushort) numPacketSize.Value);
        }
    }
}
