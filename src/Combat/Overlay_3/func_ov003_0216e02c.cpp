#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ClearTarget0205a234;
extern "C" void func_0205a234(struct ClearTarget0205a234* target);

struct BackgroundGraphics;
extern "C" void Background_Init(struct BackgroundGraphics* obj);

extern "C" void WindowPane_Init(char* obj);

struct InitTarget0205cfd4;
extern "C" void Window_Init(struct InitTarget0205cfd4* s);

extern "C" void func_ov023_021e20c0(void* p);

#if defined(jpn)
struct Struct0205a198;
extern "C" void Sprite_Init(struct Struct0205a198* s);
#define BLOCK60_SIZE 0x190
#define BLOCKD4_SIZE 0x48
#else
#define BLOCK60_SIZE 0x370
#define BLOCKD4_SIZE 0x4c
#endif

// USA: func_ov003_0216e02c
extern "C" ARM void func_ov003_0216e02c(char* self, SafeAllocator* alloc) {
    if (alloc == 0) {
        return;
    }

    *(SafeAllocator**)(self + 0xd0) = alloc;
    *(void**)(self + 0x3c) = alloc->Allocate(0xbc);
    *(void**)(self + 0x40) = (*(SafeAllocator**)(self + 0xd0))->Allocate(0x40);
    *(void**)(self + 0x44) = (*(SafeAllocator**)(self + 0xd0))->Allocate(0x1c0);
    *(void**)(self + 0x60) = (*(SafeAllocator**)(self + 0xd0))->Allocate(BLOCK60_SIZE);
    *(void**)(self + 0x64) = (*(SafeAllocator**)(self + 0xd0))->Allocate(8);
    *(void**)(self + 0xd4) = (*(SafeAllocator**)(self + 0xd0))->Allocate(BLOCKD4_SIZE);

#if defined(jpn)
    for (int i = 0; i < 10; i++) {
        int off = i * 0x28;
        Sprite_Init((struct Struct0205a198*)(*(char**)(self + 0x60) + off));
        *(*(char**)(self + 0x60) + off + 0x26) = 1;
    }
#endif

    func_0205a234((struct ClearTarget0205a234*)*(void**)(self + 0x64));

    void* buf = (*(SafeAllocator**)(self + 0xd0))->Allocate(0x400);
    ((SafeAllocator*)(self + 0xbc))->CreateTypeA(buf, 0x400);
    ((SafeAllocator*)(self + 0xbc))->Reset();

    Window_Init((struct InitTarget0205cfd4*)*(void**)(self + 0x3c));

    for (int i = 0; i < 2; i++) {
        Background_Init((struct BackgroundGraphics*)(*(char**)(self + 0x40) + (i << 5)));
    }

    for (int i = 0; i < 2; i++) {
        WindowPane_Init(*(char**)(self + 0x44) + i * 0xe0);
    }

    func_ov023_021e20c0(*(void**)(self + 0xd4));
}
