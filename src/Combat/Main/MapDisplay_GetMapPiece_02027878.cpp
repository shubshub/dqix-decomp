#include <globaldefs.h>

struct Entry_02027878 {
    char unk[0x24];
};

// MapDisplay: names, nameCount
struct List_02027878 {
    char unk[0x20];
    struct Entry_02027878* images;
    int imageCount;
};

// Main, originally GetEntryFromList (USA 0x02027878, EUR 0x02027888, JPN 0x020270e4)
extern "C" ARM struct Entry_02027878* MapDisplay_GetMapPiece(struct List_02027878* display, int index) {
    if (index < 0) {
        goto outOfRange;
    }
    if (display->imageCount > index) {
        goto inRange;
    }
outOfRange:
    return 0;
inRange:
    return &display->images[index];
}
