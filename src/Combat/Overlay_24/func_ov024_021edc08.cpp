#include <globaldefs.h>

struct Struct_ov024_021edc08 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021eda78_5 {
    char unk[0x138];
    struct Struct_ov024_021edc08* inner;
};

// USA: func_ov024_021edc08
extern "C" ARM int func_ov024_021edc08(struct Struct_ov024_021eda78_5* obj) {
    return (obj->inner->flags & 0x4000000) != 0;
}
