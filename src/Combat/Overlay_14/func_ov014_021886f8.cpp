#include <globaldefs.h>
#include "Graphics/Background.h"

#if defined(jpn)
#define func_ov014_021886f8 func_ov014_021895c8
#endif
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"


struct Canvas {
    Canvas* unk_0;
    BackgroundGraphics* background_;
    char unk_8[0xd8];
};

struct Struct_ov014_02184f78;

struct Struct_020974b0 {
    char unk_0[0x10];
};

struct Struct_ov014_02186bc8 {
    char unk_0[0xa4];
    Struct_020974b0 list_;
    SafeAllocator* unknown_b4_;
    Struct_ov014_02184f78* entries_;
    Struct_ov014_02184f78* unknown_bc_;
    void* menu_;
    BackgroundGraphics* backgrounds_;
    Canvas* canvases_;
    void* canvasBuffer_;
    short* cursor_;
    void* unknown_d4_;
    void* animations_;
    void* unknown_dc_;
    char textTable_[0x18];
    char spriteRenderer_[0x54];
    char unknown_14c_[0xc];
    unsigned short unknown_158_;
    unsigned char unknown_15a_;
    char unknown_15b_;
    int unknown_15c_;
    int unknown_160_;
    int ticks_;
    int unknown_168_;
    int unknown_16c_;
    short unknown_170_;
    short unknown_172_;
    short unknown_174_;
    short unknown_176_;
    short unknown_178_;
    unsigned char unknown_17a_;
    unsigned char unknown_17b_;
    unsigned char unknown_17c_;
    signed char unknown_17d_;
    unsigned char unknown_17e_;
    bool unknown_17f_;
    short unknown_180_;
    short unknown_182_[8];
};

struct PacRecord;
struct BackgroundGraphics;
struct Struct0200fb08;
struct Struct_0204b988;
struct WindowPane;

extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" int GameState_GetLanguage(Struct0200fb08*);
extern "C" void Background_ClearMap(BackgroundGraphics*, void*);
extern "C" void func_0204b988(Struct_0204b988*, unsigned int, int, int, unsigned short);
extern "C" void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" void WindowPane_AllocateBuffer(WindowPane*, SafeAllocator*, int, unsigned int);

extern "C" {
void Background_SetPriority(BackgroundGraphics* graphics, int);
void Background_LoadFile(BackgroundGraphics* graphics, void* file, SafeAllocator* allocator, unsigned int size);
void WindowPane_Init(Canvas* canvas);
}

extern const char data_ov014_02189795[];
extern const char data_ov014_021897ac[];

// USA: func_ov014_021886f8
extern "C" ARM void func_ov014_021886f8(Struct_ov014_02186bc8* self)
{
    SafeAllocator* allocators;
#if !defined(jpn)
    GameState* gameState = GameState::GetInstance();
#endif
    if (!(self->unknown_17e_ & 0x10))
        return;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->unknown_17c_ == 0)
    {
        const char* file = data_ov014_02189795;
        if (self->unknown_17a_ == 4)
            file = data_ov014_021897ac;
        self->unknown_16c_ = loader->QueueLoadFile(file, NULL);
        self->unknown_17c_++;
    }
    else if (self->unknown_17c_ == 1)
    {
        if (!loader->GetTaskStatus(self->unknown_16c_))
            return;

        BackgroundGraphics graphics;
        void* name;
        void* file;
        unsigned int size;
        unsigned int dataSize;
        int numFiles;
        loader->GetLoadedFileByID(self->unknown_16c_, &file, &size);
        numFiles = Pac_CountFiles((PacRecord*)file);
        allocators = self->unknown_b4_;
        allocators[1].Reset();
        Background_Init((BackgroundGraphics*)&graphics);
        Background_SetMapSize((unsigned char*)&graphics, 0);
        graphics.subScreen_ = 1;
        graphics.bgNumber_ = 2;
        Background_SetPriority(&graphics, 2);
        Background_AllocateMap((BackgroundGraphics*)&graphics, &allocators[1]);
        Background_SetScroll((BackgroundGraphics*)&graphics, 0, 0);
#if defined(jpn)
        Background_AllocateScreens((BackgroundGraphics*)&graphics, 1, &allocators[1]);
#else
        Background_AllocateScreens((BackgroundGraphics*)&graphics, 5, &allocators[1]);
#endif
        for (int i = 1; i < numFiles; i++)
        {
            void* data = Pac_GetFile((PacRecord*)file, i, &name, (int*)&dataSize);
            if (data != NULL)
                Background_LoadFile(&graphics, data, &allocators[1], dataSize);
        }
        loader->RemoveTask(self->unknown_16c_);
        self->unknown_16c_ = -1;

#if !defined(jpn)
        int language = GameState_GetLanguage((Struct0200fb08*)gameState);
        int title = 0;
        switch (language)
        {
        case 2:
            title = 1;
            break;
        case 4:
            title = 2;
            break;
        case 3:
            title = 3;
            break;
        case 5:
            title = 4;
            break;
        }
#endif
        Background_ClearMap((BackgroundGraphics*)&graphics, 0);
        func_0204b988((Struct_0204b988*)&graphics, 0, 0, 0, 0xffff);

#if !defined(jpn)
        if (title != 0)
            Background_DrawScreen((BackgroundGraphics*)&graphics, title, 0, 0, 0x16, 2, 9, 2, 0xffff);
#endif
        Background_UploadMap((BackgroundGraphics*)&graphics, 0);

        allocators[1].Reset();
        for (unsigned char i = 0; i < 2; i++)
        {
            BackgroundGraphics* background = &self->backgrounds_[i];
            Background_Init((BackgroundGraphics*)background);
            background->subScreen_ = 1;
            background->bgNumber_ = i;
            Background_SetMapSize((unsigned char*)background, 0);
            Background_SetPriority(background, i);
            Background_AllocateMap((BackgroundGraphics*)background, &allocators[1]);
            Background_SetScroll((BackgroundGraphics*)background, 0, 0);
        }
        void* data = Pac_GetFile((PacRecord*)file, 0, &name, (int*)&dataSize);
        if (data != NULL)
            Background_LoadFile(self->backgrounds_, data, &allocators[1], dataSize);
        for (unsigned char i = 0; i < 2; i++)
        {
            BackgroundGraphics* background = &self->backgrounds_[i];
            Background_ClearMap((BackgroundGraphics*)background, 0);
            Background_UploadMap((BackgroundGraphics*)background, 0);
        }
        for (unsigned char i = 0; i < 4; i++)
        {
            Canvas* canvas = &self->canvases_[i];
            WindowPane_Init(canvas);
            WindowPane_AllocateBuffer((WindowPane*)canvas, &allocators[1], (int)self->canvasBuffer_, 0x600);
            canvas->background_ = self->backgrounds_;
        }
        self->unknown_17c_ = 0;
        self->unknown_17e_ &= ~0x10;
    }
}
