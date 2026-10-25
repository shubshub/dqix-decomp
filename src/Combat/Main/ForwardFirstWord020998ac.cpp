#include <globaldefs.h>
class AllocatorUnion;
int AllocatorUnion_Free(AllocatorUnion*, void*);

extern int g_mainAllocator;

// USA: func_020998ac
ARM int ForwardFirstWord020998ac(int* p) {
    return AllocatorUnion_Free((AllocatorUnion*)(&g_mainAllocator), (void*)(*p));
}
