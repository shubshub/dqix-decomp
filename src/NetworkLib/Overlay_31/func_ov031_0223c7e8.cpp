#include <globaldefs.h>

struct Struct_ov031_0223c7e8_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    signed char unknown_4_;
    unsigned char unknown_5_;
    unsigned char bpp;
    unsigned char flags;
};
struct Struct_ov031_0223c7e8 {
    unsigned char pad[8];
    Struct_ov031_0223c7e8_2* glyph;
};
struct Struct_ov031_0223c7e8_3 {
    Struct_ov031_0223c7e8* info;
};
struct Struct_ov031_0223c7e8_4 {
    void* unknown_0_;
    Struct_ov031_0223c7e8_3* font;
    int unknown_8_;
    int unknown_c_;
};
struct Struct_ov031_0223c7e8_5 {
    char pad[0x18];
    Struct_ov031_0223c7e8_4 canvas;
};
struct Struct_ov031_0223c7e8_6 { signed char x, y; };

extern "C" void func_020b25c4(Struct_ov031_0223c7e8_4* canvas, int x, int y, int color, int flags, const char* text, Struct_ov031_0223c7e8_6 direction);

// USA: func_ov031_0223c7e8
extern "C" ARM void func_ov031_0223c7e8(Struct_ov031_0223c7e8_5* window, int x, int y, int color, int flags, const char* text) {
    Struct_ov031_0223c7e8_3* font = window->canvas.font;
    Struct_ov031_0223c7e8_6 dir = {0, 0};
    switch (font->info->glyph->flags) {
    case 0:
    case 7:
        dir.x = 1;
        break;
    case 1:
    case 2:
        dir.y = 1;
        break;
    case 3:
    case 4:
        dir.x = -1;
        break;
    case 5:
    case 6:
        dir.y = -1;
        break;
    }
    func_020b25c4(&window->canvas, x, y, color, flags, text, dir);
}
