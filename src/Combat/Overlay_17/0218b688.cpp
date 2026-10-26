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
void GameState_ClearMovieId(FieldBlock63d6_115c0*);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
void SetMainBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
void SetWord0x0_0200fb84(int*, int);
extern "C" char* Zone3D_GetInstance();
void* GameState_GetZoneTransition(GameState* gs);
void GameState_LoadSkillTable(char*);
void* GetData02109dcc_020a6084();
void ClearBuffer020a6180(void* p);
void RunScriptIfAvailable020a6194(void* p);
void* BgVram_GetInstance();
void BgVram_Clear(char*);
extern "C" void* OamManager_GetInstance();
void OamManager_Init(char*);
void* GetGlobalPtr021075f4_0203cf4c();
struct Struct_0203cf58;
void InitWithExtendedRegion0203cf58(Struct_0203cf58*);
extern "C" void* LinkSession_GetInstance();
extern "C" void LinkSession_Reset(void* p);
void* LinkMessageQueue_GetInstance();
extern "C" void LinkMessageQueue_Reset(void* p);
void* GameState_GetZoneTable(void* gs);
void ZoneTable_Clear(unsigned int*);
void Init021b2f64(unsigned char*);
extern "C" void* LootPointList_GetInstance();
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
void GX_SetGraphicsMode(int mode, int a, int b);
void GXS_SetGraphicsMode(unsigned int mode);
extern "C" void func_020c51dc();
void ResetMatrixStacks020c537c();
void DebugConsole_Init();
void GlyphMetrics_SetDisplayMode(int code);
void ConfigurePairMode020bb48c(unsigned int a, int b);
void InitGlobalStateAndInstallHandlers020bb780(void* stack, int flag);
extern "C" void LinkSession_UpdateMemberCount(void* p);
int LinkSession_IsActive(int*);
void GameState_SetProtagonistIndex(GameState* gs, int value);
unsigned char GameState_GetProtagonistIndex(GameState* gs);
struct SearchStruct0202c1a4;
int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
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
void Zone3D_Init(char* p, int a, int b);
extern "C" void Camera_Init(void* p);
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
int GameState_IsErrorScreenRequested(StateBits5ccc_11570*);
void* GetData02109020_0208e9e8();
extern "C" void func_0208ea10(void* p, int a);
unsigned long long GetCurrentTimestamp();
int GameState_GetOwnPartyOrder(char*, void*);
extern "C" int func_020dcd40();
extern "C" void Party_ReformLine(void* self, int a, int b, int c, int d);
extern "C" void func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" void GameState_CreatePresetCharacters(void* gs);
void InitStruct02070378(char*);
void GameState_SetStoryChapter(char*, int);
void GameState_SetStoryPart(char*, int);
void GameState_SetStoryStep(char*, int);
extern "C" void Scenario_SetFlag(void* p, unsigned char* arr, int bit, int set);
extern "C" void GameState_CreateNativeId(void* gs);
extern "C" int RandomIntBelow(int n);
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
extern "C" void _Z16ZoneRecords_InitP11Big02028894PcS1_(void* p, void* a);
#else
extern "C" void _Z16ZoneRecords_InitP11Big02028894PcS1_(void* p, void* a, void* b);
#endif
extern "C" void ZoneRecords_Reset(void* p);
void* NumberPopups_GetInstance();
void NumberPopups_Init(void* p);
struct Container0203a54c;
void NumberPopups_UnloadSprites(Container0203a54c*);
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
extern "C" void MapDisplay_Init(void* p);
void* GetGlobal02109030_020936f8();
extern "C" void func_020938f0(void* p);
void ReleaseHandleField340_020939ac(void* p);
void ClearTwoRegions0206ebf4(char*);
void* GetData02108ea8_0207d78c();
struct Init0207d7c0;
void InitStructArray0207d798(Init0207d7c0*);
int Scenario_TestFlag(int p, unsigned char* arr, int bit);
extern "C" void func_ov017_0219bfb4(int a, int b);
void FieldTask_InitEnterZone(unsigned char*, int);
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
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
void OS_WaitVBlankIntr();
void RestoreDisplayMode_020c38d4();
struct S_02010124;
void GameState_ResetTiming(S_02010124*);
void SetActiveDmaChannel020c3a0c(int ch);
struct HeadNode02046b24;
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void func_0206e424(void* p, int a);
void InitObj021bdbf0(unsigned char*);
void DebugConsole_Clear();
void DebugConsole_Upload();
void Main_UpdateLidAndInput();
int IsBrightnessTransitionActive(GameResources*);
int FieldTaskQueue_IsEmpty(void**);
struct Vector3i;
struct FieldBlock63d8_115d0;
int IsHalfword0x63d8Set_020115d0(FieldBlock63d8_115d0*);
int GetHalfword0x63d8_020115e8(void* gs);
void ClearHalfword0x63d8_02011600(void* gs);
struct Obj02071488;
int RunScriptByValueRange02071574(unsigned int, Obj02071488*);
int CheckField0x63daNonZero_02011610(void* gs);
int GetHalfword0x63da_02011628(void* gs);
void ClearHalfword0x63da_02011634(void* gs);
void DispatchToActiveEntries020bc028(int a);
void BlankFunction020d84e0();
void LinkSession_Close(void* p);
extern "C" void func_02043368(void* c);
extern "C" void func_ov017_0218cbd4(void* self);
extern "C" void func_ov017_02191cc0(void* self);
extern "C" void func_ov017_02195a20(void* self);
void DispatchByFlag020d9834(int flag);
extern "C" void func_0209c840(void* p);
void SoundPlayer_PlayPending(void* p);
extern "C" void func_020bbd9c();
void OamManager_FlushBuffers(void* oam);
void Forward0204359c(void* c, int a);
void NotifyAllEntries0203dd94(char*);
void NoOp_0219a188(void* self);
void NoOp_021a63cc(void* self);
void WriteControlAndToggle020d86d0(int a, int b);
void ForwardObjAndField0_021a4358(int p);
struct Obj0203bdb0;
void OamManager_UploadBuffers(Obj0203bdb0*);
int* GetField1c_021a193c(int*);
extern "C" void func_020439b0(void* c, int a);
struct Node020579ec;
void ForEachNode020579ec(Node020579ec**);
extern "C" void func_ov017_021a63d0(void* self);
extern "C" void func_ov017_0219a18c(void* self);
extern "C" void BgTransfers_UploadDirtyScreens(void* p);
extern "C" void MapDisplay_SetMapScroll(void* p);
struct Obj020275e4;
void MapDisplay_ScrollMapName(Obj020275e4*);
struct ShortField0xb4_0205eac8;
int GetShortAt0xb4(ShortField0xb4_0205eac8*);
void SePlayer_LoadArchive(void* p, int mode);
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
void Zone3D_Unload(void* p, int a);
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
    Request3f8* request = (Request3f8*)GameState_GetZoneTransition(gs);
    loader->ClearQueue();
    GameState_LoadSkillTable((char*)gs);
    void* scriptBuf = GetData02109dcc_020a6084();
    ClearBuffer020a6180(scriptBuf);
    RunScriptIfAvailable020a6194(scriptBuf);
    void* regions3 = BgVram_GetInstance();
    BgVram_Clear((char*)regions3);
    void* oam = OamManager_GetInstance();
    OamManager_Init((char*)oam);
    void* extRegion = GetGlobalPtr021075f4_0203cf4c();
    InitWithExtendedRegion0203cf58((Struct_0203cf58*)extRegion);
    void* search = LinkSession_GetInstance();
    LinkSession_Reset(search);
    SetFlags00((GameResources*)self, 2);
    LinkMessageQueue_Reset(LinkMessageQueue_GetInstance());
    void* buffered = GameState_GetZoneTable(gs);
    ZoneTable_Clear((unsigned int*)buffered);
    for (int i = 0; i < 4; i++) {
        Init021b2f64((unsigned char*)&self->slots[i]);
    }
    LootableContainerManager::GetMainInstance()->Reset();
    Reset0208e4bc((char*)LootPointList_GetInstance());
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
    GX_SetGraphicsMode(1, 0, 1);
    GXS_SetGraphicsMode(0);
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
    subPrio[0] = (subPrio[0] & ~3) | 1;
    subPrio[1] = (subPrio[1] & ~3) | 2;
    subPrio[2] = (subPrio[2] & ~3);
    DebugConsole_Init();
    GlyphMetrics_SetDisplayMode(3);
    ConfigurePairMode020bb48c(4, 1);
    InitGlobalStateAndInstallHandlers020bb780((void*)0x4000, 1);

    LinkSession_UpdateMemberCount(search);
    if (LinkSession_IsActive((int*)search) == 0) {
        GameState_SetProtagonistIndex(GameState::GetInstance(), 0);
    } else {
        GameState* inst = GameState::GetInstance();
        GameState_SetProtagonistIndex(inst, LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search));
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
    Zone3D_Init(bigStruct, (int)self->data38, (int)self->data2cc);
    Camera_Init(combatCtrl);
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
            int count = GameState_GetOwnPartyOrder((char*)gs, ids);
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
                Party_ReformLine(self, 1, 1, 1, 1);
            }
        } else {
            func_ov017_0218f064(arg0, 0, 0x200, 1, 0);
            if (var29 == 0) {
                func_020897b4(0, 1, 6, 1, 1, 0, 0, 0, 0);
                GameState_CreatePresetCharacters(gs);
                g_keyManager.RefreshKeys();
                if (GetByte0x4_0200fb9c((char*)gs) == 0) {
                    InitStruct02070378((char*)request);
                    request->id = 100;
                    GameState_SetStoryChapter((char*)gs, 3);
                    GameState_SetStoryPart((char*)gs, 1);
                    GameState_SetStoryStep((char*)gs, 1);
                    Scenario_SetFlag(bits, (unsigned char*)(bits + 0x8c), 0xaed, 1);
                    GameState_CreateNativeId(gs);
                    GameObject* hero = gs->GetProtagonist();
                    if (hero != 0) {
                        Party150* party = (Party150*)GetFieldAt0x150_02053c6c((unsigned char*)hero);
                        if (party != 0) {
                            if (g_keyManager.TestKeysHeld(0x100)) {
                                var43->unknown_49c_0_ = 0;
                            } else if (g_keyManager.TestKeysHeld(0x200)) {
                                var43->unknown_49c_0_ = 1;
                            } else {
                                party->active = (unsigned char)RandomIntBelow(2);
                            }
                        }
                    }
                } else if (GetByte0x4_0200fb9c((char*)gs) == 2) {
                    InitStruct02070378((char*)request);
                    request->id = 0x1905;
                    request->value20 = 0x53fc;
                    GameState_SetStoryChapter((char*)gs, 1);
                    GameState_SetStoryPart((char*)gs, 1);
                    GameState_SetStoryStep((char*)gs, 1);
                    GameState_CreateNativeId(gs);
                    char* member = (char*)GetCombatantWithFlag0x100_0200ff1c(gs, 0);
                    if (member != 0) {
                        char* info = GetFieldAt0x150_02053c6c((unsigned char*)member);
                        if (info != 0) {
                            *(unsigned short*)(info + 0x496) = 0x4e24;
                        }
                    }
                    var32 = 1;
                } else {
                    InitStruct02070378((char*)request);
                    request->id = 1;
                    request->flag7 = 1;
                    request->dir = 0;
                    request->pos[0] = 0;
                    request->pos[1] = 0;
                    request->pos[2] = 0;
                    GameState_SetStoryChapter((char*)gs, 1);
                    GameState_SetStoryPart((char*)gs, 1);
                    GameState_SetStoryStep((char*)gs, 1);
                    GameState_CreateNativeId(gs);
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
        Party_ReformLine(self, 1, 1, 1, 1);
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
    _Z16ZoneRecords_InitP11Big02028894PcS1_(entryTable, self->dataD8);
#else
    _Z16ZoneRecords_InitP11Big02028894PcS1_(entryTable, self->dataD8, self->data27c);
#endif
    void* battleArrays = NumberPopups_GetInstance();
    NumberPopups_Init(battleArrays);
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
    MapDisplay_Init(self->timedBuffer);
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
            FieldTask_InitEnterZone((unsigned char*)self->header70c, 0);
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
    MIi_CpuClearFast(0, (void*)0x6000000, GetMainBGAssignedVRAMSize());
    OS_WaitVBlankIntr();
    RestoreDisplayMode_020c38d4();
    *(volatile unsigned int*)0x4001000 |= 0x10000;
    GameState_ResetTiming((S_02010124*)gs);
    SetActiveDmaChannel020c3a0c(0);
    unsigned long long last = GetCurrentTimestamp();
    void* list = self->list700;
    while (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)list) == 0x13) {
        loader->RemoveAllLocks();
        FieldTaskQueue_Update((FieldTaskQueue*)list);
    }
    func_0206e424(var18, 0);
    if (var32 != 0) {
        func_ov017_021bdbf0((unsigned char*)arg0->unknown_3b60_);
        arg0->unknown_3b60_[0x11] = 2;
        func_020469b4((Struct_0201bdac_2*)arg0->unknown_36fc_, (Struct_0201bdac*)arg0->unknown_3b60_);
    }
    if (GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs) != 0) {
        GameState_ClearMovieId((FieldBlock63d6_115c0*)gs);
    }
    FontBankLoader* global400 = FontBankLoader_GetInstance();
    DebugConsole_Clear();
    DebugConsole_Upload();

    for (;;) {
        int var60 = 0;
        if (TestFlags00((GameResources*)arg0, 0x4000) != 0) {
            var60 = 1;
        }
        Main_UpdateLidAndInput();
        GameState::GetInstance();
        Scenario_GetInstance();
        AlwaysTrue02094b4c(global400);
        int quit = 0;
        if (self->exitRequest == 1) {
            self->exitRequest = 0;
            quit = 1;
        }
        if (GameState_IsErrorScreenRequested((StateBits5ccc_11570*)gs) != 0) {
            if (IsBrightnessTransitionActive((GameResources*)self) == 0) {
                quit = 1;
            }
        }
        if (GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs) != 0 && FieldTaskQueue_IsEmpty((void**)self->nodeList) != 0) {
            quit = 1;
            InitStruct02070378((char*)request);
            request->id = *(unsigned short*)bigStruct;
            request->flag7 = quit;
            GameObject* obj = gs->GetLeader();
            if (obj != 0) {
                *(Vector3i*)request->pos = *(Vector3i const*)((char*)obj + 0x44);
                request->dir = obj->obj3D_.rotation_.y;
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
            BlankFunction020d84e0();
            LinkSession_Close(search);
            SetMainBrightness((GameResources*)self, -16, 0);
            SetSubBrightness((GameResources*)self, -16, 0);
            if (GetByte0x4_0200fb9c((char*)gs) == 8) {
                SetMainBrightness((GameResources*)self, 16, 0);
                SetSubBrightness((GameResources*)self, 16, 0);
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
        SoundPlayer_PlayPending(&g_sePlayer);
        func_020bbd9c();
        OamManager_FlushBuffers(oam);
        Forward0204359c(controller, RegionControllerMode);
        if (flag4000 != 0) {
            DispatchByFlag020d9834(1);
        } else {
            func_020d9834(0);
        }
        loader->RemoveAllLocks();
        NotifyAllEntries0203dd94((char*)extRegion);
        NoOp_0219a188(self);
        NoOp_021a63cc(self);
        if (data_ov017_021d82e0.paused == 0) {
            int speed = gs->currentNumTicks_;
            for (int f = 1; f < 2 - speed; f++) {
                OS_WaitVBlankIntr();
            }
            WriteControlAndToggle020d86d0(1, 0);
            self->running = 1;
            OS_WaitVBlankIntr();
        }
        if (data_ov017_021d82e0.unknown_0_ != 0) {
            var5->CalculateDeltaTime(0);
        } else {
            unsigned long long var65 = GetCurrentTimestamp();
            var5->CalculateDeltaTime(((var65 - var57) * 64000) / 33514);
        }
        var57 = GetCurrentTimestamp();
        data_02114e50++;
        ForwardObjAndField0_021a4358((int)self->nodeList);
        OamManager_UploadBuffers((Obj0203bdb0*)oam);
        int allow = 1;
        if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->nodeList) == 2) {
            Holder021a193c* holder = (Holder021a193c*)GetField1c_021a193c((int*)self->list708);
            if (holder != 0 && IS_OBJ_FLAG2_SET(holder)) {
                allow = 0;
            }
        }
        func_020439b0(controller, allow);
        ForEachNode020579ec((Node020579ec**)combatants);
        func_ov017_021a63d0(self);
        func_ov017_0219a18c(self);
        BgTransfers_UploadDirtyScreens(regions3);
        MapDisplay_SetMapScroll(self->timedBuffer);
#if !defined(jpn)
        MapDisplay_ScrollMapName((Obj020275e4*)self->timedBuffer);
#endif
        if (var60 != 0) {
            func_020d9834(1);
        }
    }

    if (GameState_IsErrorScreenRequested((StateBits5ccc_11570*)gs) != 0) {
        SetMainBrightness((GameResources*)self, -16, 0);
        SetSubBrightness((GameResources*)self, -16, 0);
    }
    if (GetByte0x4_0200fb9c((char*)gs) != 2) {
        if (GetShortAt0xb4((ShortField0xb4_0205eac8*)&g_sePlayer) != 100) {
            SePlayer_LoadArchive(&g_sePlayer, 100);
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
    NumberPopups_UnloadSprites((Container0203a54c*)battleArrays);
    ClearCombatantsAndInitStruct02057978((Foo02057930*)combatants);
    ZoneRecords_Reset(entryTable);
    CallHelperFourTimes_02190238(self);
    Zone3D_Unload(bigStruct, 1);
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
    SetWord0x0_0200fb84((int*)gs, 0);
    InitCombatController020a2010(combatCtrl);
    ResetState020a2cf0((Struct020A2CF0*)combatCtrl);
    Camera_Init(combatCtrl);
}
