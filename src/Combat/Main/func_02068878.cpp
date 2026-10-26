#include <globaldefs.h>

struct Struct_02068878_2 {
    char pad0[8];
    unsigned int unknown_8_0_ : 24;
    unsigned int unknown_b_0_ : 2;
    unsigned int unknown_b_2_ : 6;
};

struct Struct_02068878 {
    struct Struct_02068878_2* inner;
};

// USA: func_02068878
extern "C" ARM int func_02068878(int unused, struct Struct_02068878* p) {
    struct Struct_02068878_2* q = p->inner;
    return q != 0 ? q->unknown_b_0_ : 0;
}
