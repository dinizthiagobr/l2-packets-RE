#pragma once

#include <Windows.h>
#include "Client Packets/baseclientpacket.h"
#include "Client Packets/say2.h"
#include "Client Packets/action.h"
#include "Client Packets/unknownclientpacket.h"

struct ClientPacket_OpCode {
	static const int Say2 = 0x38;
	static const int Move = 0x01;
	static const int Action = 0x04;
};

BaseClientPacket* DecodeClientPacket(DWORD startAddr);