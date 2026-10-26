#include <globaldefs.h>

struct Struct_ov024_021da9c8 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021da670_8 {
    char unk[0x138];
    struct Struct_ov024_021da9c8* inner;
};

// USA: func_ov024_021da9c8
extern "C" ARM int func_ov024_021da9c8(struct Struct_ov024_021da670_8* obj) {
    return (obj->inner->flags & 0x80000) != 0;
}
