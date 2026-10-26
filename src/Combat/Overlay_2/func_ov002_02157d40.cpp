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
extern "C" void func_020474a8(void* obj, int a, int b, char* buf);
extern "C" GameObject* func_0200ff94(GameState* battleStruct, int combatantId);
#else
#define RG(u, j) (u)
#define FMT(a, b, c, d) MessageSystem_FormatText(a, b, c, d, 0xe3, 0, 1)
#define ST(x) (x)
#endif
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct TableEntry {
    char* name;
    int unk4;
    unsigned int lo8 : 8;
    unsigned int b8 : 2;
    unsigned int b10 : 2;
    unsigned int rest : 20;
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
struct GameState;

struct Container020e0310;
struct StoreStruct;
struct Struct_ov002_02157d40_3;
struct Struct020a8170 {
    char pad[0xc];
    unsigned short count;
};
struct Struct0201bc94;
struct Struct_ov002_02157d40_5;
struct Obj02046574;
struct SePlayer;
struct Struct_ov002_02157d40_8;
struct List02046a3c;
struct Node02046a3c;
struct Struct_ov002_02157d40_11;
struct Struct_ov002_02157d40_12;
struct WhistleTask;
struct Struct_02001a40;

extern "C" void* __clear(void* dst, int count);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* func_020e2ff8(void);
extern "C" void* func_02079e2c(char* p, int key);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int GameObject_GetPartyMemberLevel(void* p);
extern "C" void func_020465f0(unsigned char* p, int a, unsigned char b);
extern "C" void func_ov017_021c2b28(void* p, unsigned char a, unsigned char b);
extern "C" void func_020e3428(void* p, int flag);
extern "C" int ZoneId_IsGrotto(int v);
extern "C" int ZoneId_IsMainGrottoFloor(int v);
extern "C" void func_020541a4(struct Struct_ov002_02157d40_5* p, unsigned char b);
extern "C" void func_020465c0(struct StoreStruct* p, int a, int b);
extern "C" int LinkSession_IsActive(int* p);
void* LoadFileIntoMemory(const char* path, void* buf, unsigned int* outSize);
extern "C" void func_02048418(unsigned char* p, unsigned short mask);
extern "C" void func_020a8170(struct Struct020a8170* p);
extern "C" int GameState_GetPartyOrder(char* dst, void* src);
extern "C" int func_0202663c(unsigned char* p);
extern "C" void func_02046a3c(struct List02046a3c* list, struct Node02046a3c* node);
extern "C" void Text_Append(char* dst, const char* src);
extern "C" void MapDisplay_ClearRedChests(char* p);
extern "C" void FieldTask_InitWhistle(struct WhistleTask* p);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void ResourceScriptEntry_Init(void* p);
extern "C" void func_02048350(struct Struct_ov002_02157d40_8* p, int a);
extern "C" void func_ov002_02157ce0(char* p);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* p, int a, char* s);
extern "C" int func_02026a28(struct Struct_ov002_02157d40_11* p);
extern "C" int func_02026abc(struct Struct_ov002_02157d40_12* p);
extern "C" void func_ov017_021c2688(unsigned char* p);
extern "C" void func_02026678(char* p);
extern "C" int func_0201bc94(struct Struct0201bc94* p);
extern "C" void func_ov017_021d27a0(int, int, int);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_ov017_021acd30(char* p, unsigned char a, unsigned char b, unsigned char c);
extern "C" int func_02026a78(char* p);
extern "C" void SePlayer_Play(struct SePlayer* p, int a, int b);
struct GameObject;
extern "C" void func_020e4c74(void*, GameObject*);
extern "C" void NameText_InitFromPartyMember(void* p, int a);
extern "C" int func_02048448(struct Struct_ov002_02157d40_3* p, int a);

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void* memset(void* dst, int v, unsigned int n);
extern "C" int sprintf(char* buf, const char* fmt, ...);


