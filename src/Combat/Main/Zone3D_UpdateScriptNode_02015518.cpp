#include <globaldefs.h>
#include "World/BmdjScriptNode.h"

extern "C" void BmdjSceneElement_Update(void* a, void* b);

// Main, originally ForEachElement02015518 (USA 0x02015518, EUR 0x02015528, JPN 0x020152e4)
ARM void Zone3D_UpdateScriptNode(void* zone, char* node) {
    BmdjScriptNode* scriptNode = (BmdjScriptNode*)node;
    int count = scriptNode->scriptState.elementCount;
    int i;
    for (i = 0; i < count; i++) {
        BmdjSceneElement_Update(zone, &scriptNode->elements[i]);
    }
}
