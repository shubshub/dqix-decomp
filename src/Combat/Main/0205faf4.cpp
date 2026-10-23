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
static inline char* DateConditionBase(void* state) {
    return (char*)state + 0x5c0c;
}
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

struct Struct_0203d028_2 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_0203d028_3* unknown_8_[0xe9];
};
struct Struct_0203d028_3 {
    unsigned short unknown_0_;
    char unknown_2_[0x132];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
};

struct Struct_0205faf4_20 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    struct Struct_0205faf4_20* unknown_c_;
};

extern "C" int func_0206dfb0(int arg0, unsigned char* arg1, int arg2);
extern "C" void func_02010890(GameState*, int*, int*);
extern "C" int func_020421a0(void);
extern "C" int func_020457e0(int);
struct Struct_0205faf4;
struct GameState;
struct Struct_02053f7c;
extern "C" short func_02086aec(struct Struct_02053f7c* arg0, int arg1);
struct Struct_0205faf4_3;
extern "C" int func_0206e120(struct Struct_0205faf4_3* arg0, int arg1);
extern "C" int func_0206e31c(int arg0, int arg1);
struct Struct_0205faf4_4;
extern "C" int func_0206e260(struct Struct_0205faf4_4* arg0, int arg1);
extern "C" void* func_0202ae18(void* arg0);
extern "C" int func_0202b7d8(int* arg0);
struct Struct_0202c1a4;
extern "C" signed char func_0202c1a4(struct Struct_0202c1a4* arg0);
extern "C" int func_0206eb98(unsigned char* arg0, int arg1);
extern "C" void __clear(void* arg0, int arg1);
extern "C" void* func_02094d6c(void);
extern "C" int func_02096088(void* arg0, int arg1);
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* arg0, int arg1);
struct Struct_0203e0a0;
extern "C" void* func_02040538(struct Struct_0203e0a0* arg0);
extern "C" int func_02010804(char* arg0);
extern "C" int func_020100a8(GameState*);
struct Struct_02010834;
extern "C" void func_02010834(struct Struct_02010834* arg0, int arg1, int* arg2, int* arg3);

struct Struct_0205faf4_5 {
    int unknown_0_;
    unsigned int unknown_4_0_:10, unknown_5_2_:10, unknown_6_4_:12;
    int unknown_8_;
    unsigned int unknown_c_0_:10, unknown_d_2_:10, unknown_e_4_:10;
    unsigned int unknown_10_0_:10, unknown_11_2_:10, unknown_12_4_:10;
    unsigned int unknown_14_0_:10;
};
void* GetFieldAt0x150_02053c6c(unsigned char* obj);
unsigned char GetField0x397cValue_020100b0(GameState*);
struct Entry0x194_0205faf4 { char pad[8]; unsigned int _pad18:18, flag:1; };
struct FindEntryById02096134Table;
struct FindEntryById02096134Elem { unsigned int _pad0:9, b9:1, _pad10:5, b15:1, _pad16:2, b18:1; };
struct FindEntryById02096134Elem* FindEntryById02096134(struct FindEntryById02096134Table* t, int id);
extern "C" int func_0206474c(struct BattleStruct* obj, int a1, int a2);
extern "C" int func_0206483c(struct BattleStruct* obj, char* name);
void* GetStatFieldPointer02064904(void* obj, int id, unsigned int statIndex);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void* GetPointerFromArray0xbd0_0207c5f8(unsigned char* obj, unsigned int index);
short CountPositiveEntries0207c638(void* base, unsigned int index);
struct EntryList020deb24 { int w[6]; };
struct Entry020deb24 { int f0; int f4; unsigned int _pad9:9, level:3; };
void* ZeroInitReturn020de824(void* obj);
void ItemTable_Init(void* obj);
struct Entry020deb24* GetEntryByIndex020deb24(struct EntryList020deb24* list, int index);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" int ItemTable_LoadIds(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
int RegisterSlotA020cf0fc(int out);
extern "C" void* func_02012fe4(void);
struct Struct_0205faf4_12;
extern "C" unsigned char func_02098ee8(struct Struct_0205faf4_12* arg0);
extern "C" int func_02011b50(void* arg0, int arg1);
struct Struct_0205faf4_13;
extern "C" int func_0206e2dc(struct Struct_0205faf4_13* arg0, int arg1);
extern "C" void* func_0200fd0c(GameState*);

extern AllocatorUnion data_02114e20;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;

struct Struct_0205faf4_14 {
    int unknown_0_[16];
};
struct Struct_0205faf4_15 { int unknown_0_; int unknown_4_; int unknown_8_; int unknown_c_; };
struct Struct_0205faf4_16 { unsigned int unknown_0_0_:12, unknown_1_4_:4, unknown_2_0_:5; };
struct Struct_0205faf4_17 { char unknown_0_[0x56b]; unsigned char unknown_56b_0_:4, unknown_56b_4_:4; };

#define NIB56B(c) (*(struct Struct_0205faf4_17**)((char*)(c) + REGION_VALUE(0x144, 0x150)))
#define HasNibble56b(c) (NIB56B(c) != NULL ? (NIB56B(c)->unknown_56b_4_ != 0 ? 1 : 0) : 0)
#define GetNibble56b(c) (NIB56B(c) != NULL ? NIB56B(c)->unknown_56b_4_ : 0)

