#include <globaldefs.h>

struct Elem_0205cf78 {
    struct Elem_0205cf78* prev;
    char pad[0xE0 - 4];
};

struct Struct_0205cf78 {
    char pad0[0x9C];
    struct Elem_0205cf78* field9C;
    char pad1[0xB3 - 0xA0];
    unsigned char fieldB3;
};

// Main, originally LinkArrayPrevPointers0205cf78 (USA 0x0205cf78, EUR 0x0205cf88, JPN 0x0205e2a8)
ARM void Window_SetPanes(struct Struct_0205cf78* s, struct Elem_0205cf78* arr, unsigned char count) {
    unsigned char i;
    s->field9C = arr;
    s->fieldB3 = count;
    if (s->field9C == 0 || s->fieldB3 == 0) return;
    for (i = 1; i < s->fieldB3; i++) {
        s->field9C[i].prev = &s->field9C[i - 1];
    }
}
