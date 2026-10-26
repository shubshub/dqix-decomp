#include <globaldefs.h>
#include "Graphics/Background.h"
#include "Resource/FontBankLoader.h"

#if defined(jpn)
#define func_ov008_021895a8 func_ov008_0218a2b0
#endif
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)
#define REG_BG0CNT (*(volatile unsigned short*)0x04000008)
#define REG_BG1CNT (*(volatile unsigned short*)0x0400000a)
#define REG_BG2CNT (*(volatile unsigned short*)0x0400000c)
#define REG_BG3CNT (*(volatile unsigned short*)0x0400000e)
#define REG_BLDCNT 0x04000050

struct MessageSystem
{
#if defined(jpn)
    char unk_0[0x28];
#else
    char unk_0[0x5c];
#endif
    void* unk_5c;
};

struct Struct0205a198;
struct PacRecord;
struct BackgroundGraphics;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;
struct ClearTarget0205a234;


struct Canvas
{
    void* unk_0;
    BackgroundGraphics* background_;
    char unk_8[0xe0 - 8];
};

struct TextWindow
{
    char unk_0[0x98];
    BackgroundGraphics* background_;
    int unknown_9c_;
    char unknown_a0_[0xb2 - 0xa0];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct Sprite
{
    char unk_0[0x22];
    unsigned char unk_22;
    char unknown_23_[0x28 - 0x23];
};

struct SpriteRenderer
{
    char unk_0[0x3c];
    void* animations_;
    Sprite* sprites_;
    char unknown_44_[4];
    unsigned int unknown_48_;
    short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned char unk_50;
    char unknown_51_[3];

