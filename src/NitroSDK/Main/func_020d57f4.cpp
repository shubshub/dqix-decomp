#include <globaldefs.h>


extern "C" void func_020ca3ec(int value, void* dest, int count);

struct Struct_020d57f4 {
    int type;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
};

extern "C" void func_020d5684(int, int, int, int, unsigned short, struct Struct_020d57f4*);

// USA: func_020d57f4
extern "C" ARM void func_020d57f4(int a, int b, int c, int d, unsigned short e, unsigned short f, unsigned short g, int h, int i, int j, int k) {
    struct Struct_020d57f4 s;
    func_020ca3ec(0, &s, 0x10);
    s.type = 0x1e03;
    s.unknown_a_ = g;
    s.unknown_c_ = h;
    s.unknown_d_ = i;
    s.unknown_e_ = k;
    s.unknown_4_ = f;
    s.unknown_6_ = f;
    if (j != 0 && f != 0) {
        s.type |= 4;
        s.unknown_8_ = f;
    }
    func_020d5684(a, b, c, d, e, &s);
}
