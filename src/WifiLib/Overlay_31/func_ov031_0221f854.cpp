#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Interrupts.h"

#if defined(jpn)
#define func_020ca408 func_020cbed4
#endif

struct Struct_ov031_0224f670_6 {
    char pad[0x28];
    void* unknown_28_;
    int state;
    char unknown_30_[0x1c];
    void* payload;
    char unknown_50_[8];
    int option;
};
extern Struct_ov031_0224f670_6 data_ov031_0224f670;
extern "C" void func_020ca408(void*, void*, int);
extern "C" THUMB int func_ov031_0221f630();
extern "C" int func_ov031_0220d010(void*, void*, int);

// USA: func_ov031_0221f854
extern "C" THUMB int func_ov031_0221f854(void* payload, void* arg1, int option) {
    int var0 = DisableIRQInterrupts();
    data_ov031_0224f670.option = option;
    if (arg1) VectorizedInvertedMemcpy(arg1, data_ov031_0224f670.unknown_28_, 96);
    else VectorizedMemset(data_ov031_0224f670.unknown_28_, 0, 96);
    func_020ca408(payload, data_ov031_0224f670.payload, 192);
    if (func_ov031_0221f630() == 1) {
        data_ov031_0224f670.state = 8;
        SetIRQInterruptState(var0);
        return 1;
    }
    if (data_ov031_0224f670.state == 3 && func_ov031_0220d010(data_ov031_0224f670.payload, data_ov031_0224f670.unknown_28_, data_ov031_0224f670.option) == 3) {
        data_ov031_0224f670.state = 8;
        SetIRQInterruptState(var0);
        return 1;
    }
    SetIRQInterruptState(var0);
    return 0;
}
