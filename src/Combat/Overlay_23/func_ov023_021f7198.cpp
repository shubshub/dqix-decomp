#include <globaldefs.h>

// USA: func_ov023_021f7198
extern "C" ARM void func_ov023_021f7198(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0xaa) = value;
}
