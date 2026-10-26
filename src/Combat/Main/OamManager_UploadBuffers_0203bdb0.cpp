#include <globaldefs.h>
// The CachedTextTable's nextOamEntry (the table is at +0x10) and the OAM entry its texts start at again
#if defined(jpn)
enum { kTextNextOamEntry = 0x620 };
enum { kFirstTextOamEntry = 0 };
#else
enum { kTextNextOamEntry = 0x520 };
enum { kFirstTextOamEntry = 4 };
#endif

#include "NitroSDK/DMA.h"

extern "C" int LoadToMainOAM(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubOAM(int arg0, int arg1, unsigned int arg2);

extern int data_021052b4;  // the main screen's OAM buffer
extern int data_021056b4;  // the sub screen's OAM buffer

enum {
    kOamSize = 0x400,     // 128 objects of 8 bytes
    kOffscreenY = 0xc0    // attribute 0 with Y = 192: below the screen, so the object is hidden
};

struct Obj0203bdb0 {
    char pad[0xc];
    unsigned char uploadMainOam;
    unsigned char uploadSubOam;
};

// Main, originally SyncMainSubOam0203bdb0 (USA 0x0203bdb0, EUR 0x0203bdc0, JPN 0x0203b808)
extern "C" ARM void OamManager_UploadBuffers(struct Obj0203bdb0* oamManager) {
    if (oamManager->uploadMainOam != 0) {
        LoadToMainOAM((int)&data_021052b4, 0, kOamSize);
        DMAMemsetSynchronous(3, (unsigned int)&data_021052b4, kOffscreenY, kOamSize);
    }
    if (oamManager->uploadSubOam != 0) {
        LoadToSubOAM((int)&data_021056b4, 0, kOamSize);
        DMAMemsetSynchronous(3, (unsigned int)&data_021056b4, kOffscreenY, kOamSize);
    }
    if (oamManager->uploadMainOam != 0 || oamManager->uploadSubOam != 0) {
        *(short*)((char*)oamManager + kTextNextOamEntry) = kFirstTextOamEntry;
    }
}
