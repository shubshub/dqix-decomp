#include <globaldefs.h>

extern short data_020e8a24[8];

struct Struct_0207c258 {
    char pad0[0xbd0];
    short* unknown_bd0_[8];
    unsigned char* unknown_bf0_[8];
    short counts[8];
    unsigned char index[8];
    unsigned char used[8];
};

// USA: func_0207c258
extern "C" ARM void func_0207c258(struct Struct_0207c258* obj) {
    int i, j;
    char* base = (char*)obj;

    obj->unknown_bd0_[0] = (short*)obj;
    obj->unknown_bd0_[1] = (short*)(base + 0x330);
    obj->unknown_bd0_[2] = (short*)(base + 0x3c0);
    obj->unknown_bd0_[3] = (short*)(base + 0x600);
    obj->unknown_bd0_[4] = (short*)(base + 0x720);
    obj->unknown_bd0_[5] = (short*)(base + 0x8d0);
    obj->unknown_bd0_[6] = (short*)(base + 0x9c0);
    obj->unknown_bd0_[7] = (short*)(base + 0xb10);
    obj->unknown_bf0_[0] = (unsigned char*)(base + 0x220);
    obj->unknown_bf0_[1] = (unsigned char*)(base + 0x390);
    obj->unknown_bf0_[2] = (unsigned char*)(base + 0x540);
    obj->unknown_bf0_[3] = (unsigned char*)(base + 0x6c0);
    obj->unknown_bf0_[4] = (unsigned char*)(base + 0x840);
    obj->unknown_bf0_[5] = (unsigned char*)(base + 0x970);
    obj->unknown_bf0_[6] = (unsigned char*)(base + 0xaa0);
    obj->unknown_bf0_[7] = (unsigned char*)(base + 0xb90);

    for (i = 0; i < 8; i++) {
        obj->counts[i] = data_020e8a24[i];
        obj->index[i] = (unsigned char)i;
    }

    for (j = 0; j < 8; j++) {
        short* var3 = obj->unknown_bd0_[j];
        unsigned char* g2 = obj->unknown_bf0_[j];
        short count = obj->counts[j];
        int k;
        for (k = 0; k < count; k++) {
            var3[k] = -1;
            g2[k] = 0;
        }
        obj->used[j] = 0;
    }
}
