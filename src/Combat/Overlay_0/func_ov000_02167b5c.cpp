#include <globaldefs.h>

extern "C" int _s32_div_f(int a, int b);

// USA: func_ov000_02167b5c
extern "C" ARM int func_ov000_02167b5c(int a, int b) {
    int var0 = b - 1;
    int result = 0xb33;
    int var2 = var0 * 0x199 + 0x4000;
    int r3 = var0 * 0xb33 + a;
    if (r3 >= var2) {
        if (var2 < a) {
            result = 0x199;
        } else if ((unsigned int)b > 1) {
            result = _s32_div_f(var2 - a, var0);
        }
    }
    return result;
}
