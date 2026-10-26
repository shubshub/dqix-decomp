#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov023_021f8970 {
    char pad0[0xc8];
    short width;
    short height;
    short x;
    short y;
};

// USA: func_ov023_021f8970
extern "C" ARM int func_ov023_021f8970(struct Struct_ov023_021f8970* obj) {
    short x = obj->x;
    short y = obj->y;
    short width = obj->width;
    short height = obj->height;
    int px, var5;
    g_touchInput.GetTouchPoint(&px, &var5);
    if ((short)(x << 3) > px) goto fail;
    short var6 = (short)(x << 3);
    short var7 = (short)(width << 3);
    int xMax = var6 + var7;
    if (px >= xMax) goto fail;
    if ((short)(y << 3) > var5) goto fail;
    short var9 = (short)(y << 3);
    short var10 = (short)(height << 3);
    int var11 = var9 + var10;
    if (var5 < var11) return 1;
fail:
    return 0;
}
