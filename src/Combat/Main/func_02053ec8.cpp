#include <globaldefs.h>

// USA: func_02053ec8
extern "C" ARM void func_02053ec8(void* obj, int value) {
#if defined(jpn)
    *(int*)((char*)obj + 0x14c) = value;
#else
    *(int*)((char*)obj + 0x158) = value;
#endif
}
