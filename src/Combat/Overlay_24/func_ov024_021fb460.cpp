#include <globaldefs.h>

struct Struct_ov024_021fb460 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021fa7ec_7 {
    char unk[0x138];
    struct Struct_ov024_021fb460* inner;
};

// USA: func_ov024_021fb460
extern "C" ARM int func_ov024_021fb460(struct Struct_ov024_021fa7ec_7* obj) {
    return (obj->inner->flags & 0x10000) != 0;
}