static inline int inline_0205faf4_2(void* arg0) {
    return *(unsigned short*)((char*)arg0 + 4);
}
static inline char* inline_0205faf4_3(void* arg0) {
    return (char*)arg0 + REGION_VALUE(0x543c, 0x569c);
}
struct Struct_0205faf4_18 { int unknown_0_0_:19, unknown_2_3_:11; };
static inline struct Struct_0205faf4_6* inline_0205faf4_4(struct Struct_0203d028_3* arg0, unsigned char arg1) {
    return (struct Struct_0205faf4_6*)(*(char**)((char*)arg0 + REGION_VALUE(0x144, 0x150)) + 0x194 + arg1 * 0x20);
}

struct Struct_0205faf4_19 { char unknown_0_[0xb3c]; unsigned int unknown_b3c_; char unknown_b40_[0xb4c - 0xb40]; unsigned int unknown_b4c_; };
static inline struct Struct_0205faf4_19* inline_0205faf4_5(void* arg0) {
    return (struct Struct_0205faf4_19*)((char*)arg0 + REGION_VALUE(0x1860, 0x1840));
}
#define FLAGS1840(p) inline_0205faf4_5(p)
#define OBJB ((unsigned char*)arg0)
#define CU16(o) (*(unsigned short*)((char*)arg1 + (o)))
#define CS16(o) (*(short*)((char*)arg1 + (o)))
#define EW(o) (*(int*)((char*)extra + (o)))
#define STAT130(c) (*(void**)((char*)(c) + 0x130))
#define SUB150(c) (*(char**)((char*)(c) + REGION_VALUE(0x144, 0x150)))

static inline int inline_0205faf4_6(struct Struct_0203d028_3* arg0) { SDK_NULL_ASSERT(arg0); return *(int*)(SUB150(arg0) + REGION_VALUE(0x8b8, 0x950)); }
static inline int inline_0205faf4_7(struct Struct_0205faf4_14* extra) { SDK_NULL_ASSERT(extra); return EW(0x24); }

