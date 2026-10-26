#include <globaldefs.h>

struct Struct_0208a9c0 {
    unsigned char pad0[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_[4];
    unsigned char unknown_b_;
    int words[3];
    unsigned char unknown_18_[4];
};

// USA: func_0208a9c0
extern "C" ARM void func_0208a9c0(struct Struct_0208a9c0* p, unsigned char a, unsigned char b, unsigned char c) {
    int i;
    int j;
    p->unknown_4_ = a;
    p->unknown_5_ = b;
    p->unknown_6_ = c;
    for (i = 0; i < 4; i++) {
        p->unknown_7_[i] = 0xfe;
        p->unknown_18_[i] = 0;
    }
    for (j = 0; j < 3; j++) {
        p->words[j] = 0;
    }
}
