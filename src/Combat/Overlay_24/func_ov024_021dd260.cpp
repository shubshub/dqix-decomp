#include <globaldefs.h>

struct Struct_ov024_021dd260 {
    char unk[0x14];
    int flags;
};

struct Struct_ov024_021dd028_5 {
    char unk[0x138];
    struct Struct_ov024_021dd260* inner;
};

// USA: func_ov024_021dd260
extern "C" ARM int func_ov024_021dd260(struct Struct_ov024_021dd028_5* obj) {
    return (obj->inner->flags & 0x1000000) != 0;
}
