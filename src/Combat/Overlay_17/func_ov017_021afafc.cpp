#include <globaldefs.h>

// USA: func_ov017_021afafc
extern "C" ARM void func_ov017_021afafc(unsigned char* obj, int bit) {
    obj[0x20] |= (1 << bit);
}
