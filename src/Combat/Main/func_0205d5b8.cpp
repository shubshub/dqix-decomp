#include <globaldefs.h>

struct Struct_0205d5b8 {
    char unk[0xc5];
    unsigned char flags;
};

// USA: func_0205d5b8
extern "C" ARM void func_0205d5b8(struct Struct_0205d5b8* obj, int cond) {
    if (cond) {
        obj->flags |= 0x20;
    } else {
        obj->flags &= ~0x20;
    }
}
