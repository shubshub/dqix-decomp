#include <globaldefs.h>
#include "GameState/Field3b0.h"

#if defined(jpn)
enum { kSceneHeapSize = 0x1e384, Enum_ov017_021c0850_2888 = 0xb44, kGlobalColorOffset = 0x8c, Enum_ov017_021c0850_1288 = 0x608, Enum_ov017_021c0850_728 = 0x228, Enum_ov017_021c0850_742 = 0x236 };
#else
enum { kSceneHeapSize = 0x1e388, Enum_ov017_021c0850_2888 = 0xb48, kGlobalColorOffset = 0x6c, Enum_ov017_021c0850_1288 = 0x508, Enum_ov017_021c0850_728 = 0x2d8, Enum_ov017_021c0850_742 = 0x2e6 };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/OverlayId.h"
#include "NitroSDK/VRAM.h"
#include "World/Object3D.h"
#include "Resource/Brightness.h"

struct AllocatorUnion;
struct Obj020397cc;
struct Struct_ov017_021c0580;
struct S_e830;
struct Struct_02074b64;
struct Struct_02074bd0;
struct Struct_02074bf4;
struct HeadList020469f8;
struct HeadNode020469f8;

struct Struct_ov003_0217e6b0 {
    unsigned int low : 24;
    unsigned int unknown_3_0_ : 3;
    unsigned int unknown_3_3_ : 3;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_ov017_021c0850 {
    char pad0[0xb13];
    unsigned char kind;
    short x;
    short y;
    union {
        unsigned int flags;
        struct {
            unsigned int bit0 : 1;
            unsigned int unknown_0_1_ : 17;
            unsigned int unknown_2_2_ : 1;
            unsigned int rest : 13;
        } bits;
    };
    char unknown_b1c_[0xc];
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
};

struct Struct_ov017_021c0850_2 {
    char pad0;
    unsigned char done;
    char pad2[6];
    SafeAllocator allocator;
    Struct_ov017_021c0850* scene;
    int state;
    unsigned char unknown_24_;
    unsigned char unknown_25_;
    unsigned char unknown_26_;
    char unknown_27_;
    short x;
    short y;
    char unknown_2c_[0x10];
    unsigned char unknown_3c_;
    unsigned char unknown_3d_;
    char unknown_3e_[2];
    int unknown_40_;
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
    char unknown_50_[8];
    int unknown_58_;
    int unknown_5c_;
    int unknown_60_;
    int unknown_64_;
    int unknown_68_;
    char pad6c[4];
    int pairTable[10];
    int globalPair[2];
    unsigned int textureSize;
    unsigned int paletteSize;
    unsigned short clearColor;
    char unknown_aa_[2];
    int word;
    int field4;
    int field8;
    void* fieldB8;
    unsigned char unknown_bc_;
};

extern "C" void GameObject_DisableControl(Obj020397cc* obj, int arg1);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_020a1ef0(int id);
extern "C" void func_ov008_021843f8(void* scene);
extern "C" void func_ov008_021842a0(void* scene, SafeAllocator* alloc);
struct ShortField0xb8_0209cae8;
extern "C" int func_0209cae8(ShortField0xb8_0209cae8*);
struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(Actor0209c678*, int);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* func_0203cf4c(void);
extern "C" void func_0203e0a0(void* g, unsigned short val);
void SetBrightness(GameResources* resources, int brightness, int duration);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02074af4(void* obj);
extern "C" void func_02074b64(Struct_02074b64* backup);
extern "C" void NNS_GfdGetFrmTexVramState(int* buffer);
extern "C" void NNS_GfdSetFrmTexVramState(int* buffer);
extern "C" void NNS_GfdGetFrmPlttVramState(int* pair);
extern "C" unsigned short func_0201e830(S_e830* obj);
extern "C" void GameState_SetCamera(GameState* gs, int v);
void LockStagedTextureVRAMCopying(void);
void UnlockStagedTextureVRAMCopying(void);
void UpdateVRAMStagingVRAMBanks(void);
extern "C" void func_020bb48c(unsigned int mode, int flag);
extern "C" void GX_SetGraphicsMode(int a, int b, int c);
extern "C" void GXS_SetGraphicsMode(unsigned int mode);
extern "C" void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fog);
extern "C" void func_020c54a4(int enable, unsigned int mode, unsigned int shift, unsigned short offset);
extern "C" void* OamManager_GetInstance(void);
extern "C" void OamManager_Init(char* ctx);
extern "C" int* CachedTextTable_GetInstance(void);
extern "C" int OamManager_GetSubOamBuffer(void* ctx);
extern "C" void CachedTextTable_LoadPalettes(int* ptr);
extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov008_02184a2c(char*);
extern "C" int func_ov008_02184754(void* obj);
extern "C" void func_02074bd0(Struct_02074bd0* obj);
extern "C" void func_02074bf4(Struct_02074bf4* obj);
extern "C" void* func_ov008_021845ac(void* obj);
extern "C" void func_ov017_0218f79c(void* res);
extern "C" void func_ov017_0219b624(GameResources* res);
extern "C" int MessageSystem_GetInstance(void);
struct Foo0207df50;
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" void func_020432c4(void* controller);
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
extern "C" void func_ov017_021c0820(Struct_ov017_021c0580*);
struct Struct_ov017_021c0334;
extern "C" void func_ov017_021c0334(Struct_ov017_021c0334*);
struct Struct_ov017_021b146c;
extern "C" void func_ov017_021b14a0(Struct_ov017_021b146c*);
extern "C" void func_ov017_021b1d3c(void* obj, int v);
extern "C" void func_020469f8(HeadList020469f8* list, HeadNode020469f8* node);
extern "C" void func_ov017_021c0580(void* self, int kind, const char* name, void* handler);
extern "C" int func_0209cd50(int id);
struct Actor0209c3b4;
extern "C" void func_0209c3b4(Actor0209c3b4*, int);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021c07d0(void* self);
extern "C" int func_ov004_0215502c(SafeAllocator* alloc, int arg);
extern "C" int func_ov004_021560b0(SafeAllocator* alloc, int arg);
extern "C" int func_ov004_02156dc8(SafeAllocator* alloc, int arg);
extern "C" int func_ov004_021677b4(SafeAllocator* alloc, void* arg);
extern "C" int func_ov004_0216aa70(SafeAllocator* alloc, void* arg);

