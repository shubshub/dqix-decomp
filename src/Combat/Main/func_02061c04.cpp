#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/Field3b0.h"
#include "GameState/BattleRecordSnapshot.h"
#include "World/ZoneChest.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif
extern "C" void func_0206df6c(void *arg0, unsigned char *arg1, int arg2, int arg3);
extern "C" void *func_0202ae18(void);
extern "C" int func_0202b7d8(int *arg0);
struct Struct_0202c1a4;
extern "C" int func_0202c1a4(Struct_0202c1a4 *arg0);
extern "C" void func_ov017_021d0924(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_0206ece8(int arg0, int arg1, unsigned char *arg2, unsigned arg3);
extern "C" int func_0202c508(void *arg0);
extern "C" void *func_02012fe4(void);
void *GetPointerFromArray0x3c_0201e838(unsigned char *arr, unsigned idx);
struct AppendNode;
struct AppendList;
void AppendNodeToListField30_0206445c(int a, AppendNode *msg, AppendList *list);
void EnqueueEventTag147_021cdaa0();
void *GetGlobal02109418_02094d6c(void);
extern "C" int func_020961b0(void *g, int p1);
int TestBitInByteArray_0206dfb0(int obj, unsigned char *arr, int idx);
struct Struct020d9ae8;
void Init020d9ae8(Struct020d9ae8 *node, int mode);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4 *list, TailNode020469b4 *node);
extern "C" void func_0206e164(void *obj, int p1, int mode);
struct FindEntryById02096134Table;
void *FindEntryById02096134(FindEntryById02096134Table *table, int p1);
void SetBitWithOffset0206eb64(unsigned char *obj, int p2, int flag);
extern "C" void func_ov017_021c1a98(void *ctx, int flag);
void SetBitInArray0x8ec_02083acc(unsigned char*, int);
void PartyMember_LearnSpell(unsigned char*, int);
void ToggleElemKey2FlagInMap2010_020ae6e8(int key);
void SetElemFlag8IfOverlayActive020ae730(int key);
void SetElemFlag0x4PairAndNotify17_020ae7d4(int key);
void SetElemFlag0x4QuadAndNotify17_020ae880(int key);
void EnqueueEventTag23Field_021d0d58();
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
extern "C" void *func_ov017_021b8478(void *node);
int IsField0xcNonNegative_020a3694(int*);
struct Obj021aa16c;
void InitState60_021aa16c(Obj021aa16c*);
struct HeadList020469f8;
struct HeadNode020469f8;
void PrependNodeToHead(HeadList020469f8*, HeadNode020469f8*);
void Something_021a6b9c(void*, int);
void * GetStatFieldPointer02064904(void*, int, unsigned int);
extern "C" void func_ov017_021a5568(void *node);
void SetBytesAt20And21_021a55a4(unsigned char*, unsigned char, unsigned char);
void *GetBTRandom();
struct Random;
int NextRandomBetween(Random*, int, int);
int NextRandomMax(Random*, int);
extern short data_020e7de8[14];
extern "C" void *memmove(void *arg0, const void *arg1, unsigned int arg2);
struct Struct_02061c04_10 {
    short unknown_0_, unknown_2_, unknown_4_, unknown_6_;
    unsigned char unknown_8_;
    short unknown_a_;
    signed char unknown_c_;
    float unknown_10_;
};
extern "C" void func_ov017_021cd6d8(Struct_02061c04_10 *arg0);
extern "C" void func_0202ea10(unsigned char*, int, int);
extern "C" void func_0202ea3c(unsigned char*);
struct Struct_0202ea20;
extern "C" void func_0202ea20(Struct_0202ea20*);
extern "C" void *func_0208a9b4();
extern "C" void func_0202c288(void);
struct Struct_02061c04_11;
extern "C" void func_ov017_021b994c(Struct_02061c04_11*);
extern "C" void func_ov017_021d079c(unsigned char, unsigned char, unsigned short);
extern "C" void func_020ae990(int arg0);
extern "C" void func_020aea40(int arg0, int arg1);
extern "C" void func_ov017_02191484(void *arg0);
extern "C" void func_020d3c08(char*);
struct Struct_02061c04_12;
extern "C" void func_020d3c28(Struct_02061c04_12*);
extern "C" void * func_020d3d78(unsigned char*, int);
extern "C" void func_ov017_021913d0(void *arg0, int arg1);
struct Struct_02061c04_13 { unsigned char unknown_0_0_ : 3; unsigned char unknown_0_3_ : 5; };
extern int data_02108844;
extern "C" void func_ov017_0218b664(char*);
extern "C" void func_ov017_021d0860(int, int, int);
extern "C" void func_ov017_02198f70(void*, int);
extern "C" void func_ov017_0219c520(void);
extern "C" void func_ov017_0218d7b0(unsigned char*, char*);
struct Struct_02061c04_14 { unsigned int unknown_0_0_ : 17; unsigned int unknown_2_1_ : 1; };

struct Struct_0205faf4_3;
extern "C" int func_0206e120(Struct_0205faf4_3*, int);
struct Struct_02061c04_15;
extern "C" void func_020d9dec(Struct_02061c04_15*, int);
struct Struct_02061c04_16;
extern "C" void func_020d9fb4(Struct_02061c04_16*, int);
extern "C" void * func_02010828(GameState*);
extern "C" int func_0201079c(char*);
extern "C" int func_020107d0(char*);
extern "C" int func_02010804(char*);
extern "C" void func_0206e080(char*, int);
extern "C" void func_0206e0d0(char*, int);
extern "C" void func_0206e348(unsigned char*, int, int);

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

struct Struct_02061c04_17 { unsigned short unknown_0_, unknown_2_, unknown_4_, unknown_6_, unknown_8_, unknown_a_; unsigned short unknown_c_[8]; };

struct Struct_02061c04_18 { unsigned short unknown_0_0_ : 4; unsigned short unknown_0_4_ : 12; };

extern "C" void func_020732cc(int arg0);
extern "C" void func_ov017_021d1c2c(unsigned char arg0, unsigned short arg1);
extern "C" void func_ov017_021d1dc0(unsigned short, int, int*, int, int);
extern AllocatorUnion data_02114e20;
extern "C" void *func_02012d88(AllocatorUnion *arg0, unsigned int arg1);
extern "C" void func_02012da4(AllocatorUnion *arg0, void *arg1);
extern "C" void *func_02086f24(void *arg0, unsigned char arg1, SafeAllocator *arg2);
extern "C" void func_020aee04(unsigned short arg0, unsigned char arg1);
extern struct Struct_02109bf4 {
    char unknown_0_[0xc8];
    unsigned char unknown_c8_0_ : 2;
    unsigned char unknown_c8_2_ : 1;
} data_02109bf4;
extern "C" void func_020dac40(void);
extern "C" void * func_02053c6c(unsigned char*);
struct Struct_02061c04_22;
extern "C" void func_0208386c(Struct_02061c04_22*, int);
struct Struct_02061c04_23;
extern "C" void func_020a0a08(Struct_02061c04_23*, int, int);
extern "C" void func_020ae9f0(void);
extern "C" void func_020cf0fc(int arg0);
extern "C" void func_020cf1a8(int arg0);
extern "C" void func_02095cfc(int, int);
extern "C" int func_0202c540(void *arg0);
extern "C" void func_020ac0b4(void *arg0);
struct Struct_02061c04_24;
extern "C" void func_020643e0(Struct_02061c04_24*, Struct_02061c04_24*);
extern "C" int func_020a0870(Struct_02061c04* arg0);
extern "C" int func_020a090c(Struct_02061c04* arg0);
extern "C" int func_020a08a4(Struct_02061c04* arg0);
extern "C" int func_020a08d8(Struct_02061c04* arg0);

