#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"
#if defined(jpn)
enum { Enum_020a7ce0_1844 = 0x524 };
enum { Enum_020a7ce0_1940 = 0x7d4 };
#else
enum { Enum_020a7ce0_1844 = 0x734 };
enum { Enum_020a7ce0_1940 = 0x794 };
#endif

extern "C" void* Zone3D_GetInstance(void);

extern "C" int _s32_div_f(int a, int b);

struct Struct_020a7ce0 {
    char pad0[0x44];
    Vector3i vec44;
    char pad1[0x144 - 0x50];
    Vector3i unknown_144_;
    int unknown_150_;
};

// USA: func_020a7ce0
extern "C" ARM void func_020a7ce0(struct Struct_020a7ce0* p) {
    void* ctx = Zone3D_GetInstance();
    void* ov = GetGameResources();
    char* g = (char*)ov + 0x3000;
    void* var3 = *(void**)(g + Enum_020a7ce0_1844);
    if (((unsigned char*)var3)[3] != 0) return;

    Vector3i local = p->vec44;
    int dist = Vector3fix_Distance(&local, &p->unknown_144_);
    p->unknown_150_ += dist;
    if (p->unknown_150_ >= 0x3000) {
        int q = _s32_div_f(p->unknown_150_, 0x3000);
        char* base = (char*)ctx + 0x2000;
        *(int*)(base + Enum_020a7ce0_1940) -= q;
        p->unknown_150_ -= q << 12;
    }
    p->unknown_144_ = local;
}
