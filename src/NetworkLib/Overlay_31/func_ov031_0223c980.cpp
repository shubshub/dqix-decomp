#include <globaldefs.h>

struct Struct_ov031_0223c980_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    signed char unknown_4_;
    unsigned char unknown_5_;
    unsigned char bpp;
    unsigned char flags;
};
struct Struct_ov031_0223c980 {
    unsigned char pad[8];
    Struct_ov031_0223c980_2* glyph;
};
struct Struct_ov031_0223c980_3 {
    Struct_ov031_0223c980* info;
};
struct Struct_ov031_0223c980_4 {
    void* unknown_0_;
    Struct_ov031_0223c980_3* font;
    int unknown_8_;
    int unknown_c_;
};
struct Struct_ov031_0223c980_5 {
    char pad[0x18];
    Struct_ov031_0223c980_4 canvas;
};
struct Struct_ov031_0223c980_6 { signed char x, y; };

extern "C" void func_020b26e8(Struct_ov031_0223c980_4* canvas, int x, int y, int arg3, int available, int arg5, int flags, const char* text, Struct_ov031_0223c980_6 direction);

// USA: func_ov031_0223c980
extern "C" ARM void func_ov031_0223c980(Struct_ov031_0223c980_5* window, int x, int y, int arg3, int available, int arg5, int flags, const char* text) {
    Struct_ov031_0223c980_3* font = window->canvas.font;
    Struct_ov031_0223c980_6 dir = {0, 0};
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
    func_020b26e8(&window->canvas, x, y, arg3, available, arg5, flags, text, dir);
}
