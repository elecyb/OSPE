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
using System.Net;


namespace OSPE
{
    //ID de funciones y comandos del server
    public enum Functions : uint
    {
        CODE_NOP = 0,
        CODE_SEND = 1,
        CODE_SENDTO = 2,
        CODE_RECV = 3,
        CODE_RECVFROM = 4,
        CODE_WS2SEND = 5,
        CODE_WS2SENDTO = 6,
        CODE_WS2RECV = 7,
        CODE_WS2RECVFROM = 8,
        CODE_WSASEND = 9,
        CODE_WSASENDTO = 10,
        CODE_WSARECV = 11,
        CODE_WSARECVFROM = 12,
        CODE_PR_SEND = 13,
        CODE_PR_RECV = 14,
        CODE_PR_READ = 15,
        CODE_PR_WRITE = 16,
        CODE_SSLENCRYPTPACKET = 17,
        CODE_SSLDECRYPTPACKET = 18,
        CODE_ENCRYPTMESSAGE = 19,
        CODE_DECRYPTMESSAGE = 20,
        CODE_SSL_READ = 21,
        CODE_SSL_WRITE = 22,
        CODE_UNDEFINED_FILTERCODE = 255
    };

    public struct PacketInfo
    {
        public Functions FunctionID;
        public UInt16 SocketId;
        public UInt32 LocalIp;
        public UInt32 RemoteIp;
        public UInt16 LocalPort;
        public UInt16 RemotePort;
        public UInt16 Size;
    };

    public struct ServerCommand
    {
        public ServerCodes Code;
        public UInt16 Data_len;
    };

    [Serializable]
    public class Packet
    {
        public enum Directions
        {
            None,
            In,
            Out
        }

        public Functions FunctionID;
        public UInt16 SocketId;
        public IPAddress LocalIp { get; private set; }
        public UInt16 LocalPort { get; private set; }
        public IPAddress RemoteIp { get; private set; }
        public UInt16 RemotePort { get; private set; }
        public int Size { get; private set; }
        public byte[] Data { get; private set; }
        public Directions Direction;
        
        public Packet(Functions functionId, UInt16 socketId, UInt32 localIp, UInt16 localPort, UInt32 remoteIp, UInt16 remotePort, byte[] data, Directions direction)
        {
            FunctionID = functionId;
            SocketId = socketId;
            LocalIp = new IPAddress((UInt32)IPAddress.NetworkToHostOrder((Int32)localIp));
            LocalPort = localPort;
            RemoteIp = new IPAddress((UInt32)IPAddress.NetworkToHostOrder((Int32)remoteIp));
            RemotePort = remotePort;
            Size = data.Length;
            Data = data;
            Direction = direction;
        }
        

        /// <summary>
        /// Coverts the buffer data to a hexadecimal representation.
        /// </summary>
        /// <returns>A string with the data in hexadecimal.</returns>
        public string GetBufferAsHex()
        {
            return BitConverter.ToString(Data, 0, Size).Replace("-", " ");
        }

        /// <summary>
        /// Coverts the buffer data to a string representation.
        /// </summary>
        /// <returns>A string with the data in ASCII</returns>
        public string GetBufferAsText()
        {
            char[] str2 = new char[Size + 1];
            for (int i = 0; i < Size; i++)
            {
		        if (Data[i]==0) 
			        str2[i]= (char) 46;
		        else
			        str2[i]=(char) Data[i];
	          }
            str2[Size] = '\0';
              return new string(str2);
        }


    }

}






