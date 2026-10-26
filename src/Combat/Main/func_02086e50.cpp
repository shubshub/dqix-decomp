#include <globaldefs.h>

struct Struct_02086e50_2 {
    signed char id : 6;
    char rest[0x23c - 1];
};

struct FindEntryContainer02086e50 {
    char pad0[0xf80];
    struct Struct_02086e50_2 elems[13];
    unsigned char count;
};

// USA: func_02086e50
extern "C" ARM struct Struct_02086e50_2* func_02086e50(struct FindEntryContainer02086e50* c, int id) {
    unsigned char i;
    for (i = 0; i < c->count; i++) {
        struct Struct_02086e50_2* e = &c->elems[i];
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}
