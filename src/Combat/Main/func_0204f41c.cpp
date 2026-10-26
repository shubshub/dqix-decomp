#include <globaldefs.h>

struct Struct_0204f41c_2 {
    char pad0[0xb6];
    short lineHeight;
};

struct Glyph0204f41c {
    int data;
    signed char width;
    signed char length : 6;
};

extern "C" int func_0204fc40(Struct_0204f41c_2* window, const char** cursor, const char* tag, short* out, int count);
extern "C" void func_0204df9c(Struct_0204f41c_2* window, Glyph0204f41c* glyph, short x, short y, unsigned char color, int font);
extern "C" Glyph0204f41c* Font_FindCharacter(int key, int tableIdx);
extern "C" Glyph0204f41c* Font_GetCharacter(int idx, int tableIdx);

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
extern "C" ARM void func_0204f41c(Struct_0204f41c_2* window, short x, short y, const char* text, unsigned char size,
                                  unsigned char color, short* arg6, short* outHeight, int font) {
    int var0;
    short var1;
    short var2;
    short args[8];
    if (text == NULL) return;
    const char* p = text;
    unsigned char curColor = color;
    if (size == 12) font = 1;
    *outHeight = 0;
    *arg6 = 0;
    var1 = x;
    var2 = y;
    var0 = size;
    while (*p != 0) {
        char c = *p;
        char next = p[1];
        if ((c == '\\' && next == 'n') || (c == '\r' && next == '\n')) {
            y += window->lineHeight;
            x = var1;
            p += 2;
            continue;
        }
        if (c == '\n') {
            y += window->lineHeight;
            x = var1;
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
            short bottom = y + var0;
            short right = x + advance;
            if (*arg6 < right) *arg6 = right;
            if (*outHeight < bottom) *outHeight = bottom;
            p += glyph->length;
        } else {
            if (*p != ' ') {
                func_0204df9c(window, Font_GetCharacter(0, font), x, y, curColor, font);
            }
            p++;
        }
        x += advance;
    }
    *arg6 -= var1;
    *outHeight -= var2;
}
