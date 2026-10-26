#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "std_library_functions.h"

struct Struct_020727d8;
struct Struct020dfc40;
struct InitTarget0205cfd4;
struct BackgroundGraphics;

extern "C" void func_02074af4(void* p);
extern "C" void func_ov023_021e7220(void* arg0, int mode);
extern "C" void func_020727d8(Struct_020727d8* list);
extern "C" void KeyTable_Reset(Struct020dfc40* texts);
extern "C" void Window_Init(InitTarget0205cfd4* window);
extern "C" void Background_Init(BackgroundGraphics* background);
extern "C" void WindowPane_Init(void* canvas);
#if defined(jpn)
#define func_ov012_021845f8 func_ov012_02185690
extern "C" void GridCursor_Init(void* cursor);
extern "C" void func_ov023_021e20c0(void* profile);
#endif
extern "C" void func_ov012_021845f8(void* checker);

struct Struct_02000c9c_40 { char raw[0x20]; };
struct Struct_02000c9c_41 { char raw[0xe0]; };

struct Struct_ov012_021843d4
{
#if !defined(jpn)
    void* unk_0;
    void* unk_4;
#endif
    char unk_8[0x10];
    unsigned char unknown_18_;
    unsigned char unknown_19_;
    char unk_1a[2];
    int unknown_1c_;
#if defined(jpn)
    SafeAllocator allocators_[6];
#else
    SafeAllocator allocators_[7];
#endif
    char window_[0xbc];
    Struct_02000c9c_40 backgrounds_[3];
    Struct_02000c9c_41 canvases_[13];
#if defined(jpn)
    char card_[0x608];
#else
    char card_[0x614];
#endif
    char strings_[8];
    char texts_[0x18];
    void* renderer_;
    void* unk_1360;
    void* sprites_;
#if !defined(jpn)
    void* unknown_1368_;
    void* unknown_136c_;
#endif
    unsigned char step_;
    unsigned char state_;
    char unknown_1372_[2];
    char* text_;
    const char* unk_1378;
    void* pixels_;
#if defined(jpn)
    int tasks_[4];
#else
    int tasks_[6];
#endif
    int unk_1398;
    int unknown_139c_;
    unsigned char unknown_13a0_;
    char unknown_13a1_[3];
    int unk_13a4;
    signed char unknown_13a8_;
    signed char unknown_13a9_;
    unsigned char unknown_13aa_;
    unsigned char unknown_13ab_;
#if defined(jpn)
    unsigned char unknown1_1374_;
    unsigned char unknown_1375_;
    char unknown_1376_[2];
    char nameCursor_[0x40];
    int unknown_13b8_;
    char unknown_13bc_[0x48];
#endif
    void* unknown_13ac_;
    char* name_;
    void* unknown_13b4_;
    unsigned int unknown1_13b8_;
    char* unknown1_13bc_;
    signed char* unk_13c0;
    unsigned short unknown_13c4_0_ : 5;
    unsigned short unknown_13c4_5_ : 11;
    char unknown_13c6_[2];
    unsigned short* unk_13c8;
    unsigned int* unknown_13cc_;
    char* message_;
    unsigned int selection_;
    int selections_[6];
    int unknown_13f0_;
    unsigned int unknown_13f4_;
    unsigned int unk_13f8;
    unsigned short unknown_13fc_;
    unsigned char unknown_13fe_;
    unsigned char unknown_13ff_;
    char unknown_1400_[0x40];
    char titleText_[0x40];
#if defined(jpn)
    unsigned char unknown_1480_[0x20];
#else
    unsigned char unknown_1480_[0x3c];
#endif
    unsigned char finished_;
    unsigned char unknown_14bd_;
    char unknown_14be_[2];
};

// USA: func_ov012_021843d4
extern "C" ARM void func_ov012_021843d4(Struct_ov012_021843d4* self)
{
#if !defined(jpn)
    self->unk_0 = 0;
    self->unk_4 = 0;
#endif
    self->unknown_18_ = 0;
    self->unknown_19_ = 0;
    func_02074af4(self->unk_8);
    self->unknown_1c_ = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    self->finished_ = 0;
    self->allocators_[0].ResetAllocatorPointer();
    self->allocators_[1].ResetAllocatorPointer();
    self->allocators_[2].ResetAllocatorPointer();
    self->allocators_[3].ResetAllocatorPointer();
#if defined(jpn)
    self->allocators_[4].ResetAllocatorPointer();
    self->allocators_[5].ResetAllocatorPointer();
#else
    self->allocators_[5].ResetAllocatorPointer();
    self->allocators_[6].ResetAllocatorPointer();
#endif
    func_ov023_021e7220(self->card_, 2);
    func_020727d8((Struct_020727d8*)self->strings_);
    KeyTable_Reset((Struct020dfc40*)self->texts_);
    self->renderer_ = 0;
    self->sprites_ = 0;
    self->unk_1360 = 0;
#if !defined(jpn)
    self->unknown_1368_ = 0;
    self->unknown_136c_ = 0;
#endif
    Window_Init((InitTarget0205cfd4*)self->window_);
    for (int i = 0; i < 3; i++)
        Background_Init((BackgroundGraphics*)&self->backgrounds_[i]);
    for (int i = 0; i < 13; i++)
        WindowPane_Init(&self->canvases_[i]);
    self->step_ = 0;
    self->state_ = 0;
    self->text_ = 0;
    self->pixels_ = 0;
    self->unk_1378 = 0;
    self->unknown_139c_ = 0;
    self->unknown_13a0_ = 0;
    self->unk_1398 = 0;
    for (int i = 0; i < (int)(sizeof(self->tasks_) / sizeof(self->tasks_[0])); i++)
        self->tasks_[i] = -1;
    self->unknown_13a8_ = -1;
    self->unknown_13a9_ = 0;
    self->unknown_13aa_ = 0;
    self->unknown_13ab_ = 0;
#if defined(jpn)
    self->unknown1_1374_ = 0;
    self->unknown_1375_ = 0;
    GridCursor_Init(self->nameCursor_);
    self->unknown_13b8_ = 0;
    func_ov023_021e20c0(self->unknown_13bc_);
#endif
    self->unknown_13ac_ = 0;
    self->name_ = 0;
    self->unknown_13b4_ = 0;
    self->unknown1_13b8_ = 0;
    self->unknown1_13bc_ = 0;
    self->unk_13c0 = 0;
    self->unknown_13c4_0_ = 0;
    self->unknown_13c4_5_ = 0;
    self->unk_13c8 = 0;
    self->unknown_13cc_ = 0;
    self->message_ = 0;
    self->selection_ = 0;
    self->unknown_13f4_ = 0;
    self->unk_13f8 = 0;
    self->unknown_13fc_ = 0;
    self->unknown_13fe_ = 0;
    self->unknown_13ff_ = 0;
    self->selections_[0] = -1;
    self->selections_[1] = -1;
    self->selections_[2] = -1;
    self->selections_[3] = -1;
    self->selections_[4] = -1;
    self->selections_[5] = -1;
    memset(self->unknown_1400_, 0, sizeof(self->unknown_1400_));
    memset(self->titleText_, 0, sizeof(self->titleText_));
    func_ov012_021845f8(self->unknown_1480_);
#if !defined(jpn)
    self->unknown_14bd_ = 0;
#endif
}
