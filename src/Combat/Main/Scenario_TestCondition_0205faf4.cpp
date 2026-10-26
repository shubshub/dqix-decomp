#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
extern "C" int func_020e0484(void* list, void* alloc, const char* path, void* entries, unsigned short count, bool lock);
extern "C" int func_ov017_021b2718(void* obj);
extern const char* g_itemDataArchive;
static inline char* inline_0205faf4(void* state) {
    return (char*)state + 0x5c0c;
}
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};

struct Struct_0205faf4_20 {
    unsigned short unknown_0_;
    unsigned short p2;
    unsigned short p4;
    unsigned short p6;
    unsigned short p8;
    unsigned short pa;
    struct Struct_0205faf4_20* next;
};

extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void GameState_CollectPartyObjectIndices(GameState*, int*, int*);
extern "C" int MessageSystem_GetInstance(void);
extern "C" int func_020457e0(int);
struct Struct_0205faf4;
struct GameState;
struct Obj02086aec;
extern "C" short Party_CountItem(struct Obj02086aec* obj, int key);
struct PackedNibbleArray0206e120;
extern "C" int func_0206e120(struct PackedNibbleArray0206e120* obj, int index);
extern "C" int func_0206e31c(int unused, int index);
struct PackedNibbleArray0206e260;
extern "C" int func_0206e260(struct PackedNibbleArray0206e260* obj, int index);
extern "C" void* LinkSession_GetInstance(void* gs);
extern "C" int LinkSession_IsActive(int* obj);
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" int func_0206eb98(unsigned char* obj, int index);
extern "C" void __clear(void* buf, int count);
extern "C" void* func_02094d6c(void);
extern "C" int func_02096088(void* obj, int index);
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* base, int key);
struct Struct_0203e0a0;
extern "C" void* func_02040538(struct Struct_0203e0a0* p);
extern "C" int GameState_GetStoryStep(char* p);
extern "C" int GameState_GetProtagonistIndex(GameState*);
struct Base02010834;
extern "C" void GameState_GetPartyMemberIds(struct Base02010834* base, int index, int* out, int* outCount);

struct Struct_0205faf4_5 {
    int unknown_0_;
    unsigned int unknown_4_0_:10, base:10, unknown_6_4_:12;
    int unknown_8_;
    unsigned int unknown_c_0_:10, f0:10, f1:10;
    unsigned int f2:10, f3:10, f4:10;
    unsigned int unknown_14_0_:10;
};
extern "C" void* func_02053c6c(unsigned char* obj);
extern "C" unsigned char GameState_GetLeaderIndex(GameState*);
struct Struct_0205faf4_6 { char pad[8]; unsigned int unknown_8_0_:18, flag:1; };
struct Struct_0205faf4_7;
struct Struct_0205faf4_8 { unsigned int unknown_0_0_:9, unknown_1_1_:1, unknown_1_2_:5, unknown_1_7_:1, unknown_2_0_:2, unknown_2_2_:1; };
extern "C" struct Struct_0205faf4_8* func_02096134(struct Struct_0205faf4_7* t, int id);
extern "C" int func_0206474c(struct BattleStruct* obj, int a1, int a2);
extern "C" int func_0206483c(struct BattleStruct* obj, char* name);
extern "C" void* func_02064904(void* obj, int id, unsigned int arg2);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void* func_0207c5f8(unsigned char* obj, unsigned int index);
extern "C" short func_0207c638(void* base, unsigned int index);
struct Struct_0205faf4_9 { int w[6]; };
struct Struct_0205faf4_10 { int f0; int f4; unsigned int unknown_8_0_:9, level:3; };
extern "C" void* ItemTable_Construct(void* obj);
extern "C" void ItemTable_Init(void* obj);
extern "C" struct Struct_0205faf4_10* func_020deb24(struct Struct_0205faf4_9* list, int index);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" int ItemTable_LoadIds(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);
extern "C" int func_020cf0fc(int out);
extern "C" void* Zone3D_GetInstance(void);
struct ReadClearByte02098ee8;
extern "C" unsigned char func_02098ee8(struct ReadClearByte02098ee8* s);
extern "C" int func_02011b50(void* obj, int mask);
struct Struct_0205faf4_13;
extern "C" int func_0206e2dc(struct Struct_0205faf4_13* obj, int index);
extern "C" void* GameState_GetZoneTransition(GameState*);

extern AllocatorUnion g_mainAllocator;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;

struct ExtraStruct0205faf4 {
    int v[16];
};
struct Struct_0205faf4_15 { int f0; int f4; int f8; int fc; };
struct Struct_0205faf4_16 { unsigned int unknown_0_0_:12, a:4, b:5; };
struct Struct_0205faf4_17 { char pad[0x56b]; unsigned char unknown_56b_0_:4, hi:4; };

