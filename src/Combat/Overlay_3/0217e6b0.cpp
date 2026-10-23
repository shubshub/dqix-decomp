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
enum { Enum_ov003_0217e6b0_108 = 0x8c };
enum { Enum_ov003_0217e6b0_238492 = 0x37edc };
enum { Enum_ov003_0217e6b0_3512 = 0xd90 };
enum { Enum_ov003_0217e6b0_2404 = 0x8cc };
enum { Enum_ov003_0217e6b0_3464 = 0xd4c };
enum { Enum_ov003_0217e6b0_1288 = 0x608 };
enum { Enum_ov003_0217e6b0_3484 = 0xd60 };
enum { Enum_ov003_0217e6b0_1060 = 0x444 };
#else
enum { Enum_ov003_0217e6b0_108 = 0x6c };
enum { Enum_ov003_0217e6b0_238492 = 0x3a39c };
enum { Enum_ov003_0217e6b0_3512 = 0xdb8 };
enum { Enum_ov003_0217e6b0_2404 = 0x964 };
enum { Enum_ov003_0217e6b0_3464 = 0xd88 };
enum { Enum_ov003_0217e6b0_1288 = 0x508 };
enum { Enum_ov003_0217e6b0_3484 = 0xd9c };
enum { Enum_ov003_0217e6b0_1060 = 0x424 };
#endif

struct Struct_02018300_3;
struct Struct_02038598_5;
struct Struct_0203d028;
struct Struct_0201e830;
struct Struct_02074b64;
struct Struct_02074bd0;
struct Struct_02074bf4;
struct Struct_02058564_2;

struct Struct_ov003_0217e6b0 {
    unsigned int unknown_0_0_ : 24;
    unsigned int unknown_3_0_ : 3;
    unsigned int unknown_3_3_ : 3;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_ov003_0217e6b0_2 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    void* unknown_1c_;
    int unknown_20_;
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
    int unknown_68_[10];
    int unknown_90_[2];
    unsigned int unknown_98_;
    unsigned int unknown_9c_;
    unsigned short unknown_a0_;
    char unknown_a2_[2];
    int unknown_a4_;
    int unknown_a8_;
    int unknown_ac_;
    void* unknown_b0_;
    unsigned char unknown_b4_;
};

