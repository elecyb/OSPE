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

#include "StdAfx.h"
#include "ipc.h"

osIPC::Server::Server(void)
{
	// Set default params
	m_hMapFile = 0;
	m_hSignal = 0;
	m_hAvail = 0;
	m_pNodeHeader = NULL;
    m_sAddr = NULL;

	// create the server
	create();
};

osIPC::Server::~Server(void)
{
	// Free memory
    if (m_sAddr) {
        free(m_sAddr);
        m_sAddr = NULL;
	}

	// Close the server
	close();
};

void osIPC::Server::create(void)
{
	// Determine the name of the memory
	DWORD ProcessID = GetCurrentProcessId();

    m_sAddr = (char*)malloc(IPC_MAX_NAME);
    if (!m_sAddr) return;
    sprintf_s(m_sAddr, IPC_MAX_NAME, "%s%u", IPC_SRV_MMF_NAME, ProcessID);

	char *m_sEvtAvail = (char*)malloc(IPC_MAX_NAME);
	if (!m_sEvtAvail) { printf("server_create: failed: %01d\n", __LINE__); return; }
    sprintf_s(m_sEvtAvail, IPC_MAX_NAME, "%s_evt_nodeavail", m_sAddr);

	char *m_sEvtFilled = (char*)malloc(IPC_MAX_NAME);
	if (!m_sEvtFilled) { free(m_sEvtAvail); printf("server_create: failed: %01d\n", __LINE__); return; }
    sprintf_s(m_sEvtFilled, IPC_MAX_NAME, "%s_evt_dataexists", m_sAddr);

    char *m_sMemName = (char*)malloc(IPC_MAX_NAME);
    if (!m_sMemName) { free(m_sEvtAvail); free(m_sEvtFilled); printf("server_create: failed: %01d\n", __LINE__); return; }
    sprintf_s(m_sMemName, IPC_MAX_NAME, "%s", m_sAddr);

	// Create the events
	m_hSignal = CreateEventA(NULL, FALSE, FALSE, (LPCSTR)m_sEvtFilled);
	if (m_hSignal == NULL || m_hSignal == INVALID_HANDLE_VALUE) { free(m_sEvtAvail); free(m_sEvtFilled); free(m_sMemName); printf("server_create: failed: %01d\n", __LINE__); return; }
	m_hAvail = CreateEventA(NULL, FALSE, FALSE, (LPCSTR)m_sEvtAvail);
	if (m_hAvail == NULL || m_hSignal == INVALID_HANDLE_VALUE) { free(m_sEvtAvail); free(m_sEvtFilled); free(m_sMemName); printf("server_create: failed: %01d\n", __LINE__); return; }

    long _sizeHeader = 16; // Hardcodeado debido a los arrays
    long _sizeNodeHeader = 24; // Hardcodeado debido a los arrays
    long _sizeNode = sizeof(Node);


    // Initialise Header
    DWORD _sharedMemorySize = _sizeHeader
        + _sizeNodeHeader
        + IPC_BLOCK_COUNT * _sizeNode
        + IPC_BLOCK_COUNT * IPC_BLOCK_SIZE;

	// Create the file mapping
	m_hMapFile = CreateFileMappingA(INVALID_HANDLE_VALUE,   // FileHandle = new IntPtr(-1)
		                            NULL,                   // SECURITY_ATTRIBUTES
		                            PAGE_READWRITE,         // GetPageAccess(access = PAGE_READWRITE = 0x04;) | (int)options = MemoryMappedFileOptions.None
		                            0,
                                    _sharedMemorySize,
		                            (LPCSTR)m_sMemName);
	if (m_hMapFile == NULL || m_hMapFile == INVALID_HANDLE_VALUE)  { free(m_sEvtAvail); free(m_sEvtFilled); free(m_sMemName); printf("server_create: failed: %01d\n", __LINE__); return; }

	// Map to the file
    Header * m_pHeader = (Header*)MapViewOfFile(m_hMapFile,				// handle to map object
		                                        FILE_MAP_ALL_ACCESS,	// read/write permission
		                                        0,
		                                        0,
                                                _sharedMemorySize);
    if (m_pHeader == NULL) { free(m_sEvtAvail); free(m_sEvtFilled); free(m_sMemName); printf("server_create: failed: %01d\n", __LINE__); return; }

    // Initialise Header
    m_pHeader->SharedMemorySize = _sharedMemorySize;
    m_pHeader->Shutdown = 0;

    // Get NodeHeader pointer
    m_pNodeHeader = &m_pHeader->nodeHeader;
    // Clear the buffer
    ZeroMemory(m_pNodeHeader, _sizeNodeHeader); 

    // Initialize the pointers InitialiseNodeHeader()
    m_pNodeHeader->m_ReadEnd = 0;
    m_pNodeHeader->m_ReadStart = 0;
    m_pNodeHeader->m_WriteEnd = 0;
    m_pNodeHeader->m_WriteStart = 0;
    m_pNodeHeader->nodeCount = IPC_BLOCK_COUNT;
    m_pNodeHeader->NodeBufferSize = IPC_BLOCK_SIZE;

    long NodeHeaderOffset = 0; // -_-
    long NodeOffset = NodeHeaderOffset + _sizeNodeHeader;
    long NodeBufferOffset = NodeOffset + (_sizeNode * IPC_BLOCK_COUNT);
 
	// Create a circular linked list
	int N = 0;
    int NodeCount = IPC_BLOCK_COUNT;
    // First Node
	m_pNodeHeader->m_Nodes[N].Next = 1;
    m_pNodeHeader->m_Nodes[N].Prev = (NodeCount - 1);
    m_pNodeHeader->m_Nodes[N].Offset = NodeBufferOffset;
    m_pNodeHeader->m_Nodes[N].Index = N;
	m_pNodeHeader->m_Nodes[N].AmountWritten = 0;
    // Middle Nodes
    for (N = 1; N < NodeCount - 1; N++)
	{
		// Add this block into the available list
		m_pNodeHeader->m_Nodes[N].Next = (N + 1);
		m_pNodeHeader->m_Nodes[N].Prev = (N - 1);
        m_pNodeHeader->m_Nodes[N].Offset = NodeBufferOffset + (m_pNodeHeader->NodeBufferSize * N);
        m_pNodeHeader->m_Nodes[N].Index = N;
		m_pNodeHeader->m_Nodes[N].AmountWritten = 0;
	}
    // Last Node
	m_pNodeHeader->m_Nodes[N].Next = 0;
    m_pNodeHeader->m_Nodes[N].Prev = (NodeCount - 2);
    m_pNodeHeader->m_Nodes[N].Offset = NodeBufferOffset + (m_pNodeHeader->NodeBufferSize * N);
    m_pNodeHeader->m_Nodes[N].Index = N;
	m_pNodeHeader->m_Nodes[N].AmountWritten = 0;
   
	// Release memory
	free(m_sEvtAvail);
	free(m_sEvtFilled);
	free(m_sMemName);
};

