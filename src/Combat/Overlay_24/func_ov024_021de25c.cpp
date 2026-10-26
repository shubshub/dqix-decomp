#include <globaldefs.h>

struct Struct_ov024_021de25c {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021de124 {
    char unk[0x138];
    struct Struct_ov024_021de25c* inner;
};

// USA: func_ov024_021de25c
extern "C" ARM int func_ov024_021de25c(struct Struct_ov024_021de124* obj) {
    return (obj->inner->flags & 0x20) != 0;
}
