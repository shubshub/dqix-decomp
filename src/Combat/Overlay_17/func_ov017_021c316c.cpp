#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_02192700_2 {
    unsigned char byte0;
    unsigned char pad1[7];
    unsigned char b8;
    unsigned char unknown_9_;
};

// USA: func_ov017_021c316c
extern "C" ARM void func_ov017_021c316c(Struct_ov017_02192700_2* p, int flag) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x47;
    p->b8 = 0;
    p->unknown_9_ = (unsigned char)flag;
}
