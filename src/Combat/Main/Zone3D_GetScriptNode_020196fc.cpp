#include <globaldefs.h>

#include "World/Zone3D.h"

// Main, originally GetNodeAtDepth020196fc (USA 0x020196fc, EUR 0x0201970c, JPN 0x0201949c)
extern "C" ARM BmdjScriptNode* Zone3D_GetScriptNode(Zone3D* zone, int index) {
    BmdjScriptNode* node = zone->firstBMDJStruct_41c_;
    int i;
    for (i = 0; i < index; i++) {
        if (node == 0) {
            return 0;
        }
        node = node->next;
    }
    return node;
}
