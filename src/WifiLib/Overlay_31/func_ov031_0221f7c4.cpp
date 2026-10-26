#include <globaldefs.h>

struct Struct_ov031_0224f670_4 {
    int pad[11];
    int field2c;
};

extern Struct_ov031_0224f670_4 data_ov031_0224f670;
extern "C" int func_ov031_0220d214(void);
int DisableIRQInterrupts();
int SetIRQInterruptState(int);

// USA: func_ov031_0221f7c4
extern "C" THUMB int func_ov031_0221f7c4(void) {
    int var0 = DisableIRQInterrupts();
    if (data_ov031_0224f670.field2c == 7) {
        if (func_ov031_0220d214() == 3) {
            data_ov031_0224f670.field2c = 4;
            SetIRQInterruptState(var0);
            return 1;
        }
    }
    SetIRQInterruptState(var0);
    return 0;
}
