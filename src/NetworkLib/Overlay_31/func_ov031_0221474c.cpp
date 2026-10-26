#include <globaldefs.h>


struct Struct_ov031_0221474c_2 {
    unsigned char unknown_0_[0x40];
    unsigned char listA[0x20];
    unsigned char listB[0x20];
    unsigned char unknown_80_[0x67];
    unsigned char kind;
    unsigned char unknown_e8_[0x18];
};

struct Struct_ov031_0221474c {
    unsigned char f0;
    unsigned char slot;
    unsigned char f2;
    unsigned char count;
    unsigned char items[0x20];
};

struct Struct_ov031_0221474c_3 {
    Struct_ov031_0221474c_2 slots[3];
    Struct_ov031_0221474c entries[1];
    unsigned char unknown_324_[0x9e8];
    unsigned char unknown_d0c_0_ : 4;
};

// USA: func_ov031_0221474c
extern "C" ARM int func_ov031_0221474c(Struct_ov031_0221474c_3* list) {
    int i;
    unsigned char count = 0;
    Struct_ov031_0221474c_2* p = list->slots;
    i = 0;
    Struct_ov031_0221474c* out = list->entries;

    do {
        unsigned int var4 = list->unknown_d0c_0_;
        if (var4 == 0 || var4 == (unsigned int)(i + 1)) {
            if (p->kind != 0xff) {
                unsigned char n = 0;
                bool ok;
                do {
                    unsigned char v = p->listA[n];
                    if (v == 0) {
                        break;
                    }
                    out->items[n] = v;
                    n++;
                } while (n < 0x20);
                if (n != 0) {
                    out->count = n;
                    out->slot = i;
                    ok = true;
                } else {
                    ok = false;
                }
                if (ok) {
                    count++;
                    out++;
                }

                if (p->kind == 1) {
                    unsigned char m = 0;
                    bool var9;
                    do {
                        unsigned char v = p->listB[m];
                        if (v == 0) {
                            break;
                        }
                        out->items[m] = v;
                        m++;
                    } while (m < 0x20);
                    if (m == 0) {
                        var9 = false;
                    } else {
                        out->count = m;
                        out->slot = i + 3;
                        var9 = true;
                    }
                    if (var9) {
                        count++;
                        out++;
                    }
                }
            }
        }
        i++;
        p++;
    } while (i < 3);
    return count;
}
