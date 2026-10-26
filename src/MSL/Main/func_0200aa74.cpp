#include <globaldefs.h>


// USA: func_0200aa74
extern "C" ARM int func_0200aa74(double x) {
    unsigned int hi = ((unsigned int*)&x)[1];
    unsigned int var1 = hi & 0x7ff00000;
    if (var1 == 0) goto zerocase;
    if (var1 != 0x7ff00000) goto normalcase;
    if ((hi & 0xfffff) != 0 || ((unsigned int*)&x)[0] != 0) {
        return 1;
    }
    return 2;
zerocase:
    if ((hi & 0xfffff) != 0 || ((unsigned int*)&x)[0] != 0) {
        return 5;
    }
    return 3;
normalcase:
    return 4;
}
