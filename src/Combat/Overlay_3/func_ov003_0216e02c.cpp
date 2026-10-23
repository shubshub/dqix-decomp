#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02043368;
extern "C" void func_0205a234(struct Struct_02043368* arg0);

struct List0204af64;
extern void Background_Init(struct List0204af64* obj);

extern "C" void func_0204c684(char* arg0);

struct Struct_0205cfd4;
extern "C" void func_0205cfd4(struct Struct_0205cfd4* arg0);

extern "C" void func_ov023_021e20c0(void* arg0);

#if defined(jpn)
struct Struct0205a198;
extern void Sprite_Init(struct Struct0205a198* s);
#define BLOCK60_SIZE 0x190
#define BLOCKD4_SIZE 0x48
#else
#define BLOCK60_SIZE 0x370
#define BLOCKD4_SIZE 0x4c
#endif

// USA: func_ov003_0216e02c
extern "C" ARM void func_ov003_0216e02c(char* arg0, SafeAllocator* arg1) {
    if (arg1 == 0) {
        return;
    }

    *(SafeAllocator**)(arg0 + 0xd0) = arg1;
    *(void**)(arg0 + 0x3c) = arg1->Allocate(0xbc);
    *(void**)(arg0 + 0x40) = (*(SafeAllocator**)(arg0 + 0xd0))->Allocate(0x40);
    *(void**)(arg0 + 0x44) = (*(SafeAllocator**)(arg0 + 0xd0))->Allocate(0x1c0);
    *(void**)(arg0 + 0x60) = (*(SafeAllocator**)(arg0 + 0xd0))->Allocate(BLOCK60_SIZE);
    *(void**)(arg0 + 0x64) = (*(SafeAllocator**)(arg0 + 0xd0))->Allocate(8);
    *(void**)(arg0 + 0xd4) = (*(SafeAllocator**)(arg0 + 0xd0))->Allocate(BLOCKD4_SIZE);

#if defined(jpn)
    for (int i = 0; i < 10; i++) {
        int off = i * 0x28;
        Sprite_Init((struct Struct0205a198*)(*(char**)(self + 0x60) + off));
        *(*(char**)(self + 0x60) + off + 0x26) = 1;
    }
#endif

    func_0205a234((struct Struct_02043368*)*(void**)(arg0 + 0x64));

    void* var2 = (*(SafeAllocator**)(arg0 + 0xd0))->Allocate(0x400);
    ((SafeAllocator*)(arg0 + 0xbc))->CreateTypeA(var2, 0x400);
    ((SafeAllocator*)(arg0 + 0xbc))->Reset();

    func_0205cfd4((struct Struct_0205cfd4*)*(void**)(arg0 + 0x3c));

    for (int i = 0; i < 2; i++) {
        Background_Init((struct List0204af64*)(*(char**)(self + 0x40) + (i << 5)));
    }

    for (int var4 = 0; var4 < 2; var4++) {
        func_0204c684(*(char**)(arg0 + 0x44) + var4 * 0xe0);
    }

    func_ov023_021e20c0(*(void**)(arg0 + 0xd4));
}
