#include <globaldefs.h>

struct Elem_0205d81c { char pad0[0xe0]; };

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* unknown_9c_;
    char pad1[0xb0 - 0xa0];
    unsigned char fieldB0;
    char pad2[0xb4 - 0xb1];
    unsigned char fieldB4;
};

extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c*, int);

// Main, originally FindElementForFieldB0_0205d8c4 (USA 0x0205d8c4, EUR 0x0205d8d4, JPN 0x0205ebd8)
extern "C" ARM struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s) {
    if (s->field98 == 0) return 0;
    if (s->unknown_9c_ == 0) return 0;
    if (s->fieldB4 == 0) return 0;
    return func_0205d81c(s, s->fieldB0);
}
