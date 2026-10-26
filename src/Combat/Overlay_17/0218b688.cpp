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

extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int* word, unsigned int bits);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" int func_0201201c(void* gs);
extern "C" void func_02012010(void* gs, int value);
struct FieldBlock63d6_115a8;
extern "C" unsigned char func_020115a8(FieldBlock63d6_115a8*);
struct FieldBlock63d6_115c0;
extern "C" void GameState_ClearMovieId(FieldBlock63d6_115c0*);
extern "C" void func_020daf9c(int a, int b, int c, int d);
void SetMainBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
extern "C" void func_0200fb84(int*, int);
extern "C" char* Zone3D_GetInstance();
extern "C" void* GameState_GetZoneTransition(GameState* gs);
extern "C" void GameState_LoadSkillTable(char*);
extern "C" void* func_020a6084();
extern "C" void func_020a6180(void* p);
extern "C" void func_020a6194(void* p);
extern "C" void* BgVram_GetInstance();
extern "C" void BgVram_Clear(char*);
extern "C" void* OamManager_GetInstance();
extern "C" void OamManager_Init(char*);
extern "C" void* func_0203cf4c();
struct Struct_0203cf58;
extern "C" void func_0203cf58(Struct_0203cf58*);
extern "C" void* LinkSession_GetInstance();
extern "C" void LinkSession_Reset(void* p);
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void LinkMessageQueue_Reset(void* p);
extern "C" void* GameState_GetZoneTable(void* gs);
extern "C" void ZoneTable_Clear(unsigned int*);
extern "C" void func_ov017_021b2f64(unsigned char*);
extern "C" void* LootPointList_GetInstance();
extern "C" void func_0208e4bc(char*);
extern "C" void* func_020e2ff8();
struct Struct_020e3004;
extern "C" void func_020e3004(Struct_020e3004*);
extern "C" void* func_020e3808();
struct Struct_020e3814;
extern "C" void func_020e3814(Struct_020e3814*);
extern "C" void* func_020e3580();
struct Struct_020e358c;
extern "C" void func_020e358c(Struct_020e358c*);
extern "C" char* Scenario_GetInstance();
extern "C" char* func_02094d6c();
extern "C" unsigned char func_0200fb9c(char*);
extern "C" void func_0200fb94(char*, unsigned char);
extern "C" void func_0205facc(void* p);
extern "C" void func_02095518(char*);
extern "C" void func_020ac0dc();
extern "C" void func_02096524(void* p);
extern "C" void* func_020704fc();
struct Struct_02108d5c;
extern "C" void func_02070508(Struct_02108d5c*);
extern "C" void func_0209c2e0(void* p, int a, int b);
extern "C" void func_0205e944(void* p, int a);
extern "C" void* TextQueue_GetInstance();
struct ResetObj020d7a5c;
extern "C" void func_020d7a5c(ResetObj020d7a5c*);
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
extern "C" void func_ov017_0218d274(void* controller);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int v);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void GX_SetGraphicsMode(int mode, int a, int b);
extern "C" void GXS_SetGraphicsMode(unsigned int mode);
extern "C" void func_020c51dc();
extern "C" void func_020c537c();
extern "C" void DebugConsole_Init();
extern "C" void GlyphMetrics_SetDisplayMode(int code);
extern "C" void func_020bb48c(unsigned int a, int b);
extern "C" void func_020bb780(void* arg0, int flag);
extern "C" void LinkSession_UpdateMemberCount(void* p);
extern "C" int LinkSession_IsActive(int*);
extern "C" void GameState_SetProtagonistIndex(GameState* gs, int value);
extern "C" unsigned char GameState_GetProtagonistIndex(GameState* gs);
struct SearchStruct0202c1a4;
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void G3X_SetEdgeColorTable(int);
extern "C" void func_ov017_021a02f0(void* self);
extern "C" void func_02079870(char*);
extern "C" void func_020798b8(char*);
struct Struct_020995c0;
extern "C" void func_020998c4(Struct_020995c0*);
extern "C" void* func_0209cb68();
struct Struct_0209cbb8;
extern "C" void func_0209cbb8(Struct_0209cbb8*);
extern "C" void func_0209cbcc(void* p);
extern "C" void* func_02099f60();
extern "C" void func_02099f6c(char*);
extern "C" void func_020e5058();
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void func_020e50ec(void* buf, unsigned int size);
extern "C" void func_020e5114();
extern "C" void VramState_Reserve(void* p, int a, int b);
extern "C" void Zone3D_Init(char* p, int a, int b);
extern "C" void Camera_Init(void* p);
struct Struct_0204a120_2;
extern "C" void func_020a2cf0(Struct_0204a120_2*);
extern "C" void func_020a2010(void* p);
extern "C" void GameState_SetCamera(GameState* gs, int value);
struct Struct_02046958;
extern "C" void func_02046958(Struct_02046958*);
extern "C" void func_ov017_021a124c(void* p);
extern "C" void func_ov017_0218f064(void* self, int id, int mask, int b, int extra);
extern "C" int func_02011ff0(void* gs, int id);
extern "C" void* func_0200ff58(GameState* gs, int id);
extern "C" void func_020546a0(void* p, int value);
extern "C" char* func_02053c6c(unsigned char*);
extern "C" int func_020aaf84(void* buf, int a, int b, int c);
extern "C" int func_020ac864(int flag);
extern "C" int func_020ab9c0(int flag);
extern "C" int func_020abca8();
struct Struct_02011544;
extern "C" void func_02011544(Struct_02011544*);
struct StateBits5ccc_11570;
extern "C" int GameState_IsErrorScreenRequested(StateBits5ccc_11570*);
extern "C" void* func_0208e9e8();
extern "C" void func_0208ea10(void* p, int a);
unsigned long long GetCurrentTimestamp();
extern "C" int GameState_GetOwnPartyOrder(char*, void*);
extern "C" int func_020dcd40();
extern "C" void Party_ReformLine(void* self, int a, int b, int c, int d);
extern "C" void func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" void GameState_CreatePresetCharacters(void* gs);
extern "C" void func_02070378(char*);
extern "C" void GameState_SetStoryChapter(char*, int);
extern "C" void GameState_SetStoryPart(char*, int);
extern "C" void GameState_SetStoryStep(char*, int);
extern "C" void Scenario_SetFlag(void* p, unsigned char* arr, int bit, int set);
extern "C" void GameState_CreateNativeId(void* gs);
extern "C" int RandomIntBelow(int n);
extern "C" void func_02039768(GameObject* obj, void* dst);
extern "C" short GameState_GetLeaderIndex(GameState* gs);
extern "C" void func_020a2770(void* p, short v);
extern "C" int rand();
extern "C" void func_0201206c(void* gs, int v);
extern "C" void func_0206dfe8(void* p, int a, int b);
extern "C" void* func_02057924();
struct Struct_02057930;
extern "C" void func_02057930(Struct_02057930*);
extern "C" void func_02057978(Struct_02057930*);
extern "C" void* ZoneRecords_GetInstance();
#if defined(jpn)
extern "C" void ZoneRecords_Init(void* p, void* a);
#else
extern "C" void ZoneRecords_Init(void* p, void* a, void* b);
#endif
extern "C" void ZoneRecords_Reset(void* p);
extern "C" void* NumberPopups_GetInstance();
extern "C" void NumberPopups_Init(void* p);
struct Container0203a54c;
extern "C" void NumberPopups_UnloadSprites(Container0203a54c*);
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_02042c68(void* c);
extern "C" void MessageSystem_Stop(void* c);
extern "C" void func_02042b30(void* c, void* p);
extern "C" void func_ov017_0219b624(void* self);
extern "C" void func_ov017_0219ba0c(void* self, int a);
struct Foo0207df50;
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void VramState_Restore(char*);
extern "C" void func_020432c4(void* c);
extern "C" void VramState_Save(char*);
extern "C" void MapDisplay_Init(void* p);
extern "C" void* func_020936f8();
extern "C" void func_020938f0(void* p);
extern "C" void func_020939ac(void* p);
extern "C" void func_0206ebf4(char*);
extern "C" void* func_0207d78c();
struct Struct_0207d798;
extern "C" void func_0207d798(Struct_0207d798*);
extern "C" int Scenario_TestFlag(int p, unsigned char* arr, int bit);
extern "C" void func_ov017_0219bfb4(int a, int b);
extern "C" void FieldTask_InitEnterZone(unsigned char*, int);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
struct FieldTaskQueue;
extern "C" void FieldTaskQueue_Update(FieldTaskQueue*);
extern "C" void func_ov017_021baedc(void* p, int a);
extern "C" void func_ov017_021b2174(unsigned char*);
struct Struct_0206f81c_2;
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2*, char*);
extern "C" void func_ov017_021b2bd0(void* p, int a, int b);
extern "C" int GetMainBGAssignedVRAMSize();
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
extern "C" void OS_WaitVBlankIntr();
extern "C" void func_020c38d4();
struct S_02010124;
extern "C" void GameState_ResetTiming(S_02010124*);
extern "C" void func_020c3a0c(int ch);
struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void func_0206e424(void* p, int a);
extern "C" void func_ov017_021bdbf0(unsigned char*);
extern "C" void DebugConsole_Clear();
extern "C" void DebugConsole_Upload();
extern "C" void Main_UpdateLidAndInput();
int IsBrightnessTransitionActive(GameResources*);
extern "C" int FieldTaskQueue_IsEmpty(void**);
struct Vector3i;
struct Struct_020115d0;
extern "C" int func_020115d0(Struct_020115d0*);
extern "C" int func_020115e8(void* gs);
extern "C" void func_02011600(void* gs);
struct Struct_02071488;
extern "C" int func_02071574(unsigned int, Struct_02071488*);
extern "C" int func_02011610(void* gs);
extern "C" int func_02011628(void* gs);
extern "C" void func_02011634(void* gs);
extern "C" void func_020bc028(int a);
extern "C" void func_020d84e0();
extern "C" void LinkSession_Close(void* p);
extern "C" void func_02043368(void* c);
extern "C" void func_ov017_0218cbd4(void* self);
extern "C" void func_ov017_02191cc0(void* self);
extern "C" void func_ov017_02195a20(void* self);
extern "C" void func_020d9834(int flag);
extern "C" void func_0209c840(void* p);
extern "C" void SoundPlayer_PlayPending(void* p);
extern "C" void func_020bbd9c();
extern "C" void OamManager_FlushBuffers(void* oam);
extern "C" void func_0204359c(void* c, int a);
extern "C" void func_0203dd94(char*);
extern "C" void func_ov017_0219a188(void* self);
extern "C" void func_ov017_021a63cc(void* self);
extern "C" void func_020d86d0(int a, int b);
extern "C" void func_ov017_021a4358(int p);
struct Obj0203bdb0;
extern "C" void OamManager_UploadBuffers(Obj0203bdb0*);
extern "C" int* func_ov017_021a193c(int*);
extern "C" void func_020439b0(void* c, int a);
struct Struct_020579ec;
extern "C" void func_020579ec(Struct_020579ec**);
extern "C" void func_ov017_021a63d0(void* self);
extern "C" void func_ov017_0219a18c(void* self);
extern "C" void BgTransfers_UploadDirtyScreens(void* p);
extern "C" void MapDisplay_SetMapScroll(void* p);
struct Obj020275e4;
extern "C" void MapDisplay_ScrollMapName(Obj020275e4*);
struct ShortField0xb4_0205eac8;
extern "C" int func_0205eac8(ShortField0xb4_0205eac8*);
extern "C" void SePlayer_LoadArchive(void* p, int mode);
struct Actor0209c20c;
extern "C" void func_0209c20c(Actor0209c20c*);
struct Obj_0205e8ec;
extern "C" void func_0205e8ec(Obj_0205e8ec*);
extern "C" void FieldTaskQueue_EndAll(void* p);
struct Struct_0203cfb4;
extern "C" void func_0203cfb4(Struct_0203cfb4*);
extern "C" void func_ov017_021a316c(void* self);
extern "C" void func_02043000(char*);
extern "C" void func_ov017_02190238(void* self);
extern "C" void Zone3D_Unload(void* p, int a);
extern "C" void func_020998ac(int*);
extern "C" void func_0209cd24(Struct_0209cbb8*);
extern "C" void func_ov017_0219b938(void* self);
extern "C" void func_ov017_0219bc50(unsigned char*);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" void func_ov017_021a0790(char*);
extern "C" void func_ov017_021a0964(char*);
extern "C" void func_ov017_021a0ba8(char*);
extern "C" void func_ov017_021a0f40(char*);
extern "C" void func_ov017_021a1114(char*);
extern "C" void func_ov017_021a0d6c(char*);
extern "C" void func_ov017_021a0470(void* self);
extern "C" void func_0200fd58(GameState* gs);
extern "C" void func_020a1edc();
extern "C" void func_020a1de4();
extern "C" void func_020e5094();
extern "C" void func_ov004_0216e9cc();
extern "C" void func_ov004_0216f854();

