#include <globaldefs.h>
#include "World/BmdjScriptNode.h"


extern "C" void* Scenario_GetInstance(void);

// The head of a BmdjSceneElement (World/BmdjScriptNode.h): every caller passes one (FindElemByKeys,
// Zone3D_FindSceneElement, or Zone3D_RestoreElementVisibility's walk of the zone's script nodes' elements)
struct Struct02013380 {
    unsigned short id;
    unsigned short flags;           // BmdjElementFlag
};

// Set here with every change to BmdjElementFlag_Hidden; Zone3D_RestoreElementVisibility skips elements that have it when it sets each
// element's Hidden from its 0x20 bit
enum { kElementFlag_HiddenSet = 0x40 };

// Main, originally SetFlag0x40AndToggle0x4 (USA 0x02013380, EUR 0x02013390, JPN 0x02013148)
ARM void BmdjSceneElement_SetShown(Struct02013380* element, int unused, int shown) {
    Scenario_GetInstance();
    if (shown != 0)
        element->flags &= ~BmdjElementFlag_Hidden;
    else
        element->flags |= BmdjElementFlag_Hidden;
    element->flags |= kElementFlag_HiddenSet;
}
