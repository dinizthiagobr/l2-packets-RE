#pragma once

#include <Windows.h>

class BaseServerPacket {
public:
	int opCode;

	BaseServerPacket(int opCode);

	virtual void Print();
	virtual void Handle();
};