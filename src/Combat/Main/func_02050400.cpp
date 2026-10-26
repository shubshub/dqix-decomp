#include <globaldefs.h>

// USA: func_02050400
extern "C" ARM void func_02050400(unsigned char* obj, int value) {
    obj[0xd8] = (obj[0xd8] & ~1) | (value & 1);
    obj[0xd8] |= 2;
    obj[0xd9] = 0;
    obj[0xda] = 0;
}
