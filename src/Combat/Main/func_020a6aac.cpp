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
extern "C" void* GameState_GetFollowCamera(char* obj);

struct PointerField32c_ffc0
{
    char padding0[0x32c];
    void* unknown_32c_;
};
extern "C" void* GameState_GetShip(struct PointerField32c_ffc0* obj);

extern "C" void* GameState_GetZoneTransition(GameState*);

extern "C" void func_020da77c(void* target, int type, void* msg);

extern "C" void func_020a2770(void* obj, short value);

extern "C" void func_0203db34(unsigned char* obj, int a, int b, int c);

extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int LinkSession_IsGuest(void* obj);

extern "C" void func_ov017_021d1a18(int a, short b, short c, unsigned char d);

struct Obj02033874;
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

extern "C" void* func_0201b678(void* savedEvent, void* ptr);
struct TerrainCtx02018fbc;
extern "C" int Zone3D_GetGroundHeight(TerrainCtx02018fbc*, Vector3fix*);
extern "C" void func_ov017_0219c598(int* arg0, short* arg1, int arg2);

extern "C" void* func_0201b754(void* obj, int key);
extern "C" void func_0200fd48(GameState*, int);

struct Obj0201b600;
struct Struct_0201b600;
struct Struct02013380;
extern "C" struct Struct_0201b600* func_0201b600(Obj0201b600*, int, unsigned short);
extern "C" void BmdjSceneElement_SetShown(struct Struct02013380* obj, int unused, int clear4);
extern "C" void func_0201b8c8(struct Obj0201b600* obj, int a1, int a2, int a3);

extern "C" void func_020da244(void* sb);

extern "C" void func_020a6aa4(Vector3i* obj, int x, int y, int z);

struct Struct_ov017_021d82fc_2;
extern Struct_ov017_021d82fc_2 data_ov017_021d82fc;
extern Vector3i data_020e909c;

struct EventController020a6aac
{
    unsigned char pad0[0x1f8];
    unsigned char unknown_1f8_;
    unsigned char unknown_1f9_[7];
    float unknown_200_;
    int unknown_204_;
};
struct ActorView020a6aac
{
    Object3D object;
    unsigned char unknown_ac_[0x144 - 0xac];
    Vector3i unknown_144_;
    unsigned char unknown_150_[4];
    unsigned char unknown_154_;
};
struct MovementView020a6aac
{
    unsigned char pad0[5];
    unsigned char busy;
    unsigned char pad6[0x20 - 6];
    int unknown_20_;
};
struct Struct_020a6aac_5
{
    unsigned char pad0[8];
    Vector3i position;
    unsigned char unknown_14_[0x20 - 0x14];
    short angle;
    unsigned char unknown_22_[0x2c - 0x22];
    unsigned short id;
    short height;
    Vector3i spawnPosition;
    unsigned char unknown_3c_[4];
    Vector3i unknown_40_;
};
struct Struct_ov017_021d82fc_2
{
    unsigned char pad0[0xe];
    unsigned char status;
};

struct Struct_020a6aac_6
{
    int id;
    unsigned char flag;
};

