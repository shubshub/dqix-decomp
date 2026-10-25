#include <globaldefs.h>
class AllocatorUnion;
void AllocatorUnion_Free(AllocatorUnion*, void*);

extern int g_mainAllocator;

struct WordList0209cbb8 {
    int* buffer;
    unsigned char count;
    unsigned char capacity;
};
void ResetWordList0209cbb8(struct WordList0209cbb8*);

// USA: func_0209cd24
ARM void FreeWordListBuffer0209cd24(struct WordList0209cbb8* list) {
    if (list->buffer != NULL) {
        AllocatorUnion_Free((AllocatorUnion*)(&g_mainAllocator), (void*)(list->buffer));
    }
    ResetWordList0209cbb8(list);
}
