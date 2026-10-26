#include <globaldefs.h>

struct Struct_ov023_021dbb34_2 {
    int unk0;
    int unk4;
    int field8;
    struct {
        unsigned int lo : 10;
        unsigned int hi : 10;
        unsigned int rest : 12;
    } unknown_c_;
    int field10;
    int field14;
};

struct Struct_ov023_021dbb34 {
    float f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, unknown_2c_;
};

// USA: func_ov023_021dbb34
extern "C" ARM void func_ov023_021dbb34(void* handle, struct Struct_ov023_021dbb34* out) {
    if (handle == 0 || out == 0) return;
    struct Struct_ov023_021dbb34_2* p = *(struct Struct_ov023_021dbb34_2**)handle;
    if (p == 0) return;
    out->f0 = (float)((p->field8 << 22) >> 22);
    out->f4 = (float)((p->field8 << 12) >> 22);
    out->f8 = (float)(unsigned int)((unsigned int)p->field8 << 2 >> 22) / 10.0f;
    out->fc = (float)(unsigned int)p->unknown_c_.lo / 10.0f;
    out->f10 = (float)(unsigned int)p->unknown_c_.hi / 10.0f;
    out->f14 = 0;
    out->f18 = (float)((p->field10 << 22) >> 22);
    out->f1c = (float)((p->field10 << 12) >> 22);
    out->f20 = (float)((p->field10 << 2) >> 22);
    out->f24 = (float)((p->field14 << 22) >> 22);
    out->f28 = (float)((p->field14 << 12) >> 22);
    out->unknown_2c_ = (float)((p->field14 << 2) >> 22);
}