struct Flags02109bf4 {
    char pad[0xc8];
    unsigned char flagsC8;
};

struct Struct_ov017_021d82e0_2 {
    unsigned char paused;
    char pad[3];
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

struct Request3f8 {
    unsigned short id;
    char pad2[5];
    unsigned char flag7;
    char pad8[8];
    int pos[3];
    unsigned short dir;
    char pad1e[2];
    int unknown_20_;
    int pad24;
    int unknown_28_;
};

struct Struct_ov017_0218b688_2 {
    char pad[0x49c];
    unsigned char active : 1;
};

struct Struct_ov017_0218b688_3 {
    char pad[0x24];
    unsigned char index;
    char unknown_25_[3];
    int count;
    int selected;
};

struct Struct_ov017_0218b688_4 {
    char* obj;
};

struct Struct_01ff91ac_17 {
    char data[0x48];
};

struct Struct_ov017_0218b688_5 {
    char pad0[0x28];
    unsigned char running;
    char unknown_29_[0x38 - 0x29];
    char data38[0xc4 - 0x38];
    SafeAllocator allocator;
    char dataD8[0x150 - 0xd8];
    char unknown_150_[0x27c - 0x150];
#if !defined(jpn)
    char data27c[0x2cc - 0x27c];
#endif
    char data2cc[0x87c - 0x2cc];
    char pairTables[0xf0c - 0x87c];
#if defined(jpn)
    char dataF0c[0x28f8 - 0xebc];
#else
    char dataF0c[0x2b08 - 0xf0c];
#endif
    int unknown_2b08_;
    char unknown_2b0c_[0x2b90 - 0x2b0c];
    Foo02048004 entries[0x12];
    char unknown_3520_[0x3634 - 0x3520];
    unsigned char colorA[0x12];
    unsigned char colorB[0x12];
    unsigned char unknown_3658_[0x12];
    char unknown_366a_[0x36d0 - 0x366a];
    char* timedBuffer;
    char unknown_36d4_[0x36fc - 0x36d4];
    void* nodeList;
    void* unknown_3700_;
    void* unknown_3704_;
    void* unknown_3708_;
    void* header70c;
    char unknown_3710_[0x371c - 0x3710];
    Struct_ov017_0218b688_3* cursor;
    char unknown_3720_[0x3734 - 0x3720];
    char* unknown_3734_;
    char unknown_3738_[0x373c - 0x3738];
    Struct_01ff91ac_17 slots[4];
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
#define IS_OBJ_FLAG2_SET(h) ((h)->obj != 0 ? ((*(int*)((h)->obj + Enum_ov017_0218b688_15820) & 2) ? 1 : 0) : 0)

// USA: func_ov017_0218b688
extern "C" ARM void func_ov017_0218b688(Struct_ov017_0218b688_5* self) {
    char combatCtrl[0x2c8];
    char var1[0x68];
    char var2[8];
    unsigned char ids[4];

    SafeAllocator::GetLiveCount();
    unsigned int* flagWord = GlobalFlags_GetInstance();
    FlagWord_SetBits(flagWord, 0x100);
    GameState* gs = GameState::GetInstance();
    int mode = func_0201201c(gs);
    unsigned char field = func_020115a8((FieldBlock63d6_115a8*)gs);
    if (mode != 5 && field != 4 && field != 8 && field != 0xc) {
        func_020daf9c(1, 0, 1, 0);
    }
    SetMainBrightness((GameResources*)self, -16, 0);
    SetSubBrightness((GameResources*)self, -16, 0);
    func_0200fb84((int*)gs, (int)self);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* bigStruct = Zone3D_GetInstance();
    Request3f8* request = (Request3f8*)GameState_GetZoneTransition(gs);
    loader->ClearQueue();
    GameState_LoadSkillTable((char*)gs);
    void* var11 = func_020a6084();
    func_020a6180(var11);
    func_020a6194(var11);
    void* regions3 = BgVram_GetInstance();
    BgVram_Clear((char*)regions3);
    void* oam = OamManager_GetInstance();
    OamManager_Init((char*)oam);
    void* var14 = func_0203cf4c();
    func_0203cf58((Struct_0203cf58*)var14);
    void* search = LinkSession_GetInstance();
    LinkSession_Reset(search);
    SetFlags00((GameResources*)self, 2);
    LinkMessageQueue_Reset(LinkMessageQueue_GetInstance());
    void* buffered = GameState_GetZoneTable(gs);
    ZoneTable_Clear((unsigned int*)buffered);
    for (int i = 0; i < 4; i++) {
        func_ov017_021b2f64((unsigned char*)&self->slots[i]);
    }
    LootableContainerManager::GetMainInstance()->Reset();
    func_0208e4bc((char*)LootPointList_GetInstance());
    func_020e3004((Struct_020e3004*)func_020e2ff8());
    func_020e3814((Struct_020e3814*)func_020e3808());
    func_020e358c((Struct_020e358c*)func_020e3580());
    char* bits = Scenario_GetInstance();
    char* var19 = func_02094d6c();
    if (func_020115a8((FieldBlock63d6_115a8*)gs) == 0) {
        if (func_0201201c(gs) == 5 || func_0200fb9c((char*)gs) == 4) {
            func_0205facc(bits);
            func_02095518((char*)var19);
            func_020ac0dc();
        }
        func_02096524(var19);
    }
    *(int*)(bits + 0x480) = 0;
    *(int*)(bits + 0x47c) = 0;
    func_02070508((Struct_02108d5c*)func_020704fc());
    func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
    func_0205e944(&g_sePlayer, 0x7f);
    g_bgmPlayer.flagsC8 &= ~4;
    func_020d7a5c((ResetObj020d7a5c*)TextQueue_GetInstance());
    if (func_0201201c(gs) == 5 && func_0200fb9c((char*)gs) != 9) {
        func_0200fb94((char*)gs, 6);
    }

    LockStagedTextureVRAMCopying();
    DisableTextureImageVRAMBanks();
    DisableTexturePaletteVRAMBanks();
    DisableMainBGVRAMBanks();
    DisableSubBGVRAMBanks();
    DisableMainObjVRAMBanks();
    DisableSubObjVRAMBanks();
    func_ov017_0218d274(self);
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
    var21[0] = (var21[0] & ~3) | 1;
    var21[1] = (var21[1] & ~3) | 2;
    var21[2] = (var21[2] & ~3);
    DebugConsole_Init();
    GlyphMetrics_SetDisplayMode(3);
    func_020bb48c(4, 1);
    func_020bb780((void*)0x4000, 1);

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
    ActionDataTables* var23 = func_020797dc();
    func_02079870((char*)var23);
    func_02079900(var23, (SafeAllocator*)self->unknown_150_);
    func_020998c4((Struct_020995c0*)buffered);
    void* var24 = func_0209cb68();
    func_0209cbb8((Struct_0209cbb8*)var24);
    func_0209cbcc(var24);
    func_02099f6c((char*)func_02099f60());
    SprSprite_Init(&self->entries[11]);
    int var25 = 0;
#if !defined(jpn)
    func_020e5058();
    void* slotBuf = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x1866);
    if (slotBuf != 0) {
        func_020e50ec(slotBuf, 0x1866);
    }
    func_020e5114();
#endif
    if (func_0200fb9c((char*)gs) == 9) {
        var25 = 1;
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x30000), 0x30000);
        VramState_Reserve(self->dataF0c, 0x10, 0x10);
    }
    Zone3D_Init(bigStruct, (int)self->data38, (int)self->data2cc);
    Camera_Init(combatCtrl);
    func_020a2cf0((Struct_0204a120_2*)combatCtrl);
    func_020a2010(combatCtrl);
    GameState_SetCamera(gs, (int)combatCtrl);
    func_02046958((Struct_02046958*)self->nodeList);
    func_02046958((Struct_02046958*)self->unknown_3700_);
    func_02046958((Struct_02046958*)self->unknown_3704_);
    func_ov017_021a124c(self->unknown_3708_);
    int loaded;
    int ok;
    int var29 = 0;
    Struct_ov017_0218b688_3* cursor = self->cursor;
    cursor->index = var29;
    cursor->count = var29;
    cursor->selected = var29 - 1;
    loaded = var29;
    int var31 = var29;
    int var32 = var29;

    if (func_0200fb9c((char*)gs) != 6 && func_0200fb9c((char*)gs) != 9) {
        if (func_020115a8((FieldBlock63d6_115a8*)gs) != 0) {
            loaded = 1;
        } else {
            if (func_0200fb9c((char*)gs) == 0 || func_0200fb9c((char*)gs) == 5) {
                int var33 = func_0200fb9c((char*)gs) == 5;
                loaded = var29 = 1;
                var31 = !var33;
                if (func_0201201c(gs) == 6) {
                    ok = 0;
                    if (func_020aaf84(var2, 0, var33, 0) != 0) {
                        if (func_020ac864(var31 == 0) != 0) {
                            ok = 1;
                            if (var33 != 0 && func_020ab9c0(0) == 0 &&
                                func_020abca8() == 0) {
                                func_02011544((Struct_02011544*)gs);
                                ok = 0;
                            }
                        } else {
                            func_02011544((Struct_02011544*)gs);
                        }
                    }
                    if (ok == 0) {
                        var29 = 0;
                        loaded = var29;
                        var31 = var29;
                    }
                }
            }
            if (func_0200fb9c((char*)gs) != 5) {
                func_0208ea10(func_0208e9e8(), 1);
            }
            gs->mainTimestamp_ = GetCurrentTimestamp();
            gs->altTimestamp_ = GetCurrentTimestamp();
        }

        if (loaded != 0) {
            char* save = (char*)GameState_GetParty(gs);
            int count = GameState_GetOwnPartyOrder((char*)gs, ids);
            unsigned char* id;
            if (func_020115a8((FieldBlock63d6_115a8*)gs) != 0) {
                id = ids;
            } else {
                id = (unsigned char*)(save + 0xf78);
                count = *(unsigned char*)(save + 0xf7c);
            }
            for (int i = 0; i < count; i++, id++) {
                int cur = *id;
                if (cur == GameState_GetProtagonistIndex(gs)) {
                    func_ov017_0218f064(self, cur, 0x200, 1, 0);
                } else {
                    if (func_02011ff0(gs, cur) > 0) {
                        func_ov017_0218f064(self, cur, 4, 1, func_02011ff0(gs, cur));
                    } else {
                        func_ov017_0218f064(self, cur, 0x1000, 1, 0);
                    }
                    void* combatant = func_0200ff58(gs, cur);
                    if (combatant != 0) {
                        func_020546a0(combatant, GameState_GetProtagonistIndex(gs));
                    }
                }
                char* member = (char*)func_0200ff1c(gs, cur);
                if (member != 0) {
                    char* info = func_02053c6c((unsigned char*)member);
                    if (info != 0 && (*(int*)(info + 0x18) & 1)) {
                        *(int*)(member + Enum_ov017_0218b688_396) |= 1;
                    }
                }
            }
            if (func_020dcd40() != 0) {
                Party_ReformLine(self, 1, 1, 1, 1);
            }
        } else {
            func_ov017_0218f064(self, 0, 0x200, 1, 0);
            if (var29 == 0) {
                func_020897b4(0, 1, 6, 1, 1, 0, 0, 0, 0);
                GameState_CreatePresetCharacters(gs);
                g_keyManager.RefreshKeys();
                if (func_0200fb9c((char*)gs) == 0) {
                    func_02070378((char*)request);
                    request->id = 100;
                    GameState_SetStoryChapter((char*)gs, 3);
                    GameState_SetStoryPart((char*)gs, 1);
                    GameState_SetStoryStep((char*)gs, 1);
                    Scenario_SetFlag(bits, (unsigned char*)(bits + 0x8c), 0xaed, 1);
                    GameState_CreateNativeId(gs);
                    GameObject* hero = gs->GetProtagonist();
                    if (hero != 0) {
                        Struct_ov017_0218b688_2* party = (Struct_ov017_0218b688_2*)func_02053c6c((unsigned char*)hero);
                        if (party != 0) {
                            if (g_keyManager.TestKeysHeld(0x100)) {
                                party->active = 0;
                            } else if (g_keyManager.TestKeysHeld(0x200)) {
                                party->active = 1;
                            } else {
                                party->active = (unsigned char)RandomIntBelow(2);
                            }
                        }
                    }
                } else if (func_0200fb9c((char*)gs) == 2) {
                    func_02070378((char*)request);
                    request->id = 0x1905;
                    request->unknown_20_ = 0x53fc;
                    GameState_SetStoryChapter((char*)gs, 1);
                    GameState_SetStoryPart((char*)gs, 1);
                    GameState_SetStoryStep((char*)gs, 1);
                    GameState_CreateNativeId(gs);
                    char* member = (char*)func_0200ff1c(gs, 0);
                    if (member != 0) {
                        char* info = func_02053c6c((unsigned char*)member);
                        if (info != 0) {
                            *(unsigned short*)(info + 0x496) = 0x4e24;
                        }
                    }
                    var32 = 1;
                } else {
                    func_02070378((char*)request);
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
            if (var29 != 0) {
                char* save = (char*)GameState_GetParty(gs);
                GameObject* hero = gs->GetProtagonist();
                if (hero != 0) {
                    func_02039768(hero, save + 0x2c8d);
                }
            }
        }
        Party_ReformLine(self, 1, 1, 1, 1);
    }

    func_020a2770(combatCtrl, GameState_GetLeaderIndex(gs));
    if (func_020115a8((FieldBlock63d6_115a8*)gs) == 0) {
        func_0201206c(gs, rand());
        if (func_0200fb9c((char*)gs) != 5) {
            func_0206dfe8(bits, 0x79e, 0x2bc);
        }
    }
    void* var48 = func_02057924();
    func_02057930((Struct_02057930*)var48);
    void* entryTable = ZoneRecords_GetInstance();
#if defined(jpn)
    ZoneRecords_Init(entryTable, self->dataD8);
#else
    ZoneRecords_Init(entryTable, self->dataD8, self->data27c);
#endif
    void* battleArrays = NumberPopups_GetInstance();
    NumberPopups_Init(battleArrays);
    void* controller = MessageSystem_GetInstance();
    func_02042c68(controller);
    MessageSystem_Stop(controller);
    func_02042b30(controller, self->pairTables);
    func_ov017_0219b624(self);
    func_ov017_0219ba0c(self, 0);
    VramState_Rewind((Foo0207df50*)self->pairTables);
    VramState_Restore((char*)self->pairTables);
    func_020432c4(controller);
    VramState_Save((char*)self->pairTables);
    if (func_0200fb9c((char*)gs) != 6 && func_0200fb9c((char*)gs) != 9) {
        self->colorA[0] = 0xd4;
        self->colorB[0] = 8;
        self->unknown_3658_[0] = 0;
        self->colorA[1] = 0xc0;
        self->colorB[1] = 8;
        self->unknown_3658_[1] = 0;
    }
    MapDisplay_Init(self->timedBuffer);
    *(int*)(self->timedBuffer + 0x5a4) |= 1;
    void* handle = func_020936f8();
    func_020938f0(handle);
    func_0206ebf4((char*)self->unknown_44c4_);
    void* var53 = func_0207d78c();
    func_0207d798((Struct_0207d798*)var53);
    char* lighting = (char*)LightingManager::GetInstance();
    *(float*)(lighting + 0x94) = gs->GetDayTimer();
    *(int*)(lighting + 0x98) = gs->GetTimeOfDay();
    if (func_0200fb9c((char*)gs) != 6 && func_0200fb9c((char*)gs) != 9) {
        char* flagBits = Scenario_GetInstance();
        if (Scenario_TestFlag((int)flagBits, (unsigned char*)(flagBits + 0x8c), 0x1142) != 0) {
            var31 = 0;
        }
        if (var31 == 1) {
            func_ov017_0219bfb4(1, 0);
        } else {
            FieldTask_InitEnterZone((unsigned char*)self->header70c, 0);
            func_020469b4((TailList020469b4*)self->nodeList, (TailNode020469b4*)self->header70c);
            FieldTaskQueue_Update((FieldTaskQueue*)self->nodeList);
            if (Scenario_TestFlag((int)flagBits, (unsigned char*)(flagBits + 0x8c), 0x1142) != 0) {
                func_ov017_021baedc(self->unknown_3734_, 1);
                *(unsigned short*)(self->unknown_3734_ + 8) = 0x730a;
                func_020469b4((TailList020469b4*)self->nodeList, (TailNode020469b4*)self->unknown_3734_);
            }
        }
    }
    if (func_0200fb9c((char*)gs) == 6 || func_0200fb9c((char*)gs) == 9) {
        void* node = self->unknown_3b4c_;
        func_ov017_021b2174((unsigned char*)node);
        if (func_0200fb9c((char*)gs) == 6) {
            func_ov017_021b2ba0((Struct_0206f81c_2*)node, (char*)&data_ov017_021d736c);
            func_ov017_021b2bd0(node, (int)func_ov004_0216e9cc, OVERLAY_ID(4));
        } else if (func_0200fb9c((char*)gs) == 9) {
            func_ov017_021b2ba0((Struct_0206f81c_2*)node, (char*)&data_ov017_021d7378);
            func_ov017_021b2bd0(node, (int)func_ov004_0216f854, OVERLAY_ID(4));
        }
        func_020469b4((TailList020469b4*)self->nodeList, (TailNode020469b4*)node);
    }
    MIi_CpuClearFast(0, (void*)0x6000000, GetMainBGAssignedVRAMSize());
    OS_WaitVBlankIntr();
    func_020c38d4();
    *(volatile unsigned int*)0x4001000 |= 0x10000;
    GameState_ResetTiming((S_02010124*)gs);
    func_020c3a0c(0);
    unsigned long long last = GetCurrentTimestamp();
    void* list = self->unknown_3700_;
    while (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)list) == 0x13) {
        loader->RemoveAllLocks();
        FieldTaskQueue_Update((FieldTaskQueue*)list);
    }
    func_0206e424(bits, 0);
    if (var32 != 0) {
        func_ov017_021bdbf0((unsigned char*)self->unknown_3b60_);
        self->unknown_3b60_[0x11] = 2;
        func_020469b4((TailList020469b4*)self->nodeList, (TailNode020469b4*)self->unknown_3b60_);
    }
    if (func_020115a8((FieldBlock63d6_115a8*)gs) != 0) {
        GameState_ClearMovieId((FieldBlock63d6_115c0*)gs);
    }
    FontBankLoader* global400 = FontBankLoader_GetInstance();
    DebugConsole_Clear();
    DebugConsole_Upload();

    for (;;) {
        int var60 = 0;
        if (TestFlags00((GameResources*)self, 0x4000) != 0) {
            var60 = 1;
        }
        Main_UpdateLidAndInput();
        GameState::GetInstance();
        Scenario_GetInstance();
        func_02094b4c(global400);
        int var61 = 0;
        if (self->unknown_4324_ == 1) {
            self->unknown_4324_ = 0;
            var61 = 1;
        }
        if (GameState_IsErrorScreenRequested((StateBits5ccc_11570*)gs) != 0) {
            if (IsBrightnessTransitionActive((GameResources*)self) == 0) {
                var61 = 1;
            }
        }
        if (func_020115a8((FieldBlock63d6_115a8*)gs) != 0 && FieldTaskQueue_IsEmpty((void**)self->nodeList) != 0) {
            var61 = 1;
            func_02070378((char*)request);
            request->id = *(unsigned short*)bigStruct;
            request->flag7 = var61;
            GameObject* obj = gs->GetLeader();
            if (obj != 0) {
                *(Vector3i*)request->pos = *(Vector3i const*)((char*)obj + 0x44);
                request->dir = obj->obj3D_.rotation_.y;
            }
            if (func_020115d0((Struct_020115d0*)gs) != 0) {
                request->unknown_20_ = func_020115e8(gs);
                func_02011600(gs);
                if (func_02071574((unsigned short)request->unknown_20_, (Struct_02071488*)var1) != 0) {
                    request->id = *(unsigned short*)(var1 + 0xe);
                    request->flag7 = 0;
                }
            }
            if (func_02011610(gs) != 0) {
                request->unknown_28_ = func_02011628(gs);
                func_02011634(gs);
            }
        }
        if (var61 != 0) {
            if (func_0200fb9c((char*)gs) != 2) {
                func_020bc028(0);
            }
            func_020d84e0();
            LinkSession_Close(search);
            SetMainBrightness((GameResources*)self, -16, 0);
            SetSubBrightness((GameResources*)self, -16, 0);
            if (func_0200fb9c((char*)gs) == 8) {
                SetMainBrightness((GameResources*)self, 16, 0);
                SetSubBrightness((GameResources*)self, 16, 0);
            }
            break;
        }
        func_02043368(controller);
        func_ov017_0218cbd4(self);
        func_ov017_02191cc0(self);
        if (data_ov017_021d82e0.paused == 0 && TestFlags04((GameResources*)self, 1) == 0) {
            func_ov017_02195a20(self);
        }
        if (var60 != 0) {
            func_020d9834(1);
        }
        func_0209c840(&g_bgmPlayer);
        SoundPlayer_PlayPending(&g_sePlayer);
        func_020bbd9c();
        OamManager_FlushBuffers(oam);
        func_0204359c(controller, Enum_ov017_0218b688_24);
        if (var60 != 0) {
            func_020d9834(1);
        } else {
            func_020d9834(0);
        }
        loader->RemoveAllLocks();
        func_0203dd94((char*)var14);
        func_ov017_0219a188(self);
        func_ov017_021a63cc(self);
        if (data_ov017_021d82e0.paused == 0) {
            int speed = gs->currentNumTicks_;
            for (int f = 1; f < 2 - speed; f++) {
                OS_WaitVBlankIntr();
            }
            func_020d86d0(1, 0);
            self->running = 1;
            OS_WaitVBlankIntr();
        }
        if (data_ov017_021d82e0.paused != 0) {
            gs->CalculateDeltaTime(0);
        } else {
            unsigned long long now = GetCurrentTimestamp();
            gs->CalculateDeltaTime(((now - last) * 64000) / 33514);
        }
        last = GetCurrentTimestamp();
        data_02114e50++;
        func_ov017_021a4358((int)self->nodeList);
        OamManager_UploadBuffers((Obj0203bdb0*)oam);
        int var66 = 1;
        if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->nodeList) == 2) {
            Struct_ov017_0218b688_4* holder = (Struct_ov017_0218b688_4*)func_ov017_021a193c((int*)self->unknown_3708_);
            if (holder != 0 && IS_OBJ_FLAG2_SET(holder)) {
                var66 = 0;
            }
        }
        func_020439b0(controller, var66);
        func_020579ec((Struct_020579ec**)var48);
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
    if (func_0200fb9c((char*)gs) != 2) {
        if (func_0205eac8((ShortField0xb4_0205eac8*)&g_sePlayer) != 100) {
            SePlayer_LoadArchive(&g_sePlayer, 100);
        }
        func_0209c20c((Actor0209c20c*)&g_bgmPlayer);
        func_0205e8ec((Obj_0205e8ec*)&g_sePlayer);
        func_020bbd9c();
    }
    g_bgmPlayer.flagsC8 &= ~4;
    FieldTaskQueue_EndAll(self->nodeList);
    func_0203cfb4((Struct_0203cfb4*)var14);
    func_ov017_021a316c(self);
    for (int i = 0; i < 0x12; i++) {
        SprSprite_Unload(&self->entries[i]);
    }
    func_020798b8((char*)var23);
    func_02043000((char*)controller);
    func_020939ac(handle);
    NumberPopups_UnloadSprites((Container0203a54c*)battleArrays);
    func_02057978((Struct_02057930*)var48);
    ZoneRecords_Reset(entryTable);
    func_ov017_02190238(self);
    Zone3D_Unload(bigStruct, 1);
    func_020998ac((int*)buffered);
    func_0209cd24((Struct_0209cbb8*)var24);
    func_0207d798((Struct_0207d798*)var53);
    func_ov017_0219b938(self);
    func_ov017_0219bc50((unsigned char*)self);
    if (func_0200fb9c((char*)gs) == 9 && var25 == 1) {
        void* signedAlloc = self->allocator.GetSignedAllocator();
        if (signedAlloc != 0) {
            self->allocator.Destroy();
            AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, signedAlloc);
        }
        func_0200fb94((char*)gs, 6);
        func_02012010(gs, 2);
    }
    int var70 = self->unknown_2b08_;
    if (var70 == 0) {
        func_ov017_021a0790((char*)self);
    } else if (var70 == 1) {
        func_ov017_021a0964((char*)self);
    } else if (var70 == 2) {
        func_ov017_021a0ba8((char*)self);
    } else if (var70 == 3) {
        func_ov017_021a0f40((char*)self);
    } else if (var70 == 4) {
        func_ov017_021a1114((char*)self);
    } else if (var70 == 5) {
        func_ov017_021a0d6c((char*)self);
    }
    func_ov017_021a0470(self);
    func_0200fd58(gs);
    func_020a1edc();
    func_020a1de4();
    *(volatile unsigned int*)0x4000000 &= ~0xe000;
    data_ov017_021d82e0.unknown_4_ = 0;
#if !defined(jpn)
    func_020e5094();
#endif
    SafeAllocator::GetLiveCount();
    func_0200fb84((int*)gs, 0);
    func_020a2010(combatCtrl);
    func_020a2cf0((Struct_0204a120_2*)combatCtrl);
    Camera_Init(combatCtrl);
}
