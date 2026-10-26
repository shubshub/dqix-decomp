#include <globaldefs.h>

struct Struct_ov025_021ed1f0 {
    unsigned short unknown_0_[16];
    short unknown_20_[16];
    short unknown_40_[16];
    short unknown_60_[16];
    unsigned short unknown_80_[16];
    unsigned char unknown_a0_[16];
    unsigned int unknown_b0_[16];
    unsigned int unknown_f0_[16];
    unsigned char unknown_130_[0x20];
    unsigned char unknown_150_;
    unsigned char unknown_151_[0xb];
    short unknown_15c_;
};

// USA: func_ov025_021ed1f0
extern "C" ARM void func_ov025_021ed1f0(void* self) {
    struct Struct_ov025_021ed1f0* view = (struct Struct_ov025_021ed1f0*)self;
    unsigned char count = view->unknown_150_;
    if (count == 0) return;
    view->unknown_150_ = count - 1;

    for (int i = 0; i < view->unknown_150_; i++) {
        view->unknown_0_[i] = view->unknown_0_[i + 1];
        view->unknown_20_[i] = view->unknown_20_[i + 1];
        view->unknown_a0_[i] = view->unknown_a0_[i + 1];
        view->unknown_b0_[i] = view->unknown_b0_[i + 1];
        view->unknown_60_[i] = view->unknown_60_[i + 1];
        view->unknown_40_[i] = view->unknown_40_[i + 1];
        view->unknown_80_[i] = view->unknown_80_[i + 1];
    }

    view->unknown_15c_--;
    if (view->unknown_15c_ < 0) view->unknown_15c_ = 0;
}
