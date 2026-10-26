#include <globaldefs.h>

struct Struct_020e52a0_2 {
    char unknown_0_[0xc];
    unsigned short key;
    char unknown_e_[2];
};

struct Struct_020e52a0 {
    unsigned int count : 12;
    unsigned int pad1 : 4;
    struct Struct_020e52a0_2* entries;
};

extern "C" unsigned short func_020e51fc(unsigned char* obj);

// USA: func_020e52a0
extern "C" ARM void* func_020e52a0(void* arr, int key) {
    struct Struct_020e52a0_2* table;
    struct Struct_020e52a0_2* res;
    int count, var3, hi, lo, k;
    if (arr == 0) {
        return 0;
    }
    table = ((struct Struct_020e52a0*)arr)->entries;
    if (table == 0 || (void*)func_020e51fc == 0) {
        res = 0;
        goto found;
    }
    count = ((struct Struct_020e52a0*)arr)->count;
    if (count == 0) {
        res = 0;
        goto found;
    }
    lo = 0;
    hi = count - 1;
    while (lo <= hi) {
        var3 = lo + ((hi - lo + 1) >> 1);
        res = &table[var3];
        k = func_020e51fc((unsigned char*)res);
        if (k == key) {
            goto found;
        }
        if (k > key) {
            hi = var3 - 1;
        } else {
            lo = var3 + 1;
        }
    }
    res = 0;
found:
    return res ? res : 0;
}
