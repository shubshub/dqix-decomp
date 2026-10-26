#include <globaldefs.h>

struct Struct_ov023_021e1de8_2 {
    char pad0[8];
    unsigned int category : 4;
    unsigned int unknown_8_4_ : 5;
};

struct Struct_ov023_021e1de8 {
    int a;
    struct Struct_ov023_021e1de8_2* b;
    short c;
    unsigned short d;
    unsigned short e;
    unsigned char bit0 : 1;
    unsigned char unknown_e_1_ : 1;
    unsigned char rest : 6;
    unsigned char f;
};

struct Struct_ov023_021e1de8_3 {
    char pad0[4];
    struct Struct_ov023_021e1de8* entries;
    short count;
};

// USA: func_ov023_021e1de8
extern "C" ARM short func_ov023_021e1de8(struct Struct_ov023_021e1de8_3* list, int mode, int arg2, int arg3) {
    short count = list->count;
    short total = 0;
    switch (mode) {
    case 0: {
        for (short var2 = 0; var2 <= 7; var2++) {
            total = total + func_ov023_021e1de8(list, -1, var2, -1);
        }
        return total;
    }
    case 1:
    case 2:
    default: {
        struct Struct_ov023_021e1de8* entries = list->entries;
        for (short i = 0; i < count; i++) {
            struct Struct_ov023_021e1de8* cur = &entries[i];
            if (cur->unknown_e_1_ && cur->b != 0) {
                if (arg2 >= 0 && arg3 >= 0) {
                    if (cur->b->category == arg2 && cur->b->unknown_8_4_ == arg3) {
                        total = total + 1;
                    }
                } else if (arg2 >= 0) {
                    if (cur->b->category == arg2) {
                        total = total + 1;
                    }
                } else if (arg3 >= 0) {
                    if (cur->b->unknown_8_4_ == arg3) {
                        total = total + 1;
                    }
                }
            }
        }
        return total;
    }
    }
}
