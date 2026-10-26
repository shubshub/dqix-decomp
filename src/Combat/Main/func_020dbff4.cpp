#include <globaldefs.h>


extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* p);

// USA: func_020dbff4
ARM int GetMasterBrightnessMain_020dbff4() {
    return GXx_GetMasterBrightness_((volatile unsigned short*)0x400006c);
}
