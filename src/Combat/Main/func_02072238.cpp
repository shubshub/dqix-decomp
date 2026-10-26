#include <globaldefs.h>

struct Struct_02072238 {
    char pad0[0x10];
    unsigned int pad10 : 21;
    unsigned int active : 1;
    unsigned int unknown_12_6_ : 10;
    short unknown_14_;
    short unknown_16_;
    short pad18;
    short unknown_1a_;
};

struct Struct_020721f8_2 {
    char pad0[4];
    struct Struct_02072238* array;
    char pad8[2];
    unsigned short count;
};

// USA: func_02072238
extern "C" ARM struct Struct_02072238* func_02072238(struct Struct_020721f8_2* c, int limit) {
    unsigned short count = c->count;
    struct Struct_02072238* arr = c->array;
    struct Struct_02072238* best = NULL;
    int var3 = 0x7fff;
    unsigned short i = 0;
    for (; i < count; i++) {
        struct Struct_02072238* e = (struct Struct_02072238*)((char*)arr + (i << 5));
        if (e->active) {
            if (e->unknown_1a_ > limit && var3 > e->unknown_1a_) {
                if (e->unknown_16_ <= 0) {
                    var3 = e->unknown_1a_;
                    best = e;
                }
            }
        }
    }
    return best;
}
