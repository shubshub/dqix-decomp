#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_0204e3e0_2 {
    char pad0[0xa4];
    int unknown_a4_;
    short unknown_a8_;
    short unknown_aa_;
    char padAC[4];
    short unknown_b0_;
    short unknown_b2_;
    char padB4[2];
    short unknown_b6_;
};

struct Glyph0204e3e0 {
    int val;
    char width;
    signed char unknown_5_0_ : 6;
    signed char unused : 2;
};

extern "C" void* __clear(void* dst, int count);
extern "C" int Font_GetTextWidth(char* str, int id);
extern "C" int Font_FindCharacterIndex(int key, int tableIdx);
extern "C" char* func_020424ac(char* str);
extern "C" Glyph0204e3e0* Font_GetCharacter(int idx, int tableIdx);
extern "C" int Font_GetKerning(int a, int b, int tableIdx);
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
extern "C" ARM short func_0204e3e0(Struct_0204e3e0_2* wnd, char* text, int mode, unsigned char border, unsigned char arg4, unsigned char font) {
    int var0;
    int x, y, maxX, var4;
    short prev;
    int code;
    bool var7;
    short ret;
    int var9;
    int lineH;
    char* end;
    char* cursor;
    char* p;
    short out[8];
    char tmp[0x100];
    unsigned char var16;
    Glyph0204e3e0* glyph;

    cursor = text;
    if (cursor == 0) return 0;

    maxX = wnd->unknown_b0_;
    var4 = wnd->unknown_b2_;
    var7 = 0;
    var0 = 0;
    ret = 0;
    lineH = wnd->unknown_b6_;
    x = wnd->unknown_b0_;
    y = wnd->unknown_b2_;
    prev = 0xff;

    while (*cursor != 0) {
        char ch = *cursor;
        char next = cursor[1];
        if ((ch == '\\' && next == 'n') || (ch == '\r' && next == '\n')) {
            if (maxX < x) maxX = x;
            x = wnd->unknown_b0_;
            y += wnd->unknown_b6_;
            cursor += 2;
            prev = 0xff;
            continue;
        }
        if (ch == '\n') {
            if (maxX < x) maxX = x;
            x = wnd->unknown_b0_;
            y += wnd->unknown_b6_;
            cursor += 1;
            prev = 0xff;
            continue;
        }
        int idx = Font_FindCharacterIndex((int)cursor, font);
        if (*cursor == '<' && idx < 0) {
            p = cursor + 1;
            end = func_020424ac(cursor);
            if (func_0204fc40(wnd, &p, data_020f0248, out, 1)) {
            } else if (func_0204fc40(wnd, &p, data_020f024e, out, 1)) {
                if (maxX < x) maxX = x;
                x = out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0251, out, 1)) {
                if (var4 < y) var4 = y;
                y = out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0254, out, 2)) {
                if (maxX < x) maxX = x;
                if (var4 < y) var4 = y;
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
                var7 = 1;
                var0 = out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02db, out, 0)) {
                if (var7) {
                    if (maxX < x) maxX = x;
                    if (var4 < y) var4 = y;
                    x = wnd->unknown_b0_;
                    y = var0 + wnd->unknown_b2_;
                }
            } else if (func_0204fc40(wnd, &p, data_020f02e7, out, 1)) {
                if (maxX < x) maxX = x;
                x = out[0];
                prev = 0xff;
                var9 = x;
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
            } else if (func_0204fc40(wnd, &p, data_020f02f1, out, 0)) {
                if (maxX < x) maxX = x;
                x = var9;
                prev = 0xff;
            }
            cursor = end + 1;
            continue;
        }
        var16 = data_020e7bd6[font] + 1;
        if (idx >= 0) {
            code = idx & 0xff;
            glyph = Font_GetCharacter(idx, font);
            int kern = Font_GetKerning(prev, code, font);
            prev = code;
            var16 = glyph->width + 1 + kern;
            cursor += glyph->unknown_5_0_;
        } else {
            cursor++;
        }
        x += var16;
    }

    if (x < maxX) x = maxX;
    if (y < var4) y = var4;
    y = y + lineH - (wnd->unknown_b6_ - 10);
    if (((x + 3) & 7) <= 3) x += 4;
    int w = ((x + 7) & ~7) >> 3;
    int h = ((y + 7) & ~7) >> 3;
    if (w > 32) w = 32;
    if (h > 32) h = 32;
    if (arg4) {
        if (wnd->unknown_a8_ < w) wnd->unknown_a8_ = w;
        if (wnd->unknown_aa_ < h) wnd->unknown_aa_ = h;
    }
    if (border) {
        y -= wnd->unknown_b2_;
        if ((wnd->unknown_aa_ << 3) - y < 7) wnd->unknown_aa_ = wnd->unknown_aa_ + 1;
        wnd->unknown_b2_ = ((wnd->unknown_aa_ << 3) - y) >> 1;
    }
    if (var7) {
        wnd->unknown_b2_ = wnd->unknown_b2_ + var0;
        if (border) wnd->unknown_b2_ = wnd->unknown_b2_ - 1;
    }
    wnd->unknown_a4_ = (wnd->unknown_a8_ * wnd->unknown_aa_) << 5;
    return ret;
}
