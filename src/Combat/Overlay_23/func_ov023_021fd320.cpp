#include <globaldefs.h>

struct Struct_ov011_02188184_3 {
    char pad0[0x4];
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned short f8;
    char pad1[0x1c - 0xa];
    int f1c;
    unsigned short f20;
    unsigned short f22;
    unsigned short f24;
    unsigned short unknown_26_;
    unsigned short f28;
    unsigned short unknown_2a_;
    unsigned char unknown_2c_;
};

extern "C" void func_ov023_021f6ed8(void*);

// USA: func_ov023_021fd320
extern "C" ARM int func_ov023_021fd320(struct Struct_ov011_02188184_3* obj, int unused, int val, int byteVal, int p5, int p6, int p7, int p8, int p9) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 0x13;
    obj->unknown_6_ = (unsigned short)val;
    obj->f8 = (unsigned short)byteVal;
    obj->f1c = 2;
    obj->f20 = (unsigned short)val;
    obj->f22 = (unsigned short)p5;
    obj->f24 = (unsigned short)p6;
    obj->unknown_26_ = (unsigned short)p7;
    obj->f28 = (unsigned short)p8;
    obj->unknown_2a_ = 0;
    obj->unknown_2c_ = (unsigned char)p9;
    return 1;
}
