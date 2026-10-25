#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "World/ZoneLootableRecord.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"
#include "Resource/ActionDataTables.h"
#include "World/LootableContainer.h"
#include "Graphics/LightingManager.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define func_020c51dc func_020c6ca8
#endif



struct GameResources;
struct AllocatorUnion;

unsigned int* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int* word, unsigned int bits);
struct FlagWord020466f4;
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
int GetWord0x7f6c_0201201c(void* gs);
void SetWord0x7f6c_02012010(void* gs, int value);
struct FieldBlock63d6_115a8;
unsigned char GetByteField0x63d6_020115a8(FieldBlock63d6_115a8*);
struct FieldBlock63d6_115c0;
void ClearByte0x63d6_020115c0(FieldBlock63d6_115c0*);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
void SetMainBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
void SetWord0x0_0200fb84(int*, int);
extern "C" char* Zone3D_GetInstance();
void* GetField0x3f8Address_0200fd0c(GameState* gs);
void Init0201133c(char*);
void* GetData02109dcc_020a6084();
void ClearBuffer020a6180(void* p);
void RunScriptIfAvailable020a6194(void* p);
void* GetData02105254_0203b628();
void ClearThreeRegions0203b634(char*);
extern "C" void* func_0203bd08();
extern "C" void func_0203bd24(char*);
extern "C" void* func_0203cf4c();
struct Struct_0203cf58;
extern "C" void func_0203cf58(Struct_0203cf58*);
extern "C" void* func_0202ae18();
extern "C" void func_0202aec0(void* arg0);
extern "C" void* func_0202ae24();
extern "C" void func_0205e22c(void* arg0);
extern "C" void* func_02011584(void* arg0);
extern "C" void func_02099898(unsigned int*);
extern "C" void func_ov017_021b2f64(unsigned char*);
extern "C" void* func_0208e0a8();
void Reset0208e4bc(char*);
void* GetData02153637_020e2ff8();
struct SlotTable020e3004;
void InitSlotTable020e3004(SlotTable020e3004*);
void* GetData02153660_020e3808();
struct Entry020e3840;
void ResetEntryArray020e3814(Entry020e3840*);
void* GetData02153634_020e3580();
struct Bytes020e358c;
void ClearThreeBytes020e358c(Bytes020e358c*);
extern "C" char* Scenario_GetInstance();
char* GetGlobal02109418_02094d6c();
unsigned char GetByte0x4_0200fb9c(char*);
void SetByte0x4_0200fb94(char*, unsigned char);
void ResetState0205facc(void* p);
void Init02095518(char*);
void ClearBattleRegion0x7ac4_020ac0dc();
extern "C" void func_02096524(void* p);
extern "C" void* func_020704fc();
struct State02070508;
void ClearState02070508(State02070508*);
extern "C" void func_0209c2e0(void* p, int a, int b);
extern "C" void func_0205e944(void* p, int a);
void* TextQueue_GetInstance();
struct ResetObj020d7a5c;
void ResetAndClearFlags020d7a5c(ResetObj020d7a5c*);
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
void UpdateVRAMStagingVRAMBanks();
void Finish3DRendering();
extern "C" unsigned int DisableTextureImageVRAMBanks();
extern "C" unsigned int DisableTexturePaletteVRAMBanks();
extern "C" unsigned int DisableMainBGVRAMBanks();
extern "C" unsigned int DisableSubBGVRAMBanks();
extern "C" unsigned int DisableMainObjVRAMBanks();
extern "C" unsigned int DisableSubObjVRAMBanks();
extern "C" void func_ov017_0218d274(void* arg0);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int v);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void func_020c391c(int arg0, int arg1, int arg2);
extern "C" void func_020c3984(unsigned int arg0);
extern "C" void func_020c51dc();
void ResetMatrixStacks020c537c();
void InitPaletteTables0202ac74();
void SetStructFieldsFromCode02028d68(int code);
void ConfigurePairMode020bb48c(unsigned int a, int b);
void InitGlobalStateAndInstallHandlers020bb780(void* stack, int flag);
extern "C" void func_0202c288(void* p);
int CheckField0NonZero_0202b7d8(int*);
void SetField0x3acValue_020100a0(GameState* gs, int value);
unsigned char GameState_GetProtagonistIndex(GameState* gs);
struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
void G3X_SetEdgeColorTable(int);
extern "C" void func_ov017_021a02f0(void* self);
void ClearFourRegions02079870(char*);
void ClearFourRegions020798b8(char*);
struct Obj020995c0;
void RunBufferedScript020998c4(Obj020995c0*);
void* GetGlobalWordList_0209cb68();
struct WordList0209cbb8;
void ResetWordList0209cbb8(WordList0209cbb8*);
void RunScriptIfAvailable0209cbcc(void* p);
void* GetGlobal02109a54_02099f60();
void PrepareAndRunBufferedScript02099f6c(char*);
void ResetAllocatorSlots020e5058();
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void CreateAndResetAllocator020e50ec(void* buf, unsigned int size);
void ResetAndLoadAllocatorSlots020e5114();
extern "C" void VramState_Reserve(void* p, int a, int b);
void InitStruct02013718(char* p, int a, int b);
extern "C" void func_0202df68(void* p);
struct Struct020A2CF0;
void ResetState020a2cf0(Struct020A2CF0*);
void InitCombatController020a2010(void* p);
void GameState_SetCamera(GameState* gs, int value);
struct List02046958;
void ClearListHeadTail(List02046958*);
extern "C" void func_ov017_021a124c(void* p);
extern "C" void func_ov017_0218f064(void* self, int id, int mask, int b, int extra);
int GetLowNibbleAt0x56b_02011ff0(void* gs, int id);
void* GetCombatantWithFlag0x1000_0200ff58(GameState* gs, int id);
void SetField0x2d0_020546a0(void* p, int value);
char* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" int func_020aaf84(void* buf, int a, int b, int c);
int VerifyAndApplySaveBuffer_020ac864(int flag);
int CheckSaveBufferStatus_020ab9c0(int flag);
int AllocateAndProcessScratchBuffer020abca8();
struct StateBits5ccc_11544;
void SetFlag0x5cccBit0_02011544(StateBits5ccc_11544*);
struct StateBits5ccc_11570;
int GetFlag0x5cccBit0_02011570(StateBits5ccc_11570*);
void* GetData02109020_0208e9e8();
extern "C" void func_0208ea10(void* p, int a);
unsigned long long GetCurrentTimestamp();
extern "C" int func_02011494(char*, void*);
extern "C" int func_020dcd40();
extern "C" void func_ov017_02191108(void* self, int a, int b, int c, int d);
extern "C" void func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" void func_0201099c(void* gs);
void InitStruct02070378(char*);
void SetField5cb0AndRecordByte0_02010774(char*, int);
void SetField5cb4AndRecordByte1_020107a8(char*, int);
void SetSlotByte020107dc(char*, int);
extern "C" void Scenario_SetFlag(void* p, unsigned char* arr, int bit, int set);
extern "C" void func_020120f0(void* gs);
extern "C" int func_02032370(int n);
void CopyToBattleField02039768(GameObject* obj, void* dst);
short GameState_GetLeaderIndex(GameState* gs);
void SetField0x21c_020a2770(void* p, short v);
extern "C" int rand();
extern "C" void func_0201206c(void* arg0, int arg1);
extern "C" void func_0206dfe8(void* arg0, int arg1, int arg2);
extern "C" void* func_02057924();
struct Foo02057930;
void InitStruct02057930(Foo02057930*);
void ClearCombatantsAndInitStruct02057978(Foo02057930*);
void* ZoneRecords_GetInstance();
#if defined(jpn)
extern "C" void func_02028894(void* arg0, void* arg1);
#else
extern "C" void func_02028894(void* arg0, void* arg1, void* arg2);
#endif
extern "C" void func_020287b4(void* p);
void* GetData02104b6c_02039e70();
void ResetBattleArrays02039e7c(void* p);
struct Container0203a54c;
void ProcessAllSubObjects0203a54c(Container0203a54c*);
void* MessageSystem_GetInstance();
extern "C" void func_02042c68(void* c);
extern "C" void MessageSystem_Stop(void* c);
void SetField0x1e28_02042b30(void* c, void* p);
extern "C" void func_ov017_0219b624(void* self);
extern "C" void func_ov017_0219ba0c(void* self, int a);
struct Foo0207df50;
void VramState_Rewind(Foo0207df50*);
void VramState_Restore(char*);
extern "C" void func_020432c4(void* c);
void VramState_Save(char*);
extern "C" void func_02020554(void* p);
void* GetGlobal02109030_020936f8();
extern "C" void func_020938f0(void* p);
void ReleaseHandleField340_020939ac(void* p);
void ClearTwoRegions0206ebf4(char*);
void* GetData02108ea8_0207d78c();
struct Init0207d7c0;
void InitStructArray0207d798(Init0207d7c0*);
int Scenario_TestFlag(int p, unsigned char* arr, int bit);
extern "C" void func_ov017_0219bfb4(int a, int b);
void InitAndResetHeader_0219e310(unsigned char*, int);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
struct FieldTaskQueue;
void FieldTaskQueue_Update(FieldTaskQueue*);
extern "C" void func_ov017_021baedc(void* p, int a);
void InitObjState_021b2174(unsigned char*);
struct S021b2ba0;
void SetNameChecked_021b2ba0(S021b2ba0*, char*);
void SetFields30And34_021b2bd0(void* p, int a, int b);
extern "C" int GetMainBGAssignedVRAMSize();
extern "C" void func_020ca458(unsigned int value, void* dest, int count);
extern "C" void func_020c9820();
extern "C" void func_020c38d4();
struct Struct_0200f3a4_9;
extern "C" void func_02010124(Struct_0200f3a4_9*);
extern "C" void func_020c3a0c(int arg0);
struct Struct_02015438;
extern "C" int func_02046b24(Struct_02015438**);
extern "C" void func_0206e424(void* arg0, int arg1);
extern "C" void func_ov017_021bdbf0(unsigned char*);
extern "C" void func_0202ad30();
extern "C" void func_0202adf0();
extern "C" void func_02012efc();
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_02046b08(void**);
struct Vector3i;
struct Struct_020115d0;
extern "C" int func_020115d0(Struct_020115d0*);
extern "C" int func_020115e8(void* arg0);
extern "C" void func_02011600(void* arg0);
struct Struct_02071488;
extern "C" int func_02071574(unsigned int, Struct_02071488*);
extern "C" int func_02011610(void* arg0);
extern "C" int func_02011628(void* arg0);
extern "C" void func_02011634(void* arg0);
extern "C" void func_020bc028(int arg0);
extern "C" void func_020d84e0();
extern "C" void func_0202aff4(void* arg0);
extern "C" void func_02043368(void* arg0);
extern "C" void func_ov017_0218cbd4(void* arg0);
extern "C" void func_ov017_02191cc0(void* arg0);
extern "C" void func_ov017_02195a20(void* arg0);
extern "C" void func_020d9834(int arg0);
extern "C" void func_0209c840(void* arg0);
extern "C" void func_0203aa08(void* arg0);
extern "C" void func_020bbd9c();
void CleanInvalidateOamBuffers0203bd88(void* oam);
void Forward0204359c(void* c, int a);
void NotifyAllEntries0203dd94(char*);
void NoOp_0219a188(void* self);
void NoOp_021a63cc(void* self);
void WriteControlAndToggle020d86d0(int a, int b);
void ForwardObjAndField0_021a4358(int p);
struct Obj0203bdb0;
void SyncMainSubOam0203bdb0(Obj0203bdb0*);
int* GetField1c_021a193c(int*);
extern "C" void func_020439b0(void* c, int a);
struct Node020579ec;
void ForEachNode020579ec(Node020579ec**);
extern "C" void func_ov017_021a63d0(void* self);
extern "C" void func_ov017_0219a18c(void* self);
extern "C" void func_0203ba74(void* p);
extern "C" void func_02027438(void* p);
struct Obj020275e4;
void UpdateTimedBufferState020275e4(Obj020275e4*);
struct ShortField0xb4_0205eac8;
int GetShortAt0xb4(ShortField0xb4_0205eac8*);
void SetupContextForMode0205ea20(void* p, int mode);
struct Actor0209c20c;
void InitActorContext0209c20c(Actor0209c20c*);
struct Obj_0205e8ec;
void RefreshDisplayState0205e8ec(Obj_0205e8ec*);
extern "C" void FieldTaskQueue_EndAll(void* p);
struct Struct_0203cfb4;
void Init0203cfb4(Struct_0203cfb4*);
extern "C" void func_ov017_021a316c(void* self);
void InitControllerObject_02043000(char*);
void CallHelperFourTimes_02190238(void* self);
void ResetBigStruct02013750(void* p, int a);
void ForwardFirstWord020998ac(int*);
void FreeWordListBuffer0209cd24(WordList0209cbb8*);
extern "C" void func_ov017_0219b938(void* self);
void ResetOverlayState_0219bc50(unsigned char*);
void AllocatorUnion_Free(AllocatorUnion*, void*);
void DestroyAllocatorsFromTable_021a0790(char*);
void DestroyAllocatorsFromTable_021a0964(char*);
void DestroyAllocatorsFromTable_021a0ba8(char*);
void DestroyAllocatorsFromTable_021a0f40(char*);
void DestroyAllocatorsFromTable_021a1114(char*);
void DestroyAllocatorsFromTable_021a0d6c(char*);
extern "C" void func_ov017_021a0470(void* self);
void ClearCombatantList_0200fd58(GameState* gs);
void ResetInputLogB_020a1edc();
void ResetInputLogA_020a1de4();
void ResetSlotsAndDestroySafeAllocator020e5094();
extern "C" void func_ov004_0216e9cc();
extern "C" void func_ov004_0216f854();

