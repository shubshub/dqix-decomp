#include <globaldefs.h>

extern "C" void func_ov023_021e2bdc(void* a, int unused, short* out1, short* out2);
extern "C" void SpriteContext_DrawSprite(void* obj, void* entry);

struct Struct_ov023_021e4358 {
    char pad0[0xc8];
    void* fc8;
    void* fcc;
    #if defined(jpn)
    char pad1[0x4e4 - 0xd0];
#else
    char pad1[0x4e8 - 0xd0];
#endif
    int f4e8;
    #if defined(jpn)
    char pad2[0x56c - 0x4e8];
#else
    char pad2[0x634 - 0x4ec];
#endif
    unsigned short unknown_634_;
};

struct Struct_ov023_021e4358_2 {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x22 - 0x1c];
    unsigned char f22;
    char pad2[0x26 - 0x23];
    unsigned char unknown_26_;
};

// USA: func_ov023_021e4358
extern "C" ARM void func_ov023_021e4358(Struct_ov023_021e4358* obj) {
    if (obj->f4e8 == 1) return;
    short lo, hi;
    void* entry = obj->fcc;
    func_ov023_021e2bdc((char*)obj + 0xd4, 0x20, &lo, &hi);
    if (obj->unknown_634_ & 0x400) {
        lo++;
        hi++;
        obj->unknown_634_ &= ~0x400;
    }
    Struct_ov023_021e4358_2* e = (Struct_ov023_021e4358_2*)entry;
    e->f14 = lo << 12;
    e->f18 = hi << 12;
    e->f22 = 0x7b;
    e->unknown_26_ = 2;
    SpriteContext_DrawSprite(obj->fc8, entry);
}
