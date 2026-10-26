#include <globaldefs.h>

// USA: func_ov017_021afb34
extern "C" ARM void func_ov017_021afb34(void* objRaw, int arg1) {
    unsigned char* obj = (unsigned char*)objRaw;
    obj[0x27] |= (1 << arg1);
    int i;
    for (i = 1; i < 4; i++) {
        if ((obj + i)[0x1b] == 1) {
            if (!(obj[0x27] & (1 << i))) break;
        }
    }
    obj[0x27] |= 0x10;
}
