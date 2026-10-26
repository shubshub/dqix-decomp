#include <globaldefs.h>

extern "C" int func_020ce4e8(int a, int b, int c, void* callback, int* out);

// USA: func_020ce5b0
extern "C" ARM int func_020ce5b0(int a, void (*callback)(void), int* out) {
    int var0;
    switch (a) {
        case 1: var0 = 1; break;
        case 3: var0 = 2; break;
        case 2: var0 = 3; break;
        default: var0 = 0; break;
    }
    if (var0 == 0) {
        return 0xffff;
    }
    return func_020ce4e8(var0, 0, 0, (void*)callback, out);
}
