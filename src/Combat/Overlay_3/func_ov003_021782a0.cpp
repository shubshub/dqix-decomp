#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0207fdcc_2;
struct Struct_0207fdcc;
extern "C" struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int id);
extern "C" int WindowPane_IsReady(unsigned char* p);
extern "C" void func_ov003_02173f08(char* a, char* b, char* c, char* d);

// USA: func_ov003_021782a0
extern "C" ARM int func_ov003_021782a0(struct Struct_0207fdcc_2* obj) {
    if (g_touchInput.isRepeatValid_ == 0 || g_touchInput.currentReading_.isHeld == 0)
        return 0;

    int var0, var1;
    g_touchInput.GetTouchPoint(&var0, &var1);
    if (var1 < 0x5d || var1 > 0x6e)
        return 0;

#if defined(jpn)
    if (var0 >= 0x8c && var0 <= 0xb7)
        return 1;
    if (var0 >= 0xc8 && var0 <= 0xf0)
        return -1;
    return 0;
#else
    struct Struct_0207fdcc_2* target = *(struct Struct_0207fdcc_2**)((char*)obj + 0x89c);
    struct Struct_0207fdcc* elem = func_02081da8(target, 10);
    if (!elem)
        return 0;
    if (!WindowPane_IsReady((unsigned char*)elem))
        return 0;

    char c0, c1, c2, c3;
    func_ov003_02173f08(&c0, &c1, &c2, &c3);

    short h = *(short*)((char*)elem + 0xac);
    short x1 = c0 + (short)(h << 3);
    short x2 = c1 + (short)(h << 3);
    short var11 = c2 + x1;
    short y2 = c3 + x2;

    int point = var0;
    if (point >= x1) {
        if (point <= var11)
            return 1;
    }
    if (x1 <= point && point <= y2)
        return -1;
    return 0;
#endif
}
