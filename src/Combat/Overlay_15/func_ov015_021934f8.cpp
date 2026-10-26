#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/FontBankLoader.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/VRAM.h"
#include "Input/Input.h"

#if defined(jpn)
#define func_020c51dc func_020c6ca8
#endif



struct Struct_ov015_0218b810;
struct Struct_ov015_02192600_3;
struct Struct_0204a120_2;
struct Foo0207df50;
struct S_02010124;
struct Obj0203bdb0;

struct Struct_ov015_021934f8 {
    char data[0x2c8];
};

struct Controller021934f8 {
    char pad0[0x195a];
    unsigned char mode;
};

struct Struct_ov015_021934f8_3 {
    char pad0[0x3c];
    int config[4];
    int list[6];
    char unknown_64_[0x70 - 0x64];
    char unknown_70_[0x84 - 0x70];
    void* buffer;
    SafeAllocator partsAllocator;
    SafeAllocator monstersAllocator;
    SafeAllocator soundsAllocator;
    char unknown_c4_[0x124 - 0xc4];
    char tables[0x194 - 0x124];
    int phase;
    int unknown_198_;
    char unknown_19c_[0x1a4 - 0x19c];
    int unknown_1a4_;
    char unknown_1a8_[0x22c - 0x1a8];
    unsigned long long unknown_230_;
    unsigned long long unknown_238_;
    unsigned long long unknown_240_;
    unsigned long long unknown_248_;
    float unknown_250_;
    char unknown_254_[0x268 - 0x250];
    char scratch[0x52];
};

