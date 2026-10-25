#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"

struct BackgroundGraphics;
void Background_Init(BackgroundGraphics* graphics);
extern "C" void Background_SetPriority(void* graphics, int priority);
void Background_SetMapSize(unsigned char* graphics, int value);
void Background_SetScroll(BackgroundGraphics* graphics, int a, int b);
void Background_AllocateMap(BackgroundGraphics* graphics, SafeAllocator* allocator);
void Background_AllocateScreens(BackgroundGraphics* graphics, int count, SafeAllocator* allocator);
struct PacRecord;
int Pac_CountFiles(PacRecord* pac);
void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void Background_LoadFile(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
void Background_DrawScreen(BackgroundGraphics* graphics, unsigned int a, int b, int c, short d, short e, short width, short height, unsigned short f);
void Background_UploadMap(BackgroundGraphics* graphics, void* characters);

struct Struct_ov003_0217cb3c {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};

struct Struct_ov003_0217cb3c_2 {
    char unknown_0_[0x18];
    SafeAllocator unknown_18_;
    SafeAllocator unknown_2c_;
    Struct_ov003_0217cb3c unknown_40_;
    Struct_ov003_0217cb3c unknown_60_;
    char unknown_80_[0xb4];
    int unknown_134_[2];
};

// USA: func_ov003_0217cb3c
extern "C" ARM void func_ov003_0217cb3c(Struct_ov003_0217cb3c_2* arg0, int arg1, int arg2) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    Struct_ov003_0217cb3c* var1;
    SafeAllocator* var2;

    if (arg1 != 0) {
        BG1CNT = (BG1CNT & 0x43) | 0xf00;
        var1 = &arg0->unknown_60_;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x300;
        allocator = &self->mainAllocator_;
        Background_Init((BackgroundGraphics*)background);
        background->screen_ = 0;
        background->palette_ = 1;
        Background_SetPriority(background, 1);
    } else {
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xf00;
        var1 = &arg0->unknown_40_;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x100;
        allocator = &self->subAllocator_;
        Background_Init((BackgroundGraphics*)background);
        background->screen_ = 1;
        background->palette_ = 0;
        Background_SetPriority(background, 0);
    }

    var2->Reset();

    int var3;
    if (arg2 != 0) {
        var3 = arg0->unknown_134_[1];
    } else {
        var3 = arg0->unknown_134_[0];
    }

    Background_SetMapSize((unsigned char*)background, 0);
    Background_SetScroll((BackgroundGraphics*)background, 0, 0);
    Background_AllocateMap((BackgroundGraphics*)background, allocator);
    Background_AllocateScreens((BackgroundGraphics*)background, 1, allocator);

    void* name;
    void* file;
    unsigned int size;
    loader->GetLoadedFileByID(fileId, &file, &size);
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
