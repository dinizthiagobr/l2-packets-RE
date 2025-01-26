#pragma once

#include <Windows.h>
#include "world.h"

enum BotStatus {
	DISABLED,
	IDLE,
	WITH_TARGET,
};

class Bot {
	private:
		static BotStatus status;
		static Enemy activeTarget;

		static DWORD WINAPI Loop(LPVOID lpParam);
		Bot() = delete;
	public:
		static void Start();
		static void Stop();
};