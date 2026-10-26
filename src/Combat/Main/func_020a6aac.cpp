#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"


#if defined(jpn)
#define data_020e909c data_020e91a8
#endif

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
void* GameState_GetFollowCamera(char* obj);

struct Struct_0200ffc0
{
    char unknown_0_[0x32c];
    void* unknown_32c_;
};
void* GameState_GetShip(struct PointerField32c_ffc0* obj);

void* GameState_GetZoneTransition(GameState*);

extern "C" void func_020da77c(void* arg0, int arg1, void* arg2);

extern "C" void func_020a2770(void* arg0, short arg1);

extern "C" void func_0203db34(unsigned char* arg0, int arg1, int arg2, int arg3);

extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int LinkSession_IsGuest(void* obj);

extern "C" void func_ov017_021d1a18(int arg0, short arg1, short arg2, unsigned char arg3);

struct Obj02033874;
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

extern "C" void* func_0201b678(void* savedEvent, void* ptr);
struct TerrainCtx02018fbc;
extern "C" int Zone3D_GetGroundHeight(TerrainCtx02018fbc*, Vector3fix*);
extern "C" void func_ov017_0219c598(int* srcVec3, short* srcAngle, int forceFlag);

extern "C" void* func_0201b754(void* arg0, int arg1);
extern "C" void func_0200fd48(GameState*, int);

struct Obj0201b600;
struct Elem0201b600;
struct Struct02013380;
struct Elem0201b600* FindElemByKeys(Obj0201b600*, int, unsigned short);
void BmdjSceneElement_SetShown(struct Struct02013380* obj, int unused, int clear4);
void ApplyElementFlags0201b8c8(struct Obj0201b600* obj, int a1, int a2, int a3);

extern "C" void func_020da244(void* arg0);

extern "C" void func_020a6aa4(Vector3i* arg0, int arg1, int arg2, int arg3);

struct Struct_ov017_021d82fc_2;
extern Struct_ov017_021d82fc_2 data_ov017_021d82fc;
extern Vector3i data_020e909c;

struct Struct_020a6aac_2
{
    unsigned char unknown_0_[0x1f8];
    unsigned char unknown_1f8_;
    unsigned char unknown_1f9_[7];
    float unknown_200_;
    int unknown_204_;
};
struct Struct_020a6aac_3
{
    Object3D unknown_0_;
    unsigned char unknown_ac_[0x144 - 0xac];
    Vector3i unknown_144_;
    unsigned char unknown_150_[4];
    unsigned char unknown_154_;
};
struct Struct_020a6aac_4
{
    unsigned char unknown_0_[5];
    unsigned char unknown_5_;
    unsigned char unknown_6_[0x20 - 6];
    int unknown_20_;
};
struct Struct_020a6aac_5
{
    unsigned char unknown_0_[8];
    Vector3i unknown_8_;
    unsigned char unknown_14_[0x20 - 0x14];
    short unknown_20_;
    unsigned char unknown_22_[0x2c - 0x22];
    unsigned short unknown_2c_;
    short unknown_2e_;
    Vector3i unknown_30_;
    unsigned char unknown_3c_[4];
    Vector3i unknown_40_;
};
struct Struct_ov017_021d82fc_2
{
    unsigned char unknown_0_[0xe];
    unsigned char unknown_e_;
};

struct Struct_020a6aac_6
{
    int unknown_0_;
    unsigned char unknown_4_;
};

