#include <globaldefs.h>

struct Struct_ov024_021fb430 {
    char unk[0x18];
    int flags;
};

struct Struct_ov024_021fa7ec_5 {
    char unk[0x138];
    struct Struct_ov024_021fb430* inner;
};

// USA: func_ov024_021fb430
extern "C" ARM int func_ov024_021fb430(struct Struct_ov024_021fa7ec_5* obj) {
    return (obj->inner->flags & 0x2) != 0;
}
