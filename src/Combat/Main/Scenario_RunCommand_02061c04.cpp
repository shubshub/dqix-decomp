#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/Field3b0.h"
#include "GameState/BattleRecordSnapshot.h"
#include "World/ZoneChest.h"
#include "Resource/GameResources.h"

extern "C" void Scenario_SetFlag(void *obj, unsigned char *arr, int idx, int flag);
extern "C" void *LinkSession_GetInstance(void);
int LinkSession_IsActive(int *ctx);
struct SearchStruct0202c1a4;
int LinkSession_GetOwnSlot(SearchStruct0202c1a4 *ctx);
extern "C" void func_ov017_021d0924(int a, int b, int p1, int flag);
void ClearNibble0206ece8(int a, int b, unsigned char *c, unsigned d);
extern "C" int LinkSession_IsHostOrSolo(void *ctx);
extern "C" void *Zone3D_GetInstance(void);
void *ZoneFeatures_GetFirstOfType(unsigned char *arr, unsigned idx);
struct AppendNode;
struct AppendList;
void AppendNodeToListField30_0206445c(int a, AppendNode *msg, AppendList *list);
void EnqueueEventTag147_021cdaa0();
void *GetGlobal02109418_02094d6c(void);
extern "C" int func_020961b0(void *g, int p1);
int Scenario_TestFlag(int obj, unsigned char *arr, int idx);
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
void EnqueueEventTag142_021cd6d8(Src021cd6d8 *ev);
void Camera_Shake(unsigned char*, int, int);
void SetFlag0x4At0x168_0202ea3c(unsigned char*);
struct FlagsAndWords0202ea20;
void ClearTwoWordsAndFlag0x4(FlagsAndWords0202ea20*);
void *GetData02108f0c_0208a9b4();
extern "C" void LinkSession_UpdateMemberCount(void);
struct Obj_021b994c;
void ResetFieldsToDefault_021b994c(Obj_021b994c*);
void EnqueueEventTag153_021d079c(unsigned char, unsigned char, unsigned short);
void NotifyElemAndOverlay17OnFlag020ae990(int key);
extern "C" void func_020aea40(int a, int b);
extern "C" void func_ov017_02191484(void *base);
void ResetStruct020d3c08(char*);
struct Obj020d3c28;
void InitAndMaybeStartStream020d3c28(Obj020d3c28*);
void * GetElementCount0xb4Stride0x24_020d3d78(unsigned char*, int);
extern "C" void func_ov017_021913d0(void *base, int field);
struct ElemFlags3Bit0d3d78 { unsigned char field3 : 3; unsigned char rest : 5; };
extern int g_scenario;
void ResetFieldGroup4444_0218b664(char*);
void EnqueueEventTag154_021d0860(int, int, int);
void SetFieldFromHelper491_02198f70(void*, int);
extern "C" void func_ov017_0219c520(void);
extern "C" void func_ov017_0218d7b0(unsigned char*, char*);
struct Struct_02061c04_14 { unsigned int unknown_0_0_ : 17; unsigned int unknown_2_1_ : 1; };

struct PackedNibbleArray0206e120;
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
struct Struct020d9dec;
void Init020d9dec(Struct020d9dec*, int);
struct S020d9fb4;
void SetFlagBit020d9fb4(S020d9fb4*, int);
void * GameState_GetParty(GameState*);
int GameState_GetStoryChapter(char*);
int GameState_GetStoryPart(char*);
int GameState_GetStoryStep(char*);
void ClearRegions0206e080(char*, int);
void ClearIndexedEntryFields0206e0d0(char*, int);
void SetKeyedArrayBit0206e348(unsigned char*, int, int);

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

struct Struct_02061c04_17 { unsigned short unknown_0_, unknown_2_, unknown_4_, unknown_6_, unknown_8_, unknown_a_; unsigned short unknown_c_[8]; };

struct Struct_02061c04_18 { unsigned short unknown_0_0_ : 4; unsigned short unknown_0_4_ : 12; };

