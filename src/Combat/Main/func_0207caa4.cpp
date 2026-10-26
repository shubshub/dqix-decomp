#include <globaldefs.h>

struct Struct_0207c378 {
    char pad0[0xbd0];
    short* unknown_bd0_[8]; // 0xbd0
    char pad1[0x20];       // 0xbf0
    short counts[8];       // 0xc10
    unsigned char keys[8]; // 0xc20
};

// USA: func_0207caa4
extern "C" ARM int func_0207caa4(struct Struct_0207c378* base, int value, int key) {
    int slot;
    int i;
    short* values;
    short count;
    short j;
    if (value < 0) {
        return -2;
    }
    slot = -1;
    for (i = 0; i < 8; i++) {
        if (key == base->keys[i]) {
            slot = i;
            break;
        }
    }
    if (slot == -1) {
        return -2;
    }
    values = base->unknown_bd0_[slot];
    count = base->counts[slot];
    for (j = 0; j < count; j++) {
        if (value == values[j]) {
            return j;
        }
    }
    return -1;
}
