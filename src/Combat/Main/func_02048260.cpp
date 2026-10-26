#include <globaldefs.h>

struct Struct_02048260_3 {
    unsigned short pad0;
    unsigned short pad2;
    unsigned short value;
};

struct Struct_02048260 {
    char pad[0x30];
    unsigned short cap;
};

struct Struct_02048260_2 {
    char pad[0x130];
    struct Struct_02048260_3* current;
    struct Struct_02048260* base;
};

// USA: func_02048260
extern "C" ARM int func_02048260(struct Struct_02048260_2* c) {
    struct Struct_02048260_3* current = c->current;
    struct Struct_02048260* base = c->base;
    unsigned short v = current->value;
    unsigned short cap = base->cap;
    if (cap - v <= 0) {
        return 0;
    }
    current->value = cap;
    return cap - v;
}
