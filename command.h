#pragma once

#include <cstring>
#include <string>

class Command {
private:
	Command() = delete;
public:
	static void Run(const wchar_t* command);
};