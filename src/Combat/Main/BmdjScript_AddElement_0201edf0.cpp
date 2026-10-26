#include <globaldefs.h>
#include "Resource/Script.h"

// A ZoneResourceTreeRecord (World/ZoneResourceTree.h), with its field names: one scene element of the node.
// angle* and scale* are 4.12 (BmdjSceneElement_ComputeTransforms turns by angleY and multiplies by scale*)
struct Element0201f214 {
    short key;
    short trackerKey;
    short parentKey;
    unsigned short flags;
    unsigned int position[3];
    unsigned short angleX;
    unsigned short angleY;
    unsigned short angleZ;
    unsigned short scaleX;
    unsigned short scaleY;
    unsigned short scaleZ;
};

struct List0201f214;

void BmdjScriptState_AddElement(struct List0201f214*, struct Element0201f214*);

// data_020fdc40, the BMDJ script's context while BmdjScriptState_RunScript runs it
struct Alloc0201edf0;
struct Container0201edf0 {
    int currentResource;
    struct Alloc0201edf0* allocator;
    struct List0201f214* state;
    char pad[16];
};
extern struct Container0201edf0 data_020fdc40;

// Main, originally func_0201edf0 (USA 0x0201edf0, EUR 0x0201ee00, JPN 0x0201eb7c)
extern "C" ARM int BmdjScript_AddElement(Script::Parameter* params, int numParams) {
    struct Element0201f214 element;
    float x;
    float y;
    float z;
    float scaleX;
    float scaleY;
    float angleX;
    float scaleZ;
    float angleY;
    float angleZ;
    unsigned char flags;
    int key;
    int trackerKey;
    int parentKey;

    key = params[0].ToInt();
    trackerKey = params[1].ToInt();
    x = params[2].ToFloat();
    y = params[3].ToFloat();
    z = params[4].ToFloat();
    parentKey = params[5].ToInt();
    Script::Parameter* nameParam = &params[6];
    params += 7;
    (void)(void*)nameParam->ToString();
    scaleX = 1.0f;
    scaleY = 1.0f;
    scaleZ = 1.0f;
    if (numParams > 10) {
        scaleX = params[0].ToFloat();
        scaleY = params[1].ToFloat();
        Script::Parameter* last = &params[2];
        params += 3;
        scaleZ = last->ToFloat();
    }
    angleX = 0.0f;
    angleY = 0.0f;
    angleZ = 0.0f;
    if (numParams > 7) {
        angleX = params[0].ToFloat();
        angleY = params[1].ToFloat();
        Script::Parameter* last = &params[2];
        params += 3;
        angleZ = last->ToFloat();
    }
    flags = 0xf;
    if (numParams > 13) {
        flags = params[0].ToInt() & 0xff;
        if (flags & 0x10) {
            flags &= ~0x10;
        } else {
            flags |= 0x10;
        }
        if (flags & 0x20)
            flags = flags & ~0x20;
        else
            flags = flags | 0x20;
    }
    element.key = key;
    element.trackerKey = trackerKey;
    element.parentKey = parentKey;
    element.position[0] = (int)(4096.0f * x);
    element.position[1] = (int)(4096.0f * y);
    element.position[2] = (int)(4096.0f * z);
    element.angleX = (int)(4096.0f * angleX);
    element.angleY = (int)(4096.0f * angleY);
    element.angleZ = (int)(4096.0f * angleZ);
    element.scaleX = (int)(4096.0f * scaleX);
    element.scaleY = (int)(4096.0f * scaleY);
    element.scaleZ = (int)(4096.0f * scaleZ);
    element.flags = flags;
    BmdjScriptState_AddElement(data_020fdc40.state, &element);
    return 1;
}
