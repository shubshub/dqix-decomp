#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* GameState_GetFollowCamera(char* obj);
struct PointerField330_ffd0;
extern "C" void* GameState_GetStarflight(struct PointerField330_ffd0* obj);
extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" void func_020da77c(void* target, int type, void* msg);
extern "C" void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);
extern "C" void func_020a2770(void* obj, short value);
extern "C" void func_ov017_021d1c2c(unsigned char a, unsigned short b);
extern "C" int func_0201b868(void* obj, int id);
struct Struct_020acecc_7;
extern "C" void func_020ad1f0(struct Struct_020acecc_7* obj, int x, int y, int z);
struct Obj02033874;
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int value);
extern "C" void func_020da244(void* sb);
extern "C" void SePlayer_UnloadExtraArchiveB(void* obj);
extern "C" unsigned char GameState_GetProtagonistIndex(GameState*);
extern "C" int Zone3D_GetGroundHeight(void* zone, Vector3i* v);
extern "C" void func_ov017_0219c598(int* arg0, short* arg1, int arg2);

struct Struct_020acecc
{
    unsigned short state;
    unsigned short sub;
    Vector3i position;
    int rotationY;
    int x;
    int z;
};

struct Zone020acecc
{
#if defined(jpn)
    unsigned char pad0[0x27f4];
#else
    unsigned char pad0[0x27b4];
#endif
    Struct_020acecc saved;
};

struct Struct_020acecc_3
{
    unsigned char pad0[8];
    Vector3i position;
    unsigned char unknown_14_[0x20 - 0x14];
    short angle;
};

struct Movement020acecc
{
    unsigned char pad0[0x61];
    unsigned char active;
};

struct Prop020acecc
{
    Object3D obj3D;
    unsigned char unknown_ac_[0x13c - 0xac];
    int unknown_13c_;
    unsigned char unknown_140_[0x19c - 0x140];
    unsigned char unknown_19c_;
};

struct Struct_ov017_021d82fc_4
{
    unsigned char pad0[0xe];
    unsigned char status;
};

struct Struct_020acecc_6
{
    int id;
    unsigned char flag;
};

extern "C" void func_020ad1f8(Zone020acecc* zone, int arg1, int arg2);
extern "C" Struct_020acecc_3* func_0201b78c(Zone020acecc* zone, Vector3i* pos);
extern "C" void func_020adfa8(Prop020acecc* prop);

extern Struct_ov017_021d82fc_4 data_ov017_021d82fc;
extern int g_sePlayer;

// USA: func_020acecc
extern "C" ARM void func_020acecc(unsigned int* obj, int arg1, int arg2)
{
    GameState* state = GameState::GetInstance();
    Zone020acecc* zone = (Zone020acecc*)Zone3D_GetInstance();
    LinkSession_GetInstance();
    void* controller = GameState_GetFollowCamera((char*)state);
    Prop020acecc* prop = (Prop020acecc*)GameState_GetStarflight((struct PointerField330_ffd0*)state);
    Movement020acecc* movement = (Movement020acecc*)GameState_GetZoneTransition(state);
    GameObject* unknown = state->GetLeader();
    state->GetPartyMemberByIndex(0);
    func_020ad1f8(zone, arg1, arg2);

    if (movement->active != 0) {
        Struct_020acecc_3* node = func_0201b78c(zone, &zone->saved.position);
        if (node != 0) {
            Vector3i spawnPosition = node->position;
            spawnPosition.y = Zone3D_GetGroundHeight(zone, &spawnPosition);
            unknown->obj3D_.position_ = spawnPosition;
            func_ov017_0219c598(&spawnPosition.x, &node->angle, 0);
        }
    }

    if (arg1 == 0x2774) {
        Struct_020acecc_6 local;
        local.id = -1;
        local.flag = 0;
        local.id = prop->obj3D.actorIndex_;
        func_020da77c(&data_ov017_021d82fc, 3, &local);
        SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xa0, 0xa0);
        func_020a2770(controller, 0xca);
        prop->unknown_19c_ = 1;
        prop->unknown_13c_ = 0;
        func_ov017_021d1c2c(0, 1);
        if (func_0201b868(zone, arg2) != 0) {
            Vector3i position;
            func_020ad1f0((struct Struct_020acecc_7*)&position, 0, 0, 0);
            position.x = zone->saved.x;
            position.z = zone->saved.z;
            if (arg2 >= 0x4e20 && arg2 <= 0x752f) {
                position.x = fix32_Divide(position.x, 0x6000);
                position.y = fix32_Divide(position.y, 0x6000);
                position.z = fix32_Divide(position.z, 0x6000);
            }
            prop->obj3D.position_ = position;
            GameObject_SnapFacing((struct Obj02033874*)prop, 0x3244);
            func_020adfa8(prop);
        } else {
            prop->obj3D.position_ = zone->saved.position;
            GameObject_SnapFacing((struct Obj02033874*)prop, zone->saved.rotationY);
            func_020adfa8(prop);
        }
        SetFlags04((GameResources*)obj, 0x10044);
        ClearFlags04((GameResources*)obj, 0x40000);
    } else if (arg1 >= 0x4e20 && arg1 <= 0x752f && arg2 == 0x2774) {
        func_ov017_021d1c2c(zone->saved.state, (unsigned char)zone->saved.sub);
        short actorId = state->GetLeader()->obj3D_.actorIndex_;
        func_020a2770(controller, actorId);
        ClearFlags04((GameResources*)obj, 0x10044);
        SetFlags04((GameResources*)obj, 0x40000);
    } else if (arg1 != 0x2774 && arg2 == 0x2774) {
        if (data_ov017_021d82fc.status == 3) {
            func_020da244(&data_ov017_021d82fc);
        }
        SePlayer_UnloadExtraArchiveB(&g_sePlayer);
        func_ov017_021d1c2c(zone->saved.state, (unsigned char)zone->saved.sub);
        func_020a2770(controller, GameState_GetProtagonistIndex(state));
        ClearFlags04((GameResources*)obj, 0x10044);
        SetFlags04((GameResources*)obj, 0x40000);
    }
}
