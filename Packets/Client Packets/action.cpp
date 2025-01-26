#include "action.h"
#include "../../engine.h"

Action::Action(int _opCode, const char* _format, DWORD startAddr) : BaseClientPacket(_opCode, _format) {
	objectId = *((int*)(startAddr + 0x10));
	originX = *((int*)(startAddr + 0x14));
	originY = *((int*)(startAddr + 0x18));
	originZ = *((int*)(startAddr + 0x1C));
	shiftFlag = *((int*)(startAddr + 0x20));
}

Action::Action(Enemy enemy) : BaseClientPacket(ClientPacket_OpCode::Action, "cddddc") {
	objectId = enemy.objectId;
	originX = 0;
	originY = 0;
	originZ = 0;
	shiftFlag = 0;
}

void Action::SendToServer() {
	Engine::SendPacket(Offsets::NetworkHandlerPointer, format, opCode, objectId, originX, originY, originZ, shiftFlag);
}

void Action::Print() {
	BaseClientPacket::Print();

	std::cout << " [Action] { ";

	std::cout << "objectId: " << objectId << " ";
	std::cout << ", originX: " << originX << " ";
	std::cout << ", originY: " << originY << " ";
	std::cout << ", originZ: " << originZ << " ";
	std::cout << ", shiftFlag: " << shiftFlag << " ";

	std::cout << "}";
	std::cout << std::endl;
}