extern AllocatorUnion g_mainAllocator;
extern int g_bgmPlayer;
extern char data_ov017_021d7f00[];
extern char data_ov017_021d7f07[];
extern char data_ov017_021d7f12[];
extern char data_ov017_021d7f19[];
extern char data_ov017_021d7f22[];

#define POWCNT1 (*(volatile unsigned short*)0x04000304)

static inline void inline_ov017_021c0850(int sel) {
    POWCNT1 = (unsigned short)((POWCNT1 & ~0x8000) | (sel << 15));
}

static inline void inline_ov017_021c0850_2(int priority) {
    BG3CNT = (unsigned short)((BG3CNT & ~3) | priority);
}

static inline void inline_ov017_021c0850_3(int plane) {
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (plane << 8);
}

static inline Struct_ov003_0217e6b0 inline_ov003_0217e6b0(void) {
    return *(volatile Struct_ov003_0217e6b0*)&DISPCNT;
}

// USA: func_ov017_021c0850
extern "C" ARM void func_ov017_021c0850(Struct_ov017_021c0850_2* self) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    GameObject* leader = gs->GetLeader();
    GameObject_DisableControl((Obj020397cc*)leader, 1);

    if (self->state == 0) {
        func_020a0cc4(kSceneHeapSize);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, kSceneHeapSize);
        if (buffer == NULL) {
            ROMFilesystem_InitFileTables();
            self->done = 1;
            return;
        }
        self->allocator.CreateTypeA(buffer, kSceneHeapSize);
        self->allocator.Reset();
        self->scene = (Struct_ov017_021c0850*)self->allocator.Allocate(Enum_ov017_021c0850_2888);
        if (self->scene == NULL) {
            ROMFilesystem_InitFileTables();
            self->done = 1;
            return;
        }
        Overlay_Load(OVERLAY_ID(8));
        func_020a1ef0(1);
        func_ov008_021843f8(self->scene);
        func_ov008_021842a0(self->scene, &self->allocator);
        self->scene->unknown_b28_ = self->unknown_24_;
        self->scene->unknown_b29_ = self->unknown_25_;
        self->scene->x = self->x;
        self->scene->y = self->y;
        Struct_ov017_021c0850* scene = self->scene;
        if (self->unknown_26_) {
            scene->flags |= 0x40000;
        } else {
            scene->flags &= ~0x40000;
        }
        if (self->unknown_bc_) {
            self->scene->flags |= 1;
            if (func_0209cae8((ShortField0xb8_0209cae8*)&g_bgmPlayer) != 0x29) {
                BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0xf);
            }
        }
        unsigned short* id = (unsigned short*)Zone3D_GetInstance();
        func_0203e0a0(func_0203cf4c(), *id);
        if (GetBrightness((GameResources*)res, false) != Brightness_Black
            || GetBrightness((GameResources*)res, true) != Brightness_Black) {
            SetBrightness(res, -0x10, 0xf);
        }
        self->state++;
    } else if (self->state == 1) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        if (!self->unknown_bc_) {
            self->state++;
            return;
        }
        self->unknown_3c_ = 0;
        self->unknown_3d_ = 0;
        func_02074af4(self->unknown_2c_);
        self->unknown_40_ = (DISPCNT & 0x1f00) >> 8;
        func_02074b64((Struct_02074b64*)self->unknown_2c_);
        self->unknown_44_ = (DISPCNTSUB & 0x1f00) >> 8;
        self->unknown_48_ = GetMainBGVRAMBanks();
        self->unknown_4c_ = GetSubBGVRAMBanks();
        self->unknown_58_ = GetTextureImageVRAMBanks();
        self->unknown_5c_ = GetTexturePaletteVRAMBanks();
        self->textureSize = GetTextureImageAssignedVRAMSize();
        self->paletteSize = GetTexturePaletteAssignedVRAMSize();
        NNS_GfdGetFrmTexVramState(self->pairTable);
        NNS_GfdGetFrmPlttVramState(self->globalPair);
        Struct_ov003_0217e6b0 var6 = inline_ov003_0217e6b0();
        self->unknown_60_ = var6.unknown_3_3_;
        self->unknown_64_ = var6.unknown_3_0_;
        self->unknown_68_ = DISPCNT & 0x300010;
        self->clearColor = func_0201e830((S_e830*)((char*)Zone3D_GetInstance() + kGlobalColorOffset));
        self->word = GetFlags00(res);
        self->field4 = GetFlags04(res);
        self->field8 = GetFlags08(res);
        self->fieldB8 = gs->GetCamera();
        self->state++;
    } else if (self->state == 2) {
        LockStagedTextureVRAMCopying();
        DisableSubBGVRAMBanks();
        DisableSubObjVRAMBanks();
        DisableTextureImageVRAMBanks();
        inline_ov017_021c0850(0);
        MapVRAMBanksToTextureImage(1);
        func_020bb48c(1, 1);
        MapVRAMBanksToSubBG(4);
        MapVRAMBanksToSubObj(0x100);
        DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
        UpdateVRAMStagingVRAMBanks();
        UnlockStagedTextureVRAMCopying();
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1300;
        GX_SetGraphicsMode(1, 0, 1);
        BG1CNT = (BG1CNT & 0x43) | 0x1e00;
        BG0CNT = (BG0CNT & ~3) | 1;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 3;
        inline_ov017_021c0850_2(0);
        ColorEffect_ConfigureAlphaBlend(0x04000050, 1, 2, 0xf, 0x1f);
        inline_ov017_021c0850_3(0x13);
        GXS_SetGraphicsMode(0);
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xe00;
        BG1CNTSUB = (BG1CNTSUB & 0x43) | 0xf08;
        BG0CNTSUB = (BG0CNTSUB & ~3) | 1;
        BG1CNTSUB = BG1CNTSUB & ~3;
        BG2CNTSUB = (BG2CNTSUB & ~3) | 2;
        BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
        SetFlags00(res, 4);
        SetFlags04(res, 0x8de);
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        func_020c54a4(0, 0, 0, 0);
        char* context = (char*)OamManager_GetInstance();
        OamManager_Init(context);
        *(int*)context = 0;
        int* global = CachedTextTable_GetInstance();
        *global = OamManager_GetSubOamBuffer(context) + 0x200;
        CachedTextTable_LoadPalettes(global);
        global[Enum_ov017_021c0850_1288 / 4] = 0x7000;
        self->state++;
    } else if (self->state == 3) {
        if (func_ov017_021959b4()) {
            func_ov008_02184a2c((char*)self->scene);
        }
        if (func_ov008_02184754(self->scene)) {
            self->state++;
        }
    } else if (self->state == 4) {
        LockStagedTextureVRAMCopying();
        DisableSubBGVRAMBanks();
        DisableTextureImageVRAMBanks();
        MapVRAMBanksToSubBG(self->unknown_4c_);
        MapVRAMBanksToTextureImage(self->unknown_58_);
        func_020bb48c((unsigned short)(self->textureSize >> 17), 1);
        NNS_GfdSetFrmTexVramState(self->pairTable);
        UpdateVRAMStagingVRAMBanks();
        UnlockStagedTextureVRAMCopying();
        DISPCNT = (DISPCNT & ~0x1f00) | (self->unknown_40_ << 8);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (self->unknown_44_ << 8);
        func_02074bd0((Struct_02074bd0*)self->unknown_2c_);
        func_02074bf4((Struct_02074bf4*)self->unknown_2c_);
        Set3DClearColor(self->clearColor, 0x10, 0x7fff, 0, 0);
        func_ov008_021845ac(self->scene);
        char var9[0x20];
        memset(var9, 0, 0x20);
        CleanInvalidateCacheRange(var9, 0x20);
        LoadToMainBG1CharacterData(var9, 0, 0x20);
        ClearFlags00(res, -1);
        ClearFlags04(res, -1);
        ClearFlags08(res, -1);
        SetFlags00(res, self->word);
        SetFlags04(res, self->field4);
        SetFlags08(res, self->field8);
        func_ov017_0218f79c(res);
        GameState_SetCamera(gs, (int)self->fieldB8);
        GameState* state = GameState::GetInstance();
        int index = 0x70;
        for (int i = 0; i < 0x30; i++) {
            GameObject* monster = state->GetFieldMonsterByIndex(index);
            if (monster) {
                monster->obj3D_.StageTextureData();
            }
            index++;
        }
        func_ov017_0219b624(res);
        char* fields = res->vramStates_;
        void* controller = (void*)MessageSystem_GetInstance();
        VramState_Rewind((Foo0207df50*)(fields + 0x5b0));
        VramState_Restore(fields + 0x5b0);
        func_020432c4(controller);
        VramState_Save(fields + 0x5b0);
        if (self->scene->kind == 0) {
            func_ov017_0219bd1c(1, 0, 0, 0);
        }
        self->state++;
    } else if (self->state == 5) {
        self->unknown_3c_ = 0;
        self->unknown_3d_ = 0;
        func_02074af4(self->unknown_2c_);
        func_02074b64((Struct_02074b64*)self->unknown_2c_);
        self->unknown_25_ = self->scene->unknown_b29_;
        self->unknown_26_ = (self->scene->flags & 0x40000) != 0;
        self->x = self->scene->x;
        self->y = self->scene->y;
        GameResources* res2 = GetGameResources();
        HeadList020469f8* list = (HeadList020469f8*)res2->fieldTaskQueue_;
        HeadNode020469f8* node;
        switch (self->scene->kind) {
        case 1:
            func_ov017_021c0820((Struct_ov017_021c0580*)self);
            self->unknown_24_ = 0;
            node = (HeadNode020469f8*)res2->fieldTasks_[15];
            func_ov017_021c0334((Struct_ov017_021c0334*)node);
            func_020469f8(list, node);
            return;
        case 2:
            func_ov017_021c0580(self, 1, data_ov017_021d7f00, (void*)func_ov004_0215502c);
            return;
        case 3:
            func_ov017_021c0580(self, 2, data_ov017_021d7f07, (void*)func_ov004_021560b0);
            return;
        case 4:
            func_ov017_021c0820((Struct_ov017_021c0580*)self);
            self->unknown_24_ = 3;
            node = (HeadNode020469f8*)res2->fieldTasks_[18];
            func_ov017_021b14a0((Struct_ov017_021b146c*)node);
            func_ov017_021b1d3c(node, 1);
            func_020469f8(list, node);
            return;
        case 5:
            func_ov017_021c0580(self, 4, data_ov017_021d7f12, (void*)func_ov004_02156dc8);
            return;
        case 6:
            func_ov017_021c0580(self, 5, data_ov017_021d7f19, (void*)func_ov004_021677b4);
            return;
        case 7:
            func_ov017_021c0580(self, 6, data_ov017_021d7f22, (void*)func_ov004_0216aa70);
            return;
        case 0: {
            SetMainBrightness(res, 0, 0xf);
            func_0209c3b4((Actor0209c3b4*)&g_bgmPlayer, func_0209cd50(*(unsigned short*)Zone3D_GetInstance()));
            char* global = (char*)MessageSystem_GetInstance();
            *(int*)(global + Enum_ov017_021c0850_728) = 0;
            *(unsigned char*)(global + Enum_ov017_021c0850_742) = 1;
            break;
        }
        }
        self->state++;
    } else {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        if (self->scene->kind == 0) {
            GameObject_EnableControl(leader);
        } else {
            GameObject_DisableControl((Obj020397cc*)leader, 1);
        }
        func_ov017_021c07d0(self);
        ROMFilesystem_InitFileTables();
        self->done = 1;
    }
}
