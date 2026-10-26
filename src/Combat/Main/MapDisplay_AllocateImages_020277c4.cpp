#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// MapDisplay: names, nameCount, field28
struct Struct020277c4 {
    char pad[0x20];
    void* images;
    int imageCount;
    int imageCapacity;
};

enum { kMapImageSize = 0x24 };

// Main, originally InitEntryList020277c4 (USA 0x020277c4, EUR 0x020277d4, JPN 0x02027030)
extern "C" ARM void MapDisplay_AllocateImages(struct Struct020277c4* display, int capacity, SafeAllocator* allocator) {
    display->images = allocator->Allocate(capacity * kMapImageSize);
    display->imageCount = 0;
    display->imageCapacity = capacity;
}
