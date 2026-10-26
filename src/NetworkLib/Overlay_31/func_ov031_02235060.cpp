#include <globaldefs.h>

extern "C" ARM void *func_ov031_0223e218(void *a, void *b, void *c, int d);
extern int data_ov031_02290ce8;
extern "C" void func_ov031_0223508c(int);

// USA: func_ov031_02235060
extern "C" ARM void *func_ov031_02235060(int v) {
    *(int*)((char*)&data_ov031_02290ce8 + 0x4) = v;
    return func_ov031_0223e218((void*)1, (void*)func_ov031_0223508c, 0, 0x78);
}
