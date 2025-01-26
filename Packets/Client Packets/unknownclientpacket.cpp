#include <iostream>
#include "unknownclientpacket.h"

UnknownCP::UnknownCP(int _opCode, const char* _format) : BaseClientPacket(_opCode, _format) {}

void UnknownCP::SendToServer() {}

void UnknownCP::Print() {
	BaseClientPacket::Print();

	std::cout << " [Undefined]";

	std::cout << std::endl;
}