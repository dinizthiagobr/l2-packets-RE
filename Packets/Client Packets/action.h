#pragma once

#include "baseclientpacket.h"
#include "../clientpackets.h"
#include "../../world.h"

class Action : public BaseClientPacket {
private:
	int objectId;
	int originX;
	int originY;
	int originZ;
	int shiftFlag;
public:
	Action(int opCode, const char* format, DWORD startAddr);
	Action(Enemy enemy);

	void Print() override;
	void SendToServer() override;
};