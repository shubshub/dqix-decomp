#include <globaldefs.h>

struct Struct_020c2cf0 {
    volatile unsigned short cnt;
    unsigned char unknown_2_[0xe];
    volatile unsigned int unknown_10_;
    volatile unsigned int unknown_14_;
    volatile unsigned int unknown_18_;
    volatile unsigned int unknown_1c_;
};

// USA: func_020c2cf0
extern "C" ARM void fix32_QueueComputeQuotient(unsigned int arg0, unsigned int arg1) {
    struct Struct_020c2cf0* var0 = (struct Struct_020c2cf0*)0x4000280;
    var0->cnt = 1;
    var0->unknown_10_ = 0;
    var0->unknown_14_ = arg0;
    var0->unknown_18_ = arg1;
    var0->unknown_1c_ = 0;
}
