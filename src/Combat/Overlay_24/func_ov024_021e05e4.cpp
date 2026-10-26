#include <globaldefs.h>

struct Struct_ov024_021e05e4 {
    char unk[0x18];
    int flags;
};

struct Struct_ov024_021e04e0 {
    char unk[0x138];
    struct Struct_ov024_021e05e4* inner;
};

// USA: func_ov024_021e05e4
extern "C" ARM int func_ov024_021e05e4(struct Struct_ov024_021e04e0* obj) {
    return (obj->inner->flags & 0x1000) != 0;
}
