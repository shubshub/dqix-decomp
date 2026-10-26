#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x79c3
#define REGION_OFFSET_1 0x79c4
#else
#define REGION_OFFSET_0 0x77d3
#define REGION_OFFSET_1 0x77d4
#endif

// USA: func_ov000_0216872c
extern "C" ARM void func_ov000_0216872c(void* obj, int a, int b) {
    *(unsigned char*)((char*)obj + REGION_OFFSET_0) = (unsigned char)a;
    *(unsigned char*)((char*)obj + REGION_OFFSET_1) = (unsigned char)b;
}
