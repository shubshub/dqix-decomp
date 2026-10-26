#include <globaldefs.h>
#if defined(jpn)
enum { kMinimumSize = 0x129e00 };
#else
enum { kMinimumSize = 0x12d0f4 };
#endif

#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory/HPXEAllocator.h"


int GetArenaLow(int index);
int GetArenaHigh(int index);

extern "C" {
    void* AllocateFromArenaLow(int, unsigned int, int);
    void HaltSystem(void);
}

enum {
    kMainArena = 0,          // the arena tables' first entry: low ends at 0x027ffda0, high ends at 0x027ffdc4
    kHeapAlignment = 0x10,   // the heap's start and end are 16-byte aligned
    kForwardAlign4 = 4,      // AllocatorTypeB::alignmentAndDir: positive = allocate forwards, 4-byte aligned
};

// Main, originally InitMainAllocator02012d18 (USA 0x02012d18, EUR 0x02012d28, JPN 0x02012ae0)
ARM void AllocatorUnion_InitMainArenaHeap(AllocatorUnion* allocator) {
    int arenaLow = GetArenaLow(kMainArena);
    int arenaHigh = GetArenaHigh(kMainArena);
    unsigned int heapStart = (arenaLow + (kHeapAlignment - 1)) & ~(kHeapAlignment - 1);
    unsigned int heapEnd = arenaHigh & ~(kHeapAlignment - 1);
    unsigned int size = heapEnd - heapStart;

    void* heapMemory = AllocateFromArenaLow(kMainArena, size, kHeapAlignment);
    HPXEAllocator* heap = HPXEAllocator::CreateAtLocation(heapMemory, size, 0);
    allocator->InitializeTypeB(heap, kForwardAlign4);

    if (size < kMinimumSize) {
        HaltSystem();
    }
}
