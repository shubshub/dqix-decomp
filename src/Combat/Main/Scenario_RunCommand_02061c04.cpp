#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/Field3b0.h"
#include "GameState/BattleRecordSnapshot.h"
#include "World/ZoneChest.h"
#include "Resource/GameResources.h"

extern "C" void Scenario_SetFlag(void *obj, unsigned char *arr, int idx, int flag);
extern "C" void *LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int *ctx);
struct SearchStruct0202c1a4;
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4 *ctx);
extern "C" void func_ov017_021d0924(int a, int b, int p1, int flag);
extern "C" void func_0206ece8(int a, int b, unsigned char *c, unsigned d);
extern "C" int LinkSession_IsHostOrSolo(void *ctx);
extern "C" void *Zone3D_GetInstance(void);
extern "C" void *ZoneFeatures_GetFirstOfType(unsigned char *arr, unsigned idx);
struct Struct_02061c04_25;
struct Struct_02061c04_26;
extern "C" void func_0206445c(int a, Struct_02061c04_25 *msg, Struct_02061c04_26 *list);
extern "C" void func_ov017_021cdaa0();
extern "C" void *func_02094d6c(void);
extern "C" int func_020961b0(void *g, int p1);
extern "C" int Scenario_TestFlag(int obj, unsigned char *arr, int idx);
struct Struct_02061c04_7;
extern "C" void func_020d9ae8(Struct_02061c04_7 *node, int mode);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4 *list, TailNode020469b4 *node);
extern "C" void func_0206e164(void *obj, int p1, int mode);
struct Struct_0205faf4_7;
extern "C" void *func_02096134(Struct_0205faf4_7 *table, int p1);
extern "C" void func_0206eb64(unsigned char *obj, int p2, int flag);
extern "C" void func_ov017_021c1a98(void *ctx, int flag);
extern "C" void func_02083acc(unsigned char*, int);
extern "C" void PartyMember_LearnSpell(unsigned char*, int);
extern "C" void func_020ae6e8(int key);
extern "C" void func_020ae730(int key);
extern "C" void func_020ae7d4(int key);
extern "C" void func_020ae880(int key);
extern "C" void func_ov017_021d0d58();
struct ListHead02046b60;
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" void *func_ov017_021b8478(void *node);
extern "C" int func_020a3694(int*);
struct Struct_02061c04_8;
extern "C" void func_ov017_021aa16c(Struct_02061c04_8*);
struct HeadList020469f8;
struct HeadNode020469f8;
extern "C" void func_020469f8(HeadList020469f8*, HeadNode020469f8*);
extern "C" void func_ov017_021a6b9c(void*, int);
extern "C" void * func_02064904(void*, int, unsigned int);
extern "C" void func_ov017_021a5568(void *node);
extern "C" void func_ov017_021a55a4(unsigned char*, unsigned char, unsigned char);
void *GetBTRandom();
struct Random;
int NextRandomBetween(Random*, int, int);
int NextRandomMax(Random*, int);
extern short data_020e7de8[14];
extern "C" void *memmove(void *dst, const void *src, unsigned int n);
struct Struct_02061c04_10 {
    short f0, f1, f2, f3;
    unsigned char f4;
    short unknown_a_;
    signed char unknown_c_;
    float unknown_10_;
};
extern "C" void func_ov017_021cd6d8(Struct_02061c04_10 *ev);
extern "C" void Camera_Shake(unsigned char*, int, int);
extern "C" void func_0202ea3c(unsigned char*);
struct Struct_0202ea20;
extern "C" void func_0202ea20(Struct_0202ea20*);
extern "C" void *func_0208a9b4();
extern "C" void LinkSession_UpdateMemberCount(void);
struct Struct_02061c04_11;
extern "C" void func_ov017_021b994c(Struct_02061c04_11*);
extern "C" void func_ov017_021d079c(unsigned char, unsigned char, unsigned short);
extern "C" void func_020ae990(int key);
extern "C" void func_020aea40(int a, int b);
extern "C" void func_ov017_02191484(void *base);
extern "C" void func_020d3c08(char*);
struct Struct_02061c04_12;
extern "C" void func_020d3c28(Struct_02061c04_12*);
extern "C" void * func_020d3d78(unsigned char*, int);
extern "C" void func_ov017_021913d0(void *base, int field);
struct Struct_02061c04_13 { unsigned char unknown_0_0_ : 3; unsigned char rest : 5; };
extern int g_scenario;
extern "C" void func_ov017_0218b664(char*);
extern "C" void func_ov017_021d0860(int, int, int);
extern "C" void func_ov017_02198f70(void*, int);
extern "C" void func_ov017_0219c520(void);
extern "C" void func_ov017_0218d7b0(unsigned char*, char*);
struct Struct_02061c04_14 { unsigned int pad : 17; unsigned int unknown_2_1_ : 1; };

struct PackedNibbleArray0206e120;
extern "C" int func_0206e120(PackedNibbleArray0206e120*, int);
struct Struct_02061c04_15;
extern "C" void func_020d9dec(Struct_02061c04_15*, int);
struct Struct_02061c04_16;
extern "C" void func_020d9fb4(Struct_02061c04_16*, int);
extern "C" void * GameState_GetParty(GameState*);
extern "C" int GameState_GetStoryChapter(char*);
extern "C" int GameState_GetStoryPart(char*);
extern "C" int GameState_GetStoryStep(char*);
extern "C" void func_0206e080(char*, int);
extern "C" void func_0206e0d0(char*, int);
extern "C" void func_0206e348(unsigned char*, int, int);

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

struct CmdMsg64 { unsigned short cmd, p1, p2, p3, p4, p5; unsigned short rest[8]; };

struct Struct_02061c04_18 { unsigned short unknown_0_0_ : 4; unsigned short unknown_0_4_ : 12; };

extern "C" void func_020732cc(int p1);
extern "C" void func_ov017_021d1c2c(unsigned char a, unsigned short b);
extern "C" void func_ov017_021d1dc0(unsigned short, int, int*, int, int);
extern AllocatorUnion g_mainAllocator;
extern "C" void *AllocatorUnion_AllocateRounded(AllocatorUnion *alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion *alloc, void *data);
extern "C" void *func_02086f24(void *p, unsigned char b, SafeAllocator *alloc);
extern "C" void func_020aee04(unsigned short a, unsigned char b);
extern struct Struct_02109bf4 {
    char unk[0xc8];
    unsigned char low : 2;
    unsigned char foo : 1;
} g_bgmPlayer;
extern "C" void func_020dac40(void);
extern "C" void * func_02053c6c(unsigned char*);
struct Struct_02061c04_22;
extern "C" void func_0208386c(Struct_02061c04_22*, int);
struct Struct_02061c04_23;
extern "C" void func_020a0a08(Struct_02061c04_23*, int, int);
extern "C" void func_020ae9f0(void);
extern "C" void func_020cf0fc(int p);
extern "C" void RTC_GetTime(int p);
extern "C" void func_02095cfc(int, int);
extern "C" int LinkSession_IsGuest(void *ctx);
extern "C" void func_020ac0b4(void *dst);
struct Struct_02061c04_24;
extern "C" void func_020643e0(Struct_02061c04_24*, Struct_02061c04_24*);
extern "C" int func_020a0870(Struct_02061c04* record);
extern "C" int func_020a090c(Struct_02061c04* record);
extern "C" int func_020a08a4(Struct_02061c04* record);
extern "C" int func_020a08d8(Struct_02061c04* record);

