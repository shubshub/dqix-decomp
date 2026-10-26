#include <globaldefs.h>
#include "NitroSDK/Graphics.h"

// USA: func_ov023_021ec454
extern "C" ARM void func_ov023_021ec454(int arg0, int arg1, int arg2, int charBase) {
    BG2CNT = (unsigned short)((BG2CNT & 0x43) | (arg0 << 14) | (arg1 << 7) | (arg2 << 8) | (charBase << 2));
}
