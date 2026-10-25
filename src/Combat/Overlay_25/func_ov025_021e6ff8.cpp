#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8 {
    char unknown_0_[0xe];
    short unknown_e_;
};

struct Struct_ov025_021e6ff8 {
    char unknown_0_[8];
    unsigned char unknown_8_;
    char unknown_9_[3];
    fix32_t unknown_c_;
    fix32_t unknown_10_;
    fix32_t unknown_14_;
    int arg18;
    int unknown_1c_;
    int arg20;
    unsigned char unknown_24_;
};

extern "C" void* func_ov000_02160130(void);
extern "C" unsigned char func_ov025_021dcc64(void* arg0);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c* arg0, int arg1);
extern "C" void func_0202edf8(char* arg0, int arg1, int arg2, int arg3, int arg4);

// USA: func_ov025_021e6ff8
extern "C" ARM int func_ov025_021e6ff8(Struct_ov025_021e6ff8* arg0, Struct_ov000_0215440c* arg1) {
#if defined(jpn)
 enum { Enum_ov025_021e6ff8_28629=0x71c5 };
#else
 enum { Enum_ov025_021e6ff8_28629=0x6fd5 };
#endif
    GameState* gs = GameState::GetInstance();
    void* camera = gs->GetCamera();
    void* work = GetActiveCombatWork_ov000_02160130();
    if (work != NULL) {
        *((unsigned char*)work + regionalOffset) = 1;
        if (GetByte_021dcc64_021dcc64(work)) {
            return 1;
        }
    }
    Vector3fix var3 = *(Vector3fix*)((char*)var1 + 0x70);
    if (arg0->unknown_8_ & 1) {
        if (fix32SignedAngleDistance(var3.x, arg0->unknown_c_) > 0) {
            fix32_t var4 = arg0->unknown_c_;
            while (var4 < var3.x) {
                var4 += FIX_2PI;
            }
            var3.x = var4;
        } else {
            fix32_t var5 = arg0->unknown_c_;
            while (var3.x < var5) {
                var5 -= FIX_2PI;
            }
            var3.x = var5;
        }
    }
    if (arg0->unknown_8_ & 2) {
        var3.y = arg0->unknown_10_;
    }
    if (arg0->unknown_8_ & 4) {
        var3.z = arg0->unknown_14_;
    }
    if (arg0->unknown_24_ == 2) {
        int var6 = 1;
        Struct_ov000_021600f8* var7 = func_ov000_021600f8(arg1, 0);
        if (var7 != NULL) {
            GameObject* var8 = var0->GetCombatantByIndex(var7->unknown_e_);
            if (var8 != NULL) {
                var6 = var8->obj3D_.GetHeight();
            }
        }
        float var9 = 1.0f;
        if (var6 >= 0x1800) {
            var9 = 1.0f + 0.8f * ((float)var6 / 4096.0f - 1.5f) / 2.5f;
            if (var9 >= 1.8f) {
                var9 = 1.8f;
            }
        }
        float var10 = (float)var3.y / 4096.0f;
        float var11 = (float)var3.z / 4096.0f;
        var10 = var10 * var9;
        var11 = var11 * var9;
        var3.y = (int)(4096.0f * var10);
        var3.z = (int)(4096.0f * var11);
    }
    func_0202edf8((char*)var1, (int)&var3, arg0->arg18, arg0->unknown_1c_, arg0->arg20);
    return 1;
}
