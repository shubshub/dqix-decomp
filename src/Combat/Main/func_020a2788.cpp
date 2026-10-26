#include <globaldefs.h>

// USA: func_020a2788
extern "C" ARM void func_020a2788(void* obj, short value) {
    *(short*)((char*)obj + 0x246) = value;
}
