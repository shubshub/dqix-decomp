#include <globaldefs.h>

struct Struct_020482bc_2 {
    unsigned short pad0;
    unsigned short pad2;
    unsigned short pad4;
    unsigned short value;
};

struct Struct_020482bc {
    char pad[0x32];
    unsigned short cap;
};

struct Struct_02010604_3 {
    char pad[0x130];
    struct Struct_020482bc_2* current;
    struct Struct_020482bc* base;
};

// USA: func_020482bc
extern "C" ARM int func_020482bc(struct Struct_02010604_3* c) {
    struct Struct_020482bc_2* current = c->current;
    struct Struct_020482bc* base = c->base;
    unsigned short v = current->value;
    unsigned short cap = base->cap;
    if (cap - v <= 0) {
        return 0;
    }
    current->value = cap;
    return cap - v;
}
