#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_021681c8_76 = 0x48 };
#else
enum { Enum_ov003_021681c8_76 = 0x4c };
#endif
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"

struct Struct_0205cfd4;
struct Struct_0201099c_14;

extern "C" void func_02074af4(void* obj);
void Window_Init(struct InitTarget0205cfd4* s);
void Background_Init(struct BackgroundGraphics* obj);
extern "C" void WindowPane_Init(void* obj);
void SpriteContext_Init(char* obj);
void KeyTable_Reset(struct Struct020dfc40* p);
void ClearFields_021e20c0(void* p);
void ClearFlagFields_02169658(void* obj);

struct Struct_02000c9c_85 {
    unsigned char unknown_0_[0xe0];
};

struct BattleView021681c8 {
    SafeAllocator allocs[5];
    unsigned char field_0x64[0x1c];
    unsigned char field_0x80[kRegion4c];
    unsigned char field_0xcc[0x10];
    unsigned char field_0xdc;
    unsigned char field_0xdd;
    unsigned char pad_0xde[2];
    int savedBgMode;
    unsigned char field_0xe4[0xbc];
    BackgroundGraphics lists[2];
    CanvasSlot021681c8 canvases[3];
    char field_0x480[0x54];
    int field_0x4d4;
    int field_0x4d8;
    int field_0x4dc;
    unsigned char pad_0x4e0[8];
    unsigned char field_0x4e8;
    unsigned char field_0x4e9;
    unsigned char field_0x4ea;
    unsigned char field_0x4eb;
    unsigned char field_0x4ec;
    unsigned char field_0x4ed;
    unsigned char field_0x4ee;
    unsigned char field_0x4ef[4];
    unsigned char field_0x4f3[4];
    unsigned char pad_0x4f7;
    int field_0x4f8;
    unsigned char pad_0x4fc[0xa3];
    unsigned char field_0x59f;
    int field_0x5a0;
    unsigned char field_0x5a4;
    unsigned char field_0x5a5;
};

// USA: func_ov003_021681c8
extern "C" ARM void func_ov003_021681c8(Struct_ov003_021681c8* arg0) {
    arg0->unknown_dc_ = 0;
    arg0->unknown_dd_ = 0;
    func_02074af4(arg0->unknown_cc_);

    volatile unsigned int* var0 = (volatile unsigned int*)0x4000000;
    arg0->unknown_e0_ = (*var0 & 0x1f00) >> 8;
    *var0 = (*var0 & ~0x1f00) | 0x100;

    arg0->unknown_0_[4].ResetAllocatorPointer();
    arg0->unknown_0_[3].ResetAllocatorPointer();
    arg0->unknown_0_[2].ResetAllocatorPointer();
    arg0->unknown_0_[1].ResetAllocatorPointer();
    arg0->unknown_0_[0].ResetAllocatorPointer();

    Window_Init((struct InitTarget0205cfd4*)view->field_0xe4);
    for (int i = 0; i < 2; i++) {
        Background_Init(&view->lists[i]);
    }
    for (int i = 0; i < 3; i++) {
        WindowPane_Init(&view->canvases[i]);
    }
    SpriteContext_Init(view->field_0x480);
    view->field_0x4d4 = 0;
    view->field_0x4d8 = 0;
    KeyTable_Reset((struct Struct020dfc40*)view->field_0x64);
    ClearFields_021e20c0(view->field_0x80);

    arg0->unknown_4dc_ = 0;
    arg0->unknown_4ec_ = 0;
    arg0->unknown_4e8_ = 0;
    arg0->unknown_4e9_ = 0;
    arg0->unknown_4ea_ = 0;
    arg0->unknown_4eb_ = 0;
    arg0->unknown_4ed_ = 0;
    arg0->unknown_4ee_ = 0;
    for (int var3 = 0; var3 < 4; var3++) {
        arg0->unknown_4ef_[var3] = 0;
    }
    for (int var4 = 0; var4 < 4; var4++) {
        arg0->unknown_4f3_[var4] = 0;
    }
    arg0->unknown_4f8_ = 0;
    arg0->unknown_5a0_ = 0;
    arg0->unknown_5a4_ = 0;
    arg0->unknown_5a5_ = 0;
    arg0->unknown_59f_ = 0;
    func_ov003_02169658(arg0);
}
