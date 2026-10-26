#include <globaldefs.h>

#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"
#include "World/ZoneResourceTree.h"

struct Struct02013380;
extern "C" void BmdjSceneElement_SetShown(struct Struct02013380* obj, int unused, int clear4);

// BmdjSceneElement::flags bits: whether the element was shown when Zone3D_SaveAndOverrideElementVisibility saved it, and the
// bit BmdjSceneElement_SetShown sets with every change since
enum {
    kElementFlag_SavedShown = 0x20,
    kElementFlag_HiddenSet = 0x40,
};

// Main, originally func_02019678 (USA 0x02019678, EUR 0x02019688, JPN 0x02019418)
extern "C" ARM void Zone3D_RestoreElementVisibility(Zone3D* zone) {
    GameState::GetInstance();
    LightingManager::GetInstance();
    BmdjScriptNode* node = zone->firstBMDJStruct_41c_;
    while (node != 0) {
        for (int j = 0; j < node->scriptState.elementCount; j++) {
            BmdjScriptState_GetElementRecord((Manager_1f2a4*)&node->scriptState, j);
            BmdjSceneElement* element = &node->elements[j];
            if (element->flags & kElementFlag_HiddenSet) continue;
            int rawId = node->unknown0;
            int nodeId = 0;
            if (rawId >= 0) nodeId = rawId & 0xff;
            BmdjSceneElement_SetShown((struct Struct02013380*)element, nodeId, element->flags & kElementFlag_SavedShown);
        }
        node = node->next;
    }
}
