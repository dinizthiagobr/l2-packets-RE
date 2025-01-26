#pragma once

class BaseClientPacket {
protected:
	const char* format;
public:
	int opCode;

	BaseClientPacket(int opCode, const char* format);

	virtual void Print();
	virtual void SendToServer() = 0;
};