// USA: func_0205faf4
extern "C" ARM int func_0205faf4(struct Struct_0203d028_2* arg0, void* arg1, struct Struct_0205faf4_14* extra) {
    unsigned short var0 = *(unsigned short*)arg1;
    switch (var0) {
    case 0:
        return func_0206dfb0((int)arg0, OBJB + 0x8c, CU16(2));
    case 1:
        return !func_0206dfb0((int)arg0, OBJB + 0x8c, CU16(2));
    case 2: {
        unsigned char var1 = *(OBJB + 0x332);
        return func_0206dfb0((int)arg0, OBJB + var1 * 0x1c + 3, CU16(2));
    }
    case 3: {
        unsigned char var2 = *(OBJB + 0x332);
        return !func_0206dfb0((int)arg0, OBJB + var2 * 0x1c + 3, CU16(2));
    }
    case 4: {
        unsigned char var3 = *(OBJB + 0x332);
        return func_0206dfb0((int)arg0, OBJB + var3 * 0x1c + 0x10, CU16(2));
    }
    case 5: {
        unsigned char var4 = *(OBJB + 0x332);
        return !func_0206dfb0((int)arg0, OBJB + var4 * 0x1c + 0x10, CU16(2));
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
        int var5[4]; int var6;
        func_02010890((GameState*)(void*)GameState::GetInstance(), var5, &var6);
        return CU16(2) <= var6;
    }
    case 14: {
        int var7[4]; int var8;
        func_02010890((GameState*)(void*)GameState::GetInstance(), var7, &var8);
        return CU16(2) >= var8;
    }
    case 15: {
        int var9[4]; int var10;
        func_02010890((GameState*)(void*)GameState::GetInstance(), var9, &var10);
        return CU16(2) == var10;
    }
    case 16:
        return CU16(2) == func_020457e0(func_020421a0());
    case 17: {
        struct Struct_0203d028_2* var11 = (struct Struct_0203d028_2*)(void*)GameState::GetInstance();
        if (CU16(2) == 1) {
            return !((GameState*)((struct Struct_0205faf4*)var11))->IsMorningDayOrEvening();
        }
        return ((GameState*)((struct Struct_0205faf4*)var11))->IsMorningDayOrEvening();
    }
    case 18:
        return func_02086aec((struct Struct_02053f7c*)func_02010828((GameState*)(void*)GameState::GetInstance()), CS16(2)) > 0;
    case 19:
        return func_02086aec((struct Struct_02053f7c*)func_02010828((GameState*)(void*)GameState::GetInstance()), CS16(2)) <= 0;
    case 20: {
        int var12 = 0;
        int var13 = func_0206e120((struct Struct_0205faf4_3*)arg0, CU16(2)) == 2;
        if (var13) {
            if (func_0206e31c((int)arg0, CU16(2))) var12 = 1;
        }
        return var12;
    }
    case 21: {
        if (func_0206e260((struct Struct_0205faf4_4*)arg0, CU16(2))) {
            if (func_0206e31c((int)arg0, CU16(2))) return 1;
        }
        return 0;
    }
    case 22: {
        int var14 = 0;
        int var15 = func_0206e120((struct Struct_0205faf4_3*)arg0, CU16(2)) == 3;
        if (var15) {
            if (func_0206e31c((int)arg0, CU16(2))) var14 = 1;
        }
        return var14;
    }
    case 23: {
        void* var16 = func_0202ae18((void*)GameState::GetInstance());
        int var17 = 0;
        switch (CU16(2)) {
        case 1:
            if (func_0202b7d8((int*)var16)) var17 = 1;
            break;
        case 0:
            if (!func_0202b7d8((int*)var16)) var17 = 1;
            break;
        case 2:
            if (func_0202b7d8((int*)var16)) {
                if (func_0202c1a4((struct Struct_0202c1a4*)var16) == 0) {
                    var17 = 1;
                    break;
                }
            }
            if (func_0202b7d8((int*)var16) == 0) var17 = 1;
            break;
        case 3:
            if (func_0202b7d8((int*)var16)) {
                if (func_0202c1a4((struct Struct_0202c1a4*)var16)) var17 = 1;
            }
            break;
        }
        return var17;
    }
    case 25: {
        int var18 = 0;
        int var19 = func_0206e120((struct Struct_0205faf4_3*)arg0, CU16(2)) == 1;
        if (var19) {
            if (func_0206e31c((int)arg0, CU16(2))) var18 = 1;
        }
        return var18;
    }
    case 26:
        return func_0206eb98(OBJB, CU16(2));
    case 27:
        return !func_0206eb98(OBJB, CU16(2));
    case 28: {
        int var20 = 0;
        int var21 = func_0206e120((struct Struct_0205faf4_3*)arg0, CU16(2)) == 0;
        if (var21) {
            if (func_0206e31c((int)arg0, CU16(2))) var20 = 1;
        }
        return var20;
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
        int var22;
        for (var22 = 0; var22 < 4; var22++) {
            signed char var23 = ((signed char*)((int)arg1 + 4))[var22];
            if (var23 != 0 && var23 != ((signed char*)extra + var22)[0x2a]) break;
        }
        return var22 == 4;
    }
    case 33: {
        unsigned char var24[4];
        __clear(var24, 4);
        signed char* var25 = (signed char*)arg1 + 4;
        int var26, var27;
        for (var26 = 0; var26 < 4; var26++) {
            signed char var28 = var25[var26];
            if (var28 == 0) continue;
            for (var27 = 0; var27 < 4; var27++) {
                if (var28 == ((signed char*)extra + 0x2a)[var27] && var24[var27] == 0) {
                    var24[var27] = 1;
                    break;
                }
            }
            if (var27 == 4) return 0;
        }
        return 1;
    }
    case 34: {
        void* var29 = func_02010828((GameState*)(void*)GameState::GetInstance());
        unsigned short var30 = CU16(2);
        if (var30 != 0 && *((unsigned char*)var29 + 0xf7c) > 1) return 1;
        if (var30 == 0 && *((unsigned char*)var29 + 0xf7c) <= 1) return 1;
        return 0;
    }
    case 35:
        return CU16(2) == func_02010804((char*)(void*)GameState::GetInstance());
    case 36: {
        struct Struct_0203d028_3* var31 = (Struct_0203d028_3*)((GameState*)((struct Struct_0203d028_2*)(void*)GameState::GetInstance()))->GetGameObjectByIndex(0);
        unsigned short var32 = CU16(2);
        if (var32 != 0 && inline_0205faf4_2(STAT130(var31)) <= 0) return 1;
        if (var32 == 0 && inline_0205faf4_2(STAT130(var31)) > 0) return 1;
        return 0;
    }
    case 37: {
        if (func_02096088(func_02094d6c(), CU16(2))) {
            if (func_0206e31c((int)arg0, CU16(2))) return 1;
        }
        return 0;
    }
    case 38: {
        if (!func_02096088(func_02094d6c(), CU16(2))) {
            if (func_0206e31c((int)arg0, CU16(2))) return 1;
        }
        return 0;
    }
    case 39:
        return func_0206dfb0((int)arg0, OBJB + 0x8c, CU16(2) + 0x776);
    case 40:
        return !func_0206dfb0((int)arg0, OBJB + 0x8c, CU16(2) + 0x776);
    case 41: {
        struct Struct_0205faf4_2 { int unknown_0_; int unknown_4_; int unknown_8_; };
        void* var33 = func_0203df78(func_0203cf4c(), EW(0));
        if (!var33) return 0;
        void* var34 = func_02040538((struct Struct_0203e0a0*)var33);
        if (!var34) return 0;
        struct Struct_0203d028_3* var35 = (Struct_0203d028_3*)((GameState*)((struct Struct_0203d028_2*)(void*)GameState::GetInstance()))->GetUnknownGameObject();
        struct Struct_0205faf4_2 var36 = *(struct Struct_0205faf4_2*)((char*)var35 + 0x44);
        int* var37;
        for (var37 = *(int**)((char*)var34 + 0x40); var37 != NULL; var37 = (int*)var37[5]) {
            if (var36.unknown_0_ < var37[1] && var36.unknown_8_ < var37[2] && var36.unknown_0_ > var37[3] && var36.unknown_8_ > var37[4]) return CU16(2) != 0;
        }
        return CU16(2) == 0;
    }
    case 42: {
        struct Struct_0203d028_3* var38 = (Struct_0203d028_3*)((GameState*)((struct Struct_0203d028_2*)(void*)GameState::GetInstance()))->GetGameObjectByIndex(0);
        return CU16(2) == inline_0205faf4_6(var38);
    }
    case 43: {
        char* var39 = inline_0205faf4_3((void*)GameState::GetInstance());
        return ((struct Struct_0205faf4_18*)(var39 + 4))->unknown_2_3_ == CU16(2);
    }
    case 44: {
        struct Struct_0203d028_2* var40 = (struct Struct_0203d028_2*)(void*)GameState::GetInstance();
        int var41[4];
        int var42;
        func_02010834((struct Struct_02010834*)var40, func_020100a8((GameState*)var40), var41, &var42);
        int var43;
        for (var43 = 0; var43 < var42; var43++) {
            struct Struct_0203d028_3* var44 = (Struct_0203d028_3*)((GameState*)var40)->GetGameObjectByIndex(var41[var43]);
            if (!var44) continue;
            void* var45 = STAT130(var44);
            if (*(int*)var45 & 1) continue;
            if (inline_0205faf4_2(var45) <= 0) continue;
            if (*(unsigned char*)(SUB150(var44) + (unsigned char)CU16(2) + 0x464) >= CU16(4)) return 1;
        }
        return 0;
    }
    case 45: {
        struct Struct_0205faf4_5* var46 = (struct Struct_0205faf4_5*)SUB150((Struct_0203d028_3*)((GameState*)((struct Struct_0203d028_2*)(void*)GameState::GetInstance()))->GetGameObjectByIndex(0));
        unsigned short var47[6];
        var47[0] = var46->unknown_d_2_; var47[1] = var46->unknown_e_4_; var47[2] = var46->unknown_10_0_;
        var47[3] = var46->unknown_11_2_; var47[4] = var46->unknown_12_4_; var47[5] = var46->unknown_14_0_;
        unsigned short var48 = CU16(2);
        int var49 = var47[var48];
        int var50;
        for (var50 = 0; var50 < 6; var50++) {
            if (var50 == var48) continue;
            if (var49 < var47[var50]) return 0;
        }
        return 1;
    }
    case 46: {
        struct Struct_0205faf4_5* var51 = (struct Struct_0205faf4_5*)SUB150((Struct_0203d028_3*)((GameState*)((struct Struct_0203d028_2*)(void*)GameState::GetInstance()))->GetGameObjectByIndex(0));
        unsigned short var52 = var51->unknown_5_2_;
        int var53 = CU16(4);
        unsigned short var54 = CU16(2);
        if (CU16(6) != 0) {
            switch (var54) {
            case 0: if (var53 >= (unsigned short)var51->unknown_d_2_ - var52) return 1; break;
            case 1: if (var53 >= (unsigned short)var51->unknown_e_4_ - var52) return 1; break;
            case 2: if (var53 >= (unsigned short)var51->unknown_10_0_ - var52) return 1; break;
            case 3: if (var53 >= (unsigned short)var51->unknown_11_2_ - var52) return 1; break;
            case 4: if (var53 >= (unsigned short)var51->unknown_12_4_ - var52) return 1; break;
            case 5: if (var53 >= (unsigned short)var51->unknown_14_0_ - var52) return 1; break;
            }
        } else {
            switch (var54) {
            case 0: if (var53 < (unsigned short)var51->unknown_d_2_ - var52) return 1; break;
            case 1: if (var53 < (unsigned short)var51->unknown_e_4_ - var52) return 1; break;
            case 2: if (var53 < (unsigned short)var51->unknown_10_0_ - var52) return 1; break;
            case 3: if (var53 < (unsigned short)var51->unknown_11_2_ - var52) return 1; break;
            case 4: if (var53 < (unsigned short)var51->unknown_12_4_ - var52) return 1; break;
            case 5: if (var53 < (unsigned short)var51->unknown_14_0_ - var52) return 1; break;
            }
        }
        return 0;
    }
    case 47: {
        struct Struct_0203d028_2* var55 = (struct Struct_0203d028_2*)(void*)GameState::GetInstance();
        struct Struct_0203d028_3* var56 = (Struct_0203d028_3*)func_0200ff1c((GameState*)var55, func_020100b0((GameState*)var55));
        if (!var56) return 0;
        int var57 = 0;
        int var58;
        for (var58 = 0; var58 < 0xb; var58++) {
            struct Struct_0205faf4_6* var59 = inline_0205faf4_4(var56, var58);
            if (var59 == NULL) continue;
            if (var59->unknown_a_2_) var57++;
        }
        if (CU16(2) != 0) {
            if (var57 >= CU16(4)) return 1;
        } else if (var57 < CU16(4)) {
            return 1;
        }
        return 0;
    }
    case 48: {
        void* var60 = func_02010828((GameState*)(void*)GameState::GetInstance());
        if (!var60) return 0;
        return func_02086aec((struct Struct_02053f7c*)var60, CS16(2)) >= CU16(4) ? 1 : 0;
    }
    case 49: {
        struct Struct_0203d028_2* var61 = (struct Struct_0203d028_2*)(void*)GameState::GetInstance();
        int var62[4];
        int var63;
        func_02010834((struct Struct_02010834*)var61, func_020100a8((GameState*)var61), var62, &var63);
        int var64;
        for (var64 = 0; var64 < var63; var64++) {
            struct Struct_0203d028_3* var65 = (Struct_0203d028_3*)func_0200ff1c((GameState*)var61, var62[var64]);
            if (!var65) continue;
            void* var66 = STAT130(var65);
            if (*(int*)var66 & 1) continue;
            if (CU16(2) != inline_0205faf4_6(var65)) continue;
            if (inline_0205faf4_2(var66) <= 0) continue;
            void* var67 = func_02053c6c((unsigned char*)var65);
            if (!var67) continue;
            if (*(unsigned short*)((char*)var67 + CU16(2) * 2 + 0x16c) >= CU16(4)) return 1;
        }
        return 0;
    }
    case 50:
    case 82: {
        struct Struct_0203d028_2* var68 = (struct Struct_0203d028_2*)(void*)GameState::GetInstance();
        unsigned char* var69 = (unsigned char*)func_02010828((GameState*)var68);
        int var70 = var69[0xf7c];
        int var71 = 0;
        if (CU16(0) == 0x52) var70 = 1;
        for (; var71 < var70; var71++) {
            struct Struct_0203d028_3* var72;
            if (CU16(0) == 0x52) {
                var72 = (Struct_0203d028_3*)((GameState*)var68)->GetProtagonist();
            } else {
                var72 = (Struct_0203d028_3*)func_0200ff1c((GameState*)var68, *(var69 + var71 + 0xf78));
            }
            if (var72 == NULL) continue;
            if (*(int*)STAT130(var72) & 1) continue;
            if (CU16(2) == 1) {
                if (CS16(4) > 0 && CS16(4) != *(short*)(SUB150(var72) + 0x1ac)) continue;
                if (CS16(6) > 0 && CS16(6) != *(short*)(SUB150(var72) + 0x1cc)) continue;
                if (CS16(8) > 0 && CS16(8) != *(short*)(SUB150(var72) + 0x24c)) continue;
                if (CS16(10) > 0 && CS16(10) != *(short*)(SUB150(var72) + 0x26c)) continue;
                *(OBJB + 0x492) |= 1 << var71;
            } else if (*(OBJB + 0x492) & (1 << var71)) {
                if (CS16(4) != 0 && CS16(4) != *(short*)(SUB150(var72) + 0x28c)) continue;
                if (CS16(6) != 0 && CS16(6) != *(short*)(SUB150(var72) + 0x2ac)) continue;
                if (CS16(8) != 0 && CS16(8) != *(short*)(SUB150(var72) + 0x2cc)) continue;
                if (CS16(10) == 0 || CS16(10) == *(short*)(SUB150(var72) + 0x2ec)) return 1;
            }
        }
        if (CU16(2) != 1 && var71 == var70) return 0;
        return *(OBJB + 0x492);
    }
    case 51: {
        struct Struct_0205faf4_8* var73 = func_02096134((struct Struct_0205faf4_7*)func_02094d6c(), CU16(2));
        if (var73 != NULL && var73->unknown_1_7_) return 1;
        break;
    }
    case 52: {
        struct Struct_0205faf4_20 var74;
        var74.unknown_0_ = 6; var74.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var74, extra)) return 0;
        var74.unknown_0_ = 5; var74.unknown_2_ = CU16(4);
        if (!func_0205faf4(arg0, &var74, extra)) return 0;
        var74.unknown_0_ = 0x17; var74.unknown_2_ = CS16(6);
        return func_0205faf4(arg0, &var74, extra) != 0;
    }
    case 53: {
        struct Struct_0205faf4_20 var75;
        var75.unknown_0_ = 6; var75.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var75, extra)) return 0;
        if (!func_0206474c(arg0, CU16(4), CS16(6))) return 0;
        var75.unknown_0_ = 0xb; var75.unknown_2_ = CU16(8);
        if (!func_0205faf4(arg0, &var75, extra)) return 0;
        var75.unknown_0_ = 0x10; var75.unknown_2_ = CU16(10);
        return func_0205faf4(arg0, &var75, extra) != 0;
    }
    case 54: {
        struct Struct_0205faf4_20 var76;
        var76.unknown_0_ = 6; var76.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var76, extra)) return 0;
        if (!func_0206474c(arg0, CU16(4), CS16(6))) return 0;
        var76.unknown_0_ = 0x12; var76.unknown_2_ = CU16(8);
        return func_0205faf4(arg0, &var76, extra) != 0;
    }
    case 55: {
        struct Struct_0205faf4_20 var77;
        var77.unknown_0_ = 6; var77.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var77, extra)) return 0;
        return func_0206474c(arg0, CU16(4), CS16(6)) ? 1 : 0;
    }
    case 56: {
        struct Struct_0205faf4_20 var78;
        var78.unknown_0_ = 6; var78.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var78, extra)) return 0;
        if (!func_0206474c(arg0, CU16(4), CS16(6))) return 0;
        var78.unknown_0_ = 0x24; var78.unknown_2_ = CU16(8);
        return func_0205faf4(arg0, &var78, extra) != 0;
    }
    case 57: {
        struct Struct_0205faf4_20 var79;
        var79.unknown_0_ = 6; var79.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var79, extra)) return 0;
        if (!func_0206474c(arg0, CU16(4), CS16(6))) return 0;
        if (!func_0206eb98(OBJB, CU16(8))) return 0;
        var79.unknown_0_ = 0x17; var79.unknown_2_ = CU16(10);
        return func_0205faf4(arg0, &var79, extra) != 0;
    }
    case 58: {
        struct Struct_0205faf4_20 var80;
        var80.unknown_0_ = 6; var80.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var80, extra)) return 0;
        if (!func_0206474c(arg0, CU16(4), CS16(6))) return 0;
        if (func_0206eb98(OBJB, CU16(8))) return 0;
        var80.unknown_0_ = 0x17; var80.unknown_2_ = CU16(10);
        return func_0205faf4(arg0, &var80, extra) != 0;
    }
    case 59: {
        struct Struct_0205faf4_20 var81;
        var81.unknown_0_ = 6; var81.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var81, extra)) return 0;
        if (!func_0206474c(arg0, CU16(4), CS16(6))) return 0;
        return func_0206eb98(OBJB, CU16(8)) ? 1 : 0;
    }
    case 60: {
        struct Struct_0205faf4_20 var82;
        var82.unknown_0_ = 6; var82.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var82, extra)) return 0;
        if (!func_0206474c(arg0, CU16(4), CS16(6))) return 0;
        return func_0206eb98(OBJB, CU16(8)) ? 0 : 1;
    }
    case 61: {
        struct Struct_0205faf4_20 var83;
        var83.unknown_0_ = 6; var83.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var83, extra)) return 0;
        if (!func_0206474c(arg0, CU16(4), CS16(6))) return 0;
        var83.unknown_0_ = 0x17; var83.unknown_2_ = CU16(8);
        return func_0205faf4(arg0, &var83, extra) != 0;
    }
    case 62: {
        struct Struct_0205faf4_20 var84;
        var84.unknown_0_ = 6; var84.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var84, extra)) return 0;
        var84.unknown_0_ = 0; var84.unknown_2_ = CU16(4);
        if (!func_0205faf4(arg0, &var84, extra)) return 0;
        var84.unknown_0_ = 0x17; var84.unknown_2_ = CS16(6);
        return func_0205faf4(arg0, &var84, extra) != 0;
    }
    case 63: {
        struct Struct_0205faf4_20 var85;
        var85.unknown_0_ = 6; var85.unknown_2_ = CU16(2);
        if (!func_0205faf4(arg0, &var85, extra)) return 0;
        var85.unknown_0_ = 1; var85.unknown_2_ = CU16(4);
        if (!func_0205faf4(arg0, &var85, extra)) return 0;
        var85.unknown_0_ = 0x17; var85.unknown_2_ = CS16(6);
        return func_0205faf4(arg0, &var85, extra) != 0;
    }
    case 64: {
        struct Struct_0205faf4_20 var86;
        int var87;
        var86.unknown_0_ = 0;
        for (var87 = 0; var87 < 4; var87++) {
            short var88 = ((short*)((char*)arg1 + 4))[var87];
            if (var88 < 0) continue;
            var86.unknown_2_ = var88;
            if (!func_0205faf4(arg0, &var86, extra)) return 0;
        }
        return 1;
    }
    case 65: {
        struct Struct_0205faf4_20 var89;
        int var90;
        var89.unknown_0_ = 1;
        for (var90 = 0; var90 < 4; var90++) {
            short var91 = ((short*)((char*)arg1 + 4))[var90];
            if (var91 < 0) continue;
            var89.unknown_2_ = var91;
            if (!func_0205faf4(arg0, &var89, extra)) return 0;
        }
        return 1;
    }
    case 66: {
        int var92 = func_02086aec((struct Struct_02053f7c*)func_02010828((GameState*)(void*)GameState::GetInstance()), CS16(4)) > CU16(6);
        if (CU16(2) != 0) return var92;
        return var92 == 0;
    }
    case 67:
        return func_0206dfb0((int)arg0, OBJB + 0x8c, CU16(2) + 0x1136);
    case 68:
        return !func_0206dfb0((int)arg0, OBJB + 0x8c, CU16(2) + 0x1136);
    case 69: {
        int var93 = func_0206483c(arg0, *(char**)((char*)arg1 + 4));
        if (CU16(2) != 0) return var93;
        return var93 == 0;
    }
    case 70: {
        struct Struct_0205faf4_8* var94 = func_02096134((struct Struct_0205faf4_7*)func_02094d6c(), CU16(2));
        if (var94 != NULL) {
            if (CU16(4) != 0) return var94->unknown_2_2_;
            return var94->unknown_2_2_ == 0;
        }
        return 0;
    }
    case 71:
        return 0;
    case 72:
        return 0;
    case 73: {
        int var95 = CU16(4) <= *(short*)(OBJB + 0x2ca);
        if (CU16(2) != 0) return var95;
        return var95 == 0;
    }
    case 74: {
        unsigned short var96 = *(unsigned short*)((char*)(void*)GameState::GetInstance() + REGION_VALUE(0x6f9c, 0x71dc));
        if (var96 == 0) return CU16(2) == 0;
        return var96 == CU16(2);
    }
    case 75: {
        int var97 = 0;
        if (CU16(4) == inline_0205faf4_7(extra)) var97 = 1;
        return var97;
    }
    case 76: {
        int var98 = 0;
        if (CU16(4) == inline_0205faf4_7(extra)) var98 = 1;
        return var98;
    }
    case 77: {
        int var99 = 0;
        if (func_0206dfb0((int)arg0, OBJB + 0x8c, 0x364)) {
            if (func_0206dfb0((int)arg0, OBJB + 0x8c, 0x365)) var99 = 1;
        }
        return var99;
    }
    case 78: {
        unsigned short* var100 = (unsigned short*)func_02064904(arg0, CU16(2), CU16(4));
        if (var100 != NULL) {
            switch (CU16(8)) {
            case 0: return *var100 >= CU16(6);
            case 1: return *var100 < CU16(6);
            case 2: return *var100 == CU16(6);
            }
        }
        return 0;
    }
    case 79: {
        char* var101 = *(char**)((char*)GetGameResources() + REGION_VALUE(0x3500, 0x3710));
        return *((unsigned char*)arg1 + 4) == *(unsigned char*)(var101 + 0x133) && CU16(2) == *(unsigned short*)(var101 + 0x134);
    }
    case 80: {
        struct Struct_0203d028_2* var102 = (struct Struct_0203d028_2*)(void*)GameState::GetInstance();
        int var103[4];
        int var104;
        func_02010834((struct Struct_02010834*)var102, func_020100a8((GameState*)var102), var103, &var104);
        int var105;
        for (var105 = 0; var105 < var104; var105++) {
            struct Struct_0203d028_3* var106 = (Struct_0203d028_3*)((GameState*)var102)->GetPartyMemberByIndex(var103[var105]);
            if (!var106) continue;
            void* var107 = STAT130(var106);
            if (*(int*)var107 & 1) continue;
            if (inline_0205faf4_2(var107) <= 0) continue;
            char* var108 = SUB150(var106);
            if (*(unsigned short*)(var108 + *(int*)(var108 + REGION_VALUE(0x8b8, 0x950)) * 2 + 0x16c) >= CU16(2)) return 1;
        }
        return 0;
    }
    case 81: {
        int var109 = func_0202b7d8((int*)func_0202ae18((void*)GameState::GetInstance()));
        if (CU16(2) != 0) return var109;
        return var109 == 0;
    }
    case 83: {
        void* buf = AllocateAligned4_02012d88(&data_02114e20, 0xc000);
        if (buf == NULL) return 0;
        SafeAllocator alloc;
        struct EntryList020deb24 list;
        unsigned int size;
        alloc.ResetAllocatorPointer();
        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(buf, 0xc000);
        unsigned char* party = (unsigned char*)GetPtrField0x2a04_02010828((GameState*)(void*)GameState::GetInstance());
        void* entries = GetPointerFromArray0xbd0_0207c5f8(party + 0x1d4, CU16(2));
        short n = CountPositiveEntries0207c638(party + 0x1d4, CU16(2));
        ZeroInitReturn020de824(&list);
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
        int var118 = 0;
        signed char var119;
        for (var119 = 0; var119 < var116; var119++) {
            struct Struct_0205faf4_10* var120 = func_020deb24(&var112, var119);
            if (var120 == NULL) continue;
            if (var120->unknown_9_1_ >= CU16(4)) {
                var118 = 1;
                break;
            }
        }
        SignedAllocatorHeader* var121 = var111.GetSignedAllocator();
        if (var121 != NULL) {
            var111.Destroy();
            func_02012da4(&data_02114e20, var121);
        }
        return var118;
    }
    case 84: {
        GetGameResources();
        unsigned char var122 = *((unsigned char*)(void*)GameState::GetInstance() + REGION_VALUE(0x629e, 0x64de));
        return var122 == CU16(2);
    }
    case 85: {
        char* var123 = (char*)func_02010828((GameState*)(void*)GameState::GetInstance());
        if (CU16(2) != 0) return *(unsigned int*)(var123 + 0xf6c) >= *(unsigned int*)((char*)arg1 + 4);
        return *(unsigned int*)(var123 + 0xf6c) < *(unsigned int*)((char*)arg1 + 4);
    }
    case 86: {
        struct Struct_0203d028_2* var124 = (struct Struct_0203d028_2*)(void*)GameState::GetInstance();
        int var125;
        for (var125 = 0; var125 < 4; var125++) {
            struct Struct_0203d028_3* var126 = (Struct_0203d028_3*)func_0200ff1c((GameState*)var124, var125);
            if (var126 == NULL) continue;
            if (!func_02061bd8((struct Struct_0205faf4_11*)var126)) continue;
            if (inline_0205faf4_2(STAT130(var126)) <= 0) return CU16(2) == 0;
            return CU16(2) == 1;
        }
        if ((Struct_0203d028_3*)((GameState*)var124)->GetGameObjectByIndex(0xce) != NULL) return CU16(2) == 1;
        return CU16(2) == 0;
    }
    case 87: {
        unsigned char var127 = *(unsigned char*)func_02094d6c();
        if (CU16(2) != 0) return var127 == 8;
        return var127 < 8;
    }
    case 88:
        if (CU16(2) >= 0x49) return 0;
        return func_0206dfb0((int)arg0, OBJB + 0x8c, CU16(2) + 0x33e);
    case 89:
        if (CU16(2) < 0x49) return !func_0206dfb0((int)arg0, OBJB + 0x8c, CU16(2) + 0x33e);
        return 1;
    case 90: {
        struct Struct_0205faf4_15 var128;
        func_020cf0fc((int)&var128);
        return var128.unknown_4_ == CU16(2) && var128.unknown_8_ == CU16(4);
    }
    case 91: {
        char* var129 = (char*)GetGameResources();
        return *((unsigned char*)arg1 + 4) == *(unsigned char*)(var129 + REGION_VALUE(0x4199, 0x4449)) && CU16(2) == *(signed char*)(var129 + REGION_VALUE(0x4196, 0x4446));
    }
    case 92: {
        struct Struct_0205faf4_8* var130 = func_02096134((struct Struct_0205faf4_7*)func_02094d6c(), CU16(2));
        if (var130 != NULL) return var130->unknown_1_1_ == 0;
        return 0;
    }
    case 93: {
        unsigned int var131 = 1 << CU16(2);
        return (FLAGS1840(func_02012fe4())->unknown_b4c_ & var131) ? 1 : 0;
    }
    case 94:
        return CU16(2) == FLAGS1840(func_02012fe4())->unknown_b3c_;
    case 95: {
        unsigned short var132 = *(unsigned short*)((char*)func_02012fe4() + REGION_VALUE(0x27f4, 0x27b4));
        return CS16(2) == var132;
    }
    case 96: {
        struct Struct_0203d028_3* var133 = (Struct_0203d028_3*)((GameState*)((struct Struct_0203d028_2*)(void*)GameState::GetInstance()))->GetProtagonist();
        if (var133 == NULL) return 0;
        int var134 = 0;
        int var135;
        for (var135 = 0; var135 < 13; var135++) {
            if (*(unsigned short*)(SUB150(var133) + (unsigned char)var135 * 2 + 0x16c) >= 99) var134++;
        }
        return var134 >= CU16(2);
    }
    case 97:
