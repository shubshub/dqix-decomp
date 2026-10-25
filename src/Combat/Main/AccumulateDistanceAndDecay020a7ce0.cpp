#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"
#if defined(jpn)
enum { kContextField = 0x524 };
enum { kDistanceField = 0x7d4 };
#else
enum { kContextField = 0x734 };
enum { kDistanceField = 0x794 };
#endif

extern "C" void* Zone3D_GetInstance(void);

extern "C" int _s32_div_f(int a, int b);

struct Obj020a7ce0 {
    char pad0[0x44];
    Vector3i vec44;
    char pad1[0x144 - 0x50];
    Vector3i vec144;
    int dist150;
};

// USA: func_020a7ce0  (semantic: AccumulateDistanceAndDecay020a7ce0)
extern "C" ARM void func_020a7ce0(struct Obj020a7ce0* p) {
    void* ctx = Zone3D_GetInstance();
    void* ov = GetGameResources();
    char* g = (char*)ov + 0x3000;
    void* g734 = *(void**)(g + kContextField);
    if (((unsigned char*)g734)[3] != 0) return;

    Vector3i local = p->vec44;
    int dist = Vector3fix_Distance(&local, &p->vec144);
    p->dist150 += dist;
    if (p->dist150 >= 0x3000) {
        int q = _s32_div_f(p->dist150, 0x3000);
        char* base = (char*)ctx + 0x2000;
        *(int*)(base + kDistanceField) -= q;
        p->dist150 -= q << 12;
    }
    p->vec144 = local;
}
