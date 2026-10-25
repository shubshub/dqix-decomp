#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "NitroSDK/Graphics.h"

static inline unsigned long inline_ov021_0218b5fc_2(volatile unsigned int* arg0) { return *arg0; }
static inline void inline_ov021_0218b5fc(volatile unsigned int* arg0, unsigned int arg1) { *arg0 = arg1; }

#if defined(jpn)
enum { Enum_ov021_0218b5fc_1288 = 0x608, Enum_ov021_0218b5fc_7720 = 0x1c4c, Enum_ov021_0218b5fc_307768 = 0x48e10, Enum_ov021_0218b5fc_3512 = 0xd90, Enum_ov021_0218b5fc_3464 = 0xd4c };
#else
enum { Enum_ov021_0218b5fc_1288 = 0x508, Enum_ov021_0218b5fc_7720 = 0x1e28, Enum_ov021_0218b5fc_307768 = 0x4b238, Enum_ov021_0218b5fc_3512 = 0xdb8, Enum_ov021_0218b5fc_3464 = 0xd88 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

#if defined(jpn)
#define func_020c51dc func_020c6ca8
#endif


struct AllocatorUnion;
struct Struct_0203d028;
struct Struct_0200f3a4_9;
struct Struct_0203bdb0;
struct GameResources;
struct Struct_0209c3b4_2;
struct Struct_02109bf4_4;
struct Struct_02109bf4_3;

void PushInputLogA_020a1df8(int value);
void PopStack0AndTrigger_020a1e54(int value);
extern "C" void func_020a1940(unsigned int id);
void SetWord0x0_0200fb84(int* obj, int value);
extern "C" void GXx_SetMasterBrightness_(short* reg, int value);
extern "C" void* func_0203bd08(void);
extern "C" void func_0203bd24(char* arg0);
extern "C" int* func_0203bd14();
extern "C" int func_0203be4c(void* arg0);
extern "C" void func_0203c35c(int* arg0);
extern "C" void MapVRAMBanksToLCDC(unsigned short mask);
extern "C" void func_020ca458(unsigned int value, void* dest, int count);
extern "C" int DisableLCDCMappedVRAMBanks(void);
void Finish3DRendering();
extern "C" void func_020c51dc();
extern "C" void func_020c537c();
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
void UpdateVRAMStagingVRAMBanks();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void func_020bb780(void* arg0, int arg1);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" void MapVRAMBanksToSubObj(int value);
void SetDispcntModeAndFlags020c391c(int mode, int a, int b);
void SetSubBgMode_020c3984(unsigned int mode);
void Set3DClearColor_020c5588(int a, int b, int c, int d, int e);
void G3X_SetEdgeColorTable(int table);
extern "C" void VramState_Reserve(void* p, int a, int b);
void* MessageSystem_GetInstance();
extern "C" void func_02042c68(void* controller);
extern "C" void MessageSystem_Stop(void* obj);
void TailForward020440a4(void* controller);
void VramState_Rewind(Foo0207df50* obj);
void VramState_Restore(char* obj);
extern "C" void func_020432c4(void* controller);
void VramState_Save(char* obj);
void SetField0x3acValue_020100a0(GameState* gs, int value);
int GameState_GetProtagonistIndex(GameState* gs);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void CharacterCreationUI_Init(void* scene, int a, int b);
void* FindSlotWithNegShort02010954(char* gs);
extern "C" void CharacterCreationUI_Allocate(void* scene, SafeAllocator* allocator);
void SetStateAndDispatch0209c3b4(Actor0209c3b4* actor, int state);
void DelayThenSyncBit0_020c9820();
void RestoreDisplayMode_020c38d4();
void InitFields02010124(S_02010124* obj);
int GetByte0x4_0200fb9c(char* gs);
void InitCombatSubsystems02012efc();
extern "C" void func_ov021_0218bb30(void* self);
void ProcessRingJobs020bbcb4();
extern "C" void CharacterCreationUI_UpdateVBlank(void* scene);
void SyncMainSubOam0203bdb0(Obj0203bdb0* obj);
void UpdateAndApplyBrightness(GameResources* resources);
extern "C" void CharacterCreationUI_Destroy(void* scene);
void BgmPlayer_FadeOut(Actor0209c678* actor, int state);
void ScaleAndNotify0203ad88(void* a, void* b, int c);
void ResetXYField0203aa08(void* obj);
void InitActorContext0209c20c(Actor0209c20c* actor);
void InitControllerObject_02043000(char* controller);
extern char g_mainAllocator;
extern char g_bgmPlayer;
extern int data_02114e50;

struct Struct_ov021_0218bbc4 {
    unsigned short unknown_0_[8];
};

extern Struct_ov021_0218bbc4 data_ov021_0218bbc4;

struct Struct_ov021_0218b5fc {
    char unknown_0_[0x28];
    unsigned char unknown_28_;
    char unknown_29_[0x2c - 0x29];
    SafeAllocator unknown_2c_;
    void* unknown_40_;
    char unknown_44_[0xb4 - 0x44];
    char* unknown_b4_;
    int unknown_b8_;
};

struct Struct_ov021_0218b5fc_2;
extern "C" void func_ov021_0218baf8(Struct_ov021_0218b5fc_2* arg0);

// USA: func_ov021_0218b5fc
extern "C" ARM void func_ov021_0218b5fc(Struct_ov021_0218b5fc* arg0) {
#if !defined(jpn)
    func_020a1df8(3);
#endif
    func_020a1940(OVERLAY_ID(9));
    func_020a1940(OVERLAY_ID(23));
    GameState* gs = GameState::GetInstance();
    SetWord0x0_0200fb84((int*)gs, (int)self);
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    BackgroundLoader::GetInstance()->MaybeReset();
    void* var1 = func_0203bd08();
    func_0203bd24((char*)var1);
    *(int*)var1 = 0;
    int* var2 = func_0203bd14();
    *var2 = func_0203be4c(var1) + 0x200;
    func_0203c35c(var2);
    var2[Enum_ov021_0218b5fc_1288 / 4] = 0x7000;
    MapVRAMBanksToLCDC(0x1ff);
    func_020ca458(0, (void*)0x6800000, 0xa4000);
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
    unsigned int var3 = inline_ov021_0218b5fc_2(&DISPCNT);
#if defined(jpn)
    var3 = (var3 & 0xffcfffef) | 0x10;
#else
    var3 &= 0xffcfffef;
    var3 |= 0x10;
#endif
    inline_ov021_0218b5fc(&DISPCNT, var3);
    MapVRAMBanksToSubObj(8);
    DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    var3 = inline_ov021_0218b5fc_2(&DISPCNT);
    var3 = (var3 & ~0x1f00) | 0x1f00;
    inline_ov021_0218b5fc(&DISPCNT, var3);
    func_020c391c(1, 0, 1);

    BG1CNT = (BG1CNT & 0x43) | 0x1d00;
    BG2CNT = (BG2CNT & 0x43) | 0x1e08;
    BG3CNT = (BG3CNT & 0x43) | 0x1f0c;
    BG0CNT = (BG0CNT & ~3) | 2;
    BG1CNT = (BG1CNT & ~3) | 3;
    BG2CNT = (BG2CNT & ~3) | 1;
    BG3CNT = BG3CNT & ~3;
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
    func_020c3984(0);

    BG0CNTSUB = (BG0CNTSUB & 0x43) | 0x1d00;
    BG1CNTSUB = (BG1CNTSUB & 0x43) | 0x1e10;
    BG2CNTSUB = (BG2CNTSUB & 0x43) | 0x1f18;
    BG0CNTSUB = (BG0CNTSUB & ~3) | 2;
    BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
    BG2CNTSUB = BG2CNTSUB & ~3;
    BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
    *(unsigned short*)0x4000304 |= 0x8000;
    func_020c5588(0, 0, 0x7fff, 0, 0);

    EdgeColors0218b5fc edges = data_ov021_0218bbc4;
    G3X_SetEdgeColorTable((int)&edges);
    VramState_Reserve(self->state44, 0x4000, 0x40);
    void* controller = MessageSystem_GetInstance();
    func_02042c68(controller);
    MessageSystem_Stop(controller);
    TailForward020440a4(controller);
    *(char**)((char*)controller + kControllerBackupOffset) = self->state44;
    VramState_Rewind((Foo0207df50*)self->state44);
    VramState_Restore(self->state44);
    func_020432c4(controller);
    VramState_Save(self->state44);
    SetField0x3acValue_020100a0(gs, 0);
    self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, kSceneAllocatorSize), kSceneAllocatorSize);
    self->allocator.Reset();
    self->scene = self->allocator.Allocate(kSceneSize);
    CharacterCreationUI_Init(self->scene, 0, CreationMode_NewGame);
    self->slot = (char*)FindSlotWithNegShort02010954((char*)gs);
    *(short*)(self->slot + 0x568) = GameState_GetProtagonistIndex(gs);
    *(char**)((char*)self->scene + kSceneSlotOffset) = self->slot;
    CharacterCreationUI_Allocate(self->scene, &self->allocator);
    SetStateAndDispatch0209c3b4((Actor0209c3b4*)&g_bgmPlayer, 2);
    DelayThenSyncBit0_020c9820();
    RestoreDisplayMode_020c38d4();
    DISPCNTSUB |= 0x10000;
    func_02010124((Struct_0200f3a4_9*)var0);

    for (;;) {
        if (func_0200fb9c((char*)var0) == 0 || arg0->unknown_b8_ != 0) {
            break;
        }
        InitCombatSubsystems02012efc();
        ReleaseLocksAndReset_0218baf8((Obj0218baf8*)self);
        func_ov021_0218bb30(self);
        self->running = 1;
        DelayThenSyncBit0_020c9820();
        ProcessRingJobs020bbcb4();
        CharacterCreationUI_UpdateVBlank(self->scene);
        SyncMainSubOam0203bdb0((Obj0203bdb0*)func_0203bd08());
        UpdateAndApplyBrightness((GameResources*)self);
        data_02114e50++;
        var0->CalculateDeltaTime(0x411b);
    }

    CharacterCreationUI_Destroy(self->scene);
    BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
    ScaleAndNotify0203ad88(&g_bgmPlayer, 0, 0);
    ResetXYField0203aa08(&g_bgmPlayer);
    InitActorContext0209c20c((Actor0209c20c*)&g_bgmPlayer);
    InitControllerObject_02043000((char*)controller);
    VramState_Rewind((Foo0207df50*)self->state44);
    SetWord0x0_0200fb84((int*)gs, 0);
#if !defined(jpn)
    func_020a1e54(1);
#endif
}