    void SetSprites(Sprite* sprites, short arg1)
    {
        sprites_ = sprites;
        unknown_4c_ = arg1;
    }
};

struct PartyMemberData
{
    char unk_0[0x49c];
    unsigned char female_ : 1;
};

struct Struct_ov008_02187278
{
    char unk_0[0x16];
    unsigned char female_ : 1;
    unsigned char unknown_16_1_ : 4;
    unsigned char unknown_16_5_ : 3;
    unsigned char unknown_17_;
};

struct Struct_ov008_02188f5c_2
{
    char unk_0[0x38];
    Struct_ov008_02187278 unknown_38_;
};

struct Struct_ov008_021895a8
{
    unsigned char b[2];
};

extern "C" void func_020728ac(void* texts, SafeAllocator* allocator, void* file, unsigned int size, int, int, int);
extern "C" void KeyTable_Load(void* texts, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" void Background_SetPriority(BackgroundGraphics* background, int);
extern "C" void Background_LoadFile(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_FillRect(BackgroundGraphics* background, int, int, int, int, int, int);
extern "C" void SpriteContext_LoadFile(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int a, int b, int c, int d);
extern "C" void func_ov008_0218b240(void* self);
extern "C" void func_ov008_0218aa24(void* self);

extern "C" int FieldTaskQueue_IsEmpty(void** field);
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int* field, unsigned int bits);
extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" PartyMemberData* func_02053c6c(unsigned char* member);
extern "C" void Background_SetMapSize(unsigned char* background, int);
extern "C" void Background_AllocateMap(BackgroundGraphics* background, SafeAllocator* allocator);
extern "C" void Background_SetScroll(BackgroundGraphics* background, int, int);
extern "C" void Background_UploadMap(BackgroundGraphics* background, void*);
extern "C" void WindowPane_AllocateBuffer(WindowPane* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
extern "C" void Window_SetPanes(Struct_0205cf78* window, WindowPane* canvases, unsigned char count);
extern "C" void Sprite_Init(Struct0205a198* sprite);
extern "C" void func_0205a234(ClearTarget0205a234* list);
extern "C" void SpriteContext_Init(char* renderer);
extern "C" int Pac_CountFiles(PacRecord* archive);
extern "C" void* Pac_GetFile(PacRecord* archive, int index, void** name, int* size);

extern char data_ov008_0218b4c8[];
extern char data_ov008_0218b4df[];
extern char data_ov008_0218b4f2[];
extern char data_ov008_0218b508[];
extern char data_ov008_0218b51a[];
extern char data_ov008_0218b52d[];
extern char data_ov008_0218b544[];
extern char data_ov008_0218b559[];
extern char data_ov008_0218b56a[];
extern char data_ov008_0218b57f[];
extern const unsigned char data_ov008_0218b3b8[4];

struct Struct_ov008_02188f5c_3
{
    char unk_0[0x10];
    unsigned char unk_10;
    unsigned char unknown_11_;
    unsigned int layers_;
    TextWindow window_;
    BackgroundGraphics backgrounds_[2];
    Canvas canvas_;
    SpriteRenderer* renderer_;
    Sprite* sprites_;
    void* animations_;
    SafeAllocator allocator_;
    SafeAllocator textAllocator_;
    SafeAllocator unknown_228_;
    SafeAllocator spriteAllocator_;
    SafeAllocator unknown_250_;
    SafeAllocator titleAllocator_;
    char texts_[8];
    char unknown_280_[8];
    char titles_[0x18];
    char* text_;
    void* pixels_;
#if defined(jpn)
    char unknown_2a8_[0xb44];
#else
    char unknown1_2a8_[0xb48];
#endif
    char entry_[0x2c];
    char unknown_e1c_[0x7c];
    unsigned char unknown_e98_;
    signed char state_;
    signed char step_;
    signed char unknown_e9b_;
    signed char unknown_e9c_;
    int unknown_ea0_;
    int unknown_ea4_;
    int unknown_ea8_;
    int unknown_eac_;
#if !defined(jpn)
    int unknown_eb0_;
#endif
    int unknown_eb4_;
    unsigned char unknown_eb8_;
    signed char member_;
    unsigned char unknown_eba_;
    unsigned char unknown_ebb_;
    Struct_ov008_02188f5c_2* unknown_ebc_;
    unsigned char active_ : 1;
    unsigned char unknown_ec0_1_ : 1;
    unsigned char unknown_ec0_2_ : 1;
    unsigned char unknown_ec0_3_ : 1;
    unsigned char unknown_ec0_4_ : 4;
    void* unknown_ec4_;
    unsigned int unknown_ec8_;
};

// USA: func_ov008_021895a8
extern "C" ARM void func_ov008_021895a8(Struct_ov008_02188f5c_3* self)
{
    GameState* gameState = GameState::GetInstance();
    char* resources = (char*)gameState->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    FontBankLoader_GetInstance();
    signed char step = self->step_;
    if (step == 0)
    {
        if (!FieldTaskQueue_IsEmpty(*(void***)(resources
#if defined(jpn)
            + 0x34f0)))
#else
            + 0x3700)))
#endif
            return;
        SetFlags00(GetGameResources(), 0x10);
        FlagWord_SetBits(GlobalFlags_GetInstance(), 0xd);
        unsigned int female;
        self->text_ = (char*)MessageSystem_GetInstance()->unk_5c;
        female = 0;
        Struct_ov008_02188f5c_2* var5 = self->unknown_ebc_;
        if (var5 == NULL)
        {
            GameObject* member = gameState->GetPartyMemberByIndex(self->member_);
            if (member == NULL)
            {
                func_ov008_0218b240(self);
                return;
            }
            PartyMemberData* data = func_02053c6c((unsigned char*)member);
            if (data != NULL)
                female = data->female_;
        }
        else
        {
            female = var5->unknown_38_.female_;
        }
#if defined(jpn)
        char gp2[0x40];
        sprintf(gp2, data_ov008_0218b4c8, female);
        self->unknown_ea0_ = loader->QueueLoadFile(data_ov008_0218b4f2, NULL);
        self->unknown_eb4_ = loader->QueueLoadFile(gp2, NULL);
#else
        char gp2[0x40];
        char inner[0x20];
        sprintf(gp2, data_ov008_0218b4c8, female);
        sprintf(inner, data_ov008_0218b4df, female);
        self->unknown_ea0_ = loader->QueueLoadFileInGP2(data_ov008_0218b4f2, data_ov008_0218b508, NULL);
        self->unknown_eb4_ = loader->QueueLoadFileInGP2(gp2, inner, NULL);
#endif
        self->unknown_ea4_ = loader->QueueLoadFile(data_ov008_0218b51a, NULL);
        self->unknown_ea8_ = loader->QueueLoadFile(data_ov008_0218b52d, NULL);
        self->step_++;
    }
    else if (step == 1)
    {
        if (loader->GetTaskStatus(self->unknown_ea0_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->unknown_ea0_, &file, &size);
            self->textAllocator_.Reset();
            func_020728ac(&self->texts_, &self->textAllocator_, file, size, 0, 0, 0);
            loader->RemoveTask(self->unknown_ea0_);
            self->unknown_ea0_ = -1;
            self->step_++;
        }
    }
    else if (step == 2)
    {
        if (loader->GetTaskStatus(self->unknown_eb4_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->unknown_eb4_, &file, &size);
            self->titleAllocator_.Reset();
            KeyTable_Load(&self->titles_, &self->titleAllocator_, file, size);
            self->unknown_ec0_2_ = 1;
            loader->RemoveTask(self->unknown_eb4_);
            self->unknown_eb4_ = -1;
            self->allocator_.Reset();
            unsigned char layers[2];
            unsigned char priorities[2];
            *(Struct_ov008_021895a8*)layers = *(Struct_ov008_021895a8*)&data_ov008_0218b3b8[2];
            *(Struct_ov008_021895a8*)priorities = *(Struct_ov008_021895a8*)&data_ov008_0218b3b8[0];
            BackgroundGraphics* background;
            for (int i = 0; i < 2; i++)
            {
                background = &self->backgrounds_[i];
                Background_SetMapSize((unsigned char*)background, 0);
                background->subScreen_ = 0;
                background->bgNumber_ = layers[i];
                Background_SetPriority(background, priorities[i]);
                Background_AllocateMap((BackgroundGraphics*)background, &self->allocator_);
                Background_SetScroll((BackgroundGraphics*)background, 0, 0);
            }
            REG_BG1CNT = (REG_BG1CNT & 0x43) | 0x1d00;
            REG_BG2CNT = (REG_BG2CNT & 0x43) | 0x1e00;
            ColorEffect_ConfigureAlphaBlend((void*)REG_BLDCNT, 2, 1, 10, 6);
            self->step_++;
        }
    }
    else if (step == 3)
    {
        if (loader->GetTaskStatus(self->unknown_ea4_))
        {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            loader->GetLoadedFileByID(self->unknown_ea4_, &archive, &archiveSize);
            int count = Pac_CountFiles((PacRecord*)archive);
            for (int i = 0; i < count; i++)
            {
                unsigned int size;
                void* file = Pac_GetFile((PacRecord*)archive, i, (void**)name, (int*)&size);
                if (file != NULL)
                    Background_LoadFile(&self->backgrounds_[1], file, &self->allocator_, size);
            }
            loader->RemoveTask(self->unknown_ea4_);
            self->unknown_ea4_ = -1;
            BackgroundGraphics* background;
            for (int i = 0; i < 2; i++)
            {
                background = &self->backgrounds_[i];
                Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics*)background, 0);
            }
            self->pixels_ = self->allocator_.Allocate(0x800);
            WindowPane_AllocateBuffer((WindowPane*)&self->canvas_, &self->allocator_, (int)self->pixels_, 0x100);
            self->canvas_.background_ = &self->backgrounds_[1];
            self->window_.background_ = &self->backgrounds_[0];
            self->window_.unknown_b2_ = 2;
            Window_SetPanes((Struct_0205cf78*)&self->window_, (WindowPane*)&self->canvas_, 1);
            for (unsigned char i = 0; i < 8; i++)
            {
                int offset = i * sizeof(Sprite);
                Sprite_Init((Struct0205a198*)((char*)self->sprites_ + offset));
                ((Sprite*)((char*)self->sprites_ + offset))->unk_22 = i + 4;
            }
            func_0205a234((ClearTarget0205a234*)self->animations_);
            SpriteContext_Init((char*)self->renderer_);
            self->renderer_->unk_50 = 0;
            SpriteRenderer* renderer = self->renderer_;
            renderer->SetSprites(self->sprites_, 8);
            self->renderer_->animations_ = self->animations_;
            self->step_++;
        }
    }
    else if (step == 4)
    {
        if (loader->GetTaskStatus(self->unknown_ea8_))
        {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            loader->GetLoadedFileByID(self->unknown_ea8_, &archive, &archiveSize);
            int count = Pac_CountFiles((PacRecord*)archive);
            self->spriteAllocator_.Reset();
            for (int i = 0; i < count; i++)
            {
                unsigned int size;
                SpriteContext_LoadFile(self->renderer_, Pac_GetFile((PacRecord*)archive, i, (void**)name, (int*)&size), size, &self->spriteAllocator_);
            }
            loader->RemoveTask(self->unknown_ea8_);
            self->unknown_ea8_ = -1;
            REG_BG0CNT = (REG_BG0CNT & ~3) | 2;
            REG_BG1CNT = (REG_BG1CNT & ~3) | 1;
            REG_BG2CNT = REG_BG2CNT & ~3;
            REG_BG3CNT = (REG_BG3CNT & ~3) | 3;
            REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x1700;
            func_02094b34(FontBankLoader_GetInstance(), 0x6b, 0x206, 0, 0);
            self->step_++;
        }
    }
    else if (step == 5)
    {
        if (func_02094b4c(FontBankLoader_GetInstance()))
        {
            func_ov008_0218aa24(self);
#if defined(jpn)
            self->unknown_eac_ = loader->QueueLoadFile(data_ov008_0218b544, NULL);
#else
            self->unknown_eac_ = loader->QueueLoadFileInGP2(data_ov008_0218b544, data_ov008_0218b559, NULL);
            self->unknown_eb0_ = loader->QueueLoadFileInGP2(data_ov008_0218b56a, data_ov008_0218b57f, NULL);
#endif
            self->state_ = 1;
            self->step_ = 0;
        }
    }
}
