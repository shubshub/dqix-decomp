#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_ov031_0221f26c {
    unsigned int type;
    unsigned int start;
    unsigned int size;
    unsigned int unknown_c_;
};
typedef void (*Type_01ff8300)();
struct Struct_ov031_0224f620_7 {
    unsigned int start;
    unsigned int unknown_4_;
    Struct_ov031_0221f26c* region;
    char unknown_c_[0xc];
    int state;
    void* owner;
    unsigned int unknown_20_;
    unsigned int base;
};
extern Struct_ov031_0224f620_7 data_ov031_0224f620;
extern "C" int func_ov031_0220c970(unsigned int, unsigned int);
extern "C" int func_ov031_0220cae0(Struct_ov031_0221f26c*, Type_01ff8300);
extern "C" void func_ov031_0221ecc8();

// USA: func_ov031_0221f26c
extern "C" THUMB int func_ov031_0221f26c(void* owner, unsigned int base, unsigned int size) {
    int var0 = DisableIRQInterrupts();
    Struct_ov031_0221f26c* region = (Struct_ov031_0221f26c*)((base + 0x53) & ~3u);
    data_ov031_0224f620.base = base;
    data_ov031_0224f620.region = region;
    unsigned int start = ((unsigned int)region + 0x2f) & ~31u;
    data_ov031_0224f620.start = start;
    start = (start + 0x231f) & ~31u;
    data_ov031_0224f620.unknown_20_ = start;
    start = (start + 0xdf) & ~31u;
    region->start = start;
    data_ov031_0224f620.region->size = base + size - data_ov031_0224f620.region->start;
    data_ov031_0224f620.region->unknown_c_ = 0;
    data_ov031_0224f620.region->type = 3;
    data_ov031_0224f620.owner = owner;
    if (data_ov031_0224f620.state == 0) {
        if (func_ov031_0220c970(data_ov031_0224f620.start, 0x2300) != 0) {
            SetIRQInterruptState(var0);
            return 0;
        }
        data_ov031_0224f620.state = 1;
    }
    if (data_ov031_0224f620.state == 1) {
        if (func_ov031_0220cae0(data_ov031_0224f620.region, func_ov031_0221ecc8) != 3) {
            SetIRQInterruptState(var0);
            return 0;
        }
        data_ov031_0224f620.state = 4;
        SetIRQInterruptState(var0);
        return 1;
    }
    SetIRQInterruptState(var0);
    return 0;
}
