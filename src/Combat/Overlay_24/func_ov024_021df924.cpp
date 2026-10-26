#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Util/Random.h"

struct Struct_02052df8;
struct Struct_020a0720;
struct Struct_0209fffc;
struct Struct_020a0750;
struct Struct_020a0038;

struct Struct_ov024_021df924_7 {
    char unknown_0_[0x3d];
    unsigned char unknown_3d_;
};
struct Struct_ov024_021df924_8 {
    char unknown_0_[0x10];
    unsigned short unknown_10_;
};
struct Struct_ov024_021df924_9 {
    char unknown_0_[2];
    unsigned char unknown_2_[2];
    unsigned short unknown_4_[2];
};
struct Struct_ov024_021df924_10 {
    char unknown_0_[4];
    unsigned int unknown_4_0_ : 10;
    unsigned int unknown_5_2_ : 22;
};
struct Struct_ov024_021df924_11 : GameObject {
    char unknown_13c_[8];
#if defined(jpn)
    union {
        Struct_ov024_021df924_8* unknown_144_;
        Struct_ov024_021df924_10* unknown_150_;
    };
    Struct_ov024_021df924_9* unknown_148_;
#else
    Struct_ov024_021df924_8* unknown_144_;
    Struct_ov024_021df924_9* unknown_148_;
    char unknown_14c_[4];
    Struct_ov024_021df924_10* unknown_150_;
#endif
};
struct Struct_ov024_021df924_12 {
    char unknown_0_[4];
    short unknown_4_;
};
struct Struct_ov024_021df924_13 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 7;
    unsigned char unknown_1c_7_ : 1;
};
struct Struct_ov024_021df924 {
    char unknown_0_[0x8e4a];
    short unknown_8e4a_;
};
struct Struct_ov024_021df924_2 {
    int unknown_0_;
    Struct_ov024_021df924_12* unknown_4_;
    int unknown_8_;
    Struct_ov024_021df924_13* unknown_c_;
    Struct_ov024_021df924* unknown_10_;
};
struct Struct_ov024_021df924_3 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};
struct Struct_ov024_021df924_4 {
    char unknown_0_[0x20];
    Struct_ov024_021df924_3 unknown_20_;
    Struct_ov024_021df924_3 unknown_24_;
};
struct Struct_ov024_021df924_5 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 1;
    unsigned int unknown_1_3_ : 7;
    unsigned int unknown_2_2_ : 7;
    unsigned int unknown_3_1_ : 7;
};
struct Struct_ov024_021df924_6 {
    SafeAllocator unknown_0_;
    char unknown_14_[0x2c - sizeof(SafeAllocator)];
    void* unknown_2c_;
    char unknown_30_[8];
};

extern float data_ov024_021fe860[];

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
int IsIdOrEffectMatchTarget0215fd24(int world, int id);
extern "C" unsigned short* Zone3D_GetInstance(void);
static inline int GetActionID() { return *Zone3D_GetInstance(); }
extern "C" int func_ov024_021df71c(Fighter021df924* self, unsigned short actionID, int alternate, unsigned short* resultID, unsigned short* combatantKey, unsigned short* entryID);
short GetHalfwordEntryFromField150(Field150Holder02052df8* holder, int part);
void* GetActiveCombatWork_ov000_02160130();
char* GetOffsetPtr02160f08(void* work);
void* ItemTable_Construct(void* obj);
void InitStruct0207cbe8(char* obj);
void SetShortFields0x8e4aTo0x8e4e_ov000_0215fa70(void*, short, short, short);
extern "C" int func_0207ccf0(void* buf, int a, int b, int c, int d, int e, int f);
int CopyIndexedRegion0x75f0_020ac020(void* unused, short* indices, int* dest, int count);
extern "C" void func_020abe84(void* unused, short* indices, Counts021df924* values, int count);
void LoadBattleBlock020ac4c0(void* block);
void AddClamped24BitField_020a0720(S_a0720* block, unsigned int value);
void AddClampedLow16BitFieldAt0x8_0209fffc(S_9fffc* block, unsigned int value);
void AddCappedValue_020a0750(Field0x30* block, unsigned int value);
void AddClampedHigh16BitFieldAt0x8_020a0038(S_a0038* block, unsigned int value);
void CopyInBattleField0x7540_020ac494(void* block);
extern "C" void* func_ov000_0215e958(void* world);
void AddEntryAndIncrementCount0215a88c(void* world, void* entry, int value);
extern "C" void func_ov000_0215cd44(void* world, void* entry, GameObject* target, int a, int b, int c, int d);

