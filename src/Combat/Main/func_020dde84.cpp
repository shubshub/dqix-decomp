#include <globaldefs.h>

// USA: func_020dde84
extern "C" ARM void func_020dde84(char* obj, int a, int b) {
    *(int*)(obj + 0x8) = a;
    *(int*)(obj + 0xc) = b;
}
