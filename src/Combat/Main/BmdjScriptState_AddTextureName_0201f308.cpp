#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

// A BmdjScriptState (World/BmdjScriptNode.h): the resource and element records, then the texture names (opcode
// 0x70) and their count
struct StrTable0201f308 {
    void* resources;
    int resourceCount;
    int resourceCapacity;
    void* elements;
    int elementCount;
    int elementCapacity;
    char* textureNames[8];
    unsigned char textureNameCount;
};

// Main, originally AddString0201f308 (USA 0x0201f308, EUR 0x0201f318, JPN 0x0201f094)
extern "C" ARM void BmdjScriptState_AddTextureName(struct StrTable0201f308* state, char* name, SafeAllocator* allocator) {
    state->textureNames[state->textureNameCount] = (char*)allocator->Allocate(strlen(name) + 1);
    if (state->textureNames[state->textureNameCount] != NULL) {
        strcpy(state->textureNames[state->textureNameCount], name);
        state->textureNameCount++;
    }
}
