#include <globaldefs.h>

struct Struct_ov011_02184a40_2 {
    char pad[0xbc];
    unsigned short flagA;
};

struct Struct_ov011_02184a40 {
    char pad0[0x1b4];
    int (**table)(void*);
    unsigned int count;
};

// USA: func_ov011_02184a40
extern "C" ARM void* func_ov011_02184a40(struct Struct_ov011_02184a40* obj, unsigned int idx) {
    if (obj->table == 0) return obj;
    if (idx == 0) return obj;
    if (obj->count <= idx) return obj;
    void* result = (void*)obj->table[idx](obj);
    if (result != 0) {
        struct Struct_ov011_02184a40_2* sub = (struct Struct_ov011_02184a40_2*)((char*)obj + 0x100);
        sub->flagA = (unsigned short)idx;
        result = sub;
    }
    return result;
}
