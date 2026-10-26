#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern int data_021052b4;  // the main screen's OAM buffer
extern int data_021056b4;  // the sub screen's OAM buffer

enum { kOamSize = 0x400 };  // 128 objects of 8 bytes

// Main, originally CleanInvalidateOamBuffers0203bd88 (USA 0x0203bd88, EUR 0x0203bd98, JPN 0x0203b7e0)
extern "C" ARM void OamManager_FlushBuffers(void* oamManager) {
    CleanInvalidateCacheRange((const void*)((int)&data_021052b4), kOamSize);
    CleanInvalidateCacheRange((const void*)((int)&data_021056b4), kOamSize);
}
