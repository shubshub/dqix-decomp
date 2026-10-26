#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0209f030_3 {
    unsigned char unk0[0x16];
    unsigned short key;
    unsigned char unknown_18_[0x28];
};

struct Struct_0209f030 {
    int count;
    Struct_0209f030_3 entries[16];
};

struct Struct_0209f030_2 {
    unsigned char unk0[4];
    unsigned char* data;
    unsigned char unknown_8_[0x90];
    Struct_0209f030 kept;
    Struct_0209f030 scratch;
};

// USA: func_0209f030
extern "C" ARM void func_0209f030(struct Struct_0209f030_2* owner, int arg1, int key, int arg3)
{
    if (arg1 == 0) {
        int total;
        owner->kept.count = 0;
        total = *(owner->data + 0x8e07);
        for (int i = 0; i < total; i++) {
            Struct_0209f030_3* e = (Struct_0209f030_3*)(owner->data + 0x5c60) + i;
            unsigned short v;
            int n;
            if (e == NULL) {
                continue;
            }
            v = e->key;
            if (arg3 != 0) {
                if (v < key) {
                    continue;
                }
            } else {
                if (v >= key) {
                    continue;
                }
            }
            n = owner->kept.count;
            owner->kept.count = owner->kept.count + 1;
            memcpy(&owner->kept.entries[n], e, 0x40);
        }
        return;
    }

    owner->scratch.count = 0;
    memset(owner->scratch.entries, 0, 0x400);
    for (int i = 0; i < owner->kept.count; i++) {
        Struct_0209f030_3* e = &owner->kept.entries[i];
        unsigned short v = e->key;
        int n;
        if (arg3 != 0) {
            if (v < key) {
                continue;
            }
        } else {
            if (v >= key) {
                continue;
            }
        }
        n = owner->scratch.count;
        owner->scratch.count = owner->scratch.count + 1;
        memcpy(&owner->scratch.entries[n], e, 0x40);
    }
    owner->kept.count = owner->scratch.count;
    memcpy(owner->kept.entries, owner->scratch.entries, 0x400);
}
