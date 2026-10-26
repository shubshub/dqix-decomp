#include <globaldefs.h>

struct Struct_ov024_021df6ec {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021df454_2 {
    char unk[0x138];
    struct Struct_ov024_021df6ec* inner;
};

// USA: func_ov024_021df6ec
extern "C" ARM int func_ov024_021df6ec(struct Struct_ov024_021df454_2* obj) {
    return (obj->inner->flags & 0x40) != 0;
}
