#include <globaldefs.h>

struct Struct_02098a84;
extern "C" int func_02098e3c(struct Struct_02098a84* s, int val);

struct Struct_02098630 {
    unsigned char pad0[0xc];
    unsigned int unknown_c_0_ : 4;
    unsigned int category : 4;
    unsigned int unknown_d_0_ : 24;
    unsigned int used : 2;
    unsigned int unknown_10_2_ : 30;
    unsigned char pad1[0xe8 - 0x14];
};

extern "C" struct Struct_02098630* func_02098834(struct Struct_02098630* dst, struct Struct_02098630* src);
extern "C" void func_02098364(void* entry);

struct Struct_02098a84 {
    Struct_02098630 entries[30];
    unsigned char unknown_1b30_[8];
    int unknown_1b38_;
    unsigned char unknown_1b3c_[0x1b68 - 0x1b3c];
    unsigned int values[3];
    int unknown_1b74_;
};

// USA: func_02098a84
extern "C" ARM int func_02098a84(Struct_02098a84* list) {
    Struct_02098630* arr = list->entries;
    if (list->unknown_1b38_ == 0) {
        return 0;
    }

    int var1 = 0;
    int last = var1;
    int var3 = var1 - 1;
    int var4 = 1;
    for (int idx = var1; idx < 0x1e; idx++) {
        struct Struct_02098630* e = &arr[idx];
        if (e->used == 0) {
            var3 = idx;
            break;
        }
        if (e->category == 9 || e->category == 10) {
            continue;
        }
        if (func_02098e3c(list, e->unknown_10_2_) == 0) {
            var4 = 0;
        }
    }

    if (var3 == 0) {
        return 0;
    }

    if (var3 != -1) {
        if (var4) {
            if (var3 < 6) {
                return var3;
            }
            func_02098834(&arr[var3], &arr[list->unknown_1b74_]);
            func_02098364(&arr[list->unknown_1b74_]);
            return list->unknown_1b74_;
        }
        var1 = var3;
    } else {
        for (int idx = 0x1d; idx >= 0; idx--) {
            struct Struct_02098630* e = &arr[idx];
            if (e->category == 9 || e->category == 10) {
                continue;
            }
            if (func_02098e3c(list, e->unknown_10_2_) == 0) {
                var1 = idx;
                break;
            }
        }
    }

    for (int idx = var1 - 1; idx >= 0; idx--) {
        struct Struct_02098630* e = &arr[idx];
        if (e->category == 9 || e->category == 10) {
            continue;
        }
        if (func_02098e3c(list, e->unknown_10_2_) == 0) {
            last = idx;
            func_02098834(&arr[var1], e);
            var1 = idx;
        }
    }
    struct Struct_02098630* var11 = &arr[last];
    func_02098364(var11);

    struct Struct_02098630* e;
    for (var1 = 0; var1 < 6; var1++) {
        if (arr[var1].category == 9 || arr[var1].category == 10) {
            continue;
        }
        e = &arr[var1];
        if (func_02098e3c(list, e->unknown_10_2_) == 0) {
            e->category = 2;
        }
    }
    for (var1 = 6; var1 < 12; var1++) {
        if (arr[var1].category == 9 || arr[var1].category == 10) {
            continue;
        }
        e = &arr[var1];
        if (func_02098e3c(list, e->unknown_10_2_) == 0) {
            e->category = 3;
        }
    }
    for (var1 = 12; var1 < 18; var1++) {
        if (arr[var1].category == 9 || arr[var1].category == 10) {
            continue;
        }
        e = &arr[var1];
        if (func_02098e3c(list, e->unknown_10_2_) == 0) {
            e->category = 4;
        }
    }
    for (var1 = 18; var1 < 24; var1++) {
        if (arr[var1].category == 9 || arr[var1].category == 10) {
            continue;
        }
        e = &arr[var1];
        if (func_02098e3c(list, e->unknown_10_2_) == 0) {
            e->category = 5;
        }
    }
    for (var1 = 24; var1 < 0x1e; var1++) {
        if (arr[var1].category == 9 || arr[var1].category == 10) {
            continue;
        }
        e = &arr[var1];
        if (func_02098e3c(list, e->unknown_10_2_) == 0) {
            e->category = 6;
        }
    }

    if (last < 6) {
        return last;
    }
    func_02098834(var11, &arr[list->unknown_1b74_]);
    func_02098364(&arr[list->unknown_1b74_]);
    return list->unknown_1b74_;
}
