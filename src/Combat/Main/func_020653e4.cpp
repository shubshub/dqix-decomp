#include <globaldefs.h>
#include "NitroSDK/Graphics.h"
#include "NitroSDK/Matrix.h"

// USA: func_020653e4
extern "C" ARM void func_020653e4(fix32_t s, fix32_t t) {
    short var0 = s >> 8;
    short var1 = t >> 8;
    GXFIFO_VERTEX_TEXCOORD = static_cast<unsigned short>(var0) |
                            (static_cast<unsigned int>(static_cast<unsigned short>(var1)) << 16);
}
