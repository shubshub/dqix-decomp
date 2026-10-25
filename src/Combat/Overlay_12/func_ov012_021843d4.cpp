#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "std_library_functions.h"

struct List020727d8;
struct Struct020dfc40;
struct InitTarget0205cfd4;
struct BackgroundGraphics;

extern "C" void func_02074af4(void* p);
extern "C" void func_ov023_021e7220(void* card, int mode);
void ResetListHeader020727d8(List020727d8* list);
void KeyTable_Reset(Struct020dfc40* texts);
void Window_Init(InitTarget0205cfd4* window);
void Background_Init(BackgroundGraphics* background);
extern "C" void WindowPane_Init(void* canvas);
#if defined(jpn)
#define func_ov012_021845f8 func_ov012_02185690
extern "C" void _Z15GridCursor_InitP10GridCursor(void* cursor);
void ClearFields_021e20c0(void* profile);
#endif
extern "C" void func_ov012_021845f8(void* arg0);

struct Struct_02000c9c_40 { char unknown_0_[0x20]; };
struct Struct_02000c9c_41 { char unknown_0_[0xe0]; };

struct Struct_ov012_021843d4
{
#if !defined(jpn)
    void* unknown_0_;
    void* unknown_4_;
#endif
    char unknown_8_[0x10];
    unsigned char unknown_18_;
    unsigned char unknown_19_;
    char unknown_1a_[2];
    int unknown_1c_;
#if defined(jpn)
    SafeAllocator unknown_20_[6];
#else
    SafeAllocator unknown_20_[7];
#endif
    char unknown_ac_[0xbc];
    Struct_02000c9c_40 unknown_168_[3];
    Struct_02000c9c_41 unknown_1c8_[13];
#if defined(jpn)
    char unknown_d28_[0x608];
#else
    char unknown_d28_[0x614];
#endif
    char unknown_133c_[8];
    char unknown_1344_[0x18];
    void* unknown_135c_;
    void* unknown_1360_;
    void* unknown_1364_;
#if !defined(jpn)
    void* unknown_1368_;
    void* unknown_136c_;
#endif
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    char unknown_1372_[2];
    char* unknown_1374_;
    const char* unknown_1378_;
    void* unknown_137c_;
#if defined(jpn)
    int unknown_1380_[4];
#else
    int unknown_1380_[6];
#endif
    int unknown_1398_;
    int unknown_139c_;
    unsigned char unknown_13a0_;
    char unknown_13a1_[3];
    int unknown_13a4_;
    signed char unknown_13a8_;
    signed char unknown_13a9_;
    unsigned char unknown_13aa_;
    unsigned char unknown_13ab_;
#if defined(jpn)
    unsigned char unknown1_1374_;
    unsigned char unknown_1375_;
    char unknown_1376_[2];
    char unknown1_1378_[0x40];
    int unknown_13b8_;
    char unknown_13bc_[0x48];
#endif
    void* unknown_13ac_;
    char* unknown_13b0_;
    void* unknown_13b4_;
    unsigned int unknown1_13b8_;
    char* unknown1_13bc_;
    signed char* unknown_13c0_;
    unsigned short unknown_13c4_0_ : 5;
    unsigned short unknown_13c4_5_ : 11;
    char unknown_13c6_[2];
    unsigned short* unknown_13c8_;
    unsigned int* unknown_13cc_;
    char* unknown_13d0_;
    unsigned int unknown_13d4_;
    int unknown_13d8_[6];
    int unknown_13f0_;
    unsigned int unknown_13f4_;
    unsigned int unknown_13f8_;
    unsigned short unknown_13fc_;
    unsigned char unknown_13fe_;
    unsigned char unknown_13ff_;
    char unknown_1400_[0x40];
    char unknown_1440_[0x40];
#if defined(jpn)
    unsigned char unknown_1480_[0x20];
#else
    unsigned char unknown_1480_[0x3c];
#endif
    unsigned char unknown_14bc_;
    unsigned char unknown_14bd_;
    char unknown_14be_[2];
};

// USA: func_ov012_021843d4
extern "C" ARM void func_ov012_021843d4(Struct_ov012_021843d4* arg0)
{
#if !defined(jpn)
    arg0->unknown_0_ = 0;
    arg0->unknown_4_ = 0;
#endif
    arg0->unknown_18_ = 0;
    arg0->unknown_19_ = 0;
    func_02074af4(arg0->unknown_8_);
    arg0->unknown_1c_ = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    arg0->unknown_14bc_ = 0;
    arg0->unknown_20_[0].ResetAllocatorPointer();
    arg0->unknown_20_[1].ResetAllocatorPointer();
    arg0->unknown_20_[2].ResetAllocatorPointer();
    arg0->unknown_20_[3].ResetAllocatorPointer();
#if defined(jpn)
    arg0->unknown_20_[4].ResetAllocatorPointer();
    arg0->unknown_20_[5].ResetAllocatorPointer();
#else
    arg0->unknown_20_[5].ResetAllocatorPointer();
    arg0->unknown_20_[6].ResetAllocatorPointer();
#endif
    func_ov023_021e7220(self->card_, 2);
    ResetListHeader020727d8((List020727d8*)self->strings_);
    KeyTable_Reset((Struct020dfc40*)self->texts_);
    self->renderer_ = 0;
    self->sprites_ = 0;
    self->unk_1360 = 0;
#if !defined(jpn)
    arg0->unknown_1368_ = 0;
    arg0->unknown_136c_ = 0;
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
    self->result_ = 0;
    self->unk_13a0 = 0;
    self->unk_1398 = 0;
    for (int i = 0; i < (int)(sizeof(self->tasks_) / sizeof(self->tasks_[0])); i++)
        self->tasks_[i] = -1;
    self->unk_13a8 = -1;
    self->unk_13a9 = 0;
    self->unk_13aa = 0;
    self->unk_13ab = 0;
#if defined(jpn)
    self->nameFlag_ = 0;
    self->nameStep_ = 0;
    _Z15GridCursor_InitP10GridCursor(self->nameCursor_);
    self->profileIndex_ = 0;
    ClearFields_021e20c0(self->profile_);
#endif
    arg0->unknown_13ac_ = 0;
    arg0->unknown_13b0_ = 0;
    arg0->unknown_13b4_ = 0;
    arg0->unknown1_13b8_ = 0;
    arg0->unknown1_13bc_ = 0;
    arg0->unknown_13c0_ = 0;
    arg0->unknown_13c4_0_ = 0;
    arg0->unknown_13c4_5_ = 0;
    arg0->unknown_13c8_ = 0;
    arg0->unknown_13cc_ = 0;
    arg0->unknown_13d0_ = 0;
    arg0->unknown_13d4_ = 0;
    arg0->unknown_13f4_ = 0;
    arg0->unknown_13f8_ = 0;
    arg0->unknown_13fc_ = 0;
    arg0->unknown_13fe_ = 0;
    arg0->unknown_13ff_ = 0;
    arg0->unknown_13d8_[0] = -1;
    arg0->unknown_13d8_[1] = -1;
    arg0->unknown_13d8_[2] = -1;
    arg0->unknown_13d8_[3] = -1;
    arg0->unknown_13d8_[4] = -1;
    arg0->unknown_13d8_[5] = -1;
    memset(arg0->unknown_1400_, 0, sizeof(arg0->unknown_1400_));
    memset(arg0->unknown_1440_, 0, sizeof(arg0->unknown_1440_));
    func_ov012_021845f8(arg0->unknown_1480_);
#if !defined(jpn)
    arg0->unknown_14bd_ = 0;
#endif
}
