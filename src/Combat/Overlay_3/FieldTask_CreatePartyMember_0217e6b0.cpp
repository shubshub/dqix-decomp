#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/OverlayId.h"
#include "NitroSDK/VRAM.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { kRegionValue6C_8C = 0x8c };
enum { Enum_ov003_0217e6b0_238492 = 0x37edc };
enum { Enum_ov003_0217e6b0_3512 = 0xd90 };
enum { Enum_ov003_0217e6b0_2404 = 0x8cc };
enum { Enum_ov003_0217e6b0_3464 = 0xd4c };
enum { Enum_ov003_0217e6b0_1288 = 0x608 };
enum { Enum_ov003_0217e6b0_3484 = 0xd60 };
enum { kRegionValue424_444 = 0x444 };
#else
enum { kRegionValue6C_8C = 0x6c };
enum { Enum_ov003_0217e6b0_238492 = 0x3a39c };
enum { Enum_ov003_0217e6b0_3512 = 0xdb8 };
enum { Enum_ov003_0217e6b0_2404 = 0x964 };
enum { Enum_ov003_0217e6b0_3464 = 0xd88 };
enum { Enum_ov003_0217e6b0_1288 = 0x508 };
enum { Enum_ov003_0217e6b0_3484 = 0xd9c };
enum { kRegionValue424_444 = 0x424 };
#endif

struct Obj020397cc;
struct ListHead02046b60;
struct Foo0207df50;
struct S_e830;
struct Struct_02074b64;
struct Struct_02074bd0;
struct Struct_02074bf4;
struct Struct_02058564_2;

struct Struct_ov003_0217e6b0 {
    unsigned int low : 24;
    unsigned int unknown_3_0_ : 3;
    unsigned int unknown_3_3_ : 3;
    unsigned int unknown_3_6_ : 2;
};

struct SceneSwap0217e6b0 {
    char pad0;
    unsigned char done;
    char pad2[6];
    SafeAllocator allocator;
    void* scene;
    int state;
    char unknown_24_[0x10];
    unsigned char unknown_34_;
    unsigned char unknown_35_;
    char unknown_36_[2];
    int unknown_38_;
    int unknown_3c_;
    int unknown_40_;
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
    int unknown_50_;
    int unknown_54_;
    int unknown_58_;
    int unknown_5c_;
    int unknown_60_;
    int unknown_64_;
    int pairTable[10];
    int globalPair[2];
    unsigned int textureSize;
    unsigned int paletteSize;
    unsigned short clearColor;
    char unknown_a2_[2];
    int word;
    int field4;
    int field8;
    void* fieldB0;
    unsigned char sceneArg;
};

extern "C" void GameObject_DisableControl(Obj020397cc* obj, int arg1);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
void SetBrightness(GameResources* resources, int brightness, int duration);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02074af4(void* obj);
extern "C" void func_02074b64(Struct_02074b64* backup);
extern "C" void NNS_GfdGetFrmTexVramState(int* buffer);
extern "C" void NNS_GfdSetFrmTexVramState(int* buffer);
extern "C" void NNS_GfdGetFrmPlttVramState(int* pair);
extern "C" void* Zone3D_GetInstance(void);
extern "C" unsigned short func_0201e830(S_e830* obj);
extern "C" void func_ov017_0219bf74(void);
extern "C" void VramState_Rewind(Foo0207df50* p);
extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_020a1ef0(int id);
extern "C" void CharacterCreationUI_Init(void* scene, int a, int b);
extern "C" void func_ov008_021842a0(void* scene, SafeAllocator* alloc);
extern "C" void func_02082828(void* obj);
extern "C" void GameState_SetCamera(GameState* gs, int v);
extern "C" void func_ov003_0217eea8(int enable);
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
extern "C" int CharacterCreationUI_Update(void* scene);
extern "C" void func_02074bd0(Struct_02074bd0* obj);
extern "C" void func_02074bf4(Struct_02074bf4* obj);
extern "C" void func_02053c6c(unsigned char* obj);
extern "C" void func_ov017_0218f79c(void* res);
extern "C" void func_ov017_021a2840(GameResources* res);
extern "C" void* func_02057924(void);
extern "C" void func_02058564(Struct_02058564_2* list);
extern "C" void func_ov017_0219b624(GameResources* res);
extern "C" void func_ov017_0219ba0c(GameResources* res, int v);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" void func_020432c4(void* controller);
extern "C" void func_ov017_021b66b8(char* obj);
extern "C" void func_ov017_021b66f0(unsigned char* obj);
extern "C" void func_ov003_0217e67c(void* self);
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
extern "C" void func_ov017_0218f758(void* res);
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" void GameObject_EnableControl(void* obj);

