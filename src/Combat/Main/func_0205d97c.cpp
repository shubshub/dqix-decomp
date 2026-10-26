#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205d81c {
    char padding[0xb0];
    unsigned char selected;
};
struct Elem_0205d81c {
    char padding[0xa8];
    short width;
    short height;
    short x;
    short y;
};
extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c*, int);

// USA: func_0205d97c
extern "C" ARM int func_0205d97c(Struct_0205d81c* object) {
    if (!g_touchInput.pressed_) return -1;
    Elem_0205d81c* element;
    int x;
    int y;
    element = func_0205d81c(object, object->selected);
    if (element == NULL) return 0;
    g_touchInput.GetTouchPoint(&x, &y);
    if (x == 0 || y == 0) return 0;
    int left = element->x;
    int top = element->y;
    int width = element->width;
    int height = element->height;
    left = (short)(left << 3);
    top = (short)(top << 3);
    width = (short)(width << 3);
    height = (short)(height << 3);
    int right = left + width;
    int bottom = top + height;
    if (left <= x && x < right && top <= y && y < bottom) return 1;
    return 2;
}
