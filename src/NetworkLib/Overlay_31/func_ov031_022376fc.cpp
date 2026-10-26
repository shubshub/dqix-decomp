#include <globaldefs.h>


struct Struct_ov031_022376fc_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned char unknown_4_[4];
    unsigned short unknown_8_;
};
struct Struct_ov031_022376fc {
    unsigned char unknown_0_[0x1b94];
    unsigned char unknown_1b94_;
    unsigned char unknown_1b95_;
    unsigned char unknown_1b96_;
};
extern Struct_ov031_022376fc* data_ov031_02290d0c;
extern "C" void func_ov031_022378e4(Struct_ov031_022376fc_2*);
extern "C" void func_ov031_0223778c(Struct_ov031_022376fc_2*);
extern "C" int func_ov031_022375cc();
extern "C" void HaltSystem(Command022376fc*);

// USA: func_ov031_022376fc
extern "C" ARM void func_ov031_022376fc(Struct_ov031_022376fc_2* arg0) {
    if (arg0->unknown_2_) return;
    Struct_ov031_022376fc* var0 = data_ov031_02290d0c;
    if (var0->unknown_1b94_) {
        if (arg0->unknown_0_ == 2) var0->unknown_1b94_ = 2;
        return;
    }
    if (arg0->unknown_0_ != 0x26) return;
    switch (arg0->unknown_8_) {
    case 5:
        if (var0->unknown_1b96_) func_ov031_022378e4(arg0);
        else func_ov031_0223778c(arg0);
        func_ov031_022375cc();
        break;
    case 4:
        func_ov031_022375cc();
        break;
    default:
        HaltSystem(command);
        break;
    }
}
