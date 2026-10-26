#include <globaldefs.h>
class AllocatorUnion;
extern "C" int AllocatorUnion_Free(AllocatorUnion*, void*);

extern int g_mainAllocator;

// USA: func_020998ac
extern "C" ARM int func_020998ac(int* p) {
    return AllocatorUnion_Free((AllocatorUnion*)(&g_mainAllocator), (void*)(*p));
}
