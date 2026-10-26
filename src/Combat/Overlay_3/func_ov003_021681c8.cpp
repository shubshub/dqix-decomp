#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_021681c8_76 = 0x48 };
#else
enum { Enum_ov003_021681c8_76 = 0x4c };
#endif
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"

struct InitTarget0205cfd4;
struct Struct020dfc40;

extern "C" void func_02074af4(void* obj);
extern "C" void Window_Init(struct InitTarget0205cfd4* s);
extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void WindowPane_Init(void* obj);
extern "C" void SpriteContext_Init(char* obj);
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" void func_ov023_021e20c0(void* p);
extern "C" void func_ov003_02169658(void* obj);

struct Struct_02000c9c_85 {
    unsigned char data[0xe0];
};

struct Struct_ov003_021681c8 {
    SafeAllocator allocs[5];
    unsigned char field_0x64[0x1c];
    unsigned char unknown_80_[Enum_ov003_021681c8_76];
    unsigned char unknown_cc_[0x10];
    unsigned char unknown_dc_;
    unsigned char unknown_dd_;
    unsigned char unknown_de_[2];
    int unknown_e0_;
    unsigned char field_0xe4[0xbc];
    BackgroundGraphics lists[2];
    Struct_02000c9c_85 canvases[3];
    char field_0x480[0x54];
    int unknown_4d4_;
    int unknown_4d8_;
    int unknown_4dc_;
    unsigned char unknown_4e0_[8];
    unsigned char unknown_4e8_;
    unsigned char unknown_4e9_;
    unsigned char unknown_4ea_;
    unsigned char unknown_4eb_;
    unsigned char unknown_4ec_;
    unsigned char unknown_4ed_;
    unsigned char unknown_4ee_;
    unsigned char unknown_4ef_[4];
    unsigned char unknown_4f3_[4];
    unsigned char unknown_4f7_;
    int unknown_4f8_;
    unsigned char unknown_4fc_[0xa3];
    unsigned char unknown_59f_;
    int unknown_5a0_;
    unsigned char unknown_5a4_;
    unsigned char unknown_5a5_;
};

// USA: func_ov003_021681c8
extern "C" ARM void func_ov003_021681c8(Struct_ov003_021681c8* view) {
    view->unknown_dc_ = 0;
    view->unknown_dd_ = 0;
    func_02074af4(view->unknown_cc_);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    view->unknown_e0_ = (*dispcnt & 0x1f00) >> 8;
    *dispcnt = (*dispcnt & ~0x1f00) | 0x100;

    view->allocs[4].ResetAllocatorPointer();
    view->allocs[3].ResetAllocatorPointer();
    view->allocs[2].ResetAllocatorPointer();
    view->allocs[1].ResetAllocatorPointer();
    view->allocs[0].ResetAllocatorPointer();

    Window_Init((struct InitTarget0205cfd4*)view->field_0xe4);
    for (int i = 0; i < 2; i++) {
        Background_Init(&view->lists[i]);
    }
    for (int i = 0; i < 3; i++) {
        WindowPane_Init(&view->canvases[i]);
    }
    SpriteContext_Init(view->field_0x480);
    view->unknown_4d4_ = 0;
    view->unknown_4d8_ = 0;
    KeyTable_Reset((struct Struct020dfc40*)view->field_0x64);
    func_ov023_021e20c0(view->unknown_80_);

    view->unknown_4dc_ = 0;
    view->unknown_4ec_ = 0;
    view->unknown_4e8_ = 0;
    view->unknown_4e9_ = 0;
    view->unknown_4ea_ = 0;
    view->unknown_4eb_ = 0;
    view->unknown_4ed_ = 0;
    view->unknown_4ee_ = 0;
    for (int i = 0; i < 4; i++) {
        view->unknown_4ef_[i] = 0;
    }
    for (int i = 0; i < 4; i++) {
        view->unknown_4f3_[i] = 0;
    }
    view->unknown_4f8_ = 0;
    view->unknown_5a0_ = 0;
    view->unknown_5a4_ = 0;
    view->unknown_5a5_ = 0;
    view->unknown_59f_ = 0;
    func_ov003_02169658(view);
}
