#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Combat/EntryGetterTypes.h"

struct Struct_02017a94 { char unknown_0_[6]; short unknown_6_; };
struct Struct_0203dce4_2;

struct Struct_02015438;
struct GameResources;
struct Struct_0203cec4;
struct Struct_0203fc5c;
struct Node020406f8;
struct Vec3_020406f8 { int x; int y; int z; };
struct Node02040774;
struct Npc;
struct Obj02040b2c;
struct EntryPositionState { char unknown0[0x10]; int x; int y; int z; short value; };

extern "C" void* Zone3D_GetInstance(void);
extern "C" int rand(void);
extern "C" long long fix32_SinFx64c(int phase);
extern "C" long long fix32_CosFx64c(int phase);
extern "C" float _ll_sto_f(long long);
struct EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c();
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24**);
struct Obj0201b600* FindElemByKeys(Obj0201b600*, int, unsigned short);
struct Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(struct EntryList_203dce4*, int);
void ClearFlag0x1_02040648(unsigned int*);
int IsField0Null_02046b08(void**);
int IsMainBrightnessTransitionActive(struct GameResources*);
int GetMainBrightnessTransitionState(struct GameResources*);
void SetActiveChildFields02040774(struct Node02040774*, int, int, int);
void PropagateValueToActiveSlot02040b2c(struct Obj02040b2c*, int);
void SelectVec3FromSources020406f8(struct Vec3_020406f8*, struct Node020406f8*);
void SetOrClearFlag0x8_0203cec4(struct Struct_203cec4*, int);
void SetField40IfPositive(struct Struct_0203fc5c*, float);
void Npc_WalkTo(struct Npc*, int);

// USA: func_020aeb34
extern "C" ARM void func_020aeb34(void) {
    struct Struct_0203dce4_2* var0;
    struct Struct_0203dce4* var1[4];
    GameResources* var2;
    struct Struct_02017a94* var3;
    int var4;
    struct Struct_02015438** var5;

    elem = (struct Obj0201b600*)Zone3D_GetInstance();
    list = GetGlobalPtr021075f4_0203cf4c();
    base = GetGameResources();
    head = (HeadNode02046b24**)base->fieldTaskQueue_;
    GetHeadNodeIdOrMinusOne(head);
    elem = FindElemByKeys(elem, 0, 0x2a);

    if (var3 == NULL) return;

    for (var4 = 0; var4 < 4; var4++) {
        var1[var4] = func_0203dce4(var0, var2->unknown_444a_[var4]);
        if (var1[var4] == NULL) return;
        func_02040648((unsigned int*)var1[var4]);
    }

    if (func_02046b08((void**)var5) == 0 && IsMainBrightnessTransitionActive(var2) == 0 &&
        (GetMainBrightnessTransitionState(var2) == 2 ||
         GetMainBrightnessTransitionState(var2) == 3)) {
        if (var3->unknown_6_ != 0) return;
        for (int var6 = 0; var6 < 4; var6++) {
            Struct_020aeb34* var7 = (Struct_020aeb34*)func_02040538((Struct_0203e0a0*)var1[var6]);
            func_02040774((struct Struct_0203d028_15*)var1[var6], var7->unknown_10_, var7->unknown_14_, var7->unknown_18_);
            func_02040b2c((struct Struct_0203e2c4_2*)var1[var6], var7->unknown_1c_);
        }
        return;
    }

    var2->unknown_4454_ += 2 * (rand() % 13 - 6);
    if (var2->unknown_4454_ > 0x2d) var2->unknown_4454_ = 0x2d;
    if (var2->unknown_4454_ < 0x20) var2->unknown_4454_ = 0x20;

    int var8 = 88006;
    if (var3->unknown_6_ <= var2->unknown_4454_) {
        var3->unknown_6_ += 0x6487;
    }
    var3->unknown_6_ -= var2->unknown_4454_;

    int var9 = var3->unknown_6_;

    for (int k = 0; k < 4; k++) {
        int phase;
        Vector3fix vecB;
        Vector3fix vecA;
        Vector3fix out;
        struct Vec3_020406f8 sel;

        var9 += 0x1921;
        if (var9 >= 0x6487) var9 -= 0x6487;
        var11 = var9 - 0xcc;
        if (var11 <= 0) var11 += 0x6487;

        vecB.x = (int)(4096.0f * (_ll_sto_f(fix32_SinFx64c(phase)) / 4294967296.0f)) * 2;
        vecB.y = 0;
        vecB.z = (int)(4096.0f * (_ll_sto_f(fix32_CosFx64c(phase)) / 4294967296.0f)) * 2;

        var13.unknown_0_ = var8;
        struct Struct_0203dce4* var16 = var1[var10];
        func_020406f8(&var15, (struct Struct_0203de84_2*)var16);
        var13.unknown_8_ = -0x970;
        var13.unknown_4_ = var15.unknown_4_;

        Vector3fix_Add(&var13, &var12, &var14);

        if ((entry->child14) != NULL) SetOrClearFlag0x8_0203cec4((struct Struct_203cec4*)(entry->child14), 1);
        if ((entry->child14) != NULL) SetField40IfPositive((struct Struct_0203fc5c*)(entry->child14), 0.8f);
        Npc_WalkTo((struct Npc*)entry, (int)&out);
        SetActiveChildFields02040774((struct Node02040774*)entry, out.x, out.y, out.z);
    }
}
