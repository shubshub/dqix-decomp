#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x79de
#else
#define REGION_OFFSET_0 0x77ee
#endif


// USA: func_ov000_02168720
extern "C" ARM unsigned char func_ov000_02168720(char* obj) {
    return *(unsigned char*)(obj + REGION_OFFSET_0);
}
