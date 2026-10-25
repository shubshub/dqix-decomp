#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_0217cd24_52 = 0x30 };
enum { Enum_ov003_0217cd24_144 = 0x8c };
enum { Enum_ov003_0217cd24_60 = 0x38 };
#else
enum { Enum_ov003_0217cd24_52 = 0x34 };
enum { Enum_ov003_0217cd24_144 = 0x90 };
enum { Enum_ov003_0217cd24_60 = 0x3c };
#endif


struct InitTarget0205cfd4;
ARM void Window_Init(struct InitTarget0205cfd4* s);
struct BackgroundGraphics;
ARM void Background_Init(struct BackgroundGraphics* obj);
extern "C" void WindowPane_Init(void* obj);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234* target);

struct Struct_ov003_0217cd24 {
    char unknown_0_[Enum_ov003_0217cd24_52];
    void* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[Enum_ov003_0217cd24_144 - Enum_ov003_0217cd24_60];
    void* unknown_90_;
    void* unknown_94_;
    void* unknown_98_;
    char unknown_9c_[4];
    SafeAllocator* unknown_a0_;
    SafeAllocator unknown_a4_;
    SafeAllocator unknown_b8_;
};

// USA: func_ov003_0217cd24
extern "C" ARM void func_ov003_0217cd24(void* arg0, SafeAllocator* arg1) {
    if (arg1 == 0) return;
    struct Struct_ov003_0217cd24* var0 = (struct Struct_ov003_0217cd24*)arg0;

    obj->alloc = allocator;
    obj->p90 = obj->alloc->Allocate(0xbc);
    obj->p94 = obj->alloc->Allocate(0x40);
    obj->p98 = obj->alloc->Allocate(0xe0);
    Window_Init((struct InitTarget0205cfd4*)obj->p90);

    for (int i = 0; i < 2; i++) {
        Background_Init((struct BackgroundGraphics*)((char*)obj->p94 + i * 0x20));
    }
    for (int i = 0; i < 1; i++) {
        WindowPane_Init((char*)obj->p98 + i * 0xe0);
    }

    var0->unknown_34_ = var0->unknown_a0_->Allocate(0x118);
    var0->unknown_38_ = var0->unknown_a0_->Allocate(8);

    for (int i = 0; i < 7; i++) {
        Sprite_Init((struct Struct0205a198*)((char*)obj->p34 + i * 0x28));
    }
    func_0205a234((struct Struct_02043368*)var0->unknown_38_);

    void* var4 = var0->unknown_a0_->Allocate(0x800);
    var0->unknown_a4_.CreateTypeA(var4, 0x800);

    void* var5 = var0->unknown_a0_->Allocate(0x400);
    var0->unknown_b8_.CreateTypeA(var5, 0x400);
}
