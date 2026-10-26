#include <globaldefs.h>

// USA: func_ov011_02186150
extern "C" ARM void func_ov011_02186150(int screenSize, int colorMode, int screenBase, int charBase) {
    unsigned short* reg = (unsigned short*)0x400100c;
    *reg = (*reg & 0x43) | (screenSize << 0xe) | (colorMode << 0x7) | (screenBase << 0x8) | (charBase << 0x2);
}
