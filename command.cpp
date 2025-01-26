#include "command.h"
#include "Packets/Client Packets/say2.h"
#include "settings.h"
#include "Packets/serverpackets.h"
#include "Packets/clientpackets.h"
#include "bot.h"

void Command::Run(const wchar_t* command) {
	std::wstring commandStr = std::wstring(command);

	if (commandStr == L".test") {
		Say2 say2Packet(L"all set boss", 0x0);
		say2Packet.SendToServer();
	}
	else if (commandStr == L".toggle_send_packet") {
		Settings::printSendPacket = !Settings::printSendPacket;
	}
	else if (commandStr == L".toggle_receive_packet") {
		Settings::printReceivePacket = !Settings::printReceivePacket;
	}
	else if (commandStr.find(L".filter_receive_packet") == 0) {
		int filteredPacket = std::stoi(commandStr.substr(23), nullptr, 16);
		Settings::PrintOnly_ServerPacket_OpCode = filteredPacket;
	}
	else if (commandStr.find(L".clear_filter_receive_packet") == 0) {
		Settings::PrintOnly_ServerPacket_OpCode = 0x0;
	}
	else if (commandStr == L".toggle_bot") {
		Settings::botEnabled = !Settings::botEnabled;

		if (Settings::botEnabled) {
			Bot::Start();
		}
		else {
			Bot::Stop();
		}
	}
	else {
		return;
	}
}