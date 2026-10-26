#include <globaldefs.h>

struct Struct_020c2d18 {
    volatile unsigned short cnt;
    unsigned char pad0[0xe];
    volatile int unknown_10_;
    volatile int unknown_14_;
    volatile long long unknown_18_;
};

// USA: func_020c2d18
extern "C" ARM int FastIntDivide(int arg0, unsigned int arg1) {
    struct Struct_020c2d18* var0 = (struct Struct_020c2d18*)0x4000280;
    var0->cnt = 0;
    var0->unknown_10_ = arg0;
    var0->unknown_18_ = arg1;
    while (var0->cnt & 0x8000) ;
    return *(volatile int*)0x40002a0;
}
