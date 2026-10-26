#include <globaldefs.h>

// USA: func_ov023_021f9c48
extern "C" ARM void func_ov023_021f9c48(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0x40) = value;
}
