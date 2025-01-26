#pragma once

#include "baseserverpacket.h"
#include "../serverpackets.h"

class NpcInfo : public BaseServerPacket {
public:
	int opCode;
	int objectId;
	bool isAttackable;
	bool isDead;

	NpcInfo(NetworkServerPacket networkPacket);

	void Print() override;
	void Handle() override;
};