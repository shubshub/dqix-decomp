#include <globaldefs.h>

struct Struct_ov024_021da9b0 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021da670_7 {
    char unk[0x138];
    struct Struct_ov024_021da9b0* inner;
};

// USA: func_ov024_021da9b0
extern "C" ARM int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj) {
    return (obj->inner->flags & 0x8) != 0;
}
