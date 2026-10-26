#include <globaldefs.h>

struct Struct_ov025_021ed110_2 {
    char pad0[0x4];
    unsigned short value;
};

struct Struct_ov025_021ed110 {
    char pad0[0x300];
    Struct_ov025_021ed110_2 sub;

    Struct_ov025_021ed110_2* inline_ov025_021ed110() { return &sub; }
};

// USA: func_ov025_021ed110
extern "C" ARM void func_ov025_021ed110(Struct_ov025_021ed110* obj, int value) {
    obj->inline_ov025_021ed110()->value = value;
}
