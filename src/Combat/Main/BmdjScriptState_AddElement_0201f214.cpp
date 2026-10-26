#include <globaldefs.h>

struct ElementPosition0201f214 { unsigned int xyz[3]; };

// A ZoneResourceTreeRecord (World/ZoneResourceTree.h), with its field names: one scene element of the node
struct Element0201f214 {
    short key;
    short trackerKey;
    short parentKey;
    unsigned short flags;
    struct ElementPosition0201f214 position;
    unsigned short angleX;
    unsigned short angleY;
    unsigned short angleZ;
    unsigned short scaleX;
    unsigned short scaleY;
    unsigned short scaleZ;
};

// A BmdjScriptState (World/BmdjScriptNode.h) up to its element records
struct List0201f214 {
    void* resources;
    int resourceCount;
    int resourceCapacity;
    struct Element0201f214* elements;
    int elementCount;
    int elementCapacity;
};

// Main, originally AppendCappedElement0201f214 (USA 0x0201f214, EUR 0x0201f224, JPN 0x0201efa0)
ARM void BmdjScriptState_AddElement(struct List0201f214* state, struct Element0201f214* record) {
    int count = state->elementCount;
    struct Element0201f214* slot;
    if (state->elementCapacity <= count) {
        return;
    }
    state->elementCount = count + 1;
    slot = &state->elements[count];
    slot->key = record->key;
    slot->trackerKey = record->trackerKey;
    slot->parentKey = record->parentKey;
    slot->flags = record->flags;
    slot->position = record->position;
    slot->angleX = record->angleX;
    slot->angleY = record->angleY;
    slot->angleZ = record->angleZ;
    slot->scaleX = record->scaleX;
    slot->scaleY = record->scaleY;
    slot->scaleZ = record->scaleZ;
}