#define NIB56B(c) (*(struct Struct_0205faf4_17**)((char*)(c) + REGION_VALUE(0x144, 0x150)))
#define HasNibble56b(c) (NIB56B(c) != NULL ? (NIB56B(c)->hi != 0 ? 1 : 0) : 0)
#define GetNibble56b(c) (NIB56B(c) != NULL ? NIB56B(c)->hi : 0)

static inline int inline_0205faf4_2(void* arg0) {
    return *(unsigned short*)((char*)arg0 + 4);
}
static inline char* inline_0205faf4_3(void* bs) {
    return (char*)bs + REGION_VALUE(0x543c, 0x569c);
}
struct Struct_0205faf4_18 { int unknown_0_0_:19, v:11; };
static inline struct Struct_0205faf4_6* inline_0205faf4_4(struct CombatantStruct* c, unsigned char i) {
    return (struct Struct_0205faf4_6*)(*(char**)((char*)c + REGION_VALUE(0x144, 0x150)) + 0x194 + i * 0x20);
}

struct Struct_0205faf4_19 { char pad0[0xb3c]; unsigned int fb3c; char pad1[0xb4c - 0xb40]; unsigned int fb4c; };
static inline struct Struct_0205faf4_19* inline_0205faf4_5(void* p) {
    return (struct Struct_0205faf4_19*)((char*)p + REGION_VALUE(0x1860, 0x1840));
}
#define FLAGS1840(p) inline_0205faf4_5(p)
#define OBJB ((unsigned char*)obj)
#define CU16(o) (*(unsigned short*)((char*)cmd + (o)))
#define CS16(o) (*(short*)((char*)cmd + (o)))
#define EW(o) (*(int*)((char*)extra + (o)))
#define STAT130(c) (*(void**)((char*)(c) + 0x130))
#define SUB150(c) (*(char**)((char*)(c) + REGION_VALUE(0x144, 0x150)))

static inline int inline_0205faf4_6(struct CombatantStruct* c) { SDK_NULL_ASSERT(c); return *(int*)(SUB150(c) + REGION_VALUE(0x8b8, 0x950)); }
static inline int inline_0205faf4_7(struct ExtraStruct0205faf4* extra) { SDK_NULL_ASSERT(extra); return EW(0x24); }

