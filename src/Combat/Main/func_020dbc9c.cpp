#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Struct_020dbc5c {
    signed char byte0;
    signed char pad1[7];
    signed char byte8;
    signed char pad2[3];
    int unknown_c_;
    int unknown_10_;
};

// USA: func_020dbc9c
extern "C" ARM void func_020dbc9c(struct Struct_020dbc5c* p) {
    func_0204693c((struct ByteHeader0204693c*)p);
    p->byte0 = 0x4c;
    p->byte8 = 0;
    p->unknown_c_ = 0;
    p->unknown_10_ = 0;
}
