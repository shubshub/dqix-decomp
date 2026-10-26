#include <globaldefs.h>

struct Struct_ov024_021edc20 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021eda78_6 {
    char unk[0x138];
    struct Struct_ov024_021edc20* inner;
};

// USA: func_ov024_021edc20
extern "C" ARM int func_ov024_021edc20(struct Struct_ov024_021eda78_6* obj) {
    return (obj->inner->flags & 0x100000) != 0;
}
