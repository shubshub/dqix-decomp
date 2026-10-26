#include <globaldefs.h>

struct Struct_ov024_021edc38 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021eda78_7 {
    char unk[0x138];
    struct Struct_ov024_021edc38* inner;
};

// USA: func_ov024_021edc38
extern "C" ARM int func_ov024_021edc38(struct Struct_ov024_021eda78_7* obj) {
    return (obj->inner->flags & 0x200000) != 0;
}
