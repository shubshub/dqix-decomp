#if defined(jpn)
#define func_0204f7e8 func_02050cc0
#endif
#include <globaldefs.h>
#include <NitroSDK/Cache.h>
#include <std_library_functions.h>

struct Struct_02050100 {
    char padding[0x1c];
    unsigned char low : 4;
    unsigned char high : 4;
};
struct Struct_02050100_2 {
    int field_0;
    Struct_02050100* unknown_4_;
    char* buffer;
    char unknown_c_[0xa0 - 0xc];
    int offset;
    int unknown_a4_;
    short width, height;
    char unknown_ac_[0xc5 - 0xac];
    unsigned char unknown_c5_;
    char unknown_c6_[0xd8 - 0xc6];
    unsigned char enabled : 1;
    unsigned char dirty : 1;
    unsigned char unused : 6;
    unsigned char unknown_d9_;
    unsigned char unknown_da_;
};
struct Glyph02050100 { int field_0; signed char width; };
extern "C" Glyph02050100* Font_FindCharacter(int, int);
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
extern "C" ARM void func_02050100(Struct_02050100_2* self, int arg1) {
#if defined(jpn)
    unsigned char style;
#endif
    if (!self->enabled) return;
    if (!self->dirty && arg1) return;
    if (!self->unknown_4_ || !self->buffer) return;
    int low = self->unknown_4_->low;
    int high = self->unknown_4_->high;
    if (arg1) {
        char* source = func_02050064(self);
        if (!source) return;
        if (source) memcpy(self->buffer, source + self->offset, self->unknown_a4_);
    }
#if defined(jpn)
    short y = (short)((short)(self->height << 3) - 12);
    short center = (short)((short)(self->width << 3) / 2);
    if (self->unknown_c5_ & 0x10) y -= 3;
    short var6 = 0, outHeight = 0;
    short x;
    signed char counter = (signed char)self->unknown_da_;
    int digits = 2;
    while (counter != 0) { counter = (signed char)(counter + 1) / 10; }
    if (counter > 2) digits = counter;
    style = 1;
    if (self->unknown_c5_ & 4) style = 0;
    x = center - 8 - digits * 8;
    int bottom = y + 8;
    func_0204f914(self, style, x, y, x + digits * 8 + 1, bottom);
    unsigned char var12 = digits;
    func_0204f7e8(self, x, y, self->unknown_d9_ + 1, 8, 15, &var6, &outHeight, 1, var12, 0, 0);
    x = center + 8;
    func_0204f914(self, style, x, y, x + digits * 8 + 1, bottom);
    func_0204f7e8(self, x, y, self->unknown_da_, 8, 15, &var6, &outHeight, 0, var12, 0, 0);
    func_02050678(self, center - 4, y, data_020f0336, 8, 15, &var6, &outHeight);
#else
    short y = (short)((short)(self->height << 3) - 13);
    short center = (short)((short)(self->width << 3) / 2);
    if (self->unknown_c5_ & 0x10) y -= 3;
    short var15 = 0, outHeight = 0;
    short left;
    int style;
    int glyphWidth;
    signed char counter = (signed char)self->unknown_da_;
    int digits = 2;
    while (counter != 0) { counter = (signed char)(counter + 1) / 10; }
    if (counter > 2) digits = counter;
    style = 1;
    if (self->unknown_c5_ & 4) style = 0;
    glyphWidth = 0;
    Glyph02050100* glyph = Font_FindCharacter((int)data_020e7bda, glyphWidth);
    if (glyph) glyphWidth = glyph->width;
    short var23 = center - (glyphWidth >> 1);
    func_0204f41c(self, var23, y, data_020e7bda, 8, 15, &var15, &outHeight, 0);
    left = center - glyphWidth;
    int bottom = y + 9;
    func_0204f914(self, style, left - 14, y, left, bottom);
    unsigned char var25 = digits;
    func_0204f7e8(self, left, y, self->unknown_d9_ + 1, 8, 15, &var15, &outHeight, 1, var25, 0, 0);
    short right = center + glyphWidth;
    func_0204f914(self, style, right, y, right + 14, bottom);
    func_0204f7e8(self, right + 1, y, self->unknown_da_, 8, 15, &var15, &outHeight, 0, var25, 0, 0);
#endif
    if (arg1) {
        Type_02050100 var27 = func_0204a5e4(low, high);
        CleanInvalidateCacheRange(self->buffer, self->unknown_a4_);
        var27(self->buffer, self->offset, self->unknown_a4_);
    }
    self->dirty = 0;
}
