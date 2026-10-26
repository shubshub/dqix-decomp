#include <globaldefs.h>

struct Struct_ov024_021f0d0c {
    char unk[0x3c];
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char unknown_3c_4_:1;
    unsigned char unknown_3c_5_:1;
    unsigned char unknown_3c_6_:1;
    unsigned char unknown_3c_7_:1;
};

struct Struct_ov024_021f0b84 {
    char unk[0x138];
    struct Struct_ov024_021f0d0c* inner;
};

// USA: func_ov024_021f0d0c
extern "C" ARM int func_ov024_021f0d0c(struct Struct_ov024_021f0b84* obj) {
    return obj->inner->b1 != 0;
}
