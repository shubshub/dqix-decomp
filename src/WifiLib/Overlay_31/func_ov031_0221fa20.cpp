#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_ov031_0224f670_11 {
    char pad[0x68];
    int unknown_68_;
    int unknown_6c_;
};

extern Struct_ov031_0224f670_11 data_ov031_0224f670;
extern void* data_ov031_0224f6f4[4];

// USA: func_ov031_0221fa20
extern "C" THUMB void* func_ov031_0221fa20() {
    int var0 = DisableIRQInterrupts();
    int index = data_ov031_0224f670.unknown_6c_;
    void* entry;
    if (data_ov031_0224f670.unknown_68_ == index) {
        entry = 0;
    } else {
        entry = data_ov031_0224f6f4[index];
        data_ov031_0224f670.unknown_6c_ = index + 1;
        if (data_ov031_0224f670.unknown_6c_ >= 4) data_ov031_0224f670.unknown_6c_ = 0;
    }
    SetIRQInterruptState(var0);
    return entry;
}
