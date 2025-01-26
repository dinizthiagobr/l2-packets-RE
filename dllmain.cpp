#include <Windows.h>
#include <iostream>
#include <thread>
#include "dllmain.h"
#include "common.h"
#include "engine.h"

HMODULE dllHandle = nullptr;
std::atomic<bool> killSignal(false);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        dllHandle = hModule;

        CreateConsole();
        std::cout << "[*] DLL injected!" << std::endl;

        Engine::InitializeHooks();
        std::cout << "[*] Hooks installed!" << std::endl;

        CreateThread(nullptr, 0, MainLoop, nullptr, 0, nullptr);
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)
    {
        DetachDll();
    }

    return TRUE;
}

DWORD WINAPI MainLoop(LPVOID lpParameter)
{
    std::cout << "[*] Main Loop thread started!" << std::endl;

    while (killSignal == false)
    {
        if (GetAsyncKeyState(VK_F10) & 0x8000)
        {
            std::cout << "[*] F10 pressed, exiting..." << std::endl;

            killSignal = true;
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return DetachDll();
}

DWORD DetachDll()
{
    std::cout << "[*] Bye!" << std::endl;

    CloseConsole();
    FreeLibraryAndExitThread(dllHandle, 0);

    return 0;
}

