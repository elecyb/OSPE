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
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace OSPE
{
    public sealed partial class LogForm : Form
    {
        // Delegates
        delegate void WriteLineCallback(string str);
        delegate void WriteLineColorCallback(string str, Color c);

        private static readonly LogForm instance = new LogForm();
        private static int FormThreadID = Thread.CurrentThread.ManagedThreadId;

        private LogForm()
        {
            InitializeComponent();

            if (!Settings.LogSize.IsEmpty)
            {
                StartPosition = FormStartPosition.Manual;
                Location = Settings.LogLocation;
                Size = Settings.LogSize;

                if (Settings.LogState == FormWindowState.Maximized)
                    WindowState = FormWindowState.Maximized;
            }
            FormClosing += FromClosing;
            // Se usa el evento Disposed ya que Closed no se produce en el caso de eliminar la instancia sin llamar al miembro Close()
            Disposed += frmLogEnded;
        }

        private void FromClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;
            frmLogEnded(sender, e);
            Hide();
        }

        private void frmLogEnded(object sender, EventArgs e)
        {
            if (instance.WindowState == FormWindowState.Normal)
            {
                Settings.LogLocation = Location;
                Settings.LogSize = Size;
                Settings.LogState = FormWindowState.Normal;
            }
            else
            {
                Settings.LogState = instance.WindowState;
            }
        }

        /// <summary>
        /// Escribe una linea en el RichTextBox con un \n al final.
        /// </summary>
        /// <param name="str">String to write</param>
        private void writeLine(string str)
        {
                richTextBox1.AppendText(str + "\n");
                richTextBox1.SelectionStart = richTextBox1.Text.Length;
                richTextBox1.ScrollToCaret();
        }

        /// <summary>
        ///  Escribe una linea de un color en el RichTextBox con un \n al final.
        /// </summary>
        /// <param name="str">String to write</param>
        /// <param name="color">Text color</param>
        private void writeLine(string str, Color color)
        {
                richTextBox1.SelectionStart = richTextBox1.TextLength;
                richTextBox1.SelectionLength = 0;
                richTextBox1.SelectionColor = color;
                richTextBox1.AppendText(str + "\n");
                richTextBox1.SelectionStart = richTextBox1.Text.Length;
                richTextBox1.ScrollToCaret();
        }

        private void richTextBox1_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                Point pt = richTextBox1.PointToScreen(e.Location);
                contextMenuStrip1.Show(pt);
            }            
        }

        private void frmLog_Load(object sender, EventArgs e)
        {
            richTextBox1.MouseDown += new MouseEventHandler(richTextBox1_MouseClick);
        }

        private void clearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
        }


        //********************** PUBLIC FUNCTIONS ******************//

        public new static bool Visible
        {
            get { return ((Control)instance).Visible; }
            set { ((Control)instance).Visible = value; }
        }
        public new static void Show()
        {
            ((Control) instance).Show();
            instance.BringToFront();
        }
        public static void WriteLine(string str)
        {
            if (instance.IsDisposed || !instance.IsHandleCreated)
                return;

            if (instance.richTextBox1.InvokeRequired)
                instance.Invoke(new WriteLineCallback(instance.writeLine), new object[] { str });
            else
                instance.writeLine(str);
        }
        public static void WriteLine(string str, Color color)
        {
            if (instance.IsDisposed || !instance.IsHandleCreated)
                return;

            if (instance.richTextBox1.InvokeRequired)
                instance.Invoke(new WriteLineColorCallback(instance.writeLine), new object[] { str, color });
            else
                instance.writeLine(str, color);
        }

    }
}
