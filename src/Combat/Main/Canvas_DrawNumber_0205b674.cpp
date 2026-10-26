#include <globaldefs.h>

#if defined(jpn)
namespace {
struct Struct02020520;
struct S_b20c {
    void* pixels;
    Struct02020520* layout;
    unsigned char mode;
};
}
extern "C" void __clear(void*, int);
extern "C" void GlyphDestination_DrawText(S_b20c*, int, int, void*, int, int);

// JPN: Canvas_DrawNumber
// Main, originally PositionAndFormatValueLabel0205b674 (USA 0x0205b674, EUR 0x0205b684, JPN 0x0205c9ac)
extern "C" ARM void Canvas_DrawNumber(S_b20c* destination, short x, short y, int value,
                                  int pixelSize, int color, unsigned char digits, unsigned char align) {
    if (destination->pixels != NULL && destination->layout != NULL) {
        int remaining = value;
        while ((remaining = remaining / 10) != 0) {}
        if (align == 1) {
            x = (short)(x + (short)((digits - 1) * pixelSize));
        }
        char text[2];
        do {
            __clear(text, 2);
            text[0] = '0';
            text[0] += (char)(value % 10);
            GlyphDestination_DrawText(destination, x, y, text, pixelSize, color);
            x = (short)(x - pixelSize);
        } while ((value = value / 10) != 0);
    }
}
#else

struct Obj0205b674 { int field0; int field4; };

extern "C" int func_02042658(void* obj, int value);
extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(void* dst, void* fmt, int val);
extern "C" void GlyphDestination_DrawText(struct Obj0205b674* a, int b, int c, void* buf, int d, int e);
extern char data_020f0518;

// USA: Canvas_DrawNumber
extern "C" ARM void Canvas_DrawNumber(struct Obj0205b674* obj, short posX, int param2, int param3,
                                              unsigned char param4, unsigned char arg5, unsigned char arg6, unsigned char param7) {
    if (obj->field0 != 0 && obj->field4 != 0) {
        int value = param3;
        while ((value = value / 10) != 0) {}
        int var1 = func_02042658((void*)param7, param3);
        if (arg6 == 1) {
            posX = (short)(posX + (short)((arg5 << 3) - var1));
        }
        char buf[0xa];
        __clear(buf, 0xa);
        sprintf(buf, &data_020f0518, param3);
        GlyphDestination_DrawText(obj, posX, param2, buf, param4, param7);
    }
}

#endif
