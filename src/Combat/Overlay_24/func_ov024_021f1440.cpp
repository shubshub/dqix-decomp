#include <globaldefs.h>

struct Struct_ov024_021f1440 {
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

struct Struct_ov024_021f1330 {
    char unk[0x138];
    struct Struct_ov024_021f1440* inner;
};

// USA: func_ov024_021f1440
extern "C" ARM int func_ov024_021f1440(struct Struct_ov024_021f1330* obj) {
    return obj->inner->b2 != 0;
}
