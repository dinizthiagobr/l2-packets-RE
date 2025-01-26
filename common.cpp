#include "common.h"

FILE* fDummy;

void CreateConsole() {
    AllocConsole();

    freopen_s(&fDummy, "CONOUT$", "w", stdout);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONIN$", "r", stdin);

    std::cout << "[*] Console attached successfully!" << std::endl;
}

void CloseConsole() {
    fclose(fDummy);
    FreeConsole();
}

void PrintBytes(DWORD initial_adddress)
{
    for (DWORD cur_byte = 0x0; cur_byte < 0x10; cur_byte++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)*((BYTE*)initial_adddress + cur_byte) << " ";
    }
}