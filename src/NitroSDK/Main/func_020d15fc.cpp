#include <globaldefs.h>
#include "NitroSDK/IPC.h"

extern "C" void func_020d12e4(void);
void InitializeInterProcessorCommunication(void);
bool IsIPCCommandHandlerRegistered(int command, IPCSide side);
void SetArm9IPCCommandHandler(int command, IPCCommandHandler handler);
extern "C" void func_020d16b0(void);
extern "C" void func_020d1954(void* obj);
extern "C" void func_020d15b4(int flag);
extern "C" void func_020d18a4(int a, int msg);
extern "C" void func_020d18d0(int context, int code);
extern "C" void func_020d1940(void);

struct Struct_020d15fc {
    char pad0[8];
    int flag8;
    int fc;
    char pad10[8];
    int f18;
};
extern "C" struct Struct_020d15fc _ZZ15inline_020d16b0vE1s;
extern int data_02112240;

// USA: func_020d15fc
extern "C" ARM void func_020d15fc(void) {
    if (_ZZ15inline_020d16b0vE1s.flag8 != 0) return;
    _ZZ15inline_020d16b0vE1s.flag8 = 1;
    func_020d12e4();
    _ZZ15inline_020d16b0vE1s.fc = 0;
    InitializeInterProcessorCommunication();
    do {
    } while (!IsIPCCommandHandlerRegistered(0xd, IPCSide_Arm7));
    SetArm9IPCCommandHandler(0xd, (IPCCommandHandler)func_020d18a4);
    func_020d16b0();
    SetArm9IPCCommandHandler(0xd, 0);
    SetArm9IPCCommandHandler(0xd, (IPCCommandHandler)func_020d18d0);
    _ZZ15inline_020d16b0vE1s.f18 = 0;
    func_020d1954(&data_02112240);
    SetArm9IPCCommandHandler(0x11, (IPCCommandHandler)func_020d1940);
    func_020d15b4(0);
}
