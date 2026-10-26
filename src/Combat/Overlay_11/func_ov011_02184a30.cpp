#include <globaldefs.h>

// USA: func_ov011_02184a30
extern "C" ARM void* func_ov011_02184a30(void* obj, unsigned int* outCount) {
    *outCount = *(unsigned int*)((char*)obj + 0x1b8);
    return *(void**)((char*)obj + 0x1b4);
}
