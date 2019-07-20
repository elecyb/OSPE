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

#ifndef DEFINES_H
#define DEFINES_H

// LOG OPTIONS - DESCOMENTAR LO QUE QUERES LOGUEAR
//#define DBG_SENDPACKETDATA
//#define DBG_BLOCKPKT

//ID de funciones y comandos del server
enum Functions
{
    CODE_NOP,
    CODE_SEND,
    CODE_SENDTO,
    CODE_RECV,
    CODE_RECVFROM,
    CODE_WS2SEND,
    CODE_WS2SENDTO,
    CODE_WS2RECV,
    CODE_WS2RECVFROM,
    CODE_WSASEND,
    CODE_WSASENDTO,
    CODE_WSARECV,
    CODE_WSARECVFROM,
    CODE_PR_SEND,
    CODE_PR_RECV,
    CODE_PR_READ,
    CODE_PR_WRITE,
    CODE_SSLENCRYPTPACKET,
    CODE_SSLDECRYPTPACKET,
    CODE_ENCRYPTMESSAGE,
    CODE_DECRYPTMESSAGE,
    CODE_SSL_READ,
    CODE_SSL_WRITE
};

enum ServerCodes
{
    SCODE_NOP,
    SCODE_INJECTPACKET,
    SCODE_SETPACKET,
    SCODE_STARTFILTERING,
    SCODE_STOPFILTERING,
    SCODE_STARTCAPTURE,
    SCODE_STOPCAPTURE,
    SCODE_LOADDLLEX,
    SCODE_UNLOADDLLEX,
};

typedef struct
{
    Functions functionId;
    UINT16 socketId;
    UINT32 localIp;
    UINT32 remoteIp;
    UINT16 localPort;
    UINT16 remotePort;
    UINT16 size;
} PacketInfo;



#endif // DEFINES_H
