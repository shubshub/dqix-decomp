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

struct TextTable {
    char unknown_0_[0x18];
};


struct TextWindow {
    char unknown_0_[0xbc];
};

struct Canvas {
    char unknown_0_[0xe0];
};

struct WindowCursor {
    int unknown_0_[0x10];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator allocator_;
    SafeAllocator unknown_14_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator unknown_8c_;
    TextTable texts_;
    char* text_;
    char unknown_bc_[0x14];
    BackgroundGraphics backgrounds_[3];
    TextWindow window_;
    Canvas canvases_[6];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char unknown_74c_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* unknown_b08_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int flags_;
    int unknown_b1c_;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int titleX_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
    void* guestTitles_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

struct MessageSystem {
    char unknown_0_[R(0x228, 0x2d8)];
    void* unknown_2d8_;
    void* unk_2dc;
    void* unknown_2e0_;
};

struct CombatSlots02045cac;
struct BackgroundGraphics;
struct FlagWord020466f4;

extern "C" void SpriteContext_Destroy(void* renderer);
extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" void MessageSystem_ResetGlyphs(CombatSlots02045cac* messages);
extern "C" void MessageSystem_Reset(char* messages);
extern "C" void Background_ClearMap(BackgroundGraphics* background, void* value);
extern "C" void Background_Destroy(BackgroundGraphics* background);
extern "C" void func_02017d68(void* unused);
extern "C" void* GlobalFlags_GetInstance();
extern "C" void FlagWord_ClearBits(FlagWord020466f4* field, unsigned int bits);

extern "C" {
void func_ov023_021eb26c(void* arg0);
void MessageSystem_Stop(MessageSystem* messages);
void Background_FlushMap(BackgroundGraphics* background, int value);
void Background_TransferMap(BackgroundGraphics* background, int value);
unsigned int GetMainBGAssignedVRAMSize();
void MIi_CpuClearFast(int value, void* destination, unsigned int size);
void Window_Destroy(TextWindow* window);
void* Zone3D_GetInstance();
}

// USA: func_ov008_021845ac
extern "C" ARM void func_ov008_021845ac(Struct_ov008_021842a0_2* self)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task_ >= 0)
    {
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    if (self->renderer_ != NULL)
        SpriteContext_Destroy(self->renderer_);
    if (self->iconRenderer_ != NULL)
        SpriteContext_Destroy(self->iconRenderer_);
    if (self->unknown_b08_ != NULL)
        func_ov023_021eb26c(self->unknown_b08_);
    MessageSystem* messages = MessageSystem_GetInstance();
    MessageSystem_ResetGlyphs((CombatSlots02045cac*)messages);
    MessageSystem_Reset((char*)messages);
    MessageSystem_Stop(messages);
    messages->unknown_2d8_ = NULL;
    messages->unk_2dc = NULL;
    messages->unknown_2e0_ = NULL;
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
    SafeAllocator* allocators[8] = {&self->allocator_,      &self->unknown_14_, &self->textAllocator_,
                                    &self->spriteAllocator_, &self->iconAllocator_,       &self->modelAllocator_,
                                    &self->titleAllocator_,  &self->unknown_8c_};
    for (int i = 0; i < 7; i++)
        allocators[i]->Destroy();
    if (self->unknown_b13_ == 0)
    {
        if (self->mode_ == 0)
        {
            func_02017d68(Zone3D_GetInstance());
        }
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0xf);
    }
}
