#include <globaldefs.h>

// USA: func_ov011_0218623c
extern "C" ARM void func_ov011_0218623c(int screenSize, int colorMode, int screenBase, int charBase, int bit13) {
    unsigned short* reg = (unsigned short*)0x400000a;
    *reg = (*reg & 0x43) | (screenSize << 0xe) | (colorMode << 0x7) | (screenBase << 0x8) | (charBase << 0x2) | (bit13 << 0xd);
}
