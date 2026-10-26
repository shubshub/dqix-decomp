#include <globaldefs.h>

// USA: func_020d9808
extern "C" ARM int func_020d9808(int* value, int* lo, int* hi) {
    int var0 = *lo;
    int v = *value;
    if (v <= var0) {
        v = var0;
    }
    if (v >= *hi) {
        v = *hi;
    }
    return v;
}
