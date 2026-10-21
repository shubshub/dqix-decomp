#if defined(jpn)
#define R(j,u) (j)
#define data_ov009_0218aa28 data_ov009_0218ba04
#define data_ov009_0218aa34 data_ov009_0218ba10
#define data_ov009_0218aa98 data_ov009_0218ba4c
#define data_ov009_0218acd9 data_ov009_0218bc3e
#define data_ov009_0218ad41 data_ov009_0218bc71
#define func_ov023_021dac40 func_ov023_021db4b4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#if defined(jpn)
#define func_ov009_0218a930 func_ov009_0218b908
#endif
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/ColorEffects.h"

#if defined(jpn)
#define func_020c39a0 func_020c546c
#endif

#define REG_BLDCNT 0x04000050
#define REG_BLDCNT_SUB 0x04001050
#define REG_MASTER_BRIGHT ((short*)0x0400006c)
#define REG_MASTER_BRIGHT_SUB ((short*)0x0400106c)
#define FX32_FROM_FLOAT(x) ((int)((x) > 0.0f ? 0.5f + 4096.0f * (x) : 4096.0f * (x) - 0.5f))

struct Struct_ov009_02187b34 {
    short unknown_0_[10];
    unsigned char unknown_14_[4];
    short unknown_18_;
    short unknown_1a_;
};

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x488];
    Struct_ov009_02187b34 unknown_488_;
};

struct Struct_ov009_02187b34_2 {
    SafeAllocator* unknown_0_;
    const char* unknown_4_;
    unsigned char unknown_8_;
};

struct Struct_ov009_0218aa98 {
    Struct_ov009_02187b34_2 unknown_0_[4];
};

struct Struct_02109bf4_4;
struct Struct_0201099c_3;
struct Struct_0203d028;
struct Struct_02038598_4;

extern "C" Object3D* func_ov023_021e6194(void* character);
unsigned int* GetDataPtr02114e04_020d6c00();
extern "C" void func_ov023_021dac40(void* self, unsigned int ticks);
extern "C" int func_ov009_0218a930(void* self, unsigned int ticks);
void CallFunc020a0db8AtField0x16c_0202ee38(char* camera, int position, int duration);
void CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58(char* camera, int target, int duration);
void DispatchContextByState0209c678(Actor0209c678* actor, int state);
int AnySubObjectField0NonZero_0202eeb4(char* camera);
void SetForwardAndStore0205ebc0(void* sound, int a, int b);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void CopyInternalFields0207df50(Foo0207df50* a);
void RestorePairTables0207df90(char* a);
void BackupPairTables0207dfac(char* a);
void DispatchIfField0xc4NonNeg_0205ebfc(void* sound, int a, int b);
void OrBitsIntoField0_020466e4(unsigned int* field, unsigned int bits);
void ClearFlags020466f4(FlagWord020466f4* field, unsigned int bits);
extern "C" void func_020c39a0(short* reg, int brightness);
void ForwardField0xc0_0205ebec(void* sound);
#if defined(jpn)
void CharacterCreationUI_SwitchTab(unsigned char* self, int state);
#else
void CharacterCreationUI_SwitchTab(unsigned char* self, int state);
#endif

struct Struct_ov009_0218aa28 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

extern const Struct_ov009_0218aa28 data_ov009_0218aa28;
extern const Struct_ov009_0218aa28 data_ov009_0218aa34;
extern const Struct_ov009_0218aa98 data_ov009_0218aa98;
extern char data_ov009_0218acd9[];
extern char data_ov009_0218ad41[];
extern char data_02109bf4[];
extern char data_02108760[];

struct Struct_ov009_021842a0_2 {
    char unknown_0_[R(0xa0,0xb4)];
    SafeAllocator* unknown_b4_;
    SafeAllocator* unknown_b8_;
    char unknown_bc_[R(0xc0-0xa8,0xe0-0xbc)];
    char unknown_e0_[0x18];
    char unknown_f8_[R(0x7bc-0xd8,0x7f8-0xf8)];
    void* unknown_7f8_;
    void* unknown_7fc_;
    int unknown_800_;
    int unknown_804_;
    char unknown_808_[0x70];
    Object3D unknown_878_;
    char unknown_924_[0x2c8];
    char unknown_bec_[0xc58 - 0xbec];
    signed char unknown_c58_;
    unsigned char unknown_c59_;
    char unknown_c5a_[2];
    int unknown_c5c_[3];
    char unknown_c68_[0x70];
    Object3D unknown_cd8_;
    unsigned char unknown_d84_;
    unsigned char unknown_d85_;
    char unknown_d86_[2];
    Struct_ov005_0215840c_2* unknown_d88_;
    char unknown_d8c_[0xd96 - 0xd8c];
    short unknown_d96_;
    short unknown_d98_;
    char unknown_d9a_[2];
    unsigned int unknown_d9c_;
    signed char unknown_da0_[2];
    unsigned char unknown_da2_;
    unsigned char unknown_da3_;
};

