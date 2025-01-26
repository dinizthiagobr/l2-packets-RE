#pragma once

#include <array>

struct Settings {
	static bool printSendPacket;
	static bool printReceivePacket;
	static bool botEnabled;
	static char commandPrefix;
	static int PrintOnly_ServerPacket_OpCode;
	static std::array<int, 1> NeverPrint_ServerPacket_OpCodes;
};