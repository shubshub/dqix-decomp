#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_0216ae0c_4708 = 0x10f4 };
enum { Enum_ov003_0216ae0c_4800 = 0x1150 };
enum { kRegionValue126C_10FC = 0x10fc };
enum { Enum_ov003_0216ae0c_4816 = 0x1160 };
enum { Enum_ov003_0216ae0c_4812 = 0x115c };
#else
enum { Enum_ov003_0216ae0c_4708 = 0x1264 };
enum { Enum_ov003_0216ae0c_4800 = 0x12c0 };
enum { kRegionValue126C_10FC = 0x126c };
enum { Enum_ov003_0216ae0c_4816 = 0x12d0 };
enum { Enum_ov003_0216ae0c_4812 = 0x12cc };
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

struct Struct_ov003_0216ae0c {
    char pad0[Enum_ov003_0216ae0c_4708];
    void* p264;
    void* unknown_1268_;
    char pad1[Enum_ov003_0216ae0c_4800 - kRegionValue126C_10FC];
    void* p2c0;
    void* p2c4;
    void* p2c8;
    char pad2[Enum_ov003_0216ae0c_4816 - Enum_ov003_0216ae0c_4812];
    SafeAllocator* alloc;
};

// USA: func_ov003_0216ae0c
extern "C" ARM void func_ov003_0216ae0c(void* objRaw, SafeAllocator* allocator) {
    if (allocator == 0) return;
    struct Struct_ov003_0216ae0c* obj = (struct Struct_ov003_0216ae0c*)objRaw;

    obj->alloc = allocator;
    obj->p2c0 = obj->alloc->Allocate(0xbc);
    obj->p2c4 = obj->alloc->Allocate(0x40);
    obj->p2c8 = obj->alloc->Allocate(0xe0);
    Window_Init((struct InitTarget0205cfd4*)obj->p2c0);

    for (int i = 0; i < 2; i++) {
        Background_Init((struct BackgroundGraphics*)((char*)obj->p2c4 + i * 0x20));
    }
    for (int i = 0; i < 1; i++) {
        WindowPane_Init((char*)obj->p2c8 + i * 0xe0);
    }

    obj->p264 = obj->alloc->Allocate(0x258);
    obj->unknown_1268_ = obj->alloc->Allocate(8);

    for (int i = 0; i < 0xf; i++) {
        Sprite_Init((struct Struct0205a198*)((char*)obj->p264 + i * 0x28));
    }
    func_0205a234((struct ClearTarget0205a234*)obj->unknown_1268_);
}
