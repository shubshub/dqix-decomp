#include <globaldefs.h>

struct SrcPacked_021ed804 {
    unsigned int f0:6, f1:6, f2:6, f3:6, f4:2, f5:1, f6:1, f7:1;
};
struct Src_021ed804 {
    unsigned int w0;
    unsigned char pad1[0x10];
    unsigned int w14;
    SrcPacked_021ed804 packed;
};
struct DstPacked_021ed804 {
    unsigned int f0:6, f1:6, f2:6, f3:6, f4:2, f5:1, f6:1, f7:1, :2, f8:1;
};
union Dst3_021ed804 {
    unsigned int v[3];
    struct { unsigned int w0, w1; DstPacked_021ed804 packed; } f;
};

void* NameText_Clear(void* p);

// USA: func_ov023_021ed804  (semantic: PackBitFieldsRecord_021ed804)
extern "C" ARM void func_ov023_021ed804(Dst3_021ed804* dst, Dst3_021ed804 in, Src_021ed804* src) {
    NameText_Clear(&in);
    in.f.w0 = src->w0;
    in.f.w1 = src->w14;
    in.f.packed.f0 = src->packed.f0;
    in.f.packed.f1 = src->packed.f1;
    in.f.packed.f2 = src->packed.f2;
    in.f.packed.f3 = src->packed.f3;
    in.f.packed.f4 = src->packed.f4;
    in.f.packed.f5 = src->packed.f5;
    in.f.packed.f6 = src->packed.f6;
    in.f.packed.f7 = src->packed.f7;
    in.f.packed.f8 = 0;
    *dst = in;
}
