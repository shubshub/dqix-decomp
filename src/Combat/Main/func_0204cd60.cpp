#include <globaldefs.h>
#include <std_library_functions.h>
#include <NitroSDK/BGBases.h>

struct Wnd0204cd60 {
    char pad0[8];
    unsigned char* buf;
    short arrA[18];
    short arrB[18];
    short arrC[18];
    short arrD[18];
    char pad9C[4];
    int fA0;
    int fA4;
    short fA8;
    short fAA;
    char padAC[4];
    short fB0;
    short fB2;
    char padB4[2];
    short fB6;
    char padB8[2];
    short sizeTagLineHeight_;
    short fBC;
    short fBE;
    char padC0[5];
    unsigned char flags;
    unsigned char fC6;
    unsigned char fC7;
    char padC8[0x10];
    unsigned char bit0 : 2;
    unsigned char useBg : 1;
    unsigned char bit3 : 5;
    char padD9[2];
    signed char margins[4];
};

struct Struct_0204cd60_2 {
    int unknown_0_;
    char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};

extern "C" void* __clear(void* dst, int count);
extern "C" int Font_GetTextWidth(char* str, int id);
int Font_FindCharacterIndex(int key, int tableIdx);
Glyph0204cd60* Font_GetCharacter(int idx, int tableIdx);
int Font_GetKerning(int a, int b, int tableIdx);
extern "C" void func_0204cc68(Wnd0204cd60* wnd, int mode, short x0, short y0, short x1, short y1);
extern "C" void func_0204f914(Wnd0204cd60* wnd, int mode, short x0, short y0, short x1, short y1);
extern "C" void func_0204ea5c(Wnd0204cd60* wnd);
extern "C" void func_0204ecb4(Wnd0204cd60* wnd, int a, int b, int w, int h, signed char* margins);
extern "C" int func_0204fc40(void* unused0, char** cursor, char* tag, short* out, int max);
extern "C" void func_0204f3bc(Wnd0204cd60* wnd, int idx);
extern "C" void func_0204df9c(Wnd0204cd60* wnd, Glyph0204cd60* glyph, int x, int y, int color, int font);
extern "C" void func_0204fae8(Wnd0204cd60* wnd);
extern "C" void func_0204fa0c(Wnd0204cd60* wnd, short x, short y);

extern const unsigned char data_020e7bdc[];
extern char data_020f0248[];
extern char data_020f024e[];
extern char data_020f0251[];
extern char data_020f0254[];
extern char data_020f0258[];
extern char data_020f025b[];
extern char data_020f025e[];
extern char data_020f0262[];
extern char data_020f0268[];
extern char data_020f026f[];
extern char data_020f0276[];
extern char data_020f027c[];
extern char data_020f0283[];
extern char data_020f0288[];
extern char data_020f028c[];
extern char data_020f0292[];
extern char data_020f0298[];
extern char data_020f029d[];
extern char data_020f02a0[];
extern char data_020f02a3[];
extern char data_020f02aa[];
extern char data_020f02b1[];
extern char data_020f02b9[];
extern char data_020f02bd[];
extern char data_020f02c1[];
extern char data_020f02c5[];
extern char data_020f02c9[];
extern char data_020f02cf[];
extern char data_020f02d4[];
extern char data_020f02db[];
extern char data_020f02e2[];
extern char data_020f02e7[];
extern char data_020f02eb[];
extern char data_020f02f1[];

static inline void inline_01ff8b48(Struct_0204cd60* arg0, short arg1, short arg2) {
    arg0->unknown_bc_ = arg1;
    arg0->unknown_be_ = arg2;
}

