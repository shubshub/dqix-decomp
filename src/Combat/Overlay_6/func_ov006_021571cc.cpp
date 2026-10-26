#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_021571cc_2788 = 0x964, Enum_ov006_021571cc_1908 = 0x6f0, Enum_ov006_021571cc_1947 = 0x717 };
#else
enum { Enum_ov006_021571cc_2788 = 0xae4, Enum_ov006_021571cc_1908 = 0x774, Enum_ov006_021571cc_1947 = 0x79b };
#endif

extern "C" void func_ov023_021dd344(void* p);

struct Struct_ov006_021571cc {
    unsigned char unknown0[Enum_ov006_021571cc_1908];
    unsigned short flags;
    unsigned char unknown_776_[Enum_ov006_021571cc_1947 - Enum_ov006_021571cc_1908 - 2];
    unsigned char unknown_79b_;
};

struct Struct_ov006_021553bc {
    unsigned char unknown0[Enum_ov006_021571cc_2788];
    Struct_ov006_021571cc unknown_ae4_;
};

// USA: func_ov006_021571cc
extern "C" ARM void func_ov006_021571cc(struct Struct_ov006_021553bc* s) {
    int enabled = (s->unknown_ae4_.flags & 0x800) != 0;
    if (enabled) {
        func_ov023_021dd344(&s->unknown_ae4_);
    }
}
