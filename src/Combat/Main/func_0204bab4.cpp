#include <globaldefs.h>

extern "C" void Background_CopyScreenRect(void*, void*, int, int, int, int, int, int, int, int);

struct Struct_0204bab4 {
    char pad0[0x14];
    void* field14;
};

struct Struct_0204bab4_2 {
    short x;
    short y;
    char pad4[8];
    void* unknown_c_;
};

// USA: func_0204bab4
extern "C" ARM void func_0204bab4(struct Struct_0204bab4* obj, struct Struct_0204bab4_2* pt, int width, int height,
                        int arg4, short arg5, int arg6, int arg7, unsigned short a9) {
    int curX;
    short curY;
    short x, y;

    if (width <= 0 || height <= 0) return;
    if (pt->unknown_c_ == NULL) return;

    x = pt->x;
    y = pt->y;
    curY = arg5;
    if (x < width) width = x;
    if (y < height) height = y;

    for (unsigned short j = 0; j < arg7; j++) {
        curX = arg4;
        for (unsigned short i = 0; i < arg6; i++) {
            if (obj->field14 != NULL) {
                Background_CopyScreenRect(obj, obj->field14, (int)pt, 0, 0, curX, curY, width, height, a9);
            }
            curX = (short)(curX + width);
        }
        curY = (short)(curY + height);
    }
}
