#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021ab280_2096 = 0x850, Enum_ov017_021ab280_1804 = 0x4fc, Enum_ov017_021ab280_1788 = 0x4ec };
#else
enum { Enum_ov017_021ab280_2096 = 0x830, Enum_ov017_021ab280_1804 = 0x70c, Enum_ov017_021ab280_1788 = 0x6fc };
#endif

#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* func_0202ae18(void);
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
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);
struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);

extern "C" unsigned char func_02011494(char* arg0, void* arg1);

void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);
int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void VectorizedMemset(void* dst, int val, int size);
struct Vector3i;
extern "C" void func_ov017_0219e310(unsigned char* arg0, int arg1);
struct Struct_0201bdac_2;
struct Struct_0201bdac;
extern "C" void func_020469b4(struct Struct_0201bdac_2* arg0, struct Struct_0201bdac* arg1);

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
    func_0202ae18();
    unsigned char* mgr = (unsigned char*)GetGameResources();
    GameObject* combatant = battle->GetUnknownGameObject();
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

        arg0->unknown_8_ = arg0->unknown_8_ + 1;
        arg0->unknown_c_ = 0;
    } else if (var4 == 1) {
        int var9 = *((unsigned char*)var3 + Enum_ov017_021ab280_2096);
        if (var9 <= 4) {
            arg0->unknown_8_ = var4 + 1;
            arg0->unknown_c_ = 0;
            func_02033b58((struct Struct_02033b58*)var2, 1);
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
        SetByteSavingPrevious((struct Foo02033b58*)combatant, 1);
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
        SetByteSavingPrevious((struct Foo02033b58*)combatant, 1);
        *(unsigned short*)((char*)combatant + 0xb2) = 0xa3;

        if (IsBrightnessTransitionActive((GameResources*)var1) == 0) {
            arg0->unknown_8_ = arg0->unknown_8_ + 1;
            arg0->unknown_c_ = 0;
        }
    } else if (var4 == 4) {
        ((Object3D*)((unsigned char*)var2))->DisableFlag(0x01000080);

        unsigned char var16[4];
        unsigned char var17 = func_02011494((char*)var0, var16);
        for (int var18 = 0; var18 < var17; var18++) {
            GameObject* var19 = var0->GetGameObjectByIndex(var16[var18]);
            if (var19 != 0) {
                ((Object3D*)((unsigned char*)var19))->DisableFlag(0x1000000);
            }
        }

        void* entryV = GetField0x3f8Address_0200fd0c(battle);
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

        var21[0xc] = 1;
        var21[7] = 1;
        func_0200fcfc(var0, var20);

        func_ov017_0219e310(*(unsigned char**)(var1 + 0x3000 + Enum_ov017_021ab280_1804), 0);
        func_020469b4(*(struct Struct_0201bdac_2**)(var1 + 0x3000 + Enum_ov017_021ab280_1788),
                          *(struct Struct_0201bdac**)(var1 + 0x3000 + Enum_ov017_021ab280_1804));

        arg0->unknown_1_ = 1;
    }

    arg0->unknown_c_ = arg0->unknown_c_ + 1;
    return arg0->unknown_c_;
}
