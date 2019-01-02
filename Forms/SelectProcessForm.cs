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
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.Diagnostics;

// using System.IO;

namespace OSPE
{
    public partial class SelectProcessForm : Form
    {
        [DllImport("User32.dll")]
        private static extern bool SetForegroundWindow(IntPtr hWnd);
        // TODO: Parece innecesario este struct, se puede sacar todo de la variable Process (salvo el IconIndex)
        private struct ProcInfo
        {
            public readonly int Id;
            public readonly string Name;
            public readonly string Path;
            public readonly int IconIndex;
            public readonly DateTime StartTime;
            public readonly Process Process;

            public ProcInfo(int pi, string na, string pa, DateTime st, int ic, Process pc)
            {
                Id = pi;
                Name = na;
                Path = pa;
                StartTime = st;
                IconIndex = ic;
                Process = pc;
            }

        }

        private readonly List<ProcInfo> _procInfos = new List<ProcInfo>();
        private readonly ImageList _imageList16 = new ImageList();
        private readonly ImageList _imageList24 = new ImageList();
        private readonly ImageList _imageList32 = new ImageList();

        /// <summary>
        /// Takes a snapshot of all running processes filling a _procInfos list and then sort it by process Start Time (newer processes first)
        /// </summary>
        private void GetAllRunningProcesses()
        {
            _imageList16.Images.Clear();
            _imageList24.Images.Clear();
            _imageList32.Images.Clear();
            _procInfos.Clear();
            foreach (Process proc in Process.GetProcesses())
            {
                try
                {
                    _procInfos.Add(new ProcInfo(proc.Id, proc.ProcessName, proc.MainModule.FileName, proc.StartTime, _imageList16.Images.Count, proc));
                    var icon = Icon.ExtractAssociatedIcon(proc.MainModule.FileName);
                    if (icon == null) continue;
                    _imageList16.Images.Add(icon);
                    _imageList24.Images.Add(icon);
                    _imageList32.Images.Add(icon);
                }
                catch (Exception ex)
                {
                    Output.outError("Cannot open process: {0} REASON: {1}", proc.ProcessName, ex.Message);
                }                
            }
            _procInfos.Sort((s1, s2) => s2.StartTime.CompareTo(s1.StartTime));  // Sort list by process start time (no sortable columns for now)
        }

        /// <summary>
        /// Adds the ProcInfo var to the ListView1
        /// </summary>
        /// <param name="proc">Process to be added</param>
        private void AddItemToListView(ProcInfo proc)
        {
            ListViewItem item = new ListViewItem(new string[] { proc.Name + ".exe", proc.Id.ToString(), proc.Path });
            item.ImageIndex = proc.IconIndex;
            lvwProcesses.Items.Add(item);
        }

        /// <summary>
        /// Fills the ListView with all processes
        /// </summary>
        private void FillGridViewList()
        {
            lvwProcesses.Items.Clear();
            foreach (var proc in _procInfos)
                AddItemToListView(proc);
        }

        /// <summary>
        /// Fills the ListView with all processes including 'startWith' in their name
        /// </summary>
        /// <param name="startWith">String to compare with the process name</param>
        private void FillGridViewList(string startWith)
        {
            lvwProcesses.Items.Clear();
            foreach (var proc in _procInfos.Where(process => process.Name.ToLower().Contains(startWith.ToLower())))
                AddItemToListView(proc);
        }

        /// <summary>
        /// Automatically resize the last collumn with the form width
        /// </summary>
        /// <param name="lv">ListView</param>
        private void SizeLastColumn(ListView lv)
        {
            lv.Columns[lv.Columns.Count - 1].Width = -2;
        }





