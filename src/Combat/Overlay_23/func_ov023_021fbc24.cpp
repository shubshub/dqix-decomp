#include <globaldefs.h>

// USA: func_ov023_021fbc24
extern "C" ARM void func_ov023_021fbc24(void* dst, int* src) {
    *(unsigned short*)((char*)dst + 0x32) = (unsigned short)((float)src[0] / 4096.0f);
    *(unsigned short*)((char*)dst + 0x34) = (unsigned short)((float)src[1] / 4096.0f);
}
