#include <globaldefs.h>

struct Struct_0210cf88_2 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
};
extern Struct_0210cf88_2 data_0210cf88;

static inline unsigned int inline_020bb7cc_3(unsigned int arg0) {
    if (arg0 == 0) {
        return 8;
    } else {
        return (arg0 + 7) & ~7;
    }
}

static inline unsigned int inline_020bb7cc_4(unsigned int arg0, unsigned int arg1) {
    return ((arg1 >> 3) << 16) | (0xffff & (arg0 >> 3));
}

static inline unsigned int inline_020bb7cc_5(unsigned int arg0, int arg1) {
    if (arg1) {
        return 7 & (8 - (arg0 & 7));
    } else {
        return 0xf & (0x10 - (arg0 & 0xf));
    }
}

static inline unsigned int inline_020bb7cc_6(unsigned int arg0, int arg1) {
    if (arg1) {
        return arg0 & 7;
    } else {
        return arg0 & 0xf;
    }
}

static inline unsigned int inline_020bb7cc_7(void) {
    return data_0210cf88.unknown_4_ - data_0210cf88.unknown_0_;
}

static inline int inline_020bb7cc(unsigned int arg0, int arg1, unsigned int* arg2) {
    const unsigned int var0 = data_0210cf88.unknown_0_;
    const unsigned int var1 = inline_020bb7cc_5(var0, arg1);
    const unsigned int var2 = arg0 + var1;

    if (inline_020bb7cc_7() >= var2) {
        const unsigned int var3 = data_0210cf88.unknown_0_ + var2;

        if (arg1) {
            if (var3 > 0x10000) {
                return 0;
            }
        }

        *arg2 = data_0210cf88.unknown_0_ + var1;
        data_0210cf88.unknown_0_ += var2;
        return 1;
    } else {
        return 0;
    }
}

static inline int inline_020bb7cc_2(unsigned int arg0, int arg1, unsigned int* arg2) {
    if (data_0210cf88.unknown_4_ >= arg0) {
        const unsigned int var0 = data_0210cf88.unknown_4_ - arg0;
        const unsigned int var1 = inline_020bb7cc_6(var0, arg1);
        const unsigned int var2 = arg0 + var1;

        if (inline_020bb7cc_7() >= var2) {
            const unsigned int var3 = data_0210cf88.unknown_4_;

            if (arg1) {
                if (var3 > 0x10000) {
                    return 0;
                }
            }

            data_0210cf88.unknown_4_ -= var2;
            *arg2 = data_0210cf88.unknown_4_;
            return 1;
        }
    }
    return 0;
}

// Main, originally func_020bb7cc (USA 0x020bb7cc, EUR 0x020bb7dc, JPN 0x020bd298)
extern "C" ARM unsigned int NNS_GfdAllocFrmPlttVram(unsigned int szByte, int b4Pltt, unsigned int bAllocFromLo) {
    unsigned int addr = 0;
    int result = 0;

    arg0 = inline_020bb7cc_3(arg0);
    if (arg0 >= 0x7fff8) {
        return 0;
    }

    if (arg2 == 1) {
        var1 = inline_020bb7cc(arg0, arg1, &var0);
    } else {
        var1 = inline_020bb7cc_2(arg0, arg1, &var0);
    }

    if (var1) {
        return inline_020bb7cc_4(var0, arg0);
    }
    return 0;
}
