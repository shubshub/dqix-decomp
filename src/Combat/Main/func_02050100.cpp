#if defined(jpn)
#define func_0204f7e8 func_02050cc0
#endif
#include <globaldefs.h>
#include <NitroSDK/Cache.h>
#include <std_library_functions.h>

struct Struct_02050100 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
};
struct Struct_02050100_2 {
    int unknown_0_;
    Struct_02050100* unknown_4_;
    char* unknown_8_;
    char unknown_c_[0xa0 - 0xc];
    int unknown_a0_;
    int unknown_a4_;
    short unknown_a8_, unknown_aa_;
    char unknown_ac_[0xc5 - 0xac];
    unsigned char unknown_c5_;
    char unknown_c6_[0xd8 - 0xc6];
    unsigned char unknown_d8_0_ : 1;
    unsigned char unknown_d8_1_ : 1;
    unsigned char unknown_d8_2_ : 6;
    unsigned char unknown_d9_;
    unsigned char unknown_da_;
};
struct Glyph02050100 { int field_0; signed char width; };
Glyph02050100* Font_FindCharacter(int, int);
extern char data_020e7bda[];
extern "C" char* func_02050064(Struct_02050100_2*);
extern "C" void func_0204f41c(Struct_02050100_2*, short, short, char*, int, int, short*, short*, int);
extern "C" void func_0204f914(Struct_02050100_2*, int, short, short, short, short);
extern "C" void func_0204f7e8(Struct_02050100_2*, short, short, int, unsigned char, unsigned char, short*, short*, unsigned char, unsigned char, unsigned char, unsigned char);
typedef void (*Type_02050100)(void*, int, unsigned int);
extern "C" Type_02050100 func_0204a5e4(int, int);
#if defined(jpn)
extern char data_020f0336[];
extern "C" void func_02050678(Struct_02050100_2*, short, short, char*, int, int, short*, short*);
#endif

// USA: func_02050100
extern "C" ARM void func_02050100(Struct_02050100_2* arg0, int arg1) {
#if defined(jpn)
    unsigned char var0;
#endif
    if (!arg0->unknown_d8_0_) return;
    if (!arg0->unknown_d8_1_ && arg1) return;
    if (!arg0->unknown_4_ || !arg0->unknown_8_) return;
    int var1 = arg0->unknown_4_->unknown_1c_0_;
    int var2 = arg0->unknown_4_->unknown_1c_4_;
    if (arg1) {
        char* var3 = func_02050064(arg0);
        if (!var3) return;
        if (var3) memcpy(arg0->unknown_8_, var3 + arg0->unknown_a0_, arg0->unknown_a4_);
    }
#if defined(jpn)
    short var4 = (short)((short)(arg0->unknown_aa_ << 3) - 12);
    short var5 = (short)((short)(arg0->unknown_a8_ << 3) / 2);
    if (arg0->unknown_c5_ & 0x10) var4 -= 3;
    short var6 = 0, var7 = 0;
    short var8;
    signed char var9 = (signed char)arg0->unknown_da_;
    int var10 = 2;
    while (var9 != 0) { var9 = (signed char)(var9 + 1) / 10; }
    if (var9 > 2) var10 = var9;
    var0 = 1;
    if (arg0->unknown_c5_ & 4) var0 = 0;
    var8 = var5 - 8 - var10 * 8;
    int var11 = var4 + 8;
    func_0204f914(arg0, var0, var8, var4, var8 + var10 * 8 + 1, var11);
    unsigned char var12 = var10;
    func_0204f7e8(arg0, var8, var4, arg0->unknown_d9_ + 1, 8, 15, &var6, &var7, 1, var12, 0, 0);
    var8 = var5 + 8;
    func_0204f914(arg0, var0, var8, var4, var8 + var10 * 8 + 1, var11);
    func_0204f7e8(arg0, var8, var4, arg0->unknown_da_, 8, 15, &var6, &var7, 0, var12, 0, 0);
    func_02050678(arg0, var5 - 4, var4, data_020f0336, 8, 15, &var6, &var7);
#else
    short y = (short)((short)(self->height << 3) - 13);
    short center = (short)((short)(self->width << 3) / 2);
    if (self->options & 0x10) y -= 3;
    short outWidth = 0, outHeight = 0;
    short left;
    int style;
    int glyphWidth;
    signed char counter = (signed char)self->lastValue;
    int digits = 2;
    while (counter != 0) { counter = (signed char)(counter + 1) / 10; }
    if (counter > 2) digits = counter;
    style = 1;
    if (self->options & 4) style = 0;
    glyphWidth = 0;
    Glyph02050100* glyph = Font_FindCharacter((int)data_020e7bda, glyphWidth);
    if (glyph) glyphWidth = glyph->width;
    short labelX = center - (glyphWidth >> 1);
    func_0204f41c(self, labelX, y, data_020e7bda, 8, 15, &outWidth, &outHeight, 0);
    left = center - glyphWidth;
    int bottom = y + 9;
    func_0204f914(self, style, left - 14, y, left, bottom);
    unsigned char displayDigits = digits;
    func_0204f7e8(self, left, y, self->currentValue + 1, 8, 15, &outWidth, &outHeight, 1, displayDigits, 0, 0);
    short right = center + glyphWidth;
    func_0204f914(self, style, right, y, right + 14, bottom);
    func_0204f7e8(self, right + 1, y, self->lastValue, 8, 15, &outWidth, &outHeight, 0, displayDigits, 0, 0);
#endif
    if (arg1) {
        Type_02050100 var27 = func_0204a5e4(var1, var2);
        CleanInvalidateCacheRange(arg0->unknown_8_, arg0->unknown_a4_);
        var27(arg0->unknown_8_, arg0->unknown_a0_, arg0->unknown_a4_);
    }
    arg0->unknown_d8_1_ = 0;
}