// USA: func_ov009_02187b34
extern "C" ARM void func_ov009_02187b34(Struct_ov009_021842a0_2* arg0)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    Object3D* preview = func_ov023_021e6194(self->character_);
    unsigned int* unknown = GetDataPtr02114e04_020d6c00();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader == NULL)
        return;
    unsigned int var5 = var0->GetTickCount();
    if (var5 == 0)
        var5 = 1;
    func_ov023_021dac40(arg0, var5);
    if (func_ov009_0218a930(arg0, var5) > 0)
        return;

    switch (arg0->unknown_c59_)
    {
    case 0:
    {
        arg0->unknown_d9c_ &= ~1;
        arg0->unknown_804_ = 0x7a;
        arg0->unknown_d9c_ |= 8;
        Struct_ov009_0218aa28 var6 = data_ov009_0218aa28;
        Struct_ov009_0218aa28 var7 = data_ov009_0218aa34;
        func_0202ee38(arg0->unknown_924_, (int)&var6, 0x1e000);
        func_0202ee58(arg0->unknown_924_, (int)&var7, 0x1e000);
        arg0->unknown_d98_ = 90;
        arg0->unknown_d9c_ |= 0x10000;
        func_0209c678((Struct_02109bf4_4*)data_02109bf4, 120);
        arg0->unknown_c59_ = 1;
        int* var8 = arg0->unknown_c5c_;
        for (unsigned char var9 = 0; var9 < 3; var9++)
            *var8++ = -1;
        SafeAllocator* var10 = arg0->unknown_b8_;
        for (unsigned char var11 = 0; var11 < 2; var11++, var10++)
            var10->Reset();
        break;
    }
    case 1:
        if (arg0->unknown_d9c_ & 8)
            break;
        if (func_0202eeb4(arg0->unknown_924_) != 0)
            break;
        arg0->unknown_d9c_ |= 0x800000;
        if (func_ov023_021e6194(arg0->unknown_7f8_)->normalizedAnimationTime_ >= 0xccc)
        {
            func_0205ebc0(data_02108760, 0x6f, 0x6f);
            arg0->unknown_c59_ = 2;
        }
        break;
    case 2:
    {
        short var12 = arg0->unknown_da3_ * 100 + 2001;
        short var13 = arg0->unknown_da3_ * 100 + 2002;
        Struct_ov009_0218aa98 var14 = data_ov009_0218aa98;
        var14.unknown_0_[0].unknown_0_ = arg0->unknown_b8_;
        var14.unknown_0_[0].unknown_4_ = func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, var13);
        var14.unknown_0_[1].unknown_0_ = &arg0->unknown_b8_[1];
        var14.unknown_0_[1].unknown_4_ = func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, var12);
        var14.unknown_0_[2].unknown_0_ = arg0->unknown_b4_;
        var14.unknown_0_[2].unknown_4_ = func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 0x898);
        Struct_ov009_02187b34_2* var15 = var14.unknown_0_;
        const char* var16 = data_ov009_0218acd9;
        for (; var15->unknown_0_ != NULL; var15++)
        {
            int var17;
            if (var15->unknown_8_ == 2)
                var17 = var4->QueueLoadFile(var15->unknown_4_, var15->unknown_0_);
            else
                var17 = var4->QueueLoadFileInGP2(var16, var15->unknown_4_, var15->unknown_0_);
            arg0->unknown_c5c_[var15->unknown_8_] = var17;
        }
        arg0->unknown_c59_ = 3;
        break;
    }
    case 3:
    {
        int var18 = 1;
        int* var19 = arg0->unknown_c5c_;
        for (unsigned char var20 = 0; var20 < 3; var20++, var19++)
        {
            if (*var19 != -1 && var4->GetTaskStatus(*var19) == 0)
                var18 = 0;
        }
        if (var18)
            arg0->unknown_c59_ = 4;
        break;
    }
    case 4:
    {
        int* var21 = arg0->unknown_c5c_;
        for (unsigned char var22 = 0; var22 < 3; var22++, var21++)
        {
            if (*var21 == -1)
                continue;
            if (var4->GetTaskStatus(*var21) == 1)
            {
                unsigned int var23 = 0;
                void* var24 = NULL;
                var4->GetLoadedFileByID(*var21, &var24, &var23);
                ObjectArchiveLoadInfo var25;
                var25.unk_0 = 0;
                var25.allocator = NULL;
                var25.unk_14 = 0;
                var25.unk_18 = 0;
                var25.unk_10 = 0;
                var25.packageID = 0;
                var25.fileData = var24;
                var25.unk_8 = var23;
                switch (var22)
                {
                case 0:
                    var25.allocator = arg0->unknown_b8_;
                    var25.packageID = 1;
                    var2->LoadFromCHRArchive(&var25);
                    break;
                case 1:
                    var25.allocator = &arg0->unknown_b8_[1];
                    arg0->unknown_878_.LoadFromCHRArchive(&var25);
                    break;
                case 2:
                    var25.allocator = arg0->unknown_b4_;
                    func_0207df50((Struct_0203d028*)arg0->unknown_c68_);
                    func_0207df90(arg0->unknown_c68_);
                    arg0->unknown_cd8_.LoadFromCHRArchive(&var25);
                    func_0207dfac(arg0->unknown_c68_);
                    break;
                }
            }
            var4->RemoveTask(*var21);
            *var21 = -1;
        }
        arg0->unknown_c59_ = 5;
        var2->StopCurrentAnimation();
        var2->MaybeSetRegularAnimation(func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 2500), 0);
        Vector3fix var26;
        memset(&var26, 0, sizeof(var26));
        var26 = var2->rotation_;
        Struct_ov009_02187b34* var27 = &arg0->unknown_d88_->unknown_488_;
        int var28;
        int var29;
        short var30 = var27->unknown_18_;
        var28 = FX32_FROM_FLOAT(var30 / 4096.0f);
        var29 = FX32_FROM_FLOAT(var27->unknown_1a_ / 4096.0f);
        int var31 = FX32_FROM_FLOAT(var30 / 4096.0f);
