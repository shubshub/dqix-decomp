#include <globaldefs.h>

// A 12-byte BMDJ resource record (opcode 0x6c)
struct BmdjResourceRecord {
    short id;
    unsigned char flags;
    unsigned char textureMask;
    char* name;
    BmdjResourceRecord* next;
};

// The start of a BmdjScriptState (World/BmdjScriptNode.h): the resource records and their count
struct Table_1f1b0 {
    struct BmdjResourceRecord* resources;
    int resourceCount;
};

// Main, originally FindRecordIndexByHalfwordKey_0201f1b0 (USA 0x0201f1b0, EUR 0x0201f1c0, JPN 0x0201ef3c)
ARM int BmdjScriptState_FindResourceIndex(struct Table_1f1b0* state, int id) {
    int i;
    for (i = 0; i < state->resourceCount; i++) {
        if (id == state->resources[i].id) {
            return i;
        }
    }
    return -1;
}
