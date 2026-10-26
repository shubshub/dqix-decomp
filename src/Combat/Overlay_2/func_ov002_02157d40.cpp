#include "Resource/ActionDataTables.h"
#include <globaldefs.h>

#include "Combat/ResourceScriptEntry.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define RG(u, j) (j)
#define FMT(a, b, c, d) func_020474a8(a, b, c, d)
#define ST(x) ((x) == 7 ? 8 : (x) == 0x11 ? 0x12 : (x) == 0x14 ? 0x15 : (x) == 0x26 ? 0x29 : (x) == 0x2b ? 0x2e : (x))
extern "C" void func_020474a8(void* arg0, int arg1, int arg2, char* arg3);
extern "C" GameObject* func_0200ff94(GameState* arg0, int arg1);
#else
#define RG(u, j) (u)
#define FMT(a, b, c, d) MessageSystem_FormatText(a, b, c, d, 0xe3, 0, 1)
#define ST(x) (x)
#endif
struct Struct_ov002_02157d40_19 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_ov002_02157d40* unknown_8_[0xe9];
};
struct Struct_ov002_02157634_8 {
    char* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 2;
    unsigned int unknown_9_4_ : 20;
};
struct Struct_ov002_02157d40 {
    unsigned short unknown_0_;
    char unknown_2_[0x132];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
};
struct GameState;

struct Struct_0201099c_3;
struct Struct_ov002_02157d40_2;
struct Struct_ov002_02157d40_3;
struct Struct_ov002_02157634_6 {
    char unknown_0_[0xc];
    unsigned short unknown_c_;
};
struct Struct0201bc94;
struct Obj020541a4;
struct Obj02046574;
struct SePlayer;
struct Obj02048350;
struct List02046a3c;
struct Node02046a3c;
struct List02026a28;
struct List02026abc;
struct WhistleTask;
struct Obj021c2b28;

extern "C" void* __clear(void* dst, int count);
extern "C" void* Zone3D_GetInstance(void);
void* GetData02153637_020e2ff8(void);
void* SearchBothTables02079e2c(char* p, int key);
extern "C" void* LinkSession_GetInstance(void);
int GameObject_GetPartyMemberLevel(void* p);
void SetByteInRange_020465f0(unsigned char* p, int a, unsigned char b);
void InitObj021c2b28(void* p, unsigned char a, unsigned char b);
void Dispatch020e3428(void* p, int flag);
int ZoneId_IsGrotto(int v);
int ZoneId_IsMainGrottoFloor(int v);
void NotifySub020541a4(struct Obj020541a4* p, unsigned char b);
void StoreInArray0x8b0_020465c0(struct StoreStruct* p, int a, int b);
int LinkSession_IsActive(int* p);
void* LoadFileIntoMemory(const char* path, void* buf, unsigned int* outSize);
void TryClearFlags0x130_02048418(unsigned char* p, unsigned short mask);
void ClearStruct020a8170(struct Struct020a8170* p);
int GameState_GetPartyOrder(char* dst, void* src);
int GetByteFieldAt0x9ba_0202663c(unsigned char* p);
void InsertNodeAfterHead(struct List02046a3c* list, struct Node02046a3c* node);
void Text_Append(char* dst, const char* src);
void MapDisplay_ClearRedChests(char* p);
void FieldTask_InitWhistle(struct WhistleTask* p);
int KeyTable_Get(struct Container020e0310* c, int key);
void ResourceScriptEntry_Init(void* p);
void ConsumeCounter02048350(struct Obj02048350* p, int a);
void InitStateArray02157ce0(char* p);
void MessageSystem_SetStringArgument(struct Obj02046574* p, int a, char* s);
int CountEntriesByField0x8c(struct List02026a28* p);
int CountEntriesByField0x8e(struct List02026abc* p);
void InitByteHeader_021c2688(unsigned char* p);
void SetFlagsAndReset02026678(char* p);
int IsEntryEligibleAndFlagged(struct Struct0201bc94* p);
void EnqueueEventTag34_021d27a0(int, int, int);
int MessageSystem_GetInstance(void);
void InitAndInsertNode_021acd30(char* p, unsigned char a, unsigned char b, unsigned char c);
int CountMatchingEntries02026a78(char* p);
void SePlayer_Play(struct SePlayer* p, int a, int b);
struct GameObject;
void InitObjFromCombatant020e4c74(void*, GameObject*);
void NameText_InitFromPartyMember(void* p, int a);
int ClampAndCompareThreshold02048448(struct Struct02048448* p, int a);

extern "C" void* memcpy(void* arg0, const void* arg1, unsigned int arg2);
extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" int sprintf(char* arg0, const char* arg1, ...);


extern "C" int func_02026780(void* list, void* buf, unsigned int size);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void func_02046380(void* obj);
extern "C" void MessageSystem_FormatText(void* obj, int a, int b, char* buf, int c, int d, int e);
extern "C" void func_02052d7c(void* obj, signed char idx, int flag);
extern "C" void func_0207c378(void* p, short val, int flag, unsigned int nibble);

