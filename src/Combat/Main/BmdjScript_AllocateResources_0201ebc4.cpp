#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

// The start of a BmdjScriptState (World/BmdjScriptNode.h): the 12-byte resource records (opcode 0x6c), their
// count and capacity
struct Node0201ebc4 {
    void* resources;
    int resourceCount;
    int resourceCapacity;
};

// data_020fdc40, the BMDJ script's context while BmdjScriptState_RunScript runs it
struct Container0201ebc4 {
    int currentResource;
    SafeAllocator* allocator;
    Node0201ebc4* state;
};
extern Container0201ebc4 data_020fdc40;

// Main, originally AllocNode0201ebc4 (USA 0x0201ebc4, EUR 0x0201ebd4, JPN 0x0201e950)
ARM int BmdjScript_AllocateResources(Variant02030b0c* params) {
    int count = ((Script::Parameter*)params)->ToInt();
    Node0201ebc4* state = data_020fdc40.state;
    state->resources = data_020fdc40.allocator->Allocate(count * 0xc);
    state->resourceCapacity = count;
    return 1;
}