struct Struct_02109bf4_9 {
    char unknown_0_[0xc8];
    unsigned char unknown_c8_;
};

struct Struct_ov017_021d82e0_2 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    int unknown_4_;
};

extern Flags02109bf4 g_bgmPlayer;
extern char g_sePlayer;
extern char data_ov017_021d615c;
extern char g_mainAllocator;
extern char data_ov017_021d736c;
extern char data_ov017_021d7378;
extern Struct_ov017_021d82e0_2 data_ov017_021d82e0;
extern int data_02114e50;

struct Struct_ov017_0218b688 {
    unsigned short unknown_0_;
    char unknown_2_[5];
    unsigned char unknown_7_;
    char unknown_8_[8];
    int unknown_10_[3];
    unsigned short unknown_1c_;
    char unknown_1e_[2];
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
};

struct Struct_ov017_0218b688_2 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov017_0218b688_3 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    char unknown_25_[3];
    int unknown_28_;
    int unknown_2c_;
};

struct Struct_ov017_0218b688_4 {
    char* unknown_0_;
};

struct Struct_01ff91ac_17 {
    char unknown_0_[0x48];
};

struct Struct_ov017_0218b688_5 {
    char unknown_0_[0x28];
    unsigned char unknown_28_;
    char unknown_29_[0x38 - 0x29];
    char unknown_38_[0xc4 - 0x38];
    SafeAllocator unknown_c4_;
    char unknown_d8_[0x150 - 0xd8];
    char unknown_150_[0x27c - 0x150];
#if !defined(jpn)
    char unknown_27c_[0x2cc - 0x27c];
#endif
    char unknown_2cc_[0x87c - 0x2cc];
    char unknown_87c_[0xf0c - 0x87c];
#if defined(jpn)
    char unknown_f0c_[0x28f8 - 0xebc];
#else
    char unknown_f0c_[0x2b08 - 0xf0c];
#endif
    int unknown_2b08_;
    char unknown_2b0c_[0x2b90 - 0x2b0c];
    Struct_02012fa4 unknown_2b90_[0x12];
    char unknown_3520_[0x3634 - 0x3520];
    unsigned char unknown_3634_[0x12];
    unsigned char unknown_3646_[0x12];
    unsigned char unknown_3658_[0x12];
    char unknown_366a_[0x36d0 - 0x366a];
    char* unknown_36d0_;
    char unknown_36d4_[0x36fc - 0x36d4];
    void* unknown_36fc_;
    void* unknown_3700_;
    void* unknown_3704_;
    void* unknown_3708_;
    void* unknown_370c_;
    char unknown_3710_[0x371c - 0x3710];
    Struct_ov017_0218b688_3* unknown_371c_;
    char unknown_3720_[0x3734 - 0x3720];
    char* unknown_3734_;
    char unknown_3738_[0x373c - 0x3738];
    Struct_01ff91ac_17 unknown_373c_[4];
#if defined(jpn)
    char unknown_364c_[0x3b3c - 0x385c];
#else
    char unknown_385c_[0x3b4c - 0x385c];
#endif
    void* unknown_3b4c_;
    char unknown_3b50_[0x3b60 - 0x3b50];
    char* unknown_3b60_;
    char unknown_3b64_[0x4324 - 0x3b64];
    int unknown_4324_;
#if defined(jpn)
    char unknown_4108_[0x4434 - 0x4328];
#else
    char unknown_4328_[0x44c4 - 0x4328];
#endif
    void* unknown_44c4_;
};

