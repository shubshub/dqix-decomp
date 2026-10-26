#include <globaldefs.h>
#include "Resource/Brightness.h"

void* GlobalFlags_GetInstance(void);

struct FlagWord02046708;
int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);

int MapDisplay_UploadMapName(void* display, int waitVBlank);
int MapDisplay_UploadTreasureMapName(void* display, int waitVBlank);

// MapDisplay (USA/EUR layout): field9c1, scriptNameWidth, fieldb3c, fieldb40, fieldb42
struct Obj020275e4 {
    char pad0[0x9c1];
    unsigned char mode;
    char pad1[0xbe4 - 0x9c2];
    int nameWidth;
    int scrollOffset;
    short scrollState;
    short delayFrames;
};

enum {
    MapNameScroll_Waiting = 0,
    MapNameScroll_Scrolling = 1,
    MapNameScroll_Done = 2,
};

enum { kScrollDelayFrames = 0x10 };

// Main, originally UpdateTimedBufferState020275e4 (USA 0x020275e4, EUR 0x020275f4; JPN not identified)
ARM void MapDisplay_ScrollMapName(struct Obj020275e4* display) {
    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 0x41)) {
        return;
    }

    int visibleWidth = 0;
    if (display->mode == 0) {
        visibleWidth = 0x90;
    } else if (display->mode == 1) {
        visibleWidth = 0x98;
    }
    if (visibleWidth == 0) {
        return;
    }
    if (visibleWidth >= display->nameWidth) {
        return;
    }
    if (GetBrightness(GetGameResources(), true)) {
        return;
    }

    switch (display->scrollState) {
    case MapNameScroll_Waiting:
        display->delayFrames++;
        if (display->delayFrames >= kScrollDelayFrames) {
            display->delayFrames = 0;
            display->scrollState = MapNameScroll_Scrolling;
        }
        return;
    case MapNameScroll_Scrolling:
        display->scrollOffset++;
        if (display->nameWidth < display->scrollOffset) {
            display->scrollOffset = -visibleWidth;
        }
        if (display->mode == 0) {
            MapDisplay_UploadMapName(display, 0);
        } else {
            MapDisplay_UploadTreasureMapName(display, 0);
        }
        if (display->scrollOffset == 0) {
            display->scrollState = MapNameScroll_Done;
        }
        return;
    }
}
