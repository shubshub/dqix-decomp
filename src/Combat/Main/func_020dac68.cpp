#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_020dac40_2 {
    unsigned char byte0;
    unsigned char pad1[11];
    int unknown_c_;
    int unknown_10_;
    unsigned char unknown_14_[0x14];
    unsigned char unknown_28_;
};

// USA: func_020dac68
extern "C" ARM void func_020dac68(Struct_020dac40_2* p) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x4b;
    p->unknown_c_ = 0;
    p->unknown_10_ = 0;
    p->unknown_28_ = 0xff;
}
