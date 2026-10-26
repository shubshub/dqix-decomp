#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"
#include "World/ZoneResourceTree.h"

struct Struct02013380;
void BmdjSceneElement_SetShown(struct Struct02013380* obj, int unused, int clear4);

// BmdjSceneElement::flags bits: whether the element was shown when this pass saved it (Zone3D_RestoreElementVisibility puts it back),
// and the bit BmdjSceneElement_SetShown sets with every change (Zone3D_RestoreElementVisibility leaves those elements alone)
enum {
    kElementFlag_SavedShown = 0x20,
    kElementFlag_HiddenSet = 0x40,
};

// Main, originally ProcessBattlerEffects02019568 (USA 0x02019568, EUR 0x02019578, JPN 0x02019308)
ARM void Zone3D_SaveAndOverrideElementVisibility(void* zone, int mode) {
    GameState::GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    int timeOfDay = lighting->timeOfDayIndex_;

    BmdjScriptNode* node = ((Zone3D*)zone)->firstBMDJStruct_41c_;
    while (node != NULL) {
        int rawId = node->unknown0;
        int nodeId = 0;
        if (rawId >= 0) {
            nodeId = rawId & 0xff;
        }
        for (int j = 0; j < node->scriptState.elementCount; j++) {
            ZoneResourceTreeRecord* record = (ZoneResourceTreeRecord*)BmdjScriptState_GetElementRecord((Manager_1f2a4*)&node->scriptState, j);
            BmdjSceneElement* element = &node->elements[j];

            if (element->flags & BmdjElementFlag_Hidden) {
                element->flags &= ~kElementFlag_SavedShown;
            } else {
                element->flags |= kElementFlag_SavedShown;
            }

            if (record->flags & 0x10) {
                BmdjSceneElement_SetShown((struct Struct02013380*)element, nodeId, 1);
            }

            if (!(record->flags & (1 << timeOfDay))) {
                BmdjSceneElement_SetShown((struct Struct02013380*)element, nodeId, 0);
            }

            if (mode != 0) {
                if (record->flags & 0x20) {
                    BmdjSceneElement_SetShown((struct Struct02013380*)element, nodeId, 0);
                }
            } else {
                if (record->flags & 0x40) {
                    BmdjSceneElement_SetShown((struct Struct02013380*)element, nodeId, 0);
                }
            }

            element->flags &= ~kElementFlag_HiddenSet;
        }
        node = node->next;
    }
}
