#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
#define func_ov013_02184d80 func_ov013_02185db4
extern char data_ov013_02188d20[];
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"

extern "C" void KeyTable_Load(void* texts, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" void* MessageSystem_GetInstance(void);
extern "C" void func_0205cef8(void* window);
extern "C" void func_0205cf04(void* window);
extern "C" void func_ov013_02185310(unsigned char* self);
extern "C" void func_ov013_02185cc0(void* self);
extern "C" void Background_SetMapSize(unsigned char* graphics, int value);
extern "C" void Background_SetPriority(void* graphics, int priority);
struct BackgroundGraphics;
extern "C" void Background_AllocateMap(BackgroundGraphics* graphics, SafeAllocator* allocator);
extern "C" void Background_SetScroll(BackgroundGraphics* graphics, int a, int b);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord* pac);
extern "C" void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void Background_LoadFile(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_FillRect(void* graphics, int a, int b, int c, int d, int e, int f);
extern "C" void Background_UploadMap(BackgroundGraphics* graphics, void* characters);
struct WindowPane;
extern "C" void WindowPane_AllocateBuffer(WindowPane* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
struct Struct_0205cf78;
struct WindowPane;
extern "C" void Window_SetPanes(Struct_0205cf78* window, WindowPane* canvases, unsigned char count);

extern char data_ov013_02187e00[];
extern char data_ov013_02187e19[];
extern char data_ov013_02187e29[];
extern const unsigned char data_ov013_02187d88[2];
extern const unsigned char data_ov013_02187d8a[2];

struct Struct_ov013_02184d80 {
    char unk_0[0x1c];
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;
    char unknown_1e_[2];
};

struct Struct_ov013_02184d80_2 {
    void* unk_0;
    Struct_ov013_02184d80* background_;
    char unk_8[0xe0 - 8];
};

struct Struct_ov013_02184d80_3 {
    char unk_0[0x98];
    Struct_ov013_02184d80* background_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct Struct_ov013_02184d80_4 {
    SafeAllocator allocator_;
#if defined(jpn)
    char unk_14[0x34 - 0x14];
#else
    char unk_14[0x38 - 0x14];
#endif
    Struct_ov013_02184d80_3 window_;
    Struct_ov013_02184d80 backgrounds_[2];
    Struct_ov013_02184d80_2 canvases_[3];
#if defined(jpn)
    char unknown_3d0_[0x598 - 0x3d0];
#else
    char unknown_3d4_[0x60c - 0x3d4];
#endif
    SafeAllocator textAllocator_;
    char texts_[0x18];
    unsigned char unknown_638_[4];
    unsigned char state_;
    unsigned char unknown_63d_;
    unsigned char step_;
    bool unknown_63f_;
    bool subScreen_;
    unsigned int ticks_;
    int windowInput_;
#if !defined(jpn)
    int unknown_64c_;
#endif
    int task_;
    void* canvasPixels_;
    char* text_;
};

// USA: func_ov013_02184d80
extern "C" ARM void func_ov013_02184d80(Struct_ov013_02184d80_4* self) {
    if (self->state_ != 0)
        return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->subScreen_)
    {
        if (self->step_ == 0)
        {
#if defined(jpn)
            self->task_ = loader->QueueLoadFile(data_ov013_02188d20, NULL);
#else
            self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e00, data_ov013_02187e19, NULL);
#endif
            self->step_++;
        }
        else if (self->step_ == 1)
        {
            if (loader->GetTaskStatus(self->task_))
            {
                void* file;
                unsigned int size;
                loader->GetLoadedFileByID(self->task_, &file, &size);
                self->textAllocator_.Reset();
                KeyTable_Load(self->texts_, &self->textAllocator_, file, size);
                loader->RemoveTask(self->task_);
                self->task_ = -1;
                self->step_++;
            }
        }
        else if (self->step_ == 2)
        {
            self->text_ = *(char**)((char*)MessageSystem_GetInstance()
#if defined(jpn)
                + 0x28);
#else
                + 0x5c);
#endif
            BG2CNTSUB = (BG2CNTSUB & ~3) | 1;
            BG0CNTSUB = (BG0CNTSUB & ~3) | 2;
            BG1CNTSUB = (BG1CNTSUB & ~3) | 3;
            DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
            func_0205cef8(&self->window_);
            func_0205cf04(&self->window_);
            func_ov013_02185310((unsigned char*)self);
            func_ov013_02185cc0(self);
            self->step_ = 0;
            self->state_ = 1;
        }
    }
    else
    {
        if (self->step_ == 0)
        {
            FontBankLoader* music = FontBankLoader_GetInstance();
            func_02094b3c(music, 0xc);
            func_02094b30(music, 0x1f7, 0);
            self->step_++;
        }
        else if (self->step_ == 1)
        {
            if (func_02094b4c(FontBankLoader_GetInstance()))
            {
                self->text_ = *(char**)((char*)MessageSystem_GetInstance()
#if defined(jpn)
                + 0x28);
#else
                + 0x5c);
#endif
#if defined(jpn)
                Background_SetMapSize((unsigned char*)&self->backgrounds_[0], 0);
                self->backgrounds_[0].subScreen_ = 0;
                self->backgrounds_[0].bgNumber_ = 1;
                Background_SetPriority(&self->backgrounds_[0], 1);
                Background_AllocateMap((BackgroundGraphics*)&self->backgrounds_[0], &self->allocator_);
                Background_SetScroll((BackgroundGraphics*)&self->backgrounds_[0], 0, 0);
                BG1CNT = (BG1CNT & (3 | 0x40)) | (0x1d << 8);
                Background_SetMapSize((unsigned char*)&self->backgrounds_[1], 0);
                self->backgrounds_[1].subScreen_ = 0;
                self->backgrounds_[1].bgNumber_ = 2;
                Background_SetPriority(&self->backgrounds_[1], 0);
                Background_AllocateMap((BackgroundGraphics*)&self->backgrounds_[1], &self->allocator_);
                Background_SetScroll((BackgroundGraphics*)&self->backgrounds_[1], 0, 0);
                BG2CNT = (BG2CNT & (3 | 0x40)) | (0x1e << 8);
#else
                Struct_ov013_02184d80* background = self->backgrounds_;
                for (int i = 0; i < 2; background++, i++)
                {
                    Background_SetMapSize((unsigned char*)background, 0);
                    background->subScreen_ = 0;
                    background->bgNumber_ = data_ov013_02187d8a[i];
                    Background_SetPriority(background, data_ov013_02187d88[i]);
                    Background_AllocateMap((BackgroundGraphics*)background, &self->allocator_);
                    Background_SetScroll((BackgroundGraphics*)background, 0, 0);
                }
                BG1CNT = (BG1CNT & (3 | 0x40)) | (0x1d << 8);
                BG2CNT = (BG2CNT & (3 | 0x40)) | (0x1e << 8);
#endif
                ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 0xa, 6);
                self->task_ = loader->QueueLoadFile(data_ov013_02187e29, NULL);
                self->step_++;
            }
        }
        else if (self->step_ == 2)
        {
            if (loader->GetTaskStatus(self->task_))
            {
                void* name = NULL;
                void* file;
                unsigned int size;
                void* files[2];
                unsigned int sizes[2];
                loader->GetLoadedFileByID(self->task_, &file, &size);
                int numFiles = Pac_CountFiles((PacRecord*)file);
                for (int i = 0; i < numFiles; i++)
                {
                    files[i] = Pac_GetFile((PacRecord*)file, i, &name, (int*)&sizes[i]);
                }
                for (int i = 0; i < numFiles; i++)
                {
                    if (files[i] != NULL)
                        Background_LoadFile(&self->backgrounds_[1], files[i], &self->allocator_, sizes[i]);
                }
                loader->RemoveTask(self->task_);
                self->task_ = -1;
                Background_FillRect(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics*)&self->backgrounds_[0], NULL);
                Background_FillRect(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics*)&self->backgrounds_[1], NULL);
                self->canvasPixels_ = self->allocator_.Allocate(0x3c00);
                for (int i = 0; i < 3; i++)
                {
                    WindowPane_AllocateBuffer((WindowPane*)&self->canvases_[i], &self->allocator_, (int)self->canvasPixels_, 0x380);
                    self->canvases_[i].background_ = &self->backgrounds_[1];
                }
                self->window_.background_ = &self->backgrounds_[0];
                self->window_.unknown_b2_ = 2;
                Window_SetPanes((Struct_0205cf78*)&self->window_, (WindowPane*)self->canvases_, 3);
    #if defined(jpn)
            self->task_ = loader->QueueLoadFile(data_ov013_02188d20, NULL);
#else
            self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e00, data_ov013_02187e19, NULL);
#endif
                self->step_++;
            }
        }
        else if (self->step_ == 3)
        {
            if (loader->GetTaskStatus(self->task_))
            {
                void* file;
                unsigned int size;
                loader->GetLoadedFileByID(self->task_, &file, &size);
                self->textAllocator_.Reset();
                KeyTable_Load(self->texts_, &self->textAllocator_, file, size);
                loader->RemoveTask(self->task_);
                self->task_ = -1;
                self->step_++;
            }
        }
        else if (self->step_ == 4)
        {
            BG0CNT = (BG0CNT & ~3) | 2;
            BG1CNT = (BG1CNT & ~3) | 1;
            BG2CNT = BG2CNT & ~3;
            DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
            func_0205cef8(&self->window_);
            func_0205cf04(&self->window_);
            func_ov013_02185310((unsigned char*)self);
            func_ov013_02185cc0(self);
            self->step_ = 0;
            self->state_ = 1;
        }
    }
}
