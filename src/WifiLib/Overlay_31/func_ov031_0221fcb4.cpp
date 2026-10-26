#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0224f670_15 { char field_0x0[0x20]; int active; int unknown_24_; };
extern Struct_ov031_0224f670_15 data_ov031_0224f670;
extern "C" int func_ov031_0221f7c4();
extern "C" void* func_ov031_0221fa20();
extern "C" int func_ov031_022077c0();

// USA: func_ov031_0221fcb4
extern "C" THUMB void func_ov031_0221fcb4() {
    bool var0 = true;
    if (data_ov031_0224f670.active != 0) {
        if (func_ov031_0221f7c4() != 0) {
            do {
                SleepCurrentContext(10);
                int event = (int)func_ov031_0221fa20();
                if (event != 0) do {
                    switch (event) {
                    case 4: case 5: break;
                    case 14: var0 = false; break;
                    default: var0 = false; break;
                    }
                    event = (int)func_ov031_0221fa20();
                } while (event != 0);
            } while (var0 != 0);
        }
        data_ov031_0224f670.active = 0;
    }
    if (data_ov031_0224f670.unknown_24_ != 0) {
        data_ov031_0224f670.unknown_24_ = 0;
        func_ov031_022077c0();
    }
}
