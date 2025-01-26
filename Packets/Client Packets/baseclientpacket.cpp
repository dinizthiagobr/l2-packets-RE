#include <iostream>
#include "baseclientpacket.h"

BaseClientPacket::BaseClientPacket(int _opCode, const char* _format) {
	opCode = _opCode;
	format = _format;
}

void BaseClientPacket::Print() {
	std::cout << "[SendPacket] -> ";
	std::cout << std::hex << std::showbase << "[" << opCode << "]";
}