#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void* func_020bd8ac(unsigned int);

// USA: func_020c0110
extern "C" ARM int func_020c0110(char* obj, void* arg) {
    void* p = func_020bd8ac((unsigned int)arg);
    *(void**)(obj + 0xa4) = p;
    VectorizedInvertedMemcpy(p, obj + 0xa8, 0x40);
    return 1;
}