        public SelectProcessForm()
        {
            InitializeComponent();

            StartPosition = FormStartPosition.Manual;
            Location = Settings.FormSelectProcessLocation;
            Size = Settings.FormSelectProcessSize;
            colName.Width = Settings.colName;
            colPid.Width = Settings.colPID;

            _imageList16.ColorDepth = ColorDepth.Depth32Bit;
            _imageList24.ColorDepth = ColorDepth.Depth32Bit;
            _imageList32.ColorDepth = ColorDepth.Depth32Bit;
            _imageList16.ImageSize = new Size(16, 16); // 16x16  24x24  32x32
            _imageList24.ImageSize = new Size(24, 24);
            _imageList32.ImageSize = new Size(32, 32);
            lvwProcesses.SmallImageList = _imageList16;
            lvwProcesses.LargeImageList = _imageList32;
            switch (Settings.SelectProcessViewMode)
            {
                case 16:
                    rdo16Icons.Checked = true;
                    lvwProcesses.View = View.Details;
                    break;
                case 24:
                    rdo24Icons.Checked = true;
                    lvwProcesses.LargeImageList = _imageList24;
                    lvwProcesses.View = View.Tile;
                    break;
                case 32:
                    rdo32Icons.Checked = true;
                    lvwProcesses.View = View.LargeIcon;
                    break;
            }

            Closed += On_Close;
        }

        private void On_Close(object sender, EventArgs e)
        {
            Settings.FormSelectProcessLocation = Location;
            Settings.FormSelectProcessSize = Size;
            Settings.colName = colName.Width;
            Settings.colPID = colPid.Width;
        }

        private void lvwProcesses_Resize(object sender, EventArgs e)
        {
            SizeLastColumn((ListView)sender);
        }

        private void frmSelectProcess_Load(object sender, EventArgs e)
        {
            GetAllRunningProcesses();
            FillGridViewList();
            Cursor.Current = Cursors.Default;
        }

        private void btnRefresh_Click(object sender, EventArgs e)
        {
            GetAllRunningProcesses();
            FillGridViewList();
        }

        private void txtSearch_TextChanged(object sender, EventArgs e)
        {
            FillGridViewList(txtSearch.Text);
        }

        private void txtSearch_Click(object sender, EventArgs e)
        {
            txtSearch.Text = "";
            txtSearch.Font = new Font(txtSearch.Font, FontStyle.Regular);
        }

        private void rdo16Icons_CheckedChanged(object sender, EventArgs e)
        {
            Settings.SelectProcessViewMode = 16;
            lvwProcesses.View = View.Details;
            lvwProcesses.Columns[lvwProcesses.Columns.Count - 1].Width = -2; // Workaround para hacer que se muestre el path
        }

        private void rdo24Icons_CheckedChanged(object sender, EventArgs e)
        {
            Settings.SelectProcessViewMode = 24;
            lvwProcesses.LargeImageList = _imageList24;
            lvwProcesses.View = View.Tile;
        }

        private void rdo32Icons_CheckedChanged(object sender, EventArgs e)
        {
            Settings.SelectProcessViewMode = 32;
            lvwProcesses.LargeImageList = _imageList32;
            lvwProcesses.View = View.LargeIcon;
        }

        private void lvwProcesses_MouseDoubleClick(object sender, EventArgs e)
        {
            ListView.SelectedListViewItemCollection itemCollection = lvwProcesses.SelectedItems;
            if (itemCollection.Count == 0) 
                return; // No item selected

            var pid = itemCollection[0].SubItems[1].Text;
            Process target = _procInfos.First(p => p.Process.Id == Convert.ToInt32(pid)).Process;
            string err;

            Inject.DoInject(target, Settings.DLL, out err);

            if (err != "")
                MessageBox.Show(err);
            else
            {
                Settings.LastProcessInjected = target.ProcessName;
                DllCommunication.SetTargetPid(target.Id);
                DllCommunication.StartPacketReaderMMF();
                Program.mainForm.Text = "OSPE - PID: " + target.Id + " - " + target.ProcessName;
                Program.mainForm.processInyectedId = target.Id;
                Program.mainForm.ActionStartStopFiltering(false);
                Program.mainForm.ActionStopCapture();
                Program.mainForm.ActionStartStopScript(false);
                Close();
            }
            
        }

        private void btnInject_Click(object sender, EventArgs e)
        {
            lvwProcesses_MouseDoubleClick(null, null); //=D
        }

        private void btnBringToFront_Click(object sender, EventArgs e)
        {
            ListView.SelectedListViewItemCollection itemCollection = lvwProcesses.SelectedItems;
            if (itemCollection.Count == 0)
                return; // No item selected

            var pid = itemCollection[0].SubItems[1].Text;
            Process target = _procInfos.First(p => p.Process.Id == Convert.ToInt32(pid)).Process;
            SetForegroundWindow(target.MainWindowHandle);
        }











    }
}
