#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/Brightness.h"

struct Struct_ov026_021d8ba0_4;
struct Struct_ov000_02160da0;
struct Struct_ov000_02161e30;
struct Struct_ov000_0217e870_2;
struct Struct_ov026_021d8ba0_5;
struct Struct_ov023_021f4c04;
struct Struct_ov026_021d8ba0_6;
struct Struct_ov026_021d8ba0_7;
struct Struct_ov026_021d8ba0_8;
struct Struct_ov026_021d8ba0_9;
struct Struct_020a36a8;
struct Struct_0200f3a4_8;
struct Struct_0209a470;
struct Struct_02086f24_6;
struct Struct_02013fb4;
struct Struct_0204671c;
struct Struct_020d6ec8;
struct Struct_ov000_02163a7c;
struct Struct_02010088;
struct Struct_ov026_021d8ba0_10;
struct Struct_0203c108_3;
struct Struct_02053dc0;
struct Struct_02010604;
struct Struct_02015ef4_5;
struct Struct_020e385c;
struct Struct_02046574_2;
struct Struct_02012de8;
struct Struct_02038598_4;
struct Struct_0202b2f0;
struct Struct_02053dd0;

struct Struct_ov026_021d8ba0 {
    unsigned char unknown_0_[4];
    signed char unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
};

struct Struct_ov026_021de6dc { int unknown_0_[3]; };
struct Struct_ov026_021d8ba0_2 { int unknown_0_, unknown_4_; };
struct Struct_020e6e88 { char unknown_0_[0x80]; };
struct Struct_ov026_021d8ba0_3 {
    char unknown_0_[8][3];
    int unknown_18_;
    const char* unknown_1c_[8];
};

inline Struct_ov026_021d8ba0_3& inline_ov026_021d8ba0_2() {
    static Struct_ov026_021d8ba0_3 s = {
        {"f4", "f3", "f1", "f2", "b4", "b1", "b2", "b3"},
        -1,
        {s.unknown_0_[2], s.unknown_0_[3], s.unknown_0_[1], s.unknown_0_[0], s.unknown_0_[5], s.unknown_0_[6], s.unknown_0_[7], s.unknown_0_[4]},
    };
    return s;
}

struct Struct_ov000_0215440c_6 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unknown_2_[4];
    unsigned char unknown_6_[8];
    unsigned char unknown_e_0_ : 4;
    unsigned char unknown_e_4_ : 4;
    unsigned char unknown_f_[9];
};

