#if defined(jpn)
enum {regionalOffset0=0x56c};
#else
enum {regionalOffset0=0x634};
#endif
#include <globaldefs.h>

extern "C" void func_ov023_021e2bdc(void* a, int unused, short* out1, short* out2);
extern "C" void SpriteContext_DrawSprite(void* obj, void* entry);

struct Struct_ov023_021e4264 {
    char pad0[0xc8];
    void* fc8;
    void* fcc;
    char pad1[regionalOffset0 - 0xd0];
    unsigned short unknown_634_;
};

struct Struct_ov023_021e4264_2 {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x22 - 0x1c];
    unsigned char f22;
    char pad2[0x26 - 0x23];
    unsigned char unknown_26_;
};

// USA: func_ov023_021e4264
extern "C" ARM void func_ov023_021e4264(Struct_ov023_021e4264* obj) {
    short lo, hi;
    Struct_ov023_021e4264_2* entry = (Struct_ov023_021e4264_2*)obj->fcc;
    func_ov023_021e2bdc((char*)obj + 0xd4, 0x11, &lo, &hi);
    if (obj->unknown_634_ & 0x100) {
        lo--;
        hi++;
    }
    Struct_ov023_021e4264_2* e0 = (Struct_ov023_021e4264_2*)((char*)entry + 0x50);
    e0->f14 = lo << 12;
    e0->f18 = hi << 12;
    e0->f22 = 0x7f;
    e0->unknown_26_ = 2;
    SpriteContext_DrawSprite(obj->fc8, e0);

    entry = (Struct_ov023_021e4264_2*)obj->fcc;
    func_ov023_021e2bdc((char*)obj + 0xd4, 0x12, &lo, &hi);
    if (obj->unknown_634_ & 0x200) {
        lo++;
        hi++;
    }
    Struct_ov023_021e4264_2* e1 = (Struct_ov023_021e4264_2*)((char*)entry + 0x78);
    e1->f14 = lo << 12;
    e1->f18 = hi << 12;
    e1->f22 = 0x7e;
    e1->unknown_26_ = 2;
    SpriteContext_DrawSprite(obj->fc8, e1);
}
