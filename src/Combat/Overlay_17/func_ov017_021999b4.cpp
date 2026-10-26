#include <globaldefs.h>

// USA: func_ov017_021999b4
extern "C" ARM int func_ov017_021999b4(int screenSize, int colorMode, int screenBase, int charBase) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x400000c;
    int value = (*var0 & 0x43) | (screenSize << 14);
    value |= (colorMode << 7);
    value |= (screenBase << 8);
    value |= (charBase << 2);
    *var0 = value;
    return value;
}
