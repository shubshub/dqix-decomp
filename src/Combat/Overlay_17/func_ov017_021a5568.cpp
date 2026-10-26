#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021a5568 {
    unsigned char byte0;
    unsigned char pad0[7];
    int f8;
    unsigned char pad1[0x14];
    unsigned char f20;
    unsigned char unknown_21_;
    short f22;
};

extern int data_ov017_021d83ac;

// USA: func_ov017_021a5568
extern "C" ARM void func_ov017_021a5568(Struct_ov017_021a5568* p) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0xc;
    p->f8 = 0;
    data_ov017_021d83ac = 0;
    p->f20 = 0;
    p->unknown_21_ = 0;
    p->f22 = -1;
}