#if defined(jpn)
        return func_ov017_021b2718(*(void**)(inline_0205faf4((void*)GameState::GetInstance()) + 0x104)) == 0;
#else
        return 0;
#endif
    case 98:
        return *((unsigned char*)func_02012fe4() + REGION_VALUE(0x2810, 0x27d0)) <= CU16(2);
    case 99:
        return *((unsigned char*)func_02012fe4() + REGION_VALUE(0x2810, 0x27d0)) >= CU16(2);
    case 500: {
        struct Struct_0203d028_2* var136 = (struct Struct_0203d028_2*)(void*)GameState::GetInstance();
        int var137[4];
        int var138;
        func_02010834((struct Struct_02010834*)var136, func_020100a8((GameState*)var136), var137, &var138);
        int var139;
        for (var139 = 0; var139 < var138; var139++) {
            struct Struct_0203d028_3* var140 = (Struct_0203d028_3*)func_0200ff1c((GameState*)var136, var137[var139]);
            if (var140 == NULL) continue;
            if (!HasNibble56b(var140)) continue;
            if (CU16(2) != GetNibble56b(var140)) continue;
            if (*(int*)STAT130(var140) & 1) return CU16(4) == 0;
            return CU16(4) == 1;
        }
        return 0;
    }
    case 501:
        return CU16(2) == ((GameState*)((struct Struct_0203d028_2*)(void*)GameState::GetInstance()))->GetTimeOfDay();
    case 502:
        return func_02098ee8((struct Struct_0205faf4_12*)((char*)func_02012fe4() + REGION_VALUE(0x860, 0x840)));
    case 503:
        if (CU16(2) != 0) return func_0206dfb0((int)arg0, OBJB + 0x8c, 0x798);
        return !func_0206dfb0((int)arg0, OBJB + 0x8c, 0x798);
    case 504: {
        char* var141 = (char*)(void*)GameState::GetInstance();
        struct Struct_0205faf4_15 var142;
        func_020cf0fc((int)&var142);
        struct Struct_0205faf4_16* var143 = (struct Struct_0205faf4_16*)(var141 + REGION_VALUE(0x543c, 0x569c));
        return var142.unknown_4_ == var143->unknown_1_4_ && var142.unknown_8_ == var143->unknown_2_0_;
    }
    case 505:
        return func_02011b50((void*)GameState::GetInstance(), 1);
    case 506:
        return func_0206e2dc((struct Struct_0205faf4_13*)arg0, CU16(2));
    case 507:
        return CU16(2) == *(unsigned short*)func_0200fd0c((GameState*)(void*)GameState::GetInstance());
    }
    return 0;
}
