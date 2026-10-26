#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/ColorEffects.h"

#if defined(jpn)
#define data_ov012_0218af75 data_ov012_0218bcec
#define data_ov012_0218af78 data_ov012_0218bcef
enum { kPixels = 0x134c, Enum_ov012_02185f74_5004 = 0x1358 };
#else
enum { kPixels = 0x137c, Enum_ov012_02185f74_5004 = 0x138c };
#endif

struct Background02185f74
{
    char unk_0[0x1c];
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;
    char unknown_1e_[2];
};

struct Struct_ov012_02185f74_4
{
    void* unk_0;
    Background02185f74* background_;
    char unk_8[0xe0 - 8];
};

struct Struct_02000c9c_44
{
    int field0, field4, field8, fieldC;
    unsigned char field10;
    int field14, field18, unknown_1c_, field20, field24, field28, unknown_2c_;
};

struct Struct_02000c9c_45
{
    Struct_02000c9c_44 transform;
    int unknown_30_, field34;
    short field38, unknown_3a_;
    int unknown_3c_, field40, field44, field48;
    unsigned char unknown_4c_, unknown_4d_, unknown_4e_;
};

struct Struct_02000c9c_42
{
    Struct_02000c9c_44 transform;
    int unknown_30_;
    short field34;
    unsigned char unknown_36_, unknown_37_, field38, unknown_39_, unknown_3a_;
    unsigned char unknown_3b_, unknown_3c_, unknown_3d_;
};

struct Struct_ov012_02185f74
{
    unsigned int unknown0;
    Struct_02000c9c_45 frame;
    Struct_02000c9c_42 cursor;
    unsigned char field94, unknown_95_;
    Background02185f74* backgrounds;
    Struct_ov012_02185f74_4* canvases;
    unsigned short unknown_a0_, unknown_a2_, unknown_a4_, unknown_a6_;
    unsigned short unknown_a8_, unknown_aa_, unknown_ac_, unknown_ae_;
    unsigned char fieldB0, unknown_b1_, unknown_b2_, unknown_b3_;
    unsigned char fieldB4, unknown_b5_, fieldB6, unknown_b7_, fieldB8;
};

struct Struct_ov012_02185f74_2
{
#if !defined(jpn)
    void* unknown0;
    void* unknown4;
#endif
    struct Struct_02000c9c_43 {
        unsigned short value;
        unsigned short unknown;
    } unknown_8_[4];
    unsigned char unknown_18_;
    unsigned char unknown_19_;
    unsigned short unknown_1a_;
    unsigned int unknown_1c_;
#if defined(jpn)
    SafeAllocator allocators[6];
#else
    SafeAllocator allocators[7];
#endif
    Struct_ov012_02185f74 window;
    Background02185f74 backgrounds[3];
    Struct_ov012_02185f74_4 canvases[13];
};

struct BackgroundGraphics;
struct PacRecord;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;

extern "C" void Background_SetMapSize(unsigned char* background, int a);
extern "C" void Background_SetPriority(Background02185f74* background, int a);
extern "C" void Background_AllocateMap(BackgroundGraphics* background, SafeAllocator* allocator);
extern "C" void Background_SetScroll(BackgroundGraphics* background, int a, int b);
extern "C" int Pac_CountFiles(PacRecord* archive);
extern "C" void* Pac_GetFile(PacRecord* archive, int index, void** name, int* size);
extern "C" void Background_LoadFile(Background02185f74* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_FillRect(Background02185f74* background, int a, int b, int c, int d, int e, int f);
extern "C" void Background_UploadMap(BackgroundGraphics* background, void* a);
extern "C" void WindowPane_AllocateBuffer(WindowPane* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
extern "C" void Window_SetPanes(Struct_0205cf78* window, WindowPane* canvases, unsigned char count);

extern "C" const unsigned char data_ov012_0218af75[3];
extern "C" const unsigned char data_ov012_0218af78[3];

// USA: func_ov012_02185f74
extern "C" ARM void func_ov012_02185f74(Struct_ov012_02185f74_2* self)
{
    Background02185f74* background;
    int count;
    BackgroundLoader* loader;
    Struct_ov012_02185f74_4* canvas;
    void* name;
    void* file;
    unsigned int size;
    int fileSize;
    loader = BackgroundLoader::GetInstance();
    self->allocators[0].Reset();
    for (int i = 0; i < 3; i++)
    {
        background = &self->backgrounds[i];
        Background_SetMapSize((unsigned char*)background, 0);
        background->subScreen_ = 0;
        background->bgNumber_ = data_ov012_0218af75[i];
        Background_SetPriority(background, data_ov012_0218af78[i]);
        Background_AllocateMap((BackgroundGraphics*)background, &self->allocators[0]);
        Background_SetScroll((BackgroundGraphics*)background, 0, 0);
    }
    BG1CNT = (BG1CNT & 0x43) | 0x1d00;
    BG2CNT = (BG2CNT & 0x43) | 0x1e00;
    BG3CNT = (BG3CNT & 0x43) | 0x1f08;
    ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);

    loader->GetLoadedFileByID(*(int*)((char*)self + Enum_ov012_02185f74_5004), &file, &size);
    count = Pac_CountFiles((PacRecord*)file);
    for (int i = 0; i < count; i++)
    {
        void* data = Pac_GetFile((PacRecord*)file, i, &name, &fileSize);
        if (data != 0)
        {
            Background_LoadFile(&self->backgrounds[1], data, &self->allocators[0], fileSize);
            Background_LoadFile(&self->backgrounds[2], data, &self->allocators[0], fileSize);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        background = &self->backgrounds[i];
        Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((BackgroundGraphics*)background, 0);
    }
    char* storage = (char*)self;
    *(void**)(storage + kPixels) = self->allocators[0].Allocate(0x7800);
    for (int i = 0; i < 13; i++)
    {
        canvas = &self->canvases[i];
        WindowPane_AllocateBuffer((WindowPane*)canvas, &self->allocators[0], (int)*(void**)(storage + kPixels), 0x800);
        canvas->background_ = &self->backgrounds[1];
    }
    self->window.backgrounds = self->backgrounds;
    self->window.unknown_b2_ = 3;
    Window_SetPanes((Struct_0205cf78*)&self->window, (WindowPane*)self->canvases, 13);
    loader->RemoveTask(*(int*)((char*)self + Enum_ov012_02185f74_5004));
    *(int*)((char*)self + Enum_ov012_02185f74_5004) = -1;
}
