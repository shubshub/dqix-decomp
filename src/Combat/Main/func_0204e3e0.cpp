#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_0204e3e0_2 {
    char unknown_0_[0xa4];
    int unknown_a4_;
    short unknown_a8_;
    short unknown_aa_;
    char unknown_ac_[4];
    short unknown_b0_;
    short unknown_b2_;
    char unknown_b4_[2];
    short unknown_b6_;
};

struct Struct_0204e3e0 {
    int unknown_0_;
    char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
};

extern "C" void* __clear(void* dst, int count);
extern "C" int Font_GetTextWidth(char* str, int id);
int Font_FindCharacterIndex(int key, int tableIdx);
char* FindUnescapedAngleBracket_020424ac(char* str);
Glyph0204e3e0* Font_GetCharacter(int idx, int tableIdx);
int Font_GetKerning(int a, int b, int tableIdx);
extern "C" int func_0204fc40(void* unused0, char** cursor, char* tag, short* out, int max);
extern const unsigned char data_020e7bd6[];
extern char data_020f0248[];
extern char data_020f024e[];
extern char data_020f0251[];
extern char data_020f0254[];
extern char data_020f0258[];
extern char data_020f025b[];
extern char data_020f025e[];
extern char data_020f0298[];
extern char data_020f02d4[];
extern char data_020f02db[];
extern char data_020f02e7[];
extern char data_020f02eb[];
extern char data_020f02f1[];

// USA: func_0204e3e0
extern "C" ARM short func_0204e3e0(Struct_0204e3e0_2* arg0, char* arg1, int arg2, unsigned char arg3, unsigned char arg4, unsigned char arg5) {
    int var0;
    int var1, var2, var3, var4;
    short var5;
    int var6;
    bool var7;
    short var8;
    int var9;
    int var10;
    char* var11;
    char* var12;
    char* var13;
    short var14[8];
    char var15[0x100];
    unsigned char var16;
    Struct_0204e3e0* var17;

    var12 = arg1;
    if (var12 == 0) return 0;

    var3 = arg0->unknown_b0_;
    var4 = arg0->unknown_b2_;
    var7 = 0;
    var0 = 0;
    var8 = 0;
    var10 = arg0->unknown_b6_;
    var1 = arg0->unknown_b0_;
    var2 = arg0->unknown_b2_;
    var5 = 0xff;

    while (*var12 != 0) {
        char var18 = *var12;
        char var19 = var12[1];
        if ((var18 == '\\' && var19 == 'n') || (var18 == '\r' && var19 == '\n')) {
            if (var3 < var1) var3 = var1;
            var1 = arg0->unknown_b0_;
            var2 += arg0->unknown_b6_;
            var12 += 2;
            var5 = 0xff;
            continue;
        }
        if (var18 == '\n') {
            if (var3 < var1) var3 = var1;
            var1 = arg0->unknown_b0_;
            var2 += arg0->unknown_b6_;
            var12 += 1;
            var5 = 0xff;
            continue;
        }
        int idx = Font_FindCharacterIndex((int)cursor, font);
        if (*cursor == '<' && idx < 0) {
            p = cursor + 1;
            end = FindUnescapedAngleBracket_020424ac(cursor);
            if (func_0204fc40(wnd, &p, data_020f0248, out, 1)) {
            } else if (func_0204fc40(wnd, &p, data_020f024e, out, 1)) {
                if (maxX < x) maxX = x;
                x = out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0251, out, 1)) {
                if (maxY < y) maxY = y;
                y = out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0254, out, 2)) {
                if (maxX < x) maxX = x;
                if (maxY < y) maxY = y;
                x = out[0];
                y = out[1];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0258, out, 1)) {
                x += out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f025b, out, 1)) {
                y += out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f025e, out, 2)) {
                x += out[0];
                y += out[1];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0298, out, 1)) {
                ret = out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02d4, out, 1)) {
                boxOn = 1;
                boxY = out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02db, out, 0)) {
                if (boxOn) {
                    if (maxX < x) maxX = x;
                    if (maxY < y) maxY = y;
                    x = wnd->fB0;
                    y = boxY + wnd->fB2;
                }
            } else if (func_0204fc40(wnd, &p, data_020f02e7, out, 1)) {
                if (maxX < x) maxX = x;
                x = out[0];
                prev = 0xff;
                savedX = x;
                __clear(tmp, 0x100);
                char* start = p;
                char* found = strstr(start, data_020f02eb);
                if (found != 0) {
                    int len = found - start;
                    if (len < 0x100) {
                        memcpy(tmp, start, len);
                        x -= Font_GetTextWidth(tmp, font);
                    }
                }
            } else if (func_0204fc40(arg0, &var13, data_020f02f1, var14, 0)) {
                if (var3 < var1) var3 = var1;
                var1 = var9;
                var5 = 0xff;
            }
            var12 = var11 + 1;
            continue;
        }
        adv = data_020e7bd6[font] + 1;
        if (idx >= 0) {
            code = idx & 0xff;
            glyph = Font_GetCharacter(idx, font);
            int kern = Font_GetKerning(prev, code, font);
            prev = code;
            adv = glyph->width + 1 + kern;
            cursor += glyph->skip;
        } else {
            var12++;
        }
        var1 += var16;
    }

    if (var1 < var3) var1 = var3;
    if (var2 < var4) var2 = var4;
    var2 = var2 + var10 - (arg0->unknown_b6_ - 10);
    if (((var1 + 3) & 7) <= 3) var1 += 4;
    int var25 = ((var1 + 7) & ~7) >> 3;
    int var26 = ((var2 + 7) & ~7) >> 3;
    if (var25 > 32) var25 = 32;
    if (var26 > 32) var26 = 32;
    if (arg4) {
        if (arg0->unknown_a8_ < var25) arg0->unknown_a8_ = var25;
        if (arg0->unknown_aa_ < var26) arg0->unknown_aa_ = var26;
    }
    if (arg3) {
        var2 -= arg0->unknown_b2_;
        if ((arg0->unknown_aa_ << 3) - var2 < 7) arg0->unknown_aa_ = arg0->unknown_aa_ + 1;
        arg0->unknown_b2_ = ((arg0->unknown_aa_ << 3) - var2) >> 1;
    }
    if (var7) {
        arg0->unknown_b2_ = arg0->unknown_b2_ + var0;
        if (arg3) arg0->unknown_b2_ = arg0->unknown_b2_ - 1;
    }
    arg0->unknown_a4_ = (arg0->unknown_a8_ * arg0->unknown_aa_) << 5;
    return var8;
}
