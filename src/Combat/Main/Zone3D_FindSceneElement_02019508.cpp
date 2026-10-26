#include <globaldefs.h>
#if defined(jpn)
enum { kScriptNodesOffset = 0x43c };
#else
enum { kScriptNodesOffset = 0x41c };
#endif
#include "World/BmdjScriptNode.h"

struct Base02019508 {
    unsigned char unknown0[kScriptNodesOffset];
    BmdjScriptNode* firstBMDJStruct_41c_;
};

// Main, originally FindEntryByKeys02019508 (USA 0x02019508, EUR 0x02019518, JPN 0x020192a8)
ARM BmdjSceneElement* Zone3D_FindSceneElement(struct Base02019508* zone, int nodeId, int elementId) {
    BmdjSceneElement* result;
    BmdjScriptNode* node;
    result = 0;
    node = zone->firstBMDJStruct_41c_;
    while (node != 0) {
        if (node->unknown0 == nodeId) {
            int count = node->scriptState.elementCount;
            BmdjSceneElement* element = node->elements;
            int i;
            for (i = 0; i < count; i++, element++) {
                if (element->id == elementId) {
                    result = element;
                    break;
                }
            }
        }
        node = node->next;
    }
    return result;
}
