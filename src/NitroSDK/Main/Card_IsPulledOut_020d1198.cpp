#include <globaldefs.h>
#include "NitroSDK/Filesystem/FSInnerDefs.h"

extern int data_02112140;

// Main, originally func_020d1198 (USA 0x020d1198, EUR 0x020d11a8, JPN 0x020d2c64)
ARM CBool Card_IsPulledOut() {
    return data_02112140;
}
