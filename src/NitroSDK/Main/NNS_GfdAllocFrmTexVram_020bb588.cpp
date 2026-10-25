#include <globaldefs.h>

struct Struct_020f1f2c {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned int unknown_14_;
};
#if defined(jpn)
#define data_020f1f44 data_020f20b0
#define data_020f1ef8 data_020f2064
#define data_020f1f00 data_020f206c
#endif
extern Struct_020f1f2c data_020f1f44;
extern Struct_020f1f2c data_020f1f2c;
extern Struct_020f1f2c* data_020f1ef8[2];
extern Struct_020f1f2c* data_020f1f00[5];
static inline unsigned int inline_020bb588(const Struct_020f1f2c* arg0) {
    return arg0->unknown_4_ - arg0->unknown_0_;
}

// Main, originally func_020bb588 (USA 0x020bb588, EUR 0x020bb598, JPN 0x020bd054)
extern "C" ARM unsigned int NNS_GfdAllocFrmTexVram(unsigned int size, unsigned int fromFront) {
    unsigned int address;
    unsigned int aligned;
    int allocated;
    if (size == 0) aligned = 16;
    else aligned = (size + 15) & ~15;
    if (aligned >= 0x7fff0) return 0;
    if (fromFront != 0) {
        PairSlot020bb588* pair;
        PairSlot020bb588* slot;
        int i;
        i = 0;
        do {
            var4 = data_020f1ef8[var5];
            if (!var4->unknown_8_ || inline_020bb588(var4) < var1) goto nextFront;
            switch (var4->unknown_10_) {
            case 0: var3 = &data_020f1f2c; break;
            case 3: var3 = &data_020f1f44; break;
            default: var3 = 0; break;
            }
            if (!var3->unknown_8_ || inline_020bb588(var3) < (var1 >> 1)) goto nextFront;
            unsigned int var6 = var4->unknown_0_;
            var4->unknown_0_ += var1;
            var3->unknown_0_ += var1 >> 1;
            var0 = var6 + var4->unknown_14_;
            var2 = 1;
            goto complete;
nextFront:
            var5++;
        } while (var5 < 2);
        var2 = 0;
    } else {
        int var7 = 0;
        do {
            Struct_020f1f2c* var8 = data_020f1f00[var7];
            if (!var8->unknown_8_ || inline_020bb588(var8) < var1) goto nextBack;
            var8->unknown_4_ -= var1;
            var0 = var8->unknown_4_ + var8->unknown_14_;
            var2 = 1;
            goto complete;
nextBack:
            var7++;
        } while (var7 < 5);
        var2 = 0;
    }
complete:
    if (!var2) return 0;
    unsigned short var9 = var0 >> 3;
    return ((var1 >> 4) << 16) | var9 | (arg1 << 31);
}
