#include <globaldefs.h>

// A BmdjScriptState (World/BmdjScriptNode.h): the resource and element records, then the texture names (opcode
// 0x70) and their count
struct Container_1f368 {
    void* resources;
    int resourceCount;
    int resourceCapacity;
    void* elements;
    int elementCount;
    int elementCapacity;
    void* textureNames[8];
    unsigned char textureNameCount;
};

// Main, originally GetPointerFromArray0x18_0201f368 (USA 0x0201f368, EUR 0x0201f378, JPN 0x0201f0f4)
extern "C" ARM void* BmdjScriptState_GetTextureName(struct Container_1f368* state, int index) {
    if (index < 0 || state->textureNameCount <= index) {
        return 0;
    }
    return state->textureNames[index];
}
