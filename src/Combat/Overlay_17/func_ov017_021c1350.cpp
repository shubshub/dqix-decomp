#include <globaldefs.h>

struct ByteHeader0204693c { signed char byte0, unknown_1_, unknown_2_, unknown_3_; };
extern "C" void func_0204693c(ByteHeader0204693c* p);
extern int data_ov017_021d8478;

struct Struct_ov017_021c12fc {
    ByteHeader0204693c header;
    unsigned char pad[0x18];
    unsigned char f1c;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
};

// USA: func_ov017_021c1350
extern "C" ARM void func_ov017_021c1350(Struct_ov017_021c12fc* obj, unsigned char a, unsigned char b) {
    func_0204693c(&obj->header);
    obj->header.byte0 = 0x2e;
    data_ov017_021d8478 = 0;
    obj->f1c = 0;
    obj->unknown_1e_ = a;
    obj->unknown_1f_ = b;
    obj->unknown_1d_ = 0xff;
}
