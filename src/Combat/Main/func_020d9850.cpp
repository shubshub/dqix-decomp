#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct020d9850 {
    unsigned char byte0;
    unsigned char pad1[7];
    unsigned char byte8;
};

// USA: func_020d9850
extern "C" ARM void func_020d9850(Struct020d9850* p) {
    func_0204693c((ByteHeader0204693c*)p);
    p->byte0 = 0x48;
    p->byte8 = 0;
}