enum Enum_ov003_0217e6b0 {
    Enum_ov003_0217e6b0_0 = 0
};

static inline void inline_ov003_0217e6b0_2(Enum_ov003_0217e6b0 mode) {
    DISPCNT = (unsigned int)((DISPCNT & ~0x300010) | mode);
}

static inline void inline_ov003_0217e6b0_3(Enum_ov003_0217e6b0 mode) {
    DISPCNTSUB = (unsigned int)((DISPCNTSUB & ~0x300010) | mode);
}

static inline Struct_ov003_0217e6b0 inline_ov003_0217e6b0(void) {
    return *(volatile Struct_ov003_0217e6b0*)&DISPCNT;
}

// Overlay 3, originally func_ov003_0217e6b0 (USA/EUR 0x0217e6b0, JPN 0x0217d3b8)
extern "C" ARM void FieldTask_CreatePartyMember(SceneSwap0217e6b0* self) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    GameObject* leader = gs->GetLeader();
    GameObject_DisableControl((Obj020397cc*)leader, 1);

    if (self->state == 0) {
        if (!FieldTaskQueue_IsEmpty((void**)res->unknown_ptr_array_3700[0])) {
            return;
        }
        SetFlags00(res, 0x10);
        SetFlags04(res, 0xc0);
        SetBrightness(res, -0x10, 0xf);
        self->state++;
    } else if (self->state == 1) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        self->unknown_34_ = 0;
        self->unknown_35_ = 0;
        func_02074af4(self->unknown_24_);
        self->unknown_38_ = (DISPCNT & 0x1f00) >> 8;
        func_02074b64((Struct_02074b64*)self->unknown_24_);
        self->unknown_3c_ = (DISPCNTSUB & 0x1f00) >> 8;
        self->unknown_40_ = GetMainBGVRAMBanks();
        self->unknown_44_ = GetSubBGVRAMBanks();
        self->unknown_48_ = GetMainObjVRAMBanks();
        self->unknown_4c_ = GetSubObjVRAMBanks();
        self->unknown_50_ = GetTextureImageVRAMBanks();
        self->unknown_54_ = GetTexturePaletteVRAMBanks();
        self->textureSize = GetTextureImageAssignedVRAMSize();
        self->paletteSize = GetTexturePaletteAssignedVRAMSize();
        NNS_GfdGetFrmTexVramState(self->pairTable);
        NNS_GfdGetFrmPlttVramState(self->globalPair);
        Struct_ov003_0217e6b0 var3 = inline_ov003_0217e6b0();
        self->unknown_58_ = var3.unknown_3_3_;
        self->unknown_5c_ = var3.unknown_3_0_;
        self->unknown_60_ = DISPCNT & 0x300010;
        self->unknown_64_ = DISPCNTSUB & 0x300010;
        self->clearColor = func_0201e830((S_e830*)((char*)Zone3D_GetInstance() + kRegionValue6C_8C));
        self->word = GetFlags00(res);
        self->field4 = GetFlags04(res);
        self->field8 = GetFlags08(res);
        SetFlags00(res, 4);
        SetFlags04(res, 0x8de);
        func_ov017_0219bf74();
        res->allocator_array_38[0].Reset();
        VramState_Rewind((Foo0207df50*)res->vramStates_);
        self->allocator.CreateTypeA(res->allocator_array_38[0].Allocate(Enum_ov003_0217e6b0_238492), Enum_ov003_0217e6b0_238492);
        self->allocator.Reset();
        self->scene = self->allocator.Allocate(Enum_ov003_0217e6b0_3512);
        Overlay_Load(OVERLAY_ID(9));
        func_020a1ef0(1);
        CharacterCreationUI_Init(self->scene, self->sceneArg, CreationMode_PartyMemberCreation);
        func_ov008_021842a0(self->scene, &self->allocator);
        void* extra = self->allocator.Allocate(Enum_ov003_0217e6b0_2404);
        if (extra) {
            func_02082828(extra);
            *(void**)((char*)self->scene + Enum_ov003_0217e6b0_3464) = extra;
        }
        self->fieldB0 = gs->GetCamera();
        func_ov003_0217eea8(1);
        self->state++;
    } else if (self->state == 2) {
        LockStagedTextureVRAMCopying();
        DisableSubBGVRAMBanks();
        DisableMainObjVRAMBanks();
        DisableSubObjVRAMBanks();
        DisableTextureImageVRAMBanks();
        MapVRAMBanksToTextureImage(1);
        func_020bb48c(1, 1);
        MapVRAMBanksToSubBG(4);
        MapVRAMBanksToMainObj(0x20);
        DISPCNT = (DISPCNT & 0xffcfffef) | 0x10;
        MapVRAMBanksToSubObj(8);
        DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
        UpdateVRAMStagingVRAMBanks();
        UnlockStagedTextureVRAMCopying();
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
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
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        func_020c54a4(0, 0, 0, 0);
        char* context = (char*)OamManager_GetInstance();
        OamManager_Init(context);
        *(int*)context = 0;
        int* global = CachedTextTable_GetInstance();
        *global = OamManager_GetSubOamBuffer(context) + 0x200;
        CachedTextTable_LoadPalettes(global);
        global[Enum_ov003_0217e6b0_1288 / 4] = 0x7000;
        self->state++;
    } else if (self->state == 3) {
        if (CharacterCreationUI_Update(self->scene)) {
            self->state++;
        }
    } else if (self->state == 4) {
        func_ov003_0217eea8(0);
        DisableSubBGVRAMBanks();
        DisableMainObjVRAMBanks();
        DisableSubObjVRAMBanks();
        DisableTextureImageVRAMBanks();
        MapVRAMBanksToSubBG(self->unknown_44_);
        MapVRAMBanksToMainObj(self->unknown_48_);
        MapVRAMBanksToSubObj(self->unknown_4c_);
        MapVRAMBanksToTextureImage(self->unknown_50_);
        func_020bb48c((unsigned short)(self->textureSize >> 17), 1);
        NNS_GfdSetFrmTexVramState(self->pairTable);
        inline_ov003_0217e6b0_2((Enum_ov003_0217e6b0)self->unknown_60_);
        inline_ov003_0217e6b0_3((Enum_ov003_0217e6b0)self->unknown_64_);
        DISPCNT = (DISPCNT & ~0x1f00) | (self->unknown_38_ << 8);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (self->unknown_3c_ << 8);
        func_02074bd0((Struct_02074bd0*)self->unknown_24_);
        func_02074bf4((Struct_02074bf4*)self->unknown_24_);
        Set3DClearColor(self->clearColor, 0x10, 0x7fff, 0, 0);
        char var7[0x20];
        memset(var7, 0, 0x20);
        CleanInvalidateCacheRange(var7, 0x20);
        LoadToMainBG1CharacterData(var7, 0, 0x20);
        ClearFlags00(res, -1);
        ClearFlags04(res, -1);
        ClearFlags08(res, -1);
        SetFlags00(res, self->word);
        SetFlags04(res, self->field4);
        SetFlags08(res, self->field8);
        SetFlags00(res, 4);
        SetFlags04(res, 2);
        func_02053c6c((unsigned char*)gs->GetProtagonist());
        func_ov017_0218f79c(res);
        func_ov017_021a2840(res);
        func_02058564((Struct_02058564_2*)func_02057924());
        GameState_SetCamera(gs, (int)self->fieldB0);
        func_ov017_0219b624(res);
        func_ov017_0219ba0c(res, 0);
        char* fields = res->vramStates_;
        void* controller = (void*)MessageSystem_GetInstance();
        VramState_Rewind((Foo0207df50*)(fields + 0x5b0));
        VramState_Restore(fields + 0x5b0);
        func_020432c4(controller);
        VramState_Save(fields + 0x5b0);
        self->state++;
    } else if (self->state == 5) {
        if (*(int*)((char*)self->scene + Enum_ov003_0217e6b0_3484) & 0x400) {
            func_ov017_021b66b8((char*)res);
        } else {
            func_ov017_021b66f0((unsigned char*)res);
        }
        func_ov003_0217e67c(self);
        ClearFlags00(res, 0x10);
        func_ov017_0219bd1c(1, 0, 0, 0);
        self->state++;
    } else if (self->state == 6) {
        if (*(int*)((char*)Zone3D_GetInstance() + kRegionValue424_444) != 0) {
            return;
        }
        ClearFlags04(res, 2);
        func_ov017_0218f758(res);
        SetMainBrightness(res, 0, 0xf);
        self->state++;
    } else {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        self->done = 1;
        if (func_02046b60((ListHead02046b60*)res->fieldTaskQueue_, 0x17)) {
            return;
        }
        GameObject_EnableControl(leader);
        ClearFlags04(res, 0xc0);
        return;
    }
    GameObject_DisableControl((Obj020397cc*)leader, 1);
}
