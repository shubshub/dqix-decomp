#include <globaldefs.h>

#include "World/Zone3D.h"

// Main, originally GetNodeAtDepth020196fc (USA 0x020196fc, EUR 0x0201970c, JPN 0x0201949c)
ARM BmdjScriptNode* Zone3D_GetScriptNode(Zone3D* obj, int count) {
    BmdjScriptNode* cur = obj->firstBMDJStruct_41c_;
    int i;
    for (i = 0; i < count; i++) {
        if (cur == 0) {
            return 0;
        }
        cur = cur->next;
    }
    return cur;
}
