#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_02061c04_15 {
    unsigned char byte0;
    unsigned char pad1;
    unsigned char unknown_2_;
    unsigned char pad3[5];
    unsigned short unknown_8_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    int unknown_c_[1];
};

// USA: func_020d9dec
extern "C" ARM void func_020d9dec(Struct_02061c04_15* p, int flag) {
    int i;
    if (flag == 0 && p->unknown_2_ != 0) return;
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x49;
    p->unknown_8_ = 0;
    p->unknown_a_ = 0;
    for (i = 0; i < 1; i++) {
        p->unknown_c_[i] = -1;
    }
}
