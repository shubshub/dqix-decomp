#include <globaldefs.h>

extern void* data_02111304;

// USA: func_ov031_0220321c
extern "C" ARM void func_ov031_0220321c(void) {
    void* mgr = *((void**)&data_02111304 + 1);
    void* session = *(void**)((char*)mgr + 0xa4);
    if (session == NULL) return;
    *(void**)((char*)session + 0x0) = mgr;
    *(unsigned char*)((char*)session + 0x8) = 0;
    *(int*)((char*)session + 0x44) = 0;
    *(int*)((char*)session + 0x60) = 0;
    *(int*)((char*)session + 0x38) = 0;
}
