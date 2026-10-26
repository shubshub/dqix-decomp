#include <globaldefs.h>


extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* p);

// USA: func_020dbfe0
ARM int GetMasterBrightnessSub_020dbfe0() {
    return GXx_GetMasterBrightness_((volatile unsigned short*)0x400106c);
}