// Main, originally func_0205faf4 (USA 0x0205faf4, EUR 0x0205fb04, JPN 0x02060de0)
extern "C" ARM int Scenario_TestCondition(struct BattleStruct* obj, void* cmd, struct ExtraStruct0205faf4* extra) {
    unsigned short var0 = *(unsigned short*)cmd;
    switch (var0) {
    case 0:
        return Scenario_TestFlag((int)obj, OBJB + 0x8c, CU16(2));
    case 1:
        return !Scenario_TestFlag((int)obj, OBJB + 0x8c, CU16(2));
    case 2: {
        unsigned char id = *(OBJB + 0x332);
        return Scenario_TestFlag((int)obj, OBJB + id * 0x1c + 3, CU16(2));
    }
    case 3: {
        unsigned char id = *(OBJB + 0x332);
        return !Scenario_TestFlag((int)obj, OBJB + id * 0x1c + 3, CU16(2));
    }
    case 4: {
        unsigned char id = *(OBJB + 0x332);
        return Scenario_TestFlag((int)obj, OBJB + id * 0x1c + 0x10, CU16(2));
    }
    case 5: {
        unsigned char id = *(OBJB + 0x332);
        return !Scenario_TestFlag((int)obj, OBJB + id * 0x1c + 0x10, CU16(2));
    }
    case 6:
        return CU16(2) == EW(0);
    case 7:
        return CU16(2) == EW(4);
    case 8:
        return CU16(2) == EW(8);
    case 9:
        return CU16(2) == EW(0xc);
    case 10:
        return CU16(2) == EW(0x10);
    case 11:
        return CU16(2) == EW(0x14);
    case 12:
        return CU16(2) == EW(0x18);
    case 13: {
        int outList[4]; int outCount;
        GameState_CollectPartyObjectIndices((GameState*)(void*)GameState::GetInstance(), outList, &outCount);
        return CU16(2) <= outCount;
    }
    case 14: {
        int outList[4]; int outCount;
        GameState_CollectPartyObjectIndices((GameState*)(void*)GameState::GetInstance(), outList, &outCount);
        return CU16(2) >= outCount;
    }
    case 15: {
        int outList[4]; int outCount;
        GameState_CollectPartyObjectIndices((GameState*)(void*)GameState::GetInstance(), outList, &outCount);
        return CU16(2) == outCount;
    }
    case 16:
        return CU16(2) == func_020457e0(MessageSystem_GetInstance());
    case 17: {
        struct BattleStruct* bs = (struct BattleStruct*)(void*)GameState::GetInstance();
        if (CU16(2) == 1) {
            return !((GameState*)((struct Struct_0205faf4*)bs))->IsMorningDayOrEvening();
        }
        return ((GameState*)((struct Struct_0205faf4*)bs))->IsMorningDayOrEvening();
    }
    case 18:
        return Party_CountItem((struct Obj02086aec*)GameState_GetParty((GameState*)(void*)GameState::GetInstance()), CS16(2)) > 0;
    case 19:
        return Party_CountItem((struct Obj02086aec*)GameState_GetParty((GameState*)(void*)GameState::GetInstance()), CS16(2)) <= 0;
    case 20: {
        int result = 0;
        int match = func_0206e120((struct PackedNibbleArray0206e120*)obj, CU16(2)) == 2;
        if (match) {
            if (func_0206e31c((int)obj, CU16(2))) result = 1;
        }
        return result;
    }
    case 21: {
        if (func_0206e260((struct PackedNibbleArray0206e260*)obj, CU16(2))) {
            if (func_0206e31c((int)obj, CU16(2))) return 1;
        }
        return 0;
    }
    case 22: {
        int result = 0;
        int match = func_0206e120((struct PackedNibbleArray0206e120*)obj, CU16(2)) == 3;
        if (match) {
            if (func_0206e31c((int)obj, CU16(2))) result = 1;
        }
        return result;
    }
    case 23: {
        void* g = LinkSession_GetInstance((void*)GameState::GetInstance());
        int result = 0;
        switch (CU16(2)) {
        case 1:
            if (LinkSession_IsActive((int*)g)) result = 1;
            break;
        case 0:
            if (!LinkSession_IsActive((int*)g)) result = 1;
            break;
        case 2:
            if (LinkSession_IsActive((int*)g)) {
                if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
                    result = 1;
                    break;
                }
            }
            if (LinkSession_IsActive((int*)g) == 0) result = 1;
            break;
        case 3:
            if (LinkSession_IsActive((int*)g)) {
                if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g)) result = 1;
            }
            break;
        }
        return result;
    }
    case 25: {
        int result = 0;
        int match = func_0206e120((struct PackedNibbleArray0206e120*)obj, CU16(2)) == 1;
        if (match) {
            if (func_0206e31c((int)obj, CU16(2))) result = 1;
        }
        return result;
    }
    case 26:
        return func_0206eb98(OBJB, CU16(2));
    case 27:
        return !func_0206eb98(OBJB, CU16(2));
    case 28: {
        int result = 0;
        int match = func_0206e120((struct PackedNibbleArray0206e120*)obj, CU16(2)) == 0;
        if (match) {
            if (func_0206e31c((int)obj, CU16(2))) result = 1;
        }
        return result;
    }
    case 29:
        return CU16(4) == *(unsigned short*)((char*)extra + 0x1c) &&
               CU16(6) == *(unsigned short*)((char*)extra + 0x1e) &&
               CS16(2) == *(short*)((char*)extra + 0x28);
    case 30:
        return CU16(2) == EW(0x20);
    case 31:
        return CS16(2) == *((signed char*)(OBJB + 0x400) + 0x90);
    case 32: {
        int i;
        for (i = 0; i < 4; i++) {
            signed char c = ((signed char*)((int)cmd + 4))[i];
            if (c != 0 && c != ((signed char*)extra + i)[0x2a]) break;
        }
        return i == 4;
    }
    case 33: {
        unsigned char var24[4];
        __clear(var24, 4);
        signed char* p = (signed char*)cmd + 4;
        int i, j;
        for (i = 0; i < 4; i++) {
            signed char c = p[i];
            if (c == 0) continue;
            for (j = 0; j < 4; j++) {
                if (c == ((signed char*)extra + 0x2a)[j] && var24[j] == 0) {
                    var24[j] = 1;
                    break;
                }
            }
            if (j == 4) return 0;
        }
        return 1;
    }
    case 34: {
        void* p = GameState_GetParty((GameState*)(void*)GameState::GetInstance());
        unsigned short v = CU16(2);
        if (v != 0 && *((unsigned char*)p + 0xf7c) > 1) return 1;
        if (v == 0 && *((unsigned char*)p + 0xf7c) <= 1) return 1;
        return 0;
    }
    case 35:
        return CU16(2) == GameState_GetStoryStep((char*)(void*)GameState::GetInstance());
    case 36: {
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)((struct BattleStruct*)(void*)GameState::GetInstance()))->GetGameObjectByIndex(0);
        unsigned short v = CU16(2);
        if (v != 0 && inline_0205faf4_2(STAT130(c)) <= 0) return 1;
        if (v == 0 && inline_0205faf4_2(STAT130(c)) > 0) return 1;
        return 0;
    }
    case 37: {
        if (func_02096088(func_02094d6c(), CU16(2))) {
            if (func_0206e31c((int)obj, CU16(2))) return 1;
        }
        return 0;
    }
    case 38: {
        if (!func_02096088(func_02094d6c(), CU16(2))) {
            if (func_0206e31c((int)obj, CU16(2))) return 1;
        }
        return 0;
    }
    case 39:
        return Scenario_TestFlag((int)obj, OBJB + 0x8c, CU16(2) + 0x776);
    case 40:
        return !Scenario_TestFlag((int)obj, OBJB + 0x8c, CU16(2) + 0x776);
    case 41: {
        struct Struct_0205faf4_2 { int hi; int unknown_4_; int lo; };
        void* e = func_0203df78(func_0203cf4c(), EW(0));
        if (!e) return 0;
        void* base = func_02040538((struct Struct_0203e0a0*)e);
        if (!base) return 0;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)((struct BattleStruct*)(void*)GameState::GetInstance()))->GetLeader();
        struct Struct_0205faf4_2 k = *(struct Struct_0205faf4_2*)((char*)c + 0x44);
        int* node;
        for (node = *(int**)((char*)base + 0x40); node != NULL; node = (int*)node[5]) {
            if (k.hi < node[1] && k.lo < node[2] && k.hi > node[3] && k.lo > node[4]) return CU16(2) != 0;
        }
        return CU16(2) == 0;
    }
    case 42: {
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)((struct BattleStruct*)(void*)GameState::GetInstance()))->GetGameObjectByIndex(0);
        return CU16(2) == inline_0205faf4_6(c);
    }
    case 43: {
        char* w = inline_0205faf4_3((void*)GameState::GetInstance());
        return ((struct Struct_0205faf4_18*)(w + 4))->v == CU16(2);
    }
    case 44: {
        struct BattleStruct* bs = (struct BattleStruct*)(void*)GameState::GetInstance();
        int outList[4];
        int outCount;
        GameState_GetPartyMemberIds((struct Base02010834*)bs, GameState_GetProtagonistIndex((GameState*)bs), outList, &outCount);
        int i;
        for (i = 0; i < outCount; i++) {
            struct CombatantStruct* c = (CombatantStruct*)((GameState*)bs)->GetGameObjectByIndex(outList[i]);
            if (!c) continue;
            void* sub = STAT130(c);
            if (*(int*)sub & 1) continue;
            if (inline_0205faf4_2(sub) <= 0) continue;
            if (*(unsigned char*)(SUB150(c) + (unsigned char)CU16(2) + 0x464) >= CU16(4)) return 1;
        }
        return 0;
    }
    case 45: {
        struct Struct_0205faf4_5* p = (struct Struct_0205faf4_5*)SUB150((CombatantStruct*)((GameState*)((struct BattleStruct*)(void*)GameState::GetInstance()))->GetGameObjectByIndex(0));
        unsigned short var47[6];
        var47[0] = p->f0; var47[1] = p->f1; var47[2] = p->f2;
        var47[3] = p->f3; var47[4] = p->f4; var47[5] = p->unknown_14_0_;
        unsigned short idx = CU16(2);
        int v = var47[idx];
        int j;
        for (j = 0; j < 6; j++) {
            if (j == idx) continue;
            if (v < var47[j]) return 0;
        }
        return 1;
    }
    case 46: {
        struct Struct_0205faf4_5* p = (struct Struct_0205faf4_5*)SUB150((CombatantStruct*)((GameState*)((struct BattleStruct*)(void*)GameState::GetInstance()))->GetGameObjectByIndex(0));
        unsigned short var52 = p->base;
        int y = CU16(4);
        unsigned short z = CU16(2);
        if (CU16(6) != 0) {
            switch (z) {
            case 0: if (y >= (unsigned short)p->f0 - var52) return 1; break;
            case 1: if (y >= (unsigned short)p->f1 - var52) return 1; break;
            case 2: if (y >= (unsigned short)p->f2 - var52) return 1; break;
            case 3: if (y >= (unsigned short)p->f3 - var52) return 1; break;
            case 4: if (y >= (unsigned short)p->f4 - var52) return 1; break;
            case 5: if (y >= (unsigned short)p->unknown_14_0_ - var52) return 1; break;
            }
        } else {
            switch (z) {
            case 0: if (y < (unsigned short)p->f0 - var52) return 1; break;
            case 1: if (y < (unsigned short)p->f1 - var52) return 1; break;
            case 2: if (y < (unsigned short)p->f2 - var52) return 1; break;
            case 3: if (y < (unsigned short)p->f3 - var52) return 1; break;
            case 4: if (y < (unsigned short)p->f4 - var52) return 1; break;
            case 5: if (y < (unsigned short)p->unknown_14_0_ - var52) return 1; break;
            }
        }
        return 0;
    }
    case 47: {
        struct BattleStruct* bs = (struct BattleStruct*)(void*)GameState::GetInstance();
        struct CombatantStruct* c = (CombatantStruct*)func_0200ff1c((GameState*)bs, GameState_GetLeaderIndex((GameState*)bs));
        if (!c) return 0;
        int count = 0;
        int i;
        for (i = 0; i < 0xb; i++) {
            struct Struct_0205faf4_6* entry = inline_0205faf4_4(c, i);
            if (entry == NULL) continue;
            if (entry->flag) count++;
        }
        if (CU16(2) != 0) {
            if (count >= CU16(4)) return 1;
        } else if (count < CU16(4)) {
            return 1;
        }
        return 0;
    }
    case 48: {
        void* p = GameState_GetParty((GameState*)(void*)GameState::GetInstance());
        if (!p) return 0;
        return Party_CountItem((struct Obj02086aec*)p, CS16(2)) >= CU16(4) ? 1 : 0;
    }
    case 49: {
        struct BattleStruct* bs = (struct BattleStruct*)(void*)GameState::GetInstance();
        int outList[4];
        int outCount;
        GameState_GetPartyMemberIds((struct Base02010834*)bs, GameState_GetProtagonistIndex((GameState*)bs), outList, &outCount);
        int i;
        for (i = 0; i < outCount; i++) {
            struct CombatantStruct* c = (CombatantStruct*)func_0200ff1c((GameState*)bs, outList[i]);
            if (!c) continue;
            void* sub = STAT130(c);
            if (*(int*)sub & 1) continue;
            if (CU16(2) != inline_0205faf4_6(c)) continue;
            if (inline_0205faf4_2(sub) <= 0) continue;
            void* ptr = func_02053c6c((unsigned char*)c);
            if (!ptr) continue;
            if (*(unsigned short*)((char*)ptr + CU16(2) * 2 + 0x16c) >= CU16(4)) return 1;
        }
        return 0;
    }
    case 50:
    case 82: {
        struct BattleStruct* bs = (struct BattleStruct*)(void*)GameState::GetInstance();
        unsigned char* party = (unsigned char*)GameState_GetParty((GameState*)bs);
        int count = party[0xf7c];
        int i = 0;
        if (CU16(0) == 0x52) count = 1;
        for (; i < count; i++) {
            struct CombatantStruct* c;
            if (CU16(0) == 0x52) {
                c = (CombatantStruct*)((GameState*)bs)->GetProtagonist();
            } else {
                c = (CombatantStruct*)func_0200ff1c((GameState*)bs, *(party + i + 0xf78));
            }
            if (c == NULL) continue;
            if (*(int*)STAT130(c) & 1) continue;
            if (CU16(2) == 1) {
                if (CS16(4) > 0 && CS16(4) != *(short*)(SUB150(c) + 0x1ac)) continue;
                if (CS16(6) > 0 && CS16(6) != *(short*)(SUB150(c) + 0x1cc)) continue;
                if (CS16(8) > 0 && CS16(8) != *(short*)(SUB150(c) + 0x24c)) continue;
                if (CS16(10) > 0 && CS16(10) != *(short*)(SUB150(c) + 0x26c)) continue;
                *(OBJB + 0x492) |= 1 << i;
            } else if (*(OBJB + 0x492) & (1 << i)) {
                if (CS16(4) != 0 && CS16(4) != *(short*)(SUB150(c) + 0x28c)) continue;
                if (CS16(6) != 0 && CS16(6) != *(short*)(SUB150(c) + 0x2ac)) continue;
                if (CS16(8) != 0 && CS16(8) != *(short*)(SUB150(c) + 0x2cc)) continue;
                if (CS16(10) == 0 || CS16(10) == *(short*)(SUB150(c) + 0x2ec)) return 1;
            }
        }
        if (CU16(2) != 1 && i == count) return 0;
        return *(OBJB + 0x492);
    }
    case 51: {
        struct Struct_0205faf4_8* e = func_02096134((struct Struct_0205faf4_7*)func_02094d6c(), CU16(2));
        if (e != NULL && e->unknown_1_7_) return 1;
        break;
    }
    case 52: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        sub.unknown_0_ = 5; sub.p2 = CU16(4);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        sub.unknown_0_ = 0x17; sub.p2 = CS16(6);
        return Scenario_TestCondition(obj, &sub, extra) != 0;
    }
    case 53: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        sub.unknown_0_ = 0xb; sub.p2 = CU16(8);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        sub.unknown_0_ = 0x10; sub.p2 = CU16(10);
        return Scenario_TestCondition(obj, &sub, extra) != 0;
    }
    case 54: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        sub.unknown_0_ = 0x12; sub.p2 = CU16(8);
        return Scenario_TestCondition(obj, &sub, extra) != 0;
    }
    case 55: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        return func_0206474c(obj, CU16(4), CS16(6)) ? 1 : 0;
    }
    case 56: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        sub.unknown_0_ = 0x24; sub.p2 = CU16(8);
        return Scenario_TestCondition(obj, &sub, extra) != 0;
    }
    case 57: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        if (!func_0206eb98(OBJB, CU16(8))) return 0;
        sub.unknown_0_ = 0x17; sub.p2 = CU16(10);
        return Scenario_TestCondition(obj, &sub, extra) != 0;
    }
    case 58: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        if (func_0206eb98(OBJB, CU16(8))) return 0;
        sub.unknown_0_ = 0x17; sub.p2 = CU16(10);
        return Scenario_TestCondition(obj, &sub, extra) != 0;
    }
    case 59: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        return func_0206eb98(OBJB, CU16(8)) ? 1 : 0;
    }
    case 60: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        return func_0206eb98(OBJB, CU16(8)) ? 0 : 1;
    }
    case 61: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        sub.unknown_0_ = 0x17; sub.p2 = CU16(8);
        return Scenario_TestCondition(obj, &sub, extra) != 0;
    }
    case 62: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        sub.unknown_0_ = 0; sub.p2 = CU16(4);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        sub.unknown_0_ = 0x17; sub.p2 = CS16(6);
        return Scenario_TestCondition(obj, &sub, extra) != 0;
    }
    case 63: {
        struct Struct_0205faf4_20 sub;
        sub.unknown_0_ = 6; sub.p2 = CU16(2);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        sub.unknown_0_ = 1; sub.p2 = CU16(4);
        if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        sub.unknown_0_ = 0x17; sub.p2 = CS16(6);
        return Scenario_TestCondition(obj, &sub, extra) != 0;
    }
    case 64: {
        struct Struct_0205faf4_20 sub;
        int i;
        sub.unknown_0_ = 0;
        for (i = 0; i < 4; i++) {
            short v = ((short*)((char*)cmd + 4))[i];
            if (v < 0) continue;
            sub.p2 = v;
            if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        }
        return 1;
    }
    case 65: {
        struct Struct_0205faf4_20 sub;
        int i;
        sub.unknown_0_ = 1;
        for (i = 0; i < 4; i++) {
            short v = ((short*)((char*)cmd + 4))[i];
            if (v < 0) continue;
            sub.p2 = v;
            if (!Scenario_TestCondition(obj, &sub, extra)) return 0;
        }
        return 1;
    }
    case 66: {
        int r = Party_CountItem((struct Obj02086aec*)GameState_GetParty((GameState*)(void*)GameState::GetInstance()), CS16(4)) > CU16(6);
        if (CU16(2) != 0) return r;
        return r == 0;
    }
    case 67:
        return Scenario_TestFlag((int)obj, OBJB + 0x8c, CU16(2) + 0x1136);
    case 68:
        return !Scenario_TestFlag((int)obj, OBJB + 0x8c, CU16(2) + 0x1136);
    case 69: {
        int r = func_0206483c(obj, *(char**)((char*)cmd + 4));
        if (CU16(2) != 0) return r;
        return r == 0;
    }
    case 70: {
        struct Struct_0205faf4_8* e = func_02096134((struct Struct_0205faf4_7*)func_02094d6c(), CU16(2));
        if (e != NULL) {
            if (CU16(4) != 0) return e->unknown_2_2_;
            return e->unknown_2_2_ == 0;
        }
        return 0;
    }
    case 71:
        return 0;
    case 72:
        return 0;
    case 73: {
        int r = CU16(4) <= *(short*)(OBJB + 0x2ca);
        if (CU16(2) != 0) return r;
        return r == 0;
    }
    case 74: {
        unsigned short v = *(unsigned short*)((char*)(void*)GameState::GetInstance() + REGION_VALUE(0x6f9c, 0x71dc));
        if (v == 0) return CU16(2) == 0;
        return v == CU16(2);
    }
    case 75: {
        int r = 0;
        if (CU16(4) == inline_0205faf4_7(extra)) r = 1;
        return r;
    }
    case 76: {
        int r = 0;
        if (CU16(4) == inline_0205faf4_7(extra)) r = 1;
        return r;
    }
    case 77: {
        int r = 0;
        if (Scenario_TestFlag((int)obj, OBJB + 0x8c, 0x364)) {
            if (Scenario_TestFlag((int)obj, OBJB + 0x8c, 0x365)) r = 1;
        }
        return r;
    }
    case 78: {
        unsigned short* p = (unsigned short*)func_02064904(obj, CU16(2), CU16(4));
        if (p != NULL) {
            switch (CU16(8)) {
            case 0: return *p >= CU16(6);
            case 1: return *p < CU16(6);
            case 2: return *p == CU16(6);
            }
        }
        return 0;
    }
    case 79: {
        char* p = *(char**)((char*)GetGameResources() + REGION_VALUE(0x3500, 0x3710));
        return *((unsigned char*)cmd + 4) == *(unsigned char*)(p + 0x133) && CU16(2) == *(unsigned short*)(p + 0x134);
    }
    case 80: {
        struct BattleStruct* bs = (struct BattleStruct*)(void*)GameState::GetInstance();
        int outList[4];
        int outCount;
        GameState_GetPartyMemberIds((struct Base02010834*)bs, GameState_GetProtagonistIndex((GameState*)bs), outList, &outCount);
        int i;
        for (i = 0; i < outCount; i++) {
            struct CombatantStruct* c = (CombatantStruct*)((GameState*)bs)->GetPartyMemberByIndex(outList[i]);
            if (!c) continue;
            void* sub = STAT130(c);
            if (*(int*)sub & 1) continue;
            if (inline_0205faf4_2(sub) <= 0) continue;
            char* p = SUB150(c);
            if (*(unsigned short*)(p + *(int*)(p + REGION_VALUE(0x8b8, 0x950)) * 2 + 0x16c) >= CU16(2)) return 1;
        }
        return 0;
    }
    case 81: {
        int r = LinkSession_IsActive((int*)LinkSession_GetInstance((void*)GameState::GetInstance()));
        if (CU16(2) != 0) return r;
        return r == 0;
    }
    case 83: {
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xc000);
        if (buf == NULL) return 0;
        SafeAllocator alloc;
        struct Struct_0205faf4_9 list;
        unsigned int size;
        alloc.ResetAllocatorPointer();
        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(buf, 0xc000);
        unsigned char* party = (unsigned char*)GameState_GetParty((GameState*)(void*)GameState::GetInstance());
        void* entries = func_0207c5f8(party + 0x1d4, CU16(2));
        short n = func_0207c638(party + 0x1d4, CU16(2));
        ItemTable_Construct(&list);
        ItemTable_Init(&list);
