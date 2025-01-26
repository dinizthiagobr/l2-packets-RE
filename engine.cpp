#include "engine.h"
#include "Packets/serverpackets.h"
#include "settings.h"
#include "command.h"
#include "Packets/clientpackets.h"

DWORD Offsets::NetworkHandlerPointer = 0x0;

SendPacketType Engine::SendPacket = nullptr;
DWORD Engine::sendPacketNewStartAddr = 0x0;

DWORD Engine::addNetworkQueueNewStartAddr = 0x0;

DWORD sendPacketEspAddress = 0x0;
DWORD receivePacketEspAddress = 0x0;

static bool __stdcall SendPacketHook()
{
	BaseClientPacket* packet = DecodeClientPacket(sendPacketEspAddress);

	if (packet->opCode == ClientPacket_OpCode::Say2) {
		if (Offsets::NetworkHandlerPointer == 0x0) {
			Offsets::NetworkHandlerPointer = *(DWORD*)(sendPacketEspAddress + 0x4);
		}

		Say2* derivedPacket = static_cast<Say2*>(packet);
		if (derivedPacket->message[0] == Settings::commandPrefix) {
			Command::Run(derivedPacket->message);

			// bruh
			__asm {
				mov eax, 0;
			}

			return false;
		}
	}

	if (Settings::printSendPacket) {
		packet->Print();
	}

	return true;
}

static VOID __declspec(naked) SendPacketTrampoline() {
	__asm
	{
		mov sendPacketEspAddress, esp;

		pushad;
		pushfd;

		call SendPacketHook;
		test eax, eax;
		jz early_return;

		popfd;
		popad;

		mov eax, 2000h;
		jmp[Engine::sendPacketNewStartAddr];
		
	early_return:
		popfd;
		popad;
		ret;
	}
}

static void __stdcall AddNetworkQueueHook()
{
	BaseServerPacket* packet = DecodeServerPacket(receivePacketEspAddress + 0x4);

	packet->Handle();

	if (Settings::printReceivePacket) {
		if (Settings::PrintOnly_ServerPacket_OpCode != 0x0 && packet->opCode != Settings::PrintOnly_ServerPacket_OpCode) {
			return;
		}

		if (std::count(std::begin(Settings::NeverPrint_ServerPacket_OpCodes), std::end(Settings::NeverPrint_ServerPacket_OpCodes), packet->opCode) > 0) {
			return;
		}

		packet->Print();
	}
}

static VOID __declspec(naked) AddNetworkQueueTrampoline() {
	__asm
	{
		mov receivePacketEspAddress, esp;

		pushad;
		pushfd;

		call AddNetworkQueueHook;

		popfd;
		popad;

		push ebx;
		push esi;
		push edi;
		mov esi, ecx;
		jmp[Engine::addNetworkQueueNewStartAddr];
	}
}

static DWORD Hook(DWORD originalAddress, PVOID trampolineFunction) {
	DWORD newStartAddress = originalAddress + 5;

	DWORD originalProtect;
	VirtualProtect((PVOID)originalAddress, 5, PAGE_EXECUTE_READWRITE, &originalProtect);
	*(BYTE*)originalAddress = 0xE9;
	*((DWORD*)((BYTE*)originalAddress + 0x1)) = (DWORD)trampolineFunction - originalAddress - 5;
	VirtualProtect((PVOID)originalAddress, 5, PAGE_EXECUTE_READWRITE, &originalProtect);

	return newStartAddress;
}

void Engine::InitializeHooks() {
	HMODULE hEngineBase = GetModuleHandleA("engine.dll");

	/* Start SendPacket Hook */

	DWORD originalSendPacketAddr = (DWORD)hEngineBase + Offsets::SendPacket;
	SendPacket = (SendPacketType)(originalSendPacketAddr);
	sendPacketNewStartAddr = Hook(originalSendPacketAddr, SendPacketTrampoline);

	/* End SendPacket Hook */

	/* Start AddNetworkQueue Hook */

	DWORD originalAddNetworkQueueAddr = (DWORD)hEngineBase + Offsets::AddNetworkQueue;
	addNetworkQueueNewStartAddr = Hook(originalAddNetworkQueueAddr, AddNetworkQueueTrampoline);

	/* End AddNetworkQueue Hook */
}
