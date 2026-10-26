#include <globaldefs.h>

struct Struct_020d76b8_2 {
    char unk[0x26];
    unsigned short flags;
};

struct Struct_020d76b8 {
    char unk[0xa00];
    struct Struct_020d76b8_2 sub;
};

// USA: func_020d76b8
extern "C" ARM void func_020d76b8(struct Struct_020d76b8* obj, int index) {
    if (index >= 0xc0) {
        index -= 0xbc;
    }
    obj->sub.flags |= 1 << index;
}
