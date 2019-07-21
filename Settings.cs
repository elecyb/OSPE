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
using System.Windows.Forms;
using Microsoft.Win32;

namespace OSPE
{
    public static class Settings
    {
        
        private static readonly RegistryKey registry;

        static Settings()
        {
            try
            {
                registry = Registry.CurrentUser.OpenSubKey("Software", true)
                    .CreateSubKey(Application.CompanyName)
                    .CreateSubKey(Application.ProductName);
            }
            catch (Exception e)
            {
                MessageBox.Show(@"Error opening registry key. \n" + e.Message);
                throw new NotImplementedException();
            }
        }

        public static void Reset()
        {
            var keys = registry.GetValueNames();
            foreach (var key in keys)
            {
                registry.DeleteValue(key);
            }
            registry.Close();
        }
  

        #region Main Form Settings

        public static Point FormLocation
        {
            get
            {
                return new Point(
                    (int) (registry.GetValue("FormLocationX") ?? 0),
                    (int) (registry.GetValue("FormLocationY") ?? 0)
                    );
            }
            set
            {
                registry.SetValue("FormLocationX", value.X);
                registry.SetValue("FormLocationY", value.Y);
            }
        }
        public static Size FormSize
        {
            get
            {
                return new Size(
                    (int) (registry.GetValue("FormSizeW") ?? 0),
                    (int) (registry.GetValue("FormSizeH") ?? 0)
                    );
            }
            set
            {
                registry.SetValue("FormSizeW", value.Width);
                registry.SetValue("FormSizeH", value.Height);
            }
        }
        public static FormWindowState FormState
        {
            get { return (FormWindowState) (registry.GetValue("FormState") ?? FormWindowState.Normal); }
            set { registry.SetValue("FormState", (int) value); }
        }
        public static int CurrentTab
        {
            get { return (int)(registry.GetValue("CurrentTab") ?? 2); }
            set { registry.SetValue("CurrentTab", value); }
        }
        public static int CurrentCaptureFilterTab
        {
            get { return (int)(registry.GetValue("CaptureFilterTab") ?? 2); }
            set { registry.SetValue("CaptureFilterTab", value); }
        }
        public static bool ViewAsHex
        {
            get { return 0 != (int)(registry.GetValue("ViewAsHex") ?? 0); }
            set { registry.SetValue("ViewAsHex", value ? 1 : 0); }
        }
        public static bool AutoScroll
        {
            get { return 0 != (int)(registry.GetValue("AutoScroll") ?? 0); }
            set { registry.SetValue("AutoScroll", value ? 1 : 0); }
        }
        public static int SpliterDistanceTabsAndHex
        {
            get { return (int)(registry.GetValue("SpliterDistanceTabsAndHex") ?? 360); }
            set { registry.SetValue("SpliterDistanceTabsAndHex", value); }
        }
        public static int SpliterDistanceFilterAndConversions
        {
            get { return (int)(registry.GetValue("SpliterDistanceFilterAndConversions") ?? 360); }
            set { registry.SetValue("SpliterDistanceFilterAndConversions", value); }
        }
        public static bool MinimizeToSystemTray
        {
            get { return 0 != (int)(registry.GetValue("MinimizeToSystemTray") ?? 1); }
            set { registry.SetValue("MinimizeToSystemTray", value ? 1 : 0); }
        }

        #endregion

        #region Columns Width
        public static int colPacket
        {
            get { return (int)(registry.GetValue("colPacket") ?? 60); }
            set { registry.SetValue("colPacket", value); }
        }
        public static int colSource
        {
            get { return (int)(registry.GetValue("colSource") ?? 60); }
            set { registry.SetValue("colSource", value); }
        }
        public static int colDestination
        {
            get { return (int)(registry.GetValue("colDestination") ?? 60); }
            set { registry.SetValue("colDestination", value); }
        }
        public static int colSize
        {
            get { return (int)(registry.GetValue("colSize") ?? 60); }
            set { registry.SetValue("colSize", value); }
        }
        
        #endregion

        #region Form Log Settings

        public static bool LogOpened
        {
            get { return 0 != (int)(registry.GetValue("LogOpened") ?? 0); }
            set { registry.SetValue("LogOpened", value ? 1 : 0); }
        }
        public static bool LogEnabled
        {
            get { return 0 != (int)(registry.GetValue("LogEnabled") ?? 0); }
            set { registry.SetValue("LogEnabled", value ? 1 : 0); }
        }
        public static Point LogLocation
        {
            get
            {
                return new Point(
                    (int) (registry.GetValue("LogLocationX") ?? 0),
                    (int) (registry.GetValue("LogLocationY") ?? 0)
                    );
            }
            set
            {
                registry.SetValue("LogLocationX", value.X);
                registry.SetValue("LogLocationY", value.Y);
            }
        }
        public static Size LogSize
        {
            get
            {
                return new Size(
                    (int) (registry.GetValue("LogSizeW") ?? 0),
                    (int) (registry.GetValue("LogSizeH") ?? 0)
                    );
            }
            set
            {
                registry.SetValue("LogSizeW", value.Width - 10);
                registry.SetValue("LogSizeH", value.Height - 10);
            }
        }
        public static FormWindowState LogState
        {
            get { return (FormWindowState) (registry.GetValue("LogState") ?? FormWindowState.Normal); }
            set { registry.SetValue("LogState", (int) value); }
        }

        #endregion

        #region Form SelectProcess Settings

