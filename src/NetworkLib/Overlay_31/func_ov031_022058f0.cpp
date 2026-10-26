#include <globaldefs.h>
#include <NitroSDK/Mutex.h>
#include <NitroSDK/Interrupts.h>

struct Struct_ov031_022058f0_2 {
    char padding[0xe0];
    Mutex unknown_e0_;
};
struct Struct_ov031_022058f0 {
    char padding[0x64];
    Struct_ov031_022058f0_2* state;
    char unknown_68_[8];
    volatile short flags;
    signed char unknown_72_;
    signed char status;
};
extern "C" int func_ov031_02207180(void*);
extern "C" int func_ov031_02205a38(Struct_ov031_022058f0*, int, int, int, int, int, int);

enum { Enum_ov031_022058f0_1 = 1 };

// USA: func_ov031_022058f0
extern "C" ARM int func_ov031_022058f0(Struct_ov031_022058f0* arg0, int a, int b, int c, int d, int flags) {
    Struct_ov031_022058f0_2* state;
    int var1;
    int var2;
    signed char status;
    int closed;
    int result;

    if (func_ov031_02207180(arg0)) return -28;
    if ((flags & 4) || arg0->unknown_72_ == 0) {
        if (arg0->status == 4) return -28;
        var1 = 0;
    } else {
        if (GetProcessorMode() == 0x12) return -28;
        var1 = Enum_ov031_022058f0_1;
    }
    var2 = 0;
    if (arg0 != NULL) var2 = (arg0->flags & 1) != 0;
    if (!var2) return -39;
    status = arg0->status;
    closed = 1;
    if (status != 0 && status != 4) closed = 0;
    if (closed) {
        if (!(arg0->flags & 4) || (arg0->flags & 8)) return -56;
    }
    state = arg0->state;
    if (!(var1 & Enum_ov031_022058f0_1)) {
        if (!TryLockMutex(&state->unknown_e0_)) return -6;
    } else {
        LockMutex(&state->unknown_e0_);
    }
    result = func_ov031_02205a38(arg0, a, b, c, d, var1, flags);
    UnlockMutex(&state->unknown_e0_);
    return result;
}
