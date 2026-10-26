#include <globaldefs.h>

// USA: func_020dde90
extern "C" ARM void func_020dde90(void* obj, short value) {
    *(short*)((char*)obj + 0x0) = value;
}
