#include <globaldefs.h>

// USA: func_ov023_021f9c50
extern "C" ARM void func_ov023_021f9c50(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0x42) = value;
}
