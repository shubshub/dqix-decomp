#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
extern char data_ov013_02188de0[];
extern char data_ov013_02188dfa[];
#define data_ov013_02187db8 data_ov013_02188ce0
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "GameState/GameState.h"

extern "C" void SpriteContext_Init(char* renderer);
struct Struct0205a198;
extern "C" void Sprite_Init(Struct0205a198* sprite);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord* pac);
extern "C" void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void SpriteContext_LoadFile(void* renderer, void* file, unsigned int size, SafeAllocator* allocator);
extern "C" void func_020728ac(void* texts, SafeAllocator* allocator, void* file, unsigned int size, int, int, int);
struct Struct_0208df10;
extern "C" void func_0208df10(Struct_0208df10* table);
extern "C" void* func_02053c6c(unsigned char* member);
extern "C" signed char func_020dd11c(unsigned int vocation, unsigned int index);
struct Struct_0208df20;
extern "C" void func_0208df20(Struct_0208df20* table, void* allocator, int file, int size, int arg4, void* count);
struct BackgroundGraphics;
extern "C" void Background_Init(BackgroundGraphics* graphics);
extern "C" void Background_SetPriority(void* graphics, int priority);
extern "C" void Background_SetMapSize(unsigned char* graphics, int value);
extern "C" void Background_SetScroll(BackgroundGraphics* graphics, int a, int b);
extern "C" void Background_AllocateMap(BackgroundGraphics* graphics, SafeAllocator* allocator);
extern "C" void Background_AllocateScreens(BackgroundGraphics* graphics, int count, SafeAllocator* allocator);
extern "C" void WindowPane_Init(void* canvas);
extern "C" void func_ov013_02187a58(void* self, void* canvas);
extern "C" void Background_LoadFile(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void* Background_GetScreen(BackgroundGraphics* graphics, unsigned int index);
struct Struct_0204ae44;
extern "C" void func_0204ae44(Struct_0204ae44* layer, int member);
struct Struct_0204b988;
extern "C" void func_0204b988(Struct_0204b988* graphics, unsigned int a, int b, int c, unsigned short d);
extern "C" void Background_UploadMap(BackgroundGraphics* graphics, void* characters);
extern "C" void func_020dc7e8(int a, int b);

extern char data_ov013_02187e48[];
extern char data_ov013_02187e61[];
extern char data_ov013_02187e77[];
extern char data_ov013_02187e89[];
extern char data_ov013_02187e9e[];
extern char data_ov013_02187eaf[];
extern const unsigned char data_ov013_02187db8[2];

#define BLDCNT (*(volatile unsigned short*)0x04000050)
#define BLDCNTSUB (*(volatile unsigned short*)0x04001050)

struct Struct_ov013_021870f0 {
    char unk_0[0x28];
};

struct Struct_ov013_021870f0_2 {
    char unk_0[0x40];
    Struct_ov013_021870f0* sprites_;
    char unknown_44_[4];
    unsigned int unknown_48_;
    short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned char unk_50;
    char unknown_51_[3];
};

struct Struct_ov013_021870f0_3 {
    char unk_0[0x1c];
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;
    char unknown_1e_[2];
};

struct Struct_ov013_021870f0_4 {
    void* unk_0;
    void* background_;
    void* pixels_;
    char unk_c[0xa8 - 0xc];
    short width_;
    short height_;
    char unk_ac[0xb4 - 0xac];
    short unknown_b4_;
    short unknown_b6_;
    char unk_b8[0xe0 - 0xb8];
};

struct Struct_ov013_021870f0_5 {
#if defined(jpn)
    char unk_0[0x8b8];
#else
    char unk_0[0x950];
#endif
    int vocation_;
};

struct Struct_ov013_021870f0_6 {
    SafeAllocator* allocators_;
    char names_[8];
    char abilities_[8];
    char unk_14[0x10];
    unsigned char unk_24;
    unsigned char unknown_25_;
    char unknown_26_[2];
    Struct_ov013_021870f0_3 background_;
#if !defined(jpn)
    Struct_ov013_021870f0_2* spriteRenderer_;
    Struct_ov013_021870f0* sprites_;
    short* unknown_50_;
    short* unknown_54_;
    unsigned char* unknown_58_;
#endif
    int task_;
    unsigned int unknown_60_;
    unsigned char screen_;
    bool loaded_;
    unsigned char step_;
    signed char member_;
};

// USA: func_ov013_021870f0
extern "C" ARM bool func_ov013_021870f0(Struct_ov013_021870f0_6* self) {
    SafeAllocator* allocators;
    if (self->loaded_)
        return true;
    bool result = true;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->step_ == 0)
    {
#if defined(jpn)
        FontBankLoader* manager = FontBankLoader_GetInstance();
        func_02094b3c(manager, 10);
        func_02094b30(manager, 0x68, 0);
#else
        SafeAllocator* allocators = self->allocators_;
        allocators[4].Reset();
        self->spriteRenderer_ = (Struct_ov013_021870f0_2*)allocators[4].Allocate(sizeof(Struct_ov013_021870f0_2));
        self->sprites_ = (Struct_ov013_021870f0*)allocators[4].Allocate(13 * sizeof(Struct_ov013_021870f0));
        self->unknown_50_ = (short*)allocators[4].Allocate(13 * sizeof(short));
        self->unknown_54_ = (short*)allocators[4].Allocate(13 * sizeof(short));
        self->unknown_58_ = (unsigned char*)allocators[4].Allocate(13);
        SpriteContext_Init((char*)self->spriteRenderer_);
        self->spriteRenderer_->unk_50 = self->screen_;
        Struct_ov013_021870f0_2* renderer = self->spriteRenderer_;
        renderer->sprites_ = self->sprites_;
        renderer->unknown_4c_ = 13;
        for (int i = 0; i < 13; i++)
        {
            Sprite_Init((Struct0205a198*)&self->sprites_[i]);
        }
        for (int i = 0; i < 10; i++)
        {
            self->unknown_50_[i] = -1;
            self->unknown_54_[i] = -1;
            self->unknown_58_[i] = 2;
        }
        self->task_ = loader->QueueLoadFile(data_ov013_02187e48, NULL);
#endif
        result = false;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
#if defined(jpn)
        if (func_02094b4c(FontBankLoader_GetInstance())) {
            self->step_++;
        }
#else
        if (loader->GetTaskStatus(self->task_))
        {
            SafeAllocator* allocators = self->allocators_;
            void* name;
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int numFiles = Pac_CountFiles((PacRecord*)file);
            for (int i = 0; i < numFiles; i++)
            {
                unsigned int dataSize;
                void* data = Pac_GetFile((PacRecord*)file, i, &name, (int*)&dataSize);
                SpriteContext_LoadFile(self->spriteRenderer_, data, dataSize, &allocators[4]);
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
#endif
        result = false;
    }
    else if (self->step_ == 2)
    {
        loader->FreeAllocations();
#if defined(jpn)
        self->task_ = loader->QueueLoadFile(data_ov013_02188de0, NULL);
#else
        self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e61, data_ov013_02187e77, NULL);
#endif
        result = false;
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            SafeAllocator* allocators = self->allocators_;
            allocators[3].Reset();
            func_020728ac(self->names_, &allocators[3], file, size, 0, 0, 0);
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
        result = false;
    }
    else if (self->step_ == 4)
    {
        func_0208df10((Struct_0208df10*)self->abilities_);
        loader->FreeAllocations();
#if defined(jpn)
        self->task_ = loader->QueueLoadFile(data_ov013_02188dfa, NULL);
#else
        self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e89, data_ov013_02187e9e, NULL);
#endif
        result = false;
        self->step_++;
    }
    else if (self->step_ == 5)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            SafeAllocator* allocators = self->allocators_;
            allocators[2].Reset();
            short* var22 = NULL;
            short var23[5] = {};
            GameObject* member = func_0200ff1c(GameState::GetInstance(), self->member_);
            if (member != NULL)
            {
                Struct_ov013_021870f0_5* data = (Struct_ov013_021870f0_5*)func_02053c6c((unsigned char*)member);
                if (data != NULL)
                {
                    for (unsigned char i = 0; i < 5; i++)
                    {
                        var23[i] = func_020dd11c((unsigned char)data->vocation_, i);
                    }
                    var22 = var23;
                }
            }
            func_0208df20((Struct_0208df20*)self->abilities_, &allocators[2], (int)file, size, (int)var22, (void*)5);
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
        result = false;
    }
    else if (self->step_ == 6)
    {
        SafeAllocator* allocator = self->allocators_;
        allocator->Reset();
        unsigned char palettes[2];
        palettes[0] = data_ov013_02187db8[0];
        palettes[1] = data_ov013_02187db8[1];
        Background_Init((BackgroundGraphics*)&self->background_);
        self->background_.subScreen_ = self->screen_;
        self->background_.bgNumber_ = palettes[self->screen_];
        Background_SetPriority(&self->background_, 0);
        Background_SetMapSize((unsigned char*)&self->background_, 0);
        Background_SetScroll((BackgroundGraphics*)&self->background_, 0, 0);
        Background_AllocateMap((BackgroundGraphics*)&self->background_, allocator);
        Background_AllocateScreens((BackgroundGraphics*)&self->background_, 1, allocator);
        if (self->screen_ == 0)
        {
            DISPCNT = (DISPCNT & ~0x1f00) | 0x1200;
            BLDCNT = 0;
        }
        else
        {
            BG0CNTSUB = (BG0CNTSUB & (3 | 0x40)) | (0xf << 8);
            BLDCNTSUB = 0;
        }
        result = false;
        self->step_++;
    }
    else if (self->step_ == 7)
    {
        loader->FreeAllocations();
        self->task_ = loader->QueueLoadFile(data_ov013_02187eaf, NULL);
        result = false;
        self->step_++;
    }
    else if (self->step_ == 8)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            void* data;
            void* name;
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int numFiles = Pac_CountFiles((PacRecord*)file);
            allocators = self->allocators_;
            allocators[1].Reset();
            for (int i = 0; i < numFiles; i++)
            {
                unsigned int dataSize;
                data = Pac_GetFile((PacRecord*)file, i, &name, (int*)&dataSize);
                if (data != NULL)
                {
                    if (i == 0)
                    {
                        Struct_ov013_021870f0_4 canvas;
                        WindowPane_Init(&canvas);
                        canvas.unknown_b4_ = 0xa;
                        canvas.unknown_b6_ = 0xb;
                        canvas.width_ = 0x20;
                        canvas.height_ = 0x18;
                        canvas.pixels_ = (char*)data + 0x10;
                        func_ov013_02187a58(self, &canvas);
                    }
                    Background_LoadFile(&self->background_, data, &allocators[1], dataSize);
                }
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            void* layer = Background_GetScreen((BackgroundGraphics*)&self->background_, 0);
            if (layer != NULL)
                func_0204ae44((Struct_0204ae44*)layer, self->member_);
            func_0204b988((Struct_0204b988*)&self->background_, 0, 0, 0, 0xffff);
            Background_UploadMap((BackgroundGraphics*)&self->background_, NULL);
            self->loaded_ = true;
            self->step_ = 0;
            if (self->screen_ == 0)
                func_020dc7e8(4, -1);
            else
                func_020dc7e8(3, -1);
        }
        result = false;
    }
    return result;
}
