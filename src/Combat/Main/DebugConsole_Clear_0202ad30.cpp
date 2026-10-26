#include <globaldefs.h>

extern "C" void MIi_CpuClearFast(unsigned int value, void* destination, int size);
extern char data_020fe9cc;

// A 32x24-tile BG screen map.
enum { kScreenBytes = 32 * 24 * sizeof(unsigned short) };

// Main, originally ClearBuffer0202ad30 (USA 0x0202ad30, EUR 0x0202ad40, JPN 0x0202a8e8)
extern "C" ARM void DebugConsole_Clear() {
    MIi_CpuClearFast(0, &data_020fe9cc, kScreenBytes);
}
