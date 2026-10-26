#include <globaldefs.h>

// USA: func_ov023_021f9ca8
extern "C" ARM void func_ov023_021f9ca8(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0x58) = value;
}
