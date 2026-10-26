#include <globaldefs.h>

// USA: func_ov023_021f8aec
extern "C" ARM void func_ov023_021f8aec(void* dst, int* src) {
    *(unsigned short*)((char*)dst + 0x3a) = (unsigned short)((float)src[0] / 4096.0f);
    *(unsigned short*)((char*)dst + 0x3c) = (unsigned short)((float)src[1] / 4096.0f);
}
