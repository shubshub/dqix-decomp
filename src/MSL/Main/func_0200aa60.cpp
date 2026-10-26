#include <globaldefs.h>

// USA: func_0200aa60
extern "C" ARM int func_0200aa60(int a, ...) {
    int b = *((int*)&a + 1);
    return b & 0x80000000;
}
