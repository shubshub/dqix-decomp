#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov028_021d8a40 {
    char pad0[0x8];
    unsigned int f8;
    char unknown_c_[0xa0 - 0xc];
    unsigned int unknown_a0_;
    char unknown_a4_[0xa8 - 0xa4];
    unsigned short unknown_a8_;
    unsigned short unknown_aa_;
    unsigned short unknown_ac_;
    unsigned short unknown_ae_;
};

extern "C" void WindowPane_Init(void* obj);

// USA: func_ov028_021d8a40
extern "C" ARM void func_ov028_021d8a40(Struct_ov028_021d8a40* self, unsigned int val) {
    WindowPane_Init(self);
    self->f8 = val;
    self->unknown_ac_ = 0;
    self->unknown_ae_ = 0;
    self->unknown_a8_ = 0x20;
    self->unknown_aa_ = 0x20;
    self->unknown_a0_ = 0;
}
