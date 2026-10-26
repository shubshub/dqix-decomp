#include <globaldefs.h>

// USA: func_020340f4
ARM void ClearByte0xc1Flag0x4_020340f4(unsigned char* object) {
    object[0xc1] &= ~4;  // set by SetByte0xc1Flag0x4_020340e4; no reader found
}
