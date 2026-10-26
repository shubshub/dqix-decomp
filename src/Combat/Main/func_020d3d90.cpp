#include <globaldefs.h>

struct Struct_020d3d90_2 {
#if defined(jpn)
    unsigned char pad[0xb];
#else
    unsigned char pad[0x10];
#endif
    unsigned char kind : 3;
    unsigned char : 5;
#if defined(jpn)
    unsigned char pad2[0x14];
#else
    unsigned char pad2[0x13];
#endif
};

struct Struct_020d3d90 {
    struct Struct_020d3d90_2 entries[5];
    int count;
};

// USA: func_020d3d90
extern "C" ARM struct Struct_020d3d90_2* func_020d3d90(struct Struct_020d3d90* c, int kind) {
    struct Struct_020d3d90_2* e = c->entries;
    int i;
    for (i = 0; i < c->count; i++) {
        if (e->kind == kind) return e;
        e++;
    }
    return NULL;
}
