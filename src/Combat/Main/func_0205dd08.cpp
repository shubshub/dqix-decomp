#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205d81c;
struct Elem_0205d81c;

extern "C" struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
extern "C" int WindowPane_IsReady(unsigned char* obj);

struct Struct_0205dd08 {
    char pad0[0x98];
    void* unknown_98_;
    void* f9c;
};

struct Rect_0205dd08 {
    char pad0[0xa8];
    short height;
    short x;
    short y;
    short width;
    char pad1[0x15];
    unsigned char unknown_c5_;
};

// USA: func_0205dd08
extern "C" ARM int func_0205dd08(struct Struct_0205dd08* obj) {
    struct Rect_0205dd08* e;
    int touchY, touchX;
    short top, right, bottom, tx, ty;

    if (obj->unknown_98_ == NULL) return 0;
    if (obj->f9c == NULL) return 0;
    if (g_touchInput.pressed_ == 0) return 0;

    e = (struct Rect_0205dd08*)Window_GetActivePane((struct Struct_0205d81c*)obj);
    if (e == NULL) return 0;
    if (WindowPane_IsReady((unsigned char*)e) == 0) return 0;
    if ((e->unknown_c5_ & 8) == 0) return 0;

    g_touchInput.GetTouchPoint(&touchY, &touchX);

    top = e->y * 8;
    bottom = top + (short)(e->height * 8);
    right = (short)(e->width * 8) + (short)(e->x * 8);
    ty = (short)touchY;
    tx = (short)touchX;

    if (right - 12 < tx && tx < right) {
        if (top < ty && ty < top + 12) return -1;
        if (bottom - 12 < ty && ty < bottom) return 1;
    }
    return 0;
}
