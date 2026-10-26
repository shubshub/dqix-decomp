#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021ab280_2096 = 0x850, Enum_ov017_021ab280_1804 = 0x4fc, Enum_ov017_021ab280_1788 = 0x4ec };
#else
enum { Enum_ov017_021ab280_2096 = 0x830, Enum_ov017_021ab280_1804 = 0x70c, Enum_ov017_021ab280_1788 = 0x6fc };
#endif

#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);

struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

int fix32ReduceAngle0To2Pi(int angle);
int fix32sin(int angle);
int fix32cos(int angle);

struct Struct_ov009_0218aa28 { int unknown_0_; int unknown_4_; int unknown_8_; };
extern "C" int fix32_Atan2(int arg0, int arg1);

struct Obj02033834;
void GameObject_SetFacing(struct Obj02033834* obj, int arg);
struct Obj02033b68;
void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);
struct Foo02033b58;
void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);
struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);

unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);

void* GameState_GetZoneTransition(GameState* battleStruct);
int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void VectorizedMemset(void* dst, int val, int size);
struct Vector3i;
void FieldTask_InitEnterZone(unsigned char* obj, int flag);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_021ab280 {
    char unknown_0_[8];
    int unknown_8_, unknown_c_, unknown_10_;
    char unknown_14_[0x20 - 0x14];
    short unknown_20_;
    char unknown_22_[0x30 - 0x22];
    unsigned short unknown_30_;
    char unknown_32_[0x38 - 0x32];
    struct Struct_ov009_0218aa28 unknown_38_[4];
    short unknown_68_;
    short unknown_6a_;
};

struct Struct_ov017_021ab280_2 {
    char unknown_0_[1];
    unsigned char unknown_1_;
    char unknown_2_[8 - 2];
    int unknown_8_;
    int unknown_c_;
    struct Struct_ov017_021ab280* unknown_10_;
    struct Struct_ov009_0218aa28 unknown_14_;
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

        struct Struct_ov009_0218aa28 var5;
        struct Struct_ov009_0218aa28 var6 = *(struct Struct_ov009_0218aa28*)((char*)var2 + 0x44);
        int var7 = fix32ReduceAngle0To2Pi(arg0->unknown_10_->unknown_20_ + (int)0xffffcdc3);
        var5.unknown_0_ = fix32sin(var7);
        var5.unknown_4_ = 0;
        var5.unknown_8_ = fix32cos(var7);
        Vector3fix_Normalize((const Vector3fix*)&var5, (Vector3fix*)&var5);
        Vector3fix_Add((const Vector3fix*)((struct Struct_ov009_0218aa28*)&arg0->unknown_10_->unknown_8_), (const Vector3fix*)&var5, (Vector3fix*)&arg0->unknown_14_);
        Vector3fix_Subtract((const Vector3fix*)&arg0->unknown_14_, (const Vector3fix*)&var6, (Vector3fix*)&var5);
        Vector3fix_Normalize((const Vector3fix*)&var5, (Vector3fix*)&var5);
        int var8 = fix32_Atan2(var5.unknown_0_, var5.unknown_8_);

        GameObject_SetFacing((struct Obj02033834*)combatant, angle2);
        GameObject_SetMotionState((struct Obj02033b68*)combatant, 1);
        SetBrightness((GameResources*)mgr, -16, 15);

