#include <globaldefs.h>

struct Struct_0210cf88_2 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int szByte;
};
extern Struct_0210cf88_2 data_0210cf88;

static inline unsigned int inline_020bb7cc_3(unsigned int size) {
    if (size == 0) {
        return 8;
    } else {
        return (size + 7) & ~7;
    }
}

static inline unsigned int inline_020bb7cc_4(unsigned int addr, unsigned int size) {
    return ((size >> 3) << 16) | (0xffff & (addr >> 3));
}

static inline unsigned int inline_020bb7cc_5(unsigned int addr, int b4Pltt) {
    if (b4Pltt) {
        return 7 & (8 - (addr & 7));
    } else {
        return 0xf & (0x10 - (addr & 0xf));
    }
}

static inline unsigned int inline_020bb7cc_6(unsigned int addr, int b4Pltt) {
    if (b4Pltt) {
        return addr & 7;
    } else {
        return addr & 0xf;
    }
}

static inline unsigned int inline_020bb7cc_7(void) {
    return data_0210cf88.unknown_4_ - data_0210cf88.unknown_0_;
}

static inline int inline_020bb7cc(unsigned int szByte, int b4Pltt, unsigned int* arg2) {
    const unsigned int addr = data_0210cf88.unknown_0_;
    const unsigned int alignment = inline_020bb7cc_5(addr, b4Pltt);
    const unsigned int var2 = szByte + alignment;

    if (inline_020bb7cc_7() >= var2) {
        const unsigned int tail = data_0210cf88.unknown_0_ + var2;

        if (b4Pltt) {
            if (tail > 0x10000) {
                return 0;
            }
        }

        *arg2 = data_0210cf88.unknown_0_ + alignment;
        data_0210cf88.unknown_0_ += var2;
        return 1;
    } else {
        return 0;
    }
}

static inline int inline_020bb7cc_2(unsigned int szByte, int b4Pltt, unsigned int* arg2) {
    if (data_0210cf88.unknown_4_ >= szByte) {
        const unsigned int addr = data_0210cf88.unknown_4_ - szByte;
        const unsigned int alignment = inline_020bb7cc_6(addr, b4Pltt);
        const unsigned int var2 = szByte + alignment;

        if (inline_020bb7cc_7() >= var2) {
            const unsigned int tail = data_0210cf88.unknown_4_;

            if (b4Pltt) {
                if (tail > 0x10000) {
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

    szByte = inline_020bb7cc_3(szByte);
    if (szByte >= 0x7fff8) {
        return 0;
    }

    if (bAllocFromLo == 1) {
        result = inline_020bb7cc(szByte, b4Pltt, &addr);
    } else {
        result = inline_020bb7cc_2(szByte, b4Pltt, &addr);
    }

    if (result) {
        return inline_020bb7cc_4(addr, szByte);
    }
    return 0;
}
