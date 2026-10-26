#include <globaldefs.h>

struct Struct_ov027_021db430 {
    unsigned char pad0[0x50c];
    unsigned char unknown_50c_;
    unsigned char pad1[0x526 - 0x50d];
    unsigned short unknown_526_;
    unsigned short unknown_528_;
    unsigned short unknown_52a_;
};

struct Struct_ov027_021e33e0_2 {
    unsigned char pad0[8];
    Struct_ov027_021db430* obj;
};

extern Struct_ov027_021e33e0_2 data_ov027_021e33e0;

// USA: func_ov027_021db430
extern "C" ARM int func_ov027_021db430(void) {
    int result = 0;
    int b = 0;
    int a = 0;
    Struct_ov027_021db430* obj = data_ov027_021e33e0.obj;
    if (obj->unknown_528_ == 1 && obj->unknown_50c_ == 0) {
        a = 1;
    }
    if (a) {
        if (obj->unknown_526_ == 0) {
            b = 1;
        }
    }
    if (b) {
        if (obj->unknown_52a_ != 0) {
            result = 1;
        }
    }
    return result;
}
