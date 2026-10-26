#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_021015a0_6 {
    char pad0[0x10];
    int unknown_10_;
    char unknown_14_[0x2c - 0x14];
    int unknown_2c_;
    int unknown_30_;
    int unknown_34_;
    int unknown_38_;
};
extern struct Struct_021015a0_6 data_021015a0;
extern char data_021016e0;

extern "C" int func_0202d224(void);
extern "C" int func_0202d180(void);

// USA: func_0202dc40
extern "C" ARM int func_0202dc40(int mode, void* src) {
    data_021015a0.unknown_2c_ = 0x440;
    data_021015a0.unknown_38_ = 0x80;
    data_021015a0.unknown_34_ = mode;
    data_021015a0.unknown_10_ = 3;
    if (mode == 1 || mode == 3 || mode == 5) {
        VectorizedInvertedMemcpy(src, &data_021016e0, 0xc0);
        if (data_021015a0.unknown_30_ != 0) {
            return func_0202d180();
        }
        return func_0202d224();
    }
    return 0;
}
