#include <globaldefs.h>

struct Struct_ov026_021dd3c4 {
    char unk[0x18];
    int flags;
};

struct Struct_ov026_021d8ba0_10 {
    char unk[0x138];
    struct Struct_ov026_021dd3c4* inner;
};

// USA: func_ov026_021dd3c4
extern "C" ARM int func_ov026_021dd3c4(struct Struct_ov026_021d8ba0_10* obj) {
    return (obj->inner->flags & 0x2000) != 0;
}
