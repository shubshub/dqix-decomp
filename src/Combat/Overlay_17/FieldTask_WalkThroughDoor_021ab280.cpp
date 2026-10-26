#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021ab280_2096 = 0x850, kResourceHeaderOffset = 0x4fc, Enum_ov017_021ab280_1788 = 0x4ec };
#else
enum { Enum_ov017_021ab280_2096 = 0x830, kResourceHeaderOffset = 0x70c, Enum_ov017_021ab280_1788 = 0x6fc };
#endif

#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);

struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

int fix32ReduceAngle0To2Pi(int angle);
int fix32sin(int angle);
int fix32cos(int angle);

struct Vec3 { int x; int y; int z; };
extern "C" int fix32_Atan2(int x, int z);

struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);
struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);
struct Foo02033b58;
extern "C" void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);
struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);

extern "C" unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);

extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void VectorizedMemset(void* dst, int val, int size);
struct Vector3i;
extern "C" void FieldTask_InitEnterZone(unsigned char* obj, int flag);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_021ab280 {
    char pad0[8];
    int x, y, z;
    char pad1[0x20 - 0x14];
    short angle;
    char pad2[0x30 - 0x22];
    unsigned short unknown_30_;
    char pad3[0x38 - 0x32];
    struct Vec3 unknown_38_[4];
    short unknown_68_;
    short unknown_6a_;
};

struct Obj_021ab280 {
    char pad0[1];
    unsigned char field1;
    char pad1[8 - 2];
    int state;
    int counter;
    struct Struct_ov017_021ab280* pos;
    struct Vec3 unknown_14_;
};

