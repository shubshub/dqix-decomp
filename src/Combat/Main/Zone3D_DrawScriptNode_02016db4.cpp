#include <globaldefs.h>
#include "NitroSDK/HWRegisters.h"
#include "World/Zone3D.h"


extern "C" void G3_MultMtx43(int cmd);
extern "C" void Zone3D_DrawSceneElements(void* a, void* b, void* c, int d);

// Main, originally PushMatrixAndRender02016db4 (USA 0x02016db4, EUR 0x02016dc4, JPN 0x02016b54)
extern "C" ARM void Zone3D_DrawScriptNode(void* zoneRaw, void* nodeRaw) {
    Zone3D* zone = (Zone3D*)zoneRaw;
    BmdjScriptNode* node = (BmdjScriptNode*)nodeRaw;
    GXFIFO_MATRIX_PUSH = 0;
    if (zone->unknown_474_ != 0) {
        G3_MultMtx43((int)zone->unk_444);
    }
    Zone3D_DrawSceneElements(zone, node, node->elements, 0);
    GXFIFO_MATRIX_POP = 1;
}
