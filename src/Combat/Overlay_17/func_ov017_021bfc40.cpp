#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

int GameResources_IsSpecialItemEffectPlaying(void* obj);
int GetByteField0x252_02039820(void* obj);
void GameObject_EnableControl(void* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
int MessageSystem_GetInstance(void);

struct Vec3copy0202ec84 { unsigned int v[3]; };
int Camera_WorldToScreen(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct Struct_02015ef4_2;
extern "C" void func_020473c8(struct Struct_02015ef4_2* arg0, int arg1);

struct Struct_ov017_021bfc40 {
    char unknown_0_[0x8];
    unsigned short unknown_8_;
    char unknown_a_[0x10 - 0xa];
    unsigned char* unknown_10_;
    char unknown_14_[0x16 - 0x14];
    short unknown_16_;
    short unknown_18_;
    char unknown_1a_[0x28 - 0x1a];
    struct Struct_02015ef4 unknown_28_;
    char unknown_34_[0x48 - 0x34];
    unsigned char unknown_48_;
};

// USA: func_ov017_021bfc40
extern "C" ARM int func_ov017_021bfc40(struct Struct_ov017_021bfc40* arg0) {
    GameState* var0 = GameState::GetInstance();
    int var1 = var0->GetTickCount();
    GameResources* var2 = GetGameResources();

    if (self->skip != 0) {
        GameResources* res2 = GetGameResources();
        if (GameResources_IsSpecialItemEffectPlaying(res2) != 0) {
            return 4;
        }
        GameObject* combatant = battle->GetUnknownGameObject();
        if (combatant != NULL && GetByteField0x252_02039820(combatant) == 0) {
            GameObject_EnableControl(combatant);
        }
        int var5 = func_020100f8((char*)var0);
        if (var5 != 0) {
            func_020a27ac((void*)var5);
        }
        if (var3 != NULL) {
            ClearFlags04(var3, 0x80);
        }
        arg0->unknown_16_ = 0;
        arg0->unknown_8_ = 0;
        return 6;
    }

    GameState* state = GameState::GetInstance();
    void* ptr3b0 = state->GetCamera();
    struct Vec3copy0202ec84 vecBuf = self->pos;

    if (arg0->unknown_18_ < 0x191e) {
        arg0->unknown_18_ += var6->GetTickCount() * 0x199;
    }

    var8.unknown_0_[1] += fix32sin(arg0->unknown_18_);

    int screenY;
    int screenX;
    if (ptr3b0 != NULL) {
        Camera_WorldToScreen(ptr3b0, &vecBuf, &screenX, &screenY);
    }

    int var11 = (var10 - 0xc) << 0xc;
    int var12 = (var9 - 0x28) << 0xc;
    unsigned char* var13 = arg0->unknown_10_;
    *(int*)(var13 + 0x1c) = var11;
    *(int*)(var13 + 0x20) = var12;
    *(int*)(var13 + 0x24) = 0;
    func_020473c8((struct Struct_02015ef4_2*)var13, 1);

    short var14 = arg0->unknown_16_;
    if (var14 > 0x1f) {
        var14 = 0x1f;
    }
    *(short*)(var13 + 0x82) = var14;

    unsigned int var15 = var0->GetEffectiveDeltaTime();
    if (var15 < arg0->unknown_8_) {
        arg0->unknown_8_ = arg0->unknown_8_ - var15;
    } else {
        arg0->unknown_8_ = 0;
    }

    if (self->timer == 0) {
        GameObject* combatant = battle->GetUnknownGameObject();
        if (combatant != NULL && GetByteField0x252_02039820(combatant) == 0) {
            GameObject_EnableControl(combatant);
        }
        int var17 = func_020100f8((char*)var0);
        if (var17 != 0) {
            func_020a27ac((void*)var17);
        }
        if (var2 != NULL) {
            ClearFlags04(var2, 0x80);
        }
    }

    MessageSystem_GetInstance();
    if (ticks < self->countdown) {
        self->countdown -= ticks;
    } else {
        arg0->unknown_16_ = 0;
        arg0->unknown_8_ = 0x12c;
        return 6;
    }
    return 4;
}
