#include <globaldefs.h>

// USA: func_02049c60
extern "C" ARM void func_02049c60(unsigned char* obj, int* src) {
    if (*(int**)(obj + 0x13c) == 0) return;
    (*(int**)(obj + 0x13c))[5] = src[1];
    (*(int**)(obj + 0x13c))[8] &= ~0x1;
}
