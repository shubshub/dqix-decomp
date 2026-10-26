#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Obj020bda58;
typedef void (*NNSSndHeapDisposeCallback)(void* mem, unsigned int size, unsigned int data1, unsigned int data2);
extern void* AllocateAndLinkEntry020bda58(struct Obj020bda58* obj, unsigned int size, NNSSndHeapDisposeCallback callback, int a3, int a4);

extern void* NNS_SndHeapCreate(void* start, unsigned int size);

struct Obj020bc820;
extern void ReleaseActorAndUnlink020bc820(struct Obj020bc820* obj);

struct Block020bbf84 {
    char pad0[8];
    void* alloc;
    void* child;
    int index;
    char region[4];
};

struct ListEntry020bbf84 {
    char pad0[0xc];
    SignedAllocatorList list;
    char pad2[0xc];
};
extern struct ListEntry020bbf84 data_0210f824[];

// USA: func_020bbf84
ARM int AllocateAndRegisterEntry020bbf84(int index, struct Obj020bda58* obj, unsigned int size) {
    Block020bbf84* block = (Block020bbf84*)AllocateAndLinkEntry020bda58(obj, size + 0x14, (NNSSndHeapDisposeCallback)&ReleaseActorAndUnlink020bc820, 0, 0);
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
