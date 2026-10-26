#include <globaldefs.h>


// USA: func_ov031_0221e610
extern "C" THUMB unsigned int func_ov031_0221e610(unsigned int value) {
    return (unsigned char)(value >> 24) | ((value >> 8) & 0xff00) |
           ((value << 8) & 0xff0000) | ((value << 24) & 0xff000000);
}
