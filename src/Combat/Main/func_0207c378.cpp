#include <globaldefs.h>

struct Struct_0207c378;
extern "C" int func_0207caa4(struct Struct_0207c378* base, int value, int key);

struct Struct_020732cc {
    char pad0[0xbd0];
    short* unknown_bd0_[8];
    signed char* unknown_bf0_[8];
    short counts[8];
    unsigned char keys[8];
};

// USA: func_0207c378
extern "C" ARM int func_0207c378(struct Struct_020732cc* obj, int value, int amount, int key) {
    int found;
    signed char* var1;
    int idx;
    int i;
    int result;
    short* values;
    short count;
    short j;

    if (amount <= 0) {
        return 0;
    }

    result = func_0207caa4((struct Struct_0207c378*)obj, value, key);
    if (result == -2) {
        return 0;
    }

    idx = -1;
    for (i = 0; i < 8; i++) {
        if (key == obj->keys[i]) {
            idx = i;
            break;
        }
    }
    if (idx < 0) {
        return 0;
    }

    var1 = obj->unknown_bf0_[idx];
    found = 0;
    if (result >= 0) {
        var1[result] += amount;
        found = 1;
        if (var1[result] > 0x63) {
            var1[result] = 0x63;
        }
    } else {
        values = obj->unknown_bd0_[idx];
        count = obj->counts[idx];
        for (j = 0; j < count; j++) {
            if (values[j] < 0) {
                values[j] = value;
                var1[j] = amount;
                found = 1;
                if (var1[j] > 0x63) {
                    var1[j] = 0x63;
                }
                break;
            }
        }
    }
    return found;
}
