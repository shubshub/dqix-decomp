#include <globaldefs.h>

// USA: func_ov023_021fd394
extern "C" ARM void func_ov023_021fd394(void* dst, int* src) {
    *(unsigned short*)((char*)dst + 0x22) = (unsigned short)((float)src[0] / 4096.0f);
    *(unsigned short*)((char*)dst + 0x24) = (unsigned short)((float)src[1] / 4096.0f);
}
