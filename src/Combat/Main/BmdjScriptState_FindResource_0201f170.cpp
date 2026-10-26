#include <globaldefs.h>

// A 12-byte BMDJ resource record (opcode 0x6c)
struct Entry_1f170 {
    signed short id;
    unsigned char flags;
    unsigned char textureMask;
    char* name;
    Entry_1f170* next;
};

// The start of a BmdjScriptState (World/BmdjScriptNode.h): the resource records and their count
struct EntryList_1f170 {
    struct Entry_1f170* resources;
    int resourceCount;
};

// Main, originally FindEntryBySignedId_0201f170 (USA 0x0201f170, EUR 0x0201f180, JPN 0x0201eefc)
extern "C" ARM struct Entry_1f170* BmdjScriptState_FindResource(struct EntryList_1f170* state, int id) {
    int i;
    for (i = 0; i < state->resourceCount; i++) {
        if (id == state->resources[i].id) {
            return &state->resources[i];
        }
    }
    return 0;
}
