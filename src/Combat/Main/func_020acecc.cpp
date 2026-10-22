#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"

extern "C" void* func_02012fe4(void);
extern "C" void* func_0202ae18(void);
void* GetFieldIfFlag4_020100f8(char* obj);
struct PointerField330_ffd0;
void* GetPointerAt0x330_0200ffd0(struct PointerField330_ffd0* obj);
void* GetField0x3f8Address_0200fd0c(GameState*);
extern "C" void func_020da77c(void* target, int type, void* msg);
void SetForwardAndStore0205ebc0(void* obj, int arg1, int arg2);
void SetField0x21c_020a2770(void* obj, short value);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char a, unsigned short b);
int IsIdInSpecialSet0201b868(void* obj, int id);
struct Vec3Target020ad1f0;
void SetVec3At0x0020ad1f0(struct Vec3Target020ad1f0* obj, int x, int y, int z);
struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int value);
extern "C" void func_020da244(void* sb);
void ForwardField0xc0_0205ebec(void* obj);
unsigned char GetField0x3acValue_020100a8(GameState*);
extern "C" int func_02018fbc(void* zone, Vector3i* v);
extern "C" void func_ov017_0219c598(int* srcVec3, short* srcAngle, int forceFlag);

struct SavedProp020acecc
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
    SavedProp020acecc saved;
};

struct Node020acecc
{
    unsigned char pad0[8];
    Vector3i position;
    unsigned char pad14[0x20 - 0x14];
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
    unsigned char padac[0x13c - 0xac];
    int f13c;
    unsigned char pad140[0x19c - 0x140];
    unsigned char f19c;
};

struct Dispatcher020acecc
{
    unsigned char pad0[0xe];
    unsigned char status;
};

struct LocalMsg020acecc
{
    int id;
    unsigned char flag;
};

extern "C" void func_020ad1f8(Zone020acecc* zone, int eventCode, int previousCode);
extern "C" Node020acecc* func_0201b78c(Zone020acecc* zone, Vector3i* pos);
extern "C" void func_020adfa8(Prop020acecc* prop);

extern Dispatcher020acecc data_ov017_021d82fc;
extern int g_sePlayer;

// USA: func_020acecc
extern "C" ARM void func_020acecc(unsigned int* obj, int eventCode, int previousCode)
{
    GameState* state = GameState::GetInstance();
    Zone020acecc* zone = (Zone020acecc*)func_02012fe4();
    func_0202ae18();
    void* controller = GetFieldIfFlag4_020100f8((char*)state);
    Prop020acecc* prop = (Prop020acecc*)GetPointerAt0x330_0200ffd0((struct PointerField330_ffd0*)state);
    Movement020acecc* movement = (Movement020acecc*)GetField0x3f8Address_0200fd0c(state);
    GameObject* unknown = state->GetUnknownGameObject();
    state->GetPartyMemberByIndex(0);
    func_020ad1f8(zone, eventCode, previousCode);

    if (movement->active != 0) {
        Node020acecc* node = func_0201b78c(zone, &zone->saved.position);
        if (node != 0) {
            Vector3i spawnPosition = node->position;
            spawnPosition.y = func_02018fbc(zone, &spawnPosition);
            unknown->obj3D_.position_ = spawnPosition;
            func_ov017_0219c598(&spawnPosition.x, &node->angle, 0);
        }
    }

    if (eventCode == 0x2774) {
        LocalMsg020acecc local;
        local.id = -1;
        local.flag = 0;
        local.id = prop->obj3D.unknown_4_;
        func_020da77c(&data_ov017_021d82fc, 3, &local);
        SetForwardAndStore0205ebc0(&g_sePlayer, 0xa0, 0xa0);
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
            SetVecYFromValue02033874((struct Obj02033874*)prop, 0x3244);
            func_020adfa8(prop);
        } else {
            prop->obj3D.position_ = zone->saved.position;
            SetVecYFromValue02033874((struct Obj02033874*)prop, zone->saved.rotationY);
            func_020adfa8(prop);
        }
        SetFlags04((GameResources*)obj, 0x10044);
        ClearFlags04((GameResources*)obj, 0x40000);
    } else if (eventCode >= 0x4e20 && eventCode <= 0x752f && previousCode == 0x2774) {
        SetHalfFieldsAndEnqueueIfActive_021d1c2c(zone->saved.state, (unsigned char)zone->saved.sub);
        short actorId = state->GetUnknownGameObject()->obj3D_.unknown_4_;
        SetField0x21c_020a2770(controller, actorId);
        ClearFlags04((GameResources*)obj, 0x10044);
        SetFlags04((GameResources*)obj, 0x40000);
    } else if (eventCode != 0x2774 && previousCode == 0x2774) {
        if (data_ov017_021d82fc.status == 3) {
            func_020da244(&data_ov017_021d82fc);
        }
        ForwardField0xc0_0205ebec(&g_sePlayer);
        SetHalfFieldsAndEnqueueIfActive_021d1c2c(zone->saved.state, (unsigned char)zone->saved.sub);
        SetField0x21c_020a2770(controller, GetField0x3acValue_020100a8(state));
        ClearFlags04((GameResources*)obj, 0x10044);
        SetFlags04((GameResources*)obj, 0x40000);
    }
}
