#include <globaldefs.h>

extern "C" ARM void func_ov031_0224130c(void);
extern "C" ARM void func_ov031_02241318(void);
struct Struct_ov031_022078f0;
extern "C" ARM int func_ov031_022078f0(Struct_ov031_022078f0* obj, void* v);
extern "C" ARM int func_ov031_02207434(int a);
extern "C" ARM int func_ov031_022071d8(int unused, int mode);

struct Struct_ov031_02241338 {
    char pad[0x810];
    void (*unknown_810_)(void);
    int unknown_814_;
    int unknown_818_;
};

struct Struct_ov031_02241338_2 {
    char pad0[0x8];
    int unknown_8_;
    char unknown_c_[0x18 - 0xc];
    int unknown_18_;
    int unknown_1c_;
    Struct_ov031_02241338* unknown_20_;
};

// USA: func_ov031_02241338
extern "C" ARM int func_ov031_02241338(Struct_ov031_02241338_2* self) {
    typedef int (*Type_ov031_02241338)(int, int, int);
    int r = ((Type_ov031_02241338)func_ov031_022071d8)(2, 1, 0);
    if (r >= 0) {
        if (self->unknown_8_ != 0) {
            func_ov031_02241318();
            self->unknown_20_->unknown_814_ = self->unknown_1c_;
            self->unknown_20_->unknown_818_ = self->unknown_18_;
            self->unknown_20_->unknown_810_ = func_ov031_0224130c;
            if (func_ov031_022078f0((Struct_ov031_022078f0*)r, self->unknown_20_) < 0) {
                func_ov031_02207434(r);
                r = -1;
            }
        }
    }
    return r;
}
