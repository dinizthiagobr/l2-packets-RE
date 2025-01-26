#include "clientpackets.h"

BaseClientPacket* DecodeClientPacket(DWORD startAddr) {
	char* format = *((char**)(startAddr + 0x8));
	int opCode = *((int*)(startAddr + 0xC));

	switch (opCode) {
		case ClientPacket_OpCode::Say2:
			return new Say2(opCode, format, startAddr);
		case ClientPacket_OpCode::Action:
			return new Action(opCode, format, startAddr);
		default:
			return new UnknownCP(opCode, format);
	}

	return new UnknownCP(opCode, format);
}