extern "C" void func_020a818c(void* arg0, void* arg1);
extern "C" void func_020a8304(void* arg0);
extern "C" void func_ov002_021536e0(void* arg0);
extern "C" int func_ov002_021536ec(void* arg0, void* arg1, int arg2);
extern "C" void func_ov002_0216c42c(void* arg0, void* arg1, void* arg2);
extern "C" void func_ov016_0218b5c0(int arg0, int arg1);
extern "C" void func_ov017_0218f5a4(void* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" int func_ov017_0219ff58(int arg0, int arg1, int arg2, int arg3);
extern "C" int func_ov017_021ab860(signed char arg0);
extern "C" void func_ov017_021c12fc(void* arg0, int arg1, int arg2);
static inline short* inline_ov002_02157d40(char* arg0) {
    int* var0 = *(int**)(arg0 + 0x3000 + RG(0x71c, 0x50c));
    return (short*)((char*)var0 + 0x22);
}
extern "C" void func_ov017_021c3fb4(signed char arg0, int arg1);
extern "C" void func_ov017_021c4418(signed char arg0, int arg1);
extern "C" void func_ov017_021c9e00(signed char arg0, int arg1, int arg2, int arg3);

extern int g_sePlayer;
extern unsigned char data_ov002_0216c992;
extern int data_ov002_0216cf51;
extern int g_fileLoadBuffer;
extern int data_ov002_0216cf66;

struct Struct_ov002_02157d40_14 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};
struct Struct_ov002_02157d40_15 {
    int unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 14;
    unsigned int unknown_a_2_ : 1;
    unsigned int unknown_a_3_ : 13;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
    short unknown_1a_;
    int unknown_1c_;
};
struct Struct_ov002_02157d40_16 {
    char unknown_0_[0x138];
    int unknown_138_[0x17];
    struct Struct_ov002_02157d40_15 unknown_194_[11];
    char unknown_2f4_[0x277];
    struct Struct_ov002_02157d40_14 unknown_56b_;
    char unknown_56c_[RG(0x3e4, 0x34c)];
    int unknown_950_;
};
struct Struct_ov002_02157d40_17 {
    unsigned short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0x12a];
    int* unknown_130_;
    char* unknown_134_;
    char unknown_138_[RG(0x18, 0xc)];
    struct Struct_ov002_02157d40_16* unknown_150_;
};
struct Struct_ov002_02157d40_18 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};
struct Struct_ov002_02157634_2 {
    char unknown_0_[8];
#if !defined(jpn)
    char unknown_8_[0xc];
    char unknown_14_[0xc];
#endif
    char unknown_20_[RG(0x880, 0x7fc)];
    char unknown_8a0_[RG(0x1318, 0x127c)];
    int unknown_1bb8_;
    int unknown_1bbc_;
    int unknown_1bc0_;
    char unknown_1bc4_[0xc];
    char* unknown_1bd0_;
    char* unknown_1bd4_;
    char unknown_1bd8_[0x48];
    signed char unknown_1c20_;
    signed char unknown_1c21_;
    char unknown_1c22_[4];
    short unknown_1c26_;
    short unknown_1c28_;
    short unknown_1c2a_;
    char unknown_1c2c_[5];
    unsigned char unknown_1c31_;
    char unknown_1c32_[RG(6, 2)];
    int unknown_1c38_;
    int unknown_1c3c_[0xe];
    int unknown_1c74_;
    char unknown_1c78_[2];
    unsigned char unknown_1c7a_;
    unsigned char unknown_1c7b_;
    char unknown_1c7c_[0x4a];
    unsigned char unknown_1cc6_;
    unsigned char unknown_1cc7_;
    char unknown_1cc8_[0x3c];
    char unknown_1d04_[RG(0x770, 0x6dc)];
    struct Struct_ov002_02157634_6* unknown_2474_;
    char unknown_2478_[0x10];
    short unknown_2488_;
    unsigned char unknown_248a_;
    unsigned char unknown_248b_;
    unsigned char unknown_248c_;
    char unknown_248d_[3];
    int unknown_2490_;
    int unknown_2494_;
    char unknown_2498_[0x8a];
    unsigned char unknown_2522_;
    unsigned char unknown_2523_;
    char unknown_2524_[0xc];
    int unknown_2530_;
};
struct Struct_ov002_02157634_3 {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};
struct Struct_ov002_02157634_4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    signed char unknown_4_[4];
    struct Struct_ov002_02157634_3 unknown_8_[4];
    struct Struct_ov002_02157634_3 unknown_20_[4];
    int unknown_38_;
};
struct Struct_ov002_02157d40_20 {
    signed char unknown_0_[11];
};
struct Struct_ov002_02157d40_21 {
    void* unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned char unknown_10_[4];
    void* unknown_14_;
    unsigned char unknown_18_[4];
    struct Struct_ov002_02157d40_20 unknown_1c_;
    struct Struct_ov002_02157634_4 unknown_28_;
    struct Struct_ov002_02157634_4 unknown_64_;
    char unknown_a0_[0x28];
    struct Struct_ov002_02157634_4 unknown_c8_;
    int unknown_104_[0x15];
};

struct Struct_ov002_02157d40_22 {
    char unknown_0_[RG(0x20, 0xe8)];
    signed char unknown_20_;
    signed char unknown_21_;
    char unknown_22_[4];
    short unknown_26_;
    short unknown_28_;
    short unknown_2a_;
};
static inline struct Struct_ov002_02157d40_22* inline_ov002_02157d40_2(struct Struct_ov002_02157634_2* arg0) {
    struct Struct_ov002_02157d40_22* var0 = (struct Struct_ov002_02157d40_22*)((char*)arg0 + RG(0x1c00, 0x1a00));
    return var0;
}
static inline int inline_ov002_02157d40_3(struct Struct_ov002_02157d40_16* arg0) {
    return arg0->unknown_138_[arg0->unknown_950_];
}

