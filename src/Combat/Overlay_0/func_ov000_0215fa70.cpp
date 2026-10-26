#include <globaldefs.h>

// USA: func_ov000_0215fa70
extern "C" ARM void func_ov000_0215fa70(void* obj, short a, short b, short c) {
    *(short*)((char*)obj + 0x8e4a) = (short)a;
    *(short*)((char*)obj + 0x8e4c) = (short)b;
    *(short*)((char*)obj + 0x8e4e) = (short)c;
}
