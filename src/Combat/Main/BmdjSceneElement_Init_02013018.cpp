#include <globaldefs.h>

// A BmdjSceneElement (World/BmdjScriptNode.h, also declared as ZoneResourceRuntimeNode in World/ZoneResourceTree.h;
// Zone3D_BuildSceneElements runs this on each of a node's elements), with BmdjSceneElement's field names. Where that header only
// has an offset name: scale (+0x14) and source (+0x20) are what BmdjSceneElement_ComputeTransforms reads and writes, firstChild (+0x2c) and
// next (+0x30) the links BmdjSceneElement_AddChild and BmdjSceneElement_AppendSibling build, object (+0x54) the Object3D
// Zone3D_BuildSceneElements allocates there
struct InitTarget02013018 {
    unsigned short id;
    unsigned short flags;
    signed char state : 7;
    signed char flag4 : 1;
    char unknown5;
    unsigned short angle;
    unsigned int positionX;
    unsigned int positionY;
    unsigned int positionZ;
    unsigned int scaleX;
    unsigned int scaleY;
    unsigned int scaleZ;
    unsigned int source;
    unsigned int resource;
    unsigned int parent;
    unsigned int firstChild;
    unsigned int next;
    unsigned short destinationAngle;
    unsigned short rotationSpeed;
    unsigned short copiedAngle;
    unsigned short movementSpeed;
    int destination[3];
    int direction[3];
    unsigned int object;
    unsigned int lowerMarginX;
    unsigned int lowerMarginY;
    unsigned int lowerMarginZ;
    unsigned int upperMarginX;
    unsigned int upperMarginY;
    unsigned int upperMarginZ;
};

enum { kNoId = 0xffff, kFix32One = 0x1000 };

// Main, originally Init02013018 (USA 0x02013018, EUR 0x02013028, JPN 0x02012de0)
extern "C" ARM void BmdjSceneElement_Init(struct InitTarget02013018 *element) {
    element->id = kNoId;
    element->flags = 0;
    element->state = 0x1f;
    element->flag4 = 0;
    element->source = 0;
    element->resource = 0;
    element->positionX = 0;
    element->positionY = 0;
    element->positionZ = 0;
    element->angle = 0;
    element->scaleX = kFix32One;
    element->scaleY = kFix32One;
    element->scaleZ = kFix32One;
    element->parent = 0;
    element->firstChild = 0;
    element->next = 0;
    element->object = 0;
    element->destinationAngle = 0;
    element->rotationSpeed = 0;
    element->copiedAngle = 0;
    element->lowerMarginX = 0;
    element->lowerMarginY = 0;
    element->lowerMarginZ = 0;
    element->upperMarginX = 0;
    element->upperMarginY = 0;
    element->upperMarginZ = 0;
}
