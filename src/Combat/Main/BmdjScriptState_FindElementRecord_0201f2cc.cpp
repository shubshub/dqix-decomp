#include <globaldefs.h>

// A ZoneResourceTreeRecord (World/ZoneResourceTree.h): one scene element of the node
struct Element_1f2cc {
    short key;
    short trackerKey;
    short parentKey;
    unsigned short flags;
    int position[3];
    unsigned short angleX;
    unsigned short angleY;
    unsigned short angleZ;
    unsigned short scaleX;
    unsigned short scaleY;
    unsigned short scaleZ;
};

// A BmdjScriptState (World/BmdjScriptNode.h) up to its element records and their count
struct Manager_1f2cc {
    void* resources;
    int resourceCount;
    int resourceCapacity;
    struct Element_1f2cc* elements;
    int elementCount;
};

// Main, originally FindElementByHalfwordKey_0201f2cc (USA 0x0201f2cc, EUR 0x0201f2dc, JPN 0x0201f058)
ARM struct Element_1f2cc* BmdjScriptState_FindElementRecord(struct Manager_1f2cc* state, int key) {
    int i;
    for (i = 0; i < state->elementCount; i++) {
        if (key == state->elements[i].key) {
            return &state->elements[i];
        }
    }
    return 0;
}
