#include <globaldefs.h>

extern char data_020e8ebc;

// USA: func_0209c0f4
extern "C" ARM int func_0209c0f4(int value, int type) {
    char* p;
    if (type != 0x17) return 1;
    if (value < 0) return 1;
    p = &data_020e8ebc;
    while (*p > -1) {
        if (*p == value) return 0;
        p++;
    }
    return 1;
}
