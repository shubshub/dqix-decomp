#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

bool IsHighByteFF02044494(void* obj, void* src);
int Font_GetKerning(int a, int b, int fontIndex);

extern int data_020e7a94[];

struct Struct_02046170 {
    char unknown_0_[0x9b8];
    Struct_0204166c unknown_9b8_[0x80];
};

#if defined(jpn)
enum Enum_02046f80 { Enum_02046f80_65281 = 0xff01 };

enum Enum_02046f80_B {
    Enum_02046f80_B_33 = 0x21, Enum_02046f80_B_34, Enum_02046f80_B_35, Enum_02046f80_B_36, Enum_02046f80_B_37, Enum_02046f80_B_38
};
// USA: func_02046170
extern "C" ARM int func_02046f80(void* arg0, int arg1, unsigned short* arg2, int arg3) {
    if (arg2 == 0) return 0;
    if (arg3 < 0) return 0;
    int var0;
    switch (arg1) {
    case 10: var0 = 10; break;
    case 12: var0 = 12; break;
    default: return 0;
    }
    Enum_02046f80 var1 = Enum_02046f80_65281;
    int var2 = 0;
    int var3 = 0;
    for (int var4 = 0; var4 < arg3; var4++) {
        unsigned short var5 = arg2[var4];
        if (var5 == var1) break;
        if (var5 == var1 + 0x17 || var5 == var1 + 9 || var5 == var1 + 0x1b ||
            var5 == var1 + 0x1e || var5 == var1 + 0x1f || var5 == var1 + 0x20 ||
            var5 == var1 + 3 || var5 == var1 + 4 || var5 == var1 + 5 || var5 == var1 + 6) {
        } else if (var5 == var1 + 0x1a) {
            var2 += var0 >> 1;
        } else if (var5 == var1 + Enum_02046f80_B_33) {
            ++var4;
            if (var3 < arg2[var4]) var3 = arg2[var4];

            int var6 = var2;
            var2 = var3;
            var3 = var6;
        } else if (var5 == var1 + Enum_02046f80_B_34) {
            ++var4;
        } else if (var5 == var1 + Enum_02046f80_B_35) {
            unsigned short var7 = arg2[var4 + 1];
            var4 += 2;
            if (var3 < var7) var3 = var7;
            int var8 = var2;
            var2 = var3;
            var3 = var8;
        } else if (var5 == var1 + Enum_02046f80_B_36) {
            unsigned short var9 = arg2[var4 + 1];

            var4 += 2;
            var2 += var9;
        } else if (var5 == var1 + Enum_02046f80_B_37) {
            ++var4;
        } else if (var5 == var1 + Enum_02046f80_B_38) {
            unsigned short var10 = arg2[var4 + 1];
            var4 += 2;
            var2 += var10;
        } else {
            var2 += var0;
        }
    }
    if (var2 < var3) var2 = var3;
    return var2;
}
#else
// USA: func_02046170
extern "C" ARM int func_02046170(struct Struct_02046170* arg0, unsigned short* arg1, int arg2,
                                 int arg3) {
    if (arg1 == 0) return 0;
    if (arg2 < 0) return 0;

    int var0 = data_020e7a94[arg3] & 0xff;
    int var1 = 0;
    int var2 = 0;
    int var3 = 0xff;

    for (int var4 = 0; var4 < arg2; var4++) {
        unsigned short var5 = arg1[var4];
        if (var5 == 0xff01) break;
        if (var5 == 0xff18) {
            if (var2 < var1) var2 = var1;
            var1 = 0;
            var3 = 0xff;
        } else if (var5 == 0xff19) {
            var3 = 0xff;
            var1 += var0 + 1;
        } else if (func_02044494(arg0, &var5)) {
            var3 = 0xff;
        } else {
            MessageGlyphSlot* slot = &window->glyphs[command];
            int characterIndex = slot->characterIndex;
            currentExtent += Font_GetKerning(previousCharacter, characterIndex, fontIndex);
            previousCharacter = characterIndex;
            int glyphWidth = fallbackGlyphWidth;
            if (slot->character != 0) glyphWidth = slot->character->width_;
            currentExtent += glyphWidth + 1;
        }
    }

    if (var1 < var2) var1 = var2;
    return var1;
}
#endif