#if defined(jpn)
        func_020e0484(&list, &alloc, g_itemDataArchive, entries, n, true);
#else
        BackgroundLoader::AddLockGlobal();
        size = 0;
        void* data = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &size);
        if (data != NULL) {
            ItemTable_LoadIds(&list, &alloc, data, size, entries, n);
        }
        BackgroundLoader::RemoveLockGlobal();
#endif
        int found = 0;
        signed char i;
        for (i = 0; i < n; i++) {
            struct Struct_0205faf4_10* e = func_020deb24(&list, i);
            if (e == NULL) continue;
            if (e->level >= CU16(4)) {
                found = 1;
                break;
            }
        }
        SignedAllocatorHeader* h = alloc.GetSignedAllocator();
        if (h != NULL) {
            alloc.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, h);
        }
        return found;
    }
    case 84: {
        GetGameResources();
        unsigned char v = *((unsigned char*)(void*)GameState::GetInstance() + REGION_VALUE(0x629e, 0x64de));
        return v == CU16(2);
    }
    case 85: {
        char* p = (char*)GameState_GetParty((GameState*)(void*)GameState::GetInstance());
        if (CU16(2) != 0) return *(unsigned int*)(p + 0xf6c) >= *(unsigned int*)((char*)cmd + 4);
        return *(unsigned int*)(p + 0xf6c) < *(unsigned int*)((char*)cmd + 4);
    }
    case 86: {
        struct BattleStruct* bs = (struct BattleStruct*)(void*)GameState::GetInstance();
        int i;
        for (i = 0; i < 4; i++) {
            struct CombatantStruct* c = (CombatantStruct*)func_0200ff1c((GameState*)bs, i);
            if (c == NULL) continue;
            if (!func_02061bd8((struct Struct_0205faf4_11*)c)) continue;
            if (inline_0205faf4_2(STAT130(c)) <= 0) return CU16(2) == 0;
            return CU16(2) == 1;
        }
        if ((CombatantStruct*)((GameState*)bs)->GetGameObjectByIndex(0xce) != NULL) return CU16(2) == 1;
        return CU16(2) == 0;
    }
    case 87: {
        unsigned char v = *(unsigned char*)func_02094d6c();
        if (CU16(2) != 0) return v == 8;
        return v < 8;
    }
    case 88:
        if (CU16(2) >= 0x49) return 0;
        return Scenario_TestFlag((int)obj, OBJB + 0x8c, CU16(2) + 0x33e);
    case 89:
        if (CU16(2) < 0x49) return !Scenario_TestFlag((int)obj, OBJB + 0x8c, CU16(2) + 0x33e);
        return 1;
    case 90: {
        struct Struct_0205faf4_15 s;
        func_020cf0fc((int)&s);
        return s.f4 == CU16(2) && s.f8 == CU16(4);
    }
    case 91: {
        char* p = (char*)GetGameResources();
        return *((unsigned char*)cmd + 4) == *(unsigned char*)(p + REGION_VALUE(0x4199, 0x4449)) && CU16(2) == *(signed char*)(p + REGION_VALUE(0x4196, 0x4446));
    }
    case 92: {
        struct Struct_0205faf4_8* e = func_02096134((struct Struct_0205faf4_7*)func_02094d6c(), CU16(2));
        if (e != NULL) return e->unknown_1_1_ == 0;
        return 0;
    }
    case 93: {
        unsigned int mask = 1 << CU16(2);
        return (FLAGS1840(Zone3D_GetInstance())->fb4c & mask) ? 1 : 0;
    }
    case 94:
        return CU16(2) == FLAGS1840(Zone3D_GetInstance())->fb3c;
    case 95: {
        unsigned short v = *(unsigned short*)((char*)Zone3D_GetInstance() + REGION_VALUE(0x27f4, 0x27b4));
        return CS16(2) == v;
    }
    case 96: {
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)((struct BattleStruct*)(void*)GameState::GetInstance()))->GetProtagonist();
        if (c == NULL) return 0;
        int n = 0;
        int i;
        for (i = 0; i < 13; i++) {
            if (*(unsigned short*)(SUB150(c) + (unsigned char)i * 2 + 0x16c) >= 99) n++;
        }
        return n >= CU16(2);
    }
    case 97:
