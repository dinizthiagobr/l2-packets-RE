#include <iostream>
#include "npcinfo.h"
#include "../../world.h"

NpcInfo::NpcInfo(NetworkServerPacket networkPacket) : BaseServerPacket(networkPacket.opCode) {
	const DWORD dataAddr = (DWORD)networkPacket.data;
	
	objectId = *((int*)dataAddr);
	isAttackable = *((int*)(dataAddr + 0x8));
	isDead = *((int*)(dataAddr + 0x77));
}

void NpcInfo::Print() {
	BaseServerPacket::Print();

	std::cout << " [NpcInfo] { ";

	std::wcout << "objectId: " << objectId << " ";
	std::cout << ", isAttackable: " << isAttackable << " ";
	std::cout << ", isDead: " << isDead << " ";

	std::cout << "}";
	
	std::cout << std::endl;
}

void NpcInfo::Handle() {
	if (!isAttackable) {
		return;
	}

	World::AddEnemy({ objectId, isDead });
}