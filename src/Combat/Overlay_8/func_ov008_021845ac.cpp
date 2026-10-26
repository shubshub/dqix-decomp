#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Graphics/Background.h"
#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <Filesystem/BackgroundLoader.h>

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_01ff8b48_13 {
    char unknown_0_[0x18];
};


struct Struct_02081870_2 {
    char unknown_0_[0xbc];
};

struct Struct_ov006_02158478 {
    char unknown_0_[0xe0];
};

struct Struct_ov009_02186e00_2 {
    int unknown_0_[0x10];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    SafeAllocator unknown_8c_;
    Struct_01ff8b48_13 unknown_a0_;
    char* unknown_b8_;
    char unknown_bc_[0x14];
    Struct_ov003_021594c4 unknown_d0_[3];
    Struct_02081870_2 unknown_130_;
    Struct_ov006_02158478 unknown_1ec_[6];
    void* unknown_72c_;
    void* unknown_730_;
    void* unknown_734_;
    void* unknown_738_;
    void* unknown_73c_;
    void* unknown_740_;
    unsigned char unknown_744_[8];
    unsigned char unknown_74c_;
    Struct_ov009_02186e00_2 unknown_750_;
    Object3D unknown_790_;
    char unknown_83c_[0x2c8];
    void* unknown_b04_;
    void* unknown_b08_;
    void* unknown_b0c_;
    signed char unknown_b10_;
    unsigned char unknown_b11_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int unknown_b18_;
    int unknown_b1c_;
    int unknown_b20_;
    int unknown_b24_;
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int unknown_b2c_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
    void* unknown_b3c_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

struct Struct_02021b84 {
    char unknown_0_[R(0x228, 0x2d8)];
    void* unknown_2d8_;
    void* unknown_2dc_;
    void* unknown_2e0_;
};

struct CombatSlots02045cac;
struct BackgroundGraphics;
struct FlagWord020466f4;

void SpriteContext_Destroy(void* renderer);
MessageSystem* MessageSystem_GetInstance();
void MessageSystem_ResetGlyphs(CombatSlots02045cac* messages);
void MessageSystem_Reset(char* messages);
void Background_ClearMap(BackgroundGraphics* background, void* value);
void Background_Destroy(BackgroundGraphics* background);
void SetFlagBytes02017d68(void* unused);
void* GlobalFlags_GetInstance();
void FlagWord_ClearBits(FlagWord020466f4* field, unsigned int bits);

extern "C" {
void func_ov023_021eb26c(void* guide);
void MessageSystem_Stop(MessageSystem* messages);
void Background_FlushMap(BackgroundGraphics* background, int value);
void Background_TransferMap(BackgroundGraphics* background, int value);
unsigned int GetMainBGAssignedVRAMSize();
void MIi_CpuClearFast(int value, void* destination, unsigned int size);
void Window_Destroy(TextWindow* window);
void* Zone3D_GetInstance();
}

// USA: func_ov008_021845ac
extern "C" ARM void func_ov008_021845ac(Struct_ov008_021842a0_2* arg0)
{
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_b20_ >= 0)
    {
        var0->RemoveTask(arg0->unknown_b20_);
        arg0->unknown_b20_ = -1;
    }
    if (self->renderer_ != NULL)
        SpriteContext_Destroy(self->renderer_);
    if (self->iconRenderer_ != NULL)
        SpriteContext_Destroy(self->iconRenderer_);
    if (self->guide_ != NULL)
        func_ov023_021eb26c(self->guide_);
    MessageSystem* messages = MessageSystem_GetInstance();
    MessageSystem_ResetGlyphs((CombatSlots02045cac*)messages);
    MessageSystem_Reset((char*)messages);
    MessageSystem_Stop(messages);
    messages->unk_2d8 = NULL;
    messages->unk_2dc = NULL;
    messages->unk_2e0 = NULL;
    BackgroundGraphics* backgrounds[3] = {&self->backgrounds_[0], &self->backgrounds_[1], &self->backgrounds_[2]};
    for (int i = 0; i < 3; i++)
    {
        BackgroundGraphics* background = backgrounds[i];
        Background_ClearMap((BackgroundGraphics*)background, 0);
        Background_FlushMap(background, 0);
        Background_TransferMap(background, 0);
        Background_Destroy((BackgroundGraphics*)background);
    }
    MIi_CpuClearFast(0, (void*)0x06000000, GetMainBGAssignedVRAMSize());
    Window_Destroy(&self->window_);
    self->model_.Destroy();
    self->text_ = NULL;
    self->pixels_ = NULL;
    SafeAllocator* allocators[8] = {&self->allocator_,      &self->backgroundAllocator_, &self->textAllocator_,
                                    &self->spriteAllocator_, &self->iconAllocator_,       &self->modelAllocator_,
                                    &self->titleAllocator_,  &self->guideAllocator_};
    for (int i = 0; i < 7; i++)
        allocators[i]->Destroy();
    if (self->exit_ == 0)
    {
        if (arg0->unknown_b24_ == 0)
        {
            SetFlagBytes02017d68(Zone3D_GetInstance());
        }
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0xf);
    }
}