#if defined(jpn)
        arg0->unknown_878_.SetScale(var28, var29, var31);
        arg0->unknown_878_.rotation_ = var26;
        arg0->unknown_878_.StopCurrentAnimation();
        arg0->unknown_878_.MaybeSetRegularAnimation(func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 2500), 0);
        Vector3fix var32;
        var32 = ((Object3D*)((char*)var2 + 0x408))->position_;
        arg0->unknown_cd8_.rotation_ = var26;
        arg0->unknown_cd8_.position_ = var32;
        arg0->unknown_cd8_.StopCurrentAnimation();
        arg0->unknown_cd8_.MaybeSetRegularAnimation(data_ov009_0218ad41, 0);
#else
        Object3D* var33 = &arg0->unknown_878_;
        var33->SetScale(var28, var29, var31);
        var33->rotation_ = var26;
        var33->StopCurrentAnimation();
        var33->MaybeSetRegularAnimation(func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 2500), 0);
        Vector3fix var34;
        var34 = ((Object3D*)((char*)var2 + 0x408))->position_;
        Object3D* var35 = &arg0->unknown_cd8_;
        var35->rotation_ = var26;
        var35->position_ = var34;
        var35->StopCurrentAnimation();
        var35->MaybeSetRegularAnimation(data_ov009_0218ad41, 0);
#endif
        arg0->unknown_d9c_ |= 0x200;
        arg0->unknown_d96_ = 30;
        arg0->unknown_c59_ = 6;
        break;
    }
    case 6:
        func_0205ebfc(data_02108760, 0, 0);
        arg0->unknown_d96_ = 150;
        arg0->unknown_c59_ = 7;
        break;
    case 7:
        func_020466e4(var3, 0x100);
        SetBrightness(var1, 16, 40);
        func_0205ebfc(data_02108760, 1, 0);
        arg0->unknown_c59_ = 8;
        break;
    case 8:
        if (IsBrightnessTransitionActive(var1))
            break;
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x1f, -16);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x1f, -16);
        arg0->unknown_d96_ = 120;
        arg0->unknown_c59_ = 9;
        break;
    case 9:
        if (arg0->unknown_d96_ > 0)
        {
            unsigned int var36 = var0->GetTickCount();
            if (var36 == 0)
                var36 = 1;
            arg0->unknown_d96_ -= var36;
            break;
        }
        SetBrightness(var1, -16, 120);
        arg0->unknown_c59_ = 10;
        break;
    case 10:
        if (IsBrightnessTransitionActive(var1))
            break;
        func_020c39a0(REG_MASTER_BRIGHT, -16);
        func_020c39a0(REG_MASTER_BRIGHT_SUB, -16);
        func_020466f4((Struct_02038598_4*)var3, 0x100);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x1f, 0);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x1f, 0);
        func_0205ebec(data_02108760);
        arg0->unknown_c59_ = 11;
        break;
    case 11:
        self->step_ = 0xff;
        CharacterCreationUI_SwitchTab((unsigned char*)self, 11);
        break;
    }
}
