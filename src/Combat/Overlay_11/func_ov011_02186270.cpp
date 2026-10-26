#include <globaldefs.h>

// USA: func_ov011_02186270
extern "C" ARM void func_ov011_02186270(int screenSize, int colorMode, int screenBase, int charBase, int bit13) {
    unsigned short* reg = (unsigned short*)0x4000008;
    *reg = (*reg & 0x43) | (screenSize << 0xe) | (colorMode << 0x7) | (screenBase << 0x8) | (charBase << 0x2) | (bit13 << 0xd);
}
