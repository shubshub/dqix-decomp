#include <globaldefs.h>
class AllocatorUnion;
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);

extern int g_mainAllocator;

struct Struct_0209cbb8 {
    int* buffer;
    unsigned char count;
    unsigned char capacity;
};
extern "C" void func_0209cbb8(struct Struct_0209cbb8*);

// USA: func_0209cd24
extern "C" ARM void func_0209cd24(struct Struct_0209cbb8* list) {
    if (list->buffer != NULL) {
        AllocatorUnion_Free((AllocatorUnion*)(&g_mainAllocator), (void*)(list->buffer));
    }
    func_0209cbb8(list);
}
