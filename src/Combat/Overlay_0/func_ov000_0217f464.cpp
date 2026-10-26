#include <globaldefs.h>

// USA: func_ov000_0217f464
extern "C" ARM int func_ov000_0217f464(void* obj) {
    signed char idx = *((signed char*)obj + 0x18);
    signed char val = *((signed char*)obj + idx + 0x10);
    return val < 0x64;
}
