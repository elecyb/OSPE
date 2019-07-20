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

#include "stdafx.h"
#include <ws2tcpip.h>
#include "MinHook.h"

#if defined _M_X64
#pragma comment(lib, "Lib\\libMinHook-x64-v141-mdd.lib")
#elif defined _M_IX86
#pragma comment(lib, "Lib\\libMinHook-x86-v141-mdd.lib")
#endif

#include "Defines.h"
#include "OspeDll.h"
#include "HookedFunctions.h"
#include "NonExportedHooks.h"
#include "DllCommunication.h"
#include "stdafx.h"
#include "ipc.h"

HMODULE hDllEx;
HANDLE hMainThread;

bool isCapturing = false;
bool isFiltering = false;


void LoadDllEx(LPCSTR lpFileName) {
	hDllEx = LoadLibraryA(lpFileName);
	send_ws1 = (T_SENDWS1)GetProcAddress(hDllEx, "Send_WS1");
	recv_ws1 = (T_RECVWS1)GetProcAddress(hDllEx, "Recv_WS1");
	send_ws2 = (T_SENDWS2)GetProcAddress(hDllEx, "Send_WS2");
	recv_ws2 = (T_RECVWS2)GetProcAddress(hDllEx, "Recv_WS2");
	send_wsa = (T_SENDWSA)GetProcAddress(hDllEx, "Send_WSA");
	recv_wsa = (T_RECVWSA)GetProcAddress(hDllEx, "Recv_WSA");
}

void UnLoadDllEx() {
	FreeLibrary(hDllEx);
	send_ws1 = NULL;
	recv_ws1 = NULL;
	send_ws2 = NULL;
	recv_ws2 = NULL;
	send_wsa = NULL;
	recv_wsa = NULL;
}