extern "C" void func_0200fb84(int*, int);
extern "C" void GXx_SetMasterBrightness_(short*, int);
extern "C" void* OamManager_GetInstance();
extern "C" void OamManager_Init(char*);
void LockStagedTextureVRAMCopying();
extern "C" void MIi_CpuClearFast(unsigned int, unsigned int, unsigned int);
extern "C" void GX_SetGraphicsMode(int, int, int);
extern "C" void GXS_SetGraphicsMode(unsigned int);
void UpdateVRAMStagingVRAMBanks();
void UnlockStagedTextureVRAMCopying();
void Finish3DRendering();
extern "C" void func_020c51dc();
extern "C" void func_020c537c();
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void GlyphBitmapContext_SetBuffer(void*);
extern "C" void GlyphMetrics_SetDisplayMode(int);
extern "C" void GlyphBitmapContext_SetUpLayer(int);
extern "C" void func_020bb48c(unsigned int, int);
extern "C" void func_020bb780(void*, int);
extern "C" void func_ov015_02192600(struct Struct_ov015_02192600_3*);
extern "C" void Set3DClearColor(int, int, int, int, int);
extern "C" void func_ov015_0218b810(struct Struct_ov015_0218b810*);
extern "C" void func_ov015_0218ba44(void*, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void ItemTable_Init(void*);
extern "C" void* ExtractFileFromGP2(const char*, const char*, unsigned int*);
extern "C" void func_020dea64(void*, SafeAllocator*, void*, unsigned int, const void*, int);
extern "C" void func_0206efc4(void*);
extern "C" void func_0206efd8(void*, void*);
extern "C" void func_020709d8(void*);
extern "C" void func_020709ec(void*, void*);
extern "C" void Camera_Init(void*);
extern "C" void func_020a2cf0(struct Struct_0204a120_2*);
extern "C" void func_020a2010(void*);
extern "C" void FollowCamera_DisableFollow(void*);
extern "C" void GameState_SetCamera(GameState*, int);
extern "C" void func_ov015_02192544(void*);
extern "C" void SePlayer_LoadArchive(void*, int);
extern "C" void OS_WaitVBlankIntr();
extern "C" void func_020c38d4();
extern "C" void GameState_ResetTiming(S_02010124*);
extern "C" void func_020c3a0c(int);
unsigned long long GetCurrentTimestamp();
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_02042b30(void*, void*);
extern "C" void VramState_Rewind(struct Foo0207df50*);
extern "C" void VramState_Restore(char*);
extern "C" void func_020432c4(void*);
extern "C" void VramState_Save(char*);
extern "C" void func_0204500c(void*, const void*, int, int);
extern "C" void func_0204359c(void*, int);
extern "C" void func_020439b0(void*, int);
extern "C" void func_ov015_02192700(void*);
extern "C" void func_02012de4(AllocatorUnion*);
extern "C" void Main_UpdateLidAndInput();
extern "C" void func_020bc028(int);
extern "C" void func_ov015_02190e88(void*);
extern "C" void func_ov015_02191294(void*);
extern "C" void func_ov015_02191668(void*);
extern "C" void func_ov015_02190d7c(void*);
extern "C" void func_ov015_021901c8(void*);
extern "C" void OamManager_FlushBuffers(void* oam);
extern "C" void SoundPlayer_PlayPending(void*);
extern "C" void func_020bbd9c();
extern "C" unsigned long long _ll_udiv(unsigned long long, unsigned long long);
extern "C" float func_0200c76c(unsigned long long);
extern "C" int GXx_GetMasterBrightness_(unsigned short volatile*);
extern "C" void OamManager_UploadBuffers(Obj0203bdb0*);
extern "C" void func_020290ac(int);

extern AllocatorUnion g_mainAllocator;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern int data_ov015_02193cdc[];
extern char g_sePlayer;
extern int data_ov015_02194528[];

#define POWCNT1 (*(volatile unsigned short*)0x04000304)
#define MASTER_BRIGHT ((short*)0x0400006c)
#define MASTER_BRIGHT_SUB ((short*)0x0400106c)
#define BG0HOFS_SUB (*(volatile int*)0x04001010)

// USA: func_ov015_021934f8
extern "C" ARM void func_ov015_021934f8(Struct_ov015_021934f8_3* self)
{
    GameState* gs = GameState::GetInstance();
    if (gs == NULL)
        return;
    func_0200fb84((int*)gs, (int)self);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    loader->ClearQueue();
    FontBankLoader* global = FontBankLoader_GetInstance();
    func_02094b3c(global, 10);
    func_02094b3c(global, 12);
    func_02094b34(global, 0x69, 0, 0, 0);
    func_02094b38(global, 0x69);
    func_02094b38(global, 0);
    while (!func_02094b4c(global))
        loader->RemoveAllLocks();

    GXx_SetMasterBrightness_(MASTER_BRIGHT, -16);
    GXx_SetMasterBrightness_(MASTER_BRIGHT_SUB, -16);
    char* context = (char*)OamManager_GetInstance();
    OamManager_Init(context);
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToLCDC(0x1ff);
    MIi_CpuClearFast(0, 0x6800000, 0xa4000);
    DisableLCDCMappedVRAMBanks();
    ReleaseTextureImageVRAMBanks();
    MapVRAMBanksToTextureImage(0xb);
    ReleaseTexturePaletteVRAMBanks();
    MapVRAMBanksToTexturePalette(0x60);
    DISPCNT = DISPCNT & ~DISPCNT_MASK_CHARACTER_BASE_64K;
    DISPCNT = DISPCNT & ~DISPCNT_MASK_SCREEN_BASE_64K;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    GX_SetGraphicsMode(1, 0, 1);
    GXS_SetGraphicsMode(0);
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1100;
    ReleaseSubBGVRAMBanks();
    MapVRAMBanksToSubBG(4);
    ReleaseSubObjVRAMBanks();
    MapVRAMBanksToSubObj(0x100);
    DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    GXx_SetMasterBrightness_(MASTER_BRIGHT, 0);
    GXx_SetMasterBrightness_(MASTER_BRIGHT_SUB, 0);
    POWCNT1 &= ~0x8000;
    Finish3DRendering();
    func_020c51dc();
    func_020c537c();
    BG1CNT = BG1CNT & ~3;
    BG0CNT = (BG0CNT & ~3) | 1;
    BG0CNTSUB = BG0CNTSUB & ~3;
    BG0HOFS_SUB = 0;
    self->buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x6000);
    GlyphBitmapContext_SetBuffer(self->buffer);
    GlyphMetrics_SetDisplayMode(4);
    GlyphBitmapContext_SetUpLayer(1);
    func_020bb48c(3, 1);
    func_020bb780((void*)0x8000, 1);
    func_ov015_02192600((struct Struct_ov015_02192600_3*)self);
    Set3DClearColor(0x594a, 0x10, 0x7fff, 0, 0);
    func_ov015_0218b810((struct Struct_ov015_0218b810*)&self->config);
    func_ov015_0218ba44(&self->config, 0);
    memset(self->scratch, 0, 0x52);

    self->partsAllocator.ResetAllocatorPointer();
    self->partsAllocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x17600), 0x17600);
    self->partsAllocator.Reset();
    ItemTable_Init(self->list);
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* data;
    size = 0;
    data = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &size);
    if (data != NULL)
        func_020dea64(self->list, &self->partsAllocator, data, size, data_ov015_02193cdc, 9);
    BackgroundLoader::RemoveLockGlobal();

    self->monstersAllocator.ResetAllocatorPointer();
    self->monstersAllocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x20000), 0x20000);
    self->monstersAllocator.Reset();
    func_0206efc4(self->unknown_64_);
    func_0206efd8(self->unknown_64_, &self->monstersAllocator);

    self->soundsAllocator.ResetAllocatorPointer();
    self->soundsAllocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x20000), 0x20000);
    self->soundsAllocator.Reset();
    func_020709d8(self->unknown_70_);
    func_020709ec(self->unknown_70_, &self->soundsAllocator);

    Struct_ov015_021934f8 combat;
    Camera_Init(&combat);
    func_020a2cf0((struct Struct_0204a120_2*)&combat);
    func_020a2010(&combat);
    FollowCamera_DisableFollow(&combat);
    GameState_SetCamera(gs, (int)&combat);
    func_ov015_02192544(self);
    SePlayer_LoadArchive(&g_sePlayer, 0x65);
    OS_WaitVBlankIntr();
    func_020c38d4();
    DISPCNTSUB = DISPCNTSUB | 0x10000;
    GameState_ResetTiming((S_02010124*)gs);
    func_020c3a0c(0);
    GetCurrentTimestamp();
    Controller021934f8* controller = (Controller021934f8*)MessageSystem_GetInstance();
    func_02042b30(controller, self->tables);
    VramState_Rewind((struct Foo0207df50*)self->tables);
    VramState_Restore(self->tables);
    func_020432c4(controller);
    VramState_Save(self->tables);
    func_0204500c(controller, data_ov015_02194528, 0, 0xe3);
    controller->mode = 8;
    for (unsigned int i = 0; i < 0x10; i++)
    {
        func_0204359c(controller, 0x10);
        func_020439b0(controller, 0);
    }
    self->phase = 0;
    self->unknown_198_ = 2;
    self->unknown_1a4_ = 0;
    func_ov015_02192700(self);
    func_02012de4(&g_mainAllocator);
    unsigned long long last = GetCurrentTimestamp();

    for (;;)
    {
        Main_UpdateLidAndInput();
        int var10;
        if (g_keyManager.TestKeysHeld(4) && g_keyManager.TestKeysHeld(8))
            var10 = 1;
        else if (self->unknown_1a4_ == 0 && g_keyManager.TestKeysPressed(2))
            var10 = 1;
        else
            var10 = 0;
        if (var10)
        {
            func_020bc028(0);
            break;
        }
        if (g_keyManager.TestKeysPressed(8))
            func_ov015_02192544(self);
        switch (self->phase)
        {
        case 0:
            func_ov015_02190e88(self);
            break;
        case 1:
            func_ov015_02191294(self);
            break;
        case 2:
            func_ov015_02191668(self);
            break;
        }
        func_ov015_02190d7c(self);
        func_ov015_021901c8(self);
        OamManager_FlushBuffers(context);
        SoundPlayer_PlayPending(&g_sePlayer);
        func_020bbd9c();

        unsigned long long var11 = self->unknown_240_;
        self->unknown_240_ = _ll_udiv(GetCurrentTimestamp() * 64000, 33514);
        if (self->unknown_238_ < self->unknown_240_)
        {
            unsigned long long delta = self->unknown_240_ - self->unknown_238_;
            self->unknown_248_ = (delta + self->unknown_248_) >> 1;
        }
        if (var11 < self->unknown_240_)
        {
            self->unknown_230_ += _ll_udiv(self->unknown_240_ - var11, 1000);
            if (self->unknown_230_ > 1000)
            {
                self->unknown_230_ = 0;
                self->unknown_250_ = 1000000.0f / func_0200c76c(self->unknown_248_);
            }
        }
        loader->RemoveAllLocks();
        self->unknown_238_ = _ll_udiv(GetCurrentTimestamp() * 64000, 33514);
        if (GXx_GetMasterBrightness_((unsigned short volatile*)MASTER_BRIGHT) > -16)
            OS_WaitVBlankIntr();
        GetCurrentTimestamp();
        OamManager_UploadBuffers((Obj0203bdb0*)context);
        func_020290ac(1);
        gs->CalculateDeltaTime(_ll_udiv((GetCurrentTimestamp() - last) * 64000, 33514));
        last = GetCurrentTimestamp();
    }

    func_02094b38(global, 0x69);
    FontBankLoader_CancelLoads(global);
    SePlayer_LoadArchive(&g_sePlayer, 0x64);
    func_020a2010(&combat);
    func_020a2cf0((struct Struct_0204a120_2*)&combat);
    Camera_Init(&combat);
}
