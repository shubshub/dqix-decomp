#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021913d0 {
    unsigned char byte0;
    unsigned char pad1[7];
    short h8;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
};

// USA: func_ov017_021c1e40
extern "C" ARM void func_ov017_021c1e40(Struct_ov017_021913d0* p) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x42;
    p->unknown_a_ = 0;
    p->unknown_b_ = 0;
    p->h8 = 0x42 - 0x43;
}
