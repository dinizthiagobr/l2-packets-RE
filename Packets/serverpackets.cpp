#include "serverpackets.h"
#include "Server Packets/npcinfo.h"
#include "Server Packets/unknownserverpacket.h"

BaseServerPacket* DecodeServerPacket(DWORD startAddr) {
	DWORD packetStartAddr = *((DWORD*)startAddr);
	NetworkServerPacket networkPacket = *((NetworkServerPacket*)packetStartAddr);

	switch (networkPacket.opCode) {
	case ServerPacket_OpCode::NpcInfo:
		return new NpcInfo(networkPacket);
	default:
		return new UnknownSP(networkPacket);
	}

	return new UnknownSP(networkPacket);
}