#include <globaldefs.h>

struct Struct_ov024_021edc68 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021eda78_9 {
    char unk[0x138];
    struct Struct_ov024_021edc68* inner;
};

// USA: func_ov024_021edc68
extern "C" ARM int func_ov024_021edc68(struct Struct_ov024_021eda78_9* obj) {
    return (obj->inner->flags & 0x80000000) != 0;
}
