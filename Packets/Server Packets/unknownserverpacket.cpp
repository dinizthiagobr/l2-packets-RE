#include <iostream>
#include "unknownserverpacket.h"

UnknownSP::UnknownSP(NetworkServerPacket networkPacket) : BaseServerPacket(networkPacket.opCode) {}

void UnknownSP::Print() {
	BaseServerPacket::Print();

	std::cout << " [Undefined]";

	std::cout << std::endl;
}