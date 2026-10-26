#include <globaldefs.h>

struct Canvas0204e998 {
    char pad0[0x9c];        // 0x00
    int unknown_9c_;                // 0x9c
    unsigned int a0;        // 0xa0
    char unknown_a4_[4];         // 0xa4
    short a8;               // 0xa8 (width)
    short unknown_aa_;               // 0xaa (height)
    char unknown_ac_[0x19];      // 0xac..0xc4
    unsigned char unknown_c5_;       // 0xc5 (flags)
    char unknown_c6_[0xe];       // 0xc6..0xd3
    unsigned short *unknown_d4_;     // 0xd4 (buffer)
};

// USA: func_0204e998
extern "C" ARM void func_0204e998(struct Canvas0204e998 *s) {
    unsigned short v;
    unsigned short *p;
    short j, i;
    if ((s->unknown_c5_ & 1) && s->unknown_d4_ != NULL) {
        p = s->unknown_d4_;
        v = s->a0 >> 5;
        for (j = 0; j < s->unknown_aa_; j++) {
            for (i = 0; i < s->a8; i++) {
                p[i] = v;
                v++;
            }
            p += s->a8;
        }
        s->unknown_9c_++;
    }
}
