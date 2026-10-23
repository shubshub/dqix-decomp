#include <globaldefs.h>

#if defined(jpn)
#define func_ov014_021886f8 func_ov014_021895c8
#endif
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov003_021594c4 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov006_02158478 {
    Struct_ov006_02158478* unknown_0_;
    Struct_ov003_021594c4* unknown_4_;
    char unknown_8_[0xd8];
};

struct Struct_ov014_02184f78;

struct Struct_020974b0 {
    char unknown_0_[0x10];
};

struct Struct_ov014_02186bc8 {
    char unknown_0_[0xa4];
    Struct_020974b0 unknown_a4_;
    SafeAllocator* unknown_b4_;
    Struct_ov014_02184f78* unknown_b8_;
    Struct_ov014_02184f78* unknown_bc_;
    void* unknown_c0_;
    Struct_ov003_021594c4* unknown_c4_;
    Struct_ov006_02158478* unknown_c8_;
    void* unknown_cc_;
    short* unknown_d0_;
    void* unknown_d4_;
    void* unknown_d8_;
    void* unknown_dc_;
    char unknown_e0_[0x18];
    char unknown_f8_[0x54];
    char unknown_14c_[0xc];
    unsigned short unknown_158_;
    unsigned char unknown_15a_;
    char unknown_15b_;
    int unknown_15c_;
    int unknown_160_;
    int unknown_164_;
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

struct Struct_02020cb8_4;
struct Struct_02020cb8;
struct Struct_0204b12c;
struct Struct_02020cb8_5;
struct Struct_0204af38;
struct Struct_02020aec;
struct Struct_02000c9c_8;
struct Struct_0204b010;
struct Struct_0204b988;
struct Struct_0204b8d0;
struct Struct_02020cb8_2;
struct Struct_0204c7a8;

int Pac_CountFiles(ActiveEntry02046900*);
void Background_Init(List0204af64*);
void Background_SetMapSize(unsigned char*, int);
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
void Background_SetScroll(Obj0204b5e8*, int, int);
void Background_AllocateScreens(Foo0204af38*, int, SafeAllocator*);
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
int NormalizeField5_0200fb08(Struct0200fb08*);
void Background_ClearMap(Obj0204b010*, void*);
void DispatchIndexedEntry0204b988(Obj0204b988*, unsigned int, int, int, unsigned short);
void Background_DrawScreen(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
void Background_UploadMap(List0204b0e8*, void*);
void WindowPane_AllocateBuffer(Obj0204c7a8*, SafeAllocator*, int, unsigned int);

extern "C" {
void Background_SetPriority(BackgroundGraphics* graphics, int);
void Background_LoadFile(BackgroundGraphics* graphics, void* file, SafeAllocator* allocator, unsigned int size);
void func_0204c684(Canvas* canvas);
}

extern const char data_ov014_02189795[];
extern const char data_ov014_021897ac[];

// USA: func_ov014_021886f8
extern "C" ARM void func_ov014_021886f8(Struct_ov014_02186bc8* arg0)
{
    SafeAllocator* var0;
#if !defined(jpn)
    GameState* var1 = GameState::GetInstance();
#endif
    if (!(arg0->unknown_17e_ & 0x10))
        return;

    BackgroundLoader* var2 = BackgroundLoader::GetInstance();
    if (arg0->unknown_17c_ == 0)
    {
        const char* var3 = data_ov014_02189795;
        if (arg0->unknown_17a_ == 4)
            var3 = data_ov014_021897ac;
        arg0->unknown_16c_ = var2->QueueLoadFile(var3, NULL);
        arg0->unknown_17c_++;
    }
    else if (arg0->unknown_17c_ == 1)
    {
        if (!var2->GetTaskStatus(arg0->unknown_16c_))
            return;

        BackgroundGraphics graphics;
        void* name;
        void* file;
        unsigned int size;
        unsigned int dataSize;
        int numFiles;
        loader->GetLoadedFileByID(self->listBackgroundTaskID_, &file, &size);
        numFiles = Pac_CountFiles((ActiveEntry02046900*)file);
        allocators = self->listAllocators_;
        allocators[1].Reset();
        Background_Init((List0204af64*)&graphics);
        Background_SetMapSize((unsigned char*)&graphics, 0);
        graphics.unk_1c_0_ = 1;
        graphics.unk_1c_4_ = 2;
        Background_SetPriority(&graphics, 2);
        Background_AllocateMap((AllocTarget0204b12c*)&graphics, &allocators[1]);
        Background_SetScroll((Obj0204b5e8*)&graphics, 0, 0);
#if defined(jpn)
        Background_AllocateScreens((Foo0204af38*)&graphics, 1, &allocators[1]);
#else
        Background_AllocateScreens((Foo0204af38*)&graphics, 5, &allocators[1]);
#endif
        for (int var10 = 1; var10 < var9; var10++)
        {
            void* data = Pac_GetFile((Rec020467f0*)file, i, &name, (int*)&dataSize);
            if (data != NULL)
                Background_LoadFile(&graphics, data, &allocators[1], dataSize);
        }
        var2->RemoveTask(arg0->unknown_16c_);
        arg0->unknown_16c_ = -1;

#if !defined(jpn)
        int var12 = func_0200fb08((Struct_02000c9c_8*)var1);
        int var13 = 0;
        switch (var12)
        {
        case 2:
            var13 = 1;
            break;
        case 4:
            var13 = 2;
            break;
        case 3:
            var13 = 3;
            break;
        case 5:
            var13 = 4;
            break;
        }
#endif
        Background_ClearMap((Obj0204b010*)&graphics, 0);
        DispatchIndexedEntry0204b988((Obj0204b988*)&graphics, 0, 0, 0, 0xffff);

#if !defined(jpn)
        if (title != 0)
            Background_DrawScreen((Obj0204b8d0*)&graphics, title, 0, 0, 0x16, 2, 9, 2, 0xffff);
#endif
        Background_UploadMap((List0204b0e8*)&graphics, 0);

        var0[1].Reset();
        for (unsigned char var14 = 0; var14 < 2; var14++)
        {
            BackgroundGraphics* background = &self->backgrounds_[i];
            Background_Init((List0204af64*)background);
            background->unk_1c_0_ = 1;
            background->unk_1c_4_ = i;
            Background_SetMapSize((unsigned char*)background, 0);
            Background_SetPriority(background, i);
            Background_AllocateMap((AllocTarget0204b12c*)background, &allocators[1]);
            Background_SetScroll((Obj0204b5e8*)background, 0, 0);
        }
        void* data = Pac_GetFile((Rec020467f0*)file, 0, &name, (int*)&dataSize);
        if (data != NULL)
            Background_LoadFile(self->backgrounds_, data, &allocators[1], dataSize);
        for (unsigned char i = 0; i < 2; i++)
        {
            BackgroundGraphics* background = &self->backgrounds_[i];
            Background_ClearMap((Obj0204b010*)background, 0);
            Background_UploadMap((List0204b0e8*)background, 0);
        }
        for (unsigned char var19 = 0; var19 < 4; var19++)
        {
            Canvas* canvas = &self->canvases_[i];
            func_0204c684(canvas);
            WindowPane_AllocateBuffer((Obj0204c7a8*)canvas, &allocators[1], (int)self->canvasBuffer_, 0x600);
            canvas->background_ = self->backgrounds_;
        }
        arg0->unknown_17c_ = 0;
        arg0->unknown_17e_ &= ~0x10;
    }
}
