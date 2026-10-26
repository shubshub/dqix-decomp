#include <globaldefs.h>

struct Struct_ov024_021da998 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021da670_6 {
    char unk[0x138];
    struct Struct_ov024_021da998* inner;
};

// USA: func_ov024_021da998
extern "C" ARM int func_ov024_021da998(struct Struct_ov024_021da670_6* obj) {
    return (obj->inner->flags & 0x800000) != 0;
}
