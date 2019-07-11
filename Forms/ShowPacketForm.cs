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
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Be.Windows.Forms;
using OSPE.Properties;

namespace OSPE
{
    public partial class ShowPacketForm : Form
    {
        public byte[] NewPacketData {get;set;}
        public UInt16 NewPacketSize { get; set; }

        public ShowPacketForm(int ID, Packet packet, bool bp = false)
        {
            InitializeComponent();

            StartPosition = FormStartPosition.CenterScreen;

            Text += " " + ID;

            txtPacket.Text = ID.ToString();
            txtLocal.Text = packet.LocalIp + " : " + packet.LocalPort;
            txtRemote.Text = packet.RemoteIp + " : " + packet.RemotePort;
            txtSize.Text = packet.Size.ToString();
            txtData.Text = packet.GetBufferAsText();
            hexBox1.ByteProvider = new DynamicByteProvider(packet.Data);

            Bitmap pic;
            switch (packet.Direction)
            {
                case Packet.Directions.None:
                    pic = Resources.Faq24;
                    break;
                case Packet.Directions.In:
                    pic = Resources.received;
                    break;
                case Packet.Directions.Out:
                    pic = Resources.sent;
                    break;
                default:
                    throw new ArgumentOutOfRangeException();
            }

            picDirection.Image = pic;

            lblFunc.Text = Program.FunctionNameToString(packet.FunctionID);

            // TODO: Implementar un delegate o hacer q SetHexBoxColors() que reciba como parametro el HexBox asi no hay q crear otra funcion igual
            //Program.mainForm.SetHexBoxColors();

            if (bp)
            {
                Text = "PACKET BREAKPOINT TRIGGERED!";
                panelAceptCancel.Visible = true;
                tableLayoutPanel1.RowStyles[3].Height = 37;
                NewPacketData = packet.Data;
            }
        }

        private void btnConvertToHex_Click(object sender, EventArgs e)
        {
            hexBox1.ByteProvider = new DynamicByteProvider(Encoding.ASCII.GetBytes(txtData.Text));
        }

        private void btnAccept_Click(object sender, EventArgs e)
        {
            var bp = hexBox1.ByteProvider;
            NewPacketData = new byte[bp.Length];
            for (int i = 0; i < bp.Length; i++)
                NewPacketData[i] = bp.ReadByte(i);

            NewPacketSize = (UInt16) bp.Length;
            DialogResult = DialogResult.OK;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
            Close();
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
                strBuilder.Insert(i, (char) bp.ReadByte(i));
            }
            txtData.TextChanged -= txtData_TextChanged;
            txtData.Text = strBuilder.ToString();
            txtData.TextChanged += txtData_TextChanged;
            txtSize.Text = bp.Length.ToString();
        }

        private void btnGenerateFilter_Click(object sender, EventArgs e)
        {
            var bp = hexBox1.ByteProvider;
            byte[] bytes = new byte[bp.Length];
            for (int i = 0; i < bp.Length; i++)
            {
                bytes[i] = bp.ReadByte(i);
            }
            var filterForm = new FilterEditorForm();
            filterForm.LoadSearchData(bytes);
        }

    }
}
