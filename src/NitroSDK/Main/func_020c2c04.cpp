#include <globaldefs.h>

extern "C" int fix32_GetSqrtResult(void);

struct Struct_020c2c04 {
    volatile unsigned short cnt;
    unsigned char pad0[6];
    volatile int unknown_8_;
    volatile int unknown_c_;
};

// USA: func_020c2c04
extern "C" ARM int fix32_Sqrt(int value) {
    struct Struct_020c2c04* var0;
    if (value <= 0) return 0;
    var0 = (struct Struct_020c2c04*)0x40002b0;
    var0->cnt = 1;
    var0->unknown_8_ = 0;
    var0->unknown_c_ = value;
    return fix32_GetSqrtResult();
}
