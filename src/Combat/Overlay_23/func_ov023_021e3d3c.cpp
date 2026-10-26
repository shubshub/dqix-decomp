#include <globaldefs.h>

struct Struct_ov023_021e3d3c_2 {
    short key;
    char pad[0x16 - 0x2];
    unsigned char flags;
    char pad2[0x18 - 0x17];
};

struct Struct_ov023_021e3d3c {
    char pad0[0x8];
    struct Struct_ov023_021e3d3c_2* arr;
    char pad1[0x14 - 0xc];
    unsigned short count;
};

// USA: func_ov023_021e3d3c
extern "C" ARM void func_ov023_021e3d3c(struct Struct_ov023_021e3d3c* obj, short key, int mask) {
    struct Struct_ov023_021e3d3c_2* found;
    unsigned short i;
    unsigned short count;
    struct Struct_ov023_021e3d3c_2* arr = obj->arr;
    if (arr == 0) {
        found = 0;
        goto DONE;
    }
    count = obj->count;
    if (count == 0) {
        found = 0;
        goto DONE;
    }
    i = 0;
    goto CHECK;
LOOP:
    {
        short var4 = arr[i].key;
        if (var4 == key) {
            found = &arr[i];
            goto DONE;
        }
    }
    i = i + 1;
CHECK:
    if (i < count) goto LOOP;
    found = 0;
DONE:
    if (found != 0) {
        found->flags = found->flags & ~mask;
    }
}
