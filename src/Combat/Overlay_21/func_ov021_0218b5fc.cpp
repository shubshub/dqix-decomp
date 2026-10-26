#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "NitroSDK/Graphics.h"

static inline unsigned long inline_ov021_0218b5fc_2(volatile unsigned int* p) { return *p; }
static inline void inline_ov021_0218b5fc(volatile unsigned int* p, unsigned int value) { *p = value; }

#if defined(jpn)
enum { Enum_ov021_0218b5fc_1288 = 0x608, Enum_ov021_0218b5fc_7720 = 0x1c4c, kSceneAllocatorSize = 0x48e10, Enum_ov021_0218b5fc_3512 = 0xd90, Enum_ov021_0218b5fc_3464 = 0xd4c };
#else
enum { Enum_ov021_0218b5fc_1288 = 0x508, Enum_ov021_0218b5fc_7720 = 0x1e28, kSceneAllocatorSize = 0x4b238, Enum_ov021_0218b5fc_3512 = 0xdb8, Enum_ov021_0218b5fc_3464 = 0xd88 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

#if defined(jpn)
#define func_020c51dc func_020c6ca8
#endif


struct AllocatorUnion;
struct Foo0207df50;
struct S_02010124;
struct Obj0203bdb0;
struct GameResources;
struct Actor0209c3b4;
struct Actor0209c678;
struct Actor0209c20c;

extern "C" void func_020a1df8(int value);
extern "C" void func_020a1e54(int value);
extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_0200fb84(int* obj, int value);
extern "C" void GXx_SetMasterBrightness_(short* reg, int value);
extern "C" void* OamManager_GetInstance(void);
extern "C" void OamManager_Init(char* context);
extern "C" int* CachedTextTable_GetInstance();
extern "C" int OamManager_GetSubOamBuffer(void* context);
extern "C" void CachedTextTable_LoadPalettes(int* ptr);
extern "C" void MapVRAMBanksToLCDC(unsigned short mask);
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
extern "C" int DisableLCDCMappedVRAMBanks(void);
void Finish3DRendering();
extern "C" void func_020c51dc();
extern "C" void func_020c537c();
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
void UpdateVRAMStagingVRAMBanks();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void func_020bb48c(unsigned int a, int b);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void func_020bb780(void* arg0, int flag);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void GX_SetGraphicsMode(int mode, int a, int b);
extern "C" void GXS_SetGraphicsMode(unsigned int mode);
extern "C" void Set3DClearColor(int a, int b, int c, int d, int e);
extern "C" void G3X_SetEdgeColorTable(int table);
extern "C" void VramState_Reserve(void* p, int a, int b);
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_02042c68(void* controller);
extern "C" void MessageSystem_Stop(void* obj);
extern "C" void func_020440a4(void* controller);
extern "C" void VramState_Rewind(Foo0207df50* obj);
extern "C" void VramState_Restore(char* obj);
extern "C" void func_020432c4(void* controller);
extern "C" void VramState_Save(char* obj);
extern "C" void GameState_SetProtagonistIndex(GameState* gs, int value);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void CharacterCreationUI_Init(void* scene, int a, int b);
extern "C" void* GameState_FindFreePartyMemberData(char* gs);
extern "C" void CharacterCreationUI_Allocate(void* scene, SafeAllocator* allocator);
extern "C" void func_0209c3b4(Actor0209c3b4* actor, int state);
extern "C" void OS_WaitVBlankIntr();
extern "C" void func_020c38d4();
extern "C" void GameState_ResetTiming(S_02010124* obj);
extern "C" int func_0200fb9c(char* gs);
extern "C" void Main_UpdateLidAndInput();
extern "C" void func_ov021_0218bb30(void* self);
extern "C" void func_020bbcb4();
extern "C" void CharacterCreationUI_UpdateVBlank(void* scene);
extern "C" void OamManager_UploadBuffers(Obj0203bdb0* obj);
void UpdateAndApplyBrightness(GameResources* resources);
extern "C" void CharacterCreationUI_Destroy(void* scene);
extern "C" void BgmPlayer_FadeOut(Actor0209c678* actor, int state);
extern "C" void SoundPlayer_StopStream(void* a, void* b, int c);
extern "C" void SoundPlayer_PlayPending(void* obj);
extern "C" void func_0209c20c(Actor0209c20c* actor);
extern "C" void func_02043000(char* controller);
extern char g_mainAllocator;
extern char g_bgmPlayer;
extern int data_02114e50;

struct Struct_ov021_0218bbc4 {
    unsigned short colors[8];
};

extern Struct_ov021_0218bbc4 data_ov021_0218bbc4;

struct Struct_ov021_0218b5fc {
    char pad0[0x28];
    unsigned char running;
    char pad1[0x2c - 0x29];
    SafeAllocator allocator;
    void* scene;
    char state44[0xb4 - 0x44];
    char* slot;
    int unknown_b8_;
};

struct Struct_ov021_0218b5fc_2;
extern "C" void func_ov021_0218baf8(Struct_ov021_0218b5fc_2* obj);

// USA: func_ov021_0218b5fc
extern "C" ARM void func_ov021_0218b5fc(Struct_ov021_0218b5fc* self) {
#if !defined(jpn)
    func_020a1df8(3);
#endif
    Overlay_Load(OVERLAY_ID(9));
    Overlay_Load(OVERLAY_ID(23));
    GameState* gs = GameState::GetInstance();
    func_0200fb84((int*)gs, (int)self);
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    BackgroundLoader::GetInstance()->ClearQueue();
    void* context = OamManager_GetInstance();
    OamManager_Init((char*)context);
    *(int*)context = 0;
    int* global = CachedTextTable_GetInstance();
    *global = OamManager_GetSubOamBuffer(context) + 0x200;
    CachedTextTable_LoadPalettes(global);
    global[Enum_ov021_0218b5fc_1288 / 4] = 0x7000;
    MapVRAMBanksToLCDC(0x1ff);
    MIi_CpuClearFast(0, (void*)0x6800000, 0xa4000);
    DisableLCDCMappedVRAMBanks();
    Finish3DRendering();
    func_020c51dc();
    func_020c537c();
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(1);
    func_020bb48c(1, 1);
    MapVRAMBanksToTexturePalette(0x40);
    func_020bb780((void*)0x4000, 1);
    MapVRAMBanksToMainBG(0x10);
    MapVRAMBanksToSubBG(4);
    MapVRAMBanksToMainObj(0x20);
    unsigned int display = inline_ov021_0218b5fc_2(&DISPCNT);
#if defined(jpn)
    display = (display & 0xffcfffef) | 0x10;
#else
    display &= 0xffcfffef;
    display |= 0x10;
#endif
    inline_ov021_0218b5fc(&DISPCNT, display);
    MapVRAMBanksToSubObj(8);
    DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    display = inline_ov021_0218b5fc_2(&DISPCNT);
    display = (display & ~0x1f00) | 0x1f00;
    inline_ov021_0218b5fc(&DISPCNT, display);
    GX_SetGraphicsMode(1, 0, 1);

    BG1CNT = (BG1CNT & 0x43) | 0x1d00;
    BG2CNT = (BG2CNT & 0x43) | 0x1e08;
    BG3CNT = (BG3CNT & 0x43) | 0x1f0c;
    BG0CNT = (BG0CNT & ~3) | 2;
    BG1CNT = (BG1CNT & ~3) | 3;
    BG2CNT = (BG2CNT & ~3) | 1;
    BG3CNT = BG3CNT & ~3;
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
    GXS_SetGraphicsMode(0);

    BG0CNTSUB = (BG0CNTSUB & 0x43) | 0x1d00;
    BG1CNTSUB = (BG1CNTSUB & 0x43) | 0x1e10;
    BG2CNTSUB = (BG2CNTSUB & 0x43) | 0x1f18;
    BG0CNTSUB = (BG0CNTSUB & ~3) | 2;
    BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
    BG2CNTSUB = BG2CNTSUB & ~3;
    BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
    *(unsigned short*)0x4000304 |= 0x8000;
    Set3DClearColor(0, 0, 0x7fff, 0, 0);

    Struct_ov021_0218bbc4 edges = data_ov021_0218bbc4;
    G3X_SetEdgeColorTable((int)&edges);
    VramState_Reserve(self->state44, 0x4000, 0x40);
    void* controller = MessageSystem_GetInstance();
    func_02042c68(controller);
    MessageSystem_Stop(controller);
    func_020440a4(controller);
    *(char**)((char*)controller + Enum_ov021_0218b5fc_7720) = self->state44;
    VramState_Rewind((Foo0207df50*)self->state44);
    VramState_Restore(self->state44);
    func_020432c4(controller);
    VramState_Save(self->state44);
    GameState_SetProtagonistIndex(gs, 0);
    self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, kSceneAllocatorSize), kSceneAllocatorSize);
    self->allocator.Reset();
    self->scene = self->allocator.Allocate(Enum_ov021_0218b5fc_3512);
    CharacterCreationUI_Init(self->scene, 0, CreationMode_NewGame);
    self->slot = (char*)GameState_FindFreePartyMemberData((char*)gs);
    *(short*)(self->slot + 0x568) = GameState_GetProtagonistIndex(gs);
    *(char**)((char*)self->scene + Enum_ov021_0218b5fc_3464) = self->slot;
    CharacterCreationUI_Allocate(self->scene, &self->allocator);
    func_0209c3b4((Actor0209c3b4*)&g_bgmPlayer, 2);
    OS_WaitVBlankIntr();
    func_020c38d4();
    DISPCNTSUB |= 0x10000;
    GameState_ResetTiming((S_02010124*)gs);

    for (;;) {
        if (func_0200fb9c((char*)gs) == 0 || self->unknown_b8_ != 0) {
            break;
        }
        Main_UpdateLidAndInput();
        func_ov021_0218baf8((Struct_ov021_0218b5fc_2*)self);
        func_ov021_0218bb30(self);
        self->running = 1;
        OS_WaitVBlankIntr();
        func_020bbcb4();
        CharacterCreationUI_UpdateVBlank(self->scene);
        OamManager_UploadBuffers((Obj0203bdb0*)OamManager_GetInstance());
        UpdateAndApplyBrightness((GameResources*)self);
        data_02114e50++;
        gs->CalculateDeltaTime(0x411b);
    }

    CharacterCreationUI_Destroy(self->scene);
    BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
    SoundPlayer_StopStream(&g_bgmPlayer, 0, 0);
    SoundPlayer_PlayPending(&g_bgmPlayer);
    func_0209c20c((Actor0209c20c*)&g_bgmPlayer);
    func_02043000((char*)controller);
    VramState_Rewind((Foo0207df50*)self->state44);
    func_0200fb84((int*)gs, 0);
#if !defined(jpn)
    func_020a1e54(1);
#endif
}