// USA: func_ov024_021df924
extern "C" ARM void* func_ov024_021df924(Action021df924* self, short id, int targetId, ActionData021df924* data) {
    Fighter021df924* actor = (Fighter021df924*)GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), id);
    if (!actor) return 0;
    Fighter021df924* target = (Fighter021df924*)GetCombatantWithFlag0x400ByID_ov000_021536f8((int)self->world, targetId);
    if (!target) return 0;
    Odds021df924* odds = target->odds;
    if (!odds) return 0;
    int stolen = 0;
    unsigned char* rate;
    unsigned short* msg;
    rate = odds->rate;
    msg = odds->message;
    short level = (unsigned short)actor->info->level;
    Random* rng = (Random*)self->world;
    float rolls[2];
    rolls[0] = NextRandomFloatBetween(rng, 0.0f, 100.0f);
    rolls[1] = NextRandomFloatBetween(rng, 0.0f, 100.0f);
    int anyRate = 0;
    unsigned short resultID;
    unsigned short entryID;
    unsigned short combatantKey;
    Counts021df924 counts;
    Loader021df924 loader;
    int i;
    for (i = 0; i < 2; i++, rate++, msg++) {
        if (*rate == 0) continue;
        resultID = 0;
        entryID = 0;
        combatantKey = 0;
        int found = 0;
        void* scene = LinkSession_GetInstance();
        if (self->world->pending == 0 && LinkSession_IsHostOrSolo(scene) && IsIdOrEffectMatchTarget0215fd24((int)self->world, id)) {
            found = func_ov024_021df71c(target, GetActionID(), i != 0, &resultID, &combatantKey, &entryID);
        }
        if (((Struct_ov024_021df924_7*)var1->currentStats_)->unknown_3d_ != 0 && !var16) continue;
        if (data_ov024_021fe860[*var4] > 0.0f) var9 = 1;
        float var18 = 2.0f * (100.0f * data_ov024_021fe860[*var4]);
        float var19 = 6.0f * (100.0f * data_ov024_021fe860[*var4]);
        if (func_02052df8((Struct_02052df8*)var0, 9) == 0x467f) {
            var18 = 2.0f * var18;
            var19 = 2.0f * var19;
        }
        if (var18 > 50.0f) var18 = 50.0f;
        if (var19 > 50.0f) var19 = 50.0f;
        if (var6 > 0x33) {
            if (var6 >= 999) var18 = var19;
            else var18 = var18 + (float)(var6 - 0x33) * ((var19 - var18) / 948.0f);
        }
        if (!(rolls[i] < low)) continue;
        self->message->id = *msg;
        stolen = 1;
        ((Stats021df924*)target->currentStats_)->rank = i + 1;
        if (IsIdOrEffectMatchTarget0215fd24((int)self->world, id)) {
            char* work = GetOffsetPtr02160f08(GetActiveCombatWork_ov000_02160130());
            char* special = work + 0xd0;
            char* normal = work + 0xe8;
            loader.alloc.ResetAllocatorPointer();
            ItemTable_Construct(loader.body);
            InitStruct0207cbe8((char*)&loader);
            InitStruct0207cbe8((char*)&loader);
            if (found) {
                self->message->id = resultID;
                SetShortFields0x8e4aTo0x8e4e_ov000_0215fa70(self->world, entryID, combatantKey, resultID);
                loader.source = special;
            } else {
                var14.unknown_2c_ = var22;
                func_0207ccf0(&var14, arg0->unknown_4_->unknown_4_, 1, arg1, 1, 0, 0);
                var13.unknown_0_0_ = 0;
                var13.unknown_1_2_ = 0;
                var13.unknown_1_3_ = 0;
                var13.unknown_2_2_ = 0;
                if (var1->unknown_144_) {
                    short var23 = var1->unknown_144_->unknown_10_;
                    if (func_020ac020(0, &var23, (int*)&var13, 1)) {
                        if (var15 == 0) {
                            unsigned int var24 = var13.unknown_1_3_ + 1;
                            if (var24 > 99) var24 = 99;
                            var13.unknown_1_3_ = var24;
                        }
                        if (var15 == 1) {
                            unsigned int var25 = var13.unknown_2_2_ + 1;
                            if (var25 > 99) var25 = 99;
                            var13.unknown_2_2_ = var25;
                        }
                        func_020abe84(0, &var23, &var13, 1);
                    }
                }
            }
        }
        break;
    }
    char var26[0xb0];
    func_020ac4c0(var26);
    char* var27 = var26 + 0x68;
    func_020a0720((Struct_020a0720*)var26, 1);
    func_0209fffc((Struct_0209fffc*)var27, 1);
    unsigned short var28;
    if (var3) {
        func_020a0750((Struct_020a0750*)var26, 1);
        func_020a0038((Struct_020a0038*)var27, 1);
        var28 = arg3->unknown_24_.unknown_0_0_;
    } else if (!var9) {
        var28 = 0x25a;
    } else {
        var28 = arg3->unknown_24_.unknown_2_4_;
    }
    func_020ac494(var26);
    void* var29 = func_ov000_0215e958(arg0->unknown_10_);
    if (!var29) return 0;
    if (var28) func_ov000_0215a88c(arg0->unknown_10_, var29, var28);
    func_ov000_0215cd44(arg0->unknown_10_, var29, var1, 0, 0, 0, arg0->unknown_c_->unknown_1c_7_ != 0);
    return var29;
}
