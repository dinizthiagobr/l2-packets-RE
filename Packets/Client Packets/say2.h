#pragma once

#include <Windows.h>
#include "baseclientpacket.h"

class Say2 : public BaseClientPacket {
private:
	int channel;
public:
	const wchar_t* message;

	Say2(int opCode, const char* format, DWORD startAddr);
	Say2(const wchar_t* _message, int _channel);

	void Print() override;
	void SendToServer() override;
};