#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

// A 12-byte BMDJ resource record (Zone3D_LoadElementModel's ResourceRecord14D): its id (a time of day index on the variants
// that opcode 0x72 chains to it), flags, the texture names it uses (bits into the opcode 0x70 names), its file
// name, and its first variant
struct Elem0201f0f0 {
    signed short id;
    unsigned char flags;
    unsigned char textureMask;
    char* name;
    int next;
};

// The start of a BmdjScriptState (World/BmdjScriptNode.h): the resource records, their count and capacity
struct List0201f0f0 {
    struct Elem0201f0f0* base;
    int count;
    int capacity;
};

struct Entry_1f170 {
    signed short id;
    char unk[0xa];
};

struct EntryList_1f170 {
    struct Entry_1f170* entries;
    int count;
};

extern "C" void BmdjScriptState_AddResource(struct List0201f0f0*, struct Elem0201f0f0*);
extern "C" struct Entry_1f170* BmdjScriptState_FindResource(struct EntryList_1f170*, int);

// data_020fdc40, the BMDJ script's context while BmdjScriptState_RunScript runs it
struct Struct_020fdc40_2 {
    struct Entry_1f170* currentResource;
    SafeAllocator* allocator;
    struct List0201f0f0* state;
    char pad[16];
};
extern struct Struct_020fdc40_2 data_020fdc40;

// Main, originally func_0201ec00 (USA 0x0201ec00, EUR 0x0201ec10, JPN 0x0201e98c)
extern "C" ARM int BmdjScript_AddResource(Script::Parameter* params, int numParams) {
    struct Elem0201f0f0 resource;
    resource.id = params->ToInt();
    params++;
    const char* name = (params++)->ToString();
    if (name == NULL) {
        return 0;
    }
    resource.name = (char*)data_020fdc40.allocator->Allocate(strlen(name) + 1);
    strcpy(resource.name, name);
    resource.flags = 0;
    if (numParams >= 3) {
        resource.flags = params->ToInt();
        resource.flags &= 0x3f;
        params++;
    }
    resource.textureMask = 0;
    if (numParams >= 4) {
        resource.textureMask = params->ToInt();
    }
    resource.next = 0;
    BmdjScriptState_AddResource(data_020fdc40.state, &resource);
    data_020fdc40.currentResource = BmdjScriptState_FindResource((struct EntryList_1f170*)data_020fdc40.state, resource.id);
    return 1;
}