        obj->state = obj->state + 1;
        obj->counter = 0;
    } else if (state == 1) {
        int gVal = *((unsigned char*)g + kGlobalByteOffset);
        if (gVal <= 4) {
            obj->state = state + 1;
            obj->counter = 0;
            GameObject_StoreMotionState((struct Foo02033b58*)combatant, 1);
        }
    } else if (var4 == 2) {
        struct Struct_ov009_0218aa28 var10;
        struct Struct_ov009_0218aa28 var11 = *(struct Struct_ov009_0218aa28*)((char*)var2 + 0x44);
        Vector3fix_Subtract((const Vector3fix*)&arg0->unknown_14_, (const Vector3fix*)&var11, (Vector3fix*)&var10);
        Vector3fix_Length((const Vector3fix*)((int*)&var10));
        Vector3fix_Subtract((const Vector3fix*)&arg0->unknown_14_, (const Vector3fix*)&var11, (Vector3fix*)&var10);
        Vector3fix_Normalize((const Vector3fix*)&var10, (Vector3fix*)&var10);
        int var12 = fix32_Atan2(var10.unknown_0_, var10.unknown_8_);

        GameObject_SetFacing((struct Obj02033834*)combatant, angle2);
        GameObject_StoreMotionState((struct Foo02033b58*)combatant, 1);
        *(unsigned short*)((char*)combatant + 0xb2) = 0xa3;

        if (IsBrightnessTransitionActive((GameResources*)var1) == 0) {
            arg0->unknown_8_ = 4;
            arg0->unknown_c_ = 0;
        }
    } else if (var4 == 3) {
        struct Struct_ov009_0218aa28 var13;
        struct Struct_ov009_0218aa28 var14 = *(struct Struct_ov009_0218aa28*)((char*)var2 + 0x44);
        Vector3fix_Subtract((const Vector3fix*)&arg0->unknown_14_, (const Vector3fix*)&var14, (Vector3fix*)&var13);
        Vector3fix_Normalize((const Vector3fix*)&var13, (Vector3fix*)&var13);
        int var15 = fix32_Atan2(var13.unknown_0_, var13.unknown_8_);

        GameObject_SetFacing((struct Obj02033834*)combatant, angle2);
        GameObject_StoreMotionState((struct Foo02033b58*)combatant, 1);
        *(unsigned short*)((char*)combatant + 0xb2) = 0xa3;

        if (IsBrightnessTransitionActive((GameResources*)var1) == 0) {
            arg0->unknown_8_ = arg0->unknown_8_ + 1;
            arg0->unknown_c_ = 0;
        }
    } else if (var4 == 4) {
        ((Object3D*)((unsigned char*)var2))->DisableFlag(0x01000080);

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
        int negOneB = one - 2;
        *(signed char*)(e + 0xb) = negOneB;
        *(int*)(e + 0x20) = negOneB;
        *(int*)(e + 0x24) = negOneB;
        *(int*)(e + 0x28) = negOneB;
        *(int*)(e + 0x2c) = negOneB;
        *(short*)(e + 0x1e) = negOneB;
        e[0xc] = 0;
        *(short*)(e + 0x6c) = negOneB;

        *(unsigned short*)(var21 + 0) = arg0->unknown_10_->unknown_30_;
        *(Vector3i*)((int*)(var21 + 0x10)) = *(Vector3i const*)((int*)&arg0->unknown_10_->unknown_38_[0]);
        *(short*)(var21 + 0x1c) = arg0->unknown_10_->unknown_68_;
        var21[0xb] = (unsigned char)arg0->unknown_10_->unknown_6a_;
        *(Vector3i*)((int*)(var21 + 0x30)) = *(Vector3i const*)((int*)&arg0->unknown_10_->unknown_38_[0]);
        *(Vector3i*)((int*)(var21 + 0x3c)) = *(Vector3i const*)((int*)&arg0->unknown_10_->unknown_38_[1]);
        *(Vector3i*)((int*)(var21 + 0x48)) = *(Vector3i const*)((int*)&arg0->unknown_10_->unknown_38_[2]);
        *(Vector3i*)((int*)(var21 + 0x54)) = *(Vector3i const*)((int*)&arg0->unknown_10_->unknown_38_[3]);

        e[0xc] = 1;
        e[7] = 1;
        GameState_SetZoneTransition(battle, entryV);

        FieldTask_InitEnterZone(*(unsigned char**)(mgr + 0x3000 + kResourceHeaderOffset), 0);
        AppendNodeToTail(*(struct TailList020469b4**)(mgr + 0x3000 + kResourceTailOffset),
                          *(struct TailNode020469b4**)(mgr + 0x3000 + kResourceHeaderOffset));

        arg0->unknown_1_ = 1;
    }

    arg0->unknown_c_ = arg0->unknown_c_ + 1;
    return arg0->unknown_c_;
}
