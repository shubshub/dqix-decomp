#include <globaldefs.h>

struct Struct_0207f0ac;

struct Struct_02081198_2 {
    char pad[0x12];
    unsigned char flags;
};

extern "C" struct Struct_02081198_2* func_0207f0ac(struct Struct_0207f0ac* list, int id);

struct Struct_02081198 {
    char pad[0xc];
};

// USA: func_02081198
extern "C" ARM void func_02081198(struct Struct_02081198* owner, int id, int enable) {
    struct Struct_02081198_2* e = func_0207f0ac((struct Struct_0207f0ac*)((char*)owner + 0xc), id);
    if (e == NULL) {
        return;
    }
    if (enable) {
        e->flags = (e->flags & ~0xf0) | 0x10;
    } else {
        e->flags = e->flags & ~0xf0;
    }
}
