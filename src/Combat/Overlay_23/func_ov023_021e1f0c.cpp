#include <globaldefs.h>

struct Struct_ov023_021e1f0c_2 {
    char pad[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int kind : 5;
};

struct Struct_ov023_021e1f0c {
    char pad0[4];
    struct Struct_ov023_021e1f0c_2* info;
    char pad1[6];
    unsigned char bit0 : 1;
    unsigned char active : 1;
    unsigned char rest : 6;
    char pad2[1];
};

struct Struct_ov023_021e1f0c_3 {
    char pad0[4];
    struct Struct_ov023_021e1f0c* list;
    short num;
};

// USA: func_ov023_021e1f0c
extern "C" ARM int func_ov023_021e1f0c(Struct_ov023_021e1f0c_3* obj, short mode, short p2, short p3) {
    short num = obj->num;
    short result = 0;
    switch (mode) {
    case 0:
        for (short idx = 8; idx <= 9; idx++) {
            result += func_ov023_021e1f0c(obj, -1, idx, -1);
        }
        return result;
    case 1:
    case 2:
    default:
        break;
    }

    struct Struct_ov023_021e1f0c* list = obj->list;
    for (short i = 0; i < num; i++) {
        struct Struct_ov023_021e1f0c* elem = &list[i];
        if (elem->active) {
            struct Struct_ov023_021e1f0c_2* info = elem->info;
            if (info != 0) {
                if (p2 >= 0 && p3 >= 0) {
                    if (p2 == (short)info->unknown_8_0_ && p3 == (short)info->kind) result++;
                } else if (p2 >= 0) {
                    if (p2 == (short)info->unknown_8_0_) result++;
                } else if (p3 >= 0) {
                    if (p3 == (short)info->kind) result++;
                }
            }
        }
    }
    return result;
}
