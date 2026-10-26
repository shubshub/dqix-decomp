#include <globaldefs.h>

// A 12-byte BMDJ resource record (opcode 0x6c): its id, flags, the texture names it uses (bits into the opcode
// 0x70 names), its file name, and its first time-of-day variant (opcode 0x72)
struct Elem0201f0f0 {
    unsigned short id;
    unsigned char flags;
    unsigned char textureMask;
    int name;
    int next;
};

// The start of a BmdjScriptState (World/BmdjScriptNode.h): the resource records, their count and capacity
struct List0201f0f0 {
    struct Elem0201f0f0* resources;
    int resourceCount;
    int resourceCapacity;
};

// Main, originally AppendElementCapped0201f0f0 (USA 0x0201f0f0, EUR 0x0201f100, JPN 0x0201ee7c)
ARM void BmdjScriptState_AddResource(struct List0201f0f0* state, struct Elem0201f0f0* resource) {
    int count = state->resourceCount;
    struct Elem0201f0f0* slot;
    if (state->resourceCapacity <= count) {
        return;
    }
    state->resourceCount = count + 1;
    slot = &state->resources[count];
    slot->id = resource->id;
    slot->flags = resource->flags;
    slot->textureMask = resource->textureMask;
    slot->name = resource->name;
    slot->next = resource->next;
}
