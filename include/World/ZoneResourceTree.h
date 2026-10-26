#pragma once

#include "Util/ElementIndexTable.h"
#include "World/Object3D.h"
#include "World/ZoneResourceInitialization.h"

struct InitTarget02013018;
struct ListNode;
struct Node020130e0;
struct Table_1f1b0;

extern "C" void BmdjSceneElement_Init(InitTarget02013018 *self);
extern "C" void BmdjSceneElement_AddChild(ListNode *parent, ListNode *child);
extern "C" void BmdjSceneElement_AppendSibling(Node020130e0 *list, Node020130e0 *node);
extern "C" int BmdjScriptState_FindResourceIndex(Table_1f1b0 *table, int key);
extern "C" void BmdjSceneElement_ComputeTreeTransforms(void *node);
extern "C" int func_ov017_021b8b54(void *object);

struct ZoneResourceTreeRecord {
    short key;
    short trackerKey;
    short parentKey;
    unsigned short flags;
    Vector3i position;
    char unknown14[0xc];
};

struct ZoneResourceRuntimeNode {
    unsigned short key;
    unsigned short flags;
    signed char remaining : 7;
    unsigned char flag4 : 1;
    unsigned char unknown5[3];
    Vector3i position;
    char unknown14[0xc];
    ZoneResourceTreeRecord *source;
    Struct02012ff0 *tracker;
    ZoneResourceRuntimeNode *parent;
    ZoneResourceRuntimeNode *firstChild;
    ZoneResourceRuntimeNode *next;
    union {
        short targetAngle;
        unsigned short animationState;
    };
    union {
        short rotationSpeed;
        unsigned short delay;
    };
    short angle;
    union {
        unsigned short unknown3a;
        short movementSpeed;
    };
    Vector3i targetPosition;
    Vector3i direction;
    Object3D *object;
    char unknown58[0x18];
};

struct ZoneResourceTree {
    Struct_02014a24_2 resources;
    ZoneResourceRuntimeNode *nodes;
    Vector3i position;
};

extern "C" void *func_ov017_021b8478(void *object);
