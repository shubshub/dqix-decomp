#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

#if !defined(jpn)

int Font_GetKerning(int a, int b, int fontIndex);
extern "C" void func_020654b8(void* obj, void* context, MessageGlyphSlot* glyph, short x, short y, int mode);
extern "C" void func_020417b0(MessageGlyphSlot* glyph, int color, void* palette, int alpha);

extern const int data_020e7a94[];

struct Struct_02045f3c {
    char unknown_0_[0x34];
    void* unknown_34_;
    char unknown_38_[0x980];
    Struct_0204166c unknown_9b8_[0x80];
    char unknown_17b8_[0x1f8];
    unsigned char unknown_19b0_;
};

// USA: func_02045f3c
extern "C" ARM void func_02045f3c(Struct_02045f3c* arg0, unsigned short* arg1, int arg2, int arg3, unsigned short arg4,
                                  int arg5, int arg6, unsigned char arg7, unsigned char arg8, int arg9) {
    if (arg1 == NULL || arg0->unknown_19b0_ == 0 || arg1[0] == 0xffff) {
        return;
    }
    int var0 = 1;
    unsigned short var1 = arg1[0];
    for (int var2 = 1; var2 < 10; var2++) {
        if (var1 != arg1[var2]) {
            var0 = 0;
            break;
        }
    }
    if (var0) {
        return;
    }
    Struct_0204166c* var3;
    int var4;
    int var5;
    unsigned short var6;
    *(volatile int*)0x04000444 = 0;
    int var7 = data_020e7a94[arg8] & 0xff;
    var4 = 0;
    unsigned char var8 = 0xff;
    var6 = arg1[0];
    var5 = arg2;
    while (var6 != 0xff01) {
        var6 = arg1[var4];
        var4++;
        if ((var6 & 0xff00) == 0xff00) {
            if (var6 == 0xff18) {
                var5 = arg2;
                arg3 += arg9;
                var8 = 0xff;
                continue;
            }
            if (var6 == 0xff19) {
                var5 += var7 + 1;
                var8 = 0xff;
                continue;
            }
            break;
        }
        if (var6 >= 0x80) {
            break;
        }
        var3 = &arg0->unknown_9b8_[var6];
        if (var3->unknown_8_ < 0) {
            break;
        }
        unsigned char characterIndex = glyph->characterIndex;
        cx += Font_GetKerning(previousCharacter, characterIndex, fontIndex);
        previousCharacter = characterIndex;
        glyph->x = cx;
        glyph->y = y;
        glyph->depth = 0;
        if (absolute) {
            int mode = 15;
            if (color != 0x7fff) {
                mode = 5;
            }
            func_020654b8(arg0, arg0->unknown_34_, var3, var5, arg3, var10);
        } else {
            func_020417b0(var3, arg4, 0, 31);
        }
        if (glyph->character) {
            cx += glyph->character->width_ + 1;
        }
    }
    *(volatile int*)0x04000448 = 1;
}
#endif
