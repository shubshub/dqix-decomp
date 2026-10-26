#include <globaldefs.h>
#include "NitroSDK/Graphics.h"

// USA: func_0208c9cc
extern "C" ARM void func_0208c9cc(int screenSize, int colorMode, int screenBase, int charBase, int arg4) {
    BG0CNTSUB = (BG0CNTSUB & 0x43) | (screenSize << 14) | (colorMode << 7) |
                (screenBase << 8) | (charBase << 2) | (arg4 << 13);
}
