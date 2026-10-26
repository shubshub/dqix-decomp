#include <globaldefs.h>

// USA: func_ov023_021fc470
extern "C" ARM void func_ov023_021fc470(void* dst, int* src) {
    *(unsigned short*)((char*)dst + 0x26) = (unsigned short)((float)src[0] / 4096.0f);
    *(unsigned short*)((char*)dst + 0x28) = (unsigned short)((float)src[1] / 4096.0f);
}
