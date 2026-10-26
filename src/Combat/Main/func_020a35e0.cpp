#include <globaldefs.h>

// USA: func_020a35e0
extern "C" ARM int func_020a35e0(unsigned char* obj, unsigned char index) {
    if (index >= 4) {
        return 0;
    }
    return obj[0x34] & (1 << index);
}
