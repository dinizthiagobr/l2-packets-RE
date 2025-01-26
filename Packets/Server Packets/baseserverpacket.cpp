#include <iostream>
#include "baseserverpacket.h"

BaseServerPacket::BaseServerPacket(int _opCode) {
	opCode = _opCode;
}

void BaseServerPacket::Print() {
	std::cout << "[ReceivePacket] -> ";
	std::cout << std::hex << std::showbase << "[" << opCode << "]";
}

void BaseServerPacket::Handle() {}