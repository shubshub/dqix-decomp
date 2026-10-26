#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_ov031_0222f430 {
    unsigned char field_0[0x38];
    void* task;
    unsigned char unknown_3c_[5];
    unsigned char unknown_41_;
    unsigned char unknown_42_[3];
    unsigned char active;
    unsigned char unknown_46_;
};
struct Struct_ov031_02290ca0_7 {
    unsigned char field_0[4];
    unsigned short position;
    unsigned short unknown_6_;
    Struct_ov031_0222f430* inner;
};
extern Struct_ov031_02290ca0_7 data_ov031_02290ca0;
extern "C" unsigned char func_ov031_022351e4();
extern "C" unsigned char func_ov031_022351d0();
extern "C" void func_ov031_02222e98();
extern "C" void func_ov031_02222e80();
extern "C" void func_ov031_022238cc();
extern "C" void func_ov031_0222f9ec();
extern "C" void func_ov031_022308d4();
extern "C" int func_ov031_02236878(int);
extern "C" void func_ov031_0223060c(int);
extern "C" void func_ov031_022306d4();
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);

// USA: func_ov031_0222f430
extern "C" ARM void func_ov031_0222f430() {
    if (data_ov031_02290ca0.inner->task) return;
    if (data_ov031_02290ca0.inner->unknown_41_) data_ov031_02290ca0.inner->unknown_41_--;
    switch (func_ov031_022351e4()) {
    case 1:
        data_ov031_02290ca0.inner->active = 1;
        return;
    case 2:
        if (data_ov031_02290ca0.inner->unknown_41_) return;
        func_ov031_022238cc();
        data_ov031_02290ca0.position = (func_ov031_022351d0() * 145) / 55;
        func_ov031_0222f9ec();
        data_ov031_02290ca0.inner->unknown_41_ = 4;
        return;
    case 3: {
        data_ov031_02290ca0.inner->active = 0;
        data_ov031_02290ca0.position = (func_ov031_022351d0() * 145) / 55;
        func_ov031_02236878(0x13);
        func_ov031_0222f9ec();
        int var0 = FastIntModulus(data_ov031_02290ca0.position, 0x1d);
        if (var0 == 0) {
            func_ov031_022308d4();
            return;
        }
        if (var0 < 0x10) {
            data_ov031_02290ca0.inner->task = func_ov031_0223e218(0, (void*)func_ov031_0223060c, 0, 0x78);
            return;
        } else {
            data_ov031_02290ca0.inner->task = func_ov031_0223e218(0, (void*)func_ov031_022306d4, 0, 0x78);
        }
        return;
    }
    case 4:
        if (data_ov031_02290ca0.position == 0) {
            if (data_ov031_02290ca0.inner->unknown_46_) return;
            func_ov031_02236878(9);
            data_ov031_02290ca0.inner->unknown_46_ = 1;
        } else {
            func_ov031_02236878(0x13);
            data_ov031_02290ca0.inner->task = func_ov031_0223e218(0, (void*)func_ov031_0223060c, 0, 0x78);
        }
        return;
    case 6:
        if (data_ov031_02290ca0.position == 145) {
            if (data_ov031_02290ca0.inner->unknown_46_) return;
            func_ov031_02236878(9);
            data_ov031_02290ca0.inner->unknown_46_ = 1;
        } else {
            func_ov031_02236878(0x13);
            data_ov031_02290ca0.inner->task = func_ov031_0223e218(0, (void*)func_ov031_022306d4, 0, 0x78);
        }
        return;
    case 5:
    case 7:
        data_ov031_02290ca0.inner->unknown_46_ = 0;
        return;
    }
}
