#include <globaldefs.h>

struct Struct_020a171c_2 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 9;
    unsigned int unknown_2_2_ : 9;
    unsigned int flags : 5;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
};

struct Struct_020a171c {
    Struct_020a171c_2* entries;
    unsigned short unk4;
    unsigned short count;
    unsigned int unknown_8_;
    unsigned char* unknown_c_;
};

// USA: func_020a171c
extern "C" ARM Struct_020a171c_2* func_020a171c(Struct_020a171c* list, int mode, int arg2) {
    unsigned short best = 0xffff;
    unsigned short var1 = 0;
    int i;

    for (i = 0; i < list->count; i++) {
        Struct_020a171c_2* e;
        unsigned short cur;
        if (list->unknown_c_[i / 8] & (unsigned char)(1 << (i % 8))) {
            continue;
        }
        e = &list->entries[i];
        cur = 0xffff;
        if (mode == 1) {
            cur = e->unknown_0_0_;
        } else if (mode == 2) {
            if (arg2 == 0) {
                cur = e->unknown_1_1_;
            } else {
                cur = e->unknown_2_2_;
            }
        }
        if (best > cur && cur != 0) {
            var1 = i;
            best = cur;
        }
    }

    if (best == 0xffff) {
        return 0;
    }
    list->unknown_c_[var1 / 8] |= (unsigned char)(1 << (var1 % 8)) & 0xff;
    return &list->entries[var1];
}
