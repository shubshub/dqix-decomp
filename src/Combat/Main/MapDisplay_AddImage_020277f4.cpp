#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

// MapDisplay's Entry02021578
struct MapImage {
    int id;
    char* fileName;
    char pad[0x1c];
};

// MapDisplay: names, nameCount, field28
struct MapDisplayImages {
    char pad0[0x20];
    MapImage* images;
    int imageCount;
    int imageCapacity;
};

// Main, originally func_020277f4 (USA 0x020277f4, EUR 0x02027804, JPN 0x02027060)
extern "C" ARM void MapDisplay_AddImage(MapDisplayImages* display, int id, const char* fileName, void* allocator) {
    if (display->imageCapacity <= display->imageCount) return;
    display->images[display->imageCount].id = id;
    char* copy = (char*)((SafeAllocator*)allocator)->Allocate(strlen(fileName) + 1);
    display->images[display->imageCount].fileName = copy;
    strcpy(display->images[display->imageCount].fileName, fileName);
    display->imageCount = display->imageCount + 1;
}
