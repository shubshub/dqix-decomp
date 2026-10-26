#include <globaldefs.h>

struct Struct_ov024_021fb478 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021fa7ec_8 {
    char unk[0x138];
    struct Struct_ov024_021fb478* inner;
};

// USA: func_ov024_021fb478
extern "C" ARM int func_ov024_021fb478(struct Struct_ov024_021fa7ec_8* obj) {
    return (obj->inner->flags & 0x20000) != 0;
}
