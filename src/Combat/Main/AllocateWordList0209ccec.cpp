#include <globaldefs.h>

class AllocatorUnion;
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern AllocatorUnion g_mainAllocator;

struct WordList0209ccec {
    int* buffer;
    unsigned char index;
    unsigned char count;
};

// USA: func_0209ccec
ARM void AllocateWordList0209ccec(struct WordList0209ccec* list, int count) {
    if (count <= 0) return;
    list->buffer = (int*)AllocatorUnion_AllocateRounded(&g_mainAllocator, count << 2);
    list->count = count;
    list->index = 0;
}
