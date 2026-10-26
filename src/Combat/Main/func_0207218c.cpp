#include <globaldefs.h>

struct Struct_0207218c {
    char pad0[0x10];
    unsigned int pad10 : 21;
    unsigned int active : 1;
    unsigned int unknown_12_6_ : 10;
    short unknown_14_;
    short unknown_16_;
    short field18;
};

struct Struct_0207214c_2 {
    char pad0[4];
    struct Struct_0207218c* array;
    char pad8[2];
    unsigned short count;
};

// USA: func_0207218c
extern "C" ARM struct Struct_0207218c* func_0207218c(struct Struct_0207214c_2* c, int limit) {
    unsigned short count = c->count;
    struct Struct_0207218c* arr = c->array;
    struct Struct_0207218c* best = NULL;
    int var3 = 0x7fff;
    unsigned short i = 0;
    for (; i < count; i++) {
        struct Struct_0207218c* e = (struct Struct_0207218c*)((char*)arr + (i << 5));
        if (e->active) {
            if (e->field18 > limit && var3 > e->field18) {
                if (e->unknown_16_ <= 0) {
                    var3 = e->field18;
                    best = e;
                }
            }
        }
    }
    return best;
}
