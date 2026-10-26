#include <globaldefs.h>

extern "C" int STD_GetStringLength(const char* s);

// USA: func_020d2f28
extern "C" ARM int func_020d2f28(char* dst, const char* src, int n) {
    int i = 0;
    const char* p = src;
    if (n - 1 > 0) {
        do {
            dst[i] = *p;
            if (*p == 0) break;
            i++;
            p++;
        } while (i < n - 1);
    }
    if (i >= n - 1) {
        if (n != 0) dst[i] = 0;
    }
    return STD_GetStringLength(src);
}
