#include <globaldefs.h>

struct Struct_ov023_021fd420 {
    char pad0[0x22];
    unsigned short f22;
    unsigned short f24;
    unsigned short unknown_26_;
    unsigned short f28;
};

// USA: func_ov023_021fd420
extern "C" ARM void func_ov023_021fd420(struct Struct_ov023_021fd420* obj, unsigned short* out1, unsigned short* out2, unsigned short* out3, unsigned short* arg4) {
    *out1 = obj->f22;
    *out2 = obj->f24;
    *out3 = *out1 + obj->unknown_26_;
    *arg4 = *out2 + obj->f28;
}