#if defined(jpn)
enum { Enum_ov017_0218b688_15820 = 0x3d44, Enum_ov017_0218b688_396 = 0x180, Enum_ov017_0218b688_24 = 0x10 };
#else
enum { Enum_ov017_0218b688_15820 = 0x3dcc, Enum_ov017_0218b688_396 = 0x18c, Enum_ov017_0218b688_24 = 0x18 };
#endif
#define IS_OBJ_FLAG2_SET(h) ((h)->unknown_0_ != 0 ? ((*(int*)((h)->unknown_0_ + Enum_ov017_0218b688_15820) & 2) ? 1 : 0) : 0)

// USA: func_ov017_0218b688
extern "C" ARM void func_ov017_0218b688(Struct_ov017_0218b688_5* arg0) {
    char var0[0x2c8];
    char var1[0x68];
    char var2[8];
    unsigned char var3[4];

    SafeAllocator::GetLiveCount();
    unsigned int* flagWord = GlobalFlags_GetInstance();
    FlagWord_SetBits(flagWord, 0x100);
    GameState* gs = GameState::GetInstance();
    int mode = GetWord0x7f6c_0201201c(gs);
    unsigned char field = GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs);
    if (mode != 5 && field != 4 && field != 8 && field != 0xc) {
        DispatchWithGlobalContext020daf9c(1, 0, 1, 0);
    }
    SetMainBrightness((GameResources*)self, -16, 0);
    SetSubBrightness((GameResources*)self, -16, 0);
    SetWord0x0_0200fb84((int*)gs, (int)self);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* bigStruct = Zone3D_GetInstance();
    Request3f8* request = (Request3f8*)GetField0x3f8Address_0200fd0c(gs);
    loader->MaybeReset();
    Init0201133c((char*)gs);
    void* scriptBuf = GetData02109dcc_020a6084();
    ClearBuffer020a6180(scriptBuf);
    RunScriptIfAvailable020a6194(scriptBuf);
    void* regions3 = GetData02105254_0203b628();
    ClearThreeRegions0203b634((char*)regions3);
    void* oam = func_0203bd08();
    InitBattleContext0203bd24((char*)oam);
    void* extRegion = GetGlobalPtr021075f4_0203cf4c();
    InitWithExtendedRegion0203cf58((Struct_0203cf58*)extRegion);
    void* search = func_0202ae18();
    func_0202aec0(search);
    SetFlags00((GameResources*)self, 2);
    func_0205e22c(GetData02100044_0202ae24());
    void* buffered = GetPtrField0x468_02011584(gs);
    ClearFirstThreeWords_02099898((unsigned int*)buffered);
    for (int i = 0; i < 4; i++) {
        Init021b2f64((unsigned char*)&self->slots[i]);
    }
    LootableContainerManager::GetMainInstance()->Reset();
    Reset0208e4bc((char*)func_0208e0a8());
    InitSlotTable020e3004((SlotTable020e3004*)GetData02153637_020e2ff8());
    ResetEntryArray020e3814((Entry020e3840*)GetData02153660_020e3808());
    ClearThreeBytes020e358c((Bytes020e358c*)GetData02153634_020e3580());
    char* bits = Scenario_GetInstance();
    char* global418 = GetGlobal02109418_02094d6c();
    if (GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs) == 0) {
        if (GetWord0x7f6c_0201201c(gs) == 5 || GetByte0x4_0200fb9c((char*)gs) == 4) {
            ResetState0205facc(bits);
            Init02095518((char*)global418);
            ClearBattleRegion0x7ac4_020ac0dc();
        }
        func_02096524(var19);
    }
    *(int*)(bits + 0x480) = 0;
    *(int*)(bits + 0x47c) = 0;
    ClearState02070508((State02070508*)func_020704fc());
    func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
    func_0205e944(&g_sePlayer, 0x7f);
    g_bgmPlayer.flagsC8 &= ~4;
    ResetAndClearFlags020d7a5c((ResetObj020d7a5c*)TextQueue_GetInstance());
    if (GetWord0x7f6c_0201201c(gs) == 5 && GetByte0x4_0200fb9c((char*)gs) != 9) {
        SetByte0x4_0200fb94((char*)gs, 6);
    }

    LockStagedTextureVRAMCopying();
    DisableTextureImageVRAMBanks();
    DisableTexturePaletteVRAMBanks();
    DisableMainBGVRAMBanks();
    DisableSubBGVRAMBanks();
    DisableMainObjVRAMBanks();
    DisableSubObjVRAMBanks();
    func_ov017_0218d274(arg0);
    MapVRAMBanksToTexturePalette(0x40);
    MapVRAMBanksToMainBG(0x10);
    *(volatile unsigned int*)0x4000000 &= ~0x7000000;
    *(volatile unsigned int*)0x4000000 &= ~0x38000000;
    *(volatile unsigned short*)0x400000a = (*(volatile unsigned short*)0x400000a & 0x43) | 4;
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x1300;
    func_020c391c(1, 0, 1);
    func_020c3984(0);
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1300;
    MapVRAMBanksToSubBG(0x80);
    unsigned short* var20 = (unsigned short*)0x4001008;
    var20[0] = (var20[0] & 0x43) | 0x4e00;
    var20[1] = (var20[1] & 0x43) | 0xd00;
    MapVRAMBanksToMainObj(0x20);
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & 0xffcfffef) | 0x10;
    MapVRAMBanksToSubObj(0x100);
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    *(unsigned short*)0x4000304 &= ~0x8000;
    Finish3DRendering();
    func_020c51dc();
    func_020c537c();
    unsigned short* var21 = (unsigned short*)0x4001008;
    *(unsigned short*)0x400000a &= ~3;
    *(unsigned short*)0x4000008 = (*(unsigned short*)0x4000008 & ~3) | 1;
    var21[0] = (var21[0] & ~3) | 1;
    var21[1] = (var21[1] & ~3) | 2;
    var21[2] = (var21[2] & ~3);
    func_0202ac74();
    func_02028d68(3);
    func_020bb48c(4, 1);
    func_020bb780((void*)0x4000, 1);

    func_0202c288(var15);
    if (func_0202b7d8((int*)var15) == 0) {
        func_020100a0(GameState::GetInstance(), 0);
    } else {
        GameState* var22 = GameState::GetInstance();
        func_020100a0(var22, func_0202c1a4((Struct_0202c1a4*)var15));
    }
    G3X_SetEdgeColorTable((int)&data_ov017_021d615c);
    func_ov017_021a02f0(self);
    FlagWord_ClearBits((FlagWord020466f4*)flagWord, 0x100);
    ActionDataTables* regions4 = GetData02108e10_020797dc();
    ClearFourRegions02079870((char*)regions4);
    func_02079900(regions4, (SafeAllocator*)self->data150);
    RunBufferedScript020998c4((Obj020995c0*)buffered);
    void* wordList = GetGlobalWordList_0209cb68();
    ResetWordList0209cbb8((WordList0209cbb8*)wordList);
    RunScriptIfAvailable0209cbcc(wordList);
    PrepareAndRunBufferedScript02099f6c((char*)GetGlobal02109a54_02099f60());
    SprSprite_Init(&self->entries[11]);
    int ownAllocator = 0;
