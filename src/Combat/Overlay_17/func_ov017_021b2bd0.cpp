#include <globaldefs.h>

// USA: func_ov017_021b2bd0
extern "C" ARM void func_ov017_021b2bd0(void* obj, int a, int b) {
    *(int*)((char*)obj + 0x30) = a;
    *(int*)((char*)obj + 0x34) = b;
}
