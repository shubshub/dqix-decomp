#include <globaldefs.h>

extern "C" void LoadToSubBG0ScreenData(int data, int offset, unsigned int length);
extern "C" void LoadToSubBG1ScreenData(int data, int offset, unsigned int length);

// The sub screen's BG1 and BG0 screen buffers
extern char data_02105fd8[] __attribute__((aligned(4)));
extern char data_021065d8[];

enum {
    kScreenDirtyFlags = 0x40,   // bgTransfers: one word per (screen, bg), set by BgTransfers_PlaceMap
    kSubBg0ScreenSize = 0x1000, // 64 x 32 map entries
    kSubBg1ScreenSize = 0x600   // 32 x 24 map entries
};

// Main, originally func_0203ba74 (USA 0x0203ba74, EUR 0x0203ba84, JPN 0x0203b4cc)
extern "C" ARM void BgTransfers_UploadDirtyScreens(void* bgTransfersPtr) {
    char* bgTransfers = (char*)bgTransfersPtr;
    for (int screen = 0; screen < 2; screen++) {
        for (int bg = 0; bg < 4; bg++) {
            unsigned char zero = 0;
            zero = zero + 0;
            int* dirty = (int*)(bgTransfers + (bg + screen * 4) * 4 + kScreenDirtyFlags);
            if (*dirty != 0) {
                *dirty = zero;
                if (screen == 1) {
                    switch (bg) {
                    case 0: LoadToSubBG0ScreenData((int)data_021065d8, zero, kSubBg0ScreenSize); break;
                    case 1: LoadToSubBG1ScreenData((int)data_02105fd8, zero, kSubBg1ScreenSize); break;
                    }
                }
            }
        }
    }
}
