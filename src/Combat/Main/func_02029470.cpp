#include <globaldefs.h>

// USA: func_02029470
extern "C" ARM void func_02029470(int a, int b, int c, int d, int e, int f) {
    *(unsigned int*)0x040004a4 = a | (b << 4) | (c << 6) | f | (d << 24) | (e << 16);
}
