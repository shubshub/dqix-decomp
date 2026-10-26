#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

#if defined(jpn)
#define func_020ca408 func_020cbed4
#endif

struct Struct_ov031_0224f620_6 {
    char unknown_0_[0xc];
    int mode;
    char unknown_10_[8];
    int status;
    int field_1c;
    void* unknown_20_;
    void* unknown_24_;
};
extern Struct_ov031_0224f620_6 data_ov031_0224f620;
extern "C" void func_020ca408(const void*, void*, unsigned int);
extern "C" int func_ov031_0221ef80();
extern "C" int func_ov031_0220d010(void*, void*, int);

// USA: func_ov031_0221f1e8
extern "C" THUMB int func_ov031_0221f1e8(const void* primary, const void* arg1, int mode) {
    int var0 = DisableIRQInterrupts();
    data_ov031_0224f620.mode = mode;
    if (arg1 != 0)
        VectorizedInvertedMemcpy(arg1, data_ov031_0224f620.unknown_24_, 0x50);
    else
        VectorizedMemset(data_ov031_0224f620.unknown_24_, 0, 0x50);
    func_020ca408(primary, data_ov031_0224f620.unknown_20_, 0xc0);
    if (func_ov031_0221ef80() == 1) {
        data_ov031_0224f620.status = 8;
        SetIRQInterruptState(var0);
        return 1;
    }
    if (data_ov031_0224f620.status == 3 &&
        func_ov031_0220d010(data_ov031_0224f620.unknown_20_, data_ov031_0224f620.unknown_24_, data_ov031_0224f620.mode) == 3) {
        data_ov031_0224f620.status = 8;
        SetIRQInterruptState(var0);
        return 1;
    }
    SetIRQInterruptState(var0);
    return 0;
}
