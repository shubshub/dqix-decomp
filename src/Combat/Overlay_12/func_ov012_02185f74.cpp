#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/ColorEffects.h"

#if defined(jpn)
#define data_ov012_0218af75 data_ov012_0218bcec
#define data_ov012_0218af78 data_ov012_0218bcef
enum { Enum_ov012_02185f74_4988 = 0x134c, Enum_ov012_02185f74_5004 = 0x1358 };
#else
enum { Enum_ov012_02185f74_4988 = 0x137c, Enum_ov012_02185f74_5004 = 0x138c };
#endif

struct Struct_ov012_02185f74_3
{
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov012_02185f74_4
{
    void* unknown_0_;
    Struct_ov012_02185f74_3* unknown_4_;
    char unknown_8_[0xe0 - 8];
};

struct Struct_02000c9c_44
{
    int unknown_0_, unknown_4_, unknown_8_, unknown_c_;
    unsigned char unknown_10_;
    int unknown_14_, unknown_18_, unknown_1c_, unknown_20_, unknown_24_, unknown_28_, unknown_2c_;
};

struct Struct_02000c9c_45
{
    Struct_02000c9c_44 unknown_0_;
    int unknown_30_, unknown_34_;
    short unknown_38_, unknown_3a_;
    int unknown_3c_, unknown_40_, unknown_44_, unknown_48_;
    unsigned char unknown_4c_, unknown_4d_, unknown_4e_;
};

struct Struct_02000c9c_42
{
    Struct_02000c9c_44 unknown_0_;
    int unknown_30_;
    short unknown_34_;
    unsigned char unknown_36_, unknown_37_, unknown_38_, unknown_39_, unknown_3a_;
    unsigned char unknown_3b_, unknown_3c_, unknown_3d_;
};

struct Struct_ov012_02185f74
{
    unsigned int unknown_0_;
    Struct_02000c9c_45 unknown_4_;
    Struct_02000c9c_42 unknown_54_;
    unsigned char unknown_94_, unknown_95_;
    Struct_ov012_02185f74_3* unknown_98_;
    Struct_ov012_02185f74_4* unknown_9c_;
    unsigned short unknown_a0_, unknown_a2_, unknown_a4_, unknown_a6_;
    unsigned short unknown_a8_, unknown_aa_, unknown_ac_, unknown_ae_;
    unsigned char unknown_b0_, unknown_b1_, unknown_b2_, unknown_b3_;
    unsigned char unknown_b4_, unknown_b5_, unknown_b6_, unknown_b7_, unknown_b8_;
};

struct Struct_ov012_02185f74_2
{
#if !defined(jpn)
    void* unknown_0_;
    void* unknown_4_;
#endif
    struct Struct_02000c9c_43 {
        unsigned short unknown_0_;
        unsigned short unknown_2_;
    } unknown_8_[4];
    unsigned char unknown_18_;
    unsigned char unknown_19_;
    unsigned short unknown_1a_;
    unsigned int unknown_1c_;
#if defined(jpn)
    SafeAllocator unknown_20_[6];
#else
    SafeAllocator unknown_20_[7];
#endif
    Struct_ov012_02185f74 unknown_ac_;
    Struct_ov012_02185f74_3 unknown_168_[3];
    Struct_ov012_02185f74_4 unknown_1c8_[13];
};

struct Struct_0204b12c;
struct Struct_02020cb8_5;
struct Struct_02020cb8_4;
struct Struct_02020aec;
struct Struct_02020cb8_2;
struct Struct_0204c7a8;
struct Struct_0205cf78;
struct Struct_0205cf78_2;

void Background_SetMapSize(unsigned char* background, int a);
extern "C" void Background_SetPriority(Background02185f74* background, int a);
void Background_AllocateMap(AllocTarget0204b12c* background, SafeAllocator* allocator);
void Background_SetScroll(Obj0204b5e8* background, int a, int b);
int Pac_CountFiles(ActiveEntry02046900* archive);
void* Pac_GetFile(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void Background_LoadFile(Background02185f74* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_FillRect(Background02185f74* background, int a, int b, int c, int d, int e, int f);
void Background_UploadMap(List0204b0e8* background, void* a);
void WindowPane_AllocateBuffer(Obj0204c7a8* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
void Window_SetPanes(Struct_0205cf78* window, Elem_0205cf78* canvases, unsigned char count);

extern "C" const unsigned char data_ov012_0218af75[3];
extern "C" const unsigned char data_ov012_0218af78[3];

// USA: func_ov012_02185f74
extern "C" ARM void func_ov012_02185f74(Struct_ov012_02185f74_2* arg0)
{
    Struct_ov012_02185f74_3* var0;
    int var1;
    BackgroundLoader* var2;
    Struct_ov012_02185f74_4* var3;
    void* var4;
    void* var5;
    unsigned int var6;
    int var7;
    var2 = BackgroundLoader::GetInstance();
    arg0->unknown_20_[0].Reset();
    for (int var8 = 0; var8 < 3; var8++)
    {
        background = &self->backgrounds[i];
        Background_SetMapSize((unsigned char*)background, 0);
        background->unk_1c_0_ = 0;
        background->unk_1c_4_ = data_ov012_0218af75[i];
        Background_SetPriority(background, data_ov012_0218af78[i]);
        Background_AllocateMap((AllocTarget0204b12c*)background, &self->allocators[0]);
        Background_SetScroll((Obj0204b5e8*)background, 0, 0);
    }
    BG1CNT = (BG1CNT & 0x43) | 0x1d00;
    BG2CNT = (BG2CNT & 0x43) | 0x1e00;
    BG3CNT = (BG3CNT & 0x43) | 0x1f08;
    ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);

    loader->GetLoadedFileByID(*(int*)((char*)self + kTask), &file, &size);
    count = Pac_CountFiles((ActiveEntry02046900*)file);
    for (int i = 0; i < count; i++)
    {
        void* data = Pac_GetFile((Rec020467f0*)file, i, &name, &fileSize);
        if (data != 0)
        {
            Background_LoadFile(&self->backgrounds[1], data, &self->allocators[0], fileSize);
            Background_LoadFile(&self->backgrounds[2], data, &self->allocators[0], fileSize);
        }
    }
    for (int var11 = 0; var11 < 3; var11++)
    {
        background = &self->backgrounds[i];
        Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((List0204b0e8*)background, 0);
    }
    char* var12 = (char*)arg0;
    *(void**)(var12 + Enum_ov012_02185f74_4988) = arg0->unknown_20_[0].Allocate(0x7800);
    for (int var13 = 0; var13 < 13; var13++)
    {
        canvas = &self->canvases[i];
        WindowPane_AllocateBuffer((Obj0204c7a8*)canvas, &self->allocators[0], (int)*(void**)(storage + kPixels), 0x800);
        canvas->background_ = &self->backgrounds[1];
    }
    self->window.backgrounds = self->backgrounds;
    self->window.backgroundCount = 3;
    Window_SetPanes((Struct_0205cf78*)&self->window, (Elem_0205cf78*)self->canvases, 13);
    loader->RemoveTask(*(int*)((char*)self + kTask));
    *(int*)((char*)self + kTask) = -1;
}