#if !defined(jpn)
    ResetAllocatorSlots020e5058();
    void* slotBuf = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x1866);
    if (slotBuf != 0) {
        CreateAndResetAllocator020e50ec(slotBuf, 0x1866);
    }
    func_020e5114();
#endif
    if (GetByte0x4_0200fb9c((char*)gs) == 9) {
        ownAllocator = 1;
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x30000), 0x30000);
        VramState_Reserve(self->dataF0c, 0x10, 0x10);
    }
    InitStruct02013718(bigStruct, (int)self->data38, (int)self->data2cc);
    func_0202df68(combatCtrl);
    ResetState020a2cf0((Struct020A2CF0*)combatCtrl);
    InitCombatController020a2010(combatCtrl);
    GameState_SetCamera(gs, (int)combatCtrl);
    ClearListHeadTail((List02046958*)self->nodeList);
    ClearListHeadTail((List02046958*)self->list700);
    ClearListHeadTail((List02046958*)self->list704);
    func_ov017_021a124c(self->list708);
    int loaded;
    int ok;
    int fresh = 0;
    Cursor371c* cursor = self->cursor;
    cursor->index = fresh;
    cursor->count = fresh;
    cursor->selected = fresh - 1;
    loaded = fresh;
    int newGame = fresh;
    int showIntro = fresh;

    if (func_0200fb9c((char*)var5) != 6 && func_0200fb9c((char*)var5) != 9) {
        if (func_020115a8((Struct_02000c9c_12*)var5) != 0) {
            var27 = 1;
        } else {
            if (func_0200fb9c((char*)var5) == 0 || func_0200fb9c((char*)var5) == 5) {
                int var33 = func_0200fb9c((char*)var5) == 5;
                var27 = var29 = 1;
                var31 = !var33;
                if (func_0201201c(var5) == 6) {
                    var28 = 0;
                    if (func_020aaf84(var2, 0, var33, 0) != 0) {
                        if (func_020ac864(var31 == 0) != 0) {
                            var28 = 1;
                            if (var33 != 0 && func_020ab9c0(0) == 0 &&
                                func_020abca8() == 0) {
                                func_02011544((Struct_02011544*)var5);
                                var28 = 0;
                            }
                        } else {
                            func_02011544((Struct_02011544*)var5);
                        }
                    }
                    if (var28 == 0) {
                        var29 = 0;
                        var27 = var29;
                        var31 = var29;
                    }
                }
            }
            if (func_0200fb9c((char*)var5) != 5) {
                func_0208ea10(func_0208e9e8(), 1);
            }
            var5->mainTimestamp_ = GetCurrentTimestamp();
            var5->altTimestamp_ = GetCurrentTimestamp();
        }

        if (loaded != 0) {
            char* save = (char*)GameState_GetParty(gs);
            int count = CopyOutRegion0x5718_02011494((char*)gs, ids);
            unsigned char* id;
            if (GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs) != 0) {
                id = ids;
            } else {
                var36 = (unsigned char*)(var34 + 0xf78);
                var35 = *(unsigned char*)(var34 + 0xf7c);
            }
            for (int i = 0; i < count; i++, id++) {
                int cur = *id;
                if (cur == GameState_GetProtagonistIndex(gs)) {
                    func_ov017_0218f064(self, cur, 0x200, 1, 0);
                } else {
                    if (func_02011ff0(var5, var38) > 0) {
                        func_ov017_0218f064(arg0, var38, 4, 1, func_02011ff0(var5, var38));
                    } else {
                        func_ov017_0218f064(arg0, var38, 0x1000, 1, 0);
                    }
                    void* combatant = GetCombatantWithFlag0x1000_0200ff58(gs, cur);
                    if (combatant != 0) {
                        SetField0x2d0_020546a0(combatant, GameState_GetProtagonistIndex(gs));
                    }
                }
                char* var40 = (char*)func_0200ff1c(var5, var38);
                if (var40 != 0) {
                    char* var41 = func_02053c6c((unsigned char*)var40);
                    if (var41 != 0 && (*(int*)(var41 + 0x18) & 1)) {
                        *(int*)(var40 + Enum_ov017_0218b688_396) |= 1;
                    }
                }
            }
            if (func_020dcd40() != 0) {
                func_ov017_02191108(arg0, 1, 1, 1, 1);
            }
        } else {
            func_ov017_0218f064(arg0, 0, 0x200, 1, 0);
            if (var29 == 0) {
                func_020897b4(0, 1, 6, 1, 1, 0, 0, 0, 0);
                func_0201099c(var5);
                g_keyManager.RefreshKeys();
                if (GetByte0x4_0200fb9c((char*)gs) == 0) {
                    InitStruct02070378((char*)request);
                    request->id = 100;
                    SetField5cb0AndRecordByte0_02010774((char*)gs, 3);
                    SetField5cb4AndRecordByte1_020107a8((char*)gs, 1);
                    SetSlotByte020107dc((char*)gs, 1);
                    Scenario_SetFlag(bits, (unsigned char*)(bits + 0x8c), 0xaed, 1);
                    func_020120f0(gs);
                    GameObject* hero = gs->GetProtagonist();
                    if (hero != 0) {
                        Party150* party = (Party150*)GetFieldAt0x150_02053c6c((unsigned char*)hero);
                        if (party != 0) {
                            if (g_keyManager.TestKeysHeld(0x100)) {
                                var43->unknown_49c_0_ = 0;
                            } else if (g_keyManager.TestKeysHeld(0x200)) {
                                var43->unknown_49c_0_ = 1;
                            } else {
                                var43->unknown_49c_0_ = (unsigned char)func_02032370(2);
                            }
                        }
                    }
                } else if (func_0200fb9c((char*)var5) == 2) {
                    func_02070378((char*)var10);
                    var10->unknown_0_ = 0x1905;
                    var10->unknown_20_ = 0x53fc;
                    func_02010774((char*)var5, 1);
                    func_020107a8((char*)var5, 1);
                    func_020107dc((char*)var5, 1);
                    func_020120f0(var5);
                    char* var44 = (char*)func_0200ff1c(var5, 0);
                    if (var44 != 0) {
                        char* var45 = func_02053c6c((unsigned char*)var44);
                        if (var45 != 0) {
                            *(unsigned short*)(var45 + 0x496) = 0x4e24;
                        }
                    }
                    var32 = 1;
                } else {
                    func_02070378((char*)var10);
                    var10->unknown_0_ = 1;
                    var10->unknown_7_ = 1;
                    var10->unknown_1c_ = 0;
                    var10->unknown_10_[0] = 0;
                    var10->unknown_10_[1] = 0;
                    var10->unknown_10_[2] = 0;
                    func_02010774((char*)var5, 1);
                    func_020107a8((char*)var5, 1);
                    func_020107dc((char*)var5, 1);
                    func_020120f0(var5);
                }
            }
            if (fresh != 0) {
                char* save = (char*)GameState_GetParty(gs);
                GameObject* hero = gs->GetProtagonist();
                if (hero != 0) {
                    CopyToBattleField02039768(hero, save + 0x2c8d);
                }
            }
        }
        func_ov017_02191108(arg0, 1, 1, 1, 1);
    }

    SetField0x21c_020a2770(combatCtrl, GameState_GetLeaderIndex(gs));
    if (GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs) == 0) {
        SetWord0x71f8_0201206c(gs, rand());
        if (GetByte0x4_0200fb9c((char*)gs) != 5) {
            func_0206dfe8(bits, 0x79e, 0x2bc);
        }
    }
    void* combatants = func_02057924();
    InitStruct02057930((Foo02057930*)combatants);
    void* entryTable = ZoneRecords_GetInstance();
