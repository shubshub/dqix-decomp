#include <globaldefs.h>

extern char data_020fe9cc;
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void LoadToMainBG1ScreenData(void* data, int offset, int size);

// A 32x24-tile BG screen map.
enum { kScreenBytes = 32 * 24 * sizeof(unsigned short) };

// Main, originally FlushAndClearBuffer0202adf0 (USA 0x0202adf0, EUR 0x0202ae00, JPN 0x0202a9a8)
extern "C" ARM void DebugConsole_Upload() {
    CleanInvalidateCacheRange((const void*)((int)&data_020fe9cc), kScreenBytes);
    LoadToMainBG1ScreenData(&data_020fe9cc, 0, kScreenBytes);
}
