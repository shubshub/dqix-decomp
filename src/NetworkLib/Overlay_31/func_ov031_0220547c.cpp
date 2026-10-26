#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

extern "C" ARM int func_ov031_0220547c(void* a0);
extern "C" ARM void func_ov031_02205524(void* a0, void* a1);
extern "C" ARM void func_ov031_022070c8(void* a0);

typedef void* (*Type_01ff8300_2)(int size);
struct Struct_ov031_02205414 { char pad[0x18]; Type_01ff8300_2 unknown_18_; };
extern Struct_ov031_02205414* data_ov031_022496a4;

// USA: func_ov031_02205414
extern "C" ARM void* func_ov031_02205414(void* a0) {
    int size = func_ov031_0220547c(a0);
    void* p;
    int state = DisableIRQInterrupts();
    p = data_ov031_022496a4->unknown_18_(size);
    if (p != NULL) {
        VectorizedMemset(p, 0, size);
        func_ov031_02205524(p, a0);
        func_ov031_022070c8(p);
    }
    SetIRQInterruptState(state);
    return p;
}
