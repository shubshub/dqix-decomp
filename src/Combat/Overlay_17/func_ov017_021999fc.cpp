#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"

struct Struct020dfc40;
extern "C" void KeyTable_Reset(Struct020dfc40* texts);
extern "C" void KeyTable_Load(void* texts, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" void Background_SetMapSize(unsigned char* graphics, int value);
extern "C" void Background_SetPriority(void* graphics, int priority);
struct BackgroundGraphics;
extern "C" void Background_SetScroll(BackgroundGraphics* graphics, int a, int b);
extern "C" int func_ov017_02199964(int size, int colorMode, int arg2, int arg3, int wrap);
extern "C" int func_ov017_021999b4(int screenSize, int colorMode, int screenBase, int charBase);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord* pac);
extern "C" void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void Background_LoadFile(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
struct Struct_ov017_02199684;
extern "C" void func_ov017_02199684(Struct_ov017_02199684* arr, int count, int value);
extern "C" void func_ov017_021996bc(Struct_ov017_02199684* arr, int count);
extern "C" void Background_FillRect(void* graphics, int a, int b, int c, int d, int e, int f);
extern "C" void Background_UploadMap(BackgroundGraphics* graphics, void* characters);
struct WindowPane;
extern "C" void WindowPane_AllocateBuffer(WindowPane* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
struct Struct_0205cf78;
struct WindowPane;
extern "C" void Window_SetPanes(Struct_0205cf78* window, WindowPane* canvases, unsigned char count);

struct Struct_ov017_021999fc;
extern "C" void func_ov017_0219a388(Struct_ov017_021999fc* self);

struct Struct_ov017_021d643c {
    unsigned char values[2];
};

#if defined(jpn)
#define data_ov017_021d73f8 data_ov017_021d7858
#define data_ov017_021d7423 data_ov017_021d7872
#define data_ov017_021d643c data_ov017_021d688c
enum { Enum_ov017_021999fc_15536 = 0x3a90, Enum_ov017_021999fc_15956 = 0x3e54 };
#else
enum { Enum_ov017_021999fc_15536 = 0x3cb0, Enum_ov017_021999fc_16500 = 0x4074 };
#endif

extern char data_ov017_021d73f8[];
extern char data_ov017_021d7412[];
extern char data_ov017_021d7423[];
extern const Struct_ov017_021d643c data_ov017_021d643c[2];

struct Struct_ov017_021999fc_2 {
    char unk_0[0x1c];
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;
    char unknown_1e_[2];
};

struct Struct_ov017_021999fc_3 {
    void* unk_0;
    Struct_ov017_021999fc_2* background_;
    char unk_8[0xe0 - 8];
};

struct Struct_ov017_021999fc_4 {
    char unk_0[0x98];
    Struct_ov017_021999fc_2* background_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
};

struct Struct_ov017_021999fc {
    char unk_0[0x178];
    SafeAllocator allocator_;
    char unknown_18c_[Enum_ov017_021999fc_15536 - 0x18c];
    Struct_ov017_021999fc_4* window_;
    Struct_ov017_021999fc_2 backgrounds_[2];
    Struct_ov017_021999fc_3 canvases_[4];
    void* canvasPixels_;
    int step_;
    int task_;
    int active_;
    Struct020dfc40* texts_;
};

// USA: func_ov017_021999fc
// JPN: func_ov017_0219a5ac
extern "C" ARM void func_ov017_021999fc(Struct_ov017_021999fc* self) {
    if (self->canvasPixels_ != 0)
        return;
    if (self->active_ == 0)
        return;
    if (self->step_ == 0)
    {
        self->allocator_.Reset();
        self->texts_ = (Struct020dfc40*)self->allocator_.Allocate(0x18);
        KeyTable_Reset(self->texts_);
#if defined(jpn)
        self->task_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d73f8, NULL);
#else
        self->task_ = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d73f8, data_ov017_021d7412, NULL);
#endif
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->task_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            KeyTable_Load(self->texts_, &self->allocator_, file, size);
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
    }
    if (self->step_ == 2)
    {
        Struct_ov017_021d643c nibbles = data_ov017_021d643c[0];
        Struct_ov017_021d643c priorities = data_ov017_021d643c[1];
        Struct_ov017_021999fc_2* background;
        for (int i = 0; i < 2; i++)
        {
            background = &self->backgrounds_[i];
            Background_SetMapSize((unsigned char*)background, 0);
            background->subScreen_ = 0;
            background->bgNumber_ = nibbles.values[i];
            Background_SetPriority(background, priorities.values[i]);
            Background_SetScroll((BackgroundGraphics*)background, 0, 0);
        }
        DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
        func_ov017_02199964(0, 0, 0x1d, 0, 0);
        func_ov017_021999b4(0, 0, 0x1e, 0);
        ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 0xa, 6);
        self->task_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d7423, NULL);
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->task_))
        {
            void* name;
            void* file;
            void* files[2];
            unsigned int size;
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
            func_ov017_02199684((Struct_ov017_02199684*)self->backgrounds_, 2, 0x800);
            Struct_ov017_021999fc_2* background;
            for (int i = 0; i < 2; i++)
            {
                background = &self->backgrounds_[i];
                Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics*)background, NULL);
            }
            func_ov017_021996bc((Struct_ov017_02199684*)self->backgrounds_, 2);
            self->canvasPixels_ = self->allocator_.Allocate(0x400);
            Struct_ov017_021999fc_3* canvas;
            for (int i = 0; i < 4; i++)
            {
                canvas = &self->canvases_[i];
                WindowPane_AllocateBuffer((WindowPane*)canvas, &self->allocator_, (int)self->canvasPixels_, 0x40);
                canvas->background_ = &self->backgrounds_[1];
            }
            Struct_ov017_021999fc_4* window = self->window_;
            window->background_ = &self->backgrounds_[0];
            window->unknown_b2_ = 2;
            Window_SetPanes((Struct_0205cf78*)self->window_, (WindowPane*)self->canvases_, 4);
            BG0CNT = (BG0CNT & ~3) | 2;
            BG1CNT = (BG1CNT & ~3) | 1;
            BG2CNT = BG2CNT & ~3;
            BG3CNT = (BG3CNT & ~3) | 3;
            DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
            func_ov017_0219a388(self);
            self->step_++;
        }
    }
}
