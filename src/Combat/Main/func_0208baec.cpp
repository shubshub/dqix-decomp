#include <globaldefs.h>

extern "C" void func_0205af38(int a, char* obj, int c, int d);
extern "C" int SpriteContext_DrawSprite(int a, void* dst);

struct Struct_0208baec {
    int unknown_0_;
    int x1;
    unsigned char pad8[0xc - 0x8];
    unsigned short f0xc;
};

struct Struct_0208baec_2 {
    unsigned char pad0[0xc];
    int fc;
    int f10;
    int f14;
    int f18;
    unsigned short f1c;
    unsigned short pad1e;
    unsigned short f20;
    unsigned char f22;
};

// USA: func_0208baec
extern "C" ARM int func_0208baec(int a, Struct_0208baec_2* dst, Struct_0208baec* src, int arg3,
                                         float arg4, int pivot, unsigned char arg6) {
    dst->f22 = (unsigned char)arg3;
    func_0205af38(a, (char*)dst, 1, 1);
    dst->f20 = arg6;
    int var0 = src->unknown_0_, x1 = src->x1;
    int dx = var0 - pivot;
    int dy = x1 - pivot;
    dst->f14 = dx << 12;
    dst->f18 = dy << 12;
    dst->fc = (int)(arg4 * 4096.0f);
    dst->f10 = (int)(arg4 * 4096.0f);
    dst->f1c = src->f0xc;
    return SpriteContext_DrawSprite(a, dst);
}
