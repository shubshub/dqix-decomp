#include <globaldefs.h>

struct Struct_0207c378;
extern "C" int func_0207caa4(struct Struct_0207c378* base, int value, int key);

struct Struct_0207c484 {
    char pad0[0xbd0];
    short* unknown_bd0_[8];
    signed char* unknown_bf0_[8];
    short counts[8];
    unsigned char keys[8];
};

// USA: func_0207c484
extern "C" ARM int func_0207c484(struct Struct_0207c484* obj, int value, int amount, int key) {
    int idx;
    int i;
    int result;
    signed char* var3;

    if (amount <= 0) {
        return 0;
    }

    result = func_0207caa4((struct Struct_0207c378*)obj, value, key);
    if (result < 0) {
        return 0;
    }

    for (i = 0; i < 8; i++) {
        if (key == obj->keys[i]) {
            idx = i;
            break;
        }
    }

    var3 = obj->unknown_bf0_[idx];
    var3[result] = var3[result] - amount;
    if (var3[result] <= 0) {
        obj->unknown_bd0_[idx][result] = -1;
        var3[result] = 0;
    }

    return 1;
}
