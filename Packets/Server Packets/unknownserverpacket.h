#pragma once

#include "baseserverpacket.h"
#include "../serverpackets.h"

class UnknownSP : public BaseServerPacket {
public:
	UnknownSP(NetworkServerPacket networkPacket);

	void Print() override;
};