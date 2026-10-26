#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215a5dc_16 = 8 };
#else
enum { Enum_ov006_0215a5dc_16 = 0x10 };
#endif

struct Struct_ov006_021553bc;

extern "C" void func_ov006_021571b8(void* p, unsigned char v);
extern "C" void func_ov006_021571cc(Struct_ov006_021553bc* s);

struct Struct_ov006_02157a60 {
    char pad0[Enum_ov006_0215a5dc_16];
    Struct_ov006_021553bc* f10;
    char unknown_14_[0x38b - Enum_ov006_0215a5dc_16 - 4];
    unsigned char unknown_38b_;
};

// USA: func_ov006_0215a5dc
extern "C" ARM void func_ov006_0215a5dc(Struct_ov006_02157a60* self) {
    func_ov006_021571b8(self->f10, self->unknown_38b_);
    func_ov006_021571cc(self->f10);
}
