#include <globaldefs.h>

struct Struct_ov024_021edc50 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021eda78_8 {
    char unk[0x138];
    struct Struct_ov024_021edc50* inner;
};

// USA: func_ov024_021edc50
extern "C" ARM int func_ov024_021edc50(struct Struct_ov024_021eda78_8* obj) {
    return (obj->inner->flags & 0x40000000) != 0;
}