void osIPC::Server::close(void)
{
	// Close the event
	if (m_hSignal) {
		HANDLE handle = m_hSignal;
		m_hSignal = NULL;
		CloseHandle(handle);
	}

	// Close the event
	if (m_hAvail) {
		HANDLE handle = m_hAvail;
		m_hAvail = NULL;
		CloseHandle(handle);
	}

	// Unmap the memory
	if (m_pNodeHeader) {
		NodeHeader *pBuff = m_pNodeHeader;
		m_pNodeHeader = NULL;
		UnmapViewOfFile(pBuff);
	}

	// Close the file handle
	if (m_hMapFile) {
		HANDLE handle = m_hMapFile;
		m_hMapFile = NULL;
		CloseHandle(handle);
	}
};

osIPC::Node* osIPC::Server::GetNodeForReading(DWORD dwTimeout)
{
	// Grab another block to read from
	// Enter a continous loop (this is to make sure the operation is atomic)
	for (;;)
	{
		// Check if there is room to expand the read start cursor
		LONG blockIndex = m_pNodeHeader->m_ReadStart;
		Node *pNode = m_pNodeHeader->m_Nodes + blockIndex;
        if (blockIndex == m_pNodeHeader->m_WriteEnd)
		{
			// No room is available, wait for room to become available
			if (WaitForSingleObject(m_hSignal, dwTimeout) == WAIT_OBJECT_0)
				continue;

			// Timeout
			return NULL;
		}

		// Make sure the operation is atomic
		if (InterlockedCompareExchange(&m_pNodeHeader->m_ReadStart, pNode->Next, blockIndex) == blockIndex)
			return pNode;

		// The operation was interrupted by another thread.
		// The other thread has already stolen this block, try again
		continue;
	}
};

