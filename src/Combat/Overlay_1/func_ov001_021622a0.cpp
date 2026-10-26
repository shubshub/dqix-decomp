#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void* obj);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void _ZN6Zone3D10SwitchZoneEti(void* g, int val, int flag);

// USA: func_ov001_021622a0
extern "C" ARM int func_ov001_021622a0(void* ctx) {
    void* g = Zone3D_GetInstance(ctx);
    int v = func_ov017_021d60f4(ctx);
    _ZN6Zone3D10SwitchZoneEti(g, v, 0);
    return 1;
}
