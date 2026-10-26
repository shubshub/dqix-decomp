#include <globaldefs.h>

struct Struct_ov024_021e47dc {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021e4604 {
    char unk[0x138];
    struct Struct_ov024_021e47dc* inner;
};

// USA: func_ov024_021e47dc
extern "C" ARM int func_ov024_021e47dc(struct Struct_ov024_021e4604* obj) {
    return (obj->inner->flags & 0x400000) != 0;
}
