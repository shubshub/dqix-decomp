#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"


struct Struct_020a75ec {
    Object3D unknown_0_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[4];
    short unknown_b4_;
    char unknown_b6_[0x7a];
    unsigned int unknown_130_;
    char unknown_134_[8];
    unsigned short unknown_13c_;
    short unknown_13e_;
    int unknown_140_;
    Vector3i unknown_144_;
    unsigned char unknown_150_;
    char unknown_151_[3];
    unsigned char unknown_154_;
    char unknown_155_[5];
    unsigned char unknown_15a_;
};
struct Struct_020a75ec_2 { Object3D unknown_0_; unsigned short unknown_ac_; };
struct Struct_02038598_5;
struct Struct_02010604;
struct Struct_02015ef4;
extern short data_020e9450[];
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void GameObject_Update(WrappedActor020a75ec*);
extern "C" void func_020a78dc(WrappedActor020a75ec*);
int ListContainsId(ListHead02046b60*, int);
void* GameState_GetParty(GameState*);
int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" void* Scenario_GetInstance();
int FieldTaskQueue_IsEmpty(void**);
int Scenario_TestFlag(int, unsigned char*, int);
int GameObject_ForceMotionState(Bytes02033b88*, int);
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
    actor->oscillation = data_020e9450[((actor->phase >> 4) * 2 + 1)] >> 4;
    if (zone->currentZoneID_ != 10000) return;
    Vector3i position;
    int changed = 0;
    position = actor->object.position_;
    actor->wrapFlags = 0;
    if (position.x >= 0x90000) {
        position.x -= 0x120000;
        actor->wrapFlags |= 1;
        changed = 1;
    } else if (position.x < -0x90000) {
        position.x += 0x120000;
        actor->wrapFlags |= 2;
        changed = 1;
    }
    if (var3.z >= 0x70000) {
        var3.z -= 0xe0000;
        arg0->unknown_130_ |= 4;
        var4 = 1;
    } else if (var3.z < -0x70000) {
        var3.z += 0xe0000;
        arg0->unknown_130_ |= 8;
        var4 = 1;
    }
    if (var4) {
        arg0->unknown_0_.position_ = var3;
        arg0->unknown_144_ = var3;
    }
    GameResources* scene = GetGameResources();
    void* head = scene->fieldTaskQueue_;
    if (!ListContainsId((ListHead02046b60*)head, 3) && !ListContainsId((ListHead02046b60*)head, 1)) {
        unsigned char* party = (unsigned char*)GameState_GetParty(state);
        for (int i = 0; i < party[0xf7c]; i++) {
            PartyActor020a75ec* member = (PartyActor020a75ec*)state->GetPartyMemberByIndex(*(party + 0xf78 + i));
            if (member) {
                member->object.position_ = actor->object.position_;
                member->state = 0;
            }
        }
        *(Vector3i*)((char*)var1 + Enum_020a75ec_10100) = arg0->unknown_0_.position_;
        *(int*)((char*)var1 + Enum_020a75ec_10112) = arg0->unknown_ae_;
    }
    int screenX;
    int screenY;
    void* view = state->GetCamera();
    int hit = 0;
    if (Camera_WorldToScreen(view, (Vec3copy0202ec84*)&actor->object.position_, &screenX, &screenY) == 0) {
        int inputX;
        int inputY;
        if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) {
            var14 = g_touchInput.prevX_;
            var15 = g_touchInput.prevY_;
        }
        if (var10 - 16 < var14 && var14 < var10 + 16 && var11 - 20 < var15 && var15 < var11 + 8) var13 = 1;
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
            actor->field_15a = 0;
            actor->active = 0;
            GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
            func_ov017_021a93f0(scene, 0, 1);
        }
    }
}
