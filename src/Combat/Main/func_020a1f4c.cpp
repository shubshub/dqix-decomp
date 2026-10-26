#include <globaldefs.h>

extern "C" void Overlay_Load(int);
struct Struct_02109da4 {
    unsigned char countA;
    unsigned char countB;
    signed char unknown_2_[8];
    signed char unknown_a_[8];
};
extern Struct_02109da4 data_02109da4;
extern signed char data_020f1977[];

static inline int inline_020a1f4c(const Struct_02109da4* p) { return p->countB; }

// USA: func_020a1f4c
extern "C" ARM void func_020a1f4c(int flag) {
    if (inline_020a1f4c(&data_02109da4) == 0) return;
    data_02109da4.countB--;
    if (flag == 0 || inline_020a1f4c(&data_02109da4) == 0) return;
    signed char i = data_02109da4.unknown_2_[data_02109da4.countB - 1];
    Overlay_Load(data_020f1977[i]);
}
