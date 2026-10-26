#include <globaldefs.h>

class AllocatorUnion;
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern AllocatorUnion g_mainAllocator;

struct Struct_0209cb74 {
    int* buffer;
    unsigned char index;
    unsigned char count;
};

// USA: func_0209ccec
extern "C" ARM void func_0209ccec(struct Struct_0209cb74* list, int count) {
    if (count <= 0) return;
    list->buffer = (int*)AllocatorUnion_AllocateRounded(&g_mainAllocator, count << 2);
    list->count = count;
    list->index = 0;
}
