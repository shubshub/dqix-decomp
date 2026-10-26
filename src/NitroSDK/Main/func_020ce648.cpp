#include <globaldefs.h>

extern "C" int func_020ce4e8(int a, int b, int c, void* callback, int* out);

// USA: func_020ce648
extern "C" ARM int func_020ce648(int a, int b, void (*callback)(void), int* out) {
    int code = 0;
    if (a == 0) {
        if (b == 1) code = 6;
        if (b == 0) code = 7;
    } else if (a == 1) {
        if (b == 1) code = 4;
        if (b == 0) code = 5;
    } else if (a == 2) {
        if (b == 1) code = 8;
        if (b == 0) code = 9;
    }
    if (code == 0) return 0xffff;
    return func_020ce4e8(code, 0, 0, (void*)callback, out);
}