extern "C" int func_02026780(void* list, void* buf, unsigned int size);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void func_02046380(void* obj);
extern "C" void MessageSystem_FormatText(void* obj, int a, int b, char* buf, int c, int d, int e);
extern "C" void func_02052d7c(void* obj, signed char idx, int flag);
extern "C" void func_0207c378(void* p, short val, int flag, unsigned int nibble);

extern "C" void func_020a818c(void* p, void* allocator);
extern "C" void func_020a8304(void* p);
extern "C" void func_ov002_021536e0(void* p);
extern "C" int func_ov002_021536ec(void* a, void* b, int c);
extern "C" void func_ov002_0216c42c(void* ctx, void* buf, void* entry);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_0218f5a4(void* obj, int id, int b, int c, int d);
extern "C" int func_ov017_0219ff58(int a, int b, int c, int d);
extern "C" int func_ov017_021ab860(signed char a);
extern "C" void func_ov017_021c12fc(void* a, int b, int c);
static inline short* inline_ov002_02157d40(char* obj) {
    int* list = *(int**)(obj + 0x3000 + RG(0x71c, 0x50c));
    return (short*)((char*)list + 0x22);
}
extern "C" void func_ov017_021c3fb4(signed char a, int b);
extern "C" void func_ov017_021c4418(signed char a, int b);
extern "C" void func_ov017_021c9e00(signed char a, int b, int c, int d);

extern int g_sePlayer;
extern unsigned char data_ov002_0216c992;
extern int data_ov002_0216cf51;
extern int g_fileLoadBuffer;
extern int data_ov002_0216cf66;

struct Struct_ov002_02157d40_14 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};
struct Struct_ov002_02157d40_15 {
    int unk0;
    int unk4;
    unsigned int lo4 : 4;
    unsigned int unknown_8_4_ : 14;
    unsigned int on : 1;
    unsigned int rest : 13;
    int unkc;
    int unk10;
    int unknown_14_;
    short value;
    short pad1a;
    int unknown_1c_;
};
struct Struct_ov002_02157d40_16 {
    char pad0[0x138];
    int unknown_138_[0x17];
    struct Struct_ov002_02157d40_15 slots[11];
    char unknown_2f4_[0x277];
    struct Struct_ov002_02157d40_14 status;
    char unknown_56c_[RG(0x3e4, 0x34c)];
    int level;
};
struct Unit {
    unsigned short flags;
    short unk2;
    short id;
    char pad6[0x12a];
    int* status;
    char* name;
    char unknown_138_[RG(0x18, 0xc)];
    struct Struct_ov002_02157d40_16* ext;
};
struct PartyList {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};
struct BattleMenu {
    char pad0[8];
#if !defined(jpn)
    char obj8[0xc];
    char obj14[0xc];
#endif
    char container20[RG(0x880, 0x7fc)];
    char alloc8a0[RG(0x1318, 0x127c)];
    int state;
    int nextState;
    int timer;
    char pad1bc4[0xc];
    char* text;
    char* unknown_1bd4_;
    char unknown_1bd8_[0x48];
    signed char actor;
    signed char target;
    char unknown_1c22_[4];
    short command;
    short msgId;
    short msgId2;
    char pad1c2c[5];
    unsigned char dirty;
    char unknown_1c32_[RG(6, 2)];
    int unknown_1c38_;
    int unknown_1c3c_[0xe];
    int wait;
    char pad1c78[2];
    unsigned char waitMode;
    unsigned char waitKind;
    char pad1c7c[0x4a];
    unsigned char cc6;
    unsigned char cc7;
    char stateArray[0x3c];
    char pad1d04[RG(0x770, 0x6dc)];
    struct Struct020a8170* anim;
    char pad2478[0x10];
    short prompt;
    unsigned char showPrompt;
    unsigned char unknown_248b_;
    unsigned char unknown_248c_;
    char unknown_248d_[3];
    int countA;
    int countB;
    char unknown_2498_[0x8a];
    unsigned char unknown_2522_;
    unsigned char unknown_2523_;
    char unknown_2524_[0xc];
    int unknown_2530_;
};
struct StateSlot {
    unsigned char a[4];
    unsigned char active;
    unsigned char pad;
};
struct StateArray {
    short id;
    signed char actor;
    unsigned char count;
    signed char ids[4];
    struct StateSlot first[4];
    struct StateSlot second[4];
    int tail;
};
struct Struct_ov002_02157d40_20 {
    signed char v[11];
};
struct Struct_ov002_02157d40_21 {
    void* unknown_0_;
    void* unknown_4_;
    unsigned int size4c;
    unsigned int size50;
    unsigned char ids54[4];
    void* unknown_14_;
    unsigned char ids5c[4];
    struct Struct_ov002_02157d40_20 tab;
    struct StateArray unknown_28_;
    struct StateArray unknown_64_;
    char path[0x28];
    struct StateArray st10c;
    int obj148[0x15];
};