int GameState_GetProtagonistIndex(GameState*);
SlotWork* FindSlotById_021dae60(Container_021dae60*, int);
MessageWork* MessageSystem_GetInstance();
void* GetData02100044_0202ae24();
void* GlobalFlags_GetInstance();
unsigned char* GetData02153634_020e3580();
int ClassifyField0x81fe_ov000_0215fc60(char*);
void SetFieldsAndSignalData02184220_ov000_02160d80(void*, int);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void*, int);
void ClearCombatWorkFlags0x55f4_ov000_02160fbc(void*, int);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void*, int);
void MarkSlots0218173c(void*);
int GetByte0x63d5_02012060(void*);
int CheckField0NonZero_0202b7d8(int*);
int MatchesActiveIndex020a36a8(Combatant020A36A8*);
void InitOverlay17Sub0215e8e8(void*);
void ClearFirstTwoWords0209a338(Pair0209a338*);
void SetupAndRunBufferedScript0209a470(Ctx0209a470*, SafeAllocator*, StreamHeader*, int);
void ClearField00209a804(int*);
void SetupAndRunBufferedScript0209a8b4(Ctx0209a8b4*, SafeAllocator*, StreamHeader*, int);
void SePlayer_UnloadExtraArchiveA(void*);
int GetField0x0(S0204671c*);
void ResetField0x930And0x934_ov000_02180b3c(void*);
ViewInfo* GetPtrField612_0216f208(void*);
void InitCombatantPosition_0216118c(void*, int);
void ClearFlagIfParityMismatch02163710_02163710(void*, int);
void RunFlaglearAndSetMode02167e6c_02167e6c(unsigned char*);
Container020d6f44* GetField02163524(void*);
void ResetEntryManager020d6f44(Container020d6f44*);
void ProcessCombatantReactions020d738c(void*);
void ApplyField41ToGatheredCombatants02163a7c(GatherObj02163a7c*);
int GetSubstructByte0x1c_020493a4(unsigned char*);
void SetSubstructByte0x1c_02049390(unsigned char*, unsigned char);
void SetSubstructFields0x10And0x18ClearFlag0x1_02049bd4(unsigned char*, int*);
void MessageSystem_Reset(char*);
void ReleaseEntriesTwoGroups02174dc0(void*);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
char* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
int IsFlag10088Set_02010088(S_10088*);
int IsFlagBit8192Set_021dd3c4(FlagObj_021dd3c4*);
void SwapGlobalEntry0203c108(Obj0203c108*, char*);
void SetStoredWorkPtr_ov000_021744f4(int, void*);
void ClearFlag0x43e02176054(void*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
void* GetField0x19cOrNull(S02053dc0*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void Process02181364(void*);
void ClearFlag_021816e8_021816e8(void*, int);
void SetFlag_02181694_02181694(void*, int);
void ClearByteField_0217f5d0_0217f5d0(void*);
void VramState_CopyCurrentTo(State0207dfc8*, State0207dfc8*);
void EnqueueEventTag89_021ca174(unsigned short);
TagValueEntry020e385c* GetData02153660_020e3808();
int IsEntryCompleteOrMissing020e3ad0(TagValueEntry020e385c*, int, int);
unsigned char* FindEntryByTagAndValue(TagValueEntry020e385c*, int, int);
void ResetTaggedEntryAndNotifyOverlay020e3994(TagValueEntry020e385c*, int, int);
void SetBrightness(GameResources*, int, int);
int IsField0Null_02046b08(void**);
void UpdateFieldIfDiffers_02174514_02174514(void*);
void ClearFlag0x1000AndBytes7eA1_02088e64(unsigned char*);
void* KeyTable_Get(Container020e0310*, int);
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
int TestFlags02046708(FlagWord02046708*, unsigned int);
void FlagWord_SetBits(unsigned int*, unsigned int);
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
int GetByte2IfGlobalFlagSet_020e37e8(unsigned char*);
void ClearBitOrNotifyOverlay020e3798(unsigned char*);
void SetBitOrNotifyOverlay020e36f0(unsigned char*);
int CountUnder100Flags0217fb98(void*);
void SetBoundedArrayField0x4f4_ov000_02162c90(char*, int, int);
int TestBitBySignedByteIndex_0202c1c0(SearchStruct*, int);
int GetByteField_02168720_02168720(char*);
void ClearSlotBitndSetByte_021813d4(void*);
void SePlayer_LoadExtraArchiveA(void*, int, int);
void DispatchIfField0xc4NonNeg_0205eb90(void*, int, int);
void EnqueueEventTag108_021cefe0(unsigned short, unsigned char, unsigned char);
void EnqueueEventTag109_021cf650(unsigned short, int, int);
int CheckSlotsAllFree0205e488(void*);
void IncrementCounterUnlessFlagged_02053dd0(IncObj*);
void ResetTwoFields021637c8(void*);

extern "C" {
int* func_0202ae18();
void func_ov026_021d8aac( Struct_ov000_02160da0*, int arg1, int arg2);
void func_ov000_02181608(void*);
void func_ov000_0218048c(void*);
void func_ov000_02162cbc( BattleWork*);
void func_ov000_021626a0( BattleWork*, int, int);
void func_ov000_021629ec( BattleWork*);
int func_ov000_0215e9fc(BattleState*, short*, int, int);
int func_ov000_0215ec1c(BattleState*, short*, int, int);
int func_ov000_0215eb1c(BattleState*, short*, int, int);
Pos2i func_ov000_0216f74c(int* cell);
void MessageSystem_Stop(MessageWork*);
void func_ov026_021daec8(BattleState*, void*, int);
void func_ov000_02174614(void*, int);
void func_020e4864(void*, char*, int, int, int, int);
void __clear(void*, int);
void MessageSystem_FormatText(MessageWork*, int, char*, char*, int, int, int);
void func_ov000_0217f518(SlotWork*);
void func_ov000_02162c14( BattleWork*, int, void*);
void func_ov000_0217fa60(void*);
void func_ov000_02175258(void*);
void func_ov000_02174c14(void*);
void func_ov000_021814bc(void*);
void func_ov026_021dc8fc( Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, void*, void*, void*, int);
void* memset(void*, int, unsigned int);
void func_ov000_0217fcc4(void*, int);
int func_0202c540(int*);
void func_ov017_021c6814(unsigned short, unsigned short, Struct_ov026_021d8ba0*, unsigned char, int, int);
int func_ov026_021ddd84(GameResources*, Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, void*, void*, int);
void func_ov017_021c847c();
void func_020dd0b0(int, void*);
void func_0204500c(Struct_ov023_021f4c04*, void*, int, int);
int func_ov026_021d8a40();
void func_ov026_021dce34(int, Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, void*, void*, void*, void*, void*, void*, void*, void*);
void func_ov026_021dd8a8(Struct_ov000_02161e30*, Struct_ov000_0217e870_2*);
void func_ov000_0217fbf4(void*, int);
void func_02046380(Struct_ov023_021f4c04*);
void func_020e4ce8(void*, char*, int);
void func_ov000_0216258c( Struct_ov000_02160da0*);
void func_ov026_021db3d8( Struct_ov000_02160da0*);
int func_0202c508(int*);
void func_ov000_02175be4(void*);
void func_ov026_021db5a4( Struct_ov000_02160da0*);
void func_ov026_021dbba8( Struct_ov000_02160da0*);
void func_ov000_0217457c(void*, int);
unsigned char func_ov026_021dd3dc(Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, void*);
void* func_ov000_02160f14( Struct_ov000_02160da0*);
void func_ov017_021c894c(unsigned short);
void func_ov017_021c8758(unsigned short);
void func_ov017_021c8654();
void* func_02057924();
void func_02057f00(void*, int);
void func_ov000_02168144( Struct_ov000_02160da0*);
void func_ov000_0215d588(Struct_ov000_02161e30*);
void func_ov000_02160da0( Struct_ov000_02160da0*);
void func_ov026_021dc440(SafeAllocator*, Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, int);
int func_ov026_021dc040(SafeAllocator*, Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*);
void func_ov000_02163894( Struct_ov000_02160da0*);
void func_ov000_02163928( Struct_ov000_02160da0*);
}

extern char data_ov026_021dedbc[];
extern char data_ov026_021dedd4[];
extern char g_sePlayer;
extern Vec3i data_ov026_021de6dc;
extern NameBuf data_ov026_021de6f8;
extern NameBuf data_ov026_021de778;
extern char data_ov026_021dedec[];

#define POWCNT (*(volatile unsigned short*)0x04000304)

static inline int inline_ov017_021c9d2c(int arg0) {
    return arg0 >= 0 && arg0 <= 3;
}

struct Struct_ov026_021d8ba0_6 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
};

struct Struct_ov026_021d8ba0_7 {
    char unknown_0_[0x14];
    char* unknown_14_;
};

struct Struct_ov026_021d8ba0_8 {
    char unknown_0_[0xc];
    int unknown_c_;
};

struct Struct_ov026_021d8ba0_9 {
    char unknown_0_[0xc];
    int unknown_c_;
};

struct Struct_ov023_021f4c04 {
    char unknown_0_[0x20];
    char* unknown_20_;
    char unknown_24_[0x38];
    char* unknown_5c_;
    char unknown_60_[0x938];
    int unknown_998_;
    char unknown_99c_[0x1013];
    unsigned char unknown_19af_;
    char unknown_19b0_[0x1a];
    unsigned char unknown_19ca_;
};

struct Struct_ov026_021d8ba0_5 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov000_0217e870_2 {
    char unknown_0_[0x8];
    unsigned short unknown_8_;
    char unknown_a_[0x2];
    int unknown_c_;
    char unknown_10_[0x1a];
    unsigned char unknown_2a_;
    char unknown_2b_[0x1];
    int unknown_2c_;
    int unknown_30_;
    unsigned char unknown_34_;
};

struct Struct_ov000_02161e30 {
    Random unknown_0_;
    char unknown_20_[0x8190];
    Struct_ov000_0215440c_6 unknown_81b0_[4];
    char unknown_8210_[0xc04];
    unsigned char unknown_8e14_;
    char unknown_8e15_[0x3];
    Struct_ov026_021d8ba0_9* unknown_8e18_;
    char unknown_8e1c_[0x4];
    int unknown_8e20_;
    char unknown_8e24_[0x23];
    unsigned char unknown_8e47_;
    char unknown_8e48_[0x1];
    unsigned char unknown_8e49_;
};

struct Struct_ov000_02160da0 {
    char unknown_0_[0x30];
    char unknown_30_[0x11c];
    char unknown_14c_[0x150];
    Struct_ov000_02161e30* unknown_29c_;
    Struct_ov000_0217e870_2* unknown_2a0_;
    char unknown_2a4_[0x974];
    char unknown_c18_[0x220];
    unsigned char unknown_e38_;
    unsigned char unknown_e39_;
    char unknown_e3a_[0x5e];
    char unknown_e98_[0x8];
    char unknown_ea0_[0x8];
    char unknown_ea8_[0x4];
    int unknown_eac_;
    char unknown_eb0_[0x4];
    unsigned char unknown_eb4_;
    unsigned char unknown_eb5_;
    char unknown_eb6_[0x12];
    char unknown_ec8_[0x2898];
    char unknown_3760_[0xb8];
    Struct_0201099c_3 unknown_3818_;
    char unknown_3820_[0xbc];
    int unknown_38dc_;
    char unknown_38e0_[0x7d0];
    int unknown_40b0_;
    unsigned char unknown_40b4_;
    char unknown_40b5_[0x11b7];
    char unknown_526c_[0x150];
    char unknown_53bc_[0xc0];
    int unknown_547c_[8];
    int unknown_549c_[8];
    unsigned char unknown_54bc_;
    char unknown_54bd_[0x3];
    signed char unknown_54c0_[8];
    signed char unknown_54c8_;
    char unknown_54c9_[0x9];
    unsigned short unknown_54d2_;
    char unknown_54d4_[0x4];
    unsigned char unknown_54d8_;
    char unknown_54d9_[0x7];
    unsigned char unknown_54e0_;
    unsigned char unknown_54e1_;
    char unknown_54e2_[0x2];
    Struct_ov026_021d8ba0 unknown_54e4_;
    char unknown_54ee_[0x2];
    int unknown_54f0_;
    int unknown_54f4_[4];
    char unknown_5504_[0xd4];
    int unknown_55d8_;
    char unknown_55dc_[0x18];
    int unknown_55f4_;
    char unknown_55f8_[0x130];
    char unknown_5728_[0x1a6];
    unsigned short unknown_58ce_;
    char unknown_58d0_[0x40];
    char unknown_5910_[0x40];
    unsigned char unknown_5950_;
    char unknown_5951_[0x3];
    char unknown_5954_[0xac];
    char unknown_5a00_[0x23c];
    char unknown_5c3c_[0x1200];
    unsigned int unknown_6e3c_;
    unsigned int unknown_6e40_;
    char unknown_6e44_[0x8cc];
    signed char unknown_7710_;
    unsigned char unknown_7711_;
    signed char unknown_7712_;
    char unknown_7713_[0x1];
    short unknown_7714_;
    short unknown_7716_[4];
    short unknown_771e_;
    short unknown_7720_;
    short unknown_7722_;
    short unknown_7724_;
    char unknown_7726_[0x9];
    unsigned char unknown_772f_;
    char unknown_7730_[0x4];
    int unknown_7734_;
    int unknown_7738_;
    char unknown_773c_[0xc];
    unsigned char unknown_7748_;
    unsigned char unknown_7749_;
    unsigned char unknown_774a_;
    char unknown_774b_[0x1];
    char unknown_774c_[0x14];
    char unknown_7760_[0x150];
    Struct_0201099c_3* inline_ov026_021d8ba0() { return &unknown_3818_; }
};

// USA: func_ov026_021d8ba0
extern "C" ARM void func_ov026_021d8ba0(Struct_ov000_02160da0* arg0) {
    char var0[0x80];
    Struct_020e6e88 var1;
    char var2[0x80];
    Struct_020e6e88 var3;
    char var4[12];
    Struct_ov026_021d8ba0 var5;
    Struct_ov026_021d8ba0 var6;
    Struct_ov026_021d8ba0 var7;
    Struct_ov026_021d8ba0 var8;
    Struct_ov026_021d8ba0 var9;
    short var10[8];
    Struct_ov026_021d8ba0 var11;
    Struct_ov026_021de6dc var12;
    unsigned char var13[12];
    unsigned char var14[12][2];
    unsigned char* var15[12];
    short var16[12];
    GameState* var17;
    GameResources* var18;
    Struct_ov000_02161e30* var19;
    Struct_ov026_021d8ba0_6* var20;
    Struct_ov023_021f4c04* var21;
    int* var22;
    BackgroundLoader* var23;
    void* var24;
    void* var25;
    unsigned char* var26;
    GameObject* var27;
    int var28;
    int var29;
    unsigned char var30;
    unsigned char var31;
    unsigned char var32;
    unsigned char var33;
    int var34;
    GameState* var35;
    GameObject* var36;
    unsigned char var37;
    int var38;
    int var39;
    Struct_ov023_021f4c04* var40;
    char* var41;
    char* var42;
    GameState* var43;
    Struct_ov000_02161e30* var44;
    Struct_ov000_0217e870_2* var45;
    int* var46;
    void** var47;
    Struct_ov026_021d8ba0_7* var48;
    unsigned char var49;

    gs = GameState::GetInstance();
    res = GetGameResources();
    link = func_0202ae18();
    battle = self->battle;
    slot = FindSlotById_021dae60((Container_021dae60*)self->list, GameState_GetProtagonistIndex(gs));
    ctrl = MessageSystem_GetInstance();
    loader = BackgroundLoader::GetInstance();
    slots = GetData02100044_0202ae24();
    flagWord = GlobalFlags_GetInstance();
    field3704 = (void**)res->unknown_ptr_array_3700[1];
    notify = GetData02153634_020e3580();

    if (var19 == 0 || var20 == 0) {
        return;
    }
    if (func_ov000_0215fc60((char*)var19) != 0 && var19->unknown_8e20_ == 2) {
        func_ov000_02160d80(arg0, 4);
        return;
    }
    {
        int var50 = var19->unknown_8e20_;
        func_ov026_021d8aac(arg0, var50, func_ov000_0215fc60((char*)var19));
    }
    if (var18->unknown_42e2_ != 0 && var23->GetNumQueuedTasks() == 0) {
        func_ov000_02160fa8(arg0, 0x2000000);
        return;
    }

    if (arg0->unknown_eac_ == 0) {
        func_ov000_02181608(arg0->unknown_3760_);
        func_ov000_0218173c(arg0->unknown_3760_);
        arg0->unknown_774a_ = 0;
        if (func_02012060(var17) != 0) {
            Struct_ov000_0217e870_2* var51 = arg0->unknown_2a0_;
            if (var51->unknown_c_ < 0 && var51->unknown_2c_ == 0) {
                arg0->unknown_eac_ = 6;
                goto state1;
            }
        }
        ((SafeAllocator*)(arg0->unknown_30_))->Reset();
        inline_ov026_021d8ba0_2().unknown_18_ = var23->QueueLoadFile(data_ov026_021dedbc, 0);
        arg0->unknown_eac_ = 1;
        if (func_0202b7d8(var22) && func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
            func_ov000_0215e8e8(arg0->unknown_29c_);
        }
    }
state1:
    if (arg0->unknown_eac_ == 1) {
        void* var52;
        unsigned int var53;
        if (!var23->GetTaskStatus(inline_ov026_021d8ba0_2().unknown_18_)) {
            return;
        }
        var23->GetLoadedFileByID(inline_ov026_021d8ba0_2().unknown_18_, &var52, &var53);
        func_0209a338((Struct_0200f3a4_8*)(arg0->unknown_e98_));
        func_0209a470((Struct_0209a470*)(arg0->unknown_e98_), (SafeAllocator*)(arg0->unknown_30_), (Struct_02013fb4*)var52, var53);
        var23->RemoveTask(inline_ov026_021d8ba0_2().unknown_18_);
        inline_ov026_021d8ba0_2().unknown_18_ = -1;
        inline_ov026_021d8ba0_2().unknown_18_ = var23->QueueLoadFile(data_ov026_021dedd4, 0);
        arg0->unknown_eac_ = 2;
    }
    if (arg0->unknown_eac_ == 2) {
        void* var54;
        unsigned int var55;
        if (!var23->GetTaskStatus(inline_ov026_021d8ba0_2().unknown_18_)) {
            return;
        }
        var23->GetLoadedFileByID(inline_ov026_021d8ba0_2().unknown_18_, &var54, &var55);
        func_0209a804((int*)(arg0->unknown_ea0_));
        func_0209a8b4((Struct_02086f24_6*)(arg0->unknown_ea0_), (SafeAllocator*)(arg0->unknown_30_), (Struct_02013fb4*)var54, var55);
        var23->RemoveTask(inline_ov026_021d8ba0_2().unknown_18_);
        inline_ov026_021d8ba0_2().unknown_18_ = -1;
        arg0->unknown_eac_ = 3;
    }
    if (self->state == 3) {
        int i;
        if (self->fadeActive != 0) {
            SePlayer_UnloadExtraArchiveA(&g_sePlayer);
            self->fadeActive = 0;
        }
        self->savedWorkFlags = self->workFlags;
        self->fadeTimer = 0;
        self->savedField = GetField0x0((S0204671c*)GlobalFlags_GetInstance());
        self->cursorLock = 0;
        SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x80000);
        ClearFlags00(res, 0x10);
        func_ov000_0218048c(self->list);
        ResetField0x930And0x934_ov000_02180b3c(self->list);
        self->ready = 0;
        self->readyPrev = 0;
        self->phase = 0;
        self->objId = self->objId771e = self->objId7720 = -1;
        self->objId7722 = self->objId7724 = -1;
        {
            int var57;
            for (var57 = 0; var57 < 4; var57++) {
                arg0->unknown_7716_[var57] = -1;
            }
        }
        var49 = 1;
        arg0->unknown_772f_ = 1;
        arg0->unknown_40b0_ = var19->unknown_8e20_;
        arg0->unknown_40b4_ = var19->unknown_8e49_;
        if (arg0->unknown_e38_ == 2) {
            var49 = 0;
        }
        ClearFlags00(var18, 0x800);
        if (func_ov000_0216f208(arg0->unknown_c18_)->unknown_c_ <= 0) {
            arg0->unknown_e39_ = 1;
            ClearFlags04(var18, 0x400);
            func_ov000_0216118c(arg0, 1);
        }
        func_ov000_02163710(arg0, 1);
        func_ov000_02167e6c((unsigned char*)arg0);
        {
            Struct_020d6ec8* var58 = func_ov000_02163524(arg0);
            func_020d6f44(var58);
            func_020d738c(var58);
        }
        if (var19->unknown_8e20_ > 0) {
            func_ov000_02162cbc(arg0);
        }
        func_ov000_021626a0(arg0, 0x26, 0);
        func_ov000_021626a0(arg0, 0x27, 1);
        func_ov000_02163a7c((Struct_ov000_02163a7c*)arg0);
        func_ov000_021629ec(arg0);
        {
            int var59;
            int var60, var61;
            int var62;
            unsigned char* var63;
            unsigned char* var64;
            short* var65;
            unsigned char** var66;

            var35 = GameState::GetInstance();
            var34 = 0;
            var34 = var34 + func_ov000_0215e9fc(var19, var16, 12, var34);
            var34 = var34 + func_ov000_0215ec1c(var19, &var16[var34], 12 - var34, 0);
            var33 = 0;
            var32 = 0;
            var31 = var33;
            var30 = var33;
            var29 = var33;
            var66 = var15;
            var64 = var14[0];
            var65 = var16;
            for (; var29 < var34; var64 += 2, var66++, var65++, var29++) {
                *var66 = (unsigned char*)var35->GetCombatantByIndex(*var65);
                if (*var66 != 0) {
                    int var67 = func_020493a4(*var66);
                    var64[0] = var67 % 9;
                    var64[1] = var67 / 9;
                    if (var64[0] < 3) var30 = 1;
                    if (var64[0] > 5) var31 = 1;
                    if (var64[1] < 3) var33 = 1;
                    if (var64[1] > 5) var32 = 1;
                }
            }
            var61 = 0;
            var60 = var61;
            if (var31 != 0 && var30 == 0) var61 = -1;
            if (var31 == 0 && var30 != 0) var61 = 1;
            if (var33 == 0 && var32 != 0) var60 = -2;
            if (var33 != 0 && var32 == 0) var60 = 2;
            if (var61 != 0 || var60 != 0) {
                var63 = var13;
                var64 = var14[0];
                for (var59 = 0; var59 < var34; var64 += 2, var63++, var59++) {
                    *var63 = (var64[0] + var61) + (var64[1] + var60) * 9;
                    if (*var63 >= 81) goto shifted;
                }
                var63 = var13;
                var66 = var15;
                for (var62 = 0; var62 < var34; var66++, var63++, var62++) {
                    if (*var66 != 0) {
                        int var68;
                        func_02049390(*var66, *var63);
                        var68 = *var63;
                        const Struct_ov026_021d8ba0_2& var69 = func_ov000_0216f74c(&var68);
                        Struct_ov026_021d8ba0_2 var70 = var69;
                        var12 = data_ov026_021de6dc;
                        var12.unknown_0_[0] = var70.unknown_0_;
                        var12.unknown_0_[2] = var70.unknown_4_;
                        func_02049bd4(*var66, var12.unknown_0_);
                    }
                }
            }
        }
    shifted:
        MessageSystem_Reset((char*)ctrl);
        MessageSystem_Stop(ctrl);
        func_ov026_021daec8(self->battle, self->view, autoMode);
        {
            BattleState* b2 = self->battle;
            Group* groups;
            int j;
            int count;
            gs3 = GameState::GetInstance();
            ownerNames = self->ownerNames;
            memberNames = self->memberNames;
            groups = b2->groups;
            ctrl2 = MessageSystem_GetInstance();
            count = 0;
            func_ov000_02174614(self->list, -1);
            ReleaseEntriesTwoGroups02174dc0(self->list);
            ownerCount = 0;
            for (g = 0; g < groups->numGroups; g++) {
                first = 0;
                for (j = 0; j < groups[g].count; j++) {
                    c = GetCombatantWithFlag0x400_0200fea4(gs3, groups[g].ids[j] + 0xc0);
                    if (c == 0 || IsFlag10088Set_02010088((S_10088*)c) || IsFlagBit8192Set_021dd3c4((FlagObj_021dd3c4*)c)) {
                        continue;
                    }
                    var48 = *(Struct_ov026_021d8ba0_7**)((char*)var36 + 0x144);
                    if (var48 == 0) {
                        continue;
                    }
                    {
                        fmt = data_ov026_021de6f8;
                        func_020e4864((char*)c + 0x14c, fmt.s + 5, 1, 0, 0, 0);
                        __clear(text, sizeof(text));
                        MessageSystem_FormatText(ctrl2, 0xa, fmt.s, text, 0x100, 0, 0);
                        SwapGlobalEntry0203c108((Obj0203c108*)(memberNames + count * 0x18), text);
                    }
                    self->memberRanks[count] = *((unsigned char*)c + 0x17c);
                    self->memberIds[count] = groups[g].ids[j] + 0xc0;
                    if (first == 0) {
                        first = 1;
                        fmt2 = data_ov026_021de778;
                        func_020e4864(owner->name, fmt2.s + 5, 1, 0, 0, 0);
                        __clear(text2, sizeof(text2));
                        MessageSystem_FormatText(ctrl2, 0xa, fmt2.s, text2, 0x100, 0, 0);
                        SwapGlobalEntry0203c108((Obj0203c108*)(ownerNames + ownerCount * 0x18), text2);
                        ownerCount++;
                    }
                    var74++;
                }
            }
            func_ov000_021744f4((int)arg0->unknown_3760_, (void*)var74);
            var72 = var19->unknown_81b0_;
            arg0->unknown_54bc_ = var72->unknown_1_0_;
        }
        arg0->unknown_5950_ = 0;
        ((Object3D*)(arg0->unknown_5954_))->MakeHidden();
        ((Object3D*)(arg0->unknown_5a00_))->MakeHidden();
        func_ov000_02160fbc(arg0, 0x20000);
        for (var56 = 0; var56 < 4; var56++) {
            Struct_ov026_021d8ba0_6* var75 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, var56);
            if (var75 != 0) {
                func_ov000_0217f518(var75);
            }
        }
        func_ov000_02162c14(self, GameState_GetProtagonistIndex(gs), &self->cmd);
        func_ov000_0217fa60(self->list);
        ClearFlag0x43e02176054(self->list);
        func_ov000_02175258(self->list);
        func_ov000_02174c14(self->list);
        func_ov000_021814bc(self->list);
        self->uiFlags &= ~0x600;
        if (ClassifyField0x81fe_ov000_0215fc60((char*)battle) != 0) {
            self->versusFlag = 1;
        }
        {
            Struct_ov000_0217e870_2* var76;
            int var77;
            var44 = arg0->unknown_29c_;
            var76 = arg0->unknown_2a0_;
            for (var77 = 0; var77 < 4; var77++) {
                if (func_020a35e0((unsigned char*)var76, var77)) {
                    func_ov026_021dc8fc(arg0, var44, var76, arg0->unknown_3760_, arg0->unknown_e98_, arg0->unknown_ea0_, var77);
                }
            }
        }
        for (var56 = 0; var56 < 4; var56++) {
            void* var78;
            if (!func_020a35e0((unsigned char*)arg0->unknown_2a0_, var56)) continue;
            var27 = func_0200ff1c(var17, var56);
            if (var27 == 0) continue;
            var78 = func_02053dc0((Struct_02053dc0*)var27);
            if (var78 != 0) {
                memset(var78, 0, 6);
            }
            arg0->unknown_54f0_ = arg0->unknown_38dc_;
            if (func_02010088((Struct_02010088*)var27)) continue;
            func_02033b88((Struct_02010604*)var27, 0);
        }
        if (var19->unknown_8e20_ == 0 && arg0->unknown_29c_->unknown_8e49_ == 2) {
            func_ov000_02181364(arg0->unknown_3760_);
            func_ov000_0217fcc4(arg0->unknown_3760_, -1);
            arg0->unknown_772f_ = 0;
        }
        if (func_ov000_0215fc60((char*)var19) != 0) {
            if (func_0202c540(var22) != 0) {
                func_ov000_02181364(arg0->unknown_3760_);
                func_ov000_0217fcc4(arg0->unknown_3760_, -1);
                func_ov000_021816e8(arg0->unknown_3760_, -1);
                func_ov000_02181694(arg0->unknown_3760_, 0);
                arg0->unknown_772f_ = 0;
            } else {
                for (var56 = 1; var56 < 4; var56++) {
                    Struct_ov026_021d8ba0_6* var79 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, var56);
                    if (var79 != 0) {
                        func_ov000_0217f5d0(var79);
                        var79->unknown_10_[var79->unknown_18_] = 100;
                    }
                }
            }
        }
        if (func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
            func_ov000_02160fa8(arg0, 0x40000000);
        }
        if (((SafeAllocator*)self->cmdAlloc)->GetSignedAllocator() == 0) {
            ((SafeAllocator*)self->cmdAlloc)->CreateTypeA(((SafeAllocator*)(self->alloc))->Allocate(0x16000), 0x16000);
            VramState_CopyCurrentTo((State0207dfc8*)(self->stateA), (State0207dfc8*)(self->stateB));
        }
        arg0->unknown_eac_ = 0xe;
        {
            Roster* roster = (Roster*)GameState_GetParty(gs);
            unsigned char m;
            for (m = 0; m < roster->count; m++) {
                if (self->slotsDirty != 0) {
                    SlotWork* s = FindSlotById_021dae60((Container_021dae60*)self->list, m);
                    if (s != 0) {
                        func_ov000_0217f518(s);
                    }
                }
                func_ov000_02162c14(arg0, var80->unknown_f78_[var81], &var5);
                func_ov017_021c6814(arg0->unknown_2a0_->unknown_8_, var80->unknown_f78_[var81], &var5, 0, -1, 0);
            }
        }
    }
    if (arg0->unknown_eac_ == 0xe) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 1) != 0) {
            return;
        }
        if (func_ov000_02160fd4(arg0, 0x40000000) != 0) {
            if (arg0->unknown_774a_ != 0) {
                int var83;
                for (var83 = 0; var83 < 4; var83++) {
                    Struct_ov026_021d8ba0_6* var84 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, var83);
                    if (var84 != 0) {
                        func_ov000_0217f518(var84);
                    }
                }
                arg0->unknown_774a_ = 0;
            }
            func_ov017_021ca174(arg0->unknown_2a0_->unknown_8_);
            arg0->unknown_eac_ = 0x11;
            func_ov017_021c847c();
        }
    }
    if (self->state == 0x11) {
        int online;
        TagValueEntry020e385c* tags;
        online = battle->netInfo->state >= 0 ? 1 : 0;
        ctrl->flag19af = 0;
        ctrl->flag19ca = 0;
        tags = GetData02153660_020e3808();
        if (!online || (IsEntryCompleteOrMissing020e3ad0(tags, 1, -1) && online)) {
            unsigned char* entry = FindEntryByTagAndValue(tags, 1, -1);
            int mine = 0;
            int all;
            if (entry != 0 && (entry[5] & (1 << GameState_GetProtagonistIndex(gs)))) {
                mine = 1;
            }
            var89 = 0;
            if (var87 != 0 && (var87[5] & arg0->unknown_2a0_->unknown_34_) == var87[5]) {
                var89 = 1;
            }
            if (all || !mine || !entry) {
                MessageSystem_Reset((char*)ctrl);
                self->state = 4;
                ResetTaggedEntryAndNotifyOverlay020e3994(tags, 1, -1);
                return;
            }
        }
        if (((POWCNT & 0x8000) >> 15) == 1 && (IsBrightnessOutsideValidRange((GameResources*)res, false) || IsBrightnessOutsideValidRange((GameResources*)res, true)) && self->phase == 0) {
            SetBrightness(res, 0, 0xf);
            if (ctrl->busy == 0) {
                void* work = MessageSystem_GetInstance()->scriptWork;
                memset(work, 0, 0x960);
                func_020dd0b0(0, work);
                func_0204500c(ctrl, work, 0, 0xe3);
                ctrl->busy = 1;
            }
        }
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 1) != 0) {
            return;
        }
        if (func_ov026_021d8a40() && func_02046b08(var47) && func_020a35e0((unsigned char*)arg0->unknown_2a0_, arg0->unknown_2a0_->unknown_2a_)) {
            func_ov026_021dce34(-1, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, arg0->unknown_ec8_, arg0->unknown_5c3c_, arg0->unknown_5728_, arg0->unknown_e98_, arg0->unknown_ea0_, arg0->unknown_5910_, arg0->unknown_c18_);
        }
    }
    if (arg0->unknown_eac_ == 4) {
        int var91;
        int var92;
        if (((POWCNT & 0x8000) >> 15) == 1 && (IsBrightnessOutsideValidRange((GameResources*)var18, false) || IsBrightnessOutsideValidRange((GameResources*)var18, true)) && arg0->unknown_7712_ == 0) {
            SetBrightness(var18, 0, 0xf);
            func_ov026_021dd8a8(var19, arg0->unknown_2a0_);
            arg0->unknown_eb5_ = 0;
        } else if (arg0->unknown_eb5_ != 0) {
            func_ov026_021dd8a8(var19, arg0->unknown_2a0_);
            arg0->unknown_eb5_ = 0;
        }
        if (arg0->unknown_772f_ & (var21->unknown_998_ == 0)) {
            func_ov000_0217fbf4(arg0->unknown_3760_, -1);
            arg0->unknown_772f_ = 0;
        }
        func_ov000_02174514(arg0->unknown_3760_);
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 1) != 0) {
            return;
        }
        {
            GameState* var93;
            int var94;
            int var95;
            short var96[8];
            var28 = -1;
            memset(var96, var28, sizeof(var96));
            var95 = func_ov000_0215eb1c(var19, var96, 8, 0);
            var93 = GameState::GetInstance();
            for (var94 = 0; var94 < var95; var94++) {
                GameObject* var97 = func_0200fea4(var93, var96[var94]);
                if (var97 != 0) {
                    ModifiableCombatStats* var98 = var97->currentStats_;
                    if ((*(int*)&var98->unk1[4] & 0x1000) && func_0200ff1c(var93, *(short*)&var98->unk1[0x1a]) == 0) {
                        var28 = var96[var94];
                        func_02088e64((unsigned char*)var97->currentStats_);
                        var91 = 1;
                        goto checked;
                    }
                }
            }
            var91 = 0;
        }
    checked:
        if (revived) {
            MessageWork* msg = MessageSystem_GetInstance();
            Container020e0310* box = self->GetMsgBox();
            GameObject* c = GetCombatantWithFlag0x400_0200fea4(gs, target);
            void* text = KeyTable_Get(box, 0x28);
            if (text != 0 && c != 0) {
                func_02046380(msg);
                MessageSystem_SetStringArgument((Obj02046574*)msg, 0, (char*)c + 0x14c);
                func_020e4ce8(name, (char*)c, 1);
                msg->namePtr = name;
                func_0204500c(msg, text, 0, 0xe3);
                msg->busy = 1;
                self->state = 0xf;
                return;
            }
        }
        if (func_ov026_021d8a40() && func_02046b08(var47) && func_020a35e0((unsigned char*)arg0->unknown_2a0_, arg0->unknown_2a0_->unknown_2a_)) {
            func_ov026_021dce34(-1, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, arg0->unknown_ec8_, arg0->unknown_5c3c_, arg0->unknown_5728_, arg0->unknown_e98_, arg0->unknown_ea0_, arg0->unknown_5910_, arg0->unknown_c18_);
        }
        if (var19->unknown_8e47_ == 0) {
            if (func_02046708((Struct_02012de8*)var25, 0x200) == 0) {
                int var103 = var19->unknown_8e20_;
                int var104 = var19->unknown_8e49_;
                int var105 = 1;
                if (var103 == 0 && var104 == 2) {
                    var105 = 0;
                }
                if (set) {
                    FlagWord_SetBits((unsigned int*)flagWord, 0x200);
                }
            }
            if (func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_) && func_020e37e8(var26)) {
                func_020e3798(var26);
            }
        }
        func_ov000_0216258c(arg0);
        {
            int me = (signed char)GameState_GetProtagonistIndex(gs);
            int redo = 0;
            int changed = redo;
            int locked = redo;
            if (CheckField0NonZero_0202b7d8(link) && battle->turns == 0 && self->battle->kind == 2) {
                if (ctrl->busy != 0) {
                    locked = 1;
                }
            }
            if (var109 == 0) {
                if (arg0->unknown_54f4_[var106] != (func_ov000_0217fb98(arg0->unknown_3760_) == 0)) {
                    var108 = 1;
                }
                func_ov000_02162c90((char*)arg0, var106, func_ov000_0217fb98(arg0->unknown_3760_) == 0);
            }
            func_ov026_021db3d8(arg0);
            if (func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
                var45 = arg0->unknown_2a0_;
                var107 = 1;
                var46 = func_0202ae18();
                if (func_0202b7d8(var46)) {
                    for (var92 = 0; var92 < 4; var92++) {
                        if (func_020a35e0((unsigned char*)var45, var92) && func_0202c1c0((Struct_0202b2f0*)var46, var92)) {
                            var107 = (var107 & arg0->unknown_54f4_[var92]) ? 1 : 0;
                        }
                    }
                } else if (arg0->unknown_54f4_[0] == 0) {
                    var107 = 0;
                }
            } else if (arg0->unknown_5950_ != 0) {
                var107 = 1;
            }
            if (var107) {
                func_ov000_0217fcc4(arg0->unknown_3760_, -1);
            }
            if (func_ov000_02168720((char*)arg0) > 0 || var21->unknown_998_ != 0) {
                var107 = 0;
            }
            if (var107 && func_0202b7d8(var22) && func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
                if (func_ov026_021d8a40() == 0) {
                    var107 = 0;
                }
            }
            if (func_0202b7d8(var22)) {
                int var110 = arg0->unknown_54f0_;
                int var111 = 0;
                int var112;
                if (var110 >= 0) {
                    var111 = var110 <= 3;
                }
                if (valid) {
                    int differs;
                    func_ov000_02162c14(self, cur, &cmdB);
                    differs = !(cmdB.b[0] == self->cmd.b[0] && cmdB.b[1] == self->cmd.b[1] && cmdB.b[2] == self->cmd.b[2] &&
                                cmdB.b[3] == self->cmd.b[3] && cmdB.d == self->cmd.d && cmdB.e == self->cmd.e && cmdB.c == self->cmd.c);
                    if (differs || changed) {
                        func_ov017_021c6814(self->party->netId, self->curSlot, &cmdB, self->slotDone[me], -1, 0);
                        self->cmd.b[0] = cmdB.b[0];
                        self->cmd.b[1] = cmdB.b[1];
                        self->cmd.b[2] = cmdB.b[2];
                        self->cmd.b[3] = cmdB.b[3];
                        self->cmd.c = cmdB.c;
                        self->cmd.d = cmdB.d;
                        self->cmd.e = cmdB.e;
                        if (func_0202c508(link) != 0 && ((cmdB.b[0] == 100 && cmdB.b[1] == 6) || cmdB.b[0] == 0xd)) {
                            Roster* roster = (Roster*)GameState_GetParty(gs);
                            int m;
                            for (m = 0; m < roster->count; m++) {
                                if (self->curSlot == m) continue;
                                func_ov000_02162c14(self, roster->ids[m], &cmdC);
                                func_ov017_021c6814(self->party->netId, roster->ids[m], &cmdC, self->slotDone[me], -1, 0);
                            }
                        }
                    }
                }
                var112 = arg0->unknown_38dc_;
                if (arg0->unknown_54f0_ != var112) {
                    arg0->unknown_54f0_ = var112;
                    if (inline_ov017_021c9d2c(var112)) {
                        func_ov000_02162c14(arg0, var112, &var8);
                        func_ov017_021c6814(arg0->unknown_2a0_->unknown_8_, var112, &var8, arg0->unknown_54f4_[var106], -1, 0);
                    }
                }
            }
            if (var107 && (arg0->unknown_54d2_ & 0x200)) {
                if (arg0->unknown_54c0_[arg0->unknown_54c8_] == 100) {
                    func_ov000_02175be4(arg0->unknown_3760_);
                    arg0->unknown_54d2_ &= ~0x200;
                    arg0->unknown_54d2_ |= 0x400;
                    arg0->unknown_eb4_ = 0;
                }
                arg0->unknown_774a_ = 1;
                var107 = 0;
            }
            func_ov026_021db5a4(arg0);
            if ((arg0->unknown_54d2_ & 0x200) || arg0->unknown_7712_ > 0) {
                var107 = 0;
            }
            if (arg0->unknown_7749_ != 0 && arg0->unknown_7712_ == 0) {
                func_ov026_021dbba8(arg0);
                func_ov000_0216118c(arg0, 0);
            }
            self->ready = redo ? 1 : 0;
            if (redo) {
                ClearSlotBitndSetByte_021813d4(self->list);
                func_ov000_0217fcc4(self->list, -1);
                func_ov000_0217457c(self->list, -1);
                if (self->phase == -1) {
                    self->fadeTimer = 60;
                    SePlayer_UnloadExtraArchiveA(&g_sePlayer);
                    self->fadeActive = 0;
                    SePlayer_LoadExtraArchiveA(&g_sePlayer, 0x1b3, 0x1b3);
                    DispatchIfField0xc4NonNeg_0205eb90(&g_sePlayer, 0, 0);
                    self->fadeActive = 1;
                }
                {
                    Object3D* o;
                    int i;
                    for (i = 0; i < 4; i++) {
                        o = (Object3D*)gs->GetGameObjectByIndex(self->objIds[i]);
                        if (o != 0) {
                            o->StopCurrentAnimation();
                            o->SetAnimationByName(data_ov026_021dedec, 1);
                        }
                    }
                }
                func_ov000_02160fbc(arg0, 0x40000000);
                if (!func_0202b7d8(var22)) {
                    Random* var118;
                    arg0->unknown_5950_ = func_ov026_021dd3dc(arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_);
                    var118 = &arg0->unknown_29c_->unknown_0_;
                    arg0->unknown_6e3c_ = GetRandomStateHi(var118);
                    arg0->unknown_6e40_ = GetRandomStateLo(var118);
                    arg0->unknown_eac_ = 5;
                } else {
                    int var119;
                    int var120;
                    if (arg0->unknown_7749_ == 0) {
                        func_ov000_02167e6c((unsigned char*)arg0);
                    }
                    func_ov026_021daec8(var19, func_ov000_02160f14(arg0), 0);
                    if (func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
                        arg0->unknown_5950_ = func_ov026_021dd3dc(arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_);
                        func_ov017_021cefe0(arg0->unknown_2a0_->unknown_8_, arg0->unknown_5950_, arg0->unknown_7748_);
                        func_ov000_02160fa8(arg0, 0x800000);
                    }
                    if (func_02046708((Struct_02012de8*)var25, 0x200)) {
                        func_020e36f0(var26);
                    }
                    arg0->unknown_eac_ = 0x12;
                    func_ov017_021c894c(arg0->unknown_2a0_->unknown_8_);
                    func_ov017_021c8758(arg0->unknown_2a0_->unknown_8_);
                    func_ov017_021c8654();
                    func_ov017_021c847c();
                    var119 = 1;
                    for (var120 = 0; var120 < 4; var120++) {
                        GameObject* var121;
                        if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var120) && (var121 = var17->GetCombatantByIndex(var120)) != 0) {
                            if (func_02010088((Struct_02010088*)var121) == 0) {
                                var119 = 0;
                            }
                        }
                    }
                    if (var119) {
                        var19->unknown_8e14_ = 2;
                        func_ov000_02160d80(arg0, 0xa);
                    }
                }
            }
        }
    } else if (arg0->unknown_eac_ == 0x12) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 0) != 0) {
            return;
        }
        if (GetByte2IfGlobalFlagSet_020e37e8(notify) != 0 || TestFlags02046708((FlagWord02046708*)flagWord, 0x200) == 0) {
            FlagWord_ClearBits((FlagWord020466f4*)flagWord, 0x200);
            if (MatchesActiveIndex020a36a8((Combatant020A36A8*)self->party)) {
                self->state = 8;
            } else {
                arg0->unknown_eac_ = 0xa;
            }
        }
    } else if (arg0->unknown_eac_ == 8) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_0205e488(var24)) {
            int var122;
            for (var122 = 0; var122 < 4; var122++) {
                if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var122)) {
                    func_0200ff58(var17, var122);
                    func_ov000_02162c14(arg0, var122, &var9);
                    func_ov017_021c6814(arg0->unknown_2a0_->unknown_8_, var122, &var9, 1, -1, 1);
                }
            }
            arg0->unknown_eac_ = 9;
        }
    } else if (arg0->unknown_eac_ == 9) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_0205e488(var24)) {
            Random* var123 = &arg0->unknown_29c_->unknown_0_;
            arg0->unknown_6e3c_ = GetRandomStateHi(var123);
            arg0->unknown_6e40_ = GetRandomStateLo(var123);
            func_ov017_021cf650(arg0->unknown_2a0_->unknown_8_, arg0->unknown_6e3c_, arg0->unknown_6e40_);
            arg0->unknown_eac_ = 0xb;
        }
    } else if (arg0->unknown_eac_ >= 0xb && arg0->unknown_eac_ <= 0xd) {
        if (arg0->unknown_eac_ == 0xd) {
            arg0->unknown_eac_ = 5;
        } else {
            arg0->unknown_eac_ = arg0->unknown_eac_ + 1;
        }
    } else if (arg0->unknown_eac_ == 0xa) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_ov000_02160fd4(arg0, 0x20000)) {
            arg0->unknown_eac_ = 5;
        }
    } else if (arg0->unknown_eac_ == 5) {
        int var124;
        if (func_0202b7d8(var22) && var22[0xfc0 / 4] != 0) {
            return;
        }
        if (arg0->unknown_7711_ != 0 && arg0->unknown_7710_ != 0) {
            return;
        }
        if (arg0->unknown_7748_ != 0) {
            int var125 = func_ov000_0215ec1c(var19, var10, 8, 0);
            int var126;
            for (var126 = 0; var126 < var125; var126++) {
                GameObject* var127 = func_0200fea4(var17, var10[var126]);
                if (var127 != 0) {
                    ModifiableCombatStats* var128 = var127->currentStats_;
                    var128->primaryStats.currHP = var128->primaryStats.maxHP;
                }
            }
            arg0->unknown_7748_ = 0;
        }
        if (arg0->unknown_7712_ == -1) {
            for (var124 = 0; var124 < 4; var124++) {
                if (var17->GetGameObjectByIndex(arg0->unknown_7716_[var124]) != 0) {
                    return;
                }
            }
            func_ov026_021dbba8(arg0);
        }
        ((SafeAllocator*)arg0->unknown_774c_)->Destroy();
        arg0->unknown_7749_ = 0;
        func_02057f00(func_02057924(), 0x13);
        if (IsField0Null_02046b08((void**)res->unknown_ptr_array_3700[0]) == 0) {
            return;
        }
        SetFlags00(var18, 0x10);
        memset(arg0->unknown_54f4_, 0, 0x10);
        arg0->unknown_2a0_->unknown_30_ = 0;
        func_ov000_02160fbc(arg0, 0x4000000);
        func_ov000_02160fbc(arg0, 0x8000000);
        func_ov000_02160fbc(arg0, 0x10000000);
        func_ov000_02160fbc(arg0, 0x20000000);
        {
            Object3D* var129;
            int var130;
            for (var130 = 0; var130 < 4; var130++) {
                if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var130)) {
                    func_ov000_02162c14(arg0, var130, &var11);
                    var129 = (Object3D*)var17->GetGameObjectByIndex(var130);
                    if (var129 != 0) {
                        var129->DisableFlag(0x1000);
                    }
                }
            }
        }
        {
            Struct_ov000_0217e870_2* var131 = arg0->unknown_2a0_;
            int var132;
            Struct_ov026_021d8ba0_5* var133;
            var17 = GameState::GetInstance();
            for (var124 = 0; var124 < 4; var124++) {
                GameObject* var134;
                if (func_020a35e0((unsigned char*)var131, var124) && (var134 = func_0200ff1c(var17, var124)) != 0) {
                    func_02053dd0((Struct_02053dd0*)var134);
                }
            }
            roster = (Roster*)GameState_GetParty(gs);
            if (roster != 0) {
                for (r = 0; r < roster->count; r++) {
                    GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, roster->ids[r]);
                    if (c != 0 && IsFlag10088Set_02010088((S_10088*)c) == 0) {
                        self->reviveCount++;
                        break;
                    }
                }
            }
        }
        func_ov000_02168144(arg0);
        func_0209a338((Struct_0200f3a4_8*)(arg0->unknown_e98_));
        ((SafeAllocator*)(arg0->unknown_30_))->Reset();
        arg0->unknown_55d8_ = 0;
        func_ov000_0215d588(var19);
        if (func_0202b7d8(var22) && func_020e37e8(var26)) {
            func_020e3798(var26);
        }
        if (arg0->unknown_5950_ == 1) {
            func_ov000_02160da0(arg0);
        } else {
            func_ov000_02160d80(arg0, 0xb);
        }
    } else if (arg0->unknown_eac_ == 6) {
        if (var23->GetNumQueuedTasks() > 0) {
            return;
        }
        func_ov000_021637c8(arg0);
        func_ov026_021dc440((SafeAllocator*)(arg0->unknown_30_), arg0, arg0->unknown_29c_, arg0->unknown_2a0_, 0);
        func_ov026_021dc040((SafeAllocator*)(arg0->unknown_30_), arg0, arg0->unknown_29c_, arg0->unknown_2a0_);
        func_ov000_02163894(arg0);
        arg0->unknown_eac_ = 7;
    } else if (arg0->unknown_eac_ == 7) {
        func_ov000_02163928(arg0);
        if (func_ov026_021dc040((SafeAllocator*)(arg0->unknown_30_), arg0, arg0->unknown_29c_, arg0->unknown_2a0_) != 0) {
            arg0->unknown_eac_ = 0;
        }
    }
    if (self->state == 0xf && MessageSystem_GetInstance()->busy == 0) {
        self->state = 4;
    }
}
