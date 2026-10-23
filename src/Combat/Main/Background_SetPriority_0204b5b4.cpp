#include <globaldefs.h>

extern int (*data_020f01d8[][4])(int);

struct Struct_0204b5b4 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
};

static inline int (*inline_0204b5b4(int arg1, int arg2))(int) {
    return data_020f01d8[arg1][arg2];
}

// Main, originally func_0204b5b4 (USA 0x0204b5b4, EUR 0x0204b5c4, JPN 0x0204c3d4)
extern "C" ARM void Background_SetPriority(struct Obj0204b5b4* obj, int a) {
    tbl_at(obj->lo, obj->hi)(a & 3);
}