void osIPC::Server::ReturnNode(osIPC::Node* pNode)
{
	// Set the done flag for this block
	pNode->doneRead = 1;

	// Move the read pointer as far forward as we can
	for (;;)
	{
		// Try and get the right to move the poitner
		DWORD blockIndex = m_pNodeHeader->m_ReadEnd;
		pNode = m_pNodeHeader->m_Nodes + blockIndex;
		if (InterlockedCompareExchange(&pNode->doneRead, 0, 1) != 1)
		{
			// If we get here then another thread has already moved the pointer
			// for us or we have reached as far as we can possible move the pointer
			return;
		}

		// Move the pointer one forward (interlock protected)
		InterlockedCompareExchange(&m_pNodeHeader->m_ReadEnd, pNode->Next, blockIndex);

		// Signal availability of more data but only if a thread is waiting
		if (pNode->Prev == m_pNodeHeader->m_WriteStart)
			SetEvent(m_hAvail);
	}
};

DWORD osIPC::Server::read(void *pBuff, DWORD buffSize, DWORD dwTimeout)
{
	// Grab a block
	Node *pNode = GetNodeForReading(dwTimeout);
	if (!pNode) return 0;

	// Copy the data
	DWORD dwAmount = min(m_pNodeHeader->NodeBufferSize, buffSize);
	memcpy(pBuff, m_pNodeHeader->Data[pNode->Index], dwAmount);

	// Return the block
	ReturnNode(pNode);

	// Success
	return dwAmount;
};

osIPC::Client::Client(void)
{
	// Set default params
	m_hMapFile = 0;
	m_hSignal = 0;
	m_hAvail = 0;
	m_pNodeHeader = NULL;
};

osIPC::Client::Client(char * smName)
{
	// Set default params
	m_hMapFile = 0;
	m_hSignal = 0;
	m_hAvail = 0;
	m_pNodeHeader = NULL;

	// Determine the name of the memory
    m_sAddr = (char*)malloc(IPC_MAX_NAME);
    if (!m_sAddr) return;
    strcpy_s(m_sAddr, IPC_MAX_NAME, smName);
	
	char *m_sEvtAvail = (char*)malloc(IPC_MAX_NAME);
	if (!m_sEvtAvail) return;
    sprintf_s(m_sEvtAvail, IPC_MAX_NAME, "%s_evt_nodeavail", m_sAddr);
	
	char *m_sEvtFilled = (char*)malloc(IPC_MAX_NAME);
	if (!m_sEvtFilled) { free(m_sEvtAvail); return; }
    sprintf_s(m_sEvtFilled, IPC_MAX_NAME, "%s_evt_dataexists", m_sAddr);
		
    char *m_sMemName = (char*)malloc(IPC_MAX_NAME);
    if (!m_sMemName) { free(m_sEvtAvail); free(m_sEvtFilled); printf("server_create: failed: %01d\n", __LINE__); return; }
    sprintf_s(m_sMemName, IPC_MAX_NAME, "%s", m_sAddr);

	// Create the events
	m_hSignal = CreateEventA(NULL, FALSE, FALSE, (LPCSTR)m_sEvtFilled);
	if (m_hSignal == NULL || m_hSignal == INVALID_HANDLE_VALUE) { free(m_sEvtAvail); free(m_sEvtFilled); free(m_sMemName); return; }
	m_hAvail = CreateEventA(NULL, FALSE, FALSE, (LPCSTR)m_sEvtAvail);
	if (m_hAvail == NULL || m_hSignal == INVALID_HANDLE_VALUE) { free(m_sEvtAvail); free(m_sEvtFilled); free(m_sMemName); return; }

	// Open the shared file
	m_hMapFile = OpenFileMappingA(	FILE_MAP_ALL_ACCESS,	// read/write access
									FALSE,					// do not inherit the name
									(LPCSTR)m_sMemName);	// name of mapping object

	if (m_hMapFile == NULL || m_hMapFile == INVALID_HANDLE_VALUE)  { free(m_sEvtAvail); free(m_sEvtFilled); free(m_sMemName); return; }
 

	// Map to the file
    Header * m_pHeader = (Header*)MapViewOfFile(m_hMapFile,				// handle to map object
		FILE_MAP_ALL_ACCESS,	// read/write permission
		0,
		0,
		sizeof(Header));

    if (m_pHeader == NULL) { free(m_sEvtAvail); free(m_sEvtFilled); free(m_sMemName); return; }

    m_pNodeHeader = &m_pHeader->nodeHeader;

	// Release memory
	free(m_sEvtAvail);
	free(m_sEvtFilled);
	free(m_sMemName);
};

