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
using System.Drawing;
using System.Globalization;
using System.Windows.Forms;

namespace OSPE
{
    public partial class FilterEditorForm : Form
    {
        private int _filterIndex;

        public FilterEditorForm(int editIndex = -1)
        {
            _filterIndex = editIndex;
            InitializeComponent();
            DrawDataGridViews();
            if (editIndex != -1)
                FillDataGridViewWithFilter(FilterManager.GetFilterAtListIndex(_filterIndex));

            Show();
        }
        
        public void LoadSearchData(byte[] data)
        {
            for (int i=0; i<data.Length; i++)
                dataGridViewSearch[i, 0].Value = data[i].ToString("X2");
            
        }

        private void FillDataGridViewWithFilter(FilterManager.Filter filter)
        {
            chkActive.Checked = filter.Active;
            SetFunctionsAndActionsWithBitMask(filter.Actions, filter.Functions);
            txtFilterName.Text = filter.Name;
            if (filter.PacketLengthMin > 0)
            {
                chkPackeLength.Checked = true;
                nudPacketLengthMin.Value = filter.PacketLengthMin;
                nudPacketLengthMax.Value = filter.PacketLengthMax;
            }
            nudNumTimesApply.Value = filter.NumTimesApply;

            foreach (var pair in filter.Searches)
                dataGridViewSearch[pair.Key, 0].Value = pair.Value.ToString("X2");

            if (filter.Mode == FilterModes.SearchAndReplaceFromBegin)
            {
                radioButton1.Checked = true;
                foreach (var pair in filter.Replaces)
                    dataGridViewSearch[pair.Key, 1].Value = pair.Value.ToString("X2");

            }
            else if (filter.Mode == FilterModes.SearchOcurrenceReplaceFromBegin)
            {
                radioButton2.Checked = true;
                foreach (var pair in filter.Replaces)
                    dataGridViewReplace[pair.Key, 0].Value = pair.Value.ToString("X2");
            }
            else if (filter.Mode == FilterModes.SearchOcurrenceReplaceFromPosition)
            {
                radioButton3.Checked = true;
                foreach (var pair in filter.Replaces)
                    dataGridViewReplace2[pair.Key, 0].Value = pair.Value.ToString("X2");
            }
            else
            {
                throw new NotImplementedException(); 
            }
        }

        private void DrawDataGridViews()
        {
            dataGridViewSearch.TopLeftHeaderCell.Value = "Offset";
            for (var i = 0; i < 501; i++)
            {
                dataGridViewSearch.Columns.Add("col" + i, i.ToString("D3"));
                dataGridViewSearch.Columns[i].Width = 30;
                ((DataGridViewTextBoxColumn)dataGridViewSearch.Columns[i]).MaxInputLength = 2;
            }
            dataGridViewSearch.Rows.Add();
            dataGridViewSearch.Rows.Add();

            dataGridViewReplace.TopLeftHeaderCell.Value = "Offset";
            for (var i = 0; i < 501; i++)
            {
                dataGridViewReplace.Columns.Add("col" + i, i.ToString("D3"));
                dataGridViewReplace.Columns[i].Width = 30;
                ((DataGridViewTextBoxColumn)dataGridViewReplace.Columns[i]).MaxInputLength = 2;
            }
            dataGridViewReplace.Rows.Add();
            dataGridViewReplace.Rows[0].DefaultCellStyle.BackColor = Color.LightGoldenrodYellow;

            dataGridViewReplace2.TopLeftHeaderCell.Value = "Offset";
            int j = -251;
            for (var i = 0; i < 501; i++)
            {
                j = j + 1;
                dataGridViewReplace2.Columns.Add("col" + i, j.ToString("D3")); //(j > 0) ? "+" + j.ToString("D3") : 
                dataGridViewReplace2.Columns[i].Width = 30;
                ((DataGridViewTextBoxColumn)dataGridViewReplace2.Columns[i]).MaxInputLength = 2;
            }
            dataGridViewReplace2.Rows.Add();
            dataGridViewReplace2.Rows[0].DefaultCellStyle.BackColor = Color.LightGoldenrodYellow;
        }

        private void dataGridView_CellPainting(object sender, DataGridViewCellPaintingEventArgs e)
        {
            if (e.ColumnIndex == -1 && e.RowIndex > -1)
            {
                e.PaintBackground(e.CellBounds, true);

                using (SolidBrush br = new SolidBrush(Color.Black))
                {
                    StringFormat sf = new StringFormat();
                    sf.Alignment = StringAlignment.Center;
                    sf.LineAlignment = StringAlignment.Center;
                    if (e.RowIndex == 0 && ((DataGridView)sender).Name == "dataGridViewSearch")
                        e.Graphics.DrawString("Search", e.CellStyle.Font, br, e.CellBounds, sf);
                    else
                        e.Graphics.DrawString("Modify", e.CellStyle.Font, br, e.CellBounds, sf);
                }
                e.Handled = true;
            }
        }

