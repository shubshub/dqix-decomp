#include <globaldefs.h>

// USA: func_020ddff4
extern "C" ARM void func_020ddff4(void* obj, int value) {
    *(int*)((char*)obj + 0x20) = value;
}
