#include <globaldefs.h>


extern "C" ARM int func_ov031_022073a4(int a, int b, int c, int d, int e);

// USA: func_ov031_02220178
extern "C" THUMB int func_ov031_02220178(int a, int b, int unused, int c, int d) {
    int result = func_ov031_022073a4(a, c, d, 0, b);
    if (result < 0) {
        result = -4;
    }
    return result;
}