extern "C" void func_020732cc(int p1);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char a, unsigned short b);
void EnqueueEventTagB5_021d1dc0(unsigned short, int, int*, int, int);
extern AllocatorUnion g_mainAllocator;
void *AllocatorUnion_AllocateRounded(AllocatorUnion *alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion *alloc, void *data);
extern "C" void *func_02086f24(void *p, unsigned char b, SafeAllocator *alloc);
extern "C" void func_020aee04(unsigned short a, unsigned char b);
extern struct Str02109bf4 {
    char unk[0xc8];
    unsigned char low : 2;
    unsigned char foo : 1;
} g_bgmPlayer;
extern "C" void _Z27InitAndAppendEntity020dac40P12Root020dac40(void);
void * GetFieldAt0x150_02053c6c(unsigned char*);
struct Slots0208386c;
void RemoveSlotShiftDown0208386c(Slots0208386c*, int);
struct KeyMap020a0a08;
void DecrementKeyValue020a0a08(KeyMap020a0a08*, int, int);
void SyncEightElementFlags_020ae9f0(void);
void RegisterSlotA020cf0fc(int p);
void RTC_GetTime(int p);
void ApplySlotConfig02095cfc(int, int);
extern "C" int LinkSession_IsGuest(void *ctx);
void CopyOutBattleField0x7ac0_020ac0b4(void *dst);
struct SmallRecord020643e0;
void CopyHalfwordAndTwoBytes(SmallRecord020643e0*, SmallRecord020643e0*);
int GetFieldPercentOver307_020a0870(BattleRecordSnapshot* record);
int GetFieldPercentOver448_020a090c(BattleRecordSnapshot* record);
int GetFieldPercentOver232_020a08a4(BattleRecordSnapshot* record);
int GetFieldPercentOver944_020a08d8(BattleRecordSnapshot* record);

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
struct SrcWord44 { unsigned int v24 : 24; unsigned int hi8 : 8; };
struct SrcWord48 { unsigned int lo : 14; unsigned int v14 : 14; unsigned int hi : 4; };
struct SrcWord4c { unsigned int v9 : 9; unsigned int v14 : 14; unsigned int hi : 9; };
void *GetGlobalPtr021075f4_0203cf4c(void);
void *FindEntryPointerByKey0203df78(void *g, int key);
struct S02040538;
void * GetField0xc02040538(S02040538*);
void RegisterSlotA020cf0fc(int p);
extern "C" int func_020ac2d4(int a, void *p1, void *p2, int flag);
extern "C" void func_020ac104(void *pooled, void *p1, int flag);
extern char g_fileLoadBuffer;
void * InitObj021bdbf0(unsigned char*);
void * InitObj021beba4(char*);
struct Base02019508;
void * Zone3D_FindSceneElement(Base02019508*, int, int);
extern "C" void func_0206ea8c(void *obj, unsigned char a, short b, int flag);
struct Struct02013380;
void BmdjSceneElement_SetShown(Struct02013380*, int, int);
void InitContext020e1154(void *p);
extern "C" void FieldTask_InitAcquireTreasureMap(void *node, unsigned char b);
extern "C" void AcquireTreasureMapTask_CreateMap(void *node, unsigned char a, unsigned char b, unsigned short c, unsigned char d);
extern "C" void func_ov017_021a8614(void *base, short p1, unsigned short p2, unsigned short p3, unsigned short p4, unsigned short p5);
void EnqueueEventTag141_021ce110(int a, unsigned short b, unsigned short c, unsigned char d);
extern "C" void func_0206e748(void *obj, int a, int b, int c, int d);
struct Node64af8;
struct Obj64af8;
void AppendNodeToField494_02064af8(Obj64af8*, Node64af8*);
struct Obj02061bd8;
int CheckField0x56bLowNibble(Obj02061bd8*);
void TryClearFlags0x130_02048418(unsigned char*, unsigned short);
extern "C" void Party_ReformLine(void *base, int a, int b, int c, int d);
struct Foo02033b58;
void GameObject_StoreMotionState(Foo02033b58*, unsigned char);
void *ZoneRecords_GetInstance(void);
struct Element0x318_02028bac;
void * ZoneRecords_GetAt(Element0x318_02028bac*, int);
extern "C" void func_ov017_021a23b0(void *base, unsigned short v);
void EnqueueEventTag134_021c9544(int a, int b, int c, int d);
int LinkSession_GetState(int *ctx);
void GameState_UpdatePlayClocks(int flag);
void SetField5cbcValue_02010810(char*, int);
int GetField5cbcValue_0201081c(char*);