// Overlay 17, originally func_ov017_021ab280 (USA/EUR 0x021ab280, JPN 0x021abae0)
extern "C" ARM int FieldTask_WalkThroughDoor(struct Obj_021ab280* obj) {
    GameState* battle = GameState::GetInstance();
    LinkSession_GetInstance();
    unsigned char* mgr = (unsigned char*)GetGameResources();
    GameObject* combatant = battle->GetLeader();
    void* g = Zone3D_GetInstance();

    int state = obj->state;
    if (state == 0) {
        GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
        ((Object3D*)((unsigned char*)combatant))->EnableFlag(0x01000080);

        struct Vec3 dir;
        struct Vec3 saved = *(struct Vec3*)((char*)combatant + 0x44);
        int angleY = fix32ReduceAngle0To2Pi(obj->pos->angle + (int)0xffffcdc3);
        dir.x = fix32sin(angleY);
        dir.y = 0;
        dir.z = fix32cos(angleY);
        Vector3fix_Normalize((const Vector3fix*)&dir, (Vector3fix*)&dir);
        Vector3fix_Add((const Vector3fix*)((struct Vec3*)&obj->pos->x), (const Vector3fix*)&dir, (Vector3fix*)&obj->unknown_14_);
        Vector3fix_Subtract((const Vector3fix*)&obj->unknown_14_, (const Vector3fix*)&saved, (Vector3fix*)&dir);
        Vector3fix_Normalize((const Vector3fix*)&dir, (Vector3fix*)&dir);
        int angle2 = fix32_Atan2(dir.x, dir.z);

        GameObject_SetFacing((struct Obj02033834*)combatant, angle2);
        GameObject_SetMotionState((struct Obj02033b68*)combatant, 1);
        SetBrightness((GameResources*)mgr, -16, 15);

        obj->state = obj->state + 1;
        obj->counter = 0;
    } else if (state == 1) {
        int var9 = *((unsigned char*)g + Enum_ov017_021ab280_2096);
        if (var9 <= 4) {
            obj->state = state + 1;
            obj->counter = 0;
            GameObject_StoreMotionState((struct Foo02033b58*)combatant, 1);
        }
    } else if (state == 2) {
        struct Vec3 delta;
        struct Vec3 saved = *(struct Vec3*)((char*)combatant + 0x44);
        Vector3fix_Subtract((const Vector3fix*)&obj->unknown_14_, (const Vector3fix*)&saved, (Vector3fix*)&delta);
        Vector3fix_Length((const Vector3fix*)((int*)&delta));
        Vector3fix_Subtract((const Vector3fix*)&obj->unknown_14_, (const Vector3fix*)&saved, (Vector3fix*)&delta);
        Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
        int angle2 = fix32_Atan2(delta.x, delta.z);

        GameObject_SetFacing((struct Obj02033834*)combatant, angle2);
        GameObject_StoreMotionState((struct Foo02033b58*)combatant, 1);
        *(unsigned short*)((char*)combatant + 0xb2) = 0xa3;

        if (IsBrightnessTransitionActive((GameResources*)mgr) == 0) {
            obj->state = 4;
            obj->counter = 0;
        }
    } else if (state == 3) {
        struct Vec3 delta;
        struct Vec3 saved = *(struct Vec3*)((char*)combatant + 0x44);
        Vector3fix_Subtract((const Vector3fix*)&obj->unknown_14_, (const Vector3fix*)&saved, (Vector3fix*)&delta);
        Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
        int angle2 = fix32_Atan2(delta.x, delta.z);

        GameObject_SetFacing((struct Obj02033834*)combatant, angle2);
        GameObject_StoreMotionState((struct Foo02033b58*)combatant, 1);
        *(unsigned short*)((char*)combatant + 0xb2) = 0xa3;

        if (IsBrightnessTransitionActive((GameResources*)mgr) == 0) {
            obj->state = obj->state + 1;
            obj->counter = 0;
        }
    } else if (state == 4) {
        ((Object3D*)((unsigned char*)combatant))->DisableFlag(0x01000080);

        unsigned char buf[4];
        unsigned char count = GameState_GetOwnPartyOrder((char*)battle, buf);
        for (int i = 0; i < count; i++) {
            GameObject* c = battle->GetGameObjectByIndex(buf[i]);
            if (c != 0) {
                ((Object3D*)((unsigned char*)c))->DisableFlag(0x1000000);
            }
        }

        void* entryV = GameState_GetZoneTransition(battle);
        GameState_GetProtagonistIndex(battle);
        VectorizedMemset(entryV, 0, 0x70);
        unsigned char* e = (unsigned char*)entryV;
        unsigned char one = 1;
        e[4] = one;
        e[8] = one;
        e[9] = one;
        int var23 = one - 2;
        *(signed char*)(e + 0xb) = var23;
        *(int*)(e + 0x20) = var23;
        *(int*)(e + 0x24) = var23;
        *(int*)(e + 0x28) = var23;
        *(int*)(e + 0x2c) = var23;
        *(short*)(e + 0x1e) = var23;
        e[0xc] = 0;
        *(short*)(e + 0x6c) = var23;

        *(unsigned short*)(e + 0) = obj->pos->unknown_30_;
        *(Vector3i*)((int*)(e + 0x10)) = *(Vector3i const*)((int*)&obj->pos->unknown_38_[0]);
        *(short*)(e + 0x1c) = obj->pos->unknown_68_;
        e[0xb] = (unsigned char)obj->pos->unknown_6a_;
        *(Vector3i*)((int*)(e + 0x30)) = *(Vector3i const*)((int*)&obj->pos->unknown_38_[0]);
        *(Vector3i*)((int*)(e + 0x3c)) = *(Vector3i const*)((int*)&obj->pos->unknown_38_[1]);
        *(Vector3i*)((int*)(e + 0x48)) = *(Vector3i const*)((int*)&obj->pos->unknown_38_[2]);
        *(Vector3i*)((int*)(e + 0x54)) = *(Vector3i const*)((int*)&obj->pos->unknown_38_[3]);

        e[0xc] = 1;
        e[7] = 1;
        GameState_SetZoneTransition(battle, entryV);

        FieldTask_InitEnterZone(*(unsigned char**)(mgr + 0x3000 + kResourceHeaderOffset), 0);
        func_020469b4(*(struct TailList020469b4**)(mgr + 0x3000 + Enum_ov017_021ab280_1788),
                          *(struct TailNode020469b4**)(mgr + 0x3000 + kResourceHeaderOffset));

        obj->field1 = 1;
    }

    obj->counter = obj->counter + 1;
    return obj->counter;
}