// DLL Main
INT APIENTRY DllMain( HMODULE hDLL, DWORD dwReason, LPVOID Reserved) {
    switch ( dwReason ) 
	{
		case DLL_PROCESS_ATTACH:
		{
			DisableThreadLibraryCalls(hDLL);
			// Initialize MinHook.
			if (MH_Initialize() != MH_OK)
			{
				Utils::errorLog("MH_Initialize FAIL! ");
				return 1;
			}

			//Utils::errorLog("STARTING HOOKS ");

			// Create a hook for each winsock function, in disabled state.
			// Hooks specific to loaded DLLs

			vector<MODULEENTRY32> vDlls = Process::GetProcessModules(0);

			for (size_t i = 0; i < vDlls.size(); i++)
			{
                // Utils::errorLog((char *)Utils::ToLower(vDlls[i].szModule).c_str());
				if (Utils::ToLower(vDlls[i].szModule).compare("wsock32.dll") == 0)
				{
					// Winsock 1.1
					MH_CreateHookApi(L"wsock32.dll", "send", MySend, (LPVOID*)& pSend);
					MH_CreateHookApi(L"wsock32.dll", "sendto", MySendTo, (LPVOID*)& pSendTo);
					MH_CreateHookApi(L"wsock32.dll", "recv", MyRecv, (LPVOID*)& pRecv);
					MH_CreateHookApi(L"wsock32.dll", "recvfrom", MyRecvFrom, (LPVOID*)& pRecvFrom);
				}
				else if (Utils::ToLower(vDlls[i].szModule).compare("ws2_32.dll") == 0)
				{
					// Winsock 2.0
					MH_CreateHookApi(L"ws2_32.dll", "send", MyWS2Send, (LPVOID*)& pWS2Send);
					MH_CreateHookApi(L"ws2_32.dll", "sendto", MyWS2SendTo, (LPVOID*)& pWS2SendTo);
					MH_CreateHookApi(L"ws2_32.dll", "recv", MyWS2Recv, (LPVOID*)& pWS2Recv);
					MH_CreateHookApi(L"ws2_32.dll", "recvfrom", MyWS2RecvFrom, (LPVOID*)& pRecvFrom);
					// Winsock WSA
					MH_CreateHookApi(L"ws2_32.dll", "WSASend", MyWSASend, (LPVOID*)& pWSASend);
					MH_CreateHookApi(L"ws2_32.dll", "WSASendTo", MyWSASendTo, (LPVOID*)& pWSASendTo);
					MH_CreateHookApi(L"ws2_32.dll", "WSARecv", MyWSARecv, (LPVOID*)& pWSARecv);
					MH_CreateHookApi(L"ws2_32.dll", "WSARecvFrom", MyWSARecvFrom, (LPVOID*)& pWSARecvFrom);
				}
				else if (Utils::ToLower(vDlls[i].szModule).compare("nss3.dll") == 0 || Utils::ToLower(vDlls[i].szModule).compare("nspr4.dll") == 0)
				{
					// PR_Read, PR_Write, PR_Send, PR_Recv
					LPCWSTR sModule = Utils::ToLower(vDlls[i].szModule).compare("nss3.dll") ? L"nspr4.dll" : L"nss3.dll";
					MH_CreateHookApi(sModule, "PR_Read", PR_Read_Callback, (LPVOID*)& PR_Read_Original);
					MH_CreateHookApi(sModule, "PR_Write", PR_Write_Callback, (LPVOID*)& PR_Write_Original);
					MH_CreateHookApi(sModule, "PR_Recv", PR_Recv_Callback, (LPVOID*)& PR_Recv_Original);
					MH_CreateHookApi(sModule, "PR_Send", PR_Send_Callback, (LPVOID*)& PR_Send_Original);
					PR_GetDescType_Original = (PR_GetDescType_Typedef)GetProcAddress(LoadLibrary(vDlls[i].szModule), "PR_GetDescType");
				}
				else if (Utils::ToLower(vDlls[i].szModule).compare("ncrypt.dll") == 0)
				{
					// SslEncryptPacket, SslDecryptPacket
					MH_CreateHookApi(L"ncrypt.dll", "SslEncryptPacket", SslEncryptPacket_Callback, (LPVOID*)& SslEncryptPacket_Original);
					MH_CreateHookApi(L"ncrypt.dll", "SslDecryptPacket", SslDecryptPacket_Callback, (LPVOID*)& SslEncryptPacket_Original);
				}
				else if (Utils::ToLower(vDlls[i].szModule).compare("secur32.dll") == 0)
				{
					// EncryptMessage, DecryptMessage
					MH_CreateHookApi(L"secur32.dll", "EncryptMessage", EncryptMessage_Callback, (LPVOID*)& EncryptMessage_Original);
					MH_CreateHookApi(L"secur32.dll", "DecryptMessage", DecryptMessage_Callback, (LPVOID*)& DecryptMessage_Original);
				}
				else if (Utils::ToLower(vDlls[i].szModule).compare("ssleay32.dll") == 0)
				{
					//  SSLeay_Write, SSLeay_Read
					MH_CreateHookApi(L"ssleay32.dll", "SSL_write", SSLeay_Write_Callback, (LPVOID*)& SSLeay_Write_Original);
					MH_CreateHookApi(L"ssleay32.dll", "SSL_read", SSLeay_Read_Callback, (LPVOID*)& SSLeay_Read_Original);
				}
				else if (Utils::ToLower(vDlls[i].szModule).compare("chrome.dll") == 0)
				{
					// Hook Chrome functions
					HookChrome("chrome.dll");
				}
				else if (Utils::ToLower(vDlls[i].szModule).compare("opera_browser.dll") == 0)
				{
					// Hook Chrome functions
					HookChrome("opera_browser.dll");
				}
			}

			MH_EnableHook(MH_ALL_HOOKS);

			// Spawn command reader thread worker
			CreateThread(NULL, 0, Command_Reader, NULL, 0, NULL);
			break;
		}
		case DLL_PROCESS_DETACH:
			MH_DisableHook(MH_ALL_HOOKS);
			break;
	}

    return TRUE;
}

