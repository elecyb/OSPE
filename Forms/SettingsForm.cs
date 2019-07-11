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
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Text;
using System.Windows.Forms;
using OPSE_HotKeys;

namespace OSPE
{
    public partial class SettingsForm : Form
    {
        public SettingsForm()
        {
            InitializeComponent();
            StartPosition = FormStartPosition.Manual;
            Location = Settings.FormSettingsLocation;
            chkMinimizeToSystemTray.Checked = Settings.MinimizeToSystemTray;
            Closed += On_Close;
        }

        private void frmSettings_Load(object sender, EventArgs e)
        {
            txtStartCaptureHotKey.Text = GetTextForKeyData(Settings.HotKeyStartCapture);
            txtStopCaptureHotKey.Text = GetTextForKeyData(Settings.HotKeyStopCapture);
            txtNormalFilterHotKey.Text = GetTextForKeyData(Settings.HotKeyNormalFilter);
            txtCustomFilterHotKey.Text = GetTextForKeyData(Settings.HotKeyCustomFilter);
            txtSelectProcessHotKey.Text = GetTextForKeyData(Settings.HotKeySelectProcess);
            txtInjectLastHotKey.Text = GetTextForKeyData(Settings.HotKeyInjectLast);

            FilterCaptureFuncs logFunctions = (FilterCaptureFuncs)Settings.LogFunctions;
            chkWSSend.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WSSend);
            chkWSSendTo.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WSSendTo);
            chkWSRecv.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WSRecv);
            chkWSRecvFrom.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WSRecvFrom);
            chkWS2Send.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WS2Send);
            chkWS2SendTo.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WS2SendTo);
            chkWS2Recv.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WS2Recv);
            chkWS2RecvFrom.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WS2RecvFrom);
            chkWSASend.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WSASend);
            chkWSASendTo.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WSASendTo);
            chkWSARecv.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WSARecv);
            chkWSARecvFrom.Checked = logFunctions.HasFlag(FilterCaptureFuncs.WSARecvFrom);
            chkPRRead.Checked = logFunctions.HasFlag(FilterCaptureFuncs.PRRead);
            chkPRWrite.Checked = logFunctions.HasFlag(FilterCaptureFuncs.PRWrite);
            chkPRSend.Checked = logFunctions.HasFlag(FilterCaptureFuncs.PRSend);
            chkPRRecv.Checked = logFunctions.HasFlag(FilterCaptureFuncs.PRRecv);
            chkSSLEncryptPacket.Checked = logFunctions.HasFlag(FilterCaptureFuncs.SSLEncryptPacket);
            chkSSLDecryptPacket.Checked = logFunctions.HasFlag(FilterCaptureFuncs.SSLDecryptPacket);
            chkEncryptMessage.Checked = logFunctions.HasFlag(FilterCaptureFuncs.EncryptMessage);
            chkDecryptMessage.Checked = logFunctions.HasFlag(FilterCaptureFuncs.DecryptMessage);
            chkSSLWrite.Checked = logFunctions.HasFlag(FilterCaptureFuncs.SSLWrite);
            chkSSLRead.Checked = logFunctions.HasFlag(FilterCaptureFuncs.SSLRead);

            txtDLL.Text = Settings.DLL;
            txtScript.Text = Settings.DLLEx;
            chkLogEnabled.Checked = Settings.LogEnabled;

            chkLocalIp.Checked = Settings.LocalIpChecked;
            chkLocalPort.Checked = Settings.LocalPortChecked;
            chkRemoteIp.Checked = Settings.RemoteIpChecked;
            chkRemotePort.Checked = Settings.RemotePortChecked;
            byte[] bytes = BitConverter.GetBytes(Settings.LocalIp);
            Array.Reverse(bytes); // flip little-endian to big-endian(network order)
            txtLocalIp.Text = new IPAddress(bytes).ToString();
            numLocalPort.Value = Settings.LocalPort;
            bytes = BitConverter.GetBytes(Settings.RemoteIp);
            Array.Reverse(bytes); // flip little-endian to big-endian(network order)
            txtRemoteIp.Text = new IPAddress(bytes).ToString();
            numRemotePort.Value = Settings.RemotePort;
        }

        private void On_Close(object sender, EventArgs e)
        {
            Settings.FormSettingsLocation = Location;
        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            SaveIpPortConditions();
            SaveLogWinsockFunctions();
            Output.LogEnabled = chkLogEnabled.Checked;
            Settings.LogEnabled = chkLogEnabled.Checked;
            Close();
        }

        private void btnResetAllSettings_Click(object sender, EventArgs e)
        {
            Settings.Reset();
            Process.Start(Application.ExecutablePath);
            Application.Exit();
        }

        private void btnSelectDLL_Click(object sender, EventArgs e)
        {
            var openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Dll files|*.dll";
            openFileDialog.Title = "Please, select ospe.dll location.";
            DialogResult result = openFileDialog.ShowDialog();

            if (result == DialogResult.OK)
            {
                Settings.DLL = openFileDialog.FileName;
                txtDLL.Text = openFileDialog.FileName;
            }
        }

        private void btnSelectScript_Click(object sender, EventArgs e)
        {
            var openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Dll files|*.dll";
            openFileDialog.Title = "Please, select ospe_ex.dll location.";
            DialogResult result = openFileDialog.ShowDialog();

            if (result == DialogResult.OK)
            {
                Settings.DLLEx = openFileDialog.FileName;
                txtScript.Text = openFileDialog.FileName;
            }
        }

        private void chkMinimizeToSystemTray_CheckedChanged(object sender, EventArgs e)
        {
            Settings.MinimizeToSystemTray = chkMinimizeToSystemTray.Checked;
        }

        #region HotKey Stuff

        // On KeyDown Events
        private void txtStartCaptureKey_KeyDown(object sender, KeyEventArgs e)
        {
            Settings.HotKeyStartCapture = CheckHotKey((TextBox)sender, e, ref HotKeys.startCaptureKeyboardHook, HotKeys.hook_StartCapture);
        }

        private void txtStopCaptureKey_KeyDown(object sender, KeyEventArgs e)
        {
            Settings.HotKeyStopCapture = CheckHotKey((TextBox)sender, e, ref HotKeys.stopCaptureKeyboardHook, HotKeys.hook_StopCapture);
        }

        private void txtNormalFilterKey_KeyDown(object sender, KeyEventArgs e)
        {
            Settings.HotKeyNormalFilter = CheckHotKey((TextBox)sender, e, ref HotKeys.normalFilterKeyboardHook, HotKeys.hook_NormalFilter);
        }

        private void txtCustomFilterKey_KeyDown(object sender, KeyEventArgs e)
        {
            Settings.HotKeyCustomFilter = CheckHotKey((TextBox)sender, e, ref HotKeys.customFilterKeyboardHook, HotKeys.hook_CustomFilter);
        }

        private void txtSelectProcess_KeyDown(object sender, KeyEventArgs e)
        {
            Settings.HotKeySelectProcess = CheckHotKey((TextBox)sender, e, ref HotKeys.selectProcessKeyboardHook, HotKeys.hook_SelectProcess);
        }

        private void txtInjectLast_KeyDown(object sender, KeyEventArgs e)
        {
            Settings.HotKeyInjectLast = CheckHotKey((TextBox)sender, e, ref HotKeys.injectLastKeyboardHook, HotKeys.hook_InjectLast);
        }



        /// <summary>
        /// Esta funcion toma los eventos KeyDown sobre los controles y actualiza el texto mostrando la informacion de la HotKey
        /// </summary>
        /// <param name="textBox">Control donde se actualiza el texto con la nueva HotKey</param>
        /// <param name="e">KeyEventArgs e</param>
        /// <param name="hook">Variable tipo KeyboardHook donde se crea el hook</param>
        /// <param name="func">Funcion que es llamada cuando las teclas se apretan </param>
        /// <returns>-1 Si no debe modificarse el valor del setting, 0 si se elimina la hotkey, sino int32 con la KeyData</returns>
        private int CheckHotKey(TextBox textBox, KeyEventArgs e, ref KeyboardHook hook, EventHandler<KeyPressedEventArgs> func)
        {
            e.Handled = true;

            // Fetch the actual shortcut key.
            Keys key = e.KeyCode;
            Keys mods = e.Modifiers;
            Keys data = e.KeyData;

            // Ignore modifier keys.
            if (key == Keys.LShiftKey || key == Keys.RShiftKey || key == Keys.ShiftKey
                || key == Keys.LControlKey || key == Keys.RControlKey || key == Keys.ControlKey
                || key == Keys.Alt || key == Keys.LWin || key == Keys.RWin)
            {
                return -1;
            }

            // HotKey remover keys
            if (key == Keys.Back || key == Keys.Delete || key == Keys.Escape)
            {
                hook.Dispose();
                textBox.Text = "None";
                return 0;
            }

            // Set the hook
            hook = new KeyboardHook();
            // register the event that is fired after the key press.
            hook.KeyPressed += func;
            try
            {
                hook.RegisterHotKey(HotKeys.ToModKeys(mods), key);
            }catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
                return -1;
            }
            // Update the text box.
            textBox.Text = GetTextForKeyAndMods(key, mods);
            return (int)data;
        }

        private string GetTextForKeyData(int keyData)
        {
            if (keyData == 0) 
                return "None";

            // Get Key and Modifiers from KeyData
            Keys data = (Keys)keyData;
            Keys key = data & Keys.KeyCode;
            Keys mods = data & Keys.Modifiers;

            return GetTextForKeyAndMods(key, mods);
        }

        private string GetTextForKeyAndMods(Keys key, Keys mods)
        {
            // Build the shortcut key name.
            StringBuilder shortcutText = new StringBuilder();
            if (mods.HasFlag(Keys.Control))
            {
                shortcutText.Append("Ctrl+");
            }
            if (mods.HasFlag(Keys.Shift))
            {
                shortcutText.Append("Shift+");
            }
            if (mods.HasFlag(Keys.Alt))
            {
                shortcutText.Append("Alt+");
            }
            shortcutText.Append(key.ToString());

            return shortcutText.ToString();
        }

        #endregion

        private void SaveLogWinsockFunctions()
        {
            FilterCaptureFuncs logFuncs = 0;
            if (chkWSSend.Checked)
                logFuncs |= FilterCaptureFuncs.WSSend;
            if (chkWSSendTo.Checked)
                logFuncs |= FilterCaptureFuncs.WSSendTo;
            if (chkWSRecv.Checked)
                logFuncs |= FilterCaptureFuncs.WSRecv;
            if (chkWSRecvFrom.Checked)
                logFuncs |= FilterCaptureFuncs.WSRecvFrom;

            if (chkWS2Send.Checked)
                logFuncs |= FilterCaptureFuncs.WS2Send;
            if (chkWS2SendTo.Checked)
                logFuncs |= FilterCaptureFuncs.WS2SendTo;
            if (chkWS2Recv.Checked)
                logFuncs |= FilterCaptureFuncs.WS2Recv;
            if (chkWS2RecvFrom.Checked)
                logFuncs |= FilterCaptureFuncs.WS2RecvFrom;

            if (chkWSASend.Checked)
                logFuncs |= FilterCaptureFuncs.WSASend;
            if (chkWSASendTo.Checked)
                logFuncs |= FilterCaptureFuncs.WSASendTo;
            if (chkWSARecv.Checked)
                logFuncs |= FilterCaptureFuncs.WSARecv;
            if (chkWSARecvFrom.Checked)
                logFuncs |= FilterCaptureFuncs.WSARecvFrom;

            if (chkPRRead.Checked)
                logFuncs |= FilterCaptureFuncs.PRRead;
            if (chkPRWrite.Checked)
                logFuncs |= FilterCaptureFuncs.PRWrite;
            if (chkPRSend.Checked)
                logFuncs |= FilterCaptureFuncs.PRSend;
            if (chkPRRecv.Checked)
                logFuncs |= FilterCaptureFuncs.PRRecv;

            if (chkSSLEncryptPacket.Checked)
                logFuncs |= FilterCaptureFuncs.SSLEncryptPacket;
            if (chkSSLDecryptPacket.Checked)
                logFuncs |= FilterCaptureFuncs.SSLDecryptPacket;
            if (chkEncryptMessage.Checked)
                logFuncs |= FilterCaptureFuncs.EncryptMessage;
            if (chkDecryptMessage.Checked)
                logFuncs |= FilterCaptureFuncs.DecryptMessage;
            if (chkSSLWrite.Checked)
                logFuncs |= FilterCaptureFuncs.SSLWrite;
            if (chkSSLRead.Checked)
                logFuncs |= FilterCaptureFuncs.SSLRead;

            Settings.LogFunctions = (int)logFuncs;
            PacketManager.LogFunctions = (FilterCaptureFuncs)logFuncs; // para no tener que reiniciar el programa...
        }

        private void SaveIpPortConditions()
        {
            Settings.LocalIpChecked = chkLocalIp.Checked;
            Settings.LocalPortChecked = chkLocalPort.Checked;
            Settings.RemoteIpChecked = chkRemoteIp.Checked;
            Settings.RemotePortChecked = chkRemotePort.Checked;
            IPAddress address;
            if (IPAddress.TryParse(txtLocalIp.Text, out address))
            {
                byte[] bytes = address.GetAddressBytes();
                Array.Reverse(bytes);
                Settings.LocalIp = BitConverter.ToInt32(bytes, 0);
            }
               
            Settings.LocalPort = (int)numLocalPort.Value;
            if (IPAddress.TryParse(txtRemoteIp.Text, out address))
            {
                byte[] bytes = address.GetAddressBytes();
                Array.Reverse(bytes);
                Settings.RemoteIp = BitConverter.ToInt32(bytes, 0);
            }
                
            Settings.RemotePort = (int)numRemotePort.Value;

        }

    }
}