#if defined(jpn)
        return func_ov017_021b2718(*(void**)(inline_0205faf4((void*)GameState::GetInstance()) + 0x104)) == 0;
#else
        return 0;
#endif
    case 98:
        return *((unsigned char*)Zone3D_GetInstance() + REGION_VALUE(0x2810, 0x27d0)) <= CU16(2);
    case 99:
        return *((unsigned char*)Zone3D_GetInstance() + REGION_VALUE(0x2810, 0x27d0)) >= CU16(2);
    case 500: {
        struct BattleStruct* bs = (struct BattleStruct*)(void*)GameState::GetInstance();
        int outList[4];
        int outCount;
        GameState_GetPartyMemberIds((struct Base02010834*)bs, GameState_GetProtagonistIndex((GameState*)bs), outList, &outCount);
        int i;
        for (i = 0; i < outCount; i++) {
            struct CombatantStruct* c = (CombatantStruct*)func_0200ff1c((GameState*)bs, outList[i]);
            if (c == NULL) continue;
            if (!HasNibble56b(c)) continue;
            if (CU16(2) != GetNibble56b(c)) continue;
            if (*(int*)STAT130(c) & 1) return CU16(4) == 0;
            return CU16(4) == 1;
        }
        return 0;
    }
    case 501:
        return CU16(2) == ((GameState*)((struct BattleStruct*)(void*)GameState::GetInstance()))->GetTimeOfDay();
    case 502:
        return func_02098ee8((struct ReadClearByte02098ee8*)((char*)Zone3D_GetInstance() + REGION_VALUE(0x860, 0x840)));
    case 503:
        if (CU16(2) != 0) return Scenario_TestFlag((int)obj, OBJB + 0x8c, 0x798);
        return !Scenario_TestFlag((int)obj, OBJB + 0x8c, 0x798);
    case 504: {
        char* bs = (char*)(void*)GameState::GetInstance();
        struct Struct_0205faf4_15 s;
        func_020cf0fc((int)&s);
        struct Struct_0205faf4_16* w = (struct Struct_0205faf4_16*)(bs + REGION_VALUE(0x543c, 0x569c));
        return s.f4 == w->a && s.f8 == w->b;
    }
    case 505:
        return func_02011b50((void*)GameState::GetInstance(), 1);
    case 506:
        return func_0206e2dc((struct Struct_0205faf4_13*)obj, CU16(2));
    case 507:
        return CU16(2) == *(unsigned short*)GameState_GetZoneTransition((GameState*)(void*)GameState::GetInstance());
    }
    return 0;
}
