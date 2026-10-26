#include <globaldefs.h>

extern "C" void func_ov014_02184a64(void*);

// USA: func_ov014_02186d64
extern "C" ARM void func_ov014_02186d64(void* obj) {
    if (*(unsigned char*)((char*)obj + 0x17a) == 4) {
        func_ov014_02184a64(obj);
    }
}
