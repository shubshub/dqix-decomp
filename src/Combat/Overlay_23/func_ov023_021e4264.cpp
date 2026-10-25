#if defined(jpn)
enum {Enum_ov023_021e4264_1588=0x56c};
#else
enum {Enum_ov023_021e4264_1588=0x634};
#endif
#include <globaldefs.h>

void ComputeShortPair_021e2bdc(void* a, int unused, short* out1, short* out2);
extern "C" void SpriteContext_DrawSprite(void* obj, void* entry);

struct Struct_ov023_021e4264 {
    char unknown_0_[0xc8];
    void* unknown_c8_;
    void* unknown_cc_;
    char unknown_d0_[Enum_ov023_021e4264_1588 - 0xd0];
    unsigned short unknown_634_;
};

struct Struct_ov023_021e4264_2 {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[0x22 - 0x1c];
    unsigned char unknown_22_;
    char unknown_23_[0x26 - 0x23];
    unsigned char unknown_26_;
};

// USA: func_ov023_021e4264
extern "C" ARM void func_ov023_021e4264(Struct_ov023_021e4264* arg0) {
    short var0, var1;
    Struct_ov023_021e4264_2* var2 = (Struct_ov023_021e4264_2*)arg0->unknown_cc_;
    func_ov023_021e2bdc((char*)arg0 + 0xd4, 0x11, &var0, &var1);
    if (arg0->unknown_634_ & 0x100) {
        var0--;
        var1++;
    }
    Entry021e4264* e0 = (Entry021e4264*)((char*)entry + 0x50);
    e0->f14 = lo << 12;
    e0->f18 = hi << 12;
    e0->f22 = 0x7f;
    e0->f26 = 2;
    SpriteContext_DrawSprite(obj->fc8, e0);

    var2 = (Struct_ov023_021e4264_2*)arg0->unknown_cc_;
    func_ov023_021e2bdc((char*)arg0 + 0xd4, 0x12, &var0, &var1);
    if (arg0->unknown_634_ & 0x200) {
        var0++;
        var1++;
    }
    Entry021e4264* e1 = (Entry021e4264*)((char*)entry + 0x78);
    e1->f14 = lo << 12;
    e1->f18 = hi << 12;
    e1->f22 = 0x7e;
    e1->f26 = 2;
    SpriteContext_DrawSprite(obj->fc8, e1);
}
