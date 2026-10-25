#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"

extern "C" void* Zone3D_GetInstance(void* self);
unsigned char* Zone3D_GetChest(unsigned char* p, int i);

struct Struct_ov017_021d6318 {
    unsigned char unknown_0_[0xc0];
};

extern Struct_ov017_021d6318 data_ov017_021d6318;

struct Struct_ov017_02193290 {
    Struct_ov017_021d6318 unknown_0_;
    unsigned char unknown_c0_[0x900 - 0xc0];
    int unknown_900_;
    int unknown_904_;
    Vector3i unknown_908_;
    int unknown_914_;
    int unknown_918_;
    unsigned char unknown_91c_[0x980 - 0x91c];
};

struct Struct_ov017_02193290_2 {
    Vector3i unknown_0_;
    short unknown_c_;
};

struct Struct_ov017_02193290_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x497];
#else
    unsigned char unknown1_0_[0x477];
#endif
    unsigned char unknown_477_;
};

extern "C" int func_ov017_02192b48(Struct_ov017_02193290* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, Vector3i* arg6, int arg7, int arg8, int arg9, int* arg10, int arg11, int arg12, int arg13);

static inline fix32_t inline_ov000_0216f3d4(fix32_t arg0) {
    return FIX32_MULTIPLY(arg0, arg0);
}

// USA: func_ov017_02193290
extern "C" ARM int func_ov017_02193290(int a, int b, int c, Vector3i* pos, int d, int e, int f) {
    Owner02193290* owner = (Owner02193290*)Zone3D_GetInstance(GameState::GetInstance());
    int total = 0;
    for (int i = 0; i < owner->count; i++) {
        Element02193290* elem = (Element02193290*)Zone3D_GetChest((unsigned char*)owner, i);
        if (elem == NULL) {
            continue;
        }
        Vector3i var4 = *arg3;
        Vector3i var5 = var3->unknown_0_;
        if (fix32abs(var4.y - var5.y) > 0x1000) {
            continue;
        }
        var4.y = 0;
        var5.y = 0;
        Vector3fix_Subtract(&var4, &var5, &var4);
        if (inline_ov000_0216f3d4(var4.x) + inline_ov000_0216f3d4(var4.z) > 0x1000) {
            continue;
        }
        Struct_ov017_02193290 var6;
        memset(&var6, 0, sizeof(var6));
        memcpy(&var6.unknown_0_, &data_ov017_021d6318, sizeof(Struct_ov017_021d6318));
        var6.unknown_900_ = 8;
        var6.unknown_904_ = 1;
        var6.unknown_908_ = var3->unknown_0_;
        var6.unknown_918_ = var3->unknown_c_;
        int var7 = 0;
        var1 += func_ov017_02192b48(&var6, arg0, 8, arg1, 1, arg2, arg3, arg4, arg5, 1, &var7, 0, var2, arg6);
    }
    return var1;
}