#if defined(jpn)
    func_02028894(var49, arg0->unknown_d8_);
#else
    func_02028894(var49, arg0->unknown_d8_, arg0->unknown_27c_);
#endif
    void* battleArrays = GetData02104b6c_02039e70();
    ResetBattleArrays02039e7c(battleArrays);
    void* controller = MessageSystem_GetInstance();
    func_02042c68(controller);
    MessageSystem_Stop(controller);
    SetField0x1e28_02042b30(controller, self->pairTables);
    func_ov017_0219b624(self);
    func_ov017_0219ba0c(self, 0);
    VramState_Rewind((Foo0207df50*)self->pairTables);
    VramState_Restore((char*)self->pairTables);
    func_020432c4(controller);
    VramState_Save((char*)self->pairTables);
    if (GetByte0x4_0200fb9c((char*)gs) != 6 && GetByte0x4_0200fb9c((char*)gs) != 9) {
        self->colorA[0] = 0xd4;
        self->colorB[0] = 8;
        self->colorC[0] = 0;
        self->colorA[1] = 0xc0;
        self->colorB[1] = 8;
        self->colorC[1] = 0;
    }
    func_02020554(self->timedBuffer);
    *(int*)(self->timedBuffer + 0x5a4) |= 1;
    void* handle = GetGlobal02109030_020936f8();
    func_020938f0(handle);
    ClearTwoRegions0206ebf4((char*)self->regions);
    void* structArray = GetData02108ea8_0207d78c();
    InitStructArray0207d798((Init0207d7c0*)structArray);
    char* lighting = (char*)LightingManager::GetInstance();
    *(float*)(lighting + 0x94) = gs->GetDayTimer();
    *(int*)(lighting + 0x98) = gs->GetTimeOfDay();
    if (GetByte0x4_0200fb9c((char*)gs) != 6 && GetByte0x4_0200fb9c((char*)gs) != 9) {
        char* flagBits = Scenario_GetInstance();
        if (Scenario_TestFlag((int)flagBits, (unsigned char*)(flagBits + 0x8c), 0x1142) != 0) {
            newGame = 0;
        }
        if (var31 == 1) {
            func_ov017_0219bfb4(1, 0);
        } else {
            InitAndResetHeader_0219e310((unsigned char*)self->header70c, 0);
            AppendNodeToTail((TailList020469b4*)self->nodeList, (TailNode020469b4*)self->header70c);
            FieldTaskQueue_Update((FieldTaskQueue*)self->nodeList);
            if (Scenario_TestFlag((int)flagBits, (unsigned char*)(flagBits + 0x8c), 0x1142) != 0) {
                func_ov017_021baedc(self->node734, 1);
                *(unsigned short*)(self->node734 + 8) = 0x730a;
                AppendNodeToTail((TailList020469b4*)self->nodeList, (TailNode020469b4*)self->node734);
            }
        }
    }
    if (func_0200fb9c((char*)var5) == 6 || func_0200fb9c((char*)var5) == 9) {
        void* var56 = arg0->unknown_3b4c_;
        func_ov017_021b2174((unsigned char*)var56);
        if (func_0200fb9c((char*)var5) == 6) {
            func_ov017_021b2ba0((Struct_0206f81c_2*)var56, (char*)&data_ov017_021d736c);
            func_ov017_021b2bd0(var56, (int)func_ov004_0216e9cc, OVERLAY_ID(4));
        } else if (func_0200fb9c((char*)var5) == 9) {
            func_ov017_021b2ba0((Struct_0206f81c_2*)var56, (char*)&data_ov017_021d7378);
            func_ov017_021b2bd0(var56, (int)func_ov004_0216f854, OVERLAY_ID(4));
        }
        func_020469b4((Struct_0201bdac_2*)arg0->unknown_36fc_, (Struct_0201bdac*)var56);
    }
    func_020ca458(0, (void*)0x6000000, GetMainBGAssignedVRAMSize());
    func_020c9820();
    func_020c38d4();
    *(volatile unsigned int*)0x4001000 |= 0x10000;
    InitFields02010124((S_02010124*)gs);
    SetActiveDmaChannel020c3a0c(0);
    unsigned long long last = GetCurrentTimestamp();
    void* list = self->list700;
    while (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)list) == 0x13) {
        loader->RemoveAllLocks();
        FieldTaskQueue_Update((FieldTaskQueue*)list);
    }
    func_0206e424(var18, 0);
    if (var32 != 0) {
        func_ov017_021bdbf0((unsigned char*)arg0->unknown_3b60_);
        arg0->unknown_3b60_[0x11] = 2;
        func_020469b4((Struct_0201bdac_2*)arg0->unknown_36fc_, (Struct_0201bdac*)arg0->unknown_3b60_);
    }
    if (func_020115a8((Struct_02000c9c_12*)var5) != 0) {
        func_020115c0((Struct_02000c9c_14*)var5);
    }
    FontBankLoader* global400 = FontBankLoader_GetInstance();
    ClearBuffer0202ad30();
    FlushAndClearBuffer0202adf0();

    for (;;) {
        int var60 = 0;
        if (TestFlags00((GameResources*)arg0, 0x4000) != 0) {
            var60 = 1;
        }
        func_02012efc();
        GameState::GetInstance();
        Scenario_GetInstance();
        AlwaysTrue02094b4c(global400);
        int quit = 0;
        if (self->exitRequest == 1) {
            self->exitRequest = 0;
            quit = 1;
        }
        if (func_02011570((Struct_02000c9c_9*)var5) != 0) {
            if (IsBrightnessTransitionActive((GameResources*)arg0) == 0) {
                var61 = 1;
            }
        }
        if (func_020115a8((Struct_02000c9c_12*)var5) != 0 && func_02046b08((void**)arg0->unknown_36fc_) != 0) {
            var61 = 1;
            func_02070378((char*)var10);
            var10->unknown_0_ = *(unsigned short*)var9;
            var10->unknown_7_ = var61;
            GameObject* var62 = var5->GetUnknownGameObject();
            if (var62 != 0) {
                *(Vector3i*)var10->unknown_10_ = *(Vector3i const*)((char*)var62 + 0x44);
                var10->unknown_1c_ = var62->obj3D_.rotation_.y;
            }
            if (func_020115d0((Struct_020115d0*)var5) != 0) {
                var10->unknown_20_ = func_020115e8(var5);
                func_02011600(var5);
                if (func_02071574((unsigned short)var10->unknown_20_, (Struct_02071488*)var1) != 0) {
                    var10->unknown_0_ = *(unsigned short*)(var1 + 0xe);
                    var10->unknown_7_ = 0;
                }
            }
            if (func_02011610(var5) != 0) {
                var10->unknown_28_ = func_02011628(var5);
                func_02011634(var5);
            }
        }
        if (var61 != 0) {
            if (func_0200fb9c((char*)var5) != 2) {
                func_020bc028(0);
            }
            func_020d84e0();
            func_0202aff4(var15);
            SetMainBrightness((GameResources*)arg0, -16, 0);
            SetSubBrightness((GameResources*)arg0, -16, 0);
            if (func_0200fb9c((char*)var5) == 8) {
                SetMainBrightness((GameResources*)arg0, 16, 0);
                SetSubBrightness((GameResources*)arg0, 16, 0);
            }
            break;
        }
        func_02043368(var51);
        func_ov017_0218cbd4(arg0);
        func_ov017_02191cc0(arg0);
        if (data_ov017_021d82e0.unknown_0_ == 0 && TestFlags04((GameResources*)arg0, 1) == 0) {
            func_ov017_02195a20(arg0);
        }
        if (var60 != 0) {
            func_020d9834(1);
        }
        func_0209c840(&g_bgmPlayer);
        ResetXYField0203aa08(&g_sePlayer);
        func_020bbd9c();
        func_0203bd88(var13);
        func_0204359c(var51, Enum_ov017_0218b688_24);
        if (var60 != 0) {
            func_020d9834(1);
        } else {
            func_020d9834(0);
        }
        var8->RemoveAllLocks();
        func_0203dd94((char*)var14);
        func_ov017_0219a188(arg0);
        func_ov017_021a63cc(arg0);
        if (data_ov017_021d82e0.unknown_0_ == 0) {
            int var63 = var5->currentNumTicks_;
            for (int var64 = 1; var64 < 2 - var63; var64++) {
                func_020c9820();
            }
            func_020d86d0(1, 0);
            arg0->unknown_28_ = 1;
            func_020c9820();
        }
        if (data_ov017_021d82e0.unknown_0_ != 0) {
            var5->CalculateDeltaTime(0);
        } else {
            unsigned long long var65 = GetCurrentTimestamp();
            var5->CalculateDeltaTime(((var65 - var57) * 64000) / 33514);
        }
        var57 = GetCurrentTimestamp();
        data_02114e50++;
        func_ov017_021a4358((int)arg0->unknown_36fc_);
        func_0203bdb0((Struct_0203bdb0*)var13);
        int var66 = 1;
        if (func_02046b24((Struct_02015438**)arg0->unknown_36fc_) == 2) {
            Struct_ov017_0218b688_4* var67 = (Struct_ov017_0218b688_4*)func_ov017_021a193c((int*)arg0->unknown_3708_);
            if (var67 != 0 && IS_OBJ_FLAG2_SET(var67)) {
                var66 = 0;
            }
        }
        func_020439b0(var51, var66);
        func_020579ec((Struct_020579ec**)var48);
        func_ov017_021a63d0(arg0);
        func_ov017_0219a18c(arg0);
        func_0203ba74(var12);
        func_02027438(arg0->unknown_36d0_);
#if !defined(jpn)
        func_020275e4((Struct_020275e4*)arg0->unknown_36d0_);
#endif
        if (var60 != 0) {
            func_020d9834(1);
        }
    }

    if (func_02011570((Struct_02000c9c_9*)var5) != 0) {
        SetMainBrightness((GameResources*)arg0, -16, 0);
        SetSubBrightness((GameResources*)arg0, -16, 0);
    }
    if (GetByte0x4_0200fb9c((char*)gs) != 2) {
        if (GetShortAt0xb4((ShortField0xb4_0205eac8*)&g_sePlayer) != 100) {
            SetupContextForMode0205ea20(&g_sePlayer, 100);
        }
        InitActorContext0209c20c((Actor0209c20c*)&g_bgmPlayer);
        RefreshDisplayState0205e8ec((Obj_0205e8ec*)&g_sePlayer);
        func_020bbd9c();
    }
    g_bgmPlayer.flagsC8 &= ~4;
    FieldTaskQueue_EndAll(self->nodeList);
    Init0203cfb4((Struct_0203cfb4*)extRegion);
    func_ov017_021a316c(self);
    for (int i = 0; i < 0x12; i++) {
        SprSprite_Unload(&self->entries[i]);
    }
    ClearFourRegions020798b8((char*)regions4);
    InitControllerObject_02043000((char*)controller);
    ReleaseHandleField340_020939ac(handle);
    ProcessAllSubObjects0203a54c((Container0203a54c*)battleArrays);
    ClearCombatantsAndInitStruct02057978((Foo02057930*)combatants);
    func_020287b4(entryTable);
    CallHelperFourTimes_02190238(self);
    ResetBigStruct02013750(bigStruct, 1);
    ForwardFirstWord020998ac((int*)buffered);
    FreeWordListBuffer0209cd24((WordList0209cbb8*)wordList);
    InitStructArray0207d798((Init0207d7c0*)structArray);
    func_ov017_0219b938(self);
    ResetOverlayState_0219bc50((unsigned char*)self);
    if (GetByte0x4_0200fb9c((char*)gs) == 9 && ownAllocator == 1) {
        void* signedAlloc = self->allocator.GetSignedAllocator();
        if (signedAlloc != 0) {
            self->allocator.Destroy();
            AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, signedAlloc);
        }
        func_0200fb94((char*)var5, 6);
        func_02012010(var5, 2);
    }
    int var70 = arg0->unknown_2b08_;
    if (var70 == 0) {
        func_ov017_021a0790((char*)arg0);
    } else if (var70 == 1) {
        func_ov017_021a0964((char*)arg0);
    } else if (var70 == 2) {
        func_ov017_021a0ba8((char*)arg0);
    } else if (var70 == 3) {
        func_ov017_021a0f40((char*)arg0);
    } else if (var70 == 4) {
        func_ov017_021a1114((char*)arg0);
    } else if (var70 == 5) {
        func_ov017_021a0d6c((char*)arg0);
    }
    func_ov017_021a0470(arg0);
    func_0200fd58(var5);
    func_020a1edc();
    func_020a1de4();
    *(volatile unsigned int*)0x4000000 &= ~0xe000;
    data_ov017_021d82e0.unknown_4_ = 0;
#if !defined(jpn)
    func_020e5094();
#endif
    SafeAllocator::GetLiveCount();
    func_0200fb84((int*)var5, 0);
    func_020a2010(var0);
    func_020a2cf0((Struct_0204a120_2*)var0);
    func_0202df68(var0);
}
