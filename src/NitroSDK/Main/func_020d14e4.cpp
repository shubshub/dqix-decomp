#include <globaldefs.h>
#include "NitroSDK/GamecardBusOwnership.h"
#include "NitroSDK/Interrupts.h"

extern "C" void WaitByLoop(int);
unsigned short GetLockOwner(GamecardBusLock* lock);

struct Struct_020d14e4 {
    int field0;
    unsigned int unknown_4_;
};

// USA: func_020d14e4
extern "C" ARM void func_020d14e4(unsigned short owner, Struct_020d14e4* s) {
    for (;;) {
        s->unknown_4_ = DisableIRQInterrupts();
        int var0 = GetLockOwner((GamecardBusLock*)0x027fffe8) & 0x40;
        s->field0 = var0;
        if (var0) return;
        if (!TryAcquireGBABus(owner)) return;
        SetIRQInterruptState(s->unknown_4_);
        WaitByLoop(1);
    }
}
