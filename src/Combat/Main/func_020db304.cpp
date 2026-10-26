#include <globaldefs.h>

extern "C" int func_020db2dc(int a, int b);
void DMAMemsetSynchronous(int, unsigned int, unsigned int, unsigned int);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);

typedef void (*Type_01ff8b48)(int, int, int);
extern Type_01ff8b48 data_020f2904[];

// USA: func_020db304
extern "C" ARM void func_020db304(int param0, int param1) {
    int handle = func_020db2dc(param0, param1);
    DMAMemsetSynchronous(3, handle, 0xc0, 0x400);
    CleanInvalidateCacheRange((const void*)(handle), 0x400);
    data_020f2904[param1](handle, 0, 0x400);
    CleanCacheRange((const void*)(handle), 0x400);
}
