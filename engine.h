#pragma once

#include <Windows.h>
#include <iostream>
#include <iomanip>

struct Offsets {
	static const DWORD SendPacket = 0x1029B0;
	static const DWORD AddNetworkQueue = 0x12B7D0;
	static DWORD NetworkHandlerPointer;
};

typedef DWORD(_stdcall* SendPacketType)(DWORD thisClass, const char* format, ...);

class Engine {
private:
	Engine() = delete;

	static DWORD sendPacketNewStartAddr;
	static DWORD addNetworkQueueNewStartAddr;
public:
	static void InitializeHooks();
	static SendPacketType SendPacket;
};