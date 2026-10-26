#include <globaldefs.h>

struct Struct_ov024_021fcac0 {
    char unk[0x18];
    int flags;
};

struct Struct_ov024_021fc754_5 {
    char unk[0x138];
    struct Struct_ov024_021fcac0* inner;
};

// USA: func_ov024_021fcac0
extern "C" ARM int func_ov024_021fcac0(struct Struct_ov024_021fc754_5* obj) {
    return (obj->inner->flags & 0x400) != 0;
}
