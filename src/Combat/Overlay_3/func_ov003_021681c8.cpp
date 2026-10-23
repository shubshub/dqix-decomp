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
void InitStruct0205cfd4(struct InitTarget0205cfd4* s);
void Background_Init(struct List0204af64* obj);
extern "C" void func_0204c684(void* obj);
void SpriteContext_Init(char* obj);
void KeyTable_Reset(struct Struct020dfc40* p);
void ClearFields_021e20c0(void* p);
void ClearFlagFields_02169658(void* obj);

struct Struct_02000c9c_85 {
    unsigned char unknown_0_[0xe0];
};

struct Struct_ov003_021681c8 {
    SafeAllocator unknown_0_[5];
    unsigned char unknown_64_[0x1c];
    unsigned char unknown_80_[Enum_ov003_021681c8_76];
    unsigned char unknown_cc_[0x10];
    unsigned char unknown_dc_;
    unsigned char unknown_dd_;
    unsigned char unknown_de_[2];
    int unknown_e0_;
    unsigned char unknown_e4_[0xbc];
    Struct_02020cb8 unknown_1a0_[2];
    Struct_02000c9c_85 unknown_1e0_[3];
    char unknown_480_[0x54];
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

    InitStruct0205cfd4((struct InitTarget0205cfd4*)view->field_0xe4);
    for (int i = 0; i < 2; i++) {
        Background_Init(&view->lists[i]);
    }
    for (int var2 = 0; var2 < 3; var2++) {
        func_0204c684(&arg0->unknown_1e0_[var2]);
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
