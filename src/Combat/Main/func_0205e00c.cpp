#include <globaldefs.h>

struct Struct_0205e00c { char pad0[0xe0]; };

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Struct_0205e00c* unknown_9c_;
    char pad1[0xb4 - 0xa0];
    unsigned char fieldB4;
};

extern "C" struct Struct_0205e00c* func_0205d81c(struct Struct_0205d81c*, int);

// USA: func_0205e00c
extern "C" ARM struct Struct_0205e00c* func_0205e00c(struct Struct_0205d81c* s, int key) {
    if (func_0205d81c(s, key) != 0) return 0;
    return &s->unknown_9c_[s->fieldB4];
}
