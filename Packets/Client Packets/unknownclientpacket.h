#pragma once

#include "baseclientpacket.h"

class UnknownCP : public BaseClientPacket {
public:
	UnknownCP(int opCode, const char* format);

	void Print() override;
	void SendToServer() override;
};