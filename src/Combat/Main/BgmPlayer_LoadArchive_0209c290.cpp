#include <globaldefs.h>

extern int data_020f1730;
extern int data_ov032_02200180;

extern "C" int SoundPlayer_OpenArchive(void*, void*, void*, int, int);

// Main, originally Dispatch0203a974With0x57000_0209c290 (USA 0x0209c290, EUR 0x0209c2a0, JPN 0x0209e008)
extern "C" ARM int BgmPlayer_LoadArchive(void* ctx) {
    return SoundPlayer_OpenArchive(ctx, &data_020f1730, &data_ov032_02200180, 0x57000, 1);
}
