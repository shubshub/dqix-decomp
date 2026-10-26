#include <globaldefs.h>
#include <std_library_functions.h>
#include <NitroSDK/BGBases.h>

struct Struct_0204cd60 {
    char pad0[8];
    unsigned char* buf;
    short arrA[18];
    short arrB[18];
    short unknown_54_[18];
    short unknown_78_[18];
    char unknown_9c_[4];
    int unknown_a0_;
    int unknown_a4_;
    short unknown_a8_;
    short unknown_aa_;
    char padAC[4];
    short unknown_b0_;
    short unknown_b2_;
    char padB4[2];
    short unknown_b6_;
    char unknown_b8_[2];
    short sizeTagLineHeight_;
    short unknown_bc_;
    short unknown_be_;
    char unknown_c0_[5];
    unsigned char flags;
    unsigned char unknown_c6_;
    unsigned char unknown_c7_;
    char unknown_c8_[0x10];
    unsigned char bit0 : 2;
    unsigned char unknown_d8_2_ : 1;
    unsigned char unknown_d8_3_ : 5;
    char unknown_d9_[2];
    signed char unknown_db_[4];
};

struct Glyph0204cd60 {
    int val;
    char width;
    signed char unknown_5_0_ : 6;
    signed char unused : 2;
    char pad6[2];
};

extern "C" void* __clear(void* dst, int count);
extern "C" int Font_GetTextWidth(char* str, int id);
extern "C" int Font_FindCharacterIndex(int key, int tableIdx);
extern "C" Glyph0204cd60* Font_GetCharacter(int idx, int tableIdx);
extern "C" int Font_GetKerning(int a, int b, int tableIdx);
extern "C" void func_0204cc68(Struct_0204cd60* wnd, int mode, short arg2, short arg3, short x1, short arg5);
extern "C" void func_0204f914(Struct_0204cd60* wnd, int mode, short arg2, short arg3, short x1, short arg5);
extern "C" void func_0204ea5c(Struct_0204cd60* wnd);
extern "C" void func_0204ecb4(Struct_0204cd60* wnd, int a, int b, int w, int h, signed char* arg5);
extern "C" int func_0204fc40(void* unused0, char** cursor, char* tag, short* out, int max);
extern "C" void func_0204f3bc(Struct_0204cd60* wnd, int idx);
extern "C" void func_0204df9c(Struct_0204cd60* wnd, Glyph0204cd60* glyph, int x, int y, int color, int font);
extern "C" void func_0204fae8(Struct_0204cd60* wnd);
extern "C" void func_0204fa0c(Struct_0204cd60* wnd, short x, short y);

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

static inline void inline_01ff8b48(Struct_0204cd60* wnd, short x, short y) {
    wnd->unknown_bc_ = x;
    wnd->unknown_be_ = y;
}

