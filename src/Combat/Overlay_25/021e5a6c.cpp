#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov025_021e5a6c_28629 = 0x71c5 };
#else
enum { Enum_ov025_021e5a6c_28629 = 0x6fd5 };
#endif

struct Struct_ov009_0218aa28 { int unknown_0_; int unknown_4_; int unknown_8_; };

struct Struct_ov025_021e5a6c {
    char unknown_0_[8];
    Struct_ov009_0218aa28 unknown_8_;
    unsigned char unknown_14_;
};

struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8;

extern "C" struct Struct_ov000_021600f8* func_ov000_021600f8(struct Struct_ov000_0215440c* arg0, int arg1);
struct Vector3i;
extern "C" void* func_ov000_02160130(void);

// USA: func_ov025_021e5a6c
extern "C" ARM int func_ov025_021e5a6c(struct Obj021e5a6c* obj, struct List021600f8* list) {
    GameState* bs = GameState::GetInstance();
    void* f = bs->GetCamera();
    unsigned char mode = obj->mode;
    if (mode == 0) {
        if (f != 0) {
            *(Vector3i*)((int*)((char*)f + 0x10)) = *(Vector3i const*)((int*)&obj->pos);
        }
    } else if (var2 == 2) {
        int var3 = 1;
        struct Struct_ov000_021600f8* var4 = func_ov000_021600f8(arg1, 0);
        if (var4 != 0) {
            GameObject* var5 = var0->GetCombatantByIndex(*(short*)((char*)var4 + 0xe));
            if (var5 != 0) {
                var3 = var5->obj3D_.GetHeight();
            }
        }
        float var6 = 1.0f;
        if (var3 >= 9420) {
            var6 = 1.0f + 0.6f * ((float)var3 / 4096.0f - 2.3f) / 1.7f;
            if (var6 >= 1.6f) {
                var6 = 1.6f;
            }
        }
        float var7 = (float)arg0->unknown_8_.unknown_4_ / 4096.0f;
        float var8 = (float)arg0->unknown_8_.unknown_8_ / 4096.0f;
        var7 = var7 * var6;
        var8 = var8 * var6;
        arg0->unknown_8_.unknown_4_ = (int)(4096.0f * var7);
        arg0->unknown_8_.unknown_8_ = (int)(4096.0f * var8);
        if (var1 != 0) {
            *(Vector3i*)((int*)((char*)var1 + 0x10)) = *(Vector3i const*)((int*)&arg0->unknown_8_);
        }
    } else {
        if (var1 != 0) {
            Struct_ov009_0218aa28 var9 = *(Struct_ov009_0218aa28*)((char*)var1 + 0x10);
            Struct_ov009_0218aa28 var10 = arg0->unknown_8_;
            var9.unknown_0_ = var9.unknown_0_ + var10.unknown_0_;
            var9.unknown_4_ = var9.unknown_4_ + var10.unknown_4_;
            var9.unknown_8_ = var9.unknown_8_ + var10.unknown_8_;
            *(Vector3i*)((int*)((char*)var1 + 0x10)) = *(Vector3i const*)((int*)&var9);
        }
    }
    void* var11 = func_ov000_02160130();
    if (var11 != 0) {
        *(unsigned char*)((char*)var11 + Enum_ov025_021e5a6c_28629) = 1;
    }
    return 1;
}
