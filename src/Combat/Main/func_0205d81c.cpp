#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xC4];
    unsigned char fieldC4;
    char pad1[0xE0 - 0xC5];
};

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* unknown_9c_;
    char pad1[0xB3 - 0xA0];
    unsigned char unknown_b3_;
    unsigned char fieldB4;
};

// USA: func_0205d81c
extern "C" ARM struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key) {
    unsigned char i;
    if (s->field98 == 0) return 0;
    if (s->unknown_9c_ == 0) return 0;
    for (i = 0; i < s->unknown_b3_; i++) {
        if (i == s->fieldB4) break;
        if (key == s->unknown_9c_[i].fieldC4) return &s->unknown_9c_[i];
    }
    return 0;
}
