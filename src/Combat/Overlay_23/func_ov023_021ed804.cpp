#include <globaldefs.h>

struct Struct_ov023_021ed804_3 {
    unsigned int f0:6, f1:6, f2:6, f3:6, f4:2, unknown_3_2_:1, unknown_3_3_:1, unknown_3_4_:1;
};
struct Struct_ov023_021ed804 {
    unsigned int unknown_0_;
    unsigned char pad1[0x10];
    unsigned int unknown_14_;
    Struct_ov023_021ed804_3 packed;
};
struct Struct_ov023_021ed804_2 {
    unsigned int f0:6, f1:6, f2:6, f3:6, f4:2, unknown_3_2_:1, unknown_3_3_:1, unknown_3_4_:1, :2, f8:1;
};
union Struct_ov023_021ed804_4 {
    unsigned int v[3];
    struct { unsigned int unknown_0_, w1; Struct_ov023_021ed804_2 packed; } f;
};

extern "C" void* NameText_Clear(void* p);

// USA: func_ov023_021ed804
extern "C" ARM void func_ov023_021ed804(Struct_ov023_021ed804_4* dst, Struct_ov023_021ed804_4 in, Struct_ov023_021ed804* src) {
    NameText_Clear(&in);
    in.f.unknown_0_ = src->unknown_0_;
    in.f.w1 = src->unknown_14_;
    in.f.packed.f0 = src->packed.f0;
    in.f.packed.f1 = src->packed.f1;
    in.f.packed.f2 = src->packed.f2;
    in.f.packed.f3 = src->packed.f3;
    in.f.packed.f4 = src->packed.f4;
    in.f.packed.unknown_3_2_ = src->packed.unknown_3_2_;
    in.f.packed.unknown_3_3_ = src->packed.unknown_3_3_;
    in.f.packed.unknown_3_4_ = src->packed.unknown_3_4_;
    in.f.packed.f8 = 0;
    *dst = in;
}
