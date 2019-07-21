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
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Windows.Forms;
using OSPE.Properties;
using OPSE_HotKeys;

namespace OSPE
{
    public partial class MainForm : Form
    {
        public int processInyectedId = 0;
        private delegate void VoidDelegate();
        private DateTime lastClickTime = new DateTime();
        private List<CaptureRecord> _captures; // lista de capturas, inicialmente vacia
        private bool _isCapturing = false;
        private bool _isFiltering = false;
        private bool _isScriptActive = false;
        private bool _isPaused = false;
        private bool _isAutoScrollOn = false;
        private bool _isViewAsHexOn = false;
        private int _captureCount; // Contador de capturas en memoria, solo se usa para dar nombres "Capture XX"
        private int _searchLastFound = -1; // Ultimo index del item encontrado

        public MainForm()
        {
            InitializeComponent();
            _captures = new List<CaptureRecord>();
            notifyIcon.ContextMenuStrip = trayMenuStrip;
            
            // Load settings
            if( ! Settings.FormSize.IsEmpty)
            {
                StartPosition = FormStartPosition.Manual;
                Location = Settings.FormLocation;
                Size = Settings.FormSize;

                if (Settings.FormState == FormWindowState.Maximized)
                    WindowState = FormWindowState.Maximized;

                if(Settings.LogOpened)
                    LogForm.Show();

                Output.LogEnabled = Settings.LogEnabled;

                _isViewAsHexOn = Settings.ViewAsHex;
                _isAutoScrollOn = Settings.AutoScroll;
                splitContainerTabsAndHex.SplitterDistance = Settings.SpliterDistanceTabsAndHex;
                splitFilterAndConversions.SplitterDistance = Settings.SpliterDistanceFilterAndConversions;

            }

            InitListViews();

            Resize += OnResize;
            Closed += frmMainClosed;
                        
            FilterManager.LoadTempFilterList();
            LoadFilterItems();
            LoadSendListItems();
            LoadHotKeys();
            UpdateControls();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {

        }

        private void UpdateControls()
        {
            // Packet Capture
            if (_isCapturing)
            {
                // Capture started
                btnStartPauseCapture.Text = "Pause Capture";
                btnStartPauseCapture.Image = Resources.Pause16;
                
            }
            else if (_isPaused)
            {
                // Capture paused
                btnStartPauseCapture.Text = "Continue   ";
                btnStartPauseCapture.Image = Resources.Play16;
            }
            else
            {
                btnStartPauseCapture.Text = "Start Capture";
                btnStartPauseCapture.Image = Resources.Play16;
                btnClearPacketList.Enabled = false;
            }
            btnStopCapture.Enabled = _isCapturing;
            tsmiMenuStartCapture.Enabled = !_isCapturing;
            tsmiMenuStopCapture.Enabled = _isCapturing;
            trayTsmiStartCapture.Enabled = !_isCapturing;
            trayTsmiStopCapture.Enabled = _isCapturing;
            // Filters active
            chkActiveFilters.CheckedChanged -= chkActiveFilters_CheckedChanged;
            chkActiveFilters.Checked = _isFiltering;
            chkActiveFilters.CheckedChanged += chkActiveFilters_CheckedChanged;
            tsmiActiveFilters.Checked = _isFiltering;
            trayTsmiActiveFilters.Checked = _isFiltering;
            ((Control)this.tabFilters).Enabled = !_isFiltering;
            lvFilters.Columns[0].Text = "Filters " + (_isFiltering ? "(Active)" : "(Inactive)");
            // Script DLL
            chkActiveCustomScript.CheckedChanged -= chkActiveCustomScript_CheckedChanged;
            chkActiveCustomScript.Checked = _isScriptActive;
            chkActiveCustomScript.CheckedChanged += chkActiveCustomScript_CheckedChanged;
            tsmiActiveCustomFilters.Checked = _isScriptActive;
            trayTsmiActiveCustomFilter.Checked = _isScriptActive;
            // Auto Scroll
            chkAutoScroll.CheckedChanged -= checkAutoScroll_CheckedChanged;
            chkAutoScroll.Checked = _isAutoScrollOn;
            chkAutoScroll.CheckedChanged += checkAutoScroll_CheckedChanged;
            tsmiAutoScroll.Checked = _isAutoScrollOn;
            // View As Hex
            checkBoxViewAsHex.CheckedChanged -= checkBoxViewAsHex_CheckedChanged;
            checkBoxViewAsHex.Checked = _isViewAsHexOn;
            checkBoxViewAsHex.CheckedChanged += checkBoxViewAsHex_CheckedChanged;
            tsmiViewAsHex.Checked = _isViewAsHexOn;
        }

        private void frmMainClosed(object sender, EventArgs e)
        {
            Settings.LogOpened = LogForm.Visible;
            Settings.ViewAsHex = tsmiViewAsHex.Checked;
            Settings.AutoScroll = tsmiAutoScroll.Checked;
            Settings.SpliterDistanceTabsAndHex = splitContainerTabsAndHex.SplitterDistance;
            Settings.SpliterDistanceFilterAndConversions = splitFilterAndConversions.SplitterDistance;

            if (WindowState == FormWindowState.Normal)
            {
                Settings.FormLocation = Location;
                Settings.FormSize = Size;
                Settings.FormState = FormWindowState.Normal;
            }
            else
            {
                Settings.FormState = WindowState;
            }

            Settings.CurrentTab = tabControlMain.SelectedIndex;
            Settings.CurrentCaptureFilterTab = tabControlCapturesAndFilters.SelectedIndex;
            if (FilterManager.GetNumberOfFiltersInList() > 0)
                FilterManager.SaveTempFilterList();
        }

        private void frmMain_Resize(object sender, System.EventArgs e)
        {
            if (WindowState == FormWindowState.Minimized && Settings.MinimizeToSystemTray)
                Hide(); // Minimize to tray
        }

        #region Ospe internal private functions - state variables & checks

        private void AddToCaptureList()
        {
            // Save the capture if there are packets in the list
            if (PacketManager.IsModifiedList)
            {
                CaptureRecord cr = new CaptureRecord(PacketManager.PacketList, PacketManager.Both, PacketManager.Sent,
                    PacketManager.Received, PacketManager.Watch);
                _captures.Add(cr);
                _captureCount++;
                lvCaptures.Items.Add(new ListViewItem(new[] { "Capture " + _captureCount.ToString("D2") + " (" + cr.GetCaptureDateTime().ToLongTimeString() + ")", _captures.Count.ToString() }));
            }            
        }
        private void StartCapture()
        {
            if (!_isPaused)
                ClearPacketLists();
            _isPaused = false;
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_STARTCAPTURE);
            PacketManager.StartCapture();
            _isCapturing = true;
        }
        private void StopCapture()
        {
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_STOPCAPTURE);
            PacketManager.StopCapture();
            _isCapturing = false;
        }
        private void PauseCapture()
        {
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_STOPCAPTURE);
            PacketManager.StopCapture();
            _isCapturing = false;
            _isPaused = true;
        }
        private void ClearPacketLists()
        {
            PacketManager.ClearStorage();
            lvwReceived.VirtualListSize = 0;
            lvwSent.VirtualListSize = 0;
            lvwBoth.VirtualListSize = 0;
            lvwWatch.VirtualListSize = 0;
            ListItems.Clear();
        }
        private void StartFiltering()
        {
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_STARTFILTERING);
            PacketManager.StartFiltering();
            _isFiltering = true;
        }
        private void StopFiltering()
        {
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_STOPFILTERING);
            PacketManager.StopFiltering();
            _isFiltering = false;
        }
        private void StartScript()
        {
            InjectDllEx();
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_LOADDLLEX);
            _isScriptActive = true;
        }
        private void StopScript()
        {
            DllCommunication.WriteCommandToCmdMMF(ServerCodes.SCODE_UNLOADDLLEX);
            _isScriptActive = false;
        }
        /// <summary>
        /// Check that there is a DLL to inject, if not exists, an open file dialog will open
        /// </summary>
        /// <returns>False if no file is selected, True otherwise</returns>
        private bool CheckDllFile(bool ex = false)
        {
            var setting = ex ? Settings.DLLEx : Settings.DLL;
            if (setting == "" || !File.Exists(setting))
            {
                openFileDialog.Filter = "Dll files|*.dll";
                openFileDialog.Title = "Please, select ospe.dll location.";
                DialogResult result = openFileDialog.ShowDialog();

                if (result == DialogResult.OK)
                {
                    if (ex)
                        Settings.DLLEx = openFileDialog.FileName;
                    else
                        Settings.DLL = openFileDialog.FileName;
                }
                else
                    return false;
            }
            return true;
        }
        /// <summary>
        /// Injects the last process created (with higher StartTime) which has the same name of the latest injected process (using Select Process)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void InjectLastProcess()
        {
            if (!CheckDllFile() || Settings.LastProcessInjected == "") return;
            var procs = Process.GetProcessesByName(Settings.LastProcessInjected);
            if (procs.Length == 0) return;
            var lastProc = procs[0];
            for (int i = 1; i < procs.Length; i++)
                if (procs[i - 1].StartTime.CompareTo(procs[i].StartTime) < 0)
                    lastProc = procs[i];

            string err;
            Inject.DoInject(lastProc, Settings.DLL, out err);
            if (err != "")
                MessageBox.Show(err);
            else
            {
                DllCommunication.SetTargetPid(lastProc.Id);
                DllCommunication.StartPacketReaderMMF();
                this.Text = "OSPE - PID: " + lastProc.Id + " - " + lastProc.ProcessName;
                this.processInyectedId = lastProc.Id;
                ActionStartStopFiltering(false);
                ActionStopCapture();
                ActionStartStopScript(false);
            }
              
        }
        private void InjectDllEx()
        {
            if (!CheckDllFile(true)) return;
            var procs = Process.GetProcessById(processInyectedId);
            string err;
            Inject.DoInject(procs, Settings.DLLEx, out err);
            if (err != "")
                MessageBox.Show(err);
            else  {
            }
        }
        private bool CheckIfProcessIsInyected()
        {
            if (processInyectedId == 0)
                ActionSelectProcess();
            return processInyectedId != 0;
        }

        #endregion

        #region interface actions

        public void ActionExitProgram()
        {
            Close();
        }
        public void ActionStartCapture()
        {
            if (!CheckIfProcessIsInyected()) return;
            StartCapture();
            UpdateControls();
        }
        public void ActionPauseCapture()
        {
            if (!CheckIfProcessIsInyected()) return;
            PauseCapture();
            UpdateControls();
        }
        public void ActionStopCapture()
        {
            if (processInyectedId == 0) return;
            StopCapture();
            AddToCaptureList();
            ClearPacketLists();
            UpdateControls();
        }
        private void ActionClearPacketList()
        {
            ClearPacketLists();
            btnClearPacketList.Enabled = false;
        }
        public void ActionStartStopFiltering(bool enable)
        {
            if (!CheckIfProcessIsInyected()) return;
            if (enable)
                StartFiltering();
            else
                StopFiltering();

            UpdateControls();
        }
        public void ActionStartStopScript(bool enable)
        {
            if (!CheckIfProcessIsInyected()) return;
            if (enable)
                StartScript();
            else
                StopScript();

            UpdateControls();
        }
        public void ActionSelectProcess()
        {
            if (CheckDllFile())
            { 
                Cursor.Current = Cursors.WaitCursor;
                new SelectProcessForm().ShowDialog();
            }
        }
        public void ActionInjectLastProcess()
        {
            InjectLastProcess();
        }
        private void ActionViewAsHex(bool set)
        {
            _isViewAsHexOn = set;
            Settings.ViewAsHex = set;
            UpdateControls();
            // Se guarda el tiempo en el que se produjo el cambio para que los items que están desactualizados se actualizen.
            LastUIChange = Environment.TickCount;

            switch ((Tab)tabControlMain.SelectedIndex)
            {
                case Tab.Received:
                    lvwReceived.Refresh();
                    break;
                case Tab.Sent:
                    lvwSent.Refresh();
                    break;
                case Tab.Both:
                    lvwBoth.Refresh();
                    break;
            }
        }
        private void ActionSetAutoScrollToBottom(bool active)
        {
            _isAutoScrollOn = active;
            ScrollToBottom();
            UpdateControls();
        }
        private void ActionClearFilterList()
        {
            FilterManager.ClearFilterList();
            LoadFilterItems();
        }
        private void ActionMainOrTrayMenuOpen()
        {
            if (Settings.LastProcessInjected == "") 
            {
                tsmiMenuInjectLast.Enabled = false;
                trayTsmiInjectLastProc.Enabled = false;
            }
            else 
            {
                tsmiMenuInjectLast.Text = "Inject " + Settings.LastProcessInjected + ".exe";
                trayTsmiInjectLastProc.Text = "Inject " + Settings.LastProcessInjected + ".exe";
            }
        }
        public void ActionSearchNext()
        {
            int itemCount;
            ListView lv;

            if (txtSearch.Text == "" || txtSearch.Text == "Search...")
                return;

            switch ((Tab)tabControlMain.SelectedIndex)
            {
                case Tab.Both:
                    itemCount = lvwBoth.VirtualListSize; // Usamos el virtualSize para trabajar sobre indices 
                    lv = lvwBoth;                        // de lista existentes (refrescados en la view) 
                    break;
                case Tab.Received:
                    itemCount = lvwReceived.VirtualListSize;
                    lv = lvwReceived;
                    break;
                case Tab.Sent:
                    itemCount = lvwSent.VirtualListSize;
                    lv = lvwSent;
                    break;
                case Tab.Watch:
                    itemCount = lvwWatch.VirtualListSize;
                    lv = lvwWatch;
                    break;
                default:
                    throw new NotImplementedException();
            }

            for (int i = _searchLastFound + 1; i < itemCount; i++)
            {
                var id = GetPacketIdFromTableItemIndex(lv, i);
                Packet pkt = PacketManager.PacketList[id];
                string buffer = radioSearchHex.Checked ? pkt.GetBufferAsHex().Replace(" ", string.Empty) : pkt.GetBufferAsText();
                string search = radioSearchHex.Checked ? txtSearch.Text.Replace(" ", string.Empty).ToUpper() : txtSearch.Text;
                if (buffer.Contains(search))
                {
                    lv.Items[i].Selected = true;
                    lv.Select();
                    lv.Items[i].EnsureVisible();
                    _searchLastFound = i;
                    return;
                }
            }
            MessageBox.Show("End of search. Cannot find \"" + txtSearch.Text + "\"");
            _searchLastFound = -1; // No hubo coincidencias
        }
        
        #endregion

        #region Quick access bar controls

        private void btnStartPauseCapture_Click(object sender, EventArgs e)
        {
            if (_isCapturing)
                ActionPauseCapture();
            else
                ActionStartCapture();
        }
        private void btnStopCapture_Click(object sender, EventArgs e)
        {
            ActionStopCapture();
        }
        private void chkActiveFilters_CheckedChanged(object sender, EventArgs e)
        {
            ActionStartStopFiltering(chkActiveFilters.Checked);
        }
        private void chkActiveCustomScript_CheckedChanged(object sender, EventArgs e)
        {
            ActionStartStopScript(chkActiveCustomScript.Checked);
        }
        private void buttonClearList_Click(object sender, EventArgs e)
        {
            ActionClearPacketList();
        }
        private void checkBoxViewAsHex_CheckedChanged(object sender, EventArgs e)
        {
            ActionViewAsHex(checkBoxViewAsHex.Checked);
        }
        private void checkAutoScroll_CheckedChanged(object sender, EventArgs e)
        {
            ActionSetAutoScrollToBottom(chkAutoScroll.Checked);
        }
        private void btnSearch_Click(object sender, EventArgs e)
        {
            ActionSearchNext();
        }
        private void txtSearch_Enter(object sender, EventArgs e)
        {
            if (txtSearch.Text == "Search...")
                txtSearch.Text = "";
        }
        private void radioSearchString_CheckedChanged(object sender, EventArgs e)
        {
            if (radioSearchString.Checked)
                radioSearchHex.Checked = false;
        }
        private void radioSearchHex_CheckedChanged(object sender, EventArgs e)
        {
            if (radioSearchHex.Checked)
                radioSearchString.Checked = false;
        }
        
        #endregion

        #region ToolStripMenu Items

        // Main menu -----------
        private void tsmiProgram_Click(object sender, EventArgs e)
        {
            ActionMainOrTrayMenuOpen();
        }
        private void tsmiStartCapture_Click(object sender, EventArgs e)
        {
            ActionStartCapture();
        }
        private void tsmiStopCapture_Click(object sender, EventArgs e)
        {
            ActionStopCapture();
        }
        private void tsmiSelectProcess_Click(object sender, EventArgs e)
        {
            ActionSelectProcess();
        }
        private void tsmiInjectLast_Click(object sender, EventArgs e)
        {
            ActionInjectLastProcess();
        }
        private void tsmiConfigure_Click(object sender, EventArgs e)
        {
            new SettingsForm().Show();
        }
        private void tsmiExit_Click(object sender, EventArgs e)
        {
            ActionExitProgram();
        }
        private void tsmiViewAsHex_Click(object sender, EventArgs e)
        {
            ActionViewAsHex(!_isViewAsHexOn);
        }
        private void tsmiAutoScroll_Click(object sender, EventArgs e)
        {
            ActionSetAutoScrollToBottom(!_isAutoScrollOn);
        }
        private void tsmiScriptEditor_Click(object sender, EventArgs e)
        {
            new CustomFilterForm().Show();
        }
        private void tsmiActiveFilters_CheckedChanged(object sender, EventArgs e)
        {
            ActionStartStopFiltering(!_isFiltering);
        }
        private void tsmiViewLog_Click(object sender, EventArgs e)
        {
            LogForm.Show();
        }
        private void tsmiDisplayQuickBar_Click(object sender, EventArgs e)
        {
            groupBox1.Visible = !groupBox1.Visible;
        }
        private void tsmiActiveCustomFilters_CheckStateChanged(object sender, EventArgs e)
        {
            ActionStartStopScript(!_isScriptActive);
        }
        private void tsmiPacketInjector_Click(object sender, EventArgs e)
        {
            Form injectForm = new Forms.PacketInjectorForm();
            injectForm.Show();
        }
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Forms.AboutBox aboutForm = new Forms.AboutBox();
            aboutForm.StartPosition = FormStartPosition.CenterScreen;
            aboutForm.Show();
        }
        // Tray menu  --------------------------
        private void trayIcon_Click(object sender, EventArgs  e)
        {
            ActionMainOrTrayMenuOpen();
            if (MouseButtons.Left == ((MouseEventArgs)e).Button)
            {
                Show();
                WindowState = FormWindowState.Normal;
                Activate();
            }

        }
        private void trayMenuExit_Click(object sender, EventArgs e)
        {
            ActionExitProgram();
        }
        private void trayMenuOpen_Click(object sender, EventArgs e)
        {
            Show();
            WindowState = FormWindowState.Normal;
            BringToFront();
        }

        #endregion

        #region Capture ListView methods 

        private void cmsCaptureList_Opening(object sender, CancelEventArgs e)
        {
            // Si hay un item seleccionado se habilitan las opciones para ese item
            if (lvCaptures.SelectedItems.Count > 0)
            {
                cmsCaptures.Items[0].Enabled = true;
                cmsCaptures.Items[1].Enabled = true;
            }
            else
            {
                cmsCaptures.Items[0].Enabled = false;
                cmsCaptures.Items[1].Enabled = false;
            }
        }
        private void lvCaptures_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (lvCaptures.SelectedItems.Count == 1)
            {
                ActionStopCapture(); // Paramos la captura antes
                                     // var recordId = int.Parse(lvCaptures.SelectedItems[0].SubItems[1].Text);
                var recordId = lvCaptures.Items.IndexOf(lvCaptures.SelectedItems[0]);
                var cr = _captures[recordId];
                foreach (Packet p in cr.GetPacketList())
                {
                    AddPacket(p);
                }
                PacketManager.LoadCapture(cr);
            }
        }
        private void tsmiCaptureListOpen_Click(object sender, EventArgs e)
        {
            lvCaptures_MouseDoubleClick(null, null);
        }
        private void tsmiCaptureListDelete_Click(object sender, EventArgs e)
        {
            if (lvCaptures.SelectedItems.Count == 1)
            {
                var recordId = int.Parse(lvCaptures.SelectedItems[0].SubItems[1].Text);
                lvCaptures.Items.RemoveAt(recordId-1);
                _captures.RemoveAt(recordId-1);
            }
        }
        private void tsmiCaptureListSave_Click(object sender, EventArgs e)
        {
            var sfd = new SaveFileDialog
            {
                Title = "Save capure list",
                Filter = "OSPE capture files (*.ospec)|*.ospec|All files (*.*)|*.*"
            };
            var result = sfd.ShowDialog();
            if (result == DialogResult.OK)
            {
                Serializer.SerializeOspeCaptureList(sfd.FileName, _captures);
            }
        }
        private void tsmiCaptureListLoad_Click(object sender, EventArgs e)
        {
            var ofd = new OpenFileDialog
            {
                Title = "Open capture list",
                Filter = "OSPE capture files (*.ospec)|*.ospec|All files (*.*)|*.*"
            };
            var result = ofd.ShowDialog();
            if (result == DialogResult.OK)
            {
                _captures = Serializer.DeSerializeOspeCaptureList(ofd.FileName);
            }
            _captureCount = 0;
            lvCaptures.Items.Clear();
            foreach (CaptureRecord cr in _captures)
            {
                _captureCount++;
                lvCaptures.Items.Add(new ListViewItem(new[] { "Capture " + _captureCount.ToString("D2") + " (" + cr.GetCaptureDateTime().ToLongTimeString() + ")", _captures.Count.ToString() }));
            }

        }
        private void tsmiCaptureListClear_Click(object sender, EventArgs e)
        {
            _captures.Clear();
            lvCaptures.Items.Clear();
            _captureCount = 0;
        }
        
        #endregion

        #region Filters ListView methods

        public void LoadFilterItems()
        {
            lvFilters.Items.Clear();
            var filterList = FilterManager.GetFilterList();
            lvFilters.ItemCheck -= lvFilters_ItemCheck;
            foreach (var filter in filterList)
            {
                var item = lvFilters.Items.Add(filter.Name);
                item.Checked = filter.Active;

            }
            lvFilters.ItemCheck += lvFilters_ItemCheck;
        }
        private void cmsFilterList_Opening(object sender, CancelEventArgs e)
        {
            // Si hay un item seleccionado se habilitan las opciones para ese item
            if (lvFilters.SelectedItems.Count > 0)
            {
                cmsFilters.Items[1].Visible = true;
                cmsFilters.Items[2].Visible = true;
            }
            else
            {
                cmsFilters.Items[1].Visible = false;
                cmsFilters.Items[2].Visible = false;
            }
        }
        private void lvFilters_ItemCheck(object sender, ItemCheckEventArgs e)
        {
            lastClickTime = DateTime.MinValue;
            FilterManager.SetFilterActive(e.Index, e.NewValue == CheckState.Checked);
        }
        private void lvFilters_Resize(object sender, EventArgs e)
        {
            ListViewResizeSizeLastColumn((ListView)sender);
        }
        private void tsmiFilterListAddNew_Click(object sender, EventArgs e)
        {
            if (FilterManager.GetNumberOfFiltersInList() >= 40)
                MessageBox.Show("Cannot create more than 40 filters.");
            else
                new FilterEditorForm();
        }
        private void tsmiFilterListEdit_Click(object sender, EventArgs e)
        {
            new FilterEditorForm(lvFilters.SelectedIndices[0]);
        }
        private void tsmiFilterListDelete_Click(object sender, EventArgs e)
        {
            FilterManager.DeleteFilter(lvFilters.SelectedIndices[0]);
            lvFilters.Items.RemoveAt(lvFilters.SelectedIndices[0]);
        }
        private void tsmiFilterListLoad_Click(object sender, EventArgs e)
        {
            FilterManager.LoadFilterList();
            LoadFilterItems();
        }
        private void tsmiFilterListSave_Click(object sender, EventArgs e)
        {
            FilterManager.SaveFilterList();
        }
        private void tsmiFilterListSaveAs_Click(object sender, EventArgs e)
        {
            FilterManager.SaveFilterList();
        }
        private void tsmiFilterListClear_Click(object sender, EventArgs e)
        {
            ActionClearFilterList();
        }

        #endregion

        #region SendList ListView methods

        public void LoadSendListItems()
        {
            lvSendList.Items.Clear();
            var sendList = SendManager.GetSendList();
            lvSendList.ItemCheck -= lvSendList_ItemCheck;
            foreach (var sendItem in sendList)
            {
                var item = lvSendList.Items.Add(sendItem.Name);
                item.Checked = sendItem.Active;

            }
            lvSendList.ItemCheck += lvSendList_ItemCheck;
        }
        private void cmsSendList_Opening(object sender, CancelEventArgs e)
        {
            // Si hay un item seleccionado se habilitan las opciones para ese item
            if (lvSendList.SelectedItems.Count > 0)
            {
                cmsSendList.Items[0].Enabled = true;
                cmsSendList.Items[1].Enabled = true;
            }
            else
            {
                cmsSendList.Items[0].Enabled = false;
                cmsSendList.Items[1].Enabled = false;
            }
        }
        private void lvSendList_ItemCheck(object sender, ItemCheckEventArgs e)
        {
            SendManager.SetSendListItemActive(e.Index, e.NewValue == CheckState.Checked);
        }
        private void tsmiSendListEdit_Click(object sender, EventArgs e)
        {
            (new Forms.PacketInjectorForm(lvSendList.SelectedIndices[0])).Show();
        }
        private void tsmiSendListDelete_Click(object sender, EventArgs e)
        {
            SendManager.DeleteSendListItem(lvSendList.SelectedIndices[0]);
        }
        private void tsmiSendListLoad_Click(object sender, EventArgs e)
        {
            SendManager.LoadSendList();
            LoadSendListItems();
        }
        private void tsmiSendListSave_Click(object sender, EventArgs e)
        {
            SendManager.SaveSendList();
        }
        private void tsmiSendListClear_Click(object sender, EventArgs e)
        {
            SendManager.ClearSendList();
            LoadSendListItems();
        }
        
        #endregion


        private void hexBox_SelectionLengthChanged(object sender, EventArgs e)
        {
            UpdateConversionsValues();
        }
        private void hexBox_SelectionStartChanged(object sender, EventArgs e)
        {
            //LogForm.WriteLine(hexBox.SelectionLength.ToString() + "  -  " + hexBox.SelectionStart.ToString());
            UpdateConversionsValues();
        }
        private void UpdateConversionsValues()
        {
            long start = hexBox.SelectionStart;
            // si selecciona valores entonces solo convierte esos valores
            long selected = hexBox.SelectionLength;
            if (selected == 0 || selected > 8)
                selected = 8;

            long last = hexBox.ByteProvider.Length;
            long end = Math.Min(start + selected, last);

            // put bytes into buffer
            byte[] buffer64 = new byte[8];
            int id = -1;
            for (long i = start; i < end; i++)
            {
                id++;
                buffer64[id] = hexBox.ByteProvider.ReadByte(i);
            }

            txtConverPos.Text = start.ToString();
            txtConverChar.Text = Convert.ToChar(buffer64[0]).ToString();
            txtConverByte.Text = (buffer64[0]).ToString();
            txtConverShort.Text = BitConverter.ToInt16(buffer64, 0).ToString();
            txtConverUShort.Text = BitConverter.ToUInt16(buffer64, 0).ToString();
            txtConverInt32.Text = BitConverter.ToInt32(buffer64, 0).ToString();
            txtConverUInt32.Text = BitConverter.ToUInt32(buffer64, 0).ToString();
            txtConverInt64.Text = BitConverter.ToUInt64(buffer64, 0).ToString();
            txtConverUInt64.Text = BitConverter.ToUInt64(buffer64, 0).ToString();
            txtConverFloat.Text = BitConverter.ToSingle(buffer64, 0).ToString();
            txtConverDouble.Text = BitConverter.ToDouble(buffer64, 0).ToString();
            //LogForm.WriteLine(BitConverter.ToString(buffer64));

        }

        private void ListViewResizeSizeLastColumn(ListView lv)
        {
            lv.Columns[lv.Columns.Count - 1].Width = -2;
        }
        public void UpdateLabels(int packetsCount, int totalSizeReceived, int totalSizeSent)
        {
            if (InvokeRequired)
            {
                try
                {
                    if (!IsDisposed)
                        Invoke(new VoidDelegate(() => UpdateLabels(packetsCount, totalSizeReceived, totalSizeSent)));
                }
                catch
                {
                }
            }

            tslNumPackets.Text = packetsCount.ToString("N0");
            tslTotalReceived.Text = totalSizeReceived.ToString("N0");
            tslTotalSent.Text = totalSizeSent.ToString("N0");

            btnClearPacketList.Enabled = true;

        }

        private void LoadHotKeys()
        {
            SetKeyboardHook(ref HotKeys.searchNextKeyboardHook, HotKeys.hook_SearchNext, 114 /* F3 */);
            if (Settings.HotKeyStartCapture != 0)
                SetKeyboardHook(ref HotKeys.startCaptureKeyboardHook, HotKeys.hook_StartCapture, Settings.HotKeyStartCapture);
            if (Settings.HotKeyStopCapture != 0)
                SetKeyboardHook(ref HotKeys.stopCaptureKeyboardHook, HotKeys.hook_StopCapture, Settings.HotKeyStopCapture);
            if (Settings.HotKeyNormalFilter != 0)
                SetKeyboardHook(ref HotKeys.normalFilterKeyboardHook, HotKeys.hook_NormalFilter, Settings.HotKeyNormalFilter);
            if (Settings.HotKeyCustomFilter != 0)
                SetKeyboardHook(ref HotKeys.customFilterKeyboardHook, HotKeys.hook_CustomFilter, Settings.HotKeyCustomFilter);
            if (Settings.HotKeySelectProcess != 0)
                SetKeyboardHook(ref HotKeys.selectProcessKeyboardHook, HotKeys.hook_SelectProcess, Settings.HotKeySelectProcess);
            if (Settings.HotKeyInjectLast != 0)
                SetKeyboardHook(ref HotKeys.injectLastKeyboardHook, HotKeys.hook_InjectLast, Settings.HotKeyInjectLast);
        }
        private static void SetKeyboardHook(ref KeyboardHook hook, EventHandler<KeyPressedEventArgs> func, int keyData)
        {
            // Get Key and Modifiers from KeyData
            Keys data = (Keys)keyData;
            Keys key = data & Keys.KeyCode;
            Keys mods = data & Keys.Modifiers;

            // Set the hook
            hook = new KeyboardHook();
            // register the event that is fired after the key press.
            hook.KeyPressed += func;
            try
            {
                hook.RegisterHotKey(HotKeys.ToModKeys(mods), key);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }


    }
}
