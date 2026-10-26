#include <globaldefs.h>

struct Struct_02086e9c_2 {
    signed char value : 6;
    unsigned char : 1;
    unsigned char flag : 1;
    char rest[0x23c - 1];
};

struct Struct_02086e9c {
    char pad0[0xf80];
    struct Struct_02086e9c_2 elems[13];
    unsigned char count;
};

// USA: func_02086e9c
extern "C" ARM int func_02086e9c(struct Struct_02086e9c* c) {
    unsigned char i;
    for (i = 0; i < c->count; i++) {
        struct Struct_02086e9c_2* e = &c->elems[i];
        if (e->flag) {
            return e->value;
        }
    }
    return -1;
}
