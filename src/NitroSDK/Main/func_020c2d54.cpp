#include <globaldefs.h>

struct Struct_020c2d54 {
    volatile unsigned short cnt;
    unsigned char pad[0xe];
    volatile unsigned int unknown_10_;
    unsigned int pad2;
    volatile long long unknown_18_;
};

// USA: func_020c2d54
extern "C" ARM int FastIntModulus(int arg0, int arg1) {
    struct Struct_020c2d54* var0 = (struct Struct_020c2d54*)0x4000280;
    var0->cnt = 0;
    var0->unknown_10_ = arg0;
    var0->unknown_18_ = (unsigned int)arg1;
    while (var0->cnt & 0x8000) {}
    return *(volatile int*)0x40002a8;
}
