#include <globaldefs.h>

struct Struct_020e1eb0_2 {
    char pad[0x38];
    unsigned char unknown_38_;
    unsigned char unknown_39_;
};

struct Struct_020e1eb0 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;
};

struct Struct_020e1e4c {
    char pad0[4];
    struct Struct_020e1eb0_2* origin;
    signed char count;
    char unknown_9_;
    struct Struct_020e1eb0 rects[1];
};

// USA: func_020e1eb0
extern "C" ARM int func_020e1eb0(struct Struct_020e1e4c* list, int x, int y) {
    int i;
    for (i = 0; i < list->count; i++) {
        struct Struct_020e1eb0_2* o = list->origin;
        int var2 = o->unknown_38_ + list->rects[i].unknown_0_;
        int var3 = o->unknown_39_ + list->rects[i].unknown_2_;
        int x1 = o->unknown_38_ + list->rects[i].unknown_4_;
        int var5 = o->unknown_39_ + list->rects[i].unknown_6_;
        if (var2 <= x && x <= x1 && var3 <= y && y <= var5) {
            return i;
        }
    }
    return -1;
}
