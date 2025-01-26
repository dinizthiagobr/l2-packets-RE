#include "say2.h"
#include "../clientpackets.h"
#include "../../engine.h"

Say2::Say2(int _opCode, const char* _format, DWORD startAddr) : BaseClientPacket(_opCode, _format) {
	message = *((const wchar_t**)(startAddr + 0x10));
	channel = *((int*)(startAddr + 0x14));
}

Say2::Say2(const wchar_t* _message, int _channel) : BaseClientPacket(ClientPacket_OpCode::Say2, "cSd") {
	message = _message;
	channel = _channel;
}

void Say2::SendToServer() {
	Engine::SendPacket(Offsets::NetworkHandlerPointer, format, opCode, (DWORD)message, channel);
}

void Say2::Print() {
	BaseClientPacket::Print();

	std::cout << " [Say2] { ";

	std::wcout << "message: " << message << " ";
	std::cout << ", channel: " << channel << " ";

	std::cout << "}";
	std::cout << std::endl;
}