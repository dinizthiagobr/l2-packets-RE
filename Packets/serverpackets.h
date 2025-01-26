#pragma once

#include <Windows.h>
#include "Server Packets/baseserverpacket.h"

struct ServerPacket_OpCode {
	static const int Say = 0x4A;
	static const int Attack = 0x05;
	static const int MoveToLocation = 0x01;
	static const int MyTargetSelected = 0xA6;
	static const int StatusUpdate = 0x0E;
	static const int CharInfo = 0x03;
	static const int NpcInfo = 0x16;
	static const int MoveToPawn = 0x60;
};

struct NetworkServerPacket {
	unsigned char opCode, p1;
	unsigned short int subId, dataSize, p2;
	unsigned char* data;
};

BaseServerPacket* DecodeServerPacket(DWORD startAddr);