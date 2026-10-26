#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"


struct WrappedActor020a75ec {
    Object3D object;
    short field_ac;
    short angle;
    char unknown_b0_[4];
    short field_b4;
    char unknown_b6_[0x7a];
    unsigned int unknown_130_;
    char unknown_134_[8];
    unsigned short phase;
    short unknown_13e_;
    int unknown_140_;
    Vector3i previousPosition;
    unsigned char reset;
    char unknown_151_[3];
    unsigned char active;
    char unknown_155_[5];
    unsigned char unknown_15a_;
};
struct Struct_020a75ec_2 { Object3D object; unsigned short state; };
struct ListHead02046b60;
struct Bytes02033b88;
struct Vec3copy0202ec84;
extern short data_020e9450[];
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void GameObject_Update(WrappedActor020a75ec*);
extern "C" void func_020a78dc(WrappedActor020a75ec*);
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" void* GameState_GetParty(GameState*);
extern "C" int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" void* Scenario_GetInstance();
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" int GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_ov017_021a93f0(GameResources*, int, int);

#if defined(jpn)
enum { Enum_020a75ec_10100 = 0x27b4, Enum_020a75ec_10112 = 0x27c0 };
#else
enum { Enum_020a75ec_10100 = 0x2774, Enum_020a75ec_10112 = 0x2780 };
#endif

// USA: func_020a75ec
extern "C" ARM void func_020a75ec(WrappedActor020a75ec* actor) {
    GameState* state = GameState::GetInstance();
    Zone3D* zone = Zone3D_GetInstance();
    short field = actor->field_b4;
    GameObject_Update(actor);
    actor->field_b4 = field;
    func_020a78dc(actor);
    actor->phase += state->GetTickCount() * 364;
    actor->unknown_140_ = data_020e9450[((actor->phase >> 4) * 2 + 1)] >> 4;
    if (zone->currentZoneID_ != 10000) return;
    Vector3i position;
    int changed = 0;
    position = actor->object.position_;
    actor->unknown_130_ = 0;
    if (position.x >= 0x90000) {
        position.x -= 0x120000;
        actor->unknown_130_ |= 1;
        changed = 1;
    } else if (position.x < -0x90000) {
        position.x += 0x120000;
        actor->unknown_130_ |= 2;
        changed = 1;
    }
    if (position.z >= 0x70000) {
        position.z -= 0xe0000;
        actor->unknown_130_ |= 4;
        changed = 1;
    } else if (position.z < -0x70000) {
        position.z += 0xe0000;
        actor->unknown_130_ |= 8;
        changed = 1;
    }
    if (changed) {
        actor->object.position_ = position;
        actor->previousPosition = position;
    }
    GameResources* scene = GetGameResources();
    void* head = scene->fieldTaskQueue_;
    if (!func_02046b60((ListHead02046b60*)head, 3) && !func_02046b60((ListHead02046b60*)head, 1)) {
        unsigned char* party = (unsigned char*)GameState_GetParty(state);
        for (int i = 0; i < party[0xf7c]; i++) {
            Struct_020a75ec_2* member = (Struct_020a75ec_2*)state->GetPartyMemberByIndex(*(party + 0xf78 + i));
            if (member) {
                member->object.position_ = actor->object.position_;
                member->state = 0;
            }
        }
        *(Vector3i*)((char*)zone + Enum_020a75ec_10100) = actor->object.position_;
        *(int*)((char*)zone + Enum_020a75ec_10112) = actor->angle;
    }
    int screenX;
    int screenY;
    void* view = state->GetCamera();
    int hit = 0;
    if (Camera_WorldToScreen(view, (Vec3copy0202ec84*)&actor->object.position_, &screenX, &screenY) == 0) {
        int var14;
        int var15;
        if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) {
            var14 = g_touchInput.prevX_;
            var15 = g_touchInput.prevY_;
        }
        if (screenX - 16 < var14 && var14 < screenX + 16 && screenY - 20 < var15 && var15 < screenY + 8) hit = 1;
    }
#if !defined(jpn)
    unsigned char* flags = (unsigned char*)Scenario_GetInstance();
#endif
    if (g_keyManager.TestKeysPressed(2) || hit) {
        if (FieldTaskQueue_IsEmpty((void**)head)
#if !defined(jpn)
            && Scenario_TestFlag((int)flags, flags + 0x8c, 43)
#endif
        ) {
            actor->unknown_15a_ = 0;
            actor->active = 0;
            GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
            func_ov017_021a93f0(scene, 0, 1);
        }
    }
}
