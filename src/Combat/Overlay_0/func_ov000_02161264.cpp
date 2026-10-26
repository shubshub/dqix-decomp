#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x57e4
#else
#define REGION_OFFSET_0 0x55f4
#endif

// USA: func_ov000_02161264
extern "C" ARM int func_ov000_02161264(void* work) {
    return *(int*)((char*)work + REGION_OFFSET_0) & 0x400;
}
