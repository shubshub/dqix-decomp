#include <globaldefs.h>

struct Struct_ov026_021dce1c {
    char unk[0x14];
    int flags;
};

struct Struct_ov026_021dc8fc_4 {
    char unk[0x138];
    struct Struct_ov026_021dce1c* inner;
};

// USA: func_ov026_021dce1c
extern "C" ARM int func_ov026_021dce1c(struct Struct_ov026_021dc8fc_4* obj) {
    return (obj->inner->flags & 0x8) != 0;
}
