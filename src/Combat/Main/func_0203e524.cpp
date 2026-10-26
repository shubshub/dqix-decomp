#include <globaldefs.h>

#include "Combat/EntryGetterTypes.h"

struct Struct_0203dce4_2 {
    char pad[0xc];
    struct Struct_0203dce4* entries[0x20];
};

extern "C" struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2* list, int id);

extern "C" void* func_02040538(struct Struct_0203e0a0* p);

struct Struct_02028460_3 { int x; int y; int z; };

extern "C" extern int Vector3fix_Distance(struct Struct_02028460_3* a, struct Struct_02028460_3* b);

struct Struct_0203de84 {
    unsigned int v[3];
};

struct Struct_020406f8 {
    char pad4[4];
    struct Struct_0203de84 vec;
};

struct Struct_020406f8_2 {
    char unknown_0_[0x44];
    struct Struct_0203de84 vec;
};

struct Node020406f8 {
    char pad[0x14];
    struct Struct_020406f8* f14;
    struct Struct_020406f8_2* f18;
    struct Struct_020406f8_2* f1c;
};

extern "C" void func_020406f8(struct Struct_0203de84* dst, struct Node020406f8* n);

struct Struct_0203e524 {
    short x;
    short y;
    short z;
};

// USA: func_0203e524
extern "C" ARM int func_0203e524(struct Struct_0203dce4_2* list, struct Struct_02028460_3* pos, struct Struct_0203e524* out) {
    int var0 = 0x400000;
    int result = -1;
    int id;
    for (id = 0; id < 0x20; id++) {
        struct Struct_0203dce4* entry = func_0203dce4(list, id);
        if (entry == 0) continue;
        if (entry->flags & 0x8000) continue;
        void* field = func_02040538((struct Struct_0203e0a0*)entry);
        if (field == 0) continue;
        int dist = Vector3fix_Distance(pos, (struct Struct_02028460_3*)((char*)field + 0x10));
        if (dist >= var0) continue;
        var0 = dist;
        {
            struct Struct_0203de84 tmp;
            result = *(unsigned char*)field;
            func_020406f8(&tmp, (struct Node020406f8*)entry);
            out->x = (short)((int)tmp.v[0] >> 4);
            out->y = (short)((int)tmp.v[1] >> 4);
            out->z = (short)((int)tmp.v[2] >> 4);
        }
    }
    return result;
}
