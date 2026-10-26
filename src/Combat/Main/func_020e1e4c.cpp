#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_020e1e4c;
extern "C" ARM int func_020e1eb0(struct Struct_020e1e4c* list, int x, int y);

// USA: func_020e1e4c
extern "C" ARM int func_020e1e4c(struct Struct_020e1e4c* list) {
    if (!g_touchInput.pressed_) {
        goto no_flag;
    }
    {
        int x, y;
        g_touchInput.GetTouchPoint(&x, &y);
        int idx = func_020e1eb0(list, (short)x, (short)y);
        return (idx < 0) ? -2 : idx;
    }
no_flag:
    return -1;
}
