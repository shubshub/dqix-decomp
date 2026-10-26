#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021a93f0 {
    unsigned char byte0;
    unsigned char pad1[7];
    int w8;
    int unknown_c_;
    int unknown_10_;
};

// USA: func_ov017_021a942c
extern "C" ARM void func_ov017_021a942c(Struct_ov017_021a93f0* p) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x39;
    p->w8 = 0;
    p->unknown_c_ = 0;
    p->unknown_10_ = 0;
}
