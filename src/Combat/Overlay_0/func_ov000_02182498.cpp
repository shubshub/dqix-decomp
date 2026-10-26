#include <globaldefs.h>

// USA: func_ov000_02182498
extern "C" ARM void func_ov000_02182498(void* objRaw, int flag) {
    unsigned char* obj = (unsigned char*)objRaw;
    if (flag != 0) {
        if (obj[0x6e8] != 0) {
            obj = obj + 0x600;
            if (*(short*)(obj + 0xec) == 0) {
                *(short*)(obj + 0xec) = *(short*)(obj + 0xea) + 5;
            }
        }
    } else {
        obj[0x6e8] = 0;
        obj[0x6e9] = 0;
    }
}
