#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

extern "C" int GameResources_IsSpecialItemEffectPlaying(void* obj);
extern "C" int GameObject_IsControlEnabled(void* obj);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a27ac(void* obj);
extern "C" int MessageSystem_GetInstance(void);

struct Vec3copy0202ec84 { unsigned int v[3]; };
extern "C" int Camera_WorldToScreen(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct StructAt020473c8;
extern "C" void func_020473c8(struct StructAt020473c8* obj, int param1);

struct Struct_ov017_021bfc40 {
    char pad0[0x8];
    unsigned short timer;
    char pad1[0x10 - 0xa];
    unsigned char* sprite;
    char pad2[0x16 - 0x14];
    short countdown;
    short angle;
    char pad3[0x28 - 0x1a];
    struct Vec3copy0202ec84 pos;
    char pad4[0x48 - 0x34];
    unsigned char unknown_48_;
};

// USA: func_ov017_021bfc40
extern "C" ARM int func_ov017_021bfc40(struct Struct_ov017_021bfc40* self) {
    GameState* battle = GameState::GetInstance();
    int ticks = battle->GetTickCount();
    GameResources* res = GetGameResources();

    if (self->unknown_48_ != 0) {
        GameResources* res2 = GetGameResources();
        if (GameResources_IsSpecialItemEffectPlaying(res2) != 0) {
            return 4;
        }
        GameObject* combatant = battle->GetLeader();
        if (combatant != NULL && GameObject_IsControlEnabled(combatant) == 0) {
            GameObject_EnableControl(combatant);
        }
        int flag = GameState_GetFollowCamera((char*)battle);
        if (flag != 0) {
            func_020a27ac((void*)flag);
        }
        if (res2 != NULL) {
            ClearFlags04(res2, 0x80);
        }
        self->countdown = 0;
        self->timer = 0;
        return 6;
    }

    GameState* state = GameState::GetInstance();
    void* ptr3b0 = state->GetCamera();
    struct Vec3copy0202ec84 vecBuf = self->pos;

    if (self->angle < 0x191e) {
        self->angle += state->GetTickCount() * 0x199;
    }

    vecBuf.v[1] += fix32sin(self->angle);

    int screenY;
    int screenX;
    if (ptr3b0 != NULL) {
        Camera_WorldToScreen(ptr3b0, &vecBuf, &screenX, &screenY);
    }

    int x = (screenX - 0xc) << 0xc;
    int y = (screenY - 0x28) << 0xc;
    unsigned char* sprite = self->sprite;
    *(int*)(sprite + 0x1c) = x;
    *(int*)(sprite + 0x20) = y;
    *(int*)(sprite + 0x24) = 0;
    func_020473c8((struct StructAt020473c8*)sprite, 1);

    short level = self->countdown;
    if (level > 0x1f) {
        level = 0x1f;
    }
    *(short*)(sprite + 0x82) = level;

    unsigned int var15 = battle->GetEffectiveDeltaTime();
    if (var15 < self->timer) {
        self->timer = self->timer - var15;
    } else {
        self->timer = 0;
    }

    if (self->timer == 0) {
        GameObject* combatant = battle->GetLeader();
        if (combatant != NULL && GameObject_IsControlEnabled(combatant) == 0) {
            GameObject_EnableControl(combatant);
        }
        int flag = GameState_GetFollowCamera((char*)battle);
        if (flag != 0) {
            func_020a27ac((void*)flag);
        }
        if (res != NULL) {
            ClearFlags04(res, 0x80);
        }
    }

    MessageSystem_GetInstance();
    if (ticks < self->countdown) {
        self->countdown -= ticks;
    } else {
        self->countdown = 0;
        self->timer = 0x12c;
        return 6;
    }
    return 4;
}
