#include <globaldefs.h>

// USA: func_ov006_02153c60
extern "C" ARM void func_ov006_02153c60(void* p, int a, unsigned short b) {
    *(int*)((char*)p + 0x20) = a;
    *(unsigned short*)((char*)p + 0x24) = b;
}
