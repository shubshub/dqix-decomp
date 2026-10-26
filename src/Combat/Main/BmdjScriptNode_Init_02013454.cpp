#include <globaldefs.h>
#include "World/BmdjScriptNode.h"

// Main, originally InitStruct02013454 (USA 0x02013454, EUR 0x02013464, JPN 0x0201321c)
ARM void BmdjScriptNode_Init(BmdjScriptNode* node) {
    node->unknown0 = -1;
    node->unknown40 = 0;
    node->elements = NULL;
    node->next = NULL;
    BmdjScriptState_Reset(&node->scriptState);
    node->position.x = 0;
    node->position.y = 0;
    node->position.z = 0;
}
