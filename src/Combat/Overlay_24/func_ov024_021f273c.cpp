#include <globaldefs.h>

struct Struct_ov024_021f273c {
    char unk[0x18];
    int flags;
};

struct Struct_ov024_021f26fc {
    char unk[0x138];
    struct Struct_ov024_021f273c* inner;
};

// USA: func_ov024_021f273c
extern "C" ARM int func_ov024_021f273c(struct Struct_ov024_021f26fc* obj) {
    return (obj->inner->flags & 0x8) != 0;
}
