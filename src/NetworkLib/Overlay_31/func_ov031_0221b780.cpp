#include <globaldefs.h>
#include "NitroSDK/IPC.h"
#include "NitroSDK/Cache.h"

extern "C" unsigned int func_ov031_0221b8b4(int, int, int);
extern "C" int func_ov031_0221b284(int, int, int, int);
extern "C" void WaitByLoop(int);

// USA: func_ov031_0221b780
extern "C" ARM int func_ov031_0221b780(int a0, int a1, int a2) {
    while (IsIPCCommandHandlerRegistered(4, IPCSide_Arm7) == 0) {
    }
    SetArm9IPCCommandHandler(4, (IPCCommandHandler)func_ov031_0221b8b4);
    CleanCacheRange((const void*)a2, a1);
    for (;;) {
        int r = func_ov031_0221b284(2, a0, a1, a2);
        if (r == 1) {
            return r;
        }
        WaitByLoop(0x40000);
    }
}
