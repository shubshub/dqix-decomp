#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
void* GameState_GetFollowCamera(char* obj);
struct PointerField330_ffd0;
void* GameState_GetStarflight(struct PointerField330_ffd0* obj);
void* GameState_GetZoneTransition(GameState*);
extern "C" void func_020da77c(void* target, int type, void* msg);
void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);
void SetField0x21c_020a2770(void* obj, short value);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char a, unsigned short b);
int IsIdInSpecialSet0201b868(void* obj, int id);
struct Vec3Target020ad1f0;
void SetVec3At0x0020ad1f0(struct Vec3Target020ad1f0* obj, int x, int y, int z);
struct Obj02033874;
void GameObject_SnapFacing(struct Obj02033874* obj, int value);
extern "C" void func_020da244(void* sb);
void SePlayer_UnloadExtraArchiveB(void* obj);
unsigned char GameState_GetProtagonistIndex(GameState*);
extern "C" int Zone3D_GetGroundHeight(void* zone, Vector3i* v);
extern "C" void func_ov017_0219c598(int* srcVec3, short* srcAngle, int forceFlag);

struct Struct_020acecc
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    Vector3i unknown_4_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
};

struct Struct_020acecc_2
{
#if defined(jpn)
    unsigned char unknown_0_[0x27f4];
#else
    unsigned char unknown1_0_[0x27b4];
#endif
    Struct_020acecc unknown_27b4_;
};

struct Struct_020acecc_3
{
    unsigned char unknown_0_[8];
    Vector3i unknown_8_;
    unsigned char unknown_14_[0x20 - 0x14];
    short unknown_20_;
};

struct Struct_020acecc_4
{
    unsigned char unknown_0_[0x61];
    unsigned char unknown_61_;
};

struct Struct_020acecc_5
{
    Object3D unknown_0_;
    unsigned char unknown_ac_[0x13c - 0xac];
    int unknown_13c_;
    unsigned char unknown_140_[0x19c - 0x140];
    unsigned char unknown_19c_;
};

struct Struct_ov017_021d82fc_4
{
    unsigned char unknown_0_[0xe];
    unsigned char unknown_e_;
};

struct Struct_020acecc_6
{
    int unknown_0_;
    unsigned char unknown_4_;
};

extern "C" void func_020ad1f8(Struct_020acecc_2* arg0, int arg1, int arg2);
extern "C" Struct_020acecc_3* func_0201b78c(Struct_020acecc_2* arg0, Vector3i* arg1);
extern "C" void func_020adfa8(Struct_020acecc_5* arg0);

extern Dispatcher020acecc data_ov017_021d82fc;
extern int g_sePlayer;

// USA: func_020acecc
extern "C" ARM void func_020acecc(unsigned int* arg0, int arg1, int arg2)
{
    GameState* state = GameState::GetInstance();
    Zone020acecc* zone = (Zone020acecc*)Zone3D_GetInstance();
    LinkSession_GetInstance();
    void* controller = GameState_GetFollowCamera((char*)state);
    Prop020acecc* prop = (Prop020acecc*)GameState_GetStarflight((struct PointerField330_ffd0*)state);
    Movement020acecc* movement = (Movement020acecc*)GameState_GetZoneTransition(state);
    GameObject* unknown = state->GetLeader();
    state->GetPartyMemberByIndex(0);
    func_020ad1f8(zone, eventCode, previousCode);

    if (movement->active != 0) {
        Node020acecc* node = func_0201b78c(zone, &zone->saved.position);
        if (node != 0) {
            Vector3i spawnPosition = node->position;
            spawnPosition.y = Zone3D_GetGroundHeight(zone, &spawnPosition);
            unknown->obj3D_.position_ = spawnPosition;
            func_ov017_0219c598(&spawnPosition.x, &node->angle, 0);
        }
    }

    if (eventCode == 0x2774) {
        LocalMsg020acecc local;
        local.id = -1;
        local.flag = 0;
        local.id = prop->obj3D.actorIndex_;
        func_020da77c(&data_ov017_021d82fc, 3, &local);
        SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xa0, 0xa0);
        SetField0x21c_020a2770(controller, 0xca);
        prop->f19c = 1;
        prop->f13c = 0;
        SetHalfFieldsAndEnqueueIfActive_021d1c2c(0, 1);
        if (IsIdInSpecialSet0201b868(zone, previousCode) != 0) {
            Vector3i position;
            SetVec3At0x0020ad1f0((struct Vec3Target020ad1f0*)&position, 0, 0, 0);
            position.x = zone->saved.x;
            position.z = zone->saved.z;
            if (previousCode >= 0x4e20 && previousCode <= 0x752f) {
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
    } else if (eventCode >= 0x4e20 && eventCode <= 0x752f && previousCode == 0x2774) {
        SetHalfFieldsAndEnqueueIfActive_021d1c2c(zone->saved.state, (unsigned char)zone->saved.sub);
        short actorId = state->GetLeader()->obj3D_.actorIndex_;
        SetField0x21c_020a2770(controller, actorId);
        ClearFlags04((GameResources*)obj, 0x10044);
        SetFlags04((GameResources*)obj, 0x40000);
    } else if (eventCode != 0x2774 && previousCode == 0x2774) {
        if (data_ov017_021d82fc.status == 3) {
            func_020da244(&data_ov017_021d82fc);
        }
        SePlayer_UnloadExtraArchiveB(&g_sePlayer);
        SetHalfFieldsAndEnqueueIfActive_021d1c2c(zone->saved.state, (unsigned char)zone->saved.sub);
        SetField0x21c_020a2770(controller, GameState_GetProtagonistIndex(state));
        ClearFlags04((GameResources*)obj, 0x10044);
        SetFlags04((GameResources*)obj, 0x40000);
    }
}
