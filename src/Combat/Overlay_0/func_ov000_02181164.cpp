#include <globaldefs.h>

extern "C" void SpriteContext_DrawSprite(void* dst, void* src);

struct Struct_ov000_02181164 {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[0x22 - 0x1c];
    unsigned char unknown_22_;
    char unknown_23_[0x26 - 0x23];
    signed char unknown_26_;
    char unknown_27_[0x28 - 0x27];
};

// USA: func_ov000_02181164
extern "C" ARM void func_ov000_02181164(void* arg0, int arg1, struct Struct_ov000_02181164* arg2, int arg3, int arg4,
    int arg5, int arg6, int arg7) {
    if (arg1 < 0) return;
    if (arg2 == NULL) return;
    do {
        struct DigitSprite02181164* e = &sprites[value % 10];
        e->x = x << 12;
        e->y = y << 12;
        e->frame = frame;
        e->palette = palette & 3;
        SpriteContext_DrawSprite((char*)obj + 0x11c, e);
        frame++;
        x -= spacing;
        value /= 10;
    } while (value != 0);
}
