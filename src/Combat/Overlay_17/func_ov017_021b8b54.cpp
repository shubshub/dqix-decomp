#include <globaldefs.h>

// USA: func_ov017_021b8b54
extern "C" ARM int func_ov017_021b8b54(void* obj) {
    unsigned short v = *(unsigned short*)((char*)obj + 0x600 + 0xb4);
    return v == 0 ? 1 : 0;
}
