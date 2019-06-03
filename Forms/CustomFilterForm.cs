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
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using FastColoredTextBoxNS;

namespace OSPE
{
    public partial class CustomFilterForm : Form
    {
        MarkerStyle SameWordsStyle = new MarkerStyle(new SolidBrush(Color.FromArgb(40, Color.Gray)));
        private bool _changesMade;
        private string _openFile="";

        public CustomFilterForm()
        {
            InitializeComponent();
            fctb.SelectionStart = 50; // Mueve el cusor a la linea siguiente de los includes
        }

        private void fctb_SelectionChangedDelayed(object sender, EventArgs e)
        {
            fctb.VisibleRange.ClearStyle(SameWordsStyle);

            if (!fctb.Selection.IsEmpty)
                return;//user selected diapason

            //get fragment around caret
            var fragment = fctb.Selection.GetFragment(@"\w");
            string text = fragment.Text;
            if (text.Length == 0)
                return;
            //highlight same words
            var ranges = fctb.VisibleRange.GetRanges("\\b" + text + "\\b").ToArray();
            if (ranges.Length > 1)
                foreach (var r in ranges)
                    r.SetStyle(SameWordsStyle);
        }

#region menu items
        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!CheckChangesMade()) return;

            fctb.Text = @"#include <winsock2.h>
#include ""ospefunc.h""





int WINAPI DllMain ( void* hDLL, unsigned long dwReason, void*  Reserved) {
	switch ( dwReason ) {
	case DLL_PROCESS_ATTACH:        

		break;
	case DLL_PROCESS_DETACH:		

		break;
	}
	return 1;
}";
            fctb.SelectionStart = 50; // Mueve el cusor a la linea siguiente de los includes
            _openFile = "";
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveCustomFilter();
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveAsCustomFilter();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!CheckChangesMade()) return;

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                using (StreamReader sr = new StreamReader(ofd.FileName, Encoding.Default))
                {
                    _openFile = ofd.FileName;
                    fctb.Text = sr.ReadToEnd();
                }
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!CheckChangesMade()) return;
            Close();
        }

        private void buildToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                using (StreamWriter sw = new StreamWriter(AppDomain.CurrentDomain.BaseDirectory + @"\DLL-Ex\mydll.c"))
                    sw.Write(fctb.Text);
            } catch (Exception ex)
            {
                txtCompilerOutput.Text = "Not implemented yet.";
                return;
            }
            var proc = new Process();
            proc.StartInfo.WorkingDirectory = AppDomain.CurrentDomain.BaseDirectory + @"\DLL-Ex";
            proc.StartInfo.FileName = AppDomain.CurrentDomain.BaseDirectory + @"\DLL-Ex\bcc32.exe";
            proc.StartInfo.Arguments = "-Iinclude -LLib -P -tWD -w- -eospe_ex.dll mydll.c mydll.obj ospefunc.obj";

            // set up output redirection
            proc.StartInfo.RedirectStandardOutput = true;
            proc.StartInfo.UseShellExecute = false;
            proc.StartInfo.CreateNoWindow = true;
            proc.Start();
            txtCompilerOutput.Text = proc.StandardOutput.ReadToEnd();
            proc.WaitForExit();
        }

        private void showLogToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void optionsToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// Abre el dialogo para guardar el filtro, ya sea en Save As, Exit, u Open.
        /// </summary>
        /// <returns>false si cancela el save, true en caso contrario</returns>
        private bool SaveAsCustomFilter()
        {
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                using (StreamWriter sw = new StreamWriter(sfd.FileName))
                {
                    _openFile = sfd.FileName;
                    sw.Write(fctb.Text);
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// Guarda el filtro en el archivo _openFile
        /// </summary>
        /// <returns></returns>
        private bool SaveCustomFilter()
        {
            if (_openFile == "")
                return SaveAsCustomFilter();

            using (StreamWriter sw = new StreamWriter(_openFile))
            {
                sw.Write(fctb.Text);
                return true;
            }
        }

        /// <summary>
        /// Verifica si hubo cambios, y pregunta si quiere guardar los cambios en el textbox 
        /// </summary>
        /// <returns>false si cancela, true en caso contrario</returns>
        private bool CheckChangesMade()
        {
            if (_changesMade)
            {
                DialogResult selected = MessageBox.Show("Save changes?", "Save?",
                                                        MessageBoxButtons.YesNoCancel);
                if (selected == DialogResult.Cancel) return false;
                if (selected == DialogResult.Yes)
                {
                    if (!SaveCustomFilter())
                        return false;
                }
            }
            _changesMade = false;
            return true;
        }

        #region insert funcs
        private void wsock32RecvToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var code = @"extern ""C"" int __declspec(dllexport) WINAPI Recv_WS1(SOCKET s, char *buf, int len, int flags , LPVOID pSendWs1, LPVOID pRecvWs1, LPVOID pSendWs2, LPVOID pRecvWs2, bool IsWorking){

      return 1;
}";
            fctb.Text = fctb.Text.Insert(fctb.SelectionStart, code);
        }

        private void wsock32SendToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var code = @"extern ""C"" int __declspec(dllexport) WINAPI Send_WS1(SOCKET s, const char *buf, int len, int flags , LPVOID pSendWs1, LPVOID pRecvWs1, LPVOID pSendWs2, LPVOID pRecvWs2, bool IsWorking){

      return 1;
}";
            fctb.Text = fctb.Text.Insert(fctb.SelectionStart, code);
        }

        private void wS2RecvToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var code = @"extern ""C"" int __declspec(dllexport) WINAPI Recv_WS2(SOCKET s, char *buf, int len, int flags , LPVOID pSendWs1, LPVOID pRecvWs1, LPVOID pSendWs2, LPVOID pRecvWs2, bool IsWorking){
      
      return 1;
}";
            fctb.Text = fctb.Text.Insert(fctb.SelectionStart, code);
        }

        private void wS232SendToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var code = @"extern ""C"" int __declspec(dllexport) WINAPI Send_WS2(SOCKET s, const char *buf, int len, int flags , LPVOID pSendWs1, LPVOID pRecvWs1, LPVOID pSendWs2, LPVOID pRecvWs2, bool IsWorking){
      
      return 1;
}";
            fctb.Text = fctb.Text.Insert(fctb.SelectionStart, code);
        }

        private void wS232WSARecvToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var code = @"extern ""C"" int __declspec(dllexport) WINAPI Recv_WSA(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount,	LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine, LPVOID pSendWs1, LPVOID pRecvWs1, LPVOID pSendWs2, LPVOID pRecvWs2, bool IsWorking){
      
      return 1;
}";
            fctb.Text = fctb.Text.Insert(fctb.SelectionStart, code);
        }

        private void wS232WSASendToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var code = @"extern ""C"" int __declspec(dllexport) WINAPI Send_WSA(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount,	LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine, LPVOID pSendWs1, LPVOID pRecvWs1, LPVOID pSendWs2, LPVOID pRecvWs2, bool IsWorking){

      return 1;
}";
            fctb.Text = fctb.Text.Insert(fctb.SelectionStart, code);
        }

        private void getBufferAsHexToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var code = @"/*
      Function: GetBufferAsHex
      Propouse: Coverts the buffer data in ASCII to a hexadecimal representation.
      Parameters: buf: Pointer to a buffer
                        len: Buffer length
      Returns: Pointer to a null terminated string with data in hexadecimal.
*/
const char * GetBufferAsHex(char * buf, int len);";
            fctb.Text = fctb.Text.Insert(fctb.SelectionStart, code);
        }

        private void getBufferAsTextToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var code = @"/*
	Function: GetBufferAsHex
	Propouse: Coverts the buffer data in ASCII to a null terminated string.
	Parameters: buf: Pointer to a buffer
				len: Buffer length 
	Returns: Pointer to a null terminated string.
*/
const char * GetBufferAsText(char * buf, int len);";
            fctb.Text = fctb.Text.Insert(fctb.SelectionStart, code);
        }

        private void messageBoxToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var code = @"//void MessageBox (const char *  cStr);";
            fctb.Text = fctb.Text.Insert(fctb.SelectionStart, code);
        }

        private void changeIfMatchToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
        #endregion

#endregion

        private void fctb_KeyPressing(object sender, KeyPressEventArgs e)
        {
            _changesMade = true;
        }

    }
}
