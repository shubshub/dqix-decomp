#include <globaldefs.h>
#include <NitroSDK/Interrupts.h>

struct SessionState {
    unsigned char padding[0x18];
    int state;
};

extern SessionState data_ov031_0224f620;
extern "C" int func_ov031_0220cce4();
extern "C" int func_ov031_0221ef80();

// USA: func_ov031_0221f190
extern "C" THUMB int func_ov031_0221f190() {
    int var0 = DisableIRQInterrupts();
    if (data_ov031_0224f620.state == 3) {
        if (func_ov031_0220cce4() != 3) {
            SetIRQInterruptState(var0);
            return 0;
        }
        data_ov031_0224f620.state = 2;
        SetIRQInterruptState(var0);
        return 1;
    }
    if (func_ov031_0221ef80() == 1) {
        data_ov031_0224f620.state = 2;
        SetIRQInterruptState(var0);
        return 1;
    }
    SetIRQInterruptState(var0);
    return 0;
}
