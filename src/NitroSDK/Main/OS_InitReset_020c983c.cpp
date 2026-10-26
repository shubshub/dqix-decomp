#include <globaldefs.h>
#include "NitroSDK/IPC.h"

extern "C" void func_020c9890(int unused, unsigned int code);

extern short data_02111668;

// Main, originally func_020c983c (USA 0x020c983c, EUR 0x020c984c, JPN 0x020cb308)
extern "C" ARM void OS_InitReset(void) {
    if (*(unsigned short*)((char*)&data_02111668 + 2) != 0) return;
    *(unsigned short*)((char*)&data_02111668 + 2) = 1;
    InitializeInterProcessorCommunication();
    while (IsIPCCommandHandlerRegistered(0xc, IPCSide_Arm7) == 0) {
    }
    SetArm9IPCCommandHandler(0xc, (IPCCommandHandler)func_020c9890);
}
