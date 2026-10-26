#include <globaldefs.h>

struct Struct_ov024_021fb448 {
    char unk[0x18];
    int flags;
};

struct Struct_ov024_021fa7ec_6 {
    char unk[0x138];
    struct Struct_ov024_021fb448* inner;
};

// USA: func_ov024_021fb448
extern "C" ARM int func_ov024_021fb448(struct Struct_ov024_021fa7ec_6* obj) {
    return (obj->inner->flags & 0x4) != 0;
}
