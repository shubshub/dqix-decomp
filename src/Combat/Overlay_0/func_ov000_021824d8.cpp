#include <globaldefs.h>

// USA: func_ov000_021824d8
extern "C" ARM void func_ov000_021824d8(void* objRaw) {
    char* obj = (char*)objRaw;
    if (*(short*)(obj + 0x600 + 0xea) > 0) {
        *(short*)(obj + 0x600 + 0xea) = *(short*)(obj + 0x600 + 0xea) - 1;
    }
    if (*(short*)(obj + 0x600 + 0xec) <= 0) {
        return;
    }
    *(short*)(obj + 0x600 + 0xec) = *(short*)(obj + 0x600 + 0xec) - 1;
    if (*(short*)(obj + 0x600 + 0xec) == 0) {
        obj[0x6e8] = 0;
        obj[0x6e9] = 0;
    }
}
