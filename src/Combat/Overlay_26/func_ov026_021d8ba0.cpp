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

struct Container_021dae60;
struct Struct_ov000_02160da0;
struct Struct_ov000_02161e30;
struct PartyState;
struct Roster;
struct MessageWork;
struct Struct_ov026_021d8ba0_6;
struct Struct_ov026_021d8ba0_7;
struct Struct_ov026_021d8ba0_8;
struct Struct_ov026_021d8ba0_9;
struct Combatant020A36A8;
struct Pair0209a338;
struct Struct_0209a470;
struct Ctx0209a8b4;
struct StreamHeader;
struct S0204671c;
struct Struct_020d6ec8;
struct Struct_ov000_02163a7c;
struct S_10088;
struct Struct_ov026_021d8ba0_10;
struct Obj0203c108;
struct Struct_02053dc0;
struct Bytes02033b88;
struct State0207dfc8;
struct TagValueEntry020e385c;
struct Obj02046574;
struct FlagWord02046708;
struct FlagWord020466f4;
struct SearchStruct;
struct Struct_02053dd0;

struct Struct_ov026_021d8ba0 {
    unsigned char b[4];
    signed char c;
    unsigned short d;
    unsigned short e;
};

struct Struct_ov026_021de6dc { int v[3]; };
struct Struct_ov026_021d8ba0_2 { int x, z; };
struct Struct_020e6e88 { char s[0x80]; };
struct Struct_ov026_021d8ba0_3 {
    char names[8][3];
    int loadTask;
    const char* order[8];
};

inline Struct_ov026_021d8ba0_3& inline_ov026_021d8ba0_2() {
    static Struct_ov026_021d8ba0_3 s = {
        {"f4", "f3", "f1", "f2", "b4", "b1", "b2", "b3"},
        -1,
        {s.names[2], s.names[3], s.names[1], s.names[0], s.names[5], s.names[6], s.names[7], s.names[4]},
    };
    return s;
}

struct Struct_ov000_0215440c_6 {
    unsigned char unk0;
    unsigned char kind : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unk2[4];
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char unknown_e_4_ : 4;
    unsigned char unkF[9];
};

extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" Struct_ov026_021d8ba0_6* func_ov026_021dae60(Container_021dae60*, int);
extern "C" MessageWork* MessageSystem_GetInstance();
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void* GlobalFlags_GetInstance();
extern "C" unsigned char* func_020e3580();
extern "C" int func_ov000_0215fc60(char*);
extern "C" void func_ov000_02160d80(void*, int);
extern "C" void func_ov000_02160fa8(void*, int);
extern "C" void func_ov000_02160fbc(void*, int);
extern "C" int func_ov000_02160fd4(void*, int);
extern "C" void func_ov000_0218173c(void*);
extern "C" int func_02012060(void*);
extern "C" int LinkSession_IsActive(int*);
extern "C" int func_020a36a8(Combatant020A36A8*);
extern "C" void func_ov000_0215e8e8(void*);
extern "C" void func_0209a338(Pair0209a338*);
extern "C" void func_0209a470(Struct_0209a470*, SafeAllocator*, StreamHeader*, int);
extern "C" void func_0209a804(int*);
extern "C" void func_0209a8b4(Ctx0209a8b4*, SafeAllocator*, StreamHeader*, int);
extern "C" void SePlayer_UnloadExtraArchiveA(void*);
extern "C" int func_0204671c(S0204671c*);
extern "C" void func_ov000_02180b3c(void*);
extern "C" Struct_ov026_021d8ba0_8* func_ov000_0216f208(void*);
extern "C" void func_ov000_0216118c(void*, int);
extern "C" void func_ov000_02163710(void*, int);
extern "C" void func_ov000_02167e6c(unsigned char*);
extern "C" Struct_020d6ec8* func_ov000_02163524(void*);
extern "C" void func_020d6f44(Struct_020d6ec8*);
extern "C" void func_020d738c(void*);
extern "C" void func_ov000_02163a7c(Struct_ov000_02163a7c*);
extern "C" int func_020493a4(unsigned char*);
extern "C" void func_02049390(unsigned char*, unsigned char);
extern "C" void func_02049bd4(unsigned char*, int*);
extern "C" void MessageSystem_Reset(char*);
extern "C" void func_ov000_02174dc0(void*);
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" char* func_0200ff58(GameState*, int);
extern "C" int func_02010088(S_10088*);
extern "C" int func_ov026_021dd3c4(Struct_ov026_021d8ba0_10*);
extern "C" void CachedTextLabel_SetText(Obj0203c108*, char*);
extern "C" void func_ov000_021744f4(int, void*);
extern "C" void func_ov000_02176054(void*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void* func_02053dc0(Struct_02053dc0*);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_ov000_02181364(void*);
extern "C" void func_ov000_021816e8(void*, int);
extern "C" void func_ov000_02181694(void*, int);
extern "C" void func_ov000_0217f5d0(void*);
extern "C" void VramState_CopyCurrentTo(State0207dfc8*, State0207dfc8*);
extern "C" void func_ov017_021ca174(unsigned short);
extern "C" TagValueEntry020e385c* func_020e3808();
extern "C" int func_020e3ad0(TagValueEntry020e385c*, int, int);
extern "C" unsigned char* func_020e385c(TagValueEntry020e385c*, int, int);
extern "C" void func_020e3994(TagValueEntry020e385c*, int, int);
void SetBrightness(GameResources*, int, int);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" void func_ov000_02174514(void*);
extern "C" void func_02088e64(unsigned char*);
extern "C" void* KeyTable_Get(Container020e0310*, int);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" int FlagWord_TestBits(FlagWord02046708*, unsigned int);
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" int func_020e37e8(unsigned char*);
extern "C" void func_020e3798(unsigned char*);
extern "C" void func_020e36f0(unsigned char*);
extern "C" int func_ov000_0217fb98(void*);
extern "C" void func_ov000_02162c90(char*, int, int);
extern "C" int LinkSession_IsSlotMember(SearchStruct*, int);
extern "C" int func_ov000_02168720(char*);
extern "C" void func_ov000_021813d4(void*);
extern "C" void SePlayer_LoadExtraArchiveA(void*, int, int);
extern "C" void func_0205eb90(void*, int, int);
extern "C" void func_ov017_021cefe0(unsigned short, unsigned char, unsigned char);
extern "C" void func_ov017_021cf650(unsigned short, int, int);
extern "C" int func_0205e488(void*);
extern "C" void func_02053dd0(Struct_02053dd0*);
extern "C" void func_ov000_021637c8(void*);

extern "C" {
int* LinkSession_GetInstance();
void func_ov026_021d8aac( Struct_ov000_02160da0*, int mode, int kind);
void func_ov000_02181608(void*);
void func_ov000_0218048c(void*);
void func_ov000_02162cbc( Struct_ov000_02160da0*);
void func_ov000_021626a0( Struct_ov000_02160da0*, int, int);
void func_ov000_021629ec( Struct_ov000_02160da0*);
int func_ov000_0215e9fc(Struct_ov000_02161e30*, short*, int, int);
int func_ov000_0215ec1c(Struct_ov000_02161e30*, short*, int, int);
int func_ov000_0215eb1c(Struct_ov000_02161e30*, short*, int, int);
Struct_ov026_021d8ba0_2 func_ov000_0216f74c(int* cell);
void MessageSystem_Stop(MessageWork*);
void func_ov026_021daec8(Struct_ov000_02161e30*, void*, int);
void func_ov000_02174614(void*, int);
void func_020e4864(void*, char*, int, int, int, int);
void __clear(void*, int);
void MessageSystem_FormatText(MessageWork*, int, char*, char*, int, int, int);
void func_ov000_0217f518(Struct_ov026_021d8ba0_6*);
void func_ov000_02162c14( Struct_ov000_02160da0*, int, void*);
void func_ov000_0217fa60(void*);
void func_ov000_02175258(void*);
void func_ov000_02174c14(void*);
void func_ov000_021814bc(void*);
void func_ov026_021dc8fc( Struct_ov000_02160da0*, Struct_ov000_02161e30*, PartyState*, void*, void*, void*, int);
void* memset(void*, int, unsigned int);
void func_ov000_0217fcc4(void*, int);
int LinkSession_IsGuest(int*);
void func_ov017_021c6814(unsigned short, unsigned short, Struct_ov026_021d8ba0*, unsigned char, int, int);
int func_ov026_021ddd84(GameResources*, Struct_ov000_02160da0*, Struct_ov000_02161e30*, PartyState*, void*, void*, int);
void func_ov017_021c847c();
void func_020dd0b0(int, void*);
void func_0204500c(MessageWork*, void*, int, int);
int func_ov026_021d8a40();
void func_ov026_021dce34(int, Struct_ov000_02160da0*, Struct_ov000_02161e30*, PartyState*, void*, void*, void*, void*, void*, void*, void*, void*);
void func_ov026_021dd8a8(Struct_ov000_02161e30*, PartyState*);
void func_ov000_0217fbf4(void*, int);
void func_02046380(MessageWork*);
void func_020e4ce8(void*, char*, int);
void func_ov000_0216258c( Struct_ov000_02160da0*);
void func_ov026_021db3d8( Struct_ov000_02160da0*);
int LinkSession_IsHostOrSolo(int*);
void func_ov000_02175be4(void*);
void func_ov026_021db5a4( Struct_ov000_02160da0*);
void func_ov026_021dbba8( Struct_ov000_02160da0*);
void func_ov000_0217457c(void*, int);
unsigned char func_ov026_021dd3dc(Struct_ov000_02161e30*, PartyState*, void*);
void* func_ov000_02160f14( Struct_ov000_02160da0*);
void func_ov017_021c894c(unsigned short);
void func_ov017_021c8758(unsigned short);
void func_ov017_021c8654();
void* func_02057924();
void func_02057f00(void*, int);
void func_ov000_02168144( Struct_ov000_02160da0*);
void func_ov000_0215d588(Struct_ov000_02161e30*);
void func_ov000_02160da0( Struct_ov000_02160da0*);
void func_ov026_021dc440(SafeAllocator*, Struct_ov000_02160da0*, Struct_ov000_02161e30*, PartyState*, int);
int func_ov026_021dc040(SafeAllocator*, Struct_ov000_02160da0*, Struct_ov000_02161e30*, PartyState*);
void func_ov000_02163894( Struct_ov000_02160da0*);
void func_ov000_02163928( Struct_ov000_02160da0*);
}

extern char data_ov026_021dedbc[];
extern char data_ov026_021dedd4[];
extern char g_sePlayer;
extern Struct_ov026_021de6dc data_ov026_021de6dc;
extern Struct_020e6e88 data_ov026_021de6f8;
extern Struct_020e6e88 data_ov026_021de778;
extern char data_ov026_021dedec[];

#define POWCNT (*(volatile unsigned short*)0x04000304)

static inline int inline_ov017_021c9d2c(int slot) {
    return slot >= 0 && slot <= 3;
}

struct Struct_ov026_021d8ba0_6 {
    char pad0[0x10];
    signed char unknown_10_[8];
    signed char cursor;
};

struct Struct_ov026_021d8ba0_7 {
    char pad0[0x14];
    char* name;
};

struct Struct_ov026_021d8ba0_8 {
    char pad0[0xc];
    int count;
};

struct Struct_ov026_021d8ba0_9 {
    char pad0[0xc];
    int state;
};

struct MessageWork {
    char pad0[0x20];
    char* unknown_20_;
    char pad24[0x38];
    char* scriptWork;
    char pad60[0x938];
    int busy;
    char unknown_99c_[0x1013];
    unsigned char unknown_19af_;
    char unknown_19b0_[0x1a];
    unsigned char unknown_19ca_;
};

struct Roster {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
    char unknown_a_[0x2];
    int field0c;
    char pad10[0x1a];
    unsigned char myIndex;
    char unknown_2b_[0x1];
    int field2c;
    int unknown_30_;
    unsigned char memberMask;
};

struct Struct_ov000_02161e30 {
    Random rng;
    char pad20[0x8190];
    Struct_ov000_0215440c_6 groups[4];
    char unknown_8210_[0xc04];
    unsigned char result;
    char unknown_8e15_[0x3];
    Struct_ov026_021d8ba0_9* unknown_8e18_;
    char unknown_8e1c_[0x4];
    int turns;
    char unknown_8e24_[0x23];
    unsigned char unknown_8e47_;
    char unknown_8e48_[0x1];
    unsigned char kind;
};

struct Struct_ov000_02160da0 {
    char pad0[0x30];
    char alloc[0x11c];
    char stateA[0x150];
    Struct_ov000_02161e30* battle;
    PartyState* party;
    char unknown_2a4_[0x974];
    char view[0x220];
    unsigned char unknown_e38_;
    unsigned char unknown_e39_;
    char unknown_e3a_[0x5e];
    char unknown_e98_[0x8];
    char unknown_ea0_[0x8];
    char unknown_ea8_[0x4];
    int state;
    char unknown_eb0_[0x4];
    unsigned char unknown_eb4_;
    unsigned char unknown_eb5_;
    char unknown_eb6_[0x12];
    char unknown_ec8_[0x2898];
    char list[0xb8];
    Container020e0310 unknown_3818_;
    char unknown_3820_[0xbc];
    int unknown_38dc_;
    char unknown_38e0_[0x7d0];
    int unknown_40b0_;
    unsigned char unknown_40b4_;
    char unknown_40b5_[0x11b7];
    char ownerNames[0x150];
    char memberNames[0xc0];
    int unknown_547c_[8];
    int memberIds[8];
    unsigned char groupKind;
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
    Struct_ov026_021d8ba0 cmd;
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
    signed char phase;
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
    int savedField;
    char unknown_773c_[0xc];
    unsigned char unknown_7748_;
    unsigned char unknown_7749_;
    unsigned char unknown_774a_;
    char unknown_774b_[0x1];
    char unknown_774c_[0x14];
    char stateB[0x150];
    Container020e0310* inline_ov026_021d8ba0() { return &unknown_3818_; }
};

// USA: func_ov026_021d8ba0
extern "C" ARM void func_ov026_021d8ba0(Struct_ov000_02160da0* self) {
    char text2[0x80];
    Struct_020e6e88 fmt2;
    char text[0x80];
    Struct_020e6e88 fmt;
    char name[12];
    Struct_ov026_021d8ba0 var5;
    Struct_ov026_021d8ba0 cmdB;
    Struct_ov026_021d8ba0 var7;
    Struct_ov026_021d8ba0 var8;
    Struct_ov026_021d8ba0 var9;
    short var10[8];
    Struct_ov026_021d8ba0 var11;
    Struct_ov026_021de6dc v;
    unsigned char moved[12];
    unsigned char cells[12][2];
    unsigned char* members[12];
    short ids[12];
    GameState* gs;
    GameResources* res;
    Struct_ov000_02161e30* battle;
    Struct_ov026_021d8ba0_6* slot;
    MessageWork* ctrl;
    int* link;
    BackgroundLoader* loader;
    void* slots;
    void* flagWord;
    unsigned char* notify;
    GameObject* member;
    int target;
    int k;
    unsigned char var30;
    unsigned char var31;
    unsigned char var32;
    unsigned char var33;
    int n;
    GameState* gs2;
    GameObject* c;
    unsigned char first;
    int g;
    int ownerCount;
    MessageWork* ctrl2;
    char* memberNames;
    char* ownerNames;
    GameState* gs3;
    Struct_ov000_02161e30* b3;
    PartyState* party;
    int* lnk;
    void** field3704;
    Struct_ov026_021d8ba0_7* owner;
    unsigned char var49;

    gs = GameState::GetInstance();
    res = GetGameResources();
    link = LinkSession_GetInstance();
    battle = self->battle;
    slot = func_ov026_021dae60((Container_021dae60*)self->list, GameState_GetProtagonistIndex(gs));
    ctrl = MessageSystem_GetInstance();
    loader = BackgroundLoader::GetInstance();
    slots = LinkMessageQueue_GetInstance();
    flagWord = GlobalFlags_GetInstance();
    field3704 = (void**)res->unknown_ptr_array_3700[1];
    notify = func_020e3580();

    if (battle == 0 || slot == 0) {
        return;
    }
    if (func_ov000_0215fc60((char*)battle) != 0 && battle->turns == 2) {
        func_ov000_02160d80(self, 4);
        return;
    }
    {
        int mode = battle->turns;
        func_ov026_021d8aac(self, mode, func_ov000_0215fc60((char*)battle));
    }
    if (res->unknown_42e2_ != 0 && loader->GetNumQueuedTasks() == 0) {
        func_ov000_02160fa8(self, 0x2000000);
        return;
    }

    if (self->state == 0) {
        func_ov000_02181608(self->list);
        func_ov000_0218173c(self->list);
        self->unknown_774a_ = 0;
        if (func_02012060(gs) != 0) {
            PartyState* party = self->party;
            if (party->field0c < 0 && party->field2c == 0) {
                self->state = 6;
                goto state1;
            }
        }
        ((SafeAllocator*)(self->alloc))->Reset();
        inline_ov026_021d8ba0_2().loadTask = loader->QueueLoadFile(data_ov026_021dedbc, 0);
        self->state = 1;
        if (LinkSession_IsActive(link) && func_020a36a8((Combatant020A36A8*)self->party)) {
            func_ov000_0215e8e8(self->battle);
        }
    }
state1:
    if (self->state == 1) {
        void* file;
        unsigned int len;
        if (!loader->GetTaskStatus(inline_ov026_021d8ba0_2().loadTask)) {
            return;
        }
        loader->GetLoadedFileByID(inline_ov026_021d8ba0_2().loadTask, &file, &len);
        func_0209a338((Pair0209a338*)(self->unknown_e98_));
        func_0209a470((Struct_0209a470*)(self->unknown_e98_), (SafeAllocator*)(self->alloc), (StreamHeader*)file, len);
        loader->RemoveTask(inline_ov026_021d8ba0_2().loadTask);
        inline_ov026_021d8ba0_2().loadTask = -1;
        inline_ov026_021d8ba0_2().loadTask = loader->QueueLoadFile(data_ov026_021dedd4, 0);
        self->state = 2;
    }
    if (self->state == 2) {
        void* file;
        unsigned int len;
        if (!loader->GetTaskStatus(inline_ov026_021d8ba0_2().loadTask)) {
            return;
        }
        loader->GetLoadedFileByID(inline_ov026_021d8ba0_2().loadTask, &file, &len);
        func_0209a804((int*)(self->unknown_ea0_));
        func_0209a8b4((Ctx0209a8b4*)(self->unknown_ea0_), (SafeAllocator*)(self->alloc), (StreamHeader*)file, len);
        loader->RemoveTask(inline_ov026_021d8ba0_2().loadTask);
        inline_ov026_021d8ba0_2().loadTask = -1;
        self->state = 3;
    }
    if (self->state == 3) {
        int i;
        if (self->unknown_7711_ != 0) {
            SePlayer_UnloadExtraArchiveA(&g_sePlayer);
            self->unknown_7711_ = 0;
        }
        self->unknown_7734_ = self->unknown_55f4_;
        self->unknown_7710_ = 0;
        self->savedField = func_0204671c((S0204671c*)GlobalFlags_GetInstance());
        self->unknown_eb4_ = 0;
        func_ov000_02160fa8(self, 0x80000);
        ClearFlags00(res, 0x10);
        func_ov000_0218048c(self->list);
        func_ov000_02180b3c(self->list);
        self->unknown_54e0_ = 0;
        self->unknown_54e1_ = 0;
        self->phase = 0;
        self->unknown_7714_ = self->unknown_771e_ = self->unknown_7720_ = -1;
        self->unknown_7722_ = self->unknown_7724_ = -1;
        {
            int j;
            for (j = 0; j < 4; j++) {
                self->unknown_7716_[j] = -1;
            }
        }
        var49 = 1;
        self->unknown_772f_ = 1;
        self->unknown_40b0_ = battle->turns;
        self->unknown_40b4_ = battle->kind;
        if (self->unknown_e38_ == 2) {
            var49 = 0;
        }
        ClearFlags00(res, 0x800);
        if (func_ov000_0216f208(self->view)->count <= 0) {
            self->unknown_e39_ = 1;
            ClearFlags04(res, 0x400);
            func_ov000_0216118c(self, 1);
        }
        func_ov000_02163710(self, 1);
        func_ov000_02167e6c((unsigned char*)self);
        {
            Struct_020d6ec8* var58 = func_ov000_02163524(self);
            func_020d6f44(var58);
            func_020d738c(var58);
        }
        if (battle->turns > 0) {
            func_ov000_02162cbc(self);
        }
        func_ov000_021626a0(self, 0x26, 0);
        func_ov000_021626a0(self, 0x27, 1);
        func_ov000_02163a7c((Struct_ov000_02163a7c*)self);
        func_ov000_021629ec(self);
        {
            int i2;
            int dy, dx;
            int j;
            unsigned char* out;
            unsigned char* cell;
            short* id;
            unsigned char** m;

            gs2 = GameState::GetInstance();
            n = 0;
            n = n + func_ov000_0215e9fc(battle, ids, 12, n);
            n = n + func_ov000_0215ec1c(battle, &ids[n], 12 - n, 0);
            var33 = 0;
            var32 = 0;
            var31 = var33;
            var30 = var33;
            k = var33;
            m = members;
            cell = cells[0];
            id = ids;
            for (; k < n; cell += 2, m++, id++, k++) {
                *m = (unsigned char*)gs2->GetCombatantByIndex(*id);
                if (*m != 0) {
                    int pos = func_020493a4(*m);
                    cell[0] = pos % 9;
                    cell[1] = pos / 9;
                    if (cell[0] < 3) var30 = 1;
                    if (cell[0] > 5) var31 = 1;
                    if (cell[1] < 3) var33 = 1;
                    if (cell[1] > 5) var32 = 1;
                }
            }
            dx = 0;
            dy = dx;
            if (var31 != 0 && var30 == 0) dx = -1;
            if (var31 == 0 && var30 != 0) dx = 1;
            if (var33 == 0 && var32 != 0) dy = -2;
            if (var33 != 0 && var32 == 0) dy = 2;
            if (dx != 0 || dy != 0) {
                out = moved;
                cell = cells[0];
                for (i2 = 0; i2 < n; cell += 2, out++, i2++) {
                    *out = (cell[0] + dx) + (cell[1] + dy) * 9;
                    if (*out >= 81) goto shifted;
                }
                out = moved;
                m = members;
                for (j = 0; j < n; m++, out++, j++) {
                    if (*m != 0) {
                        int var68;
                        func_02049390(*m, *out);
                        var68 = *out;
                        const Struct_ov026_021d8ba0_2& p0 = func_ov000_0216f74c(&var68);
                        Struct_ov026_021d8ba0_2 pos = p0;
                        v = data_ov026_021de6dc;
                        v.v[0] = pos.x;
                        v.v[2] = pos.z;
                        func_02049bd4(*m, v.v);
                    }
                }
            }
        }
    shifted:
        MessageSystem_Reset((char*)ctrl);
        MessageSystem_Stop(ctrl);
        func_ov026_021daec8(self->battle, self->view, var49);
        {
            Struct_ov000_02161e30* b2 = self->battle;
            Struct_ov000_0215440c_6* groups;
            int j;
            int count;
            gs3 = GameState::GetInstance();
            ownerNames = self->ownerNames;
            memberNames = self->memberNames;
            groups = b2->groups;
            ctrl2 = MessageSystem_GetInstance();
            count = 0;
            func_ov000_02174614(self->list, -1);
            func_ov000_02174dc0(self->list);
            ownerCount = 0;
            for (g = 0; g < groups->unknown_1_4_; g++) {
                first = 0;
                for (j = 0; j < groups[g].count; j++) {
                    c = func_0200fea4(gs3, groups[g].ids[j] + 0xc0);
                    if (c == 0 || func_02010088((S_10088*)c) || func_ov026_021dd3c4((Struct_ov026_021d8ba0_10*)c)) {
                        continue;
                    }
                    owner = *(Struct_ov026_021d8ba0_7**)((char*)c + 0x144);
                    if (owner == 0) {
                        continue;
                    }
                    {
                        fmt = data_ov026_021de6f8;
                        func_020e4864((char*)c + 0x14c, fmt.s + 5, 1, 0, 0, 0);
                        __clear(text, sizeof(text));
                        MessageSystem_FormatText(ctrl2, 0xa, fmt.s, text, 0x100, 0, 0);
                        CachedTextLabel_SetText((Obj0203c108*)(memberNames + count * 0x18), text);
                    }
                    self->unknown_547c_[count] = *((unsigned char*)c + 0x17c);
                    self->memberIds[count] = groups[g].ids[j] + 0xc0;
                    if (first == 0) {
                        first = 1;
                        fmt2 = data_ov026_021de778;
                        func_020e4864(owner->name, fmt2.s + 5, 1, 0, 0, 0);
                        __clear(text2, sizeof(text2));
                        MessageSystem_FormatText(ctrl2, 0xa, fmt2.s, text2, 0x100, 0, 0);
                        CachedTextLabel_SetText((Obj0203c108*)(ownerNames + ownerCount * 0x18), text2);
                        ownerCount++;
                    }
                    count++;
                }
            }
            func_ov000_021744f4((int)self->list, (void*)count);
            groups = battle->groups;
            self->groupKind = groups->kind;
        }
        self->unknown_5950_ = 0;
        ((Object3D*)(self->unknown_5954_))->MakeHidden();
        ((Object3D*)(self->unknown_5a00_))->MakeHidden();
        func_ov000_02160fbc(self, 0x20000);
        for (i = 0; i < 4; i++) {
            Struct_ov026_021d8ba0_6* s = func_ov026_021dae60((Container_021dae60*)self->list, i);
            if (s != 0) {
                func_ov000_0217f518(s);
            }
        }
        func_ov000_02162c14(self, GameState_GetProtagonistIndex(gs), &self->cmd);
        func_ov000_0217fa60(self->list);
        func_ov000_02176054(self->list);
        func_ov000_02175258(self->list);
        func_ov000_02174c14(self->list);
        func_ov000_021814bc(self->list);
        self->unknown_54d2_ &= ~0x600;
        if (func_ov000_0215fc60((char*)battle) != 0) {
            self->unknown_54d8_ = 1;
        }
        {
            PartyState* var76;
            int i;
            b3 = self->battle;
            var76 = self->party;
            for (i = 0; i < 4; i++) {
                if (func_020a35e0((unsigned char*)var76, i)) {
                    func_ov026_021dc8fc(self, b3, var76, self->list, self->unknown_e98_, self->unknown_ea0_, i);
                }
            }
        }
        for (i = 0; i < 4; i++) {
            void* p;
            if (!func_020a35e0((unsigned char*)self->party, i)) continue;
            member = func_0200ff1c(gs, i);
            if (member == 0) continue;
            p = func_02053dc0((Struct_02053dc0*)member);
            if (p != 0) {
                memset(p, 0, 6);
            }
            self->unknown_54f0_ = self->unknown_38dc_;
            if (func_02010088((S_10088*)member)) continue;
            GameObject_ForceMotionState((Bytes02033b88*)member, 0);
        }
        if (battle->turns == 0 && self->battle->kind == 2) {
            func_ov000_02181364(self->list);
            func_ov000_0217fcc4(self->list, -1);
            self->unknown_772f_ = 0;
        }
        if (func_ov000_0215fc60((char*)battle) != 0) {
            if (LinkSession_IsGuest(link) != 0) {
                func_ov000_02181364(self->list);
                func_ov000_0217fcc4(self->list, -1);
                func_ov000_021816e8(self->list, -1);
                func_ov000_02181694(self->list, 0);
                self->unknown_772f_ = 0;
            } else {
                for (i = 1; i < 4; i++) {
                    Struct_ov026_021d8ba0_6* s = func_ov026_021dae60((Container_021dae60*)self->list, i);
                    if (s != 0) {
                        func_ov000_0217f5d0(s);
                        s->unknown_10_[s->cursor] = 100;
                    }
                }
            }
        }
        if (func_020a36a8((Combatant020A36A8*)self->party)) {
            func_ov000_02160fa8(self, 0x40000000);
        }
        if (((SafeAllocator*)self->unknown_774c_)->GetSignedAllocator() == 0) {
            ((SafeAllocator*)self->unknown_774c_)->CreateTypeA(((SafeAllocator*)(self->alloc))->Allocate(0x16000), 0x16000);
            VramState_CopyCurrentTo((State0207dfc8*)(self->stateA), (State0207dfc8*)(self->stateB));
        }
        self->state = 0xe;
        {
            Roster* roster = (Roster*)GameState_GetParty(gs);
            unsigned char m;
            for (m = 0; m < roster->count; m++) {
                if (self->unknown_774a_ != 0) {
                    Struct_ov026_021d8ba0_6* s = func_ov026_021dae60((Container_021dae60*)self->list, m);
                    if (s != 0) {
                        func_ov000_0217f518(s);
                    }
                }
                func_ov000_02162c14(self, roster->ids[m], &var5);
                func_ov017_021c6814(self->party->netId, roster->ids[m], &var5, 0, -1, 0);
            }
        }
    }
    if (self->state == 0xe) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->unknown_7748_, 1) != 0) {
            return;
        }
        if (func_ov000_02160fd4(self, 0x40000000) != 0) {
            if (self->unknown_774a_ != 0) {
                int i;
                for (i = 0; i < 4; i++) {
                    Struct_ov026_021d8ba0_6* s = func_ov026_021dae60((Container_021dae60*)self->list, i);
                    if (s != 0) {
                        func_ov000_0217f518(s);
                    }
                }
                self->unknown_774a_ = 0;
            }
            func_ov017_021ca174(self->party->netId);
            self->state = 0x11;
            func_ov017_021c847c();
        }
    }
    if (self->state == 0x11) {
        int var85;
        TagValueEntry020e385c* tags;
        var85 = battle->unknown_8e18_->state >= 0 ? 1 : 0;
        ctrl->unknown_19af_ = 0;
        ctrl->unknown_19ca_ = 0;
        tags = func_020e3808();
        if (!var85 || (func_020e3ad0(tags, 1, -1) && var85)) {
            unsigned char* entry = func_020e385c(tags, 1, -1);
            int var88 = 0;
            int all;
            if (entry != 0 && (entry[5] & (1 << GameState_GetProtagonistIndex(gs)))) {
                var88 = 1;
            }
            all = 0;
            if (entry != 0 && (entry[5] & self->party->memberMask) == entry[5]) {
                all = 1;
            }
            if (all || !var88 || !entry) {
                MessageSystem_Reset((char*)ctrl);
                self->state = 4;
                func_020e3994(tags, 1, -1);
                return;
            }
        }
        if (((POWCNT & 0x8000) >> 15) == 1 && (IsScreenFullyFaded((GameResources*)res, false) || IsScreenFullyFaded((GameResources*)res, true)) && self->phase == 0) {
            SetBrightness(res, 0, 0xf);
            if (ctrl->busy == 0) {
                void* work = MessageSystem_GetInstance()->scriptWork;
                memset(work, 0, 0x960);
                func_020dd0b0(0, work);
                func_0204500c(ctrl, work, 0, 0xe3);
                ctrl->busy = 1;
            }
        }
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->unknown_7748_, 1) != 0) {
            return;
        }
        if (func_ov026_021d8a40() && FieldTaskQueue_IsEmpty(field3704) && func_020a35e0((unsigned char*)self->party, self->party->myIndex)) {
            func_ov026_021dce34(-1, self, self->battle, self->party, self->list, self->unknown_ec8_, self->unknown_5c3c_, self->unknown_5728_, self->unknown_e98_, self->unknown_ea0_, self->unknown_5910_, self->view);
        }
    }
    if (self->state == 4) {
        int var91;
        int i;
        if (((POWCNT & 0x8000) >> 15) == 1 && (IsScreenFullyFaded((GameResources*)res, false) || IsScreenFullyFaded((GameResources*)res, true)) && self->phase == 0) {
            SetBrightness(res, 0, 0xf);
            func_ov026_021dd8a8(battle, self->party);
            self->unknown_eb5_ = 0;
        } else if (self->unknown_eb5_ != 0) {
            func_ov026_021dd8a8(battle, self->party);
            self->unknown_eb5_ = 0;
        }
        if (self->unknown_772f_ & (ctrl->busy == 0)) {
            func_ov000_0217fbf4(self->list, -1);
            self->unknown_772f_ = 0;
        }
        func_ov000_02174514(self->list);
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->unknown_7748_, 1) != 0) {
            return;
        }
        {
            GameState* var93;
            int i;
            int n5;
            short var96[8];
            target = -1;
            memset(var96, target, sizeof(var96));
            n5 = func_ov000_0215eb1c(battle, var96, 8, 0);
            var93 = GameState::GetInstance();
            for (i = 0; i < n5; i++) {
                GameObject* c = func_0200fea4(var93, var96[i]);
                if (c != 0) {
                    ModifiableCombatStats* stats = c->currentStats_;
                    if ((*(int*)&stats->unk1[4] & 0x1000) && func_0200ff1c(var93, *(short*)&stats->unk1[0x1a]) == 0) {
                        target = var96[i];
                        func_02088e64((unsigned char*)c->currentStats_);
                        var91 = 1;
                        goto checked;
                    }
                }
            }
            var91 = 0;
        }
    checked:
        if (var91) {
            MessageWork* msg = MessageSystem_GetInstance();
            Container020e0310* box = self->inline_ov026_021d8ba0();
            GameObject* c = func_0200fea4(gs, target);
            void* text = KeyTable_Get(box, 0x28);
            if (text != 0 && c != 0) {
                func_02046380(msg);
                MessageSystem_SetStringArgument((Obj02046574*)msg, 0, (char*)c + 0x14c);
                func_020e4ce8(name, (char*)c, 1);
                msg->unknown_20_ = name;
                func_0204500c(msg, text, 0, 0xe3);
                msg->busy = 1;
                self->state = 0xf;
                return;
            }
        }
        if (func_ov026_021d8a40() && FieldTaskQueue_IsEmpty(field3704) && func_020a35e0((unsigned char*)self->party, self->party->myIndex)) {
            func_ov026_021dce34(-1, self, self->battle, self->party, self->list, self->unknown_ec8_, self->unknown_5c3c_, self->unknown_5728_, self->unknown_e98_, self->unknown_ea0_, self->unknown_5910_, self->view);
        }
        if (battle->unknown_8e47_ == 0) {
            if (FlagWord_TestBits((FlagWord02046708*)flagWord, 0x200) == 0) {
                int turns = battle->turns;
                int kind = battle->kind;
                int set = 1;
                if (turns == 0 && kind == 2) {
                    set = 0;
                }
                if (set) {
                    FlagWord_SetBits((unsigned int*)flagWord, 0x200);
                }
            }
            if (func_020a36a8((Combatant020A36A8*)self->party) && func_020e37e8(notify)) {
                func_020e3798(notify);
            }
        }
        func_ov000_0216258c(self);
        {
            int me = (signed char)GameState_GetProtagonistIndex(gs);
            int redo = 0;
            int changed = redo;
            int locked = redo;
            if (LinkSession_IsActive(link) && battle->turns == 0 && self->battle->kind == 2) {
                if (ctrl->busy != 0) {
                    locked = 1;
                }
            }
            if (locked == 0) {
                if (self->unknown_54f4_[me] != (func_ov000_0217fb98(self->list) == 0)) {
                    changed = 1;
                }
                func_ov000_02162c90((char*)self, me, func_ov000_0217fb98(self->list) == 0);
            }
            func_ov026_021db3d8(self);
            if (func_020a36a8((Combatant020A36A8*)self->party)) {
                party = self->party;
                redo = 1;
                lnk = LinkSession_GetInstance();
                if (LinkSession_IsActive(lnk)) {
                    for (i = 0; i < 4; i++) {
                        if (func_020a35e0((unsigned char*)party, i) && LinkSession_IsSlotMember((SearchStruct*)lnk, i)) {
                            redo = (redo & self->unknown_54f4_[i]) ? 1 : 0;
                        }
                    }
                } else if (self->unknown_54f4_[0] == 0) {
                    redo = 0;
                }
            } else if (self->unknown_5950_ != 0) {
                redo = 1;
            }
            if (redo) {
                func_ov000_0217fcc4(self->list, -1);
            }
            if (func_ov000_02168720((char*)self) > 0 || ctrl->busy != 0) {
                redo = 0;
            }
            if (redo && LinkSession_IsActive(link) && func_020a36a8((Combatant020A36A8*)self->party)) {
                if (func_ov026_021d8a40() == 0) {
                    redo = 0;
                }
            }
            if (LinkSession_IsActive(link)) {
                int cur = self->unknown_54f0_;
                int var111 = 0;
                int sel;
                if (cur >= 0) {
                    var111 = cur <= 3;
                }
                if (var111) {
                    int var113;
                    func_ov000_02162c14(self, cur, &cmdB);
                    var113 = !(cmdB.b[0] == self->cmd.b[0] && cmdB.b[1] == self->cmd.b[1] && cmdB.b[2] == self->cmd.b[2] &&
                                cmdB.b[3] == self->cmd.b[3] && cmdB.d == self->cmd.d && cmdB.e == self->cmd.e && cmdB.c == self->cmd.c);
                    if (var113 || changed) {
                        func_ov017_021c6814(self->party->netId, self->unknown_54f0_, &cmdB, self->unknown_54f4_[me], -1, 0);
                        self->cmd.b[0] = cmdB.b[0];
                        self->cmd.b[1] = cmdB.b[1];
                        self->cmd.b[2] = cmdB.b[2];
                        self->cmd.b[3] = cmdB.b[3];
                        self->cmd.c = cmdB.c;
                        self->cmd.d = cmdB.d;
                        self->cmd.e = cmdB.e;
                        if (LinkSession_IsHostOrSolo(link) != 0 && ((cmdB.b[0] == 100 && cmdB.b[1] == 6) || cmdB.b[0] == 0xd)) {
                            Roster* roster = (Roster*)GameState_GetParty(gs);
                            int m;
                            for (m = 0; m < roster->count; m++) {
                                if (self->unknown_54f0_ == m) continue;
                                func_ov000_02162c14(self, roster->ids[m], &var7);
                                func_ov017_021c6814(self->party->netId, roster->ids[m], &var7, self->unknown_54f4_[me], -1, 0);
                            }
                        }
                    }
                }
                sel = self->unknown_38dc_;
                if (self->unknown_54f0_ != sel) {
                    self->unknown_54f0_ = sel;
                    if (inline_ov017_021c9d2c(sel)) {
                        func_ov000_02162c14(self, sel, &var8);
                        func_ov017_021c6814(self->party->netId, sel, &var8, self->unknown_54f4_[me], -1, 0);
                    }
                }
            }
            if (redo && (self->unknown_54d2_ & 0x200)) {
                if (self->unknown_54c0_[self->unknown_54c8_] == 100) {
                    func_ov000_02175be4(self->list);
                    self->unknown_54d2_ &= ~0x200;
                    self->unknown_54d2_ |= 0x400;
                    self->unknown_eb4_ = 0;
                }
                self->unknown_774a_ = 1;
                redo = 0;
            }
            func_ov026_021db5a4(self);
            if ((self->unknown_54d2_ & 0x200) || self->phase > 0) {
                redo = 0;
            }
            if (self->unknown_7749_ != 0 && self->phase == 0) {
                func_ov026_021dbba8(self);
                func_ov000_0216118c(self, 0);
            }
            self->unknown_54e0_ = redo ? 1 : 0;
            if (redo) {
                func_ov000_021813d4(self->list);
                func_ov000_0217fcc4(self->list, -1);
                func_ov000_0217457c(self->list, -1);
                if (self->phase == -1) {
                    self->unknown_7710_ = 60;
                    SePlayer_UnloadExtraArchiveA(&g_sePlayer);
                    self->unknown_7711_ = 0;
                    SePlayer_LoadExtraArchiveA(&g_sePlayer, 0x1b3, 0x1b3);
                    func_0205eb90(&g_sePlayer, 0, 0);
                    self->unknown_7711_ = 1;
                }
                {
                    Object3D* o;
                    int i;
                    for (i = 0; i < 4; i++) {
                        o = (Object3D*)gs->GetGameObjectByIndex(self->unknown_7716_[i]);
                        if (o != 0) {
                            o->StopCurrentAnimation();
                            o->SetAnimationByName(data_ov026_021dedec, 1);
                        }
                    }
                }
                func_ov000_02160fbc(self, 0x40000000);
                if (!LinkSession_IsActive(link)) {
                    Random* var118;
                    self->unknown_5950_ = func_ov026_021dd3dc(self->battle, self->party, self->list);
                    var118 = &self->battle->rng;
                    self->unknown_6e3c_ = GetRandomStateHi(var118);
                    self->unknown_6e40_ = GetRandomStateLo(var118);
                    self->state = 5;
                } else {
                    int all;
                    int i;
                    if (self->unknown_7749_ == 0) {
                        func_ov000_02167e6c((unsigned char*)self);
                    }
                    func_ov026_021daec8(battle, func_ov000_02160f14(self), 0);
                    if (func_020a36a8((Combatant020A36A8*)self->party)) {
                        self->unknown_5950_ = func_ov026_021dd3dc(self->battle, self->party, self->list);
                        func_ov017_021cefe0(self->party->netId, self->unknown_5950_, self->unknown_7748_);
                        func_ov000_02160fa8(self, 0x800000);
                    }
                    if (FlagWord_TestBits((FlagWord02046708*)flagWord, 0x200)) {
                        func_020e36f0(notify);
                    }
                    self->state = 0x12;
                    func_ov017_021c894c(self->party->netId);
                    func_ov017_021c8758(self->party->netId);
                    func_ov017_021c8654();
                    func_ov017_021c847c();
                    all = 1;
                    for (i = 0; i < 4; i++) {
                        GameObject* c;
                        if (func_020a35e0((unsigned char*)self->party, i) && (c = gs->GetCombatantByIndex(i)) != 0) {
                            if (func_02010088((S_10088*)c) == 0) {
                                all = 0;
                            }
                        }
                    }
                    if (all) {
                        battle->result = 2;
                        func_ov000_02160d80(self, 0xa);
                    }
                }
            }
        }
    } else if (self->state == 0x12) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_020e37e8(notify) != 0 || FlagWord_TestBits((FlagWord02046708*)flagWord, 0x200) == 0) {
            FlagWord_ClearBits((FlagWord020466f4*)flagWord, 0x200);
            if (func_020a36a8((Combatant020A36A8*)self->party)) {
                self->state = 8;
            } else {
                self->state = 0xa;
            }
        }
    } else if (self->state == 8) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_0205e488(slots)) {
            int i;
            for (i = 0; i < 4; i++) {
                if (func_020a35e0((unsigned char*)self->party, i)) {
                    func_0200ff58(gs, i);
                    func_ov000_02162c14(self, i, &var9);
                    func_ov017_021c6814(self->party->netId, i, &var9, 1, -1, 1);
                }
            }
            self->state = 9;
        }
    } else if (self->state == 9) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_0205e488(slots)) {
            Random* var123 = &self->battle->rng;
            self->unknown_6e3c_ = GetRandomStateHi(var123);
            self->unknown_6e40_ = GetRandomStateLo(var123);
            func_ov017_021cf650(self->party->netId, self->unknown_6e3c_, self->unknown_6e40_);
            self->state = 0xb;
        }
    } else if (self->state >= 0xb && self->state <= 0xd) {
        if (self->state == 0xd) {
            self->state = 5;
        } else {
            self->state = self->state + 1;
        }
    } else if (self->state == 0xa) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_ov000_02160fd4(self, 0x20000)) {
            self->state = 5;
        }
    } else if (self->state == 5) {
        int i;
        if (LinkSession_IsActive(link) && link[0xfc0 / 4] != 0) {
            return;
        }
        if (self->unknown_7711_ != 0 && self->unknown_7710_ != 0) {
            return;
        }
        if (self->unknown_7748_ != 0) {
            int n = func_ov000_0215ec1c(battle, var10, 8, 0);
            int i;
            for (i = 0; i < n; i++) {
                GameObject* c = func_0200fea4(gs, var10[i]);
                if (c != 0) {
                    ModifiableCombatStats* stats = c->currentStats_;
                    stats->primaryStats.currHP = stats->primaryStats.maxHP;
                }
            }
            self->unknown_7748_ = 0;
        }
        if (self->phase == -1) {
            for (i = 0; i < 4; i++) {
                if (gs->GetGameObjectByIndex(self->unknown_7716_[i]) != 0) {
                    return;
                }
            }
            func_ov026_021dbba8(self);
        }
        ((SafeAllocator*)self->unknown_774c_)->Destroy();
        self->unknown_7749_ = 0;
        func_02057f00(func_02057924(), 0x13);
        if (FieldTaskQueue_IsEmpty((void**)res->unknown_ptr_array_3700[0]) == 0) {
            return;
        }
        SetFlags00(res, 0x10);
        memset(self->unknown_54f4_, 0, 0x10);
        self->party->unknown_30_ = 0;
        func_ov000_02160fbc(self, 0x4000000);
        func_ov000_02160fbc(self, 0x8000000);
        func_ov000_02160fbc(self, 0x10000000);
        func_ov000_02160fbc(self, 0x20000000);
        {
            Object3D* o;
            int i;
            for (i = 0; i < 4; i++) {
                if (func_020a35e0((unsigned char*)self->party, i)) {
                    func_ov000_02162c14(self, i, &var11);
                    o = (Object3D*)gs->GetGameObjectByIndex(i);
                    if (o != 0) {
                        o->DisableFlag(0x1000);
                    }
                }
            }
        }
        {
            PartyState* party = self->party;
            int r;
            Roster* roster;
            gs = GameState::GetInstance();
            for (i = 0; i < 4; i++) {
                GameObject* c;
                if (func_020a35e0((unsigned char*)party, i) && (c = func_0200ff1c(gs, i)) != 0) {
                    func_02053dd0((Struct_02053dd0*)c);
                }
            }
            roster = (Roster*)GameState_GetParty(gs);
            if (roster != 0) {
                for (r = 0; r < roster->count; r++) {
                    GameObject* c = func_0200ff1c(gs, roster->ids[r]);
                    if (c != 0 && func_02010088((S_10088*)c) == 0) {
                        self->unknown_58ce_++;
                        break;
                    }
                }
            }
        }
        func_ov000_02168144(self);
        func_0209a338((Pair0209a338*)(self->unknown_e98_));
        ((SafeAllocator*)(self->alloc))->Reset();
        self->unknown_55d8_ = 0;
        func_ov000_0215d588(battle);
        if (LinkSession_IsActive(link) && func_020e37e8(notify)) {
            func_020e3798(notify);
        }
        if (self->unknown_5950_ == 1) {
            func_ov000_02160da0(self);
        } else {
            func_ov000_02160d80(self, 0xb);
        }
    } else if (self->state == 6) {
        if (loader->GetNumQueuedTasks() > 0) {
            return;
        }
        func_ov000_021637c8(self);
        func_ov026_021dc440((SafeAllocator*)(self->alloc), self, self->battle, self->party, 0);
        func_ov026_021dc040((SafeAllocator*)(self->alloc), self, self->battle, self->party);
        func_ov000_02163894(self);
        self->state = 7;
    } else if (self->state == 7) {
        func_ov000_02163928(self);
        if (func_ov026_021dc040((SafeAllocator*)(self->alloc), self, self->battle, self->party) != 0) {
            self->state = 0;
        }
    }
    if (self->state == 0xf && MessageSystem_GetInstance()->busy == 0) {
        self->state = 4;
    }
}
