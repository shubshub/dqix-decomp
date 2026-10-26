#include <globaldefs.h>

struct Entry020984dc {
    unsigned char pad0[0xc];
    unsigned int unknown_c_0_ : 4;
    unsigned int unknown_c_4_ : 4;
    unsigned int unknown_d_0_ : 24;
    unsigned int unknown_10_;
    unsigned char unknown_14_[0xe8 - 0x14];
};

// USA: func_020984dc
extern "C" ARM int func_020984dc(struct Entry020984dc* base, int type, struct Entry020984dc** out) {
    int count;
    int i;
    if (out == NULL) {
        return 0;
    }
    if (type >= 0xb) {
        return 0;
    }
    count = 0;
    for (i = 0; i < 0x1e; i++) {
        struct Entry020984dc* e = &base[i];
        if (e->unknown_10_ >> 2) {
            if (e->unknown_c_4_ == type) {
                out[count] = e;
                count++;
                if (count >= 6) {
                    break;
                }
            }
        }
    }
    return count;
}