struct Struct_01ff91ac_2 {
    unsigned char head[8];
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
    unsigned int done : 1;
    unsigned int unknown_1b_1_ : 7;
    unsigned int total;
};
struct Struct_01ff91ac_3 { unsigned int v24 : 24; unsigned int unknown_3_0_ : 8; };
struct Struct_01ff91ac_4 { unsigned int lo : 14; unsigned int v14 : 14; unsigned int hi : 4; };
struct Struct_01ff91ac_5 { unsigned int unknown_0_0_ : 9; unsigned int v14 : 14; unsigned int hi : 9; };
extern "C" void *func_0203cf4c(void);
extern "C" void *func_0203df78(void *g, int key);
struct Struct_0203e0a0;
extern "C" void * func_02040538(Struct_0203e0a0*);
extern "C" void func_020cf0fc(int p);
extern "C" int func_020ac2d4(int a, void *p1, void *p2, int flag);
extern "C" void func_020ac104(void *arg0, void *p1, int flag);
extern char g_fileLoadBuffer;
extern "C" void * func_ov017_021bdbf0(unsigned char*);
extern "C" void * func_ov017_021beba4(char*);
struct Base02019508;
extern "C" void * Zone3D_FindSceneElement(Base02019508*, int, int);
extern "C" void func_0206ea8c(void *obj, unsigned char a, short b, int flag);
struct Struct02013380;
extern "C" void BmdjSceneElement_SetShown(Struct02013380*, int, int);
extern "C" void func_020e1154(void *p);
extern "C" void FieldTask_InitAcquireTreasureMap(void *node, unsigned char b);
extern "C" void AcquireTreasureMapTask_CreateMap(void *node, unsigned char a, unsigned char b, unsigned short c, unsigned char d);
extern "C" void func_ov017_021a8614(void *base, short p1, unsigned short p2, unsigned short p3, unsigned short p4, unsigned short p5);
extern "C" void func_ov017_021ce110(int a, unsigned short b, unsigned short c, unsigned char d);
extern "C" void func_0206e748(void *obj, int a, int b, int c, int d);
struct Struct_02061c04_27;
struct Struct_02061c04_28;
extern "C" void func_02064af8(Struct_02061c04_28*, Struct_02061c04_27*);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(Struct_0205faf4_11*);
extern "C" void func_02048418(unsigned char*, unsigned short);
extern "C" void Party_ReformLine(void *base, int a, int b, int c, int d);
struct Foo02033b58;
extern "C" void GameObject_StoreMotionState(Foo02033b58*, unsigned char);
extern "C" void *ZoneRecords_GetInstance(void);
struct Element0x318_02028bac;
extern "C" void * ZoneRecords_GetAt(Element0x318_02028bac*, int);
extern "C" void func_ov017_021a23b0(void *base, unsigned short v);
extern "C" void func_ov017_021c9544(int a, int b, int c, int d);
extern "C" int LinkSession_GetState(int *ctx);
extern "C" void GameState_UpdatePlayClocks(int flag);
extern "C" void func_02010810(char*, int);
extern "C" int func_0201081c(char*);

// USA: Scenario_RunCommand
struct Struct_01ff91ac_6 { unsigned int word0; unsigned short h4, h6, h8; };
struct Vec3 { int x, y, z; };
struct Struct_02061c04_29 { int w[3]; };
struct Struct_02061c04_30 { unsigned int f0 : 7; unsigned int f1 : 4; unsigned int f2 : 5;
                          unsigned int f3 : 5; unsigned int f4 : 6; };
union Struct_02061c04_31 { unsigned int w; struct { unsigned int id : 9; unsigned int unknown_1_1_ : 2; unsigned int slot : 3; } b; };
struct Struct_02061c04_32 { unsigned int pad0 : 10; unsigned int unknown_1_2_ : 1; unsigned int unknown_1_3_ : 21; };
struct Struct_02061c04_33 { unsigned short pad0 : 2; unsigned short bit2 : 1; unsigned short rest : 13; };

struct Struct_02061c04_4 { short opt; unsigned short flags; unsigned short h4, h6, h8, ha, hc, he; };

