#include <globaldefs.h>

extern "C" signed char func_020d8550(int c);

// USA: func_020d85dc
extern "C" ARM int func_020d85dc(const char* str, const char* prefix) {
    if (str == 0) {
        return 0;
    }
    if (prefix == 0) {
        return 0;
    }
    if (str == prefix) {
        return 1;
    }
    signed char a, b;
    while ((a = *str) != 0 && (b = *prefix) != 0 && func_020d8550(a) == func_020d8550(b)) {
        str++;
        prefix++;
    }
    return (*prefix == 0) ? 1 : 0;
}
