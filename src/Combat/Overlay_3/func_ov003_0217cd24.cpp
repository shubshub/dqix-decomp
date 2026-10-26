#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_0217cd24_52 = 0x30 };
enum { kRegionValue90_8C = 0x8c };
enum { kRegionValue3C_38 = 0x38 };
#else
enum { Enum_ov003_0217cd24_52 = 0x34 };
enum { kRegionValue90_8C = 0x90 };
enum { kRegionValue3C_38 = 0x3c };
#endif


struct InitTarget0205cfd4;
extern "C" ARM void Window_Init(struct InitTarget0205cfd4* s);
struct BackgroundGraphics;
extern "C" ARM void Background_Init(struct BackgroundGraphics* obj);
extern "C" void WindowPane_Init(void* obj);
struct Struct0205a198;
extern "C" void Sprite_Init(struct Struct0205a198*);
struct ClearTarget0205a234;
extern "C" void func_0205a234(struct ClearTarget0205a234* target);

struct Struct_ov003_0217cd24 {
    char pad0[Enum_ov003_0217cd24_52];
    void* p34;
    void* unknown_38_;
    char pad1[kRegionValue90_8C - kRegionValue3C_38];
    void* p90;
    void* p94;
    void* p98;
    char pad2[4];
    SafeAllocator* alloc;
    SafeAllocator unknown_a4_;
    SafeAllocator unknown_b8_;
};

// USA: func_ov003_0217cd24
extern "C" ARM void func_ov003_0217cd24(void* objRaw, SafeAllocator* allocator) {
    if (allocator == 0) return;
    struct Struct_ov003_0217cd24* obj = (struct Struct_ov003_0217cd24*)objRaw;

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

    obj->p34 = obj->alloc->Allocate(0x118);
    obj->unknown_38_ = obj->alloc->Allocate(8);

    for (int i = 0; i < 7; i++) {
        Sprite_Init((struct Struct0205a198*)((char*)obj->p34 + i * 0x28));
    }
    func_0205a234((struct ClearTarget0205a234*)obj->unknown_38_);

    void* buf1 = obj->alloc->Allocate(0x800);
    obj->unknown_a4_.CreateTypeA(buf1, 0x800);

    void* buf2 = obj->alloc->Allocate(0x400);
    obj->unknown_b8_.CreateTypeA(buf2, 0x400);
}