// JPN: func_020a8850
// USA: func_020a6aac
extern "C" ARM void func_020a6aac(unsigned int* arg0, int arg1, int arg2)
{
    GameState* state = GameState::GetInstance();
    Zone3D* savedEvent = (Zone3D*)Zone3D_GetInstance();
    LightingManager::GetInstance();
    void* events = LinkSession_GetInstance();
    Scenario_GetInstance();
    EventController020a6aac* controller = (EventController020a6aac*)GameState_GetFollowCamera((char*)state);
    ActorView020a6aac* actor = (ActorView020a6aac*)GameState_GetShip((struct PointerField32c_ffc0*)state);
    GameObject* unknown = state->GetLeader();
    MovementView020a6aac* movement = (MovementView020a6aac*)GameState_GetZoneTransition(state);

    if ((unsigned int)(arg1 - 0x170c) <= 3) {
        var3->unknown_1f8_ = 1;
        var3->unknown_200_ = 1.0f;
        var3->unknown_204_ = 0x1000;
    } else {
        var3->unknown_1f8_ = 0;
    }

    if (eventCode == 0x2710) {
        MovementView020a6aac* movementState = (MovementView020a6aac*)GameState_GetZoneTransition(state);
        int flagMatch = 0;
        if (movementState->eventId == 0x25f1)
        {
            var8 = 1;
        }
        struct Struct_020a6aac_6 var9;
        var9.unknown_0_ = -1;
        var9.unknown_4_ = 0;
        if (var8) {
            var9.unknown_0_ = 0xa0;
            func_020da77c(&data_ov017_021d82fc, 2, &var9);
        } else {
            var9.unknown_0_ = 0xc9;
            func_020da77c(&data_ov017_021d82fc, 1, &var9);
        }
        SetField0x21c_020a2770(controller, 0xc9);
        actor->object.DisableFlag(0x100);
        actor->object.MakeVisible();
        actor->scripted = 1;
        actor->object.SetScale(0xa0, 0xa0, 0xa0);
        SetFlags04((GameResources*)obj, 0x10004);
        ZoneSavedActorState* saved = savedEvent->GetSavedActorState();
        actor->object.position_ = saved->position;
        saved = savedEvent->GetSavedActorState();
        actor->secondaryPosition = saved->position;
        int savedRotationY = savedEvent->savedActor_.rotationY;
        StoreVec3AtField0x50_0203db34((unsigned char*)actor, 0, savedRotationY, 0);
        if (LinkSession_IsHostOrSolo(events) != 0 && flagMatch == 0) {
            savedEvent->savedActor_.active = 1;
            func_ov017_021d1a18(1, -1, 1, 0);
        }
        if (LinkSession_IsGuest(events) != 0) {
            actor->object.position_.x = 0x19000;
            actor->object.position_.y = 0x199;
            actor->object.position_.z = 0x38ccc;
            GameObject_SnapFacing((struct Obj02033874*)actor, 0);
        }
    } else if (arg1 == 0x2774) {
        var4->unknown_154_ = 0;
        var4->unknown_0_.MakeVisible();
    } else if (arg1 >= 0x4e20 && arg1 <= 0x752f) {
        if (var4 == 0)
        {
            return;
        }
        {
            actor->scripted = 0;
            actor->object.SetScale(0x180, 0x180, 0x180);
            if (previousCode == 0x2710) {
                EventNode020a6aac* node1 = (EventNode020a6aac*)func_0201b678(savedEvent, &savedEvent->savedActor_.position);
                if (node1 != 0) {
                    Vector3i spawnPosition = node1->spawnPosition;
                    spawnPosition.y = Zone3D_GetGroundHeight((TerrainCtx02018fbc*)savedEvent, &spawnPosition);
                    if (movement->busy == 0) {
                        unknown->obj3D_.position_ = spawnPosition;
                        StoreVec3AtField0x50_0203db34((unsigned char*)unknown, 0, node1->height, 0);
                        func_ov017_0219c598(&spawnPosition.x, &node1->height, 0);
                    }
                    var1->unknown_2774_.unknown_10_ = var12->unknown_2c_;
                    var1->unknown_2774_.unknown_12_ = (unsigned short)arg1;
                }
                SetField0x21c_020a2770(controller, unknown->obj3D_.actorIndex_);
                ClearFlags04((GameResources*)obj, 0x10004);
                savedEvent->savedActor_.active = 0;
                short savedEventId = (short)savedEvent->savedActor_.zoneId;
                short savedNodeId = savedEvent->savedActor_.nodeId;
                func_ov017_021d1a18(savedEventId, savedNodeId, 0, 0);
            } else if (previousCode == 0x170c) {
                short savedNodeId = savedEvent->savedActor_.nodeId;
                EventNode020a6aac* node2 = (EventNode020a6aac*)FindNodeByField0x2c0201b754(savedEvent, savedNodeId);
                if (node2 != 0) {
                    Vector3i spawnPosition = node2->spawnPosition;
                    spawnPosition.y = Zone3D_GetGroundHeight((TerrainCtx02018fbc*)savedEvent, &spawnPosition);
                    if (movement->busy == 0) {
                        unknown->obj3D_.position_ = spawnPosition;
                        func_ov017_0219c598(&spawnPosition.x, &node2->height, 0);
                    }
                }
                SetField0x21c_020a2770(controller, unknown->obj3D_.actorIndex_);
                ClearFlags04((GameResources*)obj, 0x10004);
            }
            unsigned short savedEventId = savedEvent->savedActor_.zoneId;
            if (eventCode == savedEventId) {
                short savedNodeId = savedEvent->savedActor_.nodeId;
                EventNode020a6aac* node3 = (EventNode020a6aac*)FindNodeByField0x2c0201b754(savedEvent, savedNodeId);
                if (node3 != 0) {
                    actor->object.EnableFlag(0x100);
                    actor->object.position_ = node3->position;
                    actor->secondaryPosition = node3->position;
                    GameObject_SnapFacing((struct Obj02033874*)actor, node3->angle);
                    Vector3i savedPosition = node3->savedPosition;
                    savedEvent->savedActor_.position = savedPosition;
                }
                var4->unknown_0_.MakeVisible();
            } else {
                var4->unknown_0_.MakeHidden();
            }
        }
    } else if (eventCode == 0x170c) {
        if (previousCode == 0x2710) {
            GameObject* currentObject = state->GetLeader();
            SetField0x21c_020a2770(controller, currentObject->obj3D_.actorIndex_);
            ClearFlags04((GameResources*)obj, 0x10004);
            ClearCombatantSlot_0200fd48(state, 0xc9);
            if (LinkSession_IsGuest(events) != 0) {
                if (savedEvent->savedActor_.active == 0) {
                    ApplyElementFlags0201b8c8((struct Obj0201b600*)savedEvent, 0, 1, 0);
                } else {
                    func_0201b8c8((struct Struct_02017a94*)var1, 1, 0, 1);
                }
            } else {
                func_0201b8c8((struct Struct_02017a94*)var1, 1, 0, 1);
                var1->unknown_2774_.unknown_14_ = 1;
                func_ov017_021d1a18(1, -1, 1, 0);
            }
        } else {
            if (var1->unknown_2774_.unknown_14_ != 0) {
                func_0201b8c8((struct Struct_02017a94*)var1, 1, 0, 1);
                func_ov017_021d1a18(1, -1, 1, 0);
            } else {
                func_0201b8c8((struct Struct_02017a94*)var1, 0, 1, 0);
                short var24 = (short)var1->unknown_2774_.unknown_12_;
                short var25 = var1->unknown_2774_.unknown_10_;
                func_ov017_021d1a18(var24, var25, 0, 0);
            }
        }
    } else if (eventCode == 0x76c) {
        Zone3D* savedState = (Zone3D*)Zone3D_GetInstance();
        if (previousCode == 0x2710) {
            GameObject* currentObject = state->GetLeader();
            Vector3i homePosition = data_020e909c;
            short angle570 = 0x570;
            currentObject->obj3D_.position_ = homePosition;
            GameObject_SnapFacing((struct Obj02033874*)currentObject, angle570);
            func_ov017_0219c598(&homePosition.x, &angle570, 0);
            savedState->savedActor_.active = 0;
            func_ov017_021d1a18((short)eventCode, -1, 0, 0);
            savedState->savedActor_.nodeId = 0;
            savedState->savedActor_.zoneId = (unsigned short)eventCode;
            short objectId = state->GetLeader()->obj3D_.actorIndex_;
            SetField0x21c_020a2770(controller, objectId);
            ClearFlags04((GameResources*)obj, 0x10004);
            struct Elem0201b600* firstSlot = FindElemByKeys((struct Obj0201b600*)savedState, 0, 4);
            if (firstSlot != 0)
            {
                BmdjSceneElement_SetShown((struct Struct02013380*)firstSlot, 0, 1);
            }
            struct Struct_0201b600* var32 = func_0201b600((struct Struct_02017a94*)var26, 0, 0x28);
            if (var32 != 0)
            {
                BmdjSceneElement_SetShown((struct Struct02013380*)secondSlot, 0, 1);
            }
        } else {
            unsigned short var33 = var26->unknown_2774_.unknown_12_;
            if (var33 == 0x76c) {
                struct Struct_0201b600* var34 = func_0201b600((struct Struct_02017a94*)var26, 0, 4);
                if (var34 != 0)
                {
                    BmdjSceneElement_SetShown((struct Struct02013380*)firstSlot, 0, 1);
                }
                struct Struct_0201b600* var35 = func_0201b600((struct Struct_02017a94*)var26, 0, 0x28);
                if (var35 != 0)
                {
                    BmdjSceneElement_SetShown((struct Struct02013380*)secondSlot, 0, 1);
                }
            } else {
                struct Struct_0201b600* var36 = func_0201b600((struct Struct_02017a94*)var26, 0, 4);
                if (var36 != 0)
                {
                    BmdjSceneElement_SetShown((struct Struct02013380*)firstSlot, 0, 0);
                }
                struct Struct_0201b600* var37 = func_0201b600((struct Struct_02017a94*)var26, 0, 0x28);
                if (var37 != 0)
                {
                    BmdjSceneElement_SetShown((struct Struct02013380*)secondSlot, 0, 0);
                }
            }
        }
        func_0200fd48(var0, 0xc9);
    } else {
        if (previousCode == 0x2710) {
            ClearFlags04((GameResources*)obj, 0x10004);
            ClearCombatantSlot_0200fd48(state, 0xc9);
            short actorId = state->GetLeader()->obj3D_.actorIndex_;
            SetField0x21c_020a2770(controller, actorId);
            short savedEventId = (short)savedEvent->savedActor_.zoneId;
            short savedNodeId = savedEvent->savedActor_.nodeId;
            unsigned char flag2788 = savedEvent->savedActor_.active;
            func_ov017_021d1a18(savedEventId, savedNodeId, flag2788, 1);
            unsigned char statusByte = data_ov017_021d82fc.status;
            if (!(statusByte != 1 && statusByte != 2)) {
                func_020da244(&data_ov017_021d82fc);
            }
        }
    }

    Vector3i var43 = var1->unknown_2774_.unknown_0_;
    if (var43.x == 0 && var43.z == 0) {
        func_020a6aa4(&var43, 0x19000, 0x199, 0x38ccc);
        var1->unknown_2774_.unknown_0_ = var43;
    }
}