        public static string DLL
        {
            get {
                if (Environment.Is64BitProcess)
                    return (string) (registry.GetValue("DLLx64") ?? "");
                else
                    return (string)(registry.GetValue("DLLx86") ?? "");
            }
            set {
                if (Environment.Is64BitProcess)
                    registry.SetValue("DLLx64", value);
                else
                    registry.SetValue("DLLx86", value);
            }
        }
        public static string DLLEx
        {
            get { return (string)(registry.GetValue("DLLEx") ?? ""); }
            set { registry.SetValue("DLLEx", value); }
        }
        public static string LastProcessInjected
        {
            get { return (string)(registry.GetValue("LastProcessInjected") ?? ""); }
            set { registry.SetValue("LastProcessInjected", value); }
        }
        public static int SelectProcessViewMode
        {
            get { return (int) (registry.GetValue("SelectProcessViewMode") ?? 16); }
            set { registry.SetValue("SelectProcessViewMode", value); }
        }
        public static Point FormSelectProcessLocation
        {
            get
            {
                return new Point(
                    (int) (registry.GetValue("FormSelectProcessLocationX") ?? 0),
                    (int) (registry.GetValue("FormSelectProcessLocationY") ?? 0)
                    );
            }
            set
            {
                registry.SetValue("FormSelectProcessLocationX", value.X);
                registry.SetValue("FormSelectProcessLocationY", value.Y);
            }
        }
        public static Size FormSelectProcessSize
        {
            get
            {
                return new Size(
                    (int) (registry.GetValue("FormSelectProcessW") ?? 616),
                    (int) (registry.GetValue("FormSelectProcessH") ?? 520)
                    );
            }
            set
            {
                registry.SetValue("FormSelectProcessW", value.Width);
                registry.SetValue("FormSelectProcessH", value.Height);
            }
        }
        public static int colName
        {
            get { return (int)(registry.GetValue("colName") ?? 100); }
            set { registry.SetValue("colName", value); }
        }
        public static int colPID
        {
            get { return (int)(registry.GetValue("colPID") ?? 60); }
            set { registry.SetValue("colPID", value); }
        }

        #endregion

        #region Form 'Settings' Settings

        public static Point FormSettingsLocation
        {
            get
            {
                return new Point(
                    (int) (registry.GetValue("FormSettingsLocationX") ?? 0),
                    (int) (registry.GetValue("FormSettingsLocationY") ?? 0)
                    );
            }
            set
            {
                registry.SetValue("FormSettingsLocationX", value.X);
                registry.SetValue("FormSettingsLocationY", value.Y);
            }
        }
        public static int HotKeyStartCapture
        {
            get { return (int)(registry.GetValue("HotKeyStartCapture") ?? 0); }
            set { if (value != -1) registry.SetValue("HotKeyStartCapture", value); }
        }
        public static int HotKeyStopCapture
        {
            get { return (int)(registry.GetValue("HotKeyStopCapture") ?? 0); }
            set { if (value != -1) registry.SetValue("HotKeyStopCapture", value); }
        }
        public static int HotKeyNormalFilter
        {
            get { return (int)(registry.GetValue("HotKeyNormalFilter") ?? 0); }
            set { if (value != -1) registry.SetValue("HotKeyNormalFilter", value); }
        }
        public static int HotKeyCustomFilter
        {
            get { return (int)(registry.GetValue("HotKeyCustomFilter") ?? 0); }
            set { if (value != -1) registry.SetValue("HotKeyCustomFilter", value); }
        }
        public static int HotKeySelectProcess
        {
            get { return (int)(registry.GetValue("HotKeySelectProcess") ?? 0); }
            set { if (value != -1) registry.SetValue("HotKeySelectProcess", value); }
        }
        public static int HotKeyInjectLast
        {
            get { return (int)(registry.GetValue("HotKeyInjectLast") ?? 0); }
            set { if (value != -1) registry.SetValue("HotKeyInjectLast", value); }
        }
        public static int LogFunctions
        {
            get { return (int)(registry.GetValue("LogFunctions") ?? 4095); }
            set { registry.SetValue("LogFunctions", value); }
        }
        public static bool LocalIpChecked
        {
            get { return 0 != (int)(registry.GetValue("LocalIpChecked") ?? 0); }
            set { registry.SetValue("LocalIpChecked", value ? 1 : 0); }
        }
        public static bool LocalPortChecked
        {
            get { return 0 != (int)(registry.GetValue("LocalPortChecked") ?? 0); }
            set { registry.SetValue("LocalPortChecked", value ? 1 : 0); }
        }
        public static bool RemoteIpChecked
        {
            get { return 0 != (int)(registry.GetValue("RemoteIpChecked") ?? 0); }
            set { registry.SetValue("RemoteIpChecked", value ? 1 : 0); }
        }
        public static bool RemotePortChecked
        {
            get { return 0 != (int)(registry.GetValue("RemotePortChecked") ?? 0); }
            set { registry.SetValue("RemotePortChecked", value ? 1 : 0); }
        }
        public static int LocalIp
        {
            get { return (int)(registry.GetValue("LocalIp") ?? 0); }
            set { registry.SetValue("LocalIp", value); }
        }
        public static int RemoteIp
        {
            get { return (int)(registry.GetValue("RemoteIp") ?? 0); }
            set { registry.SetValue("RemoteIp", value); }
        }
        public static int LocalPort
        {
            get { return (int)(registry.GetValue("LocalPort") ?? 0); }
            set { registry.SetValue("LocalPort", value); }
        }
        public static int RemotePort
        {
            get { return (int)(registry.GetValue("RemotePort") ?? 0); }
            set { registry.SetValue("RemotePort", value); }
        }

        #endregion

        #region Filter Editor
        #endregion





    }
}
