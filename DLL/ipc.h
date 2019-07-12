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

#pragma once

#ifndef IPC_H
#define IPC_H

// Definitions
#define IPC_BLOCK_COUNT			50
#define IPC_BLOCK_SIZE			32792 // MaxPacket 32768 + packetInfo 24

#define IPC_SRV_MMF_NAME        "OSPECMDBUFF"

#define IPC_MAX_NAME			256



// ---------------------------------------
// -- Inter-Process Communication class --
// ---------------------------------------------------------------
// Provides intercommunication between processes and there threads
// ---------------------------------------------------------------
class osIPC
{
public:
	// Block that represents a piece of data to transmit between the
	// client and server
	struct Node
	{
		// Variables
		int						Next;						// Next block in the circular linked list
		int						Prev;						// Previous block in the circular linked list

		volatile LONG			doneRead;					// Flag used to signal that this block has been read
		volatile LONG			doneWrite;					// Flag used to signal that this block has been written
		
		LONG					Offset;						// Represents the offset relative to <see cref="Buffer.BufferStartPtr"/> where the data for this node can be found.

		int						_Padding;					// Padded used to ensure 64bit boundary
		int						Index;						// Represents the index of the current node.

        int						AmountWritten;              // Holds the number of bytes written into this node.
	};

private:
	// Shared memory buffer that contains everything required to transmit
	// data between the client and server
	struct NodeHeader
	{
		// Cursors
		volatile LONG			m_ReadEnd;					// End of the read cursor
		volatile LONG			m_ReadStart;				// Start of read cursor

		volatile LONG			m_WriteEnd;					// Pointer to the first write cursor, i.e. where we are currently writting to
		volatile LONG			m_WriteStart;				// Pointer in the list where we are currently writting

		int						nodeCount;					// The number of nodes within the buffer
		int						NodeBufferSize;				// The size of the buffer for each node

		// Block data, this is placed first to remove the offset (optimisation)
		Node					m_Nodes[IPC_BLOCK_COUNT];	// Array of buffers that are used in the communication
		BYTE					Data[IPC_BLOCK_COUNT][IPC_BLOCK_SIZE];		// Data contained in this block
	};

	struct Header
	{
		LONG					SharedMemorySize;			// The total size of the buffer 
		volatile int			Shutdown;					// Flag indicating whether the owner of the buffer has closed its MemoryMappedFile
		int						_padding0;					// Pad to 16-bytes

		BYTE					_padding1;                  // Agregado mio para que coincida

		NodeHeader				nodeHeader;
	};

public:
	// ID Generator
	static DWORD GetID(void)
	{
		// Generate an ID and return id
		static volatile LONG id = 1;
		return (DWORD)InterlockedIncrement((LONG*)&id);
	};

public:
	// Server class
	class Server
	{
	public:
		// Construct / Destruct
		Server();
		~Server();

	private:
		// Internal variables
        char					*m_sAddr;		// Address of this server
		HANDLE					m_hMapFile;		// Handle to the mapped memory file
		HANDLE					m_hSignal;		// Event used to signal when data exists
		HANDLE					m_hAvail;		// Event used to signal when some blocks become available
		NodeHeader				*m_pNodeHeader;		// Buffer that points to the shared memory

	public:
		// Exposed functions
		DWORD					read(void *pBuff, DWORD buffSize, DWORD timeout = INFINITE);
        char*					getAddress(void) { return m_sAddr; };

		// Block functions
		Node*					GetNodeForReading(DWORD dwTimeout = INFINITE);
		void					ReturnNode(Node* pBlock);

		// Create and destroy functions
		void					create(void);
		void					close(void);
	};

	// Client class
	class Client
	{
	public:
		// Construct / Destruct
		Client(void);
		Client(char *connectAddr);
		~Client();

	private:
		// Internal variables
        char					*m_sAddr;		// Name of the memory mapped file
		HANDLE					m_hMapFile;		// Handle to the mapped memory file
		HANDLE					m_hSignal;		// Event used to signal when data exists
		HANDLE					m_hAvail;		// Event used to signal when some blocks become available
		NodeHeader				*m_pNodeHeader;		// Buffer that points to the shared memory

	public:
		// Exposed functions
		DWORD					write(void *pBuff, DWORD amount, DWORD dwTimeout = INFINITE);	// Writes to the buffer
		bool					waitAvailable(DWORD dwTimeout = INFINITE);						// Waits until some blocks become available

		Node*					GetNodeForWriting(DWORD dwTimeout = INFINITE);							// Gets a block
		void					PostNode(Node *pBlock);										// Posts a block to be processed				

		// Functions
		BOOL					IsOk(void) { if (m_pNodeHeader) return true; else return false; };
	};
};

#endif