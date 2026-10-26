#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneResourceTree.h"

// A BmdjScriptState (World/BmdjScriptNode.h) up to its element records
struct List0201f1f0 {
    void* resources;
    int resourceCount;
    int resourceCapacity;
    void* elements;       // +0xc
    int elementCount;     // +0x10
    int elementCapacity;  // +0x14
};

// Main, originally AllocateList0201f1f0 (USA 0x0201f1f0, EUR 0x0201f200, JPN 0x0201ef7c)
extern "C" ARM void BmdjScriptState_AllocateElements(struct List0201f1f0* state, int capacity, SafeAllocator* allocator) {
    state->elements = allocator->Allocate(capacity * sizeof(ZoneResourceTreeRecord));
    state->elementCapacity = capacity;
}
