#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Obj020bda58;
typedef void (*Type_020bbf84)(void* mem, unsigned int size, unsigned int data1, unsigned int data2);
extern "C" void* func_020bda58(struct Obj020bda58* obj, unsigned int size, Type_020bbf84 callback, int a3, int a4);

extern "C" void* NNS_SndHeapCreate(void* start, unsigned int size);

struct Struct_020bc820;
extern "C" void func_020bc820(struct Struct_020bc820* obj);

struct Struct_020bbf84 {
    char pad0[8];
    void* alloc;
    void* child;
    int index;
    char region[4];
};

struct Struct_0210f824 {
    char pad0[0xc];
    SignedAllocatorList list;
    char pad2[0xc];
};
extern struct Struct_0210f824 data_0210f824[];

// USA: func_020bbf84
extern "C" ARM int func_020bbf84(int index, struct Obj020bda58* obj, unsigned int size) {
    Struct_020bbf84* block = (Struct_020bbf84*)func_020bda58(obj, size + 0x14, (Type_020bbf84)&func_020bc820, 0, 0);
    if (block == NULL) {
        return 0;
    }
    block->child = NULL;
    block->index = index;
    block->alloc = NULL;
    void* allocator = NNS_SndHeapCreate(&block->region[0], size);
    if (allocator == NULL) {
        return 0;
    }
    block->alloc = allocator;
    data_0210f824[index].list.InsertAtEnd((SignedAllocatorHeader*)block);
    return 1;
}
