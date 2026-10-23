#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"

struct List0204af64;
void Background_Init(List0204af64* graphics);
extern "C" void Background_SetPriority(void* graphics, int priority);
void Background_SetMapSize(unsigned char* graphics, int value);
struct Obj0204b5e8;
void Background_SetScroll(Obj0204b5e8* graphics, int a, int b);
struct AllocTarget0204b12c;
void Background_AllocateMap(AllocTarget0204b12c* graphics, SafeAllocator* allocator);
struct Foo0204af38;
void Background_AllocateScreens(Foo0204af38* graphics, int count, SafeAllocator* allocator);
struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900* pac);
struct Rec020467f0;
void* Pac_GetFile(Rec020467f0* pac, int index, void** outName, int* outSize);
extern "C" void Background_LoadFile(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
struct Obj0204b8d0;
void Background_DrawScreen(Obj0204b8d0* graphics, unsigned int a, int b, int c, short d, short e, short width, short height, unsigned short f);
struct List0204b0e8;
void Background_UploadMap(List0204b0e8* graphics, void* characters);

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
        Background_Init((List0204af64*)background);
        background->screen_ = 0;
        background->palette_ = 1;
        Background_SetPriority(background, 1);
    } else {
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xf00;
        var1 = &arg0->unknown_40_;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x100;
        allocator = &self->subAllocator_;
        Background_Init((List0204af64*)background);
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
    Background_SetScroll((Obj0204b5e8*)background, 0, 0);
    Background_AllocateMap((AllocTarget0204b12c*)background, allocator);
    Background_AllocateScreens((Foo0204af38*)background, 1, allocator);

    void* name;
    void* file;
    unsigned int size;
    loader->GetLoadedFileByID(fileId, &file, &size);
    int numFiles = Pac_CountFiles((ActiveEntry02046900*)file);
    for (int i = 0; i < numFiles; i++) {
        unsigned int dataSize;
        void* data = Pac_GetFile((Rec020467f0*)file, i, &name, (int*)&dataSize);
        if (data != NULL) {
            Background_LoadFile(background, data, allocator, dataSize);
        }
    }

    Background_DrawScreen((Obj0204b8d0*)background, 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    Background_UploadMap((List0204b0e8*)background, NULL);
}