// USA: Scenario_RunCommand
struct SharedFrame { unsigned int word0; unsigned short h4, h6, h8; };
struct Vec3 { int x, y, z; };
struct Vec3W { int w[3]; };
struct PackedRegSlots7f { unsigned int f0 : 7; unsigned int f1 : 4; unsigned int f2 : 5;
                          unsigned int f3 : 5; unsigned int f4 : 6; };
union SlotEntry { unsigned int w; struct { unsigned int id : 9; unsigned int pad9 : 2; unsigned int slot : 3; } b; };
struct EntryFlags { unsigned int pad0 : 10; unsigned int bit10 : 1; unsigned int pad11 : 21; };
struct Elem2Flags { unsigned short pad0 : 2; unsigned short bit2 : 1; unsigned short rest : 13; };

struct Struct_02061c04_4 { short unknown_0_; unsigned short unknown_2_; unsigned short unknown_4_, unknown_6_, unknown_8_, unknown_a_, unknown_c_, unknown_e_; };

static inline char *SubA(void *b) { return (char *)b + REGION_VALUE(0x2c4, 0x104); }
static inline char *SubB(char *a) { return a + REGION_VALUE(0x7000, 0x7400); }
struct Blk7400 { char pad[REGION_VALUE(0x7000, 0x7400)]; };
static inline int GetSlot332(void *obj) { return *((unsigned char *)obj + 0x332); }
static inline int Field134_30(void *c) { return *(unsigned short *)((char *)*(void **)((char *)c + 0x134) + 0x30); }
static inline int AngleMax() { return 0x6488; }
static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }
// Main, originally func_02061c04 (USA 0x02061c04, EUR 0x02061c14, JPN 0x02062eec)
extern "C" ARM int Scenario_RunCommand(void *obj, CmdMsg64 *msg, void *param3) {
    char cdLocal[REGION_VALUE(0xa4, 0xb8)];
    struct { int a0, a1, a2, a3; } sa;
    struct { int b0, b1, b2; } sb;
    struct Vec3 halfOut;
    CmdMsg64 m9b;
    CmdMsg64 m9c;
    CmdMsg64 m9d;
    CmdMsg64 m9e;
    CmdMsg64 m9f;
    struct Src021cd6d8 c0Local;
    unsigned short deck[14];
    struct { int a, b, c; } d8Local;
    SafeAllocator dbAlloc;
    struct Vec3 midOut;
    struct Vec3 half;
    struct Vec3 mid;
    struct Vec3 diff;
    struct LowRegion {
        short p1;
        short pad2;
        unsigned int fword0;
        unsigned short fh4, fh6, fh8;
        unsigned char d0, d1;
        short d2;
        unsigned char d3, d4;
        struct FrameB fb;
        struct PackedRegSlots7f packed;
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
        void *var28 = GetGameResources();
        unsigned char *var29 = *(unsigned char **)((char *)var28 + 0x4000 + REGION_VALUE(0x214, 0x4c4));
        func_0206ece8((int)var29, arg1->unknown_2_, var29, 0x80);
        func_0206ece8((int)var29, arg1->unknown_2_, var29 + 0x80, 0x80);
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
                FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
                if (!(f->flagsHi & 1))
                    f->flagsHi |= 4;
            }
            var32 = *(void **)((char *)var32 + 0x70);
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
            var35 = var35->unknown_70_;
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
            var37 = var37->unknown_70_;
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
            EnqueueEventTag147_021cdaa0();
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
        if (!Scenario_TestFlag((int)obj, (unsigned char *)obj + 0x8c, 0x119d)) {
            void *p = GetGameResources();
            void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
            Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x119d, 1);
            void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x9a0, 0xbc0));
            Init020d9ae8((Struct020d9ae8 *)node, 1);
            AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
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
        RegisterSlotA020cf0fc((int)&sa);
        RTC_GetTime((int)&sb);
        lr.packed.f0 = sa.a0;
        lr.packed.f1 = sa.a1;
        lr.packed.f2 = sa.a2;
        lr.packed.f3 = sb.b0;
        lr.packed.f4 = sb.b1;
        void *g = GetGlobal02109418_02094d6c();
        *(unsigned int *)((char *)g + msg->p1 * 4 + 0x178) = *(unsigned int *)&lr.packed;
        ApplySlotConfig02095cfc((int)g, msg->p1);
        return 1;
    }
    case 0x80:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x81:
        func_0206e164(arg0, arg1->unknown_2_, 1);
        return 1;
    case 0x82: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx)) {
            FindEntryById02096134((FindEntryById02096134Table *)GetGlobal02109418_02094d6c(), msg->p1);
            if (!LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx)) {
                if (msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 1);
                SetBitWithOffset0206eb64((unsigned char *)obj, msg->p2, 1);
            } else {
                func_0206eb64((unsigned char *)arg0, arg1->unknown_4_, 1);
            }
        } else {
            func_0206eb64((unsigned char *)arg0, arg1->unknown_4_, 1);
        }
        return 1;
    }
    case 0x83: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx)) {
            void *entry = FindEntryById02096134((FindEntryById02096134Table *)GetGlobal02109418_02094d6c(), msg->p1);
            if (!LinkSession_GetOwnSlot((SearchStruct0202c1a4 *)ctx)) {
                if (!(entry != 0 && ((struct EntryFlags *)entry)->bit10 == 1) &&
                    msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 0);
                SetBitWithOffset0206eb64((unsigned char *)obj, msg->p2, 0);
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
        GameState *battle = GameState::GetInstance();
        lr.fb.ha = GameState_GetStoryChapter((char*)battle);
        lr.fb.hc = GameState_GetStoryPart((char*)battle);
        lr.fb.he = GameState_GetStoryStep((char*)battle);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        if (lr.fb.ha != msg->p2)
            ClearRegions0206e080((char*)obj, *((unsigned char *)obj + 0x332));
        if (lr.fb.hc != msg->p3)
            ClearIndexedEntryFields0206e0d0((char*)obj, *((unsigned char *)obj + 0x332));
        return 1;
    }
    case 0x85: case 0x8a: case 0xe2:
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x86: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsActive((int *)ctx))
            EnqueueEventTag141_021ce110((unsigned char)msg->p2, 1, msg->p1, 1);
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
                int slot1 = GetSlot332(obj);
                func_0206e748(obj, 3, slot1, msg->p1, 1);
            }
            break;
        }
        case 5: {
            Scenario_SetFlag(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 1);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 1);
            if (LinkSession_IsGuest(ctx)) {
                int slot2 = GetSlot332(obj);
                func_0206e748(obj, 5, slot2, msg->p1, 1);
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
            EnqueueEventTag141_021ce110((unsigned char)msg->p2, 0, msg->p1, 1);
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
                int slot3 = GetSlot332(obj);
                func_0206e748(obj, 3, slot3, msg->p1, 0);
            }
            break;
        }
        case 5: {
            Scenario_SetFlag(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 0);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 0);
            if (LinkSession_IsGuest(ctx)) {
                int slot4 = GetSlot332(obj);
                func_0206e748(obj, 5, slot4, msg->p1, 0);
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
                FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
                f->flagsHi &= ~4;
            }
            var60 = *(void **)((char *)var60 + 0x70);
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
        func_0206445c((int)arg0, (Struct_02061c04_25 *)arg1, (Struct_02061c04_26 *)arg2);
        return 1;
    case 0x8e:
        func_0206e348((unsigned char*)arg0, arg1->unknown_2_, 1);
        return 1;
    case 0x8f: {
        if (arg1->unknown_2_ == 2)
            return 1;
        void *base = GetGameResources();
        void *mem = ((SafeAllocator *)((char *)base + 0x164))->Allocate(0x30);
        if (mem) {
            Zone3D_GetInstance();
            struct Msg8fExt { short cmd, pad2; int f4, f8, fc, f10; int *f14; } *m = (struct Msg8fExt *)msg;
            char *n = (char *)mem;
            *(short *)(n + 0) = (short)m->f4;
            *(int *)(n + 0x14) = m->f8;
            *(int *)(n + 0x1c) = m->f10;
            *(int *)(n + 0x18) = m->fc;
            int *p14 = m->f14;
            *(int *)(n + 0x20) = p14[1];
            *(int *)(n + 0x28) = p14[3];
            *(int *)(n + 0x24) = p14[2];
            *(short *)(n + 2) = (short)(4096.0f * (3.14159274f * (float)p14[4] / 180.0f));
            short angle = *(short *)(n + 2);
            int lim = 0x6488;
            if (angle > lim)
                *(short *)(n + 2) -= lim;
            else if (angle < 0)
                *(short *)(n + 2) = angle + 0x6488;

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
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsGuest(ctx))
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
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
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
        void *var89 = GetGameResources();
        void *var90 = *(void **)((char *)var89 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *var91 = *(void **)((char *)var89 + 0x3000 + REGION_VALUE(0x940, 0xb60));
        func_ov017_021bdbf0((unsigned char*)var91);
        *((unsigned char *)var91 + 0x11) = arg1->unknown_2_;
        func_020469f8((Struct_020469f8*)var90, (Struct_020469f8_2*)var91);
        return 1;
    }
    case 0x9b: {
        m9b.cmd = 0x68;
        m9b.p1 = msg->p2;
        Scenario_RunCommand(obj, &m9b, param3);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x9c: {
        m9c.cmd = 0x7f;
        m9c.p1 = msg->p1;
        Scenario_RunCommand(obj, &m9c, param3);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x9d: {
        switch ((short)arg1->unknown_4_) {
        case 0: var6.unknown_0_ = 0x7d; break;
        case 2: var6.unknown_0_ = 0x7f; break;
        case 3: var6.unknown_0_ = 0x81; break;
        default: return 0;
        }
        m9d.p1 = msg->p1;
        Scenario_RunCommand(obj, &m9d, param3);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
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
        c0Local.f0 = 0;
        c0Local.f1 = 0;
        c0Local.f2 = 0;
        c0Local.f3 = 0;
        c0Local.f4 = 0;
        c0Local.f5 = 0;
        c0Local.f7 = 0;
        c0Local.f6 = -1;
        c0Local.f0 = *(unsigned short *)p0;
        c0Local.f1 = msg->p1;
        c0Local.f2 = 0;
        c0Local.f4 = 1;
        c0Local.f3 = -1;
        c0Local.f7 = battle->GetDayTimer();
        EnqueueEventTag142_021cd6d8(&c0Local);
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
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1136, 0);
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
        void *base = GetGameResources();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x948, 0xb68));
        InitContext020e1154((void *)0xbb8);
        FieldTask_InitAcquireTreasureMap(node, ((unsigned char *)msg)[2]);
        AcquireTreasureMapTask_CreateMap(node, ((unsigned char *)msg)[4], ((unsigned char *)msg)[5], msg->p3,
                            ((unsigned char *)msg)[8]);
        AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
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
                EnqueueEventTag23Field_021d0d58();
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
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x1138, msg->p1);
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
        GameState *battle = GameState::GetInstance();
        void *rec = battle->GetCamera();
        if (msg->p1 != 0) {
            Camera_Shake((unsigned char*)rec, 0x333, 1);
            SetFlag0x4At0x168_0202ea3c((unsigned char*)rec);
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
        GameState *battle = GameState::GetInstance();
        void *ctx = LinkSession_GetInstance();
        int v = LinkSession_GetState((int *)ctx);
        int byte = *((unsigned char *)ctx + 0x1000 + 0xd);
        int flag = 0;
        if ((v == 5 && byte > 1) || v == 6)
            flag = 1;
        GameState_UpdatePlayClocks(flag);
        int cur = GetField5cbcValue_0201081c((char*)battle);
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
            memset(SubB(SubA(battle)) + 0xa4, 0, 0x28);
        }
        func_02010810((char*)var135, arg1->unknown_2_);
        return 1;
    }
    case 0xc6: {
        void *ctx = LinkSession_GetInstance();
        LinkSession_UpdateMemberCount();
        int lvl = *((unsigned char *)ctx + 0x100d);
        if (lvl <= 1)
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
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1198, 1);
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
            TryClearFlags0x130_02048418((unsigned char*)combatant, 1);
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
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x79a, 1);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsHostOrSolo(ctx)) {
            int rowBase;
            GameState *battle = GameState::GetInstance();
            void *base = GetGameResources();
            void *table = ZoneRecords_GetInstance();
            for (int a = 0; a < 4; a++) {
                void *elem = ZoneRecords_GetAt((Element0x318_02028bac*)table, a);
                if (!((struct Elem2Flags *)((char *)elem + 2))->bit2)
                    continue;
                unsigned short var168 = *(unsigned short *)var167;
                if ((var168 / 100) * 100 != 400)
                    continue;
                rowBase = a * 0xc + 0x70;
                for (int b = 0; b < 0xc; b++) {
                    void *c2 = battle->GetFieldMonsterByIndex(b + rowBase);
                    if (!c2)
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
            EnqueueEventTag23Field_021d0d58();
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
        unsigned int mask = 1 << msg->p1;
        ((Sub *)((char *)Zone3D_GetInstance() + REGION_VALUE(0x860, 0x840)))->bar.num |= mask;
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
        GameState *battle = GameState::GetInstance();
        lr.fh4 = GameState_GetStoryChapter((char*)battle);
        lr.fh6 = GameState_GetStoryPart((char*)battle);
        lr.fh8 = GameState_GetStoryStep((char*)battle);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0xd7: {
        void *var188 = GetGameResources();
        func_ov017_021a8614(var188, (short)arg1->unknown_2_, arg1->unknown_4_, arg1->unknown_6_, arg1->unknown_8_, arg1->unknown_a_);
        return 1;
    }
    case 0xd8: {
        int p1 = *(short *)((char *)msg + 2);
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsHostOrSolo(ctx)) {
            void *p0 = Zone3D_GetInstance();
            *(short *)((char *)p0 + 0x2700 + REGION_VALUE(0xf4, 0xb4)) = p1;
            if (LinkSession_IsActive((int *)ctx)) {
                SetHalfFieldsAndEnqueueIfActive_021d1c2c(p1, 0);
                EnqueueEventTagB5_021d1dc0((unsigned short)p1, 0, (int *)&d8Local, 0, 0);
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
        dbAlloc.ResetAllocatorPointer();
        dbAlloc.ResetAllocatorPointer();
        void *mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x1000);
        dbAlloc.CreateTypeA(mem, 0x1000);
        dbAlloc.Reset();
        GameState *battle = GameState::GetInstance();
        void *p = GameState_GetParty((GameState*)battle);
        void *r = func_02086f24(p, (unsigned char)msg->p1, &dbAlloc);
        void *signedAlloc = dbAlloc.GetSignedAllocator();
        if (signedAlloc) {
            dbAlloc.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
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
        g_bgmPlayer.foo = !msg->p1;
        return 1;
    }
    case 0xe5: {
        GameState *battle = GameState::GetInstance();
        unsigned short s5 = *(unsigned short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9c, 0xdc));
        short s6 = *(short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9e, 0xde));
        short s7 = *(short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0xa0, 0xe0));
        void *p = GameState_GetParty((GameState*)battle);
        if (s5 == 0)
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
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0xbea, msg->p2);
        return 1;
    case 0xe7: {
        void *ctx = LinkSession_GetInstance();
        if (LinkSession_IsGuest(ctx))
            return 1;
        Scenario_SetFlag(obj, (unsigned char *)obj + 0x8c, 0x796, msg->p1);
        char *battle = (char*)GameState::GetInstance();
        BattleRecordSnapshot* st = (BattleRecordSnapshot*)((char *)&((struct Blk7400 *)SubA(battle))[1] + 0x3c);
        BattleRecordCapture* snap = &st->capture;
        if (!snap->captured) {
            void *fields = GameState_GetParty((GameState*)battle);
            int level = 0;
            void *comb = ((GameState*)battle)->GetProtagonist();
            if (comb)
                level = *(*(unsigned short **)((char *)comb + 0x134) + 0x18);
            lr.fword0 = 0;
            CopyOutBattleField0x7ac0_020ac0b4((void *)&lr.fword0);
            CopyHalfwordAndTwoBytes((SmallRecord020643e0*)&snap->playClock, (SmallRecord020643e0*)&st->clocks.elapsed);
            CopyHalfwordAndTwoBytes((SmallRecord020643e0*)&snap->committedPlayClock, (SmallRecord020643e0*)&st->clocks.committed);
            snap->unknown08_0 = st->unknown08_0;
            snap->unknown08_17 = GetFieldPercentOver307_020a0870(st);
            snap->unknown08_24 = GetFieldPercentOver448_020a090c(st);
            snap->unknown0c_0 = lr.fword0;
            snap->unknown0c_17 = GetFieldPercentOver232_020a08a4(st);
            snap->unknown0c_24 = GetFieldPercentOver944_020a08d8(st);
            snap->unknown10_0 = st->unknown10_0;
            snap->unknown10_9 = st->unknown0c_14;
            snap->unknown14_0 = st->unknown08_24;
            snap->unknown14_8 = st->unknown10_9;
            snap->unknown14_22 = level;
            snap->unknown18_0 = st->unknown40_0;
            snap->unknown1c = *(unsigned int *)((char *)fields + 0xf6c) + *(unsigned int *)((char *)fields + 0xf68);
            snap->captured = 1;
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
