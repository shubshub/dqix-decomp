#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_ov031_0224f620_4 {
    unsigned char padding[0x18];
    int state;
};
extern Struct_ov031_0224f620_4 data_ov031_0224f620;
extern "C" int func_ov031_0220cdd4(int, int, int);

// USA: func_ov031_0221f11c
extern "C" THUMB int func_ov031_0221f11c() {
    int var0 = DisableIRQInterrupts();
    if (data_ov031_0224f620.state == 5) {
        if (func_ov031_0220cdd4(0, 0, 0) == 3) {
            data_ov031_0224f620.state = 4;
            SetIRQInterruptState(var0);
            return 1;
        }
    }
    SetIRQInterruptState(var0);
    return 0;
}
