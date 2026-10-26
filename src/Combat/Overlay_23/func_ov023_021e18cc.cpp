#include <globaldefs.h>

struct Struct_021e12cc {
    int a;
    int b;
    short c;
    unsigned short d;
    unsigned short e;
    unsigned char bit0 : 1;
    unsigned char unknown_e_1_ : 1;
    unsigned char rest : 6;
    unsigned char f;
};

struct Struct_ov023_021e18cc {
    char pad0[4];
    struct Struct_021e12cc* entries;
    short count;
};

// USA: func_ov023_021e18cc
extern "C" ARM struct Struct_021e12cc* func_ov023_021e18cc(struct Struct_ov023_021e18cc* list, int arg1, int arg2, int arg3, int arg4) {
    unsigned short var0 = 0xffff;
    struct Struct_021e12cc* e;
    struct Struct_021e12cc* best = 0;
    struct Struct_021e12cc* entries = list->entries;
    short count = list->count;
    for (short i = 0; i < count; i++) {
        e = &entries[i];
        if (e->bit0) {
            continue;
        }
        if (var0 < e->d) {
            continue;
        }
        if (arg4 != 0 && !e->unknown_e_1_) {
            continue;
        }
        if (arg1 == 0) {
            int ok = (e->rest >= 8 && e->rest <= 9) ? 1 : 0;
            if (!ok) {
                continue;
            }
        } else {
            if (arg2 >= 0 && arg3 >= 0) {
                if (e->f == arg3) {
                    if (e->rest != arg2) {
                        continue;
                    }
                } else {
                    continue;
                }
            } else if (arg2 >= 0) {
                if (e->rest != arg2) {
                    continue;
                }
            } else if (arg3 >= 0) {
                if (e->f != arg3) {
                    continue;
                }
            }
        }
        var0 = e->d;
        best = e;
    }
    if (best != 0) {
        best->bit0 = 1;
    }
    return best;
}
