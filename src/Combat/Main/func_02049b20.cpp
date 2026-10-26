#include <globaldefs.h>

// USA: func_02049b20
extern "C" ARM void func_02049b20(unsigned char* obj, int* src) {
    if (*(int**)(obj + 0x13c) == 0) {
        return;
    }
    (*(int**)(obj + 0x13c))[1] = src[0];
    (*(int**)(obj + 0x13c))[3] = src[2];
    (*(int**)(obj + 0x13c))[8] &= ~0x2;
}