        private void dataGridView_EditingControlShowing(object sender, DataGridViewEditingControlShowingEventArgs e)
        {
            e.CellStyle.BackColor = Color.Aquamarine;
            TextBox tx = e.Control as TextBox;
            tx.KeyPress += tx_KeyPress;
            tx.TextChanged += tx_TextChanged;
            tx.LostFocus += tx_LostFocus;
        }

        private void tx_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Escape || e.KeyChar == (char)Keys.Back)
                return;

            if (!int.TryParse(e.KeyChar.ToString(), NumberStyles.HexNumber, CultureInfo.InvariantCulture, out int result))
            {
                e.Handled = true;
            }
            else
            {
                e.KeyChar = Char.ToUpper(e.KeyChar);
            }
        }

        private void tx_TextChanged(object sender, EventArgs e)
        {
            TextBox tx = sender as TextBox;
            var dgv = (DataGridView)tx.Parent.Parent;
            int iColumn = dgv.CurrentCell.ColumnIndex;
            int iRow = dgv.CurrentCell.RowIndex;

            if (iColumn < dgv.Columns.Count - 1 && tx.Text.Length == 2)
            {
                dgv.CurrentCell = dgv[iColumn + 1, iRow];
            }
        }
        
        private void tx_LostFocus(Object sender, EventArgs e)
        {
            var tx = sender as TextBox;
            tx.TextChanged -= tx_TextChanged;
        }

        private void dataGridView_KeyDown(object sender, KeyEventArgs e)
        {
            var dgv = sender as DataGridView;
            if (e.KeyCode == Keys.Delete)
            {
                int iColumn = dgv.CurrentCell.ColumnIndex;
                int iRow = dgv.CurrentCell.RowIndex;
                dgv[iColumn, iRow].Value = "";
            }
            if (e.KeyCode == Keys.Back)
            {
                int iColumn = dgv.CurrentCell.ColumnIndex;
                int iRow = dgv.CurrentCell.RowIndex;
                if (dgv[iColumn, iRow].Value != null)
                {
                    var value = dgv[iColumn, iRow].Value.ToString();
                    dgv[iColumn, iRow].Value = value.Remove(value.Length - 1);
                }
                dgv.BeginEdit(false);
            }
        }

        private void SetDataGridViewsVisibility()
        {
            if (radioButton1.Checked)
            {
                dataGridViewSearch.Rows[1].Visible = true;
                dataGridViewReplace.Visible = false;
                dataGridViewReplace2.Visible = false;
                dataGridViewSearch.Height = 85;
            }
            else if (radioButton2.Checked)
            {
                dataGridViewSearch.Rows[1].Visible = false;
                dataGridViewReplace.Visible = true;
                dataGridViewReplace2.Visible = false;
                dataGridViewSearch.Height = 63;
            }
            else if (radioButton3.Checked)
            {
                dataGridViewSearch.Rows[1].Visible = false;
                dataGridViewReplace.Visible = false;
                dataGridViewReplace2.Visible = true;
                dataGridViewSearch.Height = 63;
                dataGridViewReplace2.FirstDisplayedScrollingColumnIndex = 242;

            }

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            SetDataGridViewsVisibility();
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            SetDataGridViewsVisibility();
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            SetDataGridViewsVisibility();
        }

        private void btnApply_Click(object sender, EventArgs e)
        {
            var searches = new Dictionary<int, byte>();
            var replaces = new Dictionary<int, byte>();
            FilterModes filterMode = FilterModes.SearchAndReplaceFromBegin;
            Byte result;
            for (var i = 0; i < 501; i++)
            {
                if (dataGridViewSearch[i, 0].Value != null && Byte.TryParse(dataGridViewSearch[i, 0].Value.ToString(), NumberStyles.HexNumber, CultureInfo.InvariantCulture, out result))
                    searches.Add(i, result);
            }

            if ( (radioButton2.Checked || radioButton3.Checked) && (searches.Count == 0 || !searches.ContainsKey(0)) )
            {
                MessageBox.Show(@"The chain to search must start at the offset 0");
                return;
            }
                  
            if (radioButton1.Checked)
            {
                filterMode = FilterModes.SearchAndReplaceFromBegin;
                for (var i = 0; i < 501; i++)
                {
                    if (dataGridViewSearch[i, 1].Value != null && Byte.TryParse(dataGridViewSearch[i, 1].Value.ToString(), NumberStyles.HexNumber, CultureInfo.InvariantCulture, out result))
                        replaces.Add(i, result);
                }
            }
            else if (radioButton2.Checked)
            {
                filterMode = FilterModes.SearchOcurrenceReplaceFromBegin;
                for (var i = 0; i < 501; i++)
                {
                    if (dataGridViewReplace[i, 0].Value != null && Byte.TryParse(dataGridViewReplace[i, 0].Value.ToString(), NumberStyles.HexNumber, CultureInfo.InvariantCulture, out result))
                        replaces.Add(i, result);
                }
            }
            else if (radioButton3.Checked)
            {
                filterMode = FilterModes.SearchOcurrenceReplaceFromPosition;
                for (var i = 0; i < 501; i++)
                {
                    if (dataGridViewReplace2[i, 0].Value != null && Byte.TryParse(dataGridViewReplace2[i, 0].Value.ToString(), NumberStyles.HexNumber, CultureInfo.InvariantCulture, out result))
                        replaces.Add(i, result);
                }
            }

            FilterCaptureFuncs functions = BuildFunctionsBitMask();
            FilterActions actions = BuildActionsBitMask();
            uint packetLengthMin = 0;
            uint packetLengthMax = 0;
            if (chkPackeLength.Checked)
            {
                packetLengthMin = (uint)nudPacketLengthMin.Value;
                packetLengthMax = (uint)nudPacketLengthMax.Value;
            }
                
            string name = txtFilterName.Text;
            if (name == "" && _filterIndex == -1)
                name = "Filter "+ (FilterManager.GetNumberOfFiltersInList()+1).ToString("D2");

            if (_filterIndex == -1)
                FilterManager.NewFilter(chkActive.Checked, filterMode, functions, actions, name, packetLengthMin, packetLengthMax, (uint)nudNumTimesApply.Value, searches, replaces);
            else
                FilterManager.EditFilter(_filterIndex, chkActive.Checked, filterMode, functions, actions, name, packetLengthMin, packetLengthMax, (uint)nudNumTimesApply.Value, searches, replaces);
            
            Program.mainForm.LoadFilterItems();
            Program.mainForm.ActionStartStopFiltering(false);
            Close();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            Close();
        }

        private FilterCaptureFuncs BuildFunctionsBitMask()
        {
            FilterCaptureFuncs functions = FilterCaptureFuncs.None;
            if (chkWSSend.Checked)
                functions |= FilterCaptureFuncs.WSSend;
            if (chkWSSendTo.Checked)
                functions |= FilterCaptureFuncs.WSSendTo;
            if (chkWSRecv.Checked)
                functions |= FilterCaptureFuncs.WSRecv;
            if (chkWSRecvFrom.Checked)
                functions |= FilterCaptureFuncs.WSRecvFrom;

            if (chkWS2Send.Checked)
                functions |= FilterCaptureFuncs.WS2Send;
            if (chkWS2SendTo.Checked)
                functions |= FilterCaptureFuncs.WS2SendTo;
            if (chkWS2Recv.Checked)
                functions |= FilterCaptureFuncs.WS2Recv;
            if (chkWS2RecvFrom.Checked)
                functions |= FilterCaptureFuncs.WS2RecvFrom;

            if (chkWSASend.Checked)
                functions |= FilterCaptureFuncs.WSASend;
            if (chkWSASendTo.Checked)
                functions |= FilterCaptureFuncs.WSASendTo;
            if (chkWSARecv.Checked)
                functions |= FilterCaptureFuncs.WSARecv;
            if (chkWSARecvFrom.Checked)
                functions |= FilterCaptureFuncs.WSARecvFrom;

            if (chkPRRead.Checked)
                functions |= FilterCaptureFuncs.PRRead;
            if (chkPRWrite.Checked)
                functions |= FilterCaptureFuncs.PRWrite;
            if (chkPRSend.Checked)
                functions |= FilterCaptureFuncs.PRSend;
            if (chkPRRecv.Checked)
                functions |= FilterCaptureFuncs.PRRecv;

            if (chkSSLEncryptPacket.Checked)
                functions |= FilterCaptureFuncs.SSLEncryptPacket;
            if (chkSSLDecryptPacket.Checked)
                functions |= FilterCaptureFuncs.SSLDecryptPacket;
            if (chkEncryptMessage.Checked)
                functions |= FilterCaptureFuncs.EncryptMessage;
            if (chkDecryptMessage.Checked)
                functions |= FilterCaptureFuncs.DecryptMessage;
            if (chkSSLWrite.Checked)
                functions |= FilterCaptureFuncs.SSLWrite;
            if (chkSSLRead.Checked)
                functions |= FilterCaptureFuncs.SSLRead;

            return functions;
        }

        private FilterActions BuildActionsBitMask()
        {
            FilterActions actions = FilterActions.None;
            if (chkBlock.Checked)
                actions |= FilterActions.Block;
            if (chkWatch.Checked)
                actions |= FilterActions.Watch;
            if (chkIgnore.Checked)
                actions |= FilterActions.Ignore;
            if (chkBreak.Checked)
                actions |= FilterActions.Break;

            return actions;
        }

        private void SetFunctionsAndActionsWithBitMask(FilterActions actions, FilterCaptureFuncs functions)
        {
            chkBlock.Checked = actions.HasFlag(FilterActions.Block);
            chkWatch.Checked = actions.HasFlag(FilterActions.Watch);
            chkIgnore.Checked = actions.HasFlag(FilterActions.Ignore);
            chkBreak.Checked = actions.HasFlag(FilterActions.Break);

            chkWSSend.Checked = functions.HasFlag(FilterCaptureFuncs.WSSend);
            chkWSSendTo.Checked = functions.HasFlag(FilterCaptureFuncs.WSSendTo);
            chkWSRecv.Checked = functions.HasFlag(FilterCaptureFuncs.WSRecv);
            chkWSRecvFrom.Checked = functions.HasFlag(FilterCaptureFuncs.WSRecvFrom);

            chkWS2Send.Checked = functions.HasFlag(FilterCaptureFuncs.WS2Send);
            chkWS2SendTo.Checked = functions.HasFlag(FilterCaptureFuncs.WS2SendTo);
            chkWS2Recv.Checked = functions.HasFlag(FilterCaptureFuncs.WS2Recv);
            chkWS2RecvFrom.Checked = functions.HasFlag(FilterCaptureFuncs.WS2RecvFrom);

            chkWSASend.Checked = functions.HasFlag(FilterCaptureFuncs.WSASend);
            chkWSASendTo.Checked = functions.HasFlag(FilterCaptureFuncs.WSASendTo);
            chkWSARecv.Checked = functions.HasFlag(FilterCaptureFuncs.WSARecv);
            chkWSARecvFrom.Checked = functions.HasFlag(FilterCaptureFuncs.WSARecvFrom);

            chkPRSend.Checked = functions.HasFlag(FilterCaptureFuncs.PRSend);
            chkPRRecv.Checked = functions.HasFlag(FilterCaptureFuncs.PRRecv);
            chkPRRead.Checked = functions.HasFlag(FilterCaptureFuncs.PRRead);
            chkPRWrite.Checked = functions.HasFlag(FilterCaptureFuncs.PRWrite);

            chkSSLEncryptPacket.Checked = functions.HasFlag(FilterCaptureFuncs.SSLEncryptPacket);
            chkSSLDecryptPacket.Checked = functions.HasFlag(FilterCaptureFuncs.SSLDecryptPacket);
            chkEncryptMessage.Checked = functions.HasFlag(FilterCaptureFuncs.EncryptMessage);
            chkDecryptMessage.Checked = functions.HasFlag(FilterCaptureFuncs.DecryptMessage);
            chkSSLRead.Checked = functions.HasFlag(FilterCaptureFuncs.SSLRead);
            chkSSLWrite.Checked = functions.HasFlag(FilterCaptureFuncs.SSLWrite);

        }

        private void chkPackeLength_CheckedChanged(object sender, EventArgs e)
        {
                nudPacketLengthMax.Enabled = chkPackeLength.Checked;
                nudPacketLengthMin.Enabled = chkPackeLength.Checked;
        }

        private void chkIgnore_CheckedChanged(object sender, EventArgs e)
        {
            if (chkIgnore.Checked)
                chkWatch.Checked = false;
        }

        private void chkWatch_CheckedChanged(object sender, EventArgs e)
        {
            if (chkWatch.Checked)
                chkIgnore.Checked = false;
        }

        private void nudPacketLengthMin_ValueChanged(object sender, EventArgs e)
        {
            nudPacketLengthMax.Minimum = nudPacketLengthMin.Value;
            
        }

        private void nudPacketLengthMax_ValueChanged(object sender, EventArgs e)
        {

        }
    }
}
