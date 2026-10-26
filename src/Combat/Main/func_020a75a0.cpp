#include <globaldefs.h>

extern "C" void GameObject_Initialize(void*);

// USA: func_020a75a0
extern "C" ARM void func_020a75a0(char* obj) {
    GameObject_Initialize(obj);
    *(unsigned short*)obj |= 0x8000;
    *(int*)(obj + 0x134) = 0;
    *(int*)(obj + 0x138) = 0;
    *(short*)(obj + 0x13c) = 0;
    *(int*)(obj + 0x140) = 0;
    *(int*)(obj + 0x150) = 0;
    *(int*)(obj + 0x144) = 0;
    *(int*)(obj + 0x148) = 0;
    *(int*)(obj + 0x14c) = 0;
    obj[0x15a] = 1;
}
