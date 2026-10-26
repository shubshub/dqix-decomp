#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_ov008_02186b18(void* obj, int a, int b);

struct SelfBB04;
extern "C" void GridCursor_SetSelectedIndex(struct SelfBB04*, int);
extern "C" int GridCursor_Update(void*, void*);

// USA: func_ov008_02186a30
extern "C" ARM int func_ov008_02186a30(void* self, void* param1) {
    int state = 0;
    int idx = -1;
    int a, b;
    g_touchInput.GetTouchPoint(&a, &b);

    if (g_touchInput.pressed_ != 0) {
        state = 1;
        idx = func_ov008_02186b18(self, a, b);
        if (idx != -1) {
            GridCursor_SetSelectedIndex((struct SelfBB04*)((char*)self + 0x750), idx);
        }
    } else {
        if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
            state = 1;
        } else if (g_touchInput.released_ != 0) {
            state = 1;
        }
    }

    if (state == 0) {
        GridCursor_Update((char*)self + 0x750, param1);
    }
    if (state != 0) {
        if (idx == -1) return 0;
        if (idx == -2) return -2;
        if (idx >= 0) return 1;
    }
    return 0;
}