extern "C" void func_020397cc(Struct_02018300_3* arg0, int arg1);
extern "C" int func_02046b08(void** arg0);
void SetBrightness(GameResources* resources, int brightness, int duration);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02074af4(void* arg0);
extern "C" void func_02074b64(Struct_02074b64* arg0);
extern "C" void func_020bb700(int* arg0);
extern "C" void func_020bb740(int* arg0);
extern "C" void func_020bb910(int* arg0);
extern "C" void* func_02012fe4(void);
unsigned short GetFieldAt0x7e_0201e830(S_e830* obj);
void ResetOverlayAndAllocator_0219bf74(void);
void CopyInternalFields0207df50(Foo0207df50* p);
extern "C" void func_020a1940(unsigned int id);
void PushInputLogB_020a1ef0(int id);
extern "C" void CharacterCreationUI_Init(void* scene, int a, int b);
extern "C" void func_ov008_021842a0(void* scene, SafeAllocator* alloc);
extern "C" void func_02082828(void* obj);
void SetField0x3b0Value_020100c4(GameState* gs, int v);
void SetPowCnt1Bit15_0217eea8(int enable);
void LockStagedTextureVRAMCopying(void);
void UnlockStagedTextureVRAMCopying(void);
void UpdateVRAMStagingVRAMBanks(void);
extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void func_020c391c(int arg0, int arg1, int arg2);
extern "C" void func_020c3984(unsigned int arg0);
extern "C" void func_020c5588(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_020c54a4(int arg0, unsigned int arg1, unsigned int arg2, unsigned short arg3);
extern "C" void* func_0203bd08(void);
void InitBattleContext0203bd24(char* ctx);
int* GetGlobalPtr02105244_0203bd14(void);
extern "C" int func_0203be4c(void* ctx);
extern "C" void func_0203c35c(int* ptr);
extern "C" int CharacterCreationUI_Update(void* scene);
void ClearFlag0x10IfSet(Struct02074bd0* obj);
void ClearFlag0x11IfSet(Struct02074bf4* obj);
void GetFieldAt0x150_02053c6c(unsigned char* obj);
void ProcessCombatantsIfFlagged_0218f79c(void* res);
void ProcessSlotField58_021a2840(GameResources* res);
extern "C" void* func_02057924(void);
void CleanupNodeList02058564(NodeList02058564* list);
extern "C" void func_ov017_0219b624(GameResources* res);
extern "C" void func_ov017_0219ba0c(GameResources* res, int v);
int GetGlobalField0x1c020421a0(void);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
extern "C" void func_020432c4(void* controller);
void AppendNode_021b66b8(char* obj);
void SetNodeStatus2_021b66f0(unsigned char* obj);
extern "C" void func_ov003_0217e67c(void* self);
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
void CallHelperFourTimesWithSelf_0218f758(void* res);
int ListContainsId(ListHead02046b60* list, int id);
void SetByteField0x253_020397c0(void* obj);

enum Enum_ov003_0217e6b0 {
    Enum_ov003_0217e6b0_0 = 0
};

static inline void inline_ov003_0217e6b0_2(Enum_ov003_0217e6b0 arg0) {
    DISPCNT = (unsigned int)((DISPCNT & ~0x300010) | arg0);
}

static inline void inline_ov003_0217e6b0_3(Enum_ov003_0217e6b0 arg0) {
    DISPCNTSUB = (unsigned int)((DISPCNTSUB & ~0x300010) | arg0);
}

static inline Struct_ov003_0217e6b0 inline_ov003_0217e6b0(void) {
    return *(volatile Struct_ov003_0217e6b0*)&DISPCNT;
}

// USA: func_ov003_0217e6b0
extern "C" ARM void func_ov003_0217e6b0(Struct_ov003_0217e6b0_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = GetGameResources();
    GameObject* var2 = var0->GetUnknownGameObject();
    func_020397cc((Struct_02018300_3*)var2, 1);

    if (arg0->unknown_20_ == 0) {
        if (!func_02046b08((void**)var1->unknown_ptr_array_36fc[1])) {
            return;
        }
        SetFlags00(var1, 0x10);
        SetFlags04(var1, 0xc0);
        SetBrightness(var1, -0x10, 0xf);
        arg0->unknown_20_++;
    } else if (arg0->unknown_20_ == 1) {
        if (IsBrightnessTransitionActive(var1)) {
            return;
        }
        arg0->unknown_34_ = 0;
        arg0->unknown_35_ = 0;
        func_02074af4(arg0->unknown_24_);
        arg0->unknown_38_ = (DISPCNT & 0x1f00) >> 8;
        func_02074b64((Struct_02074b64*)arg0->unknown_24_);
        arg0->unknown_3c_ = (DISPCNTSUB & 0x1f00) >> 8;
        arg0->unknown_40_ = GetMainBGVRAMBanks();
        arg0->unknown_44_ = GetSubBGVRAMBanks();
        arg0->unknown_48_ = GetMainObjVRAMBanks();
        arg0->unknown_4c_ = GetSubObjVRAMBanks();
        arg0->unknown_50_ = GetTextureImageVRAMBanks();
        arg0->unknown_54_ = GetTexturePaletteVRAMBanks();
        arg0->unknown_98_ = GetTextureImageAssignedVRAMSize();
        arg0->unknown_9c_ = GetTexturePaletteAssignedVRAMSize();
        func_020bb700(arg0->unknown_68_);
        func_020bb910(arg0->unknown_90_);
        Struct_ov003_0217e6b0 var3 = inline_ov003_0217e6b0();
        arg0->unknown_58_ = var3.unknown_3_3_;
        arg0->unknown_5c_ = var3.unknown_3_0_;
        arg0->unknown_60_ = DISPCNT & 0x300010;
        arg0->unknown_64_ = DISPCNTSUB & 0x300010;
        arg0->unknown_a0_ = func_0201e830((Struct_0201e830*)((char*)func_02012fe4() + Enum_ov003_0217e6b0_108));
        arg0->unknown_a4_ = GetFlags00(var1);
        arg0->unknown_a8_ = GetFlags04(var1);
        arg0->unknown_ac_ = GetFlags08(var1);
        SetFlags00(var1, 4);
        SetFlags04(var1, 0x8de);
        func_ov017_0219bf74();
        var1->allocator_array_38[0].Reset();
        func_0207df50((Struct_0203d028*)var1->unknown_2cc_);
        arg0->unknown_8_.CreateTypeA(var1->allocator_array_38[0].Allocate(Enum_ov003_0217e6b0_238492), Enum_ov003_0217e6b0_238492);
        arg0->unknown_8_.Reset();
        arg0->unknown_1c_ = arg0->unknown_8_.Allocate(Enum_ov003_0217e6b0_3512);
        func_020a1940(OVERLAY_ID(9));
        PushInputLogB_020a1ef0(1);
        CharacterCreationUI_Init(self->scene, self->sceneArg, CreationMode_PartyMemberCreation);
        func_ov008_021842a0(self->scene, &self->allocator);
        void* extra = self->allocator.Allocate(kRegionValue964_8CC);
        if (extra) {
            func_02082828(extra);
            *(void**)((char*)self->scene + kRegionValueD88_D4C) = extra;
        }
        arg0->unknown_b0_ = func_020100bc(var0);
        func_ov003_0217eea8(1);
        arg0->unknown_20_++;
    } else if (arg0->unknown_20_ == 2) {
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
        Set3DClearColor_020c5588(0, 0, 0x7fff, 0, 0);
        SetFogState_020c54a4(0, 0, 0, 0);
        char* context = (char*)func_0203bd08();
        InitBattleContext0203bd24(context);
        *(int*)context = 0;
        int* global = GetGlobalPtr02105244_0203bd14();
        *global = func_0203be4c(context) + 0x200;
        func_0203c35c(global);
        global[kRegionValue508_608 / 4] = 0x7000;
        self->state++;
    } else if (self->state == 3) {
        if (CharacterCreationUI_Update(self->scene)) {
            self->state++;
        }
    } else if (arg0->unknown_20_ == 4) {
        func_ov003_0217eea8(0);
        DisableSubBGVRAMBanks();
        DisableMainObjVRAMBanks();
        DisableSubObjVRAMBanks();
        DisableTextureImageVRAMBanks();
        MapVRAMBanksToSubBG(self->subBgBanks);
        MapVRAMBanksToMainObj(self->objBanks);
        MapVRAMBanksToSubObj(self->subObjBanks);
        MapVRAMBanksToTextureImage(self->textureBanks);
        ConfigurePairMode020bb48c((unsigned short)(self->textureSize >> 17), 1);
        RestorePairTableFromBuffer_020bb740(self->pairTable);
        GX_SetOBJVRamMode((GXOBJVRamMode)self->dispCntFlags);
        GXS_SetOBJVRamMode((GXOBJVRamMode)self->subDispCntFlags);
        DISPCNT = (DISPCNT & ~0x1f00) | (self->visiblePlanes << 8);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (self->subVisiblePlanes << 8);
        ClearFlag0x10IfSet((Struct02074bd0*)self->controlBackup);
        ClearFlag0x11IfSet((Struct02074bf4*)self->controlBackup);
        Set3DClearColor_020c5588(self->clearColor, 0x10, 0x7fff, 0, 0);
        char blank[0x20];
        memset(blank, 0, 0x20);
        CleanInvalidateCacheRange(blank, 0x20);
        LoadToMainBG1CharacterData(blank, 0, 0x20);
        ClearFlags00(res, -1);
        ClearFlags04(res, -1);
        ClearFlags08(res, -1);
        SetFlags00(res, self->word);
        SetFlags04(res, self->field4);
        SetFlags08(res, self->field8);
        SetFlags00(res, 4);
        SetFlags04(res, 2);
        GetFieldAt0x150_02053c6c((unsigned char*)gs->GetProtagonist());
        ProcessCombatantsIfFlagged_0218f79c(res);
        ProcessSlotField58_021a2840(res);
        CleanupNodeList02058564((NodeList02058564*)func_02057924());
        SetField0x3b0Value_020100c4(gs, (int)self->fieldB0);
        func_ov017_0219b624(res);
        func_ov017_0219ba0c(res, 0);
        char* fields = res->unknown_2cc;
        void* controller = (void*)GetGlobalField0x1c020421a0();
        CopyInternalFields0207df50((Foo0207df50*)(fields + 0x5b0));
        VramState_Restore(fields + 0x5b0);
        func_020432c4(controller);
        VramState_Save(fields + 0x5b0);
        self->state++;
    } else if (self->state == 5) {
        if (*(int*)((char*)self->scene + kRegionValueD9C_D60) & 0x400) {
            AppendNode_021b66b8((char*)res);
        } else {
            func_ov017_021b66f0((unsigned char*)var1);
        }
        func_ov003_0217e67c(arg0);
        ClearFlags00(var1, 0x10);
        func_ov017_0219bd1c(1, 0, 0, 0);
        arg0->unknown_20_++;
    } else if (arg0->unknown_20_ == 6) {
        if (*(int*)((char*)func_02012fe4() + Enum_ov003_0217e6b0_1060) != 0) {
            return;
        }
        ClearFlags04(var1, 2);
        func_ov017_0218f758(var1);
        SetMainBrightness(var1, 0, 0xf);
        arg0->unknown_20_++;
    } else {
        if (IsBrightnessTransitionActive(var1)) {
            return;
        }
        arg0->unknown_1_ = 1;
        if (func_02046b60((Struct_02038598_5*)var1->unknown_ptr_array_36fc[0], 0x17)) {
            return;
        }
        func_020397c0(var2);
        ClearFlags04(var1, 0xc0);
        return;
    }
    func_020397cc((Struct_02018300_3*)var2, 1);
}