static inline int inline_ov002_02157d40_4(struct Struct_ov002_02157d40_17* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_4_; }
static inline char* inline_ov002_02157d40_5(struct Struct_ov002_02157d40_17* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_134_; }

enum Enum_ov002_02157d40 { Enum_ov002_02157d40_m1 = -1, Enum_ov002_02157d40_9004 = 0x232c, Enum_ov002_02157d40_9018 = 0x233a };

// USA: func_ov002_02157d40
extern "C" ARM void func_ov002_02157d40(struct BattleMenu* p) {
    struct Frame f;
    char* tbl;
    struct BattleStruct* gs = (BattleStruct*)GameState::GetInstance();
    int word = (int)((GameState*)gs)->GetResources();
    unsigned short* obj = (unsigned short*)Zone3D_GetInstance();
    ActionDataTables* actionTables = GetData02108e10_020797dc();
    tbl = (char*)actionTables;
    struct TableEntry* entryA = (struct TableEntry*)SearchBothTables02079e2c(tbl, p->command);
    #if defined(jpn)
    struct Struct_ov002_02157d40_17* var7 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff94((GameState*)var2, arg0->unknown_1c20_);
#else
    struct Struct_ov002_02157d40_17* var7 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff1c((GameState*)var2, arg0->unknown_1c20_);
#endif
    int* checkPtr = (int*)LinkSession_GetInstance();
    int flagA = 0;
    int flagB;
    bool flag1c;

    if (arg0->unknown_1bb8_ == ST(0x11)) {

        arg0->unknown_1c28_ = 0x232d;
        arg0->unknown_1c2a_ = -1;
        var10 = 0;
        var11 = 0;
        if (arg0->unknown_1c26_ == 0xd7) {
            arg0->unknown_1c28_ = 0x233b;
        }
        if (func_02048448((struct Struct_ov002_02157d40_3*)var7, (unsigned short)var6->unknown_8_0_) == 0) {
            arg0->unknown_1c28_ = 0x232f;
            arg0->unknown_1c2a_ = -1;
            arg0->unknown_248a_ = 0;
            arg0->unknown_2488_ = -1;
            arg0->unknown_1bb8_ = ST(0x26);
            arg0->unknown_1bbc_ = ST(0x11);
            return;
        }
        if (p->command == 0xd7) {
            flagA = 1;
            flagB = 1;
            char* ov = (char*)GetGameResources();
            *ListField22(ov) = p->actor;
            func_ov017_021c12fc(ov, 1, 0);
        } else if (p->command == 0xd9) {
            flagA = 1;
            if (IsEntryEligibleAndFlagged((struct Struct0201bc94*)Zone3D_GetInstance()) != 0) {
                func_ov016_0218b5c0(0, -1);
                p->target = p->actor;
                p->msgId = 0x754a;
                flagB = 1;
                struct PartyList* party = (struct PartyList*)GameState_GetParty((GameState*)gs);
                for (int i = 0; i < party->count; i++) {
                    NotifySub020541a4((struct Obj020541a4*)(CombatantStruct*)((GameState*)gs)->GetPartyMemberByIndex(party->ids[i]), 0);
                }
            } else {
                arg0->unknown_1c28_ = 0x754e;
                arg0->unknown_248a_ = 1;
                arg0->unknown_2488_ = 0x754f;
                var9 = 0;
            }
        } else if (arg0->unknown_1c26_ == 0xcd) {
            inline_ov002_02157d40_2(arg0)->unknown_2a_ = -1;
            arg0->unknown_248a_ = 1;
            int var15 = func_ov017_021ab860(arg0->unknown_1c20_);
            if (var15 == 0) {
                arg0->unknown_2488_ = 0x232b;
            } else if (var15 == 1) {
                arg0->unknown_2488_ = 0x2338;
            } else if (var15 == 3) {
                arg0->unknown_1c28_ = 0x233c;
                arg0->unknown_1c21_ = arg0->unknown_1c20_;
                var10 = 1;
                arg0->unknown_248a_ = 0;
                var9 = 1;
                arg0->unknown_2488_ = -1;
            }
        } else if (p->command == 0x1e || p->command == 0x1f || p->command == 0x20 || p->command == 0x21 || p->command == 0x23 || p->command == 0x26 || p->command == 0x27) {
            p->state = ST(7);
            flag1c = 1;
        } else if (p->command == 0x22 || p->command == 0x310) {
            InitStateArray02157ce0((char*)&f.st10c);
            InitStateArray02157ce0((char*)&f.st10c);
            int res = 0;
            struct TableEntry* entry = (struct TableEntry*)SearchBothTables02079e2c(tbl, p->command);
            if (entry != 0) {
                __clear(f.ids5c, 4);
                int n = GameState_GetPartyOrder((char*)gs, f.ids5c);
                if (entry->b10 & 1) {
                    func_ov016_0218b5c0(0, -1);
                    var0.unknown_c8_.unknown_0_ = arg0->unknown_1c26_;
                    var0.unknown_c8_.unknown_2_ = arg0->unknown_1c20_;
                    var0.unknown_c8_.unknown_3_ = var18;
                    for (int var19 = 0; var19 < var18; var19++) {
                        var0.unknown_c8_.unknown_4_[var19] = var0.unknown_18_[var19];
                    }
                    func_ov002_021536e0(&var0.unknown_14_);
                    var0.unknown_14_ = var1;
                    var16 = func_ov002_021536ec(&var0.unknown_14_, &var0.unknown_c8_, 0);
                }
                int var20 = 0;
                struct Struct_ov002_02157634_3* var21 = var0.unknown_c8_.unknown_8_;
                struct Struct_ov002_02157634_3* var22 = var0.unknown_c8_.unknown_20_;
                int var23;
                for (var23 = 0; var23 < var0.unknown_c8_.unknown_3_; var23++) {
                    struct Struct_ov002_02157634_3* var24 = &var21[var23];
                    struct Struct_ov002_02157634_3* var25;
                    if (var24->unknown_4_ != 0 || (var25 = &var22[var23])->unknown_4_ != 0) {
                        var20 = 1;
                        break;
                    }
                }
                if (var20) {
                    func_ov002_0216c42c(arg0, &var0.unknown_c8_, var17);
                    arg0->unknown_1cc6_ = 0;
                    arg0->unknown_1cc7_ = 1;
                    func_ov002_02157ce0((char*)(arg0->unknown_1cc8_));
                    memcpy(arg0->unknown_1cc8_, &var0.unknown_c8_, 0x3c);
                    arg0->unknown_1c28_ = -1;
                    arg0->unknown_1c2a_ = -1;
                    arg0->unknown_1bb8_ = ST(0x26);
                    arg0->unknown_1bbc_ = ST(0x26);
                    arg0->unknown_2488_ = -1;
                    arg0->unknown_248a_ = 0;
                    arg0->unknown_1c7a_ = 1;
                    arg0->unknown_1c7b_ = 0x14;
                    arg0->unknown_1c74_ = 0x1e;
                    arg0->unknown_1bc0_ = 0;
                    return;
                }
                unsigned char* msg = (unsigned char*)MessageSystem_GetInstance();
                func_02046380(msg);
                memset(p->text, 0, RG(0x960, 0x800));
                tbl = p->text;
                if (comb != 0) {
                    MessageSystem_SetStringArgument((struct Obj02046574*)msg, 0, comb->name);
#if !defined(jpn)
                    NameText_InitFromPartyMember(p->obj8, UnitId(comb));
                    *(void**)msg = p->obj8;
#endif
                }
                MessageSystem_SetStringArgument((struct Obj02046574*)msg, 1, entry->name);
                if (res != 0) {
                    FMT(msg, 0xc, KeyTable_Get((struct Container020e0310*)(p->container20), 0x232d), (char*)(tbl + RG(0x860, 0x700)));
                    Text_Append(p->text, (const char*)(tbl + RG(0x860, 0x700)));
                    struct StateSlot* slots = f.st10c.first;
                    for (int i = 0; i < f.st10c.count; i++) {
                        MsgKey key;
                        if (slots[i].a[0] == 3) {
                            key = MSG_KEY_DEAD;
                        } else {
                            var29 = Enum_ov002_02157d40_9018;
                        }
                        if (var29 < 0) {
                            continue;
                        }
                        struct Struct_ov002_02157d40_17* var30 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff1c((GameState*)var2, var0.unknown_c8_.unknown_4_[var28]);
                        if (var30 == 0) {
                            continue;
                        }
                        func_02046380(msg);
                        MessageSystem_SetStringArgument((struct Obj02046574*)msg, 2, UnitName(target));
#if !defined(jpn)
                        NameText_InitFromPartyMember(p->obj14, f.st10c.ids[i]);
                        *(void**)(msg + 0x10) = p->obj14;
#endif
                        StoreInArray0x8b0_020465c0((struct StoreStruct*)msg, 9, target->id);
                        FMT(msg, 0xc, KeyTable_Get((struct Container020e0310*)(p->container20), key), (char*)(tbl + RG(0x860, 0x700)));
                        Text_Append(p->text, (const char*)KeyTable_Get((struct Container020e0310*)(p->container20), 8));
                        Text_Append(p->text, (const char*)(tbl + RG(0x860, 0x700)));
                    }
                    ConsumeCounter02048350((struct Obj02048350*)comb, entry->lo8);
                    if (LinkSession_IsActive(checkPtr) != 0) {
                        func_ov017_021c9e00(p->actor, 0, 0, 1);
                    }
                } else {
                    struct CombatantStruct* unknown = (CombatantStruct*)((GameState*)gs)->GetLeader();
                    if (unknown != 0) {
                        MessageSystem_SetStringArgument((struct Obj02046574*)msg, 2, ((struct Unit*)unknown)->name);
#if !defined(jpn)
                        InitObjFromCombatant020e4c74(p->obj14, (GameObject*)(CombatantStruct*)((GameState*)gs)->GetLeader());
                        *(void**)(msg + 0x10) = p->obj14;
#endif
                    }
                    Text_Append((char*)(tbl + RG(0x860, 0x700)), (const char*)KeyTable_Get((struct Container020e0310*)(p->container20), 0x2333));
                    Text_Append((char*)(tbl + RG(0x860, 0x700)), (const char*)KeyTable_Get((struct Container020e0310*)(p->container20), 8));
                    if (n == 1) {
                        Text_Append((char*)(tbl + RG(0x860, 0x700)), (const char*)KeyTable_Get((struct Container020e0310*)(p->container20), 0x2334));
                    } else {
                        Text_Append((char*)(tbl + RG(0x860, 0x700)), (const char*)KeyTable_Get((struct Container020e0310*)(p->container20), 0x2335));
                    }
                    FMT(var26, 0xc, (int)(var1 + RG(0x860, 0x700)), arg0->unknown_1bd0_);
                }
                arg0->unknown_1c31_ = 1;
                memcpy(arg0->unknown_1bd4_, arg0->unknown_1bd0_, RG(0x960, 0x800));
                arg0->unknown_2488_ = -1;
                arg0->unknown_248a_ = 0;
            }
        } else if (arg0->unknown_1c26_ == 0xca) {
            if (func_ov017_0219ff58(var3, 1, 0, 0) != 0) {
                var10 = 1;
                func_ov017_021acd30((char*)var3, 0, 0, 0);
            } else {
                ((SafeAllocator*)arg0->unknown_8a0_)->Reset();
                arg0->unknown_2474_ = (struct Struct_ov002_02157634_6*)((SafeAllocator*)arg0->unknown_8a0_)->Allocate(0x10);
                func_020a8170(arg0->unknown_2474_);
                func_020a818c(arg0->unknown_2474_, arg0->unknown_8a0_);
                func_020a8304(arg0->unknown_2474_);
                if (arg0->unknown_2474_->unknown_c_ == 0) {
                    arg0->unknown_1c2a_ = -1;
                    arg0->unknown_248a_ = 1;
                    arg0->unknown_2488_ = 0x2338;
                    ((SafeAllocator*)arg0->unknown_8a0_)->Reset();
                    arg0->unknown_2474_ = 0;
                } else {
                    arg0->unknown_1bb8_ = ST(0x14);
                    arg0->unknown_1bc0_ = 0;
                    return;
                }
            }
        } else if (p->command == 0xcf) {
            unsigned char* ov = (unsigned char*)GetGameResources();
            unsigned char* list;
            unsigned char* node = *(unsigned char**)(ov + RG(0x3bac, 0x398c));
            list = *(unsigned char**)(ov + RG(0x36fc, 0x34ec));
            if (node[2] == 0) {
                FieldTask_InitWhistle((struct WhistleTask*)node);
                *(int*)(node + 0x14) = comb->id;
                InsertNodeAfterHead((struct List02046a3c*)list, (struct Node02046a3c*)node);
            }
            arg0->unknown_1bb8_ = ST(0x2b);
            arg0->unknown_1bbc_ = ST(0x2b);
            return;
        } else if (p->command == 0xd0) {
            unsigned char* msg = (unsigned char*)MessageSystem_GetInstance();
            memset(p->text, 0, RG(0x960, 0x800));
            tbl = p->text;
            struct Unit* actor = (struct Unit*)(CombatantStruct*)GetCombatantWithFlag0x100_0200ff1c((GameState*)gs, p->actor);
            if (actor != 0) {
                func_02046380(msg);
                MessageSystem_SetStringArgument((struct Obj02046574*)msg, 0, actor->name);
#if !defined(jpn)
                NameText_InitFromPartyMember(p->obj8, p->actor);
                *(void**)msg = p->obj8;
#endif
                FMT(msg, 0xc, KeyTable_Get((struct Container020e0310*)(p->container20), 0x7537), (char*)(tbl + RG(0x860, 0x700)));
                Text_Append(p->text, (const char*)(tbl + RG(0x860, 0x700)));
            }
            __clear(f.ids54, 4);
            int cnt = GameState_GetPartyOrder((char*)gs, f.ids54);
            int* total = f.obj148;
            int k;
            for (k = 0; k < cnt; k++) {
                struct Unit* member = (struct Unit*)(CombatantStruct*)GetCombatantWithFlag0x100_0200ff1c((GameState*)gs, f.ids54[k]);
                if (member == 0) {
                    continue;
                }
                struct Struct_ov002_02157d40_16* var41 = var40->unknown_150_;
                int var42;
                if (var41 != 0) {
                    var42 = var41->unknown_56b_.unknown_0_0_ != 0;
                } else {
                    var42 = 0;
                }
                if (var42) {
                    continue;
                }
                func_02046380(msg);
                MessageSystem_SetStringArgument((struct Obj02046574*)msg, 0, member->name);
#if !defined(jpn)
                NameText_InitFromPartyMember(p->obj8, f.ids54[k]);
                *(void**)msg = p->obj8;
#endif
                int key;
                if (GameObject_GetPartyMemberLevel((void*)member) == 0x63) {
                    key = 0x7539;
                } else {
                    BackgroundLoader::AddLockGlobal();
                    ext = member->ext;
                    sprintf(f.path, (const char*)&data_ov002_0216cf51, ext->level);
                    void* loaded = LoadFileIntoMemory(f.path, &g_fileLoadBuffer, &f.size50);
                    ResourceScriptEntry_Init(f.obj148);
                    if (loaded != 0) {
                        ResourceScriptEntry_LoadLevel(f.obj148, loaded, f.size50, GameObject_GetPartyMemberLevel((void*)member) + 1, 0);
                    }
                    BackgroundLoader::RemoveLockGlobal();
                    int var45 = *var38 - inline_ov002_02157d40_3(var40->unknown_150_);
                    if (var45 <= 0) {
                        var43 = 0x753a;
                    } else {
                        func_020465c0((struct Struct_ov002_02157d40_2*)var35, 0, var45);
                        func_020465f0(var35, 0, 0);
                        var43 = 0x7538;
                    }
                }
                memset(tbl + RG(0x860, 0x700), 0, 0x100);
                FMT(msg, 0xc, KeyTable_Get((struct Container020e0310*)(p->container20), key), (char*)(tbl + RG(0x860, 0x700)));
                Text_Append(p->text, (const char*)KeyTable_Get((struct Container020e0310*)(p->container20), 8));
                Text_Append(p->text, (const char*)(tbl + RG(0x860, 0x700)));
            }
            arg0->unknown_1c31_ = 1;
            memcpy(arg0->unknown_1bd4_, arg0->unknown_1bd0_, RG(0x960, 0x800));
            arg0->unknown_2488_ = -1;
            arg0->unknown_248a_ = 0;
            var10 = 1;
        } else if (arg0->unknown_1c26_ == 0xd1) {
            arg0->unknown_1bb8_ = ST(7);
            var11 = 1;
        } else if (arg0->unknown_1c26_ == 0xd2) {
            arg0->unknown_248b_ = 1;
            unsigned char* var46;
            unsigned char* var47 = *(unsigned char**)((unsigned char*)var3 + RG(0x3ba8, 0x3988));
            var46 = *(unsigned char**)((unsigned char*)var3 + RG(0x36fc, 0x34ec));
            func_ov017_021c2688(var47);
            var47[0xc] = arg0->unknown_1c20_;
            func_02046a3c((struct Struct_ov002_02157d40_9*)var46, (struct Struct_ov002_02157d40_10*)var47);
            arg0->unknown_1bb8_ = ST(0x2b);
            arg0->unknown_1bbc_ = ST(0x2b);
            return;
        } else if (p->command == 0xd5) {
            unsigned char* rec = *(unsigned char**)((unsigned char*)GetGameResources() + RG(0x36d0, 0x34c0));
            p->msgId = 0x7543;
            flagA = 1;
            if (LinkSession_IsGuest(checkPtr) != 0 && ZoneId_IsGrotto(*obj) == 0) {
                p->showPrompt = 1;
                p->prompt = 0x7548;
                flagA = 0;
            } else if (GetByteFieldAt0x9ba_0202663c(rec) == 0) {
                func_ov016_0218b5c0(0, -1);
                arg0->unknown_1c21_ = arg0->unknown_1c20_;
                func_02026678((char*)var48);
            } else {
                arg0->unknown_248a_ = 1;
                arg0->unknown_2488_ = 0x232b;
                arg0->unknown_1bb8_ = ST(0x26);
                arg0->unknown_1bbc_ = ST(0x11);
                var9 = 0;
            }
            flagB = 1;
        } else if (p->command == 0xd3) {
            int ok = 1;
            unsigned char* rec = *(unsigned char**)((unsigned char*)GetGameResources() + RG(0x36d0, 0x34c0));
            p->countA = 0;
            p->countB = 0;
            flagA = ok;
            p->showPrompt = flagA;
            p->msgId = 0x7544;
            if (LinkSession_IsGuest(checkPtr) != 0) {
                p->prompt = 0x7549;
                flagA = 0;
            } else {
                if (ZoneId_IsMainGrottoFloor(*obj) != 0) {
                    ok = 0;
                } else if (GetByteFieldAt0x9ba_0202663c(rec) != 0) {
                    p->countA = CountEntriesByField0x8c((struct List02026a28*)rec);
                    p->countB = CountEntriesByField0x8e((struct List02026abc*)rec);
                } else {
                    MapDisplay_ClearRedChests((char*)rec);
                    BackgroundLoader::AddLockGlobal();
                    f.size4c = 0;
                    void* data = LoadFileIntoMemory((const char*)&data_ov002_0216cf66, &g_fileLoadBuffer, &f.size4c);
                    if (func_02026780(rec, data, f.size4c) == 0) {
                        ok = 0;
                    } else {
                        func_02026a78((char*)var50);
                        arg0->unknown_2490_ = func_02026a28((struct Struct_ov002_02157d40_11*)var50);
                        arg0->unknown_2494_ = func_02026abc((struct Struct_ov002_02157d40_12*)var50);
                    }
                    BackgroundLoader::RemoveLockGlobal();
                }
                if (var49) {
                    if (arg0->unknown_2490_ > 0 && arg0->unknown_2494_ == 0) {
                        arg0->unknown_2488_ = 0x7546;
                        var10 = 1;
                    } else if (*(int*)&arg0->unknown_2490_ > 0) {
                        arg0->unknown_2488_ = 0x7545;
                        var10 = 1;
                    } else {
                        arg0->unknown_2488_ = 0x7547;
                    }
                } else {
                    arg0->unknown_2488_ = 0x232b;
                    var9 = 0;
                }
            }
            arg0->unknown_1bb8_ = ST(0x26);
            arg0->unknown_1bbc_ = ST(0x26);
        } else if (arg0->unknown_1c26_ == 0xce) {
            unsigned char* var52 = (unsigned char*)GetGameResources();
            unsigned char* var53;
            unsigned char* var54 = *(unsigned char**)(var52 + RG(0x3bb0, 0x3990));
            var53 = *(unsigned char**)(var52 + RG(0x36fc, 0x34ec));
            if (var54[2] == 0) {
                func_ov017_021c2b28(var54, 0, var7->unknown_4_);
                func_02046a3c((struct Struct_ov002_02157d40_9*)var53, (struct Struct_ov002_02157d40_10*)var54);
            }
            arg0->unknown_1c28_ = 0x233c;
            var9 = 1;
            var10 = 1;
            arg0->unknown_1c21_ = arg0->unknown_1c20_;
        } else if (arg0->unknown_1c26_ == 0xa2 || arg0->unknown_1c26_ == 0xa4) {
            arg0->unknown_1c21_ = arg0->unknown_1c20_;
            int var55 = 0;
            struct Struct_ov002_02157634_8* var56 = (struct Struct_ov002_02157634_8*)func_02079e2c(var1, arg0->unknown_1c26_);
            if (var56 != 0 && (var56->unknown_9_2_ & 1)) {
                func_ov016_0218b5c0(var55, -1);
                func_ov002_02157ce0((char*)&var0.unknown_64_);
                func_ov002_02157ce0((char*)&var0.unknown_64_);
                var0.unknown_64_.unknown_0_ = arg0->unknown_1c26_;
                var0.unknown_64_.unknown_2_ = arg0->unknown_1c20_;
                var0.unknown_64_.unknown_3_ = 1;
                var0.unknown_64_.unknown_4_[0] = arg0->unknown_1c21_;
                func_ov002_021536e0(&var0.unknown_4_);
                var0.unknown_4_ = var1;
                var55 = func_ov002_021536ec(&var0.unknown_4_, &var0.unknown_64_, var55);
            }
            if (arg0->unknown_1c26_ == 0xa2) {
                arg0->unknown_1c28_ = 0x754c;
            } else if (arg0->unknown_1c26_ == 0xa4) {
                arg0->unknown_1c28_ = 0x754b;
            }
            arg0->unknown_1c2a_ = -1;
            if (var55 != 0) {
                arg0->unknown_248a_ = 1;
                if (arg0->unknown_1c26_ == 0xa2) {
                    arg0->unknown_2488_ = 0x754d;
                    arg0->unknown_248c_ = 1;
                } else if (arg0->unknown_1c26_ == 0xa4) {
                    arg0->unknown_2488_ = 0x232c;
                    arg0->unknown_248c_ = 1;
                }
                ConsumeCounter02048350((struct Obj02048350*)comb, entry->lo8);
                if (LinkSession_IsActive(checkPtr) != 0) {
                    func_ov017_021c9e00(p->actor, 0, 0, 1);
                }
            } else {
                arg0->unknown_248a_ = 1;
                arg0->unknown_2488_ = 0x232b;
            }
        } else {
            arg0->unknown_1c2a_ = -1;
            arg0->unknown_248a_ = 1;
            arg0->unknown_2488_ = 0x232b;
        }
        p->timer = 0;
        if (flagB != 0) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
            p->state = ST(0x26);
            p->nextState = ST(0x2b);
            if (p->command == 0xd7) {
                p->state = ST(0x2b);
            }
        } else if (flag1c == 0) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
            p->state = ST(0x26);
            p->nextState = ST(0x11);
        }
    } else if (arg0->unknown_1bb8_ == ST(7)) {
        arg0->unknown_2522_ = 0;
        arg0->unknown_2523_ = 0;
        memset(arg0->unknown_2524_, 0, 0xc);
        int var57 = 0;
        arg0->unknown_2530_ = var57;
        arg0->unknown_248a_ = 1;
        arg0->unknown_2488_ = -1;
        arg0->unknown_1c2a_ = -1;
        func_ov002_02157ce0((char*)&var0.unknown_28_);
        func_ov002_02157ce0((char*)&var0.unknown_28_);
        var0.unknown_28_.unknown_0_ = arg0->unknown_1c26_;
        var0.unknown_28_.unknown_2_ = arg0->unknown_1c20_;
        var0.unknown_28_.unknown_3_ = 1;
        var0.unknown_28_.unknown_4_[0] = arg0->unknown_1c21_;
        struct Struct_ov002_02157634_8* var58 = (struct Struct_ov002_02157634_8*)func_02079e2c(var1, arg0->unknown_1c26_);
        if (var58 != 0 && (var58->unknown_9_2_ & 1)) {
            func_ov016_0218b5c0(0, -1);
            func_ov002_021536e0(&var0.unknown_0_);
            var0.unknown_0_ = var1;
            var57 = func_ov002_021536ec(&var0.unknown_0_, &var0.unknown_28_, 0);
        }
        int var59 = 0;
        struct Struct_ov002_02157634_3* var60 = var0.unknown_28_.unknown_8_;
        struct Struct_ov002_02157634_3* var61 = var0.unknown_28_.unknown_20_;
        int var62;
        for (var62 = 0; var62 < var0.unknown_28_.unknown_3_; var62++) {
            struct Struct_ov002_02157634_3* var63 = &var60[var62];
            struct Struct_ov002_02157634_3* var64;
            if (var63->unknown_4_ != 0 || (var64 = &var61[var62])->unknown_4_ != 0) {
                var59 = 1;
                break;
            }
        }
        if (var59) {
            func_ov002_0216c42c(arg0, &var0.unknown_28_, var58);
            arg0->unknown_1cc6_ = 0;
            arg0->unknown_1cc7_ = 1;
            func_ov002_02157ce0((char*)(arg0->unknown_1cc8_));
            memcpy(arg0->unknown_1cc8_, &var0.unknown_28_, 0x3c);
            arg0->unknown_1c28_ = -1;
            arg0->unknown_1c2a_ = -1;
            arg0->unknown_1bb8_ = ST(0x26);
            arg0->unknown_1bbc_ = ST(0x26);
            arg0->unknown_2488_ = -1;
            arg0->unknown_248a_ = 0;
            arg0->unknown_1c7a_ = 1;
            arg0->unknown_1c7b_ = 0x14;
            arg0->unknown_1c74_ = 0x1e;
            arg0->unknown_1bc0_ = 0;
            return;
        }
        if (p->command == 0xd1) {
            if (LinkSession_IsActive((int*)LinkSession_GetInstance()) != 0) {
                int ok = 1;
                int j;
                for (j = 0; j < p->excludeCount; j++) {
                    if (p->target == p->exclude[j]) {
                        ok = 0;
                    }
                }
                if (var65) {
                    func_ov016_0218b5c0(0, -1);
                    EnqueueEventTag34_021d27a0(1, p->actor, p->target);
                    SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
                    p->msgId = 0x7536;
                    p->msgId2 = -1;
                    p->state = ST(0x26);
                    p->nextState = ST(0x26);
                    p->prompt = -1;
                    p->showPrompt = 0;
                    p->waitMode = 1;
                    p->waitKind = 0xa;
                    p->wait = 0x12c;
                    p->timer = 0;
                    return;
                }
            }
            func_020e3428(func_020e2ff8(), 1);
            arg0->unknown_1c28_ = 0x7535;
            arg0->unknown_1c2a_ = -1;
            int var67 = 0;
            struct Struct_ov002_02157d40_17* var68 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)func_0200ff1c((GameState*)var2, arg0->unknown_1c21_);
            if (var68 != 0 && (*var68->unknown_130_ & 4)) {
                var67 = 1;
            }
            if (cured) {
                int* cp = (int*)LinkSession_GetInstance();
                TryClearFlags0x130_02048418((unsigned char*)target, 4);
                if (LinkSession_IsActive(cp) != 0) {
                    func_ov017_021c9e00(p->target, 0, 0, 1);
                }
                unsigned char* party = (unsigned char*)GameState_GetParty((GameState*)gs);
                f.tab = *(struct Table11*)&data_ov002_0216c992;
                int any = 0;
                int q;
                for (q = 0; q < 0xb; q++) {
                    if (q == 2 || q == 3 || q == 4) {
                        continue;
                    }
                    struct Struct_ov002_02157d40_15* var73 = &var68->unknown_150_->unknown_194_[(unsigned char)var72];
                    if (var73 == 0) {
                        continue;
                    }
                    if (var73->unknown_a_2_ == 0) {
                        continue;
                    }
                    func_0207c378(var70 + 0x1d4, var73->unknown_18_, 1, var73->unknown_8_0_);
                    func_02052d7c((void*)var68, var0.unknown_1c_.unknown_0_[var72], -1);
                    var71 = 1;
                }
                if (any) {
                    if (LinkSession_IsActive(cp) != 0) {
                        func_ov017_021c3fb4(p->target, 1);
                        func_ov017_021c4418(p->target, -1);
                    }
                    void* var74 = GetGameResources();
                    BackgroundLoader::GetInstance();
                    func_ov017_0218f5a4(var74, arg0->unknown_1c21_, 1, 0, 0);
                }
                arg0->unknown_2488_ = -1;
                arg0->unknown_248a_ = 0;
                var9 = 1;
            } else {
                arg0->unknown_2488_ = 0x232b;
                arg0->unknown_248a_ = 1;
            }
        } else {
            func_020e3428(func_020e2ff8(), 1);
            struct Struct_ov002_02157d40_17* var75 = (struct Struct_ov002_02157d40_17*)(Struct_ov002_02157d40*)((GameState*)var2)->GetPartyMemberByIndex(arg0->unknown_1c21_);
            if (var57 != 0) {
                if (arg0->unknown_1c26_ == 0x1e || arg0->unknown_1c26_ == 0x1f || arg0->unknown_1c26_ == 0x20 || arg0->unknown_1c26_ == 0x21) {
                    arg0->unknown_2488_ = 0x232c;
                    var9 = 1;
                } else if (arg0->unknown_1c26_ == 0x23) {
                    arg0->unknown_2488_ = 0x794b;
                    var9 = 1;
                } else if (arg0->unknown_1c26_ == 0x27 || arg0->unknown_1c26_ == 0x26) {
                    arg0->unknown_2488_ = 0x2336;
                    var9 = 1;
                }
            } else {
                int var76 = (*var75->unknown_130_ & 1) != 0;
                if (var76) {
                    if (arg0->unknown_1c26_ == 0x26) {
                        arg0->unknown_2488_ = 0x2337;
                        var9 = 1;
                    } else {
                        arg0->unknown_2488_ = 0x232b;
                    }
                } else {
                    arg0->unknown_1c28_ = 0x2333;
                    arg0->unknown_2488_ = 0x2334;
                }
            }
        }
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
        p->state = ST(0x26);
        p->nextState = ST(0x11);
        p->timer = 0;
    }
    if (flagA != 0) {
        ConsumeCounter02048350((struct Obj02048350*)comb, entryA->lo8);
        if (LinkSession_IsActive(checkPtr) != 0) {
            func_ov017_021c9e00(p->actor, 0, 0, 1);
        }
    }
}
