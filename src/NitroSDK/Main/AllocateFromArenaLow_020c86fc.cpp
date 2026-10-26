#include <globaldefs.h>

extern "C" int GetArenaLow(int index);
extern "C" int GetArenaHigh(int index);
extern "C" void func_020c86e8(int index, int value);

// Main, originally func_020c86fc (USA 0x020c86fc, EUR 0x020c870c, JPN 0x020ca1c8)
extern "C" ARM int AllocateFromArenaLow(int handle, int size, int align) {
    int cur = GetArenaLow(handle);
    if (cur == 0) return 0;
    int start = (cur + align - 1) & ~(align - 1);
    int sum = start + size;
    int next = (sum + align - 1) & ~(align - 1);
    int limit = GetArenaHigh(handle);
    if ((unsigned int)next > (unsigned int)limit) return 0;
    func_020c86e8(handle, next);
    return start;
}
