#include <globaldefs.h>

struct Entry_020278a4 {
    int id;
    char unk[0x20];
};

// MapDisplay: names, nameCount
struct List_020278a4 {
    char unk[0x20];
    struct Entry_020278a4* images;
    int imageCount;
};

// Main, originally FindEntryIndexById (USA 0x020278a4, EUR 0x020278b4, JPN 0x02027110)
ARM int MapDisplay_FindPieceIndex(struct List_020278a4* display, int id) {
    int i;
    for (i = 0; i < display->imageCount; i++) {
        if (id == display->images[i].id) {
            return i;
        }
    }
    return -1;
}
