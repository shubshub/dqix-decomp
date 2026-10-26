#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"

struct BackgroundGraphics;
extern "C" void Background_Init(BackgroundGraphics* graphics);
extern "C" void Background_SetPriority(void* graphics, int priority);
extern "C" void Background_SetMapSize(unsigned char* graphics, int value);
extern "C" void Background_SetScroll(BackgroundGraphics* graphics, int a, int b);
extern "C" void Background_AllocateMap(BackgroundGraphics* graphics, SafeAllocator* allocator);
extern "C" void Background_AllocateScreens(BackgroundGraphics* graphics, int count, SafeAllocator* allocator);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord* pac);
extern "C" void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void Background_LoadFile(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_DrawScreen(BackgroundGraphics* graphics, unsigned int a, int b, int c, short d, short e, short width, short height, unsigned short f);
extern "C" void Background_UploadMap(BackgroundGraphics* graphics, void* characters);

struct Struct_ov003_0217cb3c {
    char unk_0[0x1c];
    unsigned char screen_ : 4;
    unsigned char palette_ : 4;
    char unknown_1d_[3];
};

struct Struct_ov003_0217cb3c_2 {
    char unk_0[0x18];
    SafeAllocator unknown_18_;
    SafeAllocator unknown_2c_;
    Struct_ov003_0217cb3c subBackground_;
    Struct_ov003_0217cb3c unknown_60_;
    char unknown_80_[0xb4];
    int unknown_134_[2];
};

// USA: func_ov003_0217cb3c
extern "C" ARM void func_ov003_0217cb3c(Struct_ov003_0217cb3c_2* self, int arg1, int alternate) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Struct_ov003_0217cb3c* background;
    SafeAllocator* allocator;

    if (arg1 != 0) {
        BG1CNT = (BG1CNT & 0x43) | 0xf00;
        background = &self->unknown_60_;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x300;
        allocator = &self->unknown_2c_;
        Background_Init((BackgroundGraphics*)background);
        background->screen_ = 0;
        background->palette_ = 1;
        Background_SetPriority(background, 1);
    } else {
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xf00;
        background = &self->subBackground_;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x100;
        allocator = &self->unknown_18_;
        Background_Init((BackgroundGraphics*)background);
        background->screen_ = 1;
        background->palette_ = 0;
        Background_SetPriority(background, 0);
    }

    allocator->Reset();

    int var3;
    if (alternate != 0) {
        var3 = self->unknown_134_[1];
    } else {
        var3 = self->unknown_134_[0];
    }

    Background_SetMapSize((unsigned char*)background, 0);
    Background_SetScroll((BackgroundGraphics*)background, 0, 0);
    Background_AllocateMap((BackgroundGraphics*)background, allocator);
    Background_AllocateScreens((BackgroundGraphics*)background, 1, allocator);

    void* name;
    void* file;
    unsigned int size;
    loader->GetLoadedFileByID(var3, &file, &size);
    int numFiles = Pac_CountFiles((PacRecord*)file);
    for (int i = 0; i < numFiles; i++) {
        unsigned int dataSize;
        void* data = Pac_GetFile((PacRecord*)file, i, &name, (int*)&dataSize);
        if (data != NULL) {
            Background_LoadFile(background, data, allocator, dataSize);
        }
    }

    Background_DrawScreen((BackgroundGraphics*)background, 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    Background_UploadMap((BackgroundGraphics*)background, NULL);
}
