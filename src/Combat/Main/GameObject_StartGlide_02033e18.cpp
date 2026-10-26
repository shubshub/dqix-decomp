#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

// Main, originally SetHalf0xc6AndCopyVec3_02033e18 (USA 0x02033e18, EUR 0x02033e28, JPN 0x02033950)
extern "C" ARM void GameObject_StartGlide(void* obj, int* src, short val) {
    *(short*)((char*)obj + 0xc6) = val;
    *(Vector3i*)((char*)obj + 0xc8) = *(Vector3i*)src;
}
