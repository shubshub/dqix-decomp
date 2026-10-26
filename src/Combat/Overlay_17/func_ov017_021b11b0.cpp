#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct021b11b0 {
    unsigned char byte0;
    unsigned char pad1[7];
    unsigned char b8;
    unsigned char pad2;
    unsigned char unknown_a_;
    unsigned char pad3;
    unsigned short hc;
};

// USA: func_ov017_021b11b0
extern "C" ARM void func_ov017_021b11b0(Struct021b11b0* p) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x27;
    p->b8 = 0;
    p->unknown_a_ = 0;
    p->hc = 0;
}
