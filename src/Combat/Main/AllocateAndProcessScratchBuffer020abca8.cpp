#include <globaldefs.h>
#if defined(jpn)
enum { kStateOffset = 0x5a68 };
#else
enum { kStateOffset = 0x5cc8 };
#endif

#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

extern "C" int func_02075910(int a, void* p, unsigned int size, int c);
extern "C" int func_02075acc(int a, void* p, unsigned int size, int c);

// USA: func_020abca8
ARM int AllocateAndProcessScratchBuffer020abca8() {
    GameState* bs = GameState::GetInstance();
    int zero = 0;
    *(unsigned char*)((char*)bs + kStateOffset) = zero;

    void* alloc = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x6fe4);
    if (alloc != NULL) {
        zero = func_02075910(0x10, alloc, 0x6fe4, zero);
        if (zero != 0) {
            func_02075acc(0x8010, alloc, 0x6fe4, 0);
        }
        AllocatorUnion_Free(&g_mainAllocator, alloc);
    }
    return zero;
}