// USA: func_0204cd60
extern "C" ARM void func_0204cd60(Struct_0204cd60* wnd, char* text, short border, short font) {
    char* p;
    short out[8];
    char tmp[0x100];
    int sel;
    short x;
    short y;
    unsigned char* dst;
    short pitch;
    unsigned char* buf;
    short stride;
    Glyph0204cd60* glyph;
    unsigned char prev;
    int code;
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
    short lineH;
    int mode;
    int color, colorIdx, var39, var40;
    int handled;
    short ax, var43, ay, var45;
    short var46, x1, var48, var49;
    unsigned char var50;
    int ch;
    char* cursor;

    cursor = text;
    if (cursor == 0) return;

    var14 = 0;
    prev = 0xff;
    wnd->flags &= ~2;
    var13 = -1;
    pitch = (wnd->unknown_a8_ << 3) >> 1;
    lineH = wnd->unknown_b6_;
    stride = lineH * pitch;
    y = wnd->unknown_b2_;
    buf = wnd->buf;
    dst = buf + y * pitch;
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
    sel = var13;
    var33 = wnd->unknown_c7_;
    x = wnd->unknown_b0_;

    if (wnd->unknown_d8_2_) {
        memcpy(wnd->buf, (char*)GetSubBG2CharacterBase() + wnd->unknown_a0_, wnd->unknown_a4_);
    } else {
        memset(wnd->buf, 0, wnd->unknown_a4_);
    }

    if (wnd->flags & 4) {
        mode = 0;
    } else {
        if (!wnd->unknown_d8_2_) {
            short rx = 0;
            short ry = 0;
            short var55 = wnd->unknown_a8_ << 3;
            short var56 = wnd->unknown_aa_ << 3;
            ry += wnd->unknown_db_[0];
            var56 -= wnd->unknown_db_[0] + wnd->unknown_db_[1];
            rx += wnd->unknown_db_[2];
            var55 -= wnd->unknown_db_[2] + wnd->unknown_db_[3];
            func_0204f914(wnd, 0x11, rx, ry, var55, var56);
            func_0204ea5c(wnd);
        }
        mode = 0x11;
    }

    if (border > 0) {
        short w = wnd->unknown_a8_ << 3;
        short h = wnd->unknown_aa_ << 3;
        func_0204cc68(wnd, 3, 0, 0, w, h);
        func_0204cc68(wnd, mode, (int)border, (int)border, w - border, h - border);
    } else if (!(wnd->flags & 0x10)) {
        func_0204ecb4(wnd, 0, 0, wnd->unknown_a8_, wnd->unknown_aa_, wnd->unknown_db_);
    }

    color = 0xf0;
    colorIdx = 0xf;
    var39 = color;
    var40 = colorIdx;

    while ((ch = *cursor) != 0) {
        int next = cursor[1];
        if ((ch == '\\' && next == 'n') || (ch == '\r' && next == '\n')) {
            y += lineH;
            x = wnd->unknown_b0_;
            cursor += 2;
            dst += stride;
            continue;
        }
        if (ch == '\n') {
            y += lineH;
            x = wnd->unknown_b0_;
            cursor += 1;
            dst += stride;
            continue;
        }
        if (ch == '<') {
            handled = 1;
            p = cursor + 1;
            if (func_0204fc40(wnd, &p, data_020f0248, out, 1)) {
                switch (out[0]) {
                case 8:
                    var33 = 8;
                    lineH = 9;
                    break;
                case 12:
                    var33 = 12;
                    lineH = 13;
                    break;
                default:
                    var33 = 10;
                    lineH = wnd->unknown_b6_;
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
                if (sel >= 0 && sel == var13) {
                    var39 = color;
                    var40 = colorIdx;
                    color = 0xe0;
                    colorIdx = 0xe;
                } else if (sel >= 0 && sel == var28) {
                    var39 = color;
                    var40 = colorIdx;
                    color = 0x50;
                    colorIdx = 0x5;
                }
            } else if (func_0204fc40(wnd, &p, data_020f02a0, out, 0)) {
                if (sel >= 0) {
                    if (sel == var13 || sel == var28) {
                        color = var39;
                        colorIdx = var40;
                    }
                }
                if (sel >= 0 && sel < 18) {
                    wnd->unknown_54_[sel] = x - wnd->arrA[sel];
                    wnd->unknown_78_[sel] = var33 + (y - wnd->arrB[sel]) + 1;
                    if (wnd->unknown_54_[sel] < 4) wnd->unknown_54_[sel] = 4;
                }
                if (var28 >= 0 && sel == var28) {
                    if (!(wnd->flags & 0x10) && (var24 >= 0 || var25 >= 0 || var26 >= 0 || var27 >= 0)) {
                        wnd->arrA[sel] -= var29 + wnd->unknown_c6_;
                        wnd->arrB[sel] -= var30;
                        wnd->unknown_54_[sel] += var29 + var31;
                        wnd->unknown_78_[sel] += var30 + var32;
                    }
                    wnd->flags |= 2;
                }
                if (!(wnd->flags & 0x10) && var17 != 0) {
                    wnd->unknown_54_[sel] = var18;
                    ax = wnd->arrA[sel];
                    var43 = wnd->unknown_54_[sel];
                    ay = wnd->arrB[sel];
                    var45 = wnd->unknown_78_[sel];
                    var46 = ax - var19;
                    x1 = var21 + (ax + var43);
                    var48 = ay - var20;
                    var49 = var22 + (ay + var45);
                    func_0204cc68(wnd, 3, var46 + 1, var48, x1 - 1, var48 + 1);
                    func_0204cc68(wnd, 3, var46 + 1, var49 - 1, x1 - 1, var49);
                    func_0204cc68(wnd, 3, var46, var48 + 1, var46 + 1, var49 - 1);
                    func_0204cc68(wnd, 3, x1 - 1, var48 + 1, x1, var49 - 1);
                }
                sel = -1;
            } else if (func_0204fc40(wnd, &p, data_020f02a3, out, 2)) {
            } else if (func_0204fc40(wnd, &p, data_020f02aa, out, 5)) {
                var28 = out[0];
                var29 = out[1];
                var30 = out[2];
                var31 = out[3];
                var32 = out[4];
            } else if (func_0204fc40(wnd, &p, data_020f02b1, out, 1)) {
                var23 = out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02b9, out, 3)) {
                var24 = (signed char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02bd, out, 3)) {
                var25 = (signed char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02c1, out, 3)) {
                var26 = (signed char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02c5, out, 3)) {
                var27 = (signed char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02c9, out, 5)) {
                var17 = 1;
                var18 = out[0];
                var19 = out[1];
                var20 = out[2];
                var21 = out[3];
                var22 = out[4];
                if (var18 == 0) var17 = 0;
            } else if (func_0204fc40(wnd, &p, data_020f02cf, out, 2)) {
                var15 = out[0];
                var16 = out[1];
            } else if (func_0204fc40(wnd, &p, data_020f02d4, out, 1)) {
                var14 = 1;
                func_0204f3bc(wnd, out[0]);
                dst = buf + wnd->unknown_b2_ * pitch;
                y = (out[0] - 10) >> 1;
            } else if (func_0204fc40(wnd, &p, data_020f02db, out, 0)) {
                if (var14 != 0) {
                    y = wnd->unknown_b2_;
                    x = wnd->unknown_b0_;
                    dst = buf + y * pitch;
                    var14 = 0;
                }
            } else if (func_0204fc40(wnd, &p, data_020f02e2, out, 1)) {
                var13 = out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02e7, out, 1)) {
                x = out[0];
                prev = 0xff;
                var34 = x;
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
            } else if (func_0204fc40(wnd, &p, data_020f02f1, out, 0)) {
                x = var34;
                prev = 0xff;
            } else {
                handled = 0;
            }
            if (handled) {
                cursor = p;
                continue;
            }
        }
        var50 = data_020e7bdc[font] + 1;
        int idx = Font_FindCharacterIndex((int)cursor, font);
        if (idx >= 0) {
            code = idx & 0xff;
            glyph = Font_GetCharacter(idx, font);
            x += Font_GetKerning(prev, code, font);
            func_0204df9c(wnd, glyph, x, y, colorIdx, font);
            prev = code;
            var50 = (unsigned char)(glyph->width + 1);
            cursor += glyph->unknown_5_0_;
        } else {
            if (ch != ' ') {
                func_0204df9c(wnd, Font_GetCharacter(0, font), x, y, colorIdx, font);
            }
            cursor++;
        }
        x += var50;
    }

    { int var64 = 0; if (var64) func_0204fae8((Struct_0204cd60*)dst); }
    if (wnd->flags & 8) func_0204fae8(wnd);
    if (!(wnd->flags & 0x10)) {
        if (var28 >= 0) wnd->flags |= 2;
        if (var23 >= 0) {
            short cx = wnd->arrA[var23] - 8;
            short var66 = wnd->arrB[var23] - 1;
            wnd->unknown_bc_ = cx;
            wnd->unknown_be_ = var66;
            func_0204fa0c(wnd, cx, var66);
        }
    }
    if (var15 > 0 && var16 > 0) {
        short base = y + var33;
        short var68 = (short)(wnd->unknown_a8_ << 3) - (var16 * 2 + 2);
        short by = base - var16;
        short i;
        for (i = 0; i < var15; i++) {
            func_0204cc68(wnd, 0xf, var68, by, var68 + var16, by + var16);
            var68 -= var16 * 2;
        }
    }
}
