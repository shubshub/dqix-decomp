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

struct Struct_02021b84
{
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    void* unknown_5c_;
};

struct Struct0205a198;
struct PacRecord;
struct BackgroundGraphics;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;
struct ClearTarget0205a234;


struct Struct_ov006_02158478
{
    void* unknown_0_;
    Struct_ov003_021594c4* unknown_4_;
    char unknown_8_[0xe0 - 8];
};

struct Struct_02081870_2
{
    char unknown_0_[0x98];
    Struct_ov003_021594c4* unknown_98_;
    int unknown_9c_;
    char unknown_a0_[0xb2 - 0xa0];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct Struct_ov006_021580b8
{
    char unknown_0_[0x22];
    unsigned char unknown_22_;
    char unknown_23_[0x28 - 0x23];
};

struct Struct_ov008_02188d74
{
    char unknown_0_[0x3c];
    void* unknown_3c_;
    Struct_ov006_021580b8* unknown_40_;
    char unknown_44_[4];
    unsigned int unknown_48_;
    short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned char unknown_50_;
    char unknown_51_[3];

    void inline_ov008_02188d74(Struct_ov006_021580b8* arg0, short arg1)
    {
        unknown_40_ = arg0;
        unknown_4c_ = arg1;
    }
};

struct Struct_ov005_0215840c_2
{
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov008_02187278
{
    char unknown_0_[0x16];
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_16_1_ : 4;
    unsigned char unknown_16_5_ : 3;
    unsigned char unknown_17_;
};

struct Struct_ov008_02188f5c_2
{
    char unknown_0_[0x38];
    Struct_ov008_02187278 unknown_38_;
};

struct Struct_ov008_021895a8
{
    unsigned char unknown_0_[2];
};

extern "C" void func_020728ac(void* texts, SafeAllocator* allocator, void* file, unsigned int size, int, int, int);
extern "C" void KeyTable_Load(void* texts, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" void Background_SetPriority(BackgroundGraphics* background, int);
extern "C" void Background_LoadFile(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_FillRect(BackgroundGraphics* background, int, int, int, int, int, int);
extern "C" void SpriteContext_LoadFile(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int a, int b, int c, int d);
extern "C" void func_ov008_0218b240(void* arg0);
extern "C" void func_ov008_0218aa24(void* arg0);

int FieldTaskQueue_IsEmpty(void** field);
unsigned int* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int* field, unsigned int bits);
MessageSystem* MessageSystem_GetInstance();
PartyMemberData* GetFieldAt0x150_02053c6c(unsigned char* member);
void Background_SetMapSize(unsigned char* background, int);
void Background_AllocateMap(BackgroundGraphics* background, SafeAllocator* allocator);
void Background_SetScroll(BackgroundGraphics* background, int, int);
void Background_UploadMap(BackgroundGraphics* background, void*);
void WindowPane_AllocateBuffer(WindowPane* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
void Window_SetPanes(Struct_0205cf78* window, WindowPane* canvases, unsigned char count);
void Sprite_Init(Struct0205a198* sprite);
void ClearField0And40205a234(ClearTarget0205a234* list);
void SpriteContext_Init(char* renderer);
int Pac_CountFiles(PacRecord* archive);
void* Pac_GetFile(PacRecord* archive, int index, void** name, int* size);

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
    char unknown_0_[0x10];
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned int unknown_14_;
    Struct_02081870_2 unknown_18_;
    Struct_ov003_021594c4 unknown_d4_[2];
    Struct_ov006_02158478 unknown_114_;
    Struct_ov008_02188d74* unknown_1f4_;
    Struct_ov006_021580b8* unknown_1f8_;
    void* unknown_1fc_;
    SafeAllocator unknown_200_;
    SafeAllocator unknown_214_;
    SafeAllocator unknown_228_;
    SafeAllocator unknown_23c_;
    SafeAllocator unknown_250_;
    SafeAllocator unknown_264_;
    char unknown_278_[8];
    char unknown_280_[8];
    char unknown_288_[0x18];
    char* unknown_2a0_;
    void* unknown_2a4_;
#if defined(jpn)
    char unknown_2a8_[0xb44];
#else
    char unknown1_2a8_[0xb48];
#endif
    char unknown_df0_[0x2c];
    char unknown_e1c_[0x7c];
    unsigned char unknown_e98_;
    signed char unknown_e99_;
    signed char unknown_e9a_;
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
    signed char unknown_eb9_;
    unsigned char unknown_eba_;
    unsigned char unknown_ebb_;
    Struct_ov008_02188f5c_2* unknown_ebc_;
    unsigned char unknown_ec0_0_ : 1;
    unsigned char unknown_ec0_1_ : 1;
    unsigned char unknown_ec0_2_ : 1;
    unsigned char unknown_ec0_3_ : 1;
    unsigned char unknown_ec0_4_ : 4;
    void* unknown_ec4_;
    unsigned int unknown_ec8_;
};

// USA: func_ov008_021895a8
extern "C" ARM void func_ov008_021895a8(Struct_ov008_02188f5c_3* arg0)
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
        GuestData* guest = self->guest_;
        if (guest == NULL)
        {
            GameObject* var6 = var0->GetPartyMemberByIndex(arg0->unknown_eb9_);
            if (var6 == NULL)
            {
                func_ov008_0218b240(arg0);
                return;
            }
            Struct_ov005_0215840c_2* var7 = func_02053c6c((unsigned char*)var6);
            if (var7 != NULL)
                var4 = var7->unknown_49c_0_;
        }
        else
        {
            var4 = var5->unknown_38_.unknown_16_0_;
        }
#if defined(jpn)
        char var8[0x40];
        sprintf(var8, data_ov008_0218b4c8, var4);
        arg0->unknown_ea0_ = var2->QueueLoadFile(data_ov008_0218b4f2, NULL);
        arg0->unknown_eb4_ = var2->QueueLoadFile(var8, NULL);
#else
        char var9[0x40];
        char var10[0x20];
        sprintf(var9, data_ov008_0218b4c8, var4);
        sprintf(var10, data_ov008_0218b4df, var4);
        arg0->unknown_ea0_ = var2->QueueLoadFileInGP2(data_ov008_0218b4f2, data_ov008_0218b508, NULL);
        arg0->unknown_eb4_ = var2->QueueLoadFileInGP2(var9, var10, NULL);
#endif
        arg0->unknown_ea4_ = var2->QueueLoadFile(data_ov008_0218b51a, NULL);
        arg0->unknown_ea8_ = var2->QueueLoadFile(data_ov008_0218b52d, NULL);
        arg0->unknown_e9a_++;
    }
    else if (var3 == 1)
    {
        if (var2->GetTaskStatus(arg0->unknown_ea0_))
        {
            void* var11;
            unsigned int var12;
            var2->GetLoadedFileByID(arg0->unknown_ea0_, &var11, &var12);
            arg0->unknown_214_.Reset();
            func_020728ac(&arg0->unknown_278_, &arg0->unknown_214_, var11, var12, 0, 0, 0);
            var2->RemoveTask(arg0->unknown_ea0_);
            arg0->unknown_ea0_ = -1;
            arg0->unknown_e9a_++;
        }
    }
    else if (var3 == 2)
    {
        if (var2->GetTaskStatus(arg0->unknown_eb4_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->titleTask_, &file, &size);
            self->titleAllocator_.Reset();
            KeyTable_Load(&self->titles_, &self->titleAllocator_, file, size);
            self->titlesLoaded_ = 1;
            loader->RemoveTask(self->titleTask_);
            self->titleTask_ = -1;
            self->allocator_.Reset();
            unsigned char layers[2];
            unsigned char priorities[2];
            *(Bytes2*)layers = *(Bytes2*)&data_ov008_0218b3b8[2];
            *(Bytes2*)priorities = *(Bytes2*)&data_ov008_0218b3b8[0];
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
            arg0->unknown_e9a_++;
        }
    }
    else if (var3 == 3)
    {
        if (var2->GetTaskStatus(arg0->unknown_ea4_))
        {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            loader->GetLoadedFileByID(self->backgroundTask_, &archive, &archiveSize);
            int count = Pac_CountFiles((PacRecord*)archive);
            for (int i = 0; i < count; i++)
            {
                unsigned int size;
                void* file = Pac_GetFile((PacRecord*)archive, i, (void**)name, (int*)&size);
                if (file != NULL)
                    Background_LoadFile(&self->backgrounds_[1], file, &self->allocator_, size);
            }
            var2->RemoveTask(arg0->unknown_ea4_);
            arg0->unknown_ea4_ = -1;
            Struct_ov003_021594c4* var26;
            for (int var27 = 0; var27 < 2; var27++)
            {
                background = &self->backgrounds_[i];
                Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics*)background, 0);
            }
            self->pixels_ = self->allocator_.Allocate(0x800);
            WindowPane_AllocateBuffer((WindowPane*)&self->canvas_, &self->allocator_, (int)self->pixels_, 0x100);
            self->canvas_.background_ = &self->backgrounds_[1];
            self->window_.background_ = &self->backgrounds_[0];
            self->window_.unk_b2 = 2;
            Window_SetPanes((Struct_0205cf78*)&self->window_, (WindowPane*)&self->canvas_, 1);
            for (unsigned char i = 0; i < 8; i++)
            {
                int offset = i * sizeof(Sprite);
                Sprite_Init((Struct0205a198*)((char*)self->sprites_ + offset));
                ((Sprite*)((char*)self->sprites_ + offset))->unk_22 = i + 4;
            }
            ClearField0And40205a234((ClearTarget0205a234*)self->animations_);
            SpriteContext_Init((char*)self->renderer_);
            self->renderer_->unk_50 = 0;
            SpriteRenderer* renderer = self->renderer_;
            renderer->SetSprites(self->sprites_, 8);
            self->renderer_->animations_ = self->animations_;
            self->step_++;
        }
    }
    else if (var3 == 4)
    {
        if (var2->GetTaskStatus(arg0->unknown_ea8_))
        {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            loader->GetLoadedFileByID(self->spriteTask_, &archive, &archiveSize);
            int count = Pac_CountFiles((PacRecord*)archive);
            self->spriteAllocator_.Reset();
            for (int i = 0; i < count; i++)
            {
                unsigned int size;
                SpriteContext_LoadFile(self->renderer_, Pac_GetFile((PacRecord*)archive, i, (void**)name, (int*)&size), size, &self->spriteAllocator_);
            }
            var2->RemoveTask(arg0->unknown_ea8_);
            arg0->unknown_ea8_ = -1;
            REG_BG0CNT = (REG_BG0CNT & ~3) | 2;
            REG_BG1CNT = (REG_BG1CNT & ~3) | 1;
            REG_BG2CNT = REG_BG2CNT & ~3;
            REG_BG3CNT = (REG_BG3CNT & ~3) | 3;
            REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x1700;
            BlankFunction02094b34(FontBankLoader_GetInstance(), 0x6b, 0x206, 0, 0);
            self->step_++;
        }
    }
    else if (var3 == 5)
    {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()))
        {
            func_ov008_0218aa24(arg0);
#if defined(jpn)
            arg0->unknown_eac_ = var2->QueueLoadFile(data_ov008_0218b544, NULL);
#else
            arg0->unknown_eac_ = var2->QueueLoadFileInGP2(data_ov008_0218b544, data_ov008_0218b559, NULL);
            arg0->unknown_eb0_ = var2->QueueLoadFileInGP2(data_ov008_0218b56a, data_ov008_0218b57f, NULL);
#endif
            arg0->unknown_e99_ = 1;
            arg0->unknown_e9a_ = 0;
        }
    }
}
