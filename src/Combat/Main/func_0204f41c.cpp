#include <globaldefs.h>

struct Window0204f41c {
    char pad0[0xb6];
    short lineHeight;
};

struct Glyph0204f41c {
    int data;
    signed char width;
    signed char length : 6;
};

extern "C" int func_0204fc40(Window0204f41c* window, const char** cursor, const char* tag, short* out, int count);
extern "C" void func_0204df9c(Window0204f41c* window, Glyph0204f41c* glyph, short x, short y, unsigned char color, int font);
Glyph0204f41c* Font_FindCharacter(int key, int tableIdx);
Glyph0204f41c* GetBoundedEntry020425b4(int idx, int tableIdx);

extern const unsigned char data_020e7bd8[];
extern const char data_020f0248[];
extern const char data_020f0258[];
extern const char data_020f025b[];
extern const char data_020f025e[];
extern const char data_020f024e[];
extern const char data_020f0251[];
extern const char data_020f0254[];
extern const char data_020f028c[];

// USA: func_0204f41c
extern "C" ARM void func_0204f41c(Window0204f41c* window, short x, short y, const char* text, unsigned char size,
                                  unsigned char color, short* outWidth, short* outHeight, int font) {
    int lineAdvance;
    short x0;
    short y0;
    short args[8];
    if (text == NULL) return;
    const char* p = text;
    unsigned char curColor = color;
    if (size == 12) font = 1;
    *outHeight = 0;
    *outWidth = 0;
    x0 = x;
    y0 = y;
    lineAdvance = size;
    while (*p != 0) {
        char c = *p;
        char next = p[1];
        if ((c == '\\' && next == 'n') || (c == '\r' && next == '\n')) {
            y += window->lineHeight;
            x = x0;
            p += 2;
            continue;
        }
        if (c == '\n') {
            y += window->lineHeight;
            x = x0;
            p += 1;
            continue;
        }
        if (c == '<') {
            p++;
            if (func_0204fc40(window, &p, data_020f0248, args, 1)) continue;
            if (func_0204fc40(window, &p, data_020f0258, args, 1)) {
                x += args[0];
                continue;
            }
            if (func_0204fc40(window, &p, data_020f025b, args, 1)) {
                y += args[0];
                continue;
            }
            if (func_0204fc40(window, &p, data_020f025e, args, 2)) {
                x += args[0];
                y += args[1];
                continue;
            }
            if (func_0204fc40(window, &p, data_020f024e, args, 1)) {
                x = args[0];
                continue;
            }
            if (func_0204fc40(window, &p, data_020f0251, args, 1)) {
                y = args[0];
                continue;
            }
            if (func_0204fc40(window, &p, data_020f0254, args, 2)) {
                x = args[0];
                y = args[1];
                continue;
            }
            if (func_0204fc40(window, &p, data_020f028c, args, 1)) {
                args[0] &= 0xf;
                curColor = args[0];
                continue;
            }
            p--;
        }
        unsigned char advance = data_020e7bd8[font] + 1;
        Glyph0204f41c* glyph = Font_FindCharacter((int)p, font);
        if (glyph != NULL) {
            func_0204df9c(window, glyph, x, y, curColor, font);
            advance = glyph->width + 1;
            short bottom = y + lineAdvance;
            short right = x + advance;
            if (*outWidth < right) *outWidth = right;
            if (*outHeight < bottom) *outHeight = bottom;
            p += glyph->length;
        } else {
            if (*p != ' ') {
                func_0204df9c(window, GetBoundedEntry020425b4(0, font), x, y, curColor, font);
            }
            p++;
        }
        x += advance;
    }
    *outWidth -= x0;
    *outHeight -= y0;
}
