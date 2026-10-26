#include <globaldefs.h>

struct Struct_ov024_021e8bf0 {
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char unknown_0_4_:1;
    unsigned char unknown_0_5_:1;
    unsigned char unknown_0_6_:1;
    unsigned char unknown_0_7_:1;
};

// USA: func_ov024_021e8bf0
extern "C" ARM void func_ov024_021e8bf0(void* unused0, char* obj, short* out2) {
    struct Struct_ov024_021e8bf0* f = (struct Struct_ov024_021e8bf0*)(obj + 0x1c);
    if (f->b2 || f->b1 || f->b3 || f->unknown_0_4_ || f->unknown_0_5_ || f->unknown_0_6_) {
        *out2 = 0;
    }
}
