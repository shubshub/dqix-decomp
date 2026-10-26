#include <globaldefs.h>

struct Struct_ov004_021589e8 {
    unsigned int low : 12;
    unsigned int f12  : 4;
    unsigned int unknown_2_0_  : 5;
    unsigned int unknown_2_5_  : 5;
    unsigned int top  : 6;
};

// USA: func_ov017_021b2090
// JPN: func_ov017_021b27b0
extern "C" ARM int func_ov017_021b2090(Struct_ov004_021589e8 a, Struct_ov004_021589e8 b) {
    if (a.low < b.low) return 1;
#if !defined(jpn)
    if (a.low > b.low) return 0;
#endif
    unsigned int var0 = 0;
    var0 = a.f12 * 1000000 + var0;
    var0 = a.unknown_2_0_ * 10000 + var0;
    var0 = a.unknown_2_5_ * 100 + var0;
    var0 = a.top + var0;
    unsigned int var1 = 0;
    var1 = b.f12 * 1000000 + var1;
    var1 = b.unknown_2_0_ * 10000 + var1;
    var1 = b.unknown_2_5_ * 100 + var1;
    var1 = b.top + var1;
    if ((int)var0 < (int)var1) return 1;
    return 0;
}
