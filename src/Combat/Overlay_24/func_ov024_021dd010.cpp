#include <globaldefs.h>

struct Struct_ov024_021dd010 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021dced0_2 {
    char unk[0x138];
    struct Struct_ov024_021dd010* inner;
};

// USA: func_ov024_021dd010
extern "C" ARM int func_ov024_021dd010(struct Struct_ov024_021dced0_2* obj) {
    return (obj->inner->flags & 0x100) != 0;
}
