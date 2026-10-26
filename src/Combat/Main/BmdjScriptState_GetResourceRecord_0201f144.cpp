#include <globaldefs.h>

// A 12-byte BMDJ resource record (opcode 0x6c)
struct BmdjResourceRecord {
    short id;
    unsigned char flags;
    unsigned char textureMask;
    char* name;
    BmdjResourceRecord* next;
};

// The start of a BmdjScriptState (World/BmdjScriptNode.h): the resource records, their count and capacity
struct BmdjResourceArray {
    BmdjResourceRecord* resources;
    int resourceCount;
    int resourceCapacity;
};

// Main, originally GetElementStride0xc_0201f144 (USA 0x0201f144, EUR 0x0201f154, JPN 0x0201eed0)
extern "C" ARM void* BmdjScriptState_GetResourceRecord(unsigned char* state, int index) {
    BmdjResourceArray* records = (BmdjResourceArray*)state;
    if (index < 0 || records->resourceCapacity <= index) {
        return NULL;
    }
    return &records->resources[index];
}
