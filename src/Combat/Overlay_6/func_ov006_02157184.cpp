#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_02157184_2786 = 0x962, Enum_ov006_02157184_1908 = 0x6f0, Enum_ov006_02157184_1947 = 0x717 };
#else
enum { Enum_ov006_02157184_2786 = 0xae2, Enum_ov006_02157184_1908 = 0x774, Enum_ov006_02157184_1947 = 0x79b };
#endif

extern "C" void func_ov023_021dcd90(void* p, int x);
extern "C" void func_ov006_02155508(void* s);

struct Struct_ov006_021571cc {
    unsigned char unknown0[Enum_ov006_02157184_1908];
    unsigned short flags;
    unsigned char unknown_776_[Enum_ov006_02157184_1947 - Enum_ov006_02157184_1908 - 2];
    unsigned char unknown_79b_;
};

struct Struct_ov006_02157184 {
    unsigned char pad[Enum_ov006_02157184_2786];
    unsigned short flags;
    Struct_ov006_021571cc unknown_ae4_;
};

// USA: func_ov006_02157184
extern "C" ARM void func_ov006_02157184(struct Struct_ov006_02157184* s) {
    s->flags &= ~0x40;
    func_ov023_021dcd90(&s->unknown_ae4_, 0);
    func_ov006_02155508(s);
}
