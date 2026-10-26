#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov023_021fd420;
extern "C" void func_ov023_021fd420(struct Struct_ov023_021fd420*, unsigned short*, unsigned short*, unsigned short*, unsigned short*);

// USA: func_ov023_021fd46c
extern "C" ARM int func_ov023_021fd46c(struct Struct_ov023_021fd420* obj) {
    if (*((unsigned char*)obj + 0xc) & 0x10) return 0;
    unsigned short x1, var1, x2, y2;
    func_ov023_021fd420(obj, &x1, &var1, &x2, &y2);
    int px, var5;
    g_touchInput.GetTouchPoint(&px, &var5);
    if (x1 <= px && px < x2 && var1 <= var5 && var5 < y2) return 1;
    return 0;
}