// JPN: func_020a8850
// USA: func_020a6aac
extern "C" ARM void func_020a6aac(unsigned int* obj, int arg1, int arg2)
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
        controller->unknown_1f8_ = 1;
        controller->unknown_200_ = 1.0f;
        controller->unknown_204_ = 0x1000;
    } else {
        controller->unknown_1f8_ = 0;
    }

    if (arg1 == 0x2710) {
        MovementView020a6aac* movementState = (MovementView020a6aac*)GameState_GetZoneTransition(state);
        int flagMatch = 0;
        if (movementState->unknown_20_ == 0x25f1)
        {
            flagMatch = 1;
        }
        struct Struct_020a6aac_6 local;
        local.id = -1;
        local.flag = 0;
        if (flagMatch) {
            local.id = 0xa0;
            func_020da77c(&data_ov017_021d82fc, 2, &local);
        } else {
            local.id = 0xc9;
            func_020da77c(&data_ov017_021d82fc, 1, &local);
        }
        func_020a2770(controller, 0xc9);
        actor->object.DisableFlag(0x100);
        actor->object.MakeVisible();
        actor->unknown_154_ = 1;
        actor->object.SetScale(0xa0, 0xa0, 0xa0);
        SetFlags04((GameResources*)obj, 0x10004);
        ZoneSavedActorState* saved = savedEvent->inline_020a6728();
        actor->object.position_ = saved->position;
        saved = savedEvent->inline_020a6728();
        actor->unknown_144_ = saved->position;
        int var11 = savedEvent->savedActor_.rotationY;
        func_0203db34((unsigned char*)actor, 0, var11, 0);
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
        actor->unknown_154_ = 0;
        actor->object.MakeVisible();
    } else if (arg1 >= 0x4e20 && arg1 <= 0x752f) {
        if (actor == 0)
        {
            return;
        }
        {
            actor->unknown_154_ = 0;
            actor->object.SetScale(0x180, 0x180, 0x180);
            if (arg2 == 0x2710) {
                Struct_020a6aac_5* var12 = (Struct_020a6aac_5*)func_0201b678(savedEvent, &savedEvent->savedActor_.position);
                if (var12 != 0) {
                    Vector3i spawnPosition = var12->spawnPosition;
                    spawnPosition.y = Zone3D_GetGroundHeight((TerrainCtx02018fbc*)savedEvent, &spawnPosition);
                    if (movement->busy == 0) {
                        unknown->obj3D_.position_ = spawnPosition;
                        func_0203db34((unsigned char*)unknown, 0, var12->height, 0);
                        func_ov017_0219c598(&spawnPosition.x, &var12->height, 0);
                    }
                    savedEvent->savedActor_.nodeId = var12->id;
                    savedEvent->savedActor_.zoneId = (unsigned short)arg1;
                }
                func_020a2770(controller, unknown->obj3D_.actorIndex_);
                ClearFlags04((GameResources*)obj, 0x10004);
                savedEvent->savedActor_.active = 0;
                short var14 = (short)savedEvent->savedActor_.zoneId;
                short var15 = savedEvent->savedActor_.nodeId;
                func_ov017_021d1a18(var14, var15, 0, 0);
            } else if (arg2 == 0x170c) {
                short var16 = savedEvent->savedActor_.nodeId;
                Struct_020a6aac_5* node2 = (Struct_020a6aac_5*)func_0201b754(savedEvent, var16);
                if (node2 != 0) {
                    Vector3i spawnPosition = node2->spawnPosition;
                    spawnPosition.y = Zone3D_GetGroundHeight((TerrainCtx02018fbc*)savedEvent, &spawnPosition);
                    if (movement->busy == 0) {
                        unknown->obj3D_.position_ = spawnPosition;
                        func_ov017_0219c598(&spawnPosition.x, &node2->height, 0);
                    }
                }
                func_020a2770(controller, unknown->obj3D_.actorIndex_);
                ClearFlags04((GameResources*)obj, 0x10004);
            }
            unsigned short var19 = savedEvent->savedActor_.zoneId;
            if (arg1 == var19) {
                short var20 = savedEvent->savedActor_.nodeId;
                Struct_020a6aac_5* node3 = (Struct_020a6aac_5*)func_0201b754(savedEvent, var20);
                if (node3 != 0) {
                    actor->object.EnableFlag(0x100);
                    actor->object.position_ = node3->position;
                    actor->unknown_144_ = node3->position;
                    GameObject_SnapFacing((struct Obj02033874*)actor, node3->angle);
                    Vector3i var22 = node3->unknown_40_;
                    savedEvent->savedActor_.position = var22;
                }
                actor->object.MakeVisible();
            } else {
                actor->object.MakeHidden();
            }
        }
    } else if (arg1 == 0x170c) {
        if (arg2 == 0x2710) {
            GameObject* currentObject = state->GetLeader();
            func_020a2770(controller, currentObject->obj3D_.actorIndex_);
            ClearFlags04((GameResources*)obj, 0x10004);
            func_0200fd48(state, 0xc9);
            if (LinkSession_IsGuest(events) != 0) {
                if (savedEvent->savedActor_.active == 0) {
                    func_0201b8c8((struct Obj0201b600*)savedEvent, 0, 1, 0);
                } else {
                    func_0201b8c8((struct Obj0201b600*)savedEvent, 1, 0, 1);
                }
            } else {
                func_0201b8c8((struct Obj0201b600*)savedEvent, 1, 0, 1);
                savedEvent->savedActor_.active = 1;
                func_ov017_021d1a18(1, -1, 1, 0);
            }
        } else {
            if (savedEvent->savedActor_.active != 0) {
                func_0201b8c8((struct Obj0201b600*)savedEvent, 1, 0, 1);
                func_ov017_021d1a18(1, -1, 1, 0);
            } else {
                func_0201b8c8((struct Obj0201b600*)savedEvent, 0, 1, 0);
                short var24 = (short)savedEvent->savedActor_.zoneId;
                short var25 = savedEvent->savedActor_.nodeId;
                func_ov017_021d1a18(var24, var25, 0, 0);
            }
        }
    } else if (arg1 == 0x76c) {
        Zone3D* savedState = (Zone3D*)Zone3D_GetInstance();
        if (arg2 == 0x2710) {
            GameObject* currentObject = state->GetLeader();
            Vector3i var28 = data_020e909c;
            short angle570 = 0x570;
            currentObject->obj3D_.position_ = var28;
            GameObject_SnapFacing((struct Obj02033874*)currentObject, angle570);
            func_ov017_0219c598(&var28.x, &angle570, 0);
            savedState->savedActor_.active = 0;
            func_ov017_021d1a18((short)arg1, -1, 0, 0);
            savedState->savedActor_.nodeId = 0;
            savedState->savedActor_.zoneId = (unsigned short)arg1;
            short objectId = state->GetLeader()->obj3D_.actorIndex_;
            func_020a2770(controller, objectId);
            ClearFlags04((GameResources*)obj, 0x10004);
            struct Struct_0201b600* firstSlot = func_0201b600((struct Obj0201b600*)savedState, 0, 4);
            if (firstSlot != 0)
            {
                BmdjSceneElement_SetShown((struct Struct02013380*)firstSlot, 0, 1);
            }
            struct Struct_0201b600* secondSlot = func_0201b600((struct Obj0201b600*)savedState, 0, 0x28);
            if (secondSlot != 0)
            {
                BmdjSceneElement_SetShown((struct Struct02013380*)secondSlot, 0, 1);
            }
        } else {
            unsigned short var33 = savedState->savedActor_.zoneId;
            if (var33 == 0x76c) {
                struct Struct_0201b600* firstSlot = func_0201b600((struct Obj0201b600*)savedState, 0, 4);
                if (firstSlot != 0)
                {
                    BmdjSceneElement_SetShown((struct Struct02013380*)firstSlot, 0, 1);
                }
                struct Struct_0201b600* secondSlot = func_0201b600((struct Obj0201b600*)savedState, 0, 0x28);
                if (secondSlot != 0)
                {
                    BmdjSceneElement_SetShown((struct Struct02013380*)secondSlot, 0, 1);
                }
            } else {
                struct Struct_0201b600* firstSlot = func_0201b600((struct Obj0201b600*)savedState, 0, 4);
                if (firstSlot != 0)
                {
                    BmdjSceneElement_SetShown((struct Struct02013380*)firstSlot, 0, 0);
                }
                struct Struct_0201b600* secondSlot = func_0201b600((struct Obj0201b600*)savedState, 0, 0x28);
                if (secondSlot != 0)
                {
                    BmdjSceneElement_SetShown((struct Struct02013380*)secondSlot, 0, 0);
                }
            }
        }
        func_0200fd48(state, 0xc9);
    } else {
        if (arg2 == 0x2710) {
            ClearFlags04((GameResources*)obj, 0x10004);
            func_0200fd48(state, 0xc9);
            short actorId = state->GetLeader()->obj3D_.actorIndex_;
            func_020a2770(controller, actorId);
            short var39 = (short)savedEvent->savedActor_.zoneId;
            short var40 = savedEvent->savedActor_.nodeId;
            unsigned char var41 = savedEvent->savedActor_.active;
            func_ov017_021d1a18(var39, var40, var41, 1);
            unsigned char var42 = data_ov017_021d82fc.status;
            if (!(var42 != 1 && var42 != 2)) {
                func_020da244(&data_ov017_021d82fc);
            }
        }
    }

    Vector3i var43 = savedEvent->savedActor_.position;
    if (var43.x == 0 && var43.z == 0) {
        func_020a6aa4(&var43, 0x19000, 0x199, 0x38ccc);
        savedEvent->savedActor_.position = var43;
    }
}
