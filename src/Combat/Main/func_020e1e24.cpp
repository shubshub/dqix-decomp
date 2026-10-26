#include <globaldefs.h>

struct Struct_020e1e24_2 {
    char unk[0x38];
    unsigned char unknown_38_;
    unsigned char unknown_39_;
};

struct Struct_020e1e24 {
    int unk0;
    struct Struct_020e1e24_2* sub;
};

// USA: func_020e1e24
extern "C" ARM void func_020e1e24(struct Struct_020e1e24* obj, unsigned short* outX, unsigned short* outY, int index) {
    *outX = obj->sub->unknown_38_ + 0xc;
    *outY = obj->sub->unknown_39_ + 8 + (index << 4);
}
