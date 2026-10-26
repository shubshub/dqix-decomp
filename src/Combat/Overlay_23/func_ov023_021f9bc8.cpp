#include <globaldefs.h>

// USA: func_ov023_021f9bc8
extern "C" ARM int func_ov023_021f9bc8(char* obj) {
    return *(unsigned short*)(obj + 0x28) * *(unsigned short*)(obj + 0x26) + *(unsigned short*)(obj + 0x2a);
}