struct Struct_ov002_02157d40_22 {
    char pad0[RG(0x20, 0xe8)];
    signed char actor;
    signed char target;
    char unknown_22_[4];
    short command;
    short msgId;
    short msgId2;
};
static inline struct Struct_ov002_02157d40_22* inline_ov002_02157d40_2(struct BattleMenu* p) {
    struct Struct_ov002_02157d40_22* h = (struct Struct_ov002_02157d40_22*)((char*)p + RG(0x1c00, 0x1a00));
    return h;
}
static inline int inline_ov002_02157d40_3(struct Struct_ov002_02157d40_16* e) {
    return e->unknown_138_[e->level];
}

static inline int UnitId(struct Unit* u) { SDK_NULL_ASSERT(u); return u->id; }
static inline char* UnitName(struct Unit* u) { SDK_NULL_ASSERT(u); return u->name; }

enum Enum_ov002_02157d40 { Enum_ov002_02157d40_m1 = -1, Enum_ov002_02157d40_9004 = 0x232c, Enum_ov002_02157d40_9018 = 0x233a };

// USA: func_ov002_02157d40
extern "C" ARM void func_ov002_02157d40(struct BattleMenu* p) {
    struct Struct_ov002_02157d40_21 f;
    char* tbl;
    struct BattleStruct* gs = (BattleStruct*)GameState::GetInstance();
    int word = (int)((GameState*)gs)->GetResources();
    unsigned short* obj = (unsigned short*)Zone3D_GetInstance();
    ActionDataTables* var5 = func_020797dc();
    tbl = (char*)var5;
    struct TableEntry* var6 = (struct TableEntry*)func_02079e2c(tbl, p->command);
    #if defined(jpn)
    struct Unit* comb = (struct Unit*)(CombatantStruct*)func_0200ff94((GameState*)gs, p->actor);
#else
    struct Unit* comb = (struct Unit*)(CombatantStruct*)func_0200ff1c((GameState*)gs, p->actor);
#endif
    int* checkPtr = (int*)LinkSession_GetInstance();
    int flagA = 0;
    int var10;
    bool var11;

    if (p->state == ST(0x11)) {

        p->msgId = 0x232d;
        p->msgId2 = -1;
        var10 = 0;
        var11 = 0;
        if (p->command == 0xd7) {
            p->msgId = 0x233b;
        }
        if (func_02048448((struct Struct_ov002_02157d40_3*)comb, (unsigned short)var6->lo8) == 0) {
            p->msgId = 0x232f;
            p->msgId2 = -1;
            p->showPrompt = 0;
            p->prompt = -1;
            p->state = ST(0x26);
            p->nextState = ST(0x11);
            return;
        }
        if (p->command == 0xd7) {
            flagA = 1;
            var10 = 1;
            char* ov = (char*)GetGameResources();
            *inline_ov002_02157d40(ov) = p->actor;
            func_ov017_021c12fc(ov, 1, 0);
        } else if (p->command == 0xd9) {
            flagA = 1;
            if (func_0201bc94((struct Struct0201bc94*)Zone3D_GetInstance()) != 0) {
                func_ov016_0218b5c0(0, -1);
                p->target = p->actor;
                p->msgId = 0x754a;
                var10 = 1;
                struct PartyList* party = (struct PartyList*)GameState_GetParty((GameState*)gs);
                for (int i = 0; i < party->count; i++) {
                    func_020541a4((struct Struct_ov002_02157d40_5*)(CombatantStruct*)((GameState*)gs)->GetPartyMemberByIndex(party->ids[i]), 0);
                }
            } else {
                p->msgId = 0x754e;
                p->showPrompt = 1;
                p->prompt = 0x754f;
                flagA = 0;
            }
        } else if (p->command == 0xcd) {
            inline_ov002_02157d40_2(p)->msgId2 = -1;
            p->showPrompt = 1;
            int r = func_ov017_021ab860(p->actor);
            if (r == 0) {
                p->prompt = 0x232b;
            } else if (r == 1) {
                p->prompt = 0x2338;
            } else if (r == 3) {
                p->msgId = 0x233c;
                p->target = p->actor;
                var10 = 1;
                p->showPrompt = 0;
                flagA = 1;
                p->prompt = -1;
            }
        } else if (p->command == 0x1e || p->command == 0x1f || p->command == 0x20 || p->command == 0x21 || p->command == 0x23 || p->command == 0x26 || p->command == 0x27) {
            p->state = ST(7);
            var11 = 1;
        } else if (p->command == 0x22 || p->command == 0x310) {
            func_ov002_02157ce0((char*)&f.st10c);
            func_ov002_02157ce0((char*)&f.st10c);
            int res = 0;
            struct TableEntry* entry = (struct TableEntry*)func_02079e2c(tbl, p->command);
            if (entry != 0) {
                __clear(f.ids5c, 4);
                int n = GameState_GetPartyOrder((char*)gs, f.ids5c);
                if (entry->b10 & 1) {
                    func_ov016_0218b5c0(0, -1);
                    f.st10c.id = p->command;
                    f.st10c.actor = p->actor;
                    f.st10c.count = n;
                    for (int i = 0; i < n; i++) {
                        f.st10c.ids[i] = f.ids5c[i];
                    }
                    func_ov002_021536e0(&f.unknown_14_);
                    f.unknown_14_ = tbl;
                    res = func_ov002_021536ec(&f.unknown_14_, &f.st10c, 0);
                }
                int found = 0;
                struct StateSlot* first = f.st10c.first;
                struct StateSlot* second = f.st10c.second;
                int i;
                for (i = 0; i < f.st10c.count; i++) {
                    struct StateSlot* a = &first[i];
                    struct StateSlot* b;
                    if (a->active != 0 || (b = &second[i])->active != 0) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    func_ov002_0216c42c(p, &f.st10c, entry);
                    p->cc6 = 0;
                    p->cc7 = 1;
                    func_ov002_02157ce0((char*)(p->stateArray));
                    memcpy(p->stateArray, &f.st10c, 0x3c);
                    p->msgId = -1;
                    p->msgId2 = -1;
                    p->state = ST(0x26);
                    p->nextState = ST(0x26);
                    p->prompt = -1;
                    p->showPrompt = 0;
                    p->waitMode = 1;
                    p->waitKind = 0x14;
                    p->wait = 0x1e;
                    p->timer = 0;
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
                        Enum_ov002_02157d40 key;
                        if (slots[i].a[0] == 3) {
                            key = Enum_ov002_02157d40_9004;
                        } else {
                            key = Enum_ov002_02157d40_9018;
                        }
                        if (key < 0) {
                            continue;
                        }
                        struct Unit* target = (struct Unit*)(CombatantStruct*)func_0200ff1c((GameState*)gs, f.st10c.ids[i]);
                        if (target == 0) {
                            continue;
                        }
                        func_02046380(msg);
                        MessageSystem_SetStringArgument((struct Obj02046574*)msg, 2, UnitName(target));
#if !defined(jpn)
                        NameText_InitFromPartyMember(p->obj14, f.st10c.ids[i]);
                        *(void**)(msg + 0x10) = p->obj14;
#endif
                        func_020465c0((struct StoreStruct*)msg, 9, target->id);
                        FMT(msg, 0xc, KeyTable_Get((struct Container020e0310*)(p->container20), key), (char*)(tbl + RG(0x860, 0x700)));
                        Text_Append(p->text, (const char*)KeyTable_Get((struct Container020e0310*)(p->container20), 8));
                        Text_Append(p->text, (const char*)(tbl + RG(0x860, 0x700)));
                    }
                    func_02048350((struct Struct_ov002_02157d40_8*)comb, entry->lo8);
                    if (LinkSession_IsActive(checkPtr) != 0) {
                        func_ov017_021c9e00(p->actor, 0, 0, 1);
                    }
                } else {
                    struct CombatantStruct* unknown = (CombatantStruct*)((GameState*)gs)->GetLeader();
                    if (unknown != 0) {
                        MessageSystem_SetStringArgument((struct Obj02046574*)msg, 2, ((struct Unit*)unknown)->name);
#if !defined(jpn)
                        func_020e4c74(p->obj14, (GameObject*)(CombatantStruct*)((GameState*)gs)->GetLeader());
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
                    FMT(msg, 0xc, (int)(tbl + RG(0x860, 0x700)), p->text);
                }
                p->dirty = 1;
                memcpy(p->unknown_1bd4_, p->text, RG(0x960, 0x800));
                p->prompt = -1;
                p->showPrompt = 0;
            }
        } else if (p->command == 0xca) {
            if (func_ov017_0219ff58(word, 1, 0, 0) != 0) {
                var10 = 1;
                func_ov017_021acd30((char*)word, 0, 0, 0);
            } else {
                ((SafeAllocator*)p->alloc8a0)->Reset();
                p->anim = (struct Struct020a8170*)((SafeAllocator*)p->alloc8a0)->Allocate(0x10);
                func_020a8170(p->anim);
                func_020a818c(p->anim, p->alloc8a0);
                func_020a8304(p->anim);
                if (p->anim->count == 0) {
                    p->msgId2 = -1;
                    p->showPrompt = 1;
                    p->prompt = 0x2338;
                    ((SafeAllocator*)p->alloc8a0)->Reset();
                    p->anim = 0;
                } else {
                    p->state = ST(0x14);
                    p->timer = 0;
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
                func_02046a3c((struct List02046a3c*)list, (struct Node02046a3c*)node);
            }
            p->state = ST(0x2b);
            p->nextState = ST(0x2b);
            return;
        } else if (p->command == 0xd0) {
            unsigned char* msg = (unsigned char*)MessageSystem_GetInstance();
            memset(p->text, 0, RG(0x960, 0x800));
            tbl = p->text;
            struct Unit* actor = (struct Unit*)(CombatantStruct*)func_0200ff1c((GameState*)gs, p->actor);
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
                struct Unit* member = (struct Unit*)(CombatantStruct*)func_0200ff1c((GameState*)gs, f.ids54[k]);
                if (member == 0) {
                    continue;
                }
                struct Struct_ov002_02157d40_16* ext = member->ext;
                int busy;
                if (ext != 0) {
                    busy = ext->status.lo != 0;
                } else {
                    busy = 0;
                }
                if (busy) {
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
                    int diff = *total - inline_ov002_02157d40_3(member->ext);
                    if (diff <= 0) {
                        key = 0x753a;
                    } else {
                        func_020465c0((struct StoreStruct*)msg, 0, diff);
                        func_020465f0(msg, 0, 0);
                        key = 0x7538;
                    }
                }
                memset(tbl + RG(0x860, 0x700), 0, 0x100);
                FMT(msg, 0xc, KeyTable_Get((struct Container020e0310*)(p->container20), key), (char*)(tbl + RG(0x860, 0x700)));
                Text_Append(p->text, (const char*)KeyTable_Get((struct Container020e0310*)(p->container20), 8));
                Text_Append(p->text, (const char*)(tbl + RG(0x860, 0x700)));
            }
            p->dirty = 1;
            memcpy(p->unknown_1bd4_, p->text, RG(0x960, 0x800));
            p->prompt = -1;
            p->showPrompt = 0;
            var10 = 1;
        } else if (p->command == 0xd1) {
            p->state = ST(7);
            var11 = 1;
        } else if (p->command == 0xd2) {
            p->unknown_248b_ = 1;
            unsigned char* list;
            unsigned char* node = *(unsigned char**)((unsigned char*)word + RG(0x3ba8, 0x3988));
            list = *(unsigned char**)((unsigned char*)word + RG(0x36fc, 0x34ec));
            func_ov017_021c2688(node);
            node[0xc] = p->actor;
            func_02046a3c((struct List02046a3c*)list, (struct Node02046a3c*)node);
            p->state = ST(0x2b);
            p->nextState = ST(0x2b);
            return;
        } else if (p->command == 0xd5) {
            unsigned char* rec = *(unsigned char**)((unsigned char*)GetGameResources() + RG(0x36d0, 0x34c0));
            p->msgId = 0x7543;
            flagA = 1;
            if (LinkSession_IsGuest(checkPtr) != 0 && ZoneId_IsGrotto(*obj) == 0) {
                p->showPrompt = 1;
                p->prompt = 0x7548;
                flagA = 0;
            } else if (func_0202663c(rec) == 0) {
                func_ov016_0218b5c0(0, -1);
                p->target = p->actor;
                func_02026678((char*)rec);
            } else {
                p->showPrompt = 1;
                p->prompt = 0x232b;
                p->state = ST(0x26);
                p->nextState = ST(0x11);
                flagA = 0;
            }
            var10 = 1;
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
                } else if (func_0202663c(rec) != 0) {
                    p->countA = func_02026a28((struct Struct_ov002_02157d40_11*)rec);
                    p->countB = func_02026abc((struct Struct_ov002_02157d40_12*)rec);
                } else {
                    MapDisplay_ClearRedChests((char*)rec);
                    BackgroundLoader::AddLockGlobal();
                    f.size4c = 0;
                    void* data = LoadFileIntoMemory((const char*)&data_ov002_0216cf66, &g_fileLoadBuffer, &f.size4c);
                    if (func_02026780(rec, data, f.size4c) == 0) {
                        ok = 0;
                    } else {
                        func_02026a78((char*)rec);
                        p->countA = func_02026a28((struct Struct_ov002_02157d40_11*)rec);
                        p->countB = func_02026abc((struct Struct_ov002_02157d40_12*)rec);
                    }
                    BackgroundLoader::RemoveLockGlobal();
                }
                if (ok) {
                    if (p->countA > 0 && p->countB == 0) {
                        p->prompt = 0x7546;
                        var10 = 1;
                    } else if (*(int*)&p->countA > 0) {
                        p->prompt = 0x7545;
                        var10 = 1;
                    } else {
                        p->prompt = 0x7547;
                    }
                } else {
                    p->prompt = 0x232b;
                    flagA = 0;
                }
            }
            p->state = ST(0x26);
            p->nextState = ST(0x26);
        } else if (p->command == 0xce) {
            unsigned char* ov = (unsigned char*)GetGameResources();
            unsigned char* list;
            unsigned char* node = *(unsigned char**)(ov + RG(0x3bb0, 0x3990));
            list = *(unsigned char**)(ov + RG(0x36fc, 0x34ec));
            if (node[2] == 0) {
                func_ov017_021c2b28(node, 0, comb->id);
                func_02046a3c((struct List02046a3c*)list, (struct Node02046a3c*)node);
            }
            p->msgId = 0x233c;
            flagA = 1;
            var10 = 1;
            p->target = p->actor;
        } else if (p->command == 0xa2 || p->command == 0xa4) {
            p->target = p->actor;
            int res = 0;
            struct TableEntry* entry = (struct TableEntry*)func_02079e2c(tbl, p->command);
            if (entry != 0 && (entry->b10 & 1)) {
                func_ov016_0218b5c0(res, -1);
                func_ov002_02157ce0((char*)&f.unknown_64_);
                func_ov002_02157ce0((char*)&f.unknown_64_);
                f.unknown_64_.id = p->command;
                f.unknown_64_.actor = p->actor;
                f.unknown_64_.count = 1;
                f.unknown_64_.ids[0] = p->target;
                func_ov002_021536e0(&f.unknown_4_);
                f.unknown_4_ = tbl;
                res = func_ov002_021536ec(&f.unknown_4_, &f.unknown_64_, res);
            }
            if (p->command == 0xa2) {
                p->msgId = 0x754c;
            } else if (p->command == 0xa4) {
                p->msgId = 0x754b;
            }
            p->msgId2 = -1;
            if (res != 0) {
                p->showPrompt = 1;
                if (p->command == 0xa2) {
                    p->prompt = 0x754d;
                    p->unknown_248c_ = 1;
                } else if (p->command == 0xa4) {
                    p->prompt = 0x232c;
                    p->unknown_248c_ = 1;
                }
                func_02048350((struct Struct_ov002_02157d40_8*)comb, entry->lo8);
                if (LinkSession_IsActive(checkPtr) != 0) {
                    func_ov017_021c9e00(p->actor, 0, 0, 1);
                }
            } else {
                p->showPrompt = 1;
                p->prompt = 0x232b;
            }
        } else {
            p->msgId2 = -1;
            p->showPrompt = 1;
            p->prompt = 0x232b;
        }
        p->timer = 0;
        if (var10 != 0) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
            p->state = ST(0x26);
            p->nextState = ST(0x2b);
            if (p->command == 0xd7) {
                p->state = ST(0x2b);
            }
        } else if (var11 == 0) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
            p->state = ST(0x26);
            p->nextState = ST(0x11);
        }
    } else if (p->state == ST(7)) {
        p->unknown_2522_ = 0;
        p->unknown_2523_ = 0;
        memset(p->unknown_2524_, 0, 0xc);
        int res = 0;
        p->unknown_2530_ = res;
        p->showPrompt = 1;
        p->prompt = -1;
        p->msgId2 = -1;
        func_ov002_02157ce0((char*)&f.unknown_28_);
        func_ov002_02157ce0((char*)&f.unknown_28_);
        f.unknown_28_.id = p->command;
        f.unknown_28_.actor = p->actor;
        f.unknown_28_.count = 1;
        f.unknown_28_.ids[0] = p->target;
        struct TableEntry* entry = (struct TableEntry*)func_02079e2c(tbl, p->command);
        if (entry != 0 && (entry->b10 & 1)) {
            func_ov016_0218b5c0(0, -1);
            func_ov002_021536e0(&f.unknown_0_);
            f.unknown_0_ = tbl;
            res = func_ov002_021536ec(&f.unknown_0_, &f.unknown_28_, 0);
        }
        int found = 0;
        struct StateSlot* first = f.unknown_28_.first;
        struct StateSlot* second = f.unknown_28_.second;
        int i;
        for (i = 0; i < f.unknown_28_.count; i++) {
            struct StateSlot* a = &first[i];
            struct StateSlot* b;
            if (a->active != 0 || (b = &second[i])->active != 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            func_ov002_0216c42c(p, &f.unknown_28_, entry);
            p->cc6 = 0;
            p->cc7 = 1;
            func_ov002_02157ce0((char*)(p->stateArray));
            memcpy(p->stateArray, &f.unknown_28_, 0x3c);
            p->msgId = -1;
            p->msgId2 = -1;
            p->state = ST(0x26);
            p->nextState = ST(0x26);
            p->prompt = -1;
            p->showPrompt = 0;
            p->waitMode = 1;
            p->waitKind = 0x14;
            p->wait = 0x1e;
            p->timer = 0;
            return;
        }
        if (p->command == 0xd1) {
            if (LinkSession_IsActive((int*)LinkSession_GetInstance()) != 0) {
                int ok = 1;
                int j;
                for (j = 0; j < p->unknown_1c38_; j++) {
                    if (p->target == p->unknown_1c3c_[j]) {
                        ok = 0;
                    }
                }
                if (ok) {
                    func_ov016_0218b5c0(0, -1);
                    func_ov017_021d27a0(1, p->actor, p->target);
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
            p->msgId = 0x7535;
            p->msgId2 = -1;
            int var67 = 0;
            struct Unit* target = (struct Unit*)(CombatantStruct*)func_0200ff1c((GameState*)gs, p->target);
            if (target != 0 && (*target->status & 4)) {
                var67 = 1;
            }
            if (var67) {
                int* cp = (int*)LinkSession_GetInstance();
                func_02048418((unsigned char*)target, 4);
                if (LinkSession_IsActive(cp) != 0) {
                    func_ov017_021c9e00(p->target, 0, 0, 1);
                }
                unsigned char* party = (unsigned char*)GameState_GetParty((GameState*)gs);
                f.tab = *(struct Struct_ov002_02157d40_20*)&data_ov002_0216c992;
                int any = 0;
                int q;
                for (q = 0; q < 0xb; q++) {
                    if (q == 2 || q == 3 || q == 4) {
                        continue;
                    }
                    struct Struct_ov002_02157d40_15* slot = &target->ext->slots[(unsigned char)q];
                    if (slot == 0) {
                        continue;
                    }
                    if (slot->on == 0) {
                        continue;
                    }
                    func_0207c378(party + 0x1d4, slot->value, 1, slot->lo4);
                    func_02052d7c((void*)target, f.tab.v[q], -1);
                    any = 1;
                }
                if (any) {
                    if (LinkSession_IsActive(cp) != 0) {
                        func_ov017_021c3fb4(p->target, 1);
                        func_ov017_021c4418(p->target, -1);
                    }
                    void* ov = GetGameResources();
                    BackgroundLoader::GetInstance();
                    func_ov017_0218f5a4(ov, p->target, 1, 0, 0);
                }
                p->prompt = -1;
                p->showPrompt = 0;
                flagA = 1;
            } else {
                p->prompt = 0x232b;
                p->showPrompt = 1;
            }
        } else {
            func_020e3428(func_020e2ff8(), 1);
            struct Unit* member = (struct Unit*)(CombatantStruct*)((GameState*)gs)->GetPartyMemberByIndex(p->target);
            if (res != 0) {
                if (p->command == 0x1e || p->command == 0x1f || p->command == 0x20 || p->command == 0x21) {
                    p->prompt = 0x232c;
                    flagA = 1;
                } else if (p->command == 0x23) {
                    p->prompt = 0x794b;
                    flagA = 1;
                } else if (p->command == 0x27 || p->command == 0x26) {
                    p->prompt = 0x2336;
                    flagA = 1;
                }
            } else {
                int var76 = (*member->status & 1) != 0;
                if (var76) {
                    if (p->command == 0x26) {
                        p->prompt = 0x2337;
                        flagA = 1;
                    } else {
                        p->prompt = 0x232b;
                    }
                } else {
                    p->msgId = 0x2333;
                    p->prompt = 0x2334;
                }
            }
        }
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
        p->state = ST(0x26);
        p->nextState = ST(0x11);
        p->timer = 0;
    }
    if (flagA != 0) {
        func_02048350((struct Struct_ov002_02157d40_8*)comb, var6->lo8);
        if (LinkSession_IsActive(checkPtr) != 0) {
            func_ov017_021c9e00(p->actor, 0, 0, 1);
        }
    }
}
