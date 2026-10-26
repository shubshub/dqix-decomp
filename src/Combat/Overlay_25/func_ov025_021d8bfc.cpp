#include <globaldefs.h>

struct Struct_ov025_021d8bfc {
    unsigned int unknown_0_;
    unsigned int w1;
    unsigned int w2;
    unsigned int unknown_c_;
    unsigned int w4;
    unsigned char unknown_14_;
};

extern "C" void func_ov025_021d8c30(void* a, unsigned int arg1, unsigned int w1, unsigned int w2,
                                     unsigned int arg4, unsigned int w4, unsigned int arg6);

// USA: func_ov025_021d8bfc
extern "C" ARM void func_ov025_021d8bfc(void* a, struct Struct_ov025_021d8bfc* b) {
    func_ov025_021d8c30(a, b->unknown_0_, b->w1, b->w2, b->unknown_c_, b->w4, b->unknown_14_);
}
