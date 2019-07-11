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
using System.Windows.Forms;

namespace OSPE
{
    static class Program
    {
        public static MainForm mainForm;

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {


            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);


            mainForm = new MainForm();
            Application.Run(mainForm);
        }

        public static string FunctionNameToString(Functions f)
        {
            switch (f)
            {
                case Functions.CODE_SEND:
                    return "WS1.1 Send";
                case Functions.CODE_RECV:
                    return "WS1.1 Recv";
                case Functions.CODE_SENDTO:
                    return "WS1.1 SendTo";
                case Functions.CODE_RECVFROM:
                    return "WS1.1 SendFrom";
                case Functions.CODE_WS2SEND:
                    return "WS2.0 Send";
                case Functions.CODE_WS2RECV:
                    return "WS2.0 Recv";
                case Functions.CODE_WS2SENDTO:
                    return "WS2.0 SendTo";
                case Functions.CODE_WS2RECVFROM:
                    return "WS2.0 RecvFrom";
                case Functions.CODE_WSASEND:
                    return "WSA Send";
                case Functions.CODE_WSARECV:
                    return "WSA Recv";
                case Functions.CODE_WSASENDTO:
                    return "WSA SendTo";
                case Functions.CODE_WSARECVFROM:
                    return "WSA RecvFrom";
                case Functions.CODE_PR_READ:
                    return "PR_Read";
                case Functions.CODE_PR_WRITE:
                    return "PR_Write";                  
                case Functions.CODE_PR_SEND:
                    return "PR_Send";
                case Functions.CODE_PR_RECV:
                    return "PR_Recv"; 
                case Functions.CODE_SSLENCRYPTPACKET:
                    return "SslEncryptPacket";
                case Functions.CODE_SSLDECRYPTPACKET:
                    return "SslDecryptPacket";
                case Functions.CODE_ENCRYPTMESSAGE:
                    return "EncryptMessage";
                case Functions.CODE_DECRYPTMESSAGE:
                    return "DecryptMessage";
                case Functions.CODE_SSL_WRITE:
                    return "SSL_write";
                case Functions.CODE_SSL_READ:
                    return "SSL_read";
                default:
                    throw new NotImplementedException();
            }
        }
    }
}