struct Struct_01ff91ac_2 {
    unsigned char unknown_0_[8];
    unsigned int unknown_8_0_ : 17;
    unsigned int unknown_a_1_ : 7;
    unsigned int unknown_b_0_ : 7;
    unsigned int unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 17;
    unsigned int unknown_e_1_ : 7;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    unsigned int unknown_14_0_ : 8;
    unsigned int unknown_15_0_ : 14;
    unsigned int unknown_16_6_ : 10;
    unsigned int unknown_18_0_ : 24;
    unsigned int unknown_1b_0_ : 1;
    unsigned int unknown_1b_1_ : 7;
    unsigned int unknown_1c_;
};
struct Struct_01ff91ac_3 { unsigned int unknown_0_0_ : 24; unsigned int unknown_3_0_ : 8; };
struct Struct_01ff91ac_4 { unsigned int unknown_0_0_ : 14; unsigned int unknown_1_6_ : 14; unsigned int unknown_3_4_ : 4; };
struct Struct_01ff91ac_5 { unsigned int unknown_0_0_ : 9; unsigned int unknown_1_1_ : 14; unsigned int unknown_2_7_ : 9; };
extern "C" void *func_0203cf4c(void);
extern "C" void *func_0203df78(void *arg0, int arg1);
struct Struct_0203e0a0;
extern "C" void * func_02040538(Struct_0203e0a0*);
extern "C" void func_020cf0fc(int arg0);
extern "C" int func_020ac2d4(int arg0, void *arg1, void *arg2, int arg3);
extern "C" void func_020ac104(void *arg0, void *arg1, int arg2);
extern char data_0211e33c;
extern "C" void * func_ov017_021bdbf0(unsigned char*);
extern "C" void * func_ov017_021beba4(char*);
struct Struct_02019508_3;
extern "C" void * func_02019508(Struct_02019508_3*, int, int);
extern "C" void func_0206ea8c(void *arg0, unsigned char arg1, short arg2, int arg3);
struct Struct_02013380;
extern "C" void func_02013380(Struct_02013380*, int, int);
extern "C" void func_020e1154(void *arg0);
extern "C" void func_ov017_021a9bc4(void *arg0, unsigned char arg1);
extern "C" void func_ov017_021a9a9c(void *arg0, unsigned char arg1, unsigned char arg2, unsigned short arg3, unsigned char arg4);
extern "C" void func_ov017_021a8614(void *arg0, short arg1, unsigned short arg2, unsigned short arg3, unsigned short arg4, unsigned short arg5);
extern "C" void func_ov017_021ce110(int arg0, unsigned short arg1, unsigned short arg2, unsigned char arg3);
extern "C" void func_0206e748(void *arg0, int arg1, int arg2, int arg3, int arg4);
struct Struct_02061c04_27;
struct Struct_02061c04_28;
extern "C" void func_02064af8(Struct_02061c04_28*, Struct_02061c04_27*);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(Struct_0205faf4_11*);
extern "C" void func_02048418(unsigned char*, unsigned short);
extern "C" void func_ov017_02191108(void *arg0, int arg1, int arg2, int arg3, int arg4);
struct Struct_02033b58;
extern "C" void func_02033b58(Struct_02033b58*, unsigned char);
extern "C" void *func_02027ca4(void);
struct Struct_02028bac;
extern "C" void * func_02028bac(Struct_02028bac*, int);
extern "C" void func_ov017_021a23b0(void *arg0, unsigned short arg1);
extern "C" void func_ov017_021c9544(int arg0, int arg1, int arg2, int arg3);
extern "C" int func_0202ba00(int *arg0);
extern "C" void func_020ac4f8(int arg0);
extern "C" void func_02010810(char*, int);
extern "C" int func_0201081c(char*);

// USA: func_02061c04
struct Struct_01ff91ac_6 { unsigned int unknown_0_; unsigned short unknown_4_, unknown_6_, unknown_8_; };
struct Struct_ov009_0218aa28 { int unknown_0_, unknown_4_, unknown_8_; };
struct Struct_02061c04_29 { int unknown_0_[3]; };
struct Struct_02061c04_30 { unsigned int unknown_0_0_ : 7; unsigned int unknown_0_7_ : 4; unsigned int unknown_1_3_ : 5;
                          unsigned int unknown_2_0_ : 5; unsigned int unknown_2_5_ : 6; };
union Struct_02061c04_31 { unsigned int unknown_0_; struct { unsigned int unknown_0_0_ : 9; unsigned int unknown_1_1_ : 2; unsigned int unknown_1_3_ : 3; } unknown1_0_; };
struct Struct_02061c04_32 { unsigned int unknown_0_0_ : 10; unsigned int unknown_1_2_ : 1; unsigned int unknown_1_3_ : 21; };
struct Struct_02061c04_33 { unsigned short unknown_0_0_ : 2; unsigned short unknown_0_2_ : 1; unsigned short unknown_0_3_ : 13; };

struct Struct_02061c04_4 { short unknown_0_; unsigned short unknown_2_; unsigned short unknown_4_, unknown_6_, unknown_8_, unknown_a_, unknown_c_, unknown_e_; };

