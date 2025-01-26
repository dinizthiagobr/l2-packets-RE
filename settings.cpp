#include "settings.h"
#include "Packets/serverpackets.h"

char Settings::commandPrefix = '.';
bool Settings::printSendPacket = false;
bool Settings::printReceivePacket = false;
bool Settings::botEnabled = false;

int Settings::PrintOnly_ServerPacket_OpCode = 0x0;
std::array<int, 1> Settings::NeverPrint_ServerPacket_OpCodes = { ServerPacket_OpCode::MoveToLocation };