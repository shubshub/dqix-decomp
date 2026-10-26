#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020947f0_836 = 0x104, regionalState = 0x138 };
#else
enum { Enum_020947f0_836 = 0x344, regionalState = 0x3c8 };
#endif

struct Struct_020947f0 {
    char pad0[Enum_020947f0_836];
    float phase;
    char unknown_348_[regionalState - Enum_020947f0_836 - 4];
    unsigned char state : 7;
    unsigned char display : 1;
};
struct Struct_02094654_2 { unsigned int attributes01; unsigned short unknown_4_; };
extern "C" double func_02009424(double);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainObjStandardPalette(const void*, unsigned int, unsigned int);
extern "C" void LoadToSubObjStandardPalette(const void*, unsigned int, unsigned int);
extern "C" int func_0209378c(int);
extern "C" unsigned int func_020937f0(int);
extern "C" Struct_02094654_2* func_02093704(int);
extern "C" void func_020946f8(Struct_02094654_2*, int, int, int, int, int, int, int, int, int, int, int);

// USA: func_020947f0
extern "C" ARM void func_020947f0(Struct_020947f0* animation) {
    float amount = (float)func_02009424((double)animation->phase);
    amount += 1.0f;
    amount *= 0.5f;
    short var1 = (short)(31.0f * amount);
    if (var1 < 0) var1 = 0;
    if (var1 > 31) var1 = 31;
    unsigned short color = var1 | (var1 << 5) | (var1 << 10);
    CleanInvalidateCacheRange(&color, 2);
    if (animation->display == 0) LoadToMainObjStandardPalette(&color, 0x1fe, 2);
    else LoadToSubObjStandardPalette(&color, 0x1fe, 2);
    int shift = func_0209378c(animation->display);
    unsigned int size = func_020937f0(animation->display);
    if (size) {
        unsigned int tile = (size - 0x800) >> shift;
        int stride = 0x100 >> shift;
        Struct_02094654_2* entries = func_02093704(animation->display);
        int x = 0;
        for (unsigned char i = 0; i < 8; ++i) {
            func_020946f8(entries + (i + 5), x, 0, 0, 0, 0, 0, 0x80004000, 0, tile, 15, 0);
            tile += stride;
            x += 32;
        }
    }
}
