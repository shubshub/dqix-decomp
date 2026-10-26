#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// MapDisplay: forwarding, forwardingCount, field34
struct Array020278e4 {
    char pad[0x2c];
    void* placements;
    int placementCount;
    int placementCapacity;
};

enum { kMapImagePlacementSize = 0x10 };

// Main, originally AllocateArray020278e4 (USA 0x020278e4, EUR 0x020278f4, JPN 0x02027150)
extern "C" ARM void MapDisplay_AllocatePlacements(struct Array020278e4* display, int capacity, SafeAllocator* allocator) {
    display->placements = allocator->Allocate(capacity * kMapImagePlacementSize);
    display->placementCount = 0;
    display->placementCapacity = capacity;
}