// USA: func_0204cd60
extern "C" ARM void func_0204cd60(Struct_0204cd60* arg0, char* arg1, short arg2, short arg3) {
    char* var0;
    short var1[8];
    char var2[0x100];
    int var3;
    short var4;
    short var5;
    unsigned char* var6;
    short var7;
    unsigned char* var8;
    short var9;
    Struct_0204cd60_2* var10;
    unsigned char var11;
    int var12;
    int var13;
    short var14;
    short var15;
    short var16;
    short var17, var18, var19, var20, var21, var22;
    int var23;
    int var24, var25, var26, var27;
    int var28;
    short var29, var30, var31, var32;
    int var33;
    short var34;
    short var35;
    int var36;
    int var37, var38, var39, var40;
    int var41;
    short var42, var43, var44, var45;
    short var46, var47, var48, var49;
    unsigned char var50;
    int var51;
    char* var52;

    var52 = arg1;
    if (var52 == 0) return;

    var14 = 0;
    var11 = 0xff;
    arg0->unknown_c5_ &= ~2;
    var13 = -1;
    var7 = (arg0->unknown_a8_ << 3) >> 1;
    var35 = arg0->unknown_b6_;
    var9 = var35 * var7;
    var5 = arg0->unknown_b2_;
    var8 = arg0->unknown_8_;
    var6 = var8 + var5 * var7;
    var15 = var14;
    var16 = var14;
    var17 = var14;
    var18 = var14;
    var19 = var14;
    var20 = var14;
    var21 = var14;
    var22 = var14;
    var28 = var27 = var23 = var26 = var25 = var24 = var13;
    var29 = var14;
    var30 = var14;
    var31 = var14;
    var32 = var14;
    var3 = var13;
    var33 = arg0->unknown_c7_;
    var4 = arg0->unknown_b0_;

    if (arg0->unknown_d8_2_) {
        memcpy(arg0->unknown_8_, (char*)GetSubBG2CharacterBase() + arg0->unknown_a0_, arg0->unknown_a4_);
    } else {
        memset(arg0->unknown_8_, 0, arg0->unknown_a4_);
    }

    if (arg0->unknown_c5_ & 4) {
        var36 = 0;
    } else {
        if (!arg0->unknown_d8_2_) {
            short var53 = 0;
            short var54 = 0;
            short var55 = arg0->unknown_a8_ << 3;
            short var56 = arg0->unknown_aa_ << 3;
            var54 += arg0->unknown_db_[0];
            var56 -= arg0->unknown_db_[0] + arg0->unknown_db_[1];
            var53 += arg0->unknown_db_[2];
            var55 -= arg0->unknown_db_[2] + arg0->unknown_db_[3];
            func_0204f914(arg0, 0x11, var53, var54, var55, var56);
            func_0204ea5c(arg0);
        }
        var36 = 0x11;
    }

    if (arg2 > 0) {
        short var57 = arg0->unknown_a8_ << 3;
        short var58 = arg0->unknown_aa_ << 3;
        func_0204cc68(arg0, 3, 0, 0, var57, var58);
        func_0204cc68(arg0, var36, (int)arg2, (int)arg2, var57 - arg2, var58 - arg2);
    } else if (!(arg0->unknown_c5_ & 0x10)) {
        func_0204ecb4(arg0, 0, 0, arg0->unknown_a8_, arg0->unknown_aa_, arg0->unknown_db_);
    }

    var37 = 0xf0;
    var38 = 0xf;
    var39 = var37;
    var40 = var38;

    while ((var51 = *var52) != 0) {
        int var59 = var52[1];
        if ((var51 == '\\' && var59 == 'n') || (var51 == '\r' && var59 == '\n')) {
            var5 += var35;
            var4 = arg0->unknown_b0_;
            var52 += 2;
            var6 += var9;
            continue;
        }
        if (var51 == '\n') {
            var5 += var35;
            var4 = arg0->unknown_b0_;
            var52 += 1;
            var6 += var9;
            continue;
        }
        if (var51 == '<') {
            var41 = 1;
            var0 = var52 + 1;
            if (func_0204fc40(arg0, &var0, data_020f0248, var1, 1)) {
                switch (var1[0]) {
                case 8:
                    var33 = 8;
                    var35 = 9;
                    break;
                case 12:
                    var33 = 12;
                    var35 = 13;
                    break;
                default:
                    var33 = 10;
                    var35 = arg0->unknown_b6_;
                    break;
                }
                if (wnd->sizeTagLineHeight_ != 0) lineH = wnd->sizeTagLineHeight_;
            } else if (func_0204fc40(wnd, &p, data_020f024e, out, 1)) {
                x = out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0251, out, 1)) {
                y = out[0];
                dst = buf + pitch * y;
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0254, out, 2)) {
                y = out[1];
                x = out[0];
                dst = buf + pitch * y;
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0258, out, 1)) {
                x += out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f025b, out, 1)) {
                dst += pitch * out[0];
                y += out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f025e, out, 2)) {
                x += out[0];
                y += out[1];
                dst += pitch * out[1];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0262, out, 1)) {
                func_0204f3bc(wnd, out[0]);
            } else if (func_0204fc40(wnd, &p, data_020f0268, out, 4)) {
                func_0204cc68(wnd, (unsigned char)out[0], out[1], out[3], out[2], out[3] + 1);
            } else if (func_0204fc40(wnd, &p, data_020f026f, out, 4)) {
                func_0204cc68(wnd, (unsigned char)out[0], out[1], out[2], out[1] + 1, out[3]);
            } else if (func_0204fc40(wnd, &p, data_020f0276, out, 0)) {
                color = 0xf0;
                colorIdx = 0xf;
            } else if (func_0204fc40(wnd, &p, data_020f027c, out, 0)) {
                color = 0xd0;
                colorIdx = 0xd;
            } else if (func_0204fc40(wnd, &p, data_020f0283, out, 0)) {
                color = 0xb0;
                colorIdx = 0xb;
            } else if (func_0204fc40(wnd, &p, data_020f0288, out, 0)) {
                color = 0x90;
                colorIdx = 0x9;
            } else if (func_0204fc40(wnd, &p, data_020f028c, out, 1)) {
                out[0] &= 0xf;
                color = (unsigned char)(out[0] << 4);
                colorIdx = (unsigned char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f0292, out, 5)) {
                func_0204cc68(wnd, (unsigned char)out[0], out[1], out[2], out[1] + out[3], out[2] + out[4]);
            } else if (func_0204fc40(wnd, &p, data_020f0298, out, 1)) {
            } else if (func_0204fc40(wnd, &p, data_020f029d, out, 1)) {
                sel = out[0];
                if (sel >= 0 && sel < 18) {
                    wnd->arrA[sel] = x;
                    wnd->arrB[sel] = y;
                }
                if (var3 >= 0 && var3 == var13) {
                    var39 = var37;
                    var40 = var38;
                    var37 = 0xe0;
                    var38 = 0xe;
                } else if (var3 >= 0 && var3 == var28) {
                    var39 = var37;
                    var40 = var38;
                    var37 = 0x50;
                    var38 = 0x5;
                }
            } else if (func_0204fc40(arg0, &var0, data_020f02a0, var1, 0)) {
                if (var3 >= 0) {
                    if (var3 == var13 || var3 == var28) {
                        var37 = var39;
                        var38 = var40;
                    }
                }
                if (var3 >= 0 && var3 < 18) {
                    arg0->unknown_54_[var3] = var4 - arg0->unknown_c_[var3];
                    arg0->unknown_78_[var3] = var33 + (var5 - arg0->unknown_30_[var3]) + 1;
                    if (arg0->unknown_54_[var3] < 4) arg0->unknown_54_[var3] = 4;
                }
                if (var28 >= 0 && var3 == var28) {
                    if (!(arg0->unknown_c5_ & 0x10) && (var24 >= 0 || var25 >= 0 || var26 >= 0 || var27 >= 0)) {
                        arg0->unknown_c_[var3] -= var29 + arg0->unknown_c6_;
                        arg0->unknown_30_[var3] -= var30;
                        arg0->unknown_54_[var3] += var29 + var31;
                        arg0->unknown_78_[var3] += var30 + var32;
                    }
                    arg0->unknown_c5_ |= 2;
                }
                if (!(arg0->unknown_c5_ & 0x10) && var17 != 0) {
                    arg0->unknown_54_[var3] = var18;
                    var42 = arg0->unknown_c_[var3];
                    var43 = arg0->unknown_54_[var3];
                    var44 = arg0->unknown_30_[var3];
                    var45 = arg0->unknown_78_[var3];
                    var46 = var42 - var19;
                    var47 = var21 + (var42 + var43);
                    var48 = var44 - var20;
                    var49 = var22 + (var44 + var45);
                    func_0204cc68(arg0, 3, var46 + 1, var48, var47 - 1, var48 + 1);
                    func_0204cc68(arg0, 3, var46 + 1, var49 - 1, var47 - 1, var49);
                    func_0204cc68(arg0, 3, var46, var48 + 1, var46 + 1, var49 - 1);
                    func_0204cc68(arg0, 3, var47 - 1, var48 + 1, var47, var49 - 1);
                }
                var3 = -1;
            } else if (func_0204fc40(arg0, &var0, data_020f02a3, var1, 2)) {
            } else if (func_0204fc40(arg0, &var0, data_020f02aa, var1, 5)) {
                var28 = var1[0];
                var29 = var1[1];
                var30 = var1[2];
                var31 = var1[3];
                var32 = var1[4];
            } else if (func_0204fc40(arg0, &var0, data_020f02b1, var1, 1)) {
                var23 = var1[0];
            } else if (func_0204fc40(arg0, &var0, data_020f02b9, var1, 3)) {
                var24 = (signed char)var1[0];
            } else if (func_0204fc40(arg0, &var0, data_020f02bd, var1, 3)) {
                var25 = (signed char)var1[0];
            } else if (func_0204fc40(arg0, &var0, data_020f02c1, var1, 3)) {
                var26 = (signed char)var1[0];
            } else if (func_0204fc40(arg0, &var0, data_020f02c5, var1, 3)) {
                var27 = (signed char)var1[0];
            } else if (func_0204fc40(arg0, &var0, data_020f02c9, var1, 5)) {
                var17 = 1;
                var18 = var1[0];
                var19 = var1[1];
                var20 = var1[2];
                var21 = var1[3];
                var22 = var1[4];
                if (var18 == 0) var17 = 0;
            } else if (func_0204fc40(arg0, &var0, data_020f02cf, var1, 2)) {
                var15 = var1[0];
                var16 = var1[1];
            } else if (func_0204fc40(arg0, &var0, data_020f02d4, var1, 1)) {
                var14 = 1;
                func_0204f3bc(arg0, var1[0]);
                var6 = var8 + arg0->unknown_b2_ * var7;
                var5 = (var1[0] - 10) >> 1;
            } else if (func_0204fc40(arg0, &var0, data_020f02db, var1, 0)) {
                if (var14 != 0) {
                    var5 = arg0->unknown_b2_;
                    var4 = arg0->unknown_b0_;
                    var6 = var8 + var5 * var7;
                    var14 = 0;
                }
            } else if (func_0204fc40(wnd, &p, data_020f02e2, out, 1)) {
                hilite = out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02e7, out, 1)) {
                x = out[0];
                prev = 0xff;
                savedX = x;
                __clear(tmp, 0x100);
                char* start = p;
                char* end = strstr(start, data_020f02eb);
                if (end != 0) {
                    int len = end - start;
                    if (len < 0x100) {
                        memcpy(tmp, start, len);
                        x -= Font_GetTextWidth(tmp, font);
                    }
                }
            } else if (func_0204fc40(arg0, &var0, data_020f02f1, var1, 0)) {
                var4 = var34;
                var11 = 0xff;
            } else {
                var41 = 0;
            }
            if (var41) {
                var52 = var0;
                continue;
            }
        }
        adv = data_020e7bdc[font] + 1;
        int idx = Font_FindCharacterIndex((int)cursor, font);
        if (idx >= 0) {
            code = idx & 0xff;
            glyph = Font_GetCharacter(idx, font);
            x += Font_GetKerning(prev, code, font);
            func_0204df9c(wnd, glyph, x, y, colorIdx, font);
            prev = code;
            adv = (unsigned char)(glyph->width + 1);
            cursor += glyph->skip;
        } else {
            if (ch != ' ') {
                func_0204df9c(wnd, Font_GetCharacter(0, font), x, y, colorIdx, font);
            }
            var52++;
        }
        var4 += var50;
    }

    { int var64 = 0; if (var64) func_0204fae8((Struct_0204cd60*)var6); }
    if (arg0->unknown_c5_ & 8) func_0204fae8(arg0);
    if (!(arg0->unknown_c5_ & 0x10)) {
        if (var28 >= 0) arg0->unknown_c5_ |= 2;
        if (var23 >= 0) {
            short var65 = arg0->unknown_c_[var23] - 8;
            short var66 = arg0->unknown_30_[var23] - 1;
            arg0->unknown_bc_ = var65;
            arg0->unknown_be_ = var66;
            func_0204fa0c(arg0, var65, var66);
        }
    }
    if (var15 > 0 && var16 > 0) {
        short var67 = var5 + var33;
        short var68 = (short)(arg0->unknown_a8_ << 3) - (var16 * 2 + 2);
        short var69 = var67 - var16;
        short var70;
        for (var70 = 0; var70 < var15; var70++) {
            func_0204cc68(arg0, 0xf, var68, var69, var68 + var16, var69 + var16);
            var68 -= var16 * 2;
        }
    }
}
