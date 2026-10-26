#include <globaldefs.h>

// USA: func_ov025_021e8a54
extern "C" ARM void* func_ov025_021e8a54(char* obj) {
    unsigned char idx = *(unsigned char*)(obj + 0x30);
    return *(void**)(obj + 0x10 + idx * 4);
}
