#include <globaldefs.h>
#include "NitroSDK/IPC.h"

void SetArm9IPCCommandHandler(int command, IPCCommandHandler handler);
extern "C" int func_020d28f0(void);
bool IsIPCCommandHandlerRegistered(int command, IPCSide side);
extern "C" void func_020d27fc(int channel, int packed);
extern "C" void func_020c976c(int);

// USA: func_020d2820
extern "C" ARM void func_020d2820(void) {
    SetArm9IPCCommandHandler(7, (IPCCommandHandler)func_020d27fc);
    if (func_020d28f0() == 0) return;
    if (IsIPCCommandHandlerRegistered(7, IPCSide_Arm7) != 0) return;
    do {
        func_020c976c(100);
    } while (IsIPCCommandHandlerRegistered(7, IPCSide_Arm7) == 0);
}