osIPC::Client::~Client(void)
{
	// Close the event
	CloseHandle(m_hSignal);

	// Close the event
	CloseHandle(m_hAvail);

	// Unmap the memory
	UnmapViewOfFile(m_pNodeHeader);

	// Close the file handle
	CloseHandle(m_hMapFile);
};

osIPC::Node* osIPC::Client::GetNodeForWriting(DWORD dwTimeout)
{
	// Grab another block to write too
	// Enter a continous loop (this is to make sure the operation is atomic)
	for (;;)
	{
		// Check if there is room to expand the write start cursor
		LONG blockIndex = m_pNodeHeader->m_WriteStart;
		Node *pNode = m_pNodeHeader->m_Nodes + blockIndex;
		if (pNode->Next == m_pNodeHeader->m_ReadEnd)
		{
			// No room is available, wait for room to become available
			if (WaitForSingleObject(m_hAvail, dwTimeout) == WAIT_OBJECT_0)
				continue;

			// Timeout
			return NULL;
		}

		// Make sure the operation is atomic
		if (InterlockedCompareExchange(&m_pNodeHeader->m_WriteStart, pNode->Next, blockIndex) == blockIndex)
			return pNode;

		// The operation was interrupted by another thread.
		// The other thread has already stolen this block, try again
		continue;
	}
};

void osIPC::Client::PostNode(Node *pNode)
{
	// Set the done flag for this block
	pNode->doneWrite = 1;

	// Move the write pointer as far forward as we can
	// always starting from WriteEnd to make all contiguous
	// completed nodes available for reading.
	for (;;)
	{
		// Try and get the right to move the poitner
		DWORD blockIndex = m_pNodeHeader->m_WriteEnd;
		pNode = m_pNodeHeader->m_Nodes + blockIndex;
		if (InterlockedCompareExchange(&pNode->doneWrite, 0, 1) != 1)
		{
			// If we get here then another thread has already moved the pointer
			// for us or we have reached as far as we can possible move the pointer
			return;
		}

		// Move the pointer one forward (interlock protected)
		InterlockedCompareExchange(&m_pNodeHeader->m_WriteEnd, pNode->Next, blockIndex);
		
		// Signal availability of more data but only if threads are waiting
		if (blockIndex == m_pNodeHeader->m_ReadStart)
			SetEvent(m_hSignal);
	}
};

DWORD osIPC::Client::write(void *pBuff, DWORD amount, DWORD dwTimeout)
{
	// Grab a block
	Node *pNode = GetNodeForWriting(dwTimeout);
	if (!pNode) return 0;

	// Copy the data
	DWORD dwAmount = min(amount, IPC_BLOCK_SIZE);

	memcpy(m_pNodeHeader->Data[pNode->Index], pBuff, dwAmount);
	pNode->AmountWritten = dwAmount;

	// Post the block
	PostNode(pNode);

	// Success
	return dwAmount;
};

