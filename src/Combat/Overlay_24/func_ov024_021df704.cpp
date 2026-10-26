#include <globaldefs.h>

struct Struct_ov024_021df704 {
    char unk[0x18];
    int flags;
};

struct Struct_ov024_021df454_7 {
    char unk[0x138];
    struct Struct_ov024_021df704* inner;
};

// USA: func_ov024_021df704
extern "C" ARM int func_ov024_021df704(struct Struct_ov024_021df454_7* obj) {
    return (obj->inner->flags & 0x10) != 0;
}
