#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021d60f4(void*);

// KEEP-NAME
// USA: func_ov001_02161f3c
ARM int SetGlobalOffset2750FromArg_02161f3c(void* obj) {
    void* g = Zone3D_GetInstance();
    int v = func_ov017_021d60f4(obj);
#if defined(jpn)
    *(int*)((char*)g + 0x2790) = v;
#else
    *(int*)((char*)g + 0x2750) = v;
#endif
    return 1;
}
