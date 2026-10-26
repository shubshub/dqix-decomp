#include <globaldefs.h>
#include "Input/Input.h"

// USA: func_ov003_02178218
extern "C" ARM int func_ov003_02178218(void) {
    if (g_touchInput.isRepeatValid_ == 0 || g_touchInput.currentReading_.isHeld == 0) {
        return 0;
    }
    int x, y;
    g_touchInput.GetTouchPoint(&x, &y);
    if (x < 0x94 || x > 0xa7) {
        return 0;
    }
    if (y >= 0x24 && y <= 0x2d) return 1;
    if (y >= 0x30 && y <= 0x39) return -1;
    return 0;
}
