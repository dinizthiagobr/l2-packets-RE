#include "bot.h"
#include "packets/Client Packets/action.h"

BotStatus Bot::status = DISABLED;
Enemy Bot::activeTarget;

void Bot::Start() {
	status = IDLE;

	CreateThread(nullptr, 0, Loop, nullptr, 0, nullptr);
}

void Bot::Stop() {
	status = DISABLED;
}

DWORD WINAPI Bot::Loop(LPVOID lpParam) {
	while (status != DISABLED) {
		if (status == IDLE) {
			activeTarget = World::GetNextEnemy();
			
			Action actionPacket(activeTarget);
			actionPacket.SendToServer();

			Sleep(50);

			actionPacket.SendToServer();

			status = WITH_TARGET;
		}
		else if (status == WITH_TARGET) {
			activeTarget = World::GetUpdatedEnemy(activeTarget);

			if (activeTarget.isDead) {
				World::RemoveEnemy(activeTarget);;
				status = IDLE;
			}

			Sleep(300);
		}

		Sleep(100);
	}

	return 0;
}