static inline char *inline_02061c04(void *arg0) { return (char *)arg0 + REGION_VALUE(0x2c4, 0x104); }
static inline char *inline_02061c04_2(char *arg0) { return arg0 + REGION_VALUE(0x7000, 0x7400); }
struct Struct_02061c04_5 { char unknown_0_[REGION_VALUE(0x7000, 0x7400)]; };
static inline int inline_02061c04_3(void *arg0) { return *((unsigned char *)arg0 + 0x332); }
static inline int inline_02061c04_4(void *arg0) { return *(unsigned short *)((char *)*(void **)((char *)arg0 + 0x134) + 0x30); }
static inline int inline_01ff91ac() { return 0x6488; }
static inline int inline_02061c04_5(int arg0, int arg1) { return (int)(((long long)arg0 * arg1 + 0x800) >> 12); }
extern "C" ARM int func_02061c04(void *arg0, Struct_02061c04_17 *arg1, void *arg2) {
    char var0[REGION_VALUE(0xa4, 0xb8)];
    struct { int unknown_0_, unknown_4_, unknown_8_, unknown_c_; } var1;
    struct { int unknown_0_, unknown_4_, unknown_8_; } var2;
    struct Struct_ov009_0218aa28 var3;
    Struct_02061c04_17 var4;
    Struct_02061c04_17 var5;
    Struct_02061c04_17 var6;
    Struct_02061c04_17 var7;
    Struct_02061c04_17 var8;
    struct Struct_02061c04_10 var9;
    unsigned short var10[14];
    struct { int unknown_0_, unknown_4_, unknown_8_; } var11;
    SafeAllocator var12;
    struct Struct_ov009_0218aa28 var13;
    struct Struct_ov009_0218aa28 var14;
    struct Struct_ov009_0218aa28 var15;
    struct Struct_ov009_0218aa28 var16;
    struct Struct_02061c04_6 {
        short unknown_0_;
        short unknown_2_;
        unsigned int unknown_4_;
        unsigned short unknown_8_, unknown_a_, unknown_c_;
        unsigned char unknown_e_, unknown_f_;
        short unknown_10_;
        unsigned char unknown_12_, unknown_13_;
        struct Struct_02061c04_4 unknown_14_;
        struct Struct_02061c04_30 unknown_24_;
    } var17;
    switch (arg1->unknown_0_) {
    case 0x64: {
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_, 1);
        void *var18 = func_0202ae18();
        if (func_0202b7d8((int *)var18) && !func_0202c1a4((Struct_0202c1a4 *)var18))
            func_ov017_021d0924(0, 0, arg1->unknown_2_, 1);
        return 1;
    }
    case 0x65: {
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_, 0);
        void *var19 = func_0202ae18();
        if (func_0202b7d8((int *)var19) && !func_0202c1a4((Struct_0202c1a4 *)var19))
            func_ov017_021d0924(0, 0, arg1->unknown_2_, 0);
        return 1;
    }
    case 0x66: {
        unsigned char var20 = *((unsigned char *)arg0 + 0x332);
        func_0206df6c(arg0, (unsigned char *)arg0 + var20 * 0x1c + 3, arg1->unknown_2_, 1);
        void *var21 = func_0202ae18();
        if (func_0202b7d8((int *)var21) && !func_0202c1a4((Struct_0202c1a4 *)var21))
            func_ov017_021d0924(3, *((unsigned char *)arg0 + 0x332), arg1->unknown_2_, 1);
        return 1;
    }
    case 0x67: {
        unsigned char var22 = *((unsigned char *)arg0 + 0x332);
        func_0206df6c(arg0, (unsigned char *)arg0 + var22 * 0x1c + 3, arg1->unknown_2_, 0);
        void *var23 = func_0202ae18();
        if (func_0202b7d8((int *)var23) && !func_0202c1a4((Struct_0202c1a4 *)var23))
            func_ov017_021d0924(3, *((unsigned char *)arg0 + 0x332), arg1->unknown_2_, 0);
        return 1;
    }
    case 0x68: {
        unsigned char var24 = *((unsigned char *)arg0 + 0x332);
        func_0206df6c(arg0, (unsigned char *)arg0 + var24 * 0x1c + 0x10, arg1->unknown_2_, 1);
        void *var25 = func_0202ae18();
        if (func_0202b7d8((int *)var25) && !func_0202c1a4((Struct_0202c1a4 *)var25))
            func_ov017_021d0924(5, *((unsigned char *)arg0 + 0x332), arg1->unknown_2_, 1);
        return 1;
    }
    case 0x69: {
        unsigned char var26 = *((unsigned char *)arg0 + 0x332);
        func_0206df6c(arg0, (unsigned char *)arg0 + var26 * 0x1c + 0x10, arg1->unknown_2_, 0);
        void *var27 = func_0202ae18();
        if (func_0202b7d8((int *)var27) && !func_0202c1a4((Struct_0202c1a4 *)var27))
            func_ov017_021d0924(5, *((unsigned char *)arg0 + 0x332), arg1->unknown_2_, 0);
        return 1;
    }
    case 0x6a: {
        void *var28 = GetGameResources();
        unsigned char *var29 = *(unsigned char **)((char *)var28 + 0x4000 + REGION_VALUE(0x214, 0x4c4));
        func_0206ece8((int)var29, arg1->unknown_2_, var29, 0x80);
        func_0206ece8((int)var29, arg1->unknown_2_, var29 + 0x80, 0x80);
        return 1;
    }
    case 0x6b: {
        void *var30 = func_0202ae18();
        if (func_0202c508(var30))
            func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, 0x113a, ((unsigned char *)arg1)[2] == 0);
        return 1;
    }
    case 0x6c: {
        void *var31 = func_02012fe4();
        void *var32 = func_0201e838((unsigned char *)((char *)var31 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (var32) {
            if (*((unsigned char *)var32 + 0x2c) == arg1->unknown_4_ &&
                *((unsigned char *)var32 + 0x2d) == arg1->unknown_6_ &&
                *(short *)((char *)var32 + 0x20) == (short)arg1->unknown_2_) {
                Struct_02061c04_18 *var33 = (Struct_02061c04_18 *)((char *)var32 + 0x2e);
                if (!(var33->unknown_0_4_ & 1))
                    var33->unknown_0_4_ |= 4;
            }
            var32 = *(void **)((char *)var32 + 0x70);
        }
        return 1;
    }
    case 0x6d: {
        Zone3D* var34 = (Zone3D*)func_02012fe4();
        Struct_020134e0::Struct_02018300* var35 = (Struct_020134e0::Struct_02018300*)func_0201e838((unsigned char*)&var34->substruct_6c_, 2);
        while (var35) {
            if (!(var35->unknown_2c_.unknown1_0_.unknown_2_4_ & 1) &&
                var35->unknown_2c_.unknown1_0_.unknown_0_ == arg1->unknown_4_ &&
                var35->unknown_2c_.unknown1_0_.unknown_1_ == arg1->unknown_6_ &&
                var35->unknown_20_ == (short)arg1->unknown_2_) {
                func_02018300(var34, var35, 1, 1, 1);
            }
            var35 = var35->unknown_70_;
        }
        return 1;
    }
    case 0x99: {
        Zone3D* var36 = (Zone3D*)func_02012fe4();
        Struct_020134e0::Struct_02018300* var37 = (Struct_020134e0::Struct_02018300*)func_0201e838((unsigned char*)&var36->substruct_6c_, 2);
        while (var37) {
            if (!(var37->unknown_2c_.unknown1_0_.unknown_2_4_ & 1) &&
                var37->unknown_2c_.unknown1_0_.unknown_0_ == arg1->unknown_4_ &&
                var37->unknown_2c_.unknown1_0_.unknown_1_ == arg1->unknown_6_ &&
                var37->unknown_20_ == (short)arg1->unknown_2_) {
                var37->unknown_2c_.unknown1_0_.unknown_2_4_ |= 0x100;
                func_02018300(var36, var37, 0, 1, 1);
            }
            var37 = var37->unknown_70_;
        }
        return 1;
    }
    case 0x6e: {
        GameState *var38 = GameState::GetInstance();
        var38->SetTimeOfDay((TimeOfDay)arg1->unknown_2_);
        LightingManager *var39 = LightingManager::GetInstance();
        var39->dayNightTimer_ = var38->GetDayTimer();
        var39->timeOfDayIndex_ = var38->GetTimeOfDay();
        void *var40 = func_0202ae18();
        if (func_0202c508(var40))
            func_ov017_021cdaa0();
        return 1;
    }
    case 0x72:
        arg1->unknown_4_ = 1;
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x73:
        arg1->unknown_4_ = 1;
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x74:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x75:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x76:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x77:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x78:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x79: case 0x89: case 0xe1:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x7a:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x7b:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x7c:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x7d: {
        if (func_020961b0(func_02094d6c(), arg1->unknown_2_) == 0)
            return 0;
        if (!func_0206dfb0((int)arg0, (unsigned char *)arg0 + 0x8c, 0x119d)) {
            void *var41 = GetGameResources();
            void *var42 = *(void **)((char *)var41 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
            func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, 0x119d, 1);
            void *var43 = *(void **)((char *)var41 + 0x3000 + REGION_VALUE(0x9a0, 0xbc0));
            func_020d9ae8((Struct_02061c04_7 *)var43, 1);
            func_020469b4((Struct_0201bdac_2 *)var42, (Struct_0201bdac *)var43);
        }
        return 1;
    }
    case 0x7e: {
        int var44 = func_0206e120((Struct_0205faf4_3*)arg0, arg1->unknown_2_) == 2;
        if (!var44)
            return 1;
        void *var45 = GetGameResources();
        void *var46 = *(void **)((char *)var45 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *var47 = *(void **)((char *)var45 + 0x3000 + REGION_VALUE(0x99c, 0xbbc));
        func_020d9dec((Struct_02061c04_15*)var47, 0);
        func_020d9fb4((Struct_02061c04_16*)var47, 0);
        *(int *)((char *)var47 + 0x10) = arg1->unknown_2_;
        if (*((unsigned char *)var47 + 2) == 0)
            func_020469b4((Struct_0201bdac_2 *)var46, (Struct_0201bdac *)var47);
        return 1;
    }
    case 0x7f: {
        func_020cf0fc((int)&var1);
        func_020cf1a8((int)&var2);
        var17.unknown_24_.unknown_0_0_ = var1.unknown_0_;
        var17.unknown_24_.unknown_0_7_ = var1.unknown_4_;
        var17.unknown_24_.unknown_1_3_ = var1.unknown_8_;
        var17.unknown_24_.unknown_2_0_ = var2.unknown_0_;
        var17.unknown_24_.unknown_2_5_ = var2.unknown_4_;
        void *var48 = func_02094d6c();
        *(unsigned int *)((char *)var48 + arg1->unknown_2_ * 4 + 0x178) = *(unsigned int *)&var17.unknown_24_;
        func_02095cfc((int)var48, arg1->unknown_2_);
        return 1;
    }
    case 0x80:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x81:
        func_0206e164(arg0, arg1->unknown_2_, 1);
        return 1;
    case 0x82: {
        void *var49 = func_0202ae18();
        if (func_0202b7d8((int *)var49)) {
            func_02096134((Struct_0205faf4_7 *)func_02094d6c(), arg1->unknown_2_);
            if (!func_0202c1a4((Struct_0202c1a4 *)var49)) {
                if (arg1->unknown_4_ < 0x400)
                    func_ov017_021d0924(0, 0, arg1->unknown_4_, 1);
                func_0206eb64((unsigned char *)arg0, arg1->unknown_4_, 1);
            } else {
                func_0206eb64((unsigned char *)arg0, arg1->unknown_4_, 1);
            }
        } else {
            func_0206eb64((unsigned char *)arg0, arg1->unknown_4_, 1);
        }
        return 1;
    }
    case 0x83: {
        void *var50 = func_0202ae18();
        if (func_0202b7d8((int *)var50)) {
            void *var51 = func_02096134((Struct_0205faf4_7 *)func_02094d6c(), arg1->unknown_2_);
            if (!func_0202c1a4((Struct_0202c1a4 *)var50)) {
                if (!(var51 != 0 && ((struct Struct_02061c04_32 *)var51)->unknown_1_2_ == 1) &&
                    arg1->unknown_4_ < 0x400)
                    func_ov017_021d0924(0, 0, arg1->unknown_4_, 0);
                func_0206eb64((unsigned char *)arg0, arg1->unknown_4_, 0);
            } else {
                if (var51 != 0 && ((struct Struct_02061c04_32 *)var51)->unknown_1_2_ == 1)
                    func_0206eb64((unsigned char *)arg0, arg1->unknown_4_, 0);
            }
        } else {
            func_0206eb64((unsigned char *)arg0, arg1->unknown_4_, 0);
        }
        return 1;
    }
    case 0x84: {
        GameState *var52 = GameState::GetInstance();
        var17.unknown_14_.unknown_a_ = func_0201079c((char*)var52);
        var17.unknown_14_.unknown_c_ = func_020107d0((char*)var52);
        var17.unknown_14_.unknown_e_ = func_02010804((char*)var52);
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        if (var17.unknown_14_.unknown_a_ != arg1->unknown_4_)
            func_0206e080((char*)arg0, *((unsigned char *)arg0 + 0x332));
        if (var17.unknown_14_.unknown_c_ != arg1->unknown_6_)
            func_0206e0d0((char*)arg0, *((unsigned char *)arg0 + 0x332));
        return 1;
    }
    case 0x85: case 0x8a: case 0xe2:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x86: {
        void *var53 = func_0202ae18();
        if (func_0202b7d8((int *)var53))
            func_ov017_021ce110((unsigned char)arg1->unknown_4_, 1, arg1->unknown_2_, 1);
        switch (arg1->unknown_4_) {
        case 3:
            func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_, 1);
            func_ov017_021d0924(0, 0, arg1->unknown_2_, 1);
            if (func_0202c540(var53))
                func_0206e748(arg0, 0, 0, arg1->unknown_2_, 1);
            break;
        case 4: {
            func_0206df6c(arg0, (unsigned char *)arg0 + *((unsigned char *)arg0 + 0x332) * 0x1c + 3, arg1->unknown_2_, 1);
            func_ov017_021d0924(3, *((unsigned char *)arg0 + 0x332), arg1->unknown_2_, 1);
            if (func_0202c540(var53)) {
                int var54 = inline_02061c04_3(arg0);
                func_0206e748(arg0, 3, var54, arg1->unknown_2_, 1);
            }
            break;
        }
        case 5: {
            func_0206df6c(arg0, (unsigned char *)arg0 + *((unsigned char *)arg0 + 0x332) * 0x1c + 0x10, arg1->unknown_2_, 1);
            func_ov017_021d0924(5, *((unsigned char *)arg0 + 0x332), arg1->unknown_2_, 1);
            if (func_0202c540(var53)) {
                int var55 = inline_02061c04_3(arg0);
                func_0206e748(arg0, 5, var55, arg1->unknown_2_, 1);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x87: {
        void *var56 = func_0202ae18();
        if (func_0202b7d8((int *)var56))
            func_ov017_021ce110((unsigned char)arg1->unknown_4_, 0, arg1->unknown_2_, 1);
        switch (arg1->unknown_4_) {
        case 3:
            func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_, 0);
            func_ov017_021d0924(0, 0, arg1->unknown_2_, 0);
            if (func_0202c540(var56))
                func_0206e748(arg0, 0, 0, arg1->unknown_2_, 0);
            break;
        case 4: {
            func_0206df6c(arg0, (unsigned char *)arg0 + *((unsigned char *)arg0 + 0x332) * 0x1c + 3, arg1->unknown_2_, 0);
            func_ov017_021d0924(3, *((unsigned char *)arg0 + 0x332), arg1->unknown_2_, 0);
            if (func_0202c540(var56)) {
                int var57 = inline_02061c04_3(arg0);
                func_0206e748(arg0, 3, var57, arg1->unknown_2_, 0);
            }
            break;
        }
        case 5: {
            func_0206df6c(arg0, (unsigned char *)arg0 + *((unsigned char *)arg0 + 0x332) * 0x1c + 0x10, arg1->unknown_2_, 0);
            func_ov017_021d0924(5, *((unsigned char *)arg0 + 0x332), arg1->unknown_2_, 0);
            if (func_0202c540(var56)) {
                int var58 = inline_02061c04_3(arg0);
                func_0206e748(arg0, 5, var58, arg1->unknown_2_, 0);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x88: {
        void *var59 = func_02012fe4();
        void *var60 = func_0201e838((unsigned char *)((char *)var59 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (var60) {
            if (*((unsigned char *)var60 + 0x2c) == arg1->unknown_4_ &&
                *((unsigned char *)var60 + 0x2d) == arg1->unknown_6_ &&
                *(short *)((char *)var60 + 0x20) == (short)arg1->unknown_2_) {
                Struct_02061c04_18 *var61 = (Struct_02061c04_18 *)((char *)var60 + 0x2e);
                var61->unknown_0_4_ &= ~4;
            }
            var60 = *(void **)((char *)var60 + 0x70);
        }
        return 1;
    }
    case 0x8b: {
        GameState *var62 = GameState::GetInstance();
        void *var63 = func_02010828((GameState*)var62);
        unsigned int var64 = *(unsigned int *)((char *)var63 + 0xf6c) + *(unsigned int *)((char *)arg1 + 4);
        *(unsigned int *)((char *)var63 + 0xf6c) = var64;
        if (var64 > 9999999)
            *(unsigned int *)((char *)var63 + 0xf6c) = 9999999;
        return 1;
    }
    case 0x8c: {
        GameState *var65 = GameState::GetInstance();
        void *var66 = func_02010828((GameState*)var65);
        unsigned int var67 = *(unsigned int *)((char *)var66 + 0xf6c);
        unsigned int var68 = *(unsigned int *)((char *)arg1 + 4);
        *(unsigned int *)((char *)var66 + 0xf6c) = (var67 < var68) ? 0 : (var67 - var68);
        return 1;
    }
    case 0x8d:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x8e:
        func_0206e348((unsigned char*)arg0, arg1->unknown_2_, 1);
        return 1;
    case 0x8f: {
        if (arg1->unknown_2_ == 2)
            return 1;
        void *var69 = GetGameResources();
        void *var70 = ((SafeAllocator *)((char *)var69 + 0x164))->Allocate(0x30);
        if (var70) {
            func_02012fe4();
            struct Struct_02061c04_9 { short unknown_0_, unknown_2_; int unknown_4_, unknown_8_, unknown_c_, unknown_10_; int *unknown_14_; } *var71 = (struct Struct_02061c04_9 *)arg1;
            char *var72 = (char *)var70;
            *(short *)(var72 + 0) = (short)var71->unknown_4_;
            *(int *)(var72 + 0x14) = var71->unknown_8_;
            *(int *)(var72 + 0x1c) = var71->unknown_10_;
            *(int *)(var72 + 0x18) = var71->unknown_c_;
            int *var73 = var71->unknown_14_;
            *(int *)(var72 + 0x20) = var73[1];
            *(int *)(var72 + 0x28) = var73[3];
            *(int *)(var72 + 0x24) = var73[2];
            *(short *)(var72 + 2) = (short)(4096.0f * (3.14159274f * (float)var73[4] / 180.0f));
            short var74 = *(short *)(var72 + 2);
            int var75 = 0x6488;
            if (var74 > var75)
                *(short *)(var72 + 2) -= var75;
            else if (var74 < 0)
                *(short *)(var72 + 2) = var74 + 0x6488;

                var15.unknown_0_ = (*(int *)(var72 + 0x14) + *(int *)(var72 + 0x20)) >> 1;
            var15.unknown_4_ = (*(int *)(var72 + 0x18) + *(int *)(var72 + 0x24)) >> 1;
            var15.unknown_8_ = (*(int *)(var72 + 0x1c) + *(int *)(var72 + 0x28)) >> 1;
            *(struct Struct_02061c04_29 *)&var13 = *(struct Struct_02061c04_29 *)&var15;
            *(int *)(var72 + 4) = var13.unknown_0_;
            *(int *)(var72 + 8) = var13.unknown_4_;
            *(int *)(var72 + 0xc) = var13.unknown_8_;

            var16.unknown_0_ = *(int *)(var72 + 0x14) - *(int *)(var72 + 0x20);
            var16.unknown_4_ = *(int *)(var72 + 0x18) - *(int *)(var72 + 0x24);
            var16.unknown_8_ = *(int *)(var72 + 0x1c) - *(int *)(var72 + 0x28);
            *(struct Struct_02061c04_29 *)&var14 = *(struct Struct_02061c04_29 *)&var16;
            *(struct Struct_02061c04_29 *)&var3 = *(struct Struct_02061c04_29 *)&var14;
            int var76 = var3.unknown_0_ / 2;
            int var77 = var3.unknown_4_ / 2;
            int var78 = inline_02061c04_5(var77, var77);
            int var79 = inline_02061c04_5(var76, var76);
            *(int *)(var72 + 0x10) = var79 + var78;
            *(int *)(var72 + 0x2c) = 0;

            func_02064af8((Struct_02061c04_28*)arg0, (Struct_02061c04_27*)var70);
        }
        return 1;
    }
    case 0x90: {
        void *var80 = func_0202ae18();
        if (func_0202c540(var80))
            return 1;
        int var81 = func_0206e120((Struct_0205faf4_3*)arg0, arg1->unknown_2_) == 2;
        if (!var81)
            return 1;
        unsigned int *var82 = (unsigned int *)((char *)func_02094d6c() + 4);
        while (var82) {
            union Struct_02061c04_31 *var83 = (union Struct_02061c04_31 *)var82;
            if (var83->unknown1_0_.unknown_0_0_ == (unsigned short)arg1->unknown_2_) {
                var83->unknown1_0_.unknown_1_3_ = arg1->unknown_4_;
                break;
            }
            var82 = (unsigned int *)((char *)var82 + 0x10);
        }
        return 1;
    }
    case 0x91:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x92:
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_ + 0x776, 1);
        return 1;
    case 0x93:
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_ + 0x776, 0);
        return 1;
    case 0x94: {
        GameState *var84 = GameState::GetInstance();
        var17.unknown_14_.unknown_4_ = func_0201079c((char*)var84);
        var17.unknown_14_.unknown_6_ = func_020107d0((char*)var84);
        var17.unknown_14_.unknown_8_ = func_02010804((char*)var84);
        arg1->unknown_2_ = 5;
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    }
    case 0x95: {
        void *var85 = func_02012fe4();
        if (!var85)
            return 0;
        void *var86 = func_02019508((Struct_02019508_3*)var85, arg1->unknown_2_, arg1->unknown_4_);
        if (!var86) {
            func_0206ea8c(arg0, (unsigned char)arg1->unknown_2_, (short)(arg1->unknown_4_ + 0x80), 1);
            func_0206ea8c(arg0, (unsigned char)arg1->unknown_2_, (short)arg1->unknown_4_, 0);
            return 1;
        }
        func_02013380((Struct_02013380*)var86, arg1->unknown_2_, 0);
        return 1;
    }
    case 0x96: {
        void *var87 = func_02012fe4();
        if (!var87)
            return 0;
        void *var88 = func_02019508((Struct_02019508_3*)var87, arg1->unknown_2_, arg1->unknown_4_);
        if (!var88) {
            func_0206ea8c(arg0, (unsigned char)arg1->unknown_2_, (short)(arg1->unknown_4_ + 0x80), 0);
            func_0206ea8c(arg0, (unsigned char)arg1->unknown_2_, (short)arg1->unknown_4_, 1);
            return 1;
        }
        func_02013380((Struct_02013380*)var88, arg1->unknown_2_, 1);
        return 1;
    }
    case 0x97: {
        void *var89 = GetGameResources();
        void *var90 = *(void **)((char *)var89 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *var91 = *(void **)((char *)var89 + 0x3000 + REGION_VALUE(0x940, 0xb60));
        func_ov017_021bdbf0((unsigned char*)var91);
        *((unsigned char *)var91 + 0x11) = arg1->unknown_2_;
        func_020469f8((Struct_020469f8*)var90, (Struct_020469f8_2*)var91);
        return 1;
    }
    case 0x9b: {
        var4.unknown_0_ = 0x68;
        var4.unknown_2_ = arg1->unknown_4_;
        func_02061c04(arg0, &var4, arg2);
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    }
    case 0x9c: {
        var5.unknown_0_ = 0x7f;
        var5.unknown_2_ = arg1->unknown_2_;
        func_02061c04(arg0, &var5, arg2);
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    }
    case 0x9d: {
        switch ((short)arg1->unknown_4_) {
        case 0: var6.unknown_0_ = 0x7d; break;
        case 2: var6.unknown_0_ = 0x7f; break;
        case 3: var6.unknown_0_ = 0x81; break;
        default: return 0;
        }
        var6.unknown_2_ = arg1->unknown_2_;
        func_02061c04(arg0, &var6, arg2);
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    }
    case 0x9e: {
        var7.unknown_0_ = 0x75;
        var7.unknown_2_ = arg1->unknown_2_;
        var7.unknown_4_ = arg1->unknown_4_;
        return func_02061c04(arg0, &var7, arg2);
    }
    case 0x9f: {
        var8.unknown_0_ = 0x74;
        var8.unknown_2_ = arg1->unknown_2_;
        var8.unknown_4_ = arg1->unknown_4_;
        return func_02061c04(arg0, &var8, arg2);
    }
    case 0xa0:
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_ + 0x113f, 1);
        return 1;
    case 0xa1: {
        var17.unknown_14_.unknown_2_ &= ~1;
        var17.unknown_14_.unknown_0_ = -1;
        var17.unknown_14_.unknown_2_ &= ~2;
        var17.unknown_14_.unknown_2_ &= ~0xfffcu;
        var17.unknown_0_ = arg1->unknown_2_;
        if (func_020ac2d4(0, &var17.unknown_0_, &var17.unknown_14_.unknown_0_, 1)) {
            var17.unknown_14_.unknown_2_ |= 2;
            func_020ac104(&data_0211e33c, &var17.unknown_14_.unknown_0_, 1);
        }
        return 1;
    }
    case 0xa2:
        if (arg1->unknown_2_ != 0)
            func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, 0x113b, 0);
        else
            func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, 0x113b, 1);
        return 1;
    case 0xc0: {
        GameState *var92 = GameState::GetInstance();
        void *var93 = func_02012fe4();
        func_0202ae18();
        var9.unknown_0_ = 0;
        var9.unknown_2_ = 0;
        var9.unknown_4_ = 0;
        var9.unknown_6_ = 0;
        var9.unknown_8_ = 0;
        var9.unknown_a_ = 0;
        var9.unknown_10_ = 0;
        var9.unknown_c_ = -1;
        var9.unknown_0_ = *(unsigned short *)var93;
        var9.unknown_2_ = arg1->unknown_2_;
        var9.unknown_4_ = 0;
        var9.unknown_8_ = 1;
        var9.unknown_6_ = -1;
        var9.unknown_10_ = var92->GetDayTimer();
        func_ov017_021cd6d8(&var9);
        return 1;
    }
    case 0xa4: {
        void *var94 = GetGameResources();
        func_ov017_021c1a98(var94, 0);
        return 1;
    }
    case 0xa5: {
        GameState *var95 = GameState::GetInstance();
        void *var96 = var95->GetGameObjectByIndex(0);
        func_02083acc((unsigned char*)(*(void **)((char *)var96 + REGION_VALUE(0x144, 0x150))), arg1->unknown_2_);
        return 1;
    }
    case 0xa6: {
        GameState *battle = GameState::GetInstance();
        void *combatant = battle->GetGameObjectByIndex(0);
        PartyMember_LearnSpell((unsigned char*)(*(void **)((char *)combatant + REGION_VALUE(0x144, 0x150))), msg->p1);
        return 1;
    }
    case 0xa7: {
        unsigned char var99 = ((unsigned char *)arg1)[2];
        if (var99 == 0)
            func_020ae6e8(((unsigned char *)arg1)[4]);
        else if (var99 == 6)
            func_020ae730(((unsigned char *)arg1)[4]);
        return 1;
    }
    case 0xa8:
        return 1;
    case 0xa9:
        if (((unsigned char *)arg1)[2] == 0)
            func_020ae7d4(((unsigned char *)arg1)[4]);
        return 1;
    case 0xaa:
        func_020ae880((unsigned char)arg1->unknown_2_);
        return 1;
    case 0xab:
        return 1;
    case 0xac:
        return 1;
    case 0xad:
        return 1;
    case 0xae:
        return 1;
    case 0xaf:
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_ + 0x1136, 0);
        return 1;
    case 0xb0: {
        void *var100 = func_02094d6c();
        Struct_02061c04_14 *var101 = (Struct_02061c04_14 *)func_02096134((Struct_0205faf4_7 *)var100, arg1->unknown_2_);
        if (var101)
            var101->unknown_2_1_ = arg1->unknown_4_;
        return 1;
    }
    case 0xb1: {
        GameState *var102 = GameState::GetInstance();
        var102->SetTimeOfDay((TimeOfDay)arg1->unknown_4_);
        LightingManager *var103 = LightingManager::GetInstance();
        var103->dayNightTimer_ = var102->GetDayTimer();
        var103->timeOfDayIndex_ = var102->GetTimeOfDay();
        var102->SetDayTimerRunning(arg1->unknown_2_ == 0);
        return 1;
    }
    case 0xb2: {
        void *var104 = GetGameResources();
        void *var105 = *(void **)((char *)var104 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *var106 = *(void **)((char *)var104 + 0x3000 + REGION_VALUE(0x948, 0xb68));
        func_020e1154((void *)0xbb8);
        func_ov017_021a9bc4(var106, ((unsigned char *)arg1)[2]);
        func_ov017_021a9a9c(var106, ((unsigned char *)arg1)[4], ((unsigned char *)arg1)[5], arg1->unknown_6_,
                            ((unsigned char *)arg1)[8]);
        func_020469b4((Struct_0201bdac_2 *)var105, (Struct_0201bdac *)var106);
        return 1;
    }
    case 0xb3: {
        GameState *var107 = GameState::GetInstance();
        void *var108 = func_02010828((GameState*)var107);
        if (arg1->unknown_2_ != 0) {
            func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, 0x113c, 1);
            *(unsigned int *)((char *)var108 + 0x2c94) = arg1->unknown_4_;
        } else {
            func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, 0x113c, 0);
            *(unsigned int *)((char *)var108 + 0x2c94) = *(unsigned int *)((char *)var107 + REGION_VALUE(0x7c34, 0x7e74));
            void *var109 = func_0202ae18();
            if (func_0202b7d8((int *)var109) && !func_0202c1a4((Struct_0202c1a4 *)var109))
                func_ov017_021d0d58();
        }
        return 1;
    }
    case 0xb4: {
        void *var110 = GetGameResources();
        void *var111 = *(void **)((char *)var110 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        if (!func_02046b60((Struct_02038598_5*)var111, 0xa))
            return 1;
        void *var112 = *(void **)((char *)var110 + 0x3000 + REGION_VALUE(0x508, 0x718));
        void *var113 = func_ov017_021b8478(var112);
        if (!func_020a3694((int*)var113))
            return 1;
        *(short *)((char *)var113 + 0x22) = (*(int *)((char *)var113 + 0xc) == arg1->unknown_2_) ? arg1->unknown_4_ : 0;
        return 1;
    }
    case 0xb5:
        return 1;
    case 0xb6:
        return 1;
    case 0xb7:
        return 1;
    case 0xb8: {
        void *var114 = GetGameResources();
        void *var115 = *(void **)((char *)var114 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *var116 = *(void **)((char *)var114 + 0x3000 + REGION_VALUE(0x968, 0xb88));
        func_ov017_021aa16c((Struct_02061c04_8*)var116);
        func_020469f8((Struct_020469f8*)var115, (Struct_020469f8_2*)var116);
        return 1;
    }
    case 0xb9: {
        void *var117 = GetGameResources();
        func_ov017_021a6b9c(var117, 0);
        return 1;
    }
    case 0xba:
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, 0x1138, arg1->unknown_2_);
        return 1;
    case 0xbb:
        *(unsigned short *)((char *)arg0 + 0x2ca) = 0;
        return 1;
    case 0xbc: {
        void *var118 = func_02064904(arg0, arg1->unknown_2_, arg1->unknown_4_);
        if (var118) {
            switch (arg1->unknown_8_) {
            case 0:
                *(unsigned short *)var118 = arg1->unknown_6_;
                break;
            case 1: {
                int var119 = *(unsigned short *)var118 + arg1->unknown_6_;
                if (var119 >= 0xffff)
                    *(unsigned short *)var118 = 0xffff;
                else
                    *(unsigned short *)var118 = var119;
                break;
            }
            case 2: {
                int var120 = *(unsigned short *)var118 - arg1->unknown_6_;
                if (var120 < 0)
                    *(unsigned short *)var118 = 0;
                else
                    *(unsigned short *)var118 = var120;
                break;
            }
            default:
                break;
            }
        }
        return 1;
    }
    case 0xbd: {
        void *var121 = GetGameResources();
        void *var122 = *(void **)((char *)var121 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *var123 = *(void **)((char *)var121 + 0x3000 + REGION_VALUE(0x50c, 0x71c));
        func_ov017_021a5568(var123);
        func_ov017_021a55a4((unsigned char*)var123, 1, ((unsigned char *)arg1)[2]);
        *(unsigned char *)((char *)var123 + 0x24) = 0;
        *(int *)((char *)var123 + 0x28) = 0;
        *(int *)((char *)var123 + 0x2c) = -1;
        func_020469b4((Struct_0201bdac_2 *)var122, (Struct_0201bdac *)var123);
        return 1;
    }
    case 0xbe: {
        if (!func_02096134((Struct_0205faf4_7 *)func_02094d6c(), arg1->unknown_2_))
            break;
        void *var124 = func_02064904(arg0, arg1->unknown_2_, arg1->unknown_4_);
        if (!var124)
            return 0;
        *(unsigned short *)var124 = NextRandomBetween((Random*)GetBTRandom(), arg1->unknown_6_, arg1->unknown_8_);
        return 1;
    }
    case 0xbf: {
        unsigned short var125 = 14;
        int var126 = 14;
        unsigned short *var127 = var10;
        unsigned short *var128 = (unsigned short *)data_020e7de8;
        do {
            *var127 = *var128;
            ++var128;
            ++var127;
        } while (--var126);
        void *var129 = func_02096134((Struct_0205faf4_7 *)func_02094d6c(), arg1->unknown_2_);
        if (!var129)
            break;
        for (int var130 = 0; var130 < 5; var130++) {
            int var131 = NextRandomMax((Random*)GetBTRandom(), var125);
            *(short *)((char *)var129 + var130 * 2 + 4) = var10[var131];
            if (var131 < var125 - 1)
                memmove(&var10[var131], &var10[var131 + 1], var125 - (var131 + 1));
            var125--;
            var10[var125] = 0;
        }
        return 1;
    }
    case 0xc1: {
        GameState *var132 = GameState::GetInstance();
        void *var133 = func_020100bc(var132);
        if (arg1->unknown_2_ != 0) {
            func_0202ea10((unsigned char*)var133, 0x333, 1);
            func_0202ea3c((unsigned char*)var133);
        } else {
            func_0202ea20((Struct_0202ea20*)var133);
        }
        return 1;
    }
    case 0xc2: {
        void *var134 = func_0208a9b4();
        *(unsigned char *)((char *)var134 + 0xa8) = arg1->unknown_2_ * 10;
        return 1;
    }
    case 0xc3:
        GetGameResources();
        return 1;
    case 0xc4:
        return 1;
    case 0xc5: {
        GameState *var135 = GameState::GetInstance();
        void *var136 = func_0202ae18();
        int var137 = func_0202ba00((int *)var136);
        int var138 = *((unsigned char *)var136 + 0x1000 + 0xd);
        int var139 = 0;
        if ((var137 == 5 && var138 > 1) || var137 == 6)
            var139 = 1;
        func_020ac4f8(var139);
        int var140 = func_0201081c((char*)var135);
        int var141 = arg1->unknown_2_;
        int var142 = var140;
        if (var140 >= 0xd && var140 <= 0xd) var142 = var140;
        else if (var140 >= 0xe && var140 <= 0xf) var142 = var140;
        else if (var140 >= 0x10 && var140 <= 0x11) var142 = var140;
        else if (var140 >= 0x12 && var140 <= 0x18) var142 = var140;
        else if (var140 >= 0x19 && var140 <= 0x1b) var142 = var140;
        else if (var140 >= 0x1c && var140 <= 0x21) var142 = var140;
        else if (var140 >= 0x22 && var140 <= 0x26) var142 = var140;
        else if (var140 >= 0x28 && var140 <= 0x5c) var142 = var140;
        else if (var140 >= 0x5d && var140 <= 0x5d) var142 = var140;
        else if (var140 >= 0x5e && var140 <= 0x64) var142 = var140;
        else if (var140 >= 0x65 && var140 <= 0x68) var142 = var140;
        else if (var140 >= 0x69 && var140 <= 0x6b) var142 = var140;
        else if (var140 >= 0x6c && var140 <= 0x71) var142 = var140;
        else if (var140 >= 0x7b && var140 <= 0x7c) var142 = var140;
        else if (var140 >= 0x7d && var140 <= 0x80) var142 = var140;
        else if (var140 >= 0x81 && var140 <= 0x85) var142 = var140;
        else if (var140 >= 0x86 && var140 <= 0x89) var142 = var140;
        else if (var140 >= 0x8a && var140 <= 0x8c) var142 = var140;
        else if (var140 >= 0x8d && var140 <= 0x92) var142 = var140;
        else if (var140 >= 0x94 && var140 <= 0x94) var142 = var140;
        int var143 = var141;
        if (var141 >= 0xd && var141 <= 0xd) var143 = var141;
        else if (var141 >= 0xe && var141 <= 0xf) var143 = var141;
        else if (var141 >= 0x10 && var141 <= 0x11) var143 = var141;
        else if (var141 >= 0x12 && var141 <= 0x18) var143 = var141;
        else if (var141 >= 0x19 && var141 <= 0x1b) var143 = var141;
        else if (var141 >= 0x1c && var141 <= 0x21) var143 = var141;
        else if (var141 >= 0x22 && var141 <= 0x26) var143 = var141;
        else if (var141 >= 0x28 && var141 <= 0x5c) var143 = var141;
        else if (var141 >= 0x5d && var141 <= 0x5d) var143 = var141;
        else if (var141 >= 0x5e && var141 <= 0x64) var143 = var141;
        else if (var141 >= 0x65 && var141 <= 0x68) var143 = var141;
        else if (var141 >= 0x69 && var141 <= 0x6b) var143 = var141;
        else if (var141 >= 0x6c && var141 <= 0x71) var143 = var141;
        else if (var141 >= 0x7b && var141 <= 0x7c) var143 = var141;
        else if (var141 >= 0x7d && var141 <= 0x80) var143 = var141;
        else if (var141 >= 0x81 && var141 <= 0x85) var143 = var141;
        else if (var141 >= 0x86 && var141 <= 0x89) var143 = var141;
        else if (var141 >= 0x8a && var141 <= 0x8c) var143 = var141;
        else if (var141 >= 0x8d && var141 <= 0x92) var143 = var141;
        else if (var141 >= 0x94 && var141 <= 0x94) var143 = var141;
        if (var142 != var143) {
            memset(inline_02061c04_2(inline_02061c04(var135)) + 0xa4, 0, 0x28);
        }
        func_02010810((char*)var135, arg1->unknown_2_);
        return 1;
    }
    case 0xc6: {
        void *var144 = func_0202ae18();
        func_0202c288();
        int var145 = *((unsigned char *)var144 + 0x100d);
        if (var145 <= 1)
            return 0;
        void *var146 = GetGameResources();
        void *var147 = *(void **)((char *)var146 + 0x3000 + REGION_VALUE(0x500, 0x710));
        func_ov017_021b994c((Struct_02061c04_11*)var147);
        *((unsigned char *)var147 + 0x130) = 1;
        GameState *var148 = GameState::GetInstance();
        int var149 = *(int *)((char *)var148 + 0x5000 + REGION_VALUE(0x4c4, 0x724));
        func_ov017_021d079c(4, 0, (unsigned short)var149);
        *(int *)((char *)var147 + 0x12c) = var149;
        return 1;
    }
    case 0xc7:
        func_020ae990(arg1->unknown_2_ & 0xff);
        return 1;
    case 0xc8:
        return 1;
    case 0xc9: {
        unsigned char var150 = ((unsigned char *)arg1)[2];
        if (var150 <= 7)
            func_020aea40(var150, ((unsigned char *)arg1)[4]);
        return 1;
    }
    case 0xca:
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_ + 0x1198, 1);
        return 1;
    case 0xcb: {
        GameState *var151 = GameState::GetInstance();
        void *var152 = GetGameResources();
        for (int var153 = 0; var153 < 4; var153++) {
            GameObject *var154 = func_0200ff1c(var151, var153);
            if (!var154)
                continue;
            if (!func_02061bd8((Struct_0205faf4_11*)var154))
                continue;
            int var155 = *(unsigned short *)((char *)*(void **)((char *)var154 + 0x130) + 4);
            if (var155 > 0)
                continue;
            if (arg1->unknown_2_ == 0) {
                unsigned short var156 = *(unsigned short *)((char *)var154->baseStats_ + 0x30);
                func_02053fe4(var154, var156, 1);
            } else if (arg1->unknown_2_ == 1) {
                int var157 = inline_02061c04_4(var154);
                func_02053fe4(var154, var157 / 2, 1);
            } else {
                func_02053fe4(var154, 1, 1);
            }
            func_02048418((unsigned char*)var154, 1);
            func_ov017_02191108(var152, 1, 1, 1, 1);
            func_02033b58((Struct_02033b58*)var154, 0);
            *(short *)((char *)var154 + 0xb2) = 0;
        }
        return 1;
    }
    case 0xcc:
        func_ov017_02191484(GetGameResources());
        return 1;
    case 0xcd: {
        void *var158 = GetGameResources();
        func_020d3c08((char*)var0);
        func_020d3c28((Struct_02061c04_12*)var0);
        void *var159 = func_020d3d78((unsigned char*)var0, arg1->unknown_2_);
        if (var159) {
            Struct_02061c04_13 *var160 = (Struct_02061c04_13 *)((char *)var159 + REGION_VALUE(0xb, 0x10));
            func_ov017_021913d0(var158, var160->unknown_0_0_);
        }
        return 1;
    }
    case 0xce: {
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, 0x79a, 1);
        void *var161 = func_0202ae18();
        if (func_0202c508(var161)) {
            int var162;
            GameState *var163 = GameState::GetInstance();
            void *var164 = GetGameResources();
            void *var165 = func_02027ca4();
            for (int var166 = 0; var166 < 4; var166++) {
                void *var167 = func_02028bac((Struct_02028bac*)var165, var166);
                if (!((struct Struct_02061c04_33 *)((char *)var167 + 2))->unknown_0_2_)
                    continue;
                unsigned short var168 = *(unsigned short *)var167;
                if ((var168 / 100) * 100 != 400)
                    continue;
                var162 = var166 * 0xc + 0x70;
                for (int var169 = 0; var169 < 0xc; var169++) {
                    void *var170 = var163->GetMaybeFieldMonsterByIndex(var169 + var162);
                    if (!var170)
                        continue;
                    unsigned short var171 = *(unsigned short *)((char *)var170 + 0x100 + 0x6a);
                    func_ov017_021a23b0(var164, var171);
                    short var172 = *(short *)((char *)var170 + 2);
                    unsigned short var173 = *(unsigned short *)var167;
                    func_ov017_021c9544(var173, var169, var172, -1);
                }
            }
        }
        return 1;
    }
    case 0xcf: {
        void *var174 = &data_02108844;
        if (var174)
            func_0206df6c(var174, (unsigned char *)var174 + 0x8c, 0x384, arg1->unknown_2_);
        void *var175 = GetGameResources();
        for (int var176 = 0; var176 < 4; var176++)
            *(unsigned short *)((char *)var175 + REGION_VALUE(0x4100, 0x4400) + var176 * 2 + REGION_VALUE(0x9a, 0x4a)) =
                *(unsigned short *)((char *)arg1 + var176 * 2 + 4);
        return 1;
    }
    case 0xd0: {
        void *var177 = func_0202ae18();
        if (func_0202c508(var177)) {
            GameState *var178 = GameState::GetInstance();
            void *var179 = func_02010828((GameState*)var178);
            *(unsigned int *)((char *)var179 + 0x2c94) = arg1->unknown_2_;
            *(unsigned int *)((char *)var178 + REGION_VALUE(0x7c34, 0x7e74)) = arg1->unknown_2_;
            func_ov017_021d0d58();
        }
        return 1;
    }
    case 0xd1: {
        void *var180 = GetGameResources();
        void *var181 = func_0202ae18();
        func_0202c288();
        int var182 = *((unsigned char *)var181 + 0x100d);
        if (var182 <= 1)
            return 1;
        func_ov017_0218b664((char*)var180);
        GameState::GetInstance();
        signed char var183 = *((signed char *)var180 + REGION_VALUE(0x4196, 0x4446));
        func_ov017_021d0860(4, 0, var183);
        *((unsigned char *)var180 + REGION_VALUE(0x4198, 0x4448)) = 1;
        var183 = *((signed char *)var180 + REGION_VALUE(0x4196, 0x4446));
        *((unsigned char *)var180 + REGION_VALUE(0x4197, 0x4447)) = var183;
        return 0;
    }
    case 0xd2: {
        void *var184 = GetGameResources();
        func_ov017_02198f70(var184, *((signed char *)var184 + REGION_VALUE(0x4196, 0x4446)));
        return 1;
    }
    case 0xd3: {

        struct Struct_02061c04_19
        {
              char unknown_0_[0x1840];
            struct Struct_02061c04_20 {
                char unknown_0_[0xb4c];
                unsigned int unknown_b4c_;
            } unknown_1840_;
        };

        struct Struct_02061c04_21 {
            char unknown_0_[0x1000];
            Struct_02061c04_19::Struct_02061c04_20 unknown_1000_;
        };
        unsigned int var185 = 1 << arg1->unknown_2_;
        ((Struct_02061c04_21 *)((char *)func_02012fe4() + REGION_VALUE(0x860, 0x840)))->unknown_1000_.unknown_b4c_ |= var185;
        return 1;
    }
    case 0xd4:
        func_ov017_0219c520();
        return 1;
    case 0xd5: {
        var17.unknown_e_ = 0;
        var17.unknown_f_ = 0;
        var17.unknown_10_ = 0;
        var17.unknown_12_ = 0;
        var17.unknown_13_ = 0;
        var17.unknown_e_ = (arg1->unknown_4_ == 0);
        var17.unknown_f_ = (arg1->unknown_6_ == 0);
        var17.unknown_10_ = arg1->unknown_8_;
        var17.unknown_12_ = (arg1->unknown_a_ == 0);
        void *var186 = GetGameResources();
        func_ov017_0218d7b0((unsigned char*)var186, (char*)&var17.unknown_e_);
        return 1;
    }
    case 0xd6: {
        GameState *var187 = GameState::GetInstance();
        var17.unknown_8_ = func_0201079c((char*)var187);
        var17.unknown_a_ = func_020107d0((char*)var187);
        var17.unknown_c_ = func_02010804((char*)var187);
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    }
    case 0xd7: {
        void *var188 = GetGameResources();
        func_ov017_021a8614(var188, (short)arg1->unknown_2_, arg1->unknown_4_, arg1->unknown_6_, arg1->unknown_8_, arg1->unknown_a_);
        return 1;
    }
    case 0xd8: {
        int var189 = *(short *)((char *)arg1 + 2);
        void *var190 = func_0202ae18();
        if (func_0202c508(var190)) {
            void *var191 = func_02012fe4();
            *(short *)((char *)var191 + 0x2700 + REGION_VALUE(0xf4, 0xb4)) = var189;
            if (func_0202b7d8((int *)var190)) {
                func_ov017_021d1c2c(var189, 0);
                func_ov017_021d1dc0((unsigned short)var189, 0, (int *)&var11, 0, 0);
            }
        }
        return 1;
    }
    case 0xd9: {
        void *var192 = GetGameResources();
        void *var193 = *(void **)((char *)var192 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *var194 = *(void **)((char *)var192 + 0x3000 + REGION_VALUE(0x94c, 0xb6c));
        func_ov017_021beba4((char*)var194);
        func_020469b4((Struct_0201bdac_2 *)var193, (Struct_0201bdac *)var194);
        return 1;
    }
    case 0xda:
        func_020732cc(arg1->unknown_2_);
        return 1;
    case 0xdb: {
        var12.ResetAllocatorPointer();
        var12.ResetAllocatorPointer();
        void *var195 = func_02012d88(&data_02114e20, 0x1000);
        var12.CreateTypeA(var195, 0x1000);
        var12.Reset();
        GameState *var196 = GameState::GetInstance();
        void *var197 = func_02010828((GameState*)var196);
        void *var198 = func_02086f24(var197, (unsigned char)arg1->unknown_2_, &var12);
        void *var199 = var12.GetSignedAllocator();
        if (var199) {
            var12.Destroy();
            func_02012da4(&data_02114e20, var199);
        }
        return (int)var198;
    }
    case 0xdc:
        func_020aee04(arg1->unknown_2_, ((unsigned char *)arg1)[4]);
        return 1;
    case 0xdd: {
        void *var200 = GetGameResources();
        func_ov017_021c1a98(var200, 1);
        return 1;
    }
    case 0xde: {
        void *var201 = func_02012fe4();
        *((unsigned char *)var201 + 0x2000 + REGION_VALUE(0x810, 0x7d0)) = 0;
        return 1;
    }
    case 0xdf:
        func_0206df6c(&data_02108844, (unsigned char *)&data_02108844 + 0x8c, 0x799, arg1->unknown_2_);
        return 1;
    case 0xe0:
        func_0206df6c(&data_02108844, (unsigned char *)&data_02108844 + 0x8c, 0x798, arg1->unknown_2_);
        return 1;
    case 0xe3: {
        void *var202 = GetGameResources();
        (void)var202;
        func_020dac40();
        return 1;
    }
    case 0xe4: {
        struct Struct_01ff91ac {
          char unknown_0_[0xc8];
            unsigned char unknown_c8_0_ : 2;
            unsigned char unknown_c8_2_ : 1;
        };
        data_02109bf4.unknown_c8_2_ = !arg1->unknown_2_;
        return 1;
    }
    case 0xe5: {
        GameState *var203 = GameState::GetInstance();
        unsigned short var204 = *(unsigned short *)((char *)var203 + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9c, 0xdc));
        short var205 = *(short *)((char *)var203 + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9e, 0xde));
        short var206 = *(short *)((char *)var203 + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0xa0, 0xe0));
        void *var207 = func_02010828((GameState*)var203);
        if (var204 == 0)
            return 1;
        if (var205 >= 0 && var205 <= 3) {
            GameObject *var208 = func_0200ff1c(var203, var205);
            if (!var208)
                return 1;
            void *var209 = func_02053c6c((unsigned char*)var208);
            func_0208386c((Struct_02061c04_22*)var209, (signed char)var206);
        } else {
            func_020a0a08((Struct_02061c04_23*)var207, (short)var204, 1);
        }
        return 1;
    }
    case 0xe6:
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, arg1->unknown_2_ + 0xbea, arg1->unknown_4_);
        return 1;
    case 0xe7: {
        void *var210 = func_0202ae18();
        if (func_0202c540(var210))
            return 1;
        func_0206df6c(arg0, (unsigned char *)arg0 + 0x8c, 0x796, arg1->unknown_2_);
        char *var211 = (char*)GameState::GetInstance();
        Struct_02061c04* var212 = (Struct_02061c04*)((char *)&((struct Struct_02061c04_5 *)inline_02061c04(var211))[1] + 0x3c);
        Struct_02061c04_3* var213 = &var212->unknown_90_;
        if (!var213->unknown_1b_0_) {
            void *var214 = func_02010828((GameState*)var211);
            int var215 = 0;
            void *var216 = ((GameState*)var211)->GetProtagonist();
            if (var216)
                var215 = *(*(unsigned short **)((char *)var216 + 0x134) + 0x18);
            var17.unknown_4_ = 0;
            func_020ac0b4((void *)&var17.unknown_4_);
            func_020643e0((Struct_02061c04_24*)&var213->unknown_0_, (Struct_02061c04_24*)&var212->unknown_0_.unknown_0_);
            func_020643e0((Struct_02061c04_24*)&var213->unknown_4_, (Struct_02061c04_24*)&var212->unknown_0_.unknown_4_);
            var213->unknown_8_0_ = var212->unknown_8_0_;
            var213->unknown_a_1_ = func_020a0870(var212);
            var213->unknown_b_0_ = func_020a090c(var212);
            var213->unknown_c_0_ = var17.unknown_4_;
            var213->unknown_e_1_ = func_020a08a4(var212);
            var213->unknown_f_0_ = func_020a08d8(var212);
            var213->unknown_10_0_ = var212->unknown_10_0_;
            var213->unknown_11_1_ = var212->unknown_d_6_;
            var213->unknown_14_0_ = var212->unknown_b_0_;
            var213->unknown_15_0_ = var212->unknown_11_1_;
            var213->unknown_16_6_ = var215;
            var213->unknown_18_0_ = var212->unknown_40_0_;
            var213->unknown_1c_ = *(unsigned int *)((char *)var214 + 0xf6c) + *(unsigned int *)((char *)var214 + 0xf68);
            var213->unknown_1b_0_ = 1;
        }
        return 1;
    }
    case 0xe8: {
        void *var217 = func_0203cf4c();
        void *var218 = func_0203df78(var217, arg1->unknown_2_);
        if (!var218)
            return 1;
        void *var219 = func_02040538((Struct_0203e0a0*)var218);
        if (!var219)
            return 1;
        unsigned char var220 = *((unsigned char *)var219 + 0xa);
        var220 = (var220 & ~0x38) | (((unsigned char)arg1->unknown_4_ & 7) << 3);
        *((unsigned char *)var219 + 0xa) = var220;
        return 1;
    }
    case 0xe9:
        func_020ae9f0();
        return 1;
    case 0x6f: case 0x70: case 0x71: case 0x98: case 0x9a: case 0xa3:
        break;
    default:
        break;
    }
    return 0;
}
