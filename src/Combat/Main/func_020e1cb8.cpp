#include <globaldefs.h>

struct Struct_020e1cb8_2 {
    char unk[0x3f];
    unsigned char flags;
};

struct Struct_020e1cb8 {
    char unk[4];
    struct Struct_020e1cb8_2* sub;
};

// USA: func_020e1cb8
extern "C" ARM void func_020e1cb8(struct Struct_020e1cb8* obj) {
    obj->sub->flags &= ~1;
    obj->sub->flags |= 2;
}
