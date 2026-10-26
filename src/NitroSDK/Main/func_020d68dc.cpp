#include <globaldefs.h>

extern "C" int func_020d4204(void);
void CleanCacheRange(const void* addr, unsigned int size);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d40bc(int a, int b, unsigned int c, int d);

// USA: func_020d68dc
extern "C" ARM int func_020d68dc(int value, unsigned int count, void* data) {
    int state = func_020d4204();
    if (state != 0) return state;
    if (count > 3) return 6;
    if (count != 0) {
        if (data == 0) return 6;
        CleanCacheRange((const void*)((int)data), 0x50);
    }
    func_020d404c(0x14, value);
    int r = func_020d40bc(0x14, 2, count, (int)data);
    return (r == 0) ? 2 : r;
}
