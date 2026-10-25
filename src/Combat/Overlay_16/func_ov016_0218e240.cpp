#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_ov016_0218e240 {
    int unknown_0_;
    signed char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};

extern "C" char data_ov016_0219d06d[];
extern "C" char data_ov016_0219d06f[];

int GetWordFromTable02042648(int idx);
int Font_FindCharacterIndex(int key, int tableIdx);
struct Glyph0218e240* Font_GetCharacter(int idx, int tableIdx);
int LookupKeyValue020425e4(int a, int b, int tableIdx);
extern "C" void* __clear(void* dst, int count);
extern "C" int Font_GetTextWidth(char* str, int id);
extern "C" int memcmp(unsigned char* a, unsigned char* b, int n);
extern "C" void func_ov016_0218e17c(unsigned short* dst, int x, int y, void* glyph, int color, int fontId);

// USA: func_ov016_0218e240
extern "C" ARM void func_ov016_0218e240(unsigned short* arg0, char* arg1, unsigned short arg2, int arg3, int arg4, unsigned char arg5, unsigned short arg6, int arg7) {
    int var0 = 0;
    int var1 = arg3;
    struct Struct_ov016_0218e240* var2;
    int var3;
    int var4 = arg4;
    short var5 = 0xff;
    int var6 = func_02042648(1) & 0xff;
    int var7;
    int var8[3];
    var8[0] = var1;
    var8[1] = var1;
    var8[2] = var1;

    if (arg5 != 0) {
        int var9 = 1;
        char* var10 = strstr(arg1, data_ov016_0219d06d);
        if (var10 == 0) {
            var10 = strstr(arg1, data_ov016_0219d06f);
            var9 = 2;
        }
        if (hit != 0) {
                        int off = hit - text;
            char buf[0x200];
            __clear(buf, 0x200);
            sprintf(buf, text);
            memset(buf + off, 0, len);
            xs[0] = (0x100 - Font_GetTextWidth(buf, 1)) >> 1;
            xs[1] = (0x100 - Font_GetTextWidth(buf + (off + len), 1)) >> 1;
            y -= 0xe;
        } else {
            xs[0] = (0x100 - Font_GetTextWidth(text, 1)) >> 1;
        }
    }

    var3 = 0;
    var1 = var8[var3];
    var3++;

    for (;;) {
        if (count <= i) break;
        if (text[0] == 0) break;
        int step = 1;
                int ctrl = (text[0] == '\n') ? step : 0;
        if (memcmp((unsigned char*)text, (unsigned char*)data_ov016_0219d06f, 2) == 0) {
                        ctrl = 1; 1;
            step = 2;
        }
        if (var14 != 0) {
            var1 = var8[var3];
            arg1 += var13;
            var3++;
            var5 = 0xff;
            var4 += 0xe;
            continue;
        }

                int wide = font + 1;
        adv = 1;
        unsigned char code = Font_FindCharacterIndex((int)text, 1);
        if (code != 0xff) {
                        glyph = Font_GetCharacter(code, 1);
            if (outline != 0) {
                func_ov016_0218e17c(dst, x - 1, y, glyph, 0, 1);
                func_ov016_0218e17c(dst, x + 1, y, glyph, 0, 1);
                func_ov016_0218e17c(dst, x, y - 1, glyph, 0, 1);
                func_ov016_0218e17c(dst, x, y + 1, glyph, 0, 1);
            }
            var1 += func_020425e4(var5, var16, 1);
            func_ov016_0218e17c(arg0, var1, var4, var2, arg2, 1);
            var5 = var16;
                        var15 = var2->unknown_4_ + 1;
            var7 = var2->unknown_5_0_;
        } else {
            var5 = 0xff;
        }
        var1 += var15;
        arg1 += var7;
        var0++;
    }
}
