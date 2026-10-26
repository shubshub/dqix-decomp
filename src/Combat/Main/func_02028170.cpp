#include <globaldefs.h>
#include "World/GrottoTileGraph.h"

struct Struct_0201a300_10 {
    unsigned char capacity;
    char pad;
    unsigned char count;
    char pad2;
    struct Struct_0201a300_3* base;
};

// USA: func_02028170
extern "C" ARM void func_02028170(struct Struct_0201a300_10* c, struct Struct_0201a300_3* src) {
    unsigned char count = c->count;
    struct Struct_0201a300_3* dst;
    if (c->capacity <= count) return;
    dst = &c->base[count];
    dst->id = src->id;
    dst->unknown_1_ = src->unknown_1_;
    dst->unknown_2_ = src->unknown_2_;
    dst->flags = src->flags;
    dst->x = src->x;
    dst->unknown_6_ = src->unknown_6_;
    dst->z = src->z;
    dst->unknown_c_ = src->unknown_c_;
    c->count++;
}