static inline char *inline_02061c04(void *b) { return (char *)b + REGION_VALUE(0x2c4, 0x104); }
static inline char *inline_02061c04_2(char *a) { return a + REGION_VALUE(0x7000, 0x7400); }
struct Struct_02061c04_5 { char pad[REGION_VALUE(0x7000, 0x7400)]; };
static inline int inline_02061c04_3(void *obj) { return *((unsigned char *)obj + 0x332); }
static inline int inline_02061c04_4(void *c) { return *(unsigned short *)((char *)*(void **)((char *)c + 0x134) + 0x30); }
static inline int inline_01ff91ac() { return 0x6488; }
static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }
// Main, originally func_02061c04 (USA 0x02061c04, EUR 0x02061c14, JPN 0x02062eec)
extern "C" ARM int Scenario_RunCommand(void *obj, CmdMsg64 *msg, void *param3) {
    char var0[REGION_VALUE(0xa4, 0xb8)];
    struct { int a0, a1, a2, a3; } sa;
    struct { int b0, b1, b2; } sb;
    struct Vec3 var3;
    CmdMsg64 m9b;
    CmdMsg64 m9c;
    CmdMsg64 m9d;
    CmdMsg64 m9e;
    CmdMsg64 m9f;
    struct Struct_02061c04_10 var9;
    unsigned short var10[14];
    struct { int a, b, c; } var11;
    SafeAllocator var12;
    struct Vec3 var13;
    struct Vec3 half;
    struct Vec3 var15;
    struct Vec3 diff;
    struct Struct_02061c04_6 {
        short p1;
        short pad2;
        unsigned int unknown_4_;
        unsigned short fh4, fh6, fh8;
        unsigned char unknown_e_, unknown_f_;
        short unknown_10_;
        unsigned char unknown_12_, unknown_13_;
        struct Struct_02061c04_4 fb;
        struct Struct_02061c04_30 packed;
    } lr;
    switch (msg->cmd) {
    case 0x64: {
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1, 1);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx) && !LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(0, 0, msg->p1, 1);
        return 1;
    }
    case 0x65: {
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1, 0);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx) && !LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(0, 0, msg->p1, 0);
        return 1;
    }
    case 0x66: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        Scenario_SetFlag(obj, (unsigned char *)obj + slot * 0x1c + 3, msg->p1, 1);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx) && !LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 1);
        return 1;
    }
    case 0x67: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        Scenario_SetFlag(obj, (unsigned char *)obj + slot * 0x1c + 3, msg->p1, 0);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx) && !LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 0);
        return 1;
    }
    case 0x68: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        Scenario_SetFlag(obj, (unsigned char *)obj + slot * 0x1c + 0x10, msg->p1, 1);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx) && !LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 1);
        return 1;
    }
    case 0x69: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        Scenario_SetFlag(obj, (unsigned char *)obj + slot * 0x1c + 0x10, msg->p1, 0);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx) && !LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 0);
        return 1;
    }
    case 0x6a: {
        void *p = GetGameResources();
        unsigned char *r5 = *(unsigned char **)((char *)p + 0x4000 + REGION_VALUE(0x214, 0x4c4));
        func_0206ece8((int)r5, msg->p1, r5, 0x80);
        func_0206ece8((int)r5, msg->p1, r5 + 0x80, 0x80);
        return 1;
    }
    case 0x6b: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsHostOrSolo(ctx))
            Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x113a, ((unsigned char *)msg)[2] == 0);
        return 1;
    }
    case 0x6c: {
        void *p0 = Zone3D_GetInstance();
        void *node = ZoneFeatures_GetFirstOfType((unsigned char *)((char *)p0 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (node) {
            if (*((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                Struct_02061c04_18 *f = (Struct_02061c04_18 *)((char *)node + 0x2e);
                if (!(f->unknown_0_4_ & 1))
                    f->unknown_0_4_ |= 4;
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x6d: {
        Zone3D* p0 = (Zone3D*)Zone3D_GetInstance();
        ZoneFeatures::Opcode6aEntry* node = (ZoneFeatures::Opcode6aEntry*)ZoneFeatures_GetFirstOfType((unsigned char*)&p0->substruct_6c_, 2);
        while (node) {
            if (!(node->unk_2c.type2.flags & DoorFlag_Open) &&
                node->unk_2c.type2.nodeId == msg->p2 &&
                node->unk_2c.type2.elementId == msg->p3 &&
                node->angle == (short)msg->p1) {
                Zone3D_OpenDoor(p0, node, 1, 1, 1);
            }
            node = node->pNext;
        }
        return 1;
    }
    case 0x99: {
        Zone3D* p0 = (Zone3D*)Zone3D_GetInstance();
        ZoneFeatures::Opcode6aEntry* node = (ZoneFeatures::Opcode6aEntry*)ZoneFeatures_GetFirstOfType((unsigned char*)&p0->substruct_6c_, 2);
        while (node) {
            if (!(node->unk_2c.type2.flags & DoorFlag_Open) &&
                node->unk_2c.type2.nodeId == msg->p2 &&
                node->unk_2c.type2.elementId == msg->p3 &&
                node->angle == (short)msg->p1) {
                node->unk_2c.type2.flags |= 0x100;
                Zone3D_OpenDoor(p0, node, 0, 1, 1);
            }
            node = node->pNext;
        }
        return 1;
    }
    case 0x6e: {
        GameState *battle = GameState::GetInstance();
        battle->SetTimeOfDay((TimeOfDay)msg->p1);
        LightingManager *d = LightingManager::GetInstance();
        d->dayNightTimer_ = battle->GetDayTimer();
        d->timeOfDayIndex_ = battle->GetTimeOfDay();
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsHostOrSolo(ctx))
            func_ov017_021cdaa0();
        return 1;
    }
    case 0x72:
        msg->p2 = 1;
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x73:
        msg->p2 = 1;
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x74:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x75:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x76:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x77:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x78:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x79: case 0x89: case 0xe1:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x7a:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x7b:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x7c:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x7d: {
        if (func_020961b0(func_02094d6c(), msg->p1) == 0)
            return 0;
        if (!Scenario_TestFlag((int)obj, (unsigned char *)obj + 0x8c, 0x119d)) {
            void *p = GetGameResources();
            void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
            Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x119d, 1);
            void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x9a0, 0xbc0));
            func_020d9ae8((Struct_02061c04_7 *)node, 1);
            func_020469b4((TailList020469b4 *)list, (TailNode020469b4 *)node);
        }
        return 1;
    }
    case 0x7e: {
        int var44 = func_0206e120((PackedNibbleArray0206e120*)obj, msg->p1) == 2;
        if (!var44)
            return 1;
        void *p = GetGameResources();
        void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x99c, 0xbbc));
        func_020d9dec((Struct_02061c04_15*)node, 0);
        func_020d9fb4((Struct_02061c04_16*)node, 0);
        *(int *)((char *)node + 0x10) = msg->p1;
        if (*((unsigned char *)node + 2) == 0)
            func_020469b4((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0x7f: {
        func_020cf0fc((int)&sa);
        RTC_GetTime((int)&sb);
        lr.packed.f0 = sa.a0;
        lr.packed.f1 = sa.a1;
        lr.packed.f2 = sa.a2;
        lr.packed.f3 = sb.b0;
        lr.packed.f4 = sb.b1;
        void *g = func_02094d6c();
        *(unsigned int *)((char *)g + msg->p1 * 4 + 0x178) = *(unsigned int *)&lr.packed;
        func_02095cfc((int)g, msg->p1);
        return 1;
    }
    case 0x80:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x81:
        func_0206e164(obj, msg->p1, 1);
        return 1;
    case 0x82: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx)) {
            func_02096134((Struct_0205faf4_7 *)func_02094d6c(), msg->p1);
            if (!LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx)) {
                if (msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 1);
                func_0206eb64((unsigned char *)obj, msg->p2, 1);
            } else {
                func_0206eb64((unsigned char *)obj, msg->p2, 1);
            }
        } else {
            func_0206eb64((unsigned char *)obj, msg->p2, 1);
        }
        return 1;
    }
    case 0x83: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx)) {
            void *entry = func_02096134((Struct_0205faf4_7 *)func_02094d6c(), msg->p1);
            if (!LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx)) {
                if (!(entry != 0 && ((struct Struct_02061c04_32 *)entry)->unknown_1_2_ == 1) &&
                    msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 0);
                func_0206eb64((unsigned char *)obj, msg->p2, 0);
            } else {
                if (entry != 0 && ((struct Struct_02061c04_32 *)entry)->unknown_1_2_ == 1)
                    func_0206eb64((unsigned char *)obj, msg->p2, 0);
            }
        } else {
            func_0206eb64((unsigned char *)obj, msg->p2, 0);
        }
        return 1;
    }
    case 0x84: {
        GameState *battle = GameState::GetInstance();
        lr.fb.ha = GameState_GetStoryChapter((char*)battle);
        lr.fb.hc = GameState_GetStoryPart((char*)battle);
        lr.fb.he = GameState_GetStoryStep((char*)battle);
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        if (lr.fb.ha != msg->p2)
            func_0206e080((char*)obj, *((unsigned char *)obj + 0x332));
        if (lr.fb.hc != msg->p3)
            func_0206e0d0((char*)obj, *((unsigned char *)obj + 0x332));
        return 1;
    }
    case 0x85: case 0x8a: case 0xe2:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x86: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx))
            func_ov017_021ce110((unsigned char)msg->p2, 1, msg->p1, 1);
        switch (msg->p2) {
        case 3:
            Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1, 1);
            func_ov017_021d0924(0, 0, msg->p1, 1);
            if (LinkSession_IsGuest(ctx))
                func_0206e748(obj, 0, 0, msg->p1, 1);
            break;
        case 4: {
            Scenario_SetFlag(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 3, msg->p1, 1);
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 1);
            if (LinkSession_IsGuest(ctx)) {
                int var54 = inline_02061c04_3(obj);
                func_0206e748(obj, 3, var54, msg->p1, 1);
            }
            break;
        }
        case 5: {
            Scenario_SetFlag(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 1);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 1);
            if (LinkSession_IsGuest(ctx)) {
                int var55 = inline_02061c04_3(obj);
                func_0206e748(obj, 5, var55, msg->p1, 1);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x87: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx))
            func_ov017_021ce110((unsigned char)msg->p2, 0, msg->p1, 1);
        switch (msg->p2) {
        case 3:
            Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1, 0);
            func_ov017_021d0924(0, 0, msg->p1, 0);
            if (LinkSession_IsGuest(ctx))
                func_0206e748(obj, 0, 0, msg->p1, 0);
            break;
        case 4: {
            Scenario_SetFlag(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 3, msg->p1, 0);
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 0);
            if (LinkSession_IsGuest(ctx)) {
                int var57 = inline_02061c04_3(obj);
                func_0206e748(obj, 3, var57, msg->p1, 0);
            }
            break;
        }
        case 5: {
            Scenario_SetFlag(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 0);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 0);
            if (LinkSession_IsGuest(ctx)) {
                int var58 = inline_02061c04_3(obj);
                func_0206e748(obj, 5, var58, msg->p1, 0);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x88: {
        void *p0 = Zone3D_GetInstance();
        void *node = ZoneFeatures_GetFirstOfType((unsigned char *)((char *)p0 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (node) {
            if (*((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                Struct_02061c04_18 *f = (Struct_02061c04_18 *)((char *)node + 0x2e);
                f->unknown_0_4_ &= ~4;
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x8b: {
        GameState *battle = GameState::GetInstance();
        void *p = GameState_GetParty((GameState*)battle);
        unsigned int v = *(unsigned int *)((char *)p + 0xf6c) + *(unsigned int *)((char *)msg + 4);
        *(unsigned int *)((char *)p + 0xf6c) = v;
        if (v > 9999999)
            *(unsigned int *)((char *)p + 0xf6c) = 9999999;
        return 1;
    }
    case 0x8c: {
        GameState *battle = GameState::GetInstance();
        void *p = GameState_GetParty((GameState*)battle);
        unsigned int v = *(unsigned int *)((char *)p + 0xf6c);
        unsigned int d = *(unsigned int *)((char *)msg + 4);
        *(unsigned int *)((char *)p + 0xf6c) = (v < d) ? 0 : (v - d);
        return 1;
    }
    case 0x8d:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x8e:
        func_0206e348((unsigned char*)obj, msg->p1, 1);
        return 1;
    case 0x8f: {
        if (msg->p1 == 2)
            return 1;
        void *base = GetGameResources();
        void *mem = ((SafeAllocator *)((char *)base + 0x164))->Allocate(0x30);
        if (mem) {
            Zone3D_GetInstance();
            struct Struct_02061c04_9 { short cmd, pad2; int f4, f8, fc, f10; int *f14; } *m = (struct Struct_02061c04_9 *)msg;
            char *n = (char *)mem;
            *(short *)(n + 0) = (short)m->f4;
            *(int *)(n + 0x14) = m->f8;
            *(int *)(n + 0x1c) = m->f10;
            *(int *)(n + 0x18) = m->fc;
            int *var73 = m->f14;
            *(int *)(n + 0x20) = var73[1];
            *(int *)(n + 0x28) = var73[3];
            *(int *)(n + 0x24) = var73[2];
            *(short *)(n + 2) = (short)(4096.0f * (3.14159274f * (float)var73[4] / 180.0f));
            short angle = *(short *)(n + 2);
            int var75 = 0x6488;
            if (angle > var75)
                *(short *)(n + 2) -= var75;
            else if (angle < 0)
                *(short *)(n + 2) = angle + 0x6488;

                var15.x = (*(int *)(n + 0x14) + *(int *)(n + 0x20)) >> 1;
            var15.y = (*(int *)(n + 0x18) + *(int *)(n + 0x24)) >> 1;
            var15.z = (*(int *)(n + 0x1c) + *(int *)(n + 0x28)) >> 1;
            *(struct Struct_02061c04_29 *)&var13 = *(struct Struct_02061c04_29 *)&var15;
            *(int *)(n + 4) = var13.x;
            *(int *)(n + 8) = var13.y;
            *(int *)(n + 0xc) = var13.z;

            diff.x = *(int *)(n + 0x14) - *(int *)(n + 0x20);
            diff.y = *(int *)(n + 0x18) - *(int *)(n + 0x24);
            diff.z = *(int *)(n + 0x1c) - *(int *)(n + 0x28);
            *(struct Struct_02061c04_29 *)&half = *(struct Struct_02061c04_29 *)&diff;
            *(struct Struct_02061c04_29 *)&var3 = *(struct Struct_02061c04_29 *)&half;
            int var76 = var3.x / 2;
            int var77 = var3.y / 2;
            int var78 = FxMul(var77, var77);
            int var79 = FxMul(var76, var76);
            *(int *)(n + 0x10) = var79 + var78;
            *(int *)(n + 0x2c) = 0;

            func_02064af8((Struct_02061c04_28*)obj, (Struct_02061c04_27*)mem);
        }
        return 1;
    }
    case 0x90: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsGuest(ctx))
            return 1;
        int var81 = func_0206e120((PackedNibbleArray0206e120*)obj, msg->p1) == 2;
        if (!var81)
            return 1;
        unsigned int *p = (unsigned int *)((char *)func_02094d6c() + 4);
        while (p) {
            union Struct_02061c04_31 *e = (union Struct_02061c04_31 *)p;
            if (e->b.id == (unsigned short)msg->p1) {
                e->b.slot = msg->p2;
                break;
            }
            p = (unsigned int *)((char *)p + 0x10);
        }
        return 1;
    }
    case 0x91:
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    case 0x92:
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x776, 1);
        return 1;
    case 0x93:
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x776, 0);
        return 1;
    case 0x94: {
        GameState *battle = GameState::GetInstance();
        lr.fb.h4 = GameState_GetStoryChapter((char*)battle);
        lr.fb.h6 = GameState_GetStoryPart((char*)battle);
        lr.fb.h8 = GameState_GetStoryStep((char*)battle);
        msg->p1 = 5;
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    }
    case 0x95: {
        void *p0 = Zone3D_GetInstance();
        if (!p0)
            return 0;
        void *entry = Zone3D_FindSceneElement((Base02019508*)p0, msg->p1, msg->p2);
        if (!entry) {
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)(msg->p2 + 0x80), 1);
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)msg->p2, 0);
            return 1;
        }
        BmdjSceneElement_SetShown((Struct02013380*)entry, msg->p1, 0);
        return 1;
    }
    case 0x96: {
        void *p0 = Zone3D_GetInstance();
        if (!p0)
            return 0;
        void *entry = Zone3D_FindSceneElement((Base02019508*)p0, msg->p1, msg->p2);
        if (!entry) {
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)(msg->p2 + 0x80), 0);
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)msg->p2, 1);
            return 1;
        }
        BmdjSceneElement_SetShown((Struct02013380*)entry, msg->p1, 1);
        return 1;
    }
    case 0x97: {
        void *p = GetGameResources();
        void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x940, 0xb60));
        func_ov017_021bdbf0((unsigned char*)node);
        *((unsigned char *)node + 0x11) = msg->p1;
        func_020469f8((HeadList020469f8*)list, (HeadNode020469f8*)node);
        return 1;
    }
    case 0x9b: {
        m9b.cmd = 0x68;
        m9b.p1 = msg->p2;
        Scenario_RunCommand(obj, &m9b, param3);
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    }
    case 0x9c: {
        m9c.cmd = 0x7f;
        m9c.p1 = msg->p1;
        Scenario_RunCommand(obj, &m9c, param3);
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    }
    case 0x9d: {
        switch ((short)msg->p2) {
        case 0: m9d.cmd = 0x7d; break;
        case 2: m9d.cmd = 0x7f; break;
        case 3: m9d.cmd = 0x81; break;
        default: return 0;
        }
        m9d.p1 = msg->p1;
        Scenario_RunCommand(obj, &m9d, param3);
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    }
    case 0x9e: {
        m9e.cmd = 0x75;
        m9e.p1 = msg->p1;
        m9e.p2 = msg->p2;
        return Scenario_RunCommand(obj, &m9e, param3);
    }
    case 0x9f: {
        m9f.cmd = 0x74;
        m9f.p1 = msg->p1;
        m9f.p2 = msg->p2;
        return Scenario_RunCommand(obj, &m9f, param3);
    }
    case 0xa0:
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x113f, 1);
        return 1;
    case 0xa1: {
        lr.fb.flags &= ~1;
        lr.fb.opt = -1;
        lr.fb.flags &= ~2;
        lr.fb.flags &= ~0xfffcu;
        lr.p1 = msg->p1;
        if (func_020ac2d4(0, &lr.p1, &lr.fb.opt, 1)) {
            lr.fb.flags |= 2;
            func_020ac104(&g_fileLoadBuffer, &lr.fb.opt, 1);
        }
        return 1;
    }
    case 0xa2:
        if (msg->p1 != 0)
            Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x113b, 0);
        else
            Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x113b, 1);
        return 1;
    case 0xc0: {
        GameState *battle = GameState::GetInstance();
        void *p0 = Zone3D_GetInstance();
        LinkSession_GetInstance();
        var9.f0 = 0;
        var9.f1 = 0;
        var9.f2 = 0;
        var9.f3 = 0;
        var9.f4 = 0;
        var9.unknown_a_ = 0;
        var9.unknown_10_ = 0;
        var9.unknown_c_ = -1;
        var9.f0 = *(unsigned short *)p0;
        var9.f1 = msg->p1;
        var9.f2 = 0;
        var9.f4 = 1;
        var9.f3 = -1;
        var9.unknown_10_ = battle->GetDayTimer();
        func_ov017_021cd6d8(&var9);
        return 1;
    }
    case 0xa4: {
        void *p = GetGameResources();
        func_ov017_021c1a98(p, 0);
        return 1;
    }
    case 0xa5: {
        GameState *battle = GameState::GetInstance();
        void *combatant = battle->GetGameObjectByIndex(0);
        func_02083acc((unsigned char*)(*(void **)((char *)combatant + REGION_VALUE(0x144, 0x150))), msg->p1);
        return 1;
    }
    case 0xa6: {
        GameState *battle = GameState::GetInstance();
        void *combatant = battle->GetGameObjectByIndex(0);
        PartyMember_LearnSpell((unsigned char*)(*(void **)((char *)combatant + REGION_VALUE(0x144, 0x150))), msg->p1);
        return 1;
    }
    case 0xa7: {
        unsigned char b = ((unsigned char *)msg)[2];
        if (b == 0)
            func_020ae6e8(((unsigned char *)msg)[4]);
        else if (b == 6)
            func_020ae730(((unsigned char *)msg)[4]);
        return 1;
    }
    case 0xa8:
        return 1;
    case 0xa9:
        if (((unsigned char *)msg)[2] == 0)
            func_020ae7d4(((unsigned char *)msg)[4]);
        return 1;
    case 0xaa:
        func_020ae880((unsigned char)msg->p1);
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
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1136, 0);
        return 1;
    case 0xb0: {
        void *global = func_02094d6c();
        Struct_02061c04_14 *entry = (Struct_02061c04_14 *)func_02096134((Struct_0205faf4_7 *)global, msg->p1);
        if (entry)
            entry->unknown_2_1_ = msg->p2;
        return 1;
    }
    case 0xb1: {
        GameState *battle = GameState::GetInstance();
        battle->SetTimeOfDay((TimeOfDay)msg->p2);
        LightingManager *d = LightingManager::GetInstance();
        d->dayNightTimer_ = battle->GetDayTimer();
        d->timeOfDayIndex_ = battle->GetTimeOfDay();
        battle->SetDayTimerRunning(msg->p1 == 0);
        return 1;
    }
    case 0xb2: {
        void *base = GetGameResources();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x948, 0xb68));
        func_020e1154((void *)0xbb8);
        FieldTask_InitAcquireTreasureMap(node, ((unsigned char *)msg)[2]);
        AcquireTreasureMapTask_CreateMap(node, ((unsigned char *)msg)[4], ((unsigned char *)msg)[5], msg->p3,
                            ((unsigned char *)msg)[8]);
        func_020469b4((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0xb3: {
        GameState *battle = GameState::GetInstance();
        void *p = GameState_GetParty((GameState*)battle);
        if (msg->p1 != 0) {
            Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x113c, 1);
            *(unsigned int *)((char *)p + 0x2c94) = msg->p2;
        } else {
            Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x113c, 0);
            *(unsigned int *)((char *)p + 0x2c94) = *(unsigned int *)((char *)battle + REGION_VALUE(0x7c34, 0x7e74));
            void *ctx = LinkSession_GetInstance();
            if (LinkSession_IsActive((int *)ctx) && !LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx))
                func_ov017_021d0d58();
        }
        return 1;
    }
    case 0xb4: {
        void *base = GetGameResources();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        if (!func_02046b60((ListHead02046b60*)list, 0xa))
            return 1;
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x508, 0x718));
        void *r = func_ov017_021b8478(node);
        if (!func_020a3694((int*)r))
            return 1;
        *(short *)((char *)r + 0x22) = (*(int *)((char *)r + 0xc) == msg->p1) ? msg->p2 : 0;
        return 1;
    }
    case 0xb5:
        return 1;
    case 0xb6:
        return 1;
    case 0xb7:
        return 1;
    case 0xb8: {
        void *base = GetGameResources();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x968, 0xb88));
        func_ov017_021aa16c((Struct_02061c04_8*)node);
        func_020469f8((HeadList020469f8*)list, (HeadNode020469f8*)node);
        return 1;
    }
    case 0xb9: {
        void *base = GetGameResources();
        func_ov017_021a6b9c(base, 0);
        return 1;
    }
    case 0xba:
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x1138, msg->p1);
        return 1;
    case 0xbb:
        *(unsigned short *)((char *)obj + 0x2ca) = 0;
        return 1;
    case 0xbc: {
        void *p = func_02064904(obj, msg->p1, msg->p2);
        if (p) {
            switch (msg->p4) {
            case 0:
                *(unsigned short *)p = msg->p3;
                break;
            case 1: {
                int v = *(unsigned short *)p + msg->p3;
                if (v >= 0xffff)
                    *(unsigned short *)p = 0xffff;
                else
                    *(unsigned short *)p = v;
                break;
            }
            case 2: {
                int v = *(unsigned short *)p - msg->p3;
                if (v < 0)
                    *(unsigned short *)p = 0;
                else
                    *(unsigned short *)p = v;
                break;
            }
            default:
                break;
            }
        }
        return 1;
    }
    case 0xbd: {
        void *base = GetGameResources();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x50c, 0x71c));
        func_ov017_021a5568(node);
        func_ov017_021a55a4((unsigned char*)node, 1, ((unsigned char *)msg)[2]);
        *(unsigned char *)((char *)node + 0x24) = 0;
        *(int *)((char *)node + 0x28) = 0;
        *(int *)((char *)node + 0x2c) = -1;
        func_020469b4((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0xbe: {
        if (!func_02096134((Struct_0205faf4_7 *)func_02094d6c(), msg->p1))
            break;
        void *p = func_02064904(obj, msg->p1, msg->p2);
        if (!p)
            return 0;
        *(unsigned short *)p = NextRandomBetween((Random*)GetBTRandom(), msg->p3, msg->p4);
        return 1;
    }
    case 0xbf: {
        unsigned short count = 14;
        int n = 14;
        unsigned short *dst = var10;
        unsigned short *src = (unsigned short *)data_020e7de8;
        do {
            *dst = *src;
            ++src;
            ++dst;
        } while (--n);
        void *entry = func_02096134((Struct_0205faf4_7 *)func_02094d6c(), msg->p1);
        if (!entry)
            break;
        for (int j = 0; j < 5; j++) {
            int idx = NextRandomMax((Random*)GetBTRandom(), count);
            *(short *)((char *)entry + j * 2 + 4) = var10[idx];
            if (idx < count - 1)
                memmove(&var10[idx], &var10[idx + 1], count - (idx + 1));
            count--;
            var10[count] = 0;
        }
        return 1;
    }
    case 0xc1: {
        GameState *battle = GameState::GetInstance();
        void *rec = battle->GetCamera();
        if (msg->p1 != 0) {
            Camera_Shake((unsigned char*)rec, 0x333, 1);
            func_0202ea3c((unsigned char*)rec);
        } else {
            func_0202ea20((Struct_0202ea20*)rec);
        }
        return 1;
    }
    case 0xc2: {
        void *d = func_0208a9b4();
        *(unsigned char *)((char *)d + 0xa8) = msg->p1 * 10;
        return 1;
    }
    case 0xc3:
        GetGameResources();
        return 1;
    case 0xc4:
        return 1;
    case 0xc5: {
        GameState *battle = GameState::GetInstance();
        void *ctx = LinkSession_GetInstance();
        int v = LinkSession_GetState((int *)ctx);
        int var138 = *((unsigned char *)ctx + 0x1000 + 0xd);
        int flag = 0;
        if ((v == 5 && var138 > 1) || v == 6)
            flag = 1;
        GameState_UpdatePlayClocks(flag);
        int cur = func_0201081c((char*)battle);
        int newVal = msg->p1;
        int a = cur;
        if (cur >= 0xd && cur <= 0xd) a = cur;
        else if (cur >= 0xe && cur <= 0xf) a = cur;
        else if (cur >= 0x10 && cur <= 0x11) a = cur;
        else if (cur >= 0x12 && cur <= 0x18) a = cur;
        else if (cur >= 0x19 && cur <= 0x1b) a = cur;
        else if (cur >= 0x1c && cur <= 0x21) a = cur;
        else if (cur >= 0x22 && cur <= 0x26) a = cur;
        else if (cur >= 0x28 && cur <= 0x5c) a = cur;
        else if (cur >= 0x5d && cur <= 0x5d) a = cur;
        else if (cur >= 0x5e && cur <= 0x64) a = cur;
        else if (cur >= 0x65 && cur <= 0x68) a = cur;
        else if (cur >= 0x69 && cur <= 0x6b) a = cur;
        else if (cur >= 0x6c && cur <= 0x71) a = cur;
        else if (cur >= 0x7b && cur <= 0x7c) a = cur;
        else if (cur >= 0x7d && cur <= 0x80) a = cur;
        else if (cur >= 0x81 && cur <= 0x85) a = cur;
        else if (cur >= 0x86 && cur <= 0x89) a = cur;
        else if (cur >= 0x8a && cur <= 0x8c) a = cur;
        else if (cur >= 0x8d && cur <= 0x92) a = cur;
        else if (cur >= 0x94 && cur <= 0x94) a = cur;
        int b = newVal;
        if (newVal >= 0xd && newVal <= 0xd) b = newVal;
        else if (newVal >= 0xe && newVal <= 0xf) b = newVal;
        else if (newVal >= 0x10 && newVal <= 0x11) b = newVal;
        else if (newVal >= 0x12 && newVal <= 0x18) b = newVal;
        else if (newVal >= 0x19 && newVal <= 0x1b) b = newVal;
        else if (newVal >= 0x1c && newVal <= 0x21) b = newVal;
        else if (newVal >= 0x22 && newVal <= 0x26) b = newVal;
        else if (newVal >= 0x28 && newVal <= 0x5c) b = newVal;
        else if (newVal >= 0x5d && newVal <= 0x5d) b = newVal;
        else if (newVal >= 0x5e && newVal <= 0x64) b = newVal;
        else if (newVal >= 0x65 && newVal <= 0x68) b = newVal;
        else if (newVal >= 0x69 && newVal <= 0x6b) b = newVal;
        else if (newVal >= 0x6c && newVal <= 0x71) b = newVal;
        else if (newVal >= 0x7b && newVal <= 0x7c) b = newVal;
        else if (newVal >= 0x7d && newVal <= 0x80) b = newVal;
        else if (newVal >= 0x81 && newVal <= 0x85) b = newVal;
        else if (newVal >= 0x86 && newVal <= 0x89) b = newVal;
        else if (newVal >= 0x8a && newVal <= 0x8c) b = newVal;
        else if (newVal >= 0x8d && newVal <= 0x92) b = newVal;
        else if (newVal >= 0x94 && newVal <= 0x94) b = newVal;
        if (a != b) {
            memset(inline_02061c04_2(inline_02061c04(battle)) + 0xa4, 0, 0x28);
        }
        func_02010810((char*)battle, msg->p1);
        return 1;
    }
    case 0xc6: {
        void *ctx = LinkSession_GetInstance();
        LinkSession_UpdateMemberCount();
        int lvl = *((unsigned char *)ctx + 0x100d);
        if (lvl <= 1)
            return 0;
        void *base = GetGameResources();
        void *rec = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x500, 0x710));
        func_ov017_021b994c((Struct_02061c04_11*)rec);
        *((unsigned char *)rec + 0x130) = 1;
        GameState *battle = GameState::GetInstance();
        int v = *(int *)((char *)battle + 0x5000 + REGION_VALUE(0x4c4, 0x724));
        func_ov017_021d079c(4, 0, (unsigned short)v);
        *(int *)((char *)rec + 0x12c) = v;
        return 1;
    }
    case 0xc7:
        func_020ae990(msg->p1 & 0xff);
        return 1;
    case 0xc8:
        return 1;
    case 0xc9: {
        unsigned char b = ((unsigned char *)msg)[2];
        if (b <= 7)
            func_020aea40(b, ((unsigned char *)msg)[4]);
        return 1;
    }
    case 0xca:
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1198, 1);
        return 1;
    case 0xcb: {
        GameState *battle = GameState::GetInstance();
        void *base = GetGameResources();
        for (int i = 0; i < 4; i++) {
            GameObject *combatant = func_0200ff1c(battle, i);
            if (!combatant)
                continue;
            if (!func_02061bd8((Struct_0205faf4_11*)combatant))
                continue;
            int hp = *(unsigned short *)((char *)*(void **)((char *)combatant + 0x130) + 4);
            if (hp > 0)
                continue;
            if (msg->p1 == 0) {
                unsigned short val = *(unsigned short *)((char *)combatant->baseStats_ + 0x30);
                func_02053fe4(combatant, val, 1);
            } else if (msg->p1 == 1) {
                int val = inline_02061c04_4(combatant);
                func_02053fe4(combatant, val / 2, 1);
            } else {
                func_02053fe4(combatant, 1, 1);
            }
            func_02048418((unsigned char*)combatant, 1);
            Party_ReformLine(base, 1, 1, 1, 1);
            GameObject_StoreMotionState((Foo02033b58*)combatant, 0);
            *(short *)((char *)combatant + 0xb2) = 0;
        }
        return 1;
    }
    case 0xcc:
        func_ov017_02191484(GetGameResources());
        return 1;
    case 0xcd: {
        void *base = GetGameResources();
        func_020d3c08((char*)var0);
        func_020d3c28((Struct_02061c04_12*)var0);
        void *elem = func_020d3d78((unsigned char*)var0, msg->p1);
        if (elem) {
            Struct_02061c04_13 *f = (Struct_02061c04_13 *)((char *)elem + REGION_VALUE(0xb, 0x10));
            func_ov017_021913d0(base, f->unknown_0_0_);
        }
        return 1;
    }
    case 0xce: {
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x79a, 1);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsHostOrSolo(ctx)) {
            int rowBase;
            GameState *battle = GameState::GetInstance();
            void *base = GetGameResources();
            void *table = ZoneRecords_GetInstance();
            for (int a = 0; a < 4; a++) {
                void *elem = ZoneRecords_GetAt((Element0x318_02028bac*)table, a);
                if (!((struct Struct_02061c04_33 *)((char *)elem + 2))->bit2)
                    continue;
                unsigned short val = *(unsigned short *)elem;
                if ((val / 100) * 100 != 400)
                    continue;
                rowBase = a * 0xc + 0x70;
                for (int b = 0; b < 0xc; b++) {
                    void *c2 = battle->GetFieldMonsterByIndex(b + rowBase);
                    if (!c2)
                        continue;
                    unsigned short v = *(unsigned short *)((char *)c2 + 0x100 + 0x6a);
                    func_ov017_021a23b0(base, v);
                    short p2 = *(short *)((char *)c2 + 2);
                    unsigned short var173 = *(unsigned short *)elem;
                    func_ov017_021c9544(var173, b, p2, -1);
                }
            }
        }
        return 1;
    }
    case 0xcf: {
        void *pool = &g_scenario;
        if (pool)
            Scenario_SetFlag(pool, (unsigned char *)pool + 0x8c, 0x384, msg->p1);
        void *base = GetGameResources();
        for (int i = 0; i < 4; i++)
            *(unsigned short *)((char *)base + REGION_VALUE(0x4100, 0x4400) + i * 2 + REGION_VALUE(0x9a, 0x4a)) =
                *(unsigned short *)((char *)msg + i * 2 + 4);
        return 1;
    }
    case 0xd0: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsHostOrSolo(ctx)) {
            GameState *battle = GameState::GetInstance();
            void *p = GameState_GetParty((GameState*)battle);
            *(unsigned int *)((char *)p + 0x2c94) = msg->p1;
            *(unsigned int *)((char *)battle + REGION_VALUE(0x7c34, 0x7e74)) = msg->p1;
            func_ov017_021d0d58();
        }
        return 1;
    }
    case 0xd1: {
        void *base = GetGameResources();
        void *ctx = LinkSession_GetInstance();
        LinkSession_UpdateMemberCount();
        int lvl = *((unsigned char *)ctx + 0x100d);
        if (lvl <= 1)
            return 1;
        func_ov017_0218b664((char*)base);
        GameState::GetInstance();
        signed char b = *((signed char *)base + REGION_VALUE(0x4196, 0x4446));
        func_ov017_021d0860(4, 0, b);
        *((unsigned char *)base + REGION_VALUE(0x4198, 0x4448)) = 1;
        b = *((signed char *)base + REGION_VALUE(0x4196, 0x4446));
        *((unsigned char *)base + REGION_VALUE(0x4197, 0x4447)) = b;
        return 0;
    }
    case 0xd2: {
        void *base = GetGameResources();
        func_ov017_02198f70(base, *((signed char *)base + REGION_VALUE(0x4196, 0x4446)));
        return 1;
    }
    case 0xd3: {

        struct Struct_02061c04_19
        {
              char unk[0x1840];
            struct Struct_02061c04_20 {
                char unk[0xb4c];
                unsigned int num;
            } bar;
        };

        struct Sub {
            char unk[0x1000];
            Struct_02061c04_19::Struct_02061c04_20 bar;
        };
        unsigned int mask = 1 << msg->p1;
        ((Sub *)((char *)Zone3D_GetInstance() + REGION_VALUE(0x860, 0x840)))->bar.num |= mask;
        return 1;
    }
    case 0xd4:
        func_ov017_0219c520();
        return 1;
    case 0xd5: {
        lr.unknown_e_ = 0;
        lr.unknown_f_ = 0;
        lr.unknown_10_ = 0;
        lr.unknown_12_ = 0;
        lr.unknown_13_ = 0;
        lr.unknown_e_ = (msg->p2 == 0);
        lr.unknown_f_ = (msg->p3 == 0);
        lr.unknown_10_ = msg->p4;
        lr.unknown_12_ = (msg->p5 == 0);
        void *base = GetGameResources();
        func_ov017_0218d7b0((unsigned char*)base, (char*)&lr.unknown_e_);
        return 1;
    }
    case 0xd6: {
        GameState *battle = GameState::GetInstance();
        lr.fh4 = GameState_GetStoryChapter((char*)battle);
        lr.fh6 = GameState_GetStoryPart((char*)battle);
        lr.fh8 = GameState_GetStoryStep((char*)battle);
        func_0206445c((int)obj, (Struct_02061c04_25 *)msg, (Struct_02061c04_26 *)param3);
        return 1;
    }
    case 0xd7: {
        void *base = GetGameResources();
        func_ov017_021a8614(base, (short)msg->p1, msg->p2, msg->p3, msg->p4, msg->p5);
        return 1;
    }
    case 0xd8: {
        int p1 = *(short *)((char *)msg + 2);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsHostOrSolo(ctx)) {
            void *p0 = Zone3D_GetInstance();
            *(short *)((char *)p0 + 0x2700 + REGION_VALUE(0xf4, 0xb4)) = p1;
            if (LinkSession_IsActive((int *)ctx)) {
                func_ov017_021d1c2c(p1, 0);
                func_ov017_021d1dc0((unsigned short)p1, 0, (int *)&var11, 0, 0);
            }
        }
        return 1;
    }
    case 0xd9: {
        void *p = GetGameResources();
        void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x94c, 0xb6c));
        func_ov017_021beba4((char*)node);
        func_020469b4((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0xda:
        func_020732cc(msg->p1);
        return 1;
    case 0xdb: {
        var12.ResetAllocatorPointer();
        var12.ResetAllocatorPointer();
        void *mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x1000);
        var12.CreateTypeA(mem, 0x1000);
        var12.Reset();
        GameState *battle = GameState::GetInstance();
        void *p = GameState_GetParty((GameState*)battle);
        void *r = func_02086f24(p, (unsigned char)msg->p1, &var12);
        void *signedAlloc = var12.GetSignedAllocator();
        if (signedAlloc) {
            var12.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
        }
        return (int)r;
    }
    case 0xdc:
        func_020aee04(msg->p1, ((unsigned char *)msg)[4]);
        return 1;
    case 0xdd: {
        void *p = GetGameResources();
        func_ov017_021c1a98(p, 1);
        return 1;
    }
    case 0xde: {
        void *p0 = Zone3D_GetInstance();
        *((unsigned char *)p0 + 0x2000 + REGION_VALUE(0x810, 0x7d0)) = 0;
        return 1;
    }
    case 0xdf:
        Scenario_SetFlag(&g_scenario, (unsigned char *)&g_scenario + 0x8c, 0x799, msg->p1);
        return 1;
    case 0xe0:
        Scenario_SetFlag(&g_scenario, (unsigned char *)&g_scenario + 0x8c, 0x798, msg->p1);
        return 1;
    case 0xe3: {
        void *p = GetGameResources();
        (void)p;
        func_020dac40();
        return 1;
    }
    case 0xe4: {
        struct Struct_01ff91ac {
          char unk[0xc8];
            unsigned char low : 2;
            unsigned char foo : 1;
        };
        g_bgmPlayer.foo = !msg->p1;
        return 1;
    }
    case 0xe5: {
        GameState *battle = GameState::GetInstance();
        unsigned short var204 = *(unsigned short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9c, 0xdc));
        short var205 = *(short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9e, 0xde));
        short var206 = *(short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0xa0, 0xe0));
        void *p = GameState_GetParty((GameState*)battle);
        if (var204 == 0)
            return 1;
        if (var205 >= 0 && var205 <= 3) {
            GameObject *combatant = func_0200ff1c(battle, var205);
            if (!combatant)
                return 1;
            void *field = func_02053c6c((unsigned char*)combatant);
            func_0208386c((Struct_02061c04_22*)field, (signed char)var206);
        } else {
            func_020a0a08((Struct_02061c04_23*)p, (short)var204, 1);
        }
        return 1;
    }
    case 0xe6:
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0xbea, msg->p2);
        return 1;
    case 0xe7: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsGuest(ctx))
            return 1;
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x796, msg->p1);
        char *battle = (char*)GameState::GetInstance();
        Struct_02061c04* st = (Struct_02061c04*)((char *)&((struct Struct_02061c04_5 *)inline_02061c04(battle))[1] + 0x3c);
        Struct_02061c04_3* snap = &st->unknown_90_;
        if (!snap->captured) {
            void *fields = GameState_GetParty((GameState*)battle);
            int level = 0;
            void *comb = ((GameState*)battle)->GetProtagonist();
            if (comb)
                level = *(*(unsigned short **)((char *)comb + 0x134) + 0x18);
            lr.unknown_4_ = 0;
            func_020ac0b4((void *)&lr.unknown_4_);
            func_020643e0((Struct_02061c04_24*)&snap->unknown_0_, (Struct_02061c04_24*)&st->unknown_0_.elapsed);
            func_020643e0((Struct_02061c04_24*)&snap->unknown_4_, (Struct_02061c04_24*)&st->unknown_0_.unknown_4_);
            snap->unknown_8_0_ = st->unknown_8_0_;
            snap->unknown_a_1_ = func_020a0870(st);
            snap->unknown_b_0_ = func_020a090c(st);
            snap->unknown_c_0_ = lr.unknown_4_;
            snap->unknown_e_1_ = func_020a08a4(st);
            snap->unknown_f_0_ = func_020a08d8(st);
            snap->unknown_10_0_ = st->unknown_10_0_;
            snap->unknown_11_1_ = st->unknown_d_6_;
            snap->unknown_14_0_ = st->unknown_b_0_;
            snap->unknown_15_0_ = st->unknown_11_1_;
            snap->unknown_16_6_ = level;
            snap->unknown_18_0_ = st->unknown_40_0_;
            snap->unknown_1c_ = *(unsigned int *)((char *)fields + 0xf6c) + *(unsigned int *)((char *)fields + 0xf68);
            snap->captured = 1;
        }
        return 1;
    }
    case 0xe8: {
        void *g = func_0203cf4c();
        void *entry = func_0203df78(g, msg->p1);
        if (!entry)
            return 1;
        void *f = func_02040538((Struct_0203e0a0*)entry);
        if (!f)
            return 1;
        unsigned char b = *((unsigned char *)f + 0xa);
        b = (b & ~0x38) | (((unsigned char)msg->p2 & 7) << 3);
        *((unsigned char *)f + 0xa) = b;
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
