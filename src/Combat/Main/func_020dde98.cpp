#include <globaldefs.h>

// USA: func_020dde98
extern "C" ARM void func_020dde98(void* obj, short value) {
    *(short*)((char*)obj + 0x2) = value;
}
