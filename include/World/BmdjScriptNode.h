#pragma once

#include "NitroSDK/Matrix.h"
#include "Grotto/Main/TileFeatures.h"

class Zone3D;
class Model3D;
class ZoneFeatures;
class FloorMap;

struct BmdjElementResource {
    unsigned short kind;
    unsigned short unknown2;
    union {
        void* polygons;
        Model3D* model;
    };
};

// BmdjSceneElement::flags bits. Zone3D_CollectTerrainPolygons skips an element with Hidden set on it or on any
// parent, and (outside grotto floors) one with Open set; the renderers (Zone3D_Draw, func_0201aedc) skip
// Hidden ones too.
enum BmdjElementFlag {
    BmdjElementFlag_Open = 0x1,     // an open door: Zone3D_OpenDoor sets it on the door and its collision element
                                    // (func_0201874c and func_02018918 clear it)
    BmdjElementFlag_Hidden = 0x4,   // removed from the scene: not drawn, no collision
};

struct BmdjSceneElement {
    unsigned short id;
    unsigned short flags;           // BmdjElementFlag
    signed char state : 7;
    signed char flag4 : 1;
    char unknown5;
    short angle;
    Vector3i position;
    unsigned char unknown14[0x10];
    BmdjElementResource* resource;
    BmdjSceneElement* parent;
    BmdjSceneElement* linkedElement2c;
    unsigned char unknown30[4];
    short destinationAngle;
    short rotationSpeed;
    short copiedAngle;
    short movementSpeed;
    Vector3i destination;
    Vector3i direction;
    unsigned char unknown54[4];
    Vector3i lowerMargins;
    Vector3i upperMargins;
};

struct BmdjScriptState {
    int unknown0;
    int unknown4;
    int unknown8;
    int unknownC;
    int elementCount;
    int unknown14;
    unsigned char unknown18[0x20];
    unsigned char unknown_38_;
    unsigned char unknown_39_[3];
};

struct BmdjScriptNode {
    int unknown0;
    BmdjScriptState scriptState;
    int unknown40;
    BmdjSceneElement* elements;
    Vector3i position;
    BmdjScriptNode* next;
};

struct GrottoTileMapRecord {
    BmdjScriptNode* node;
    TileFeaturePlacementData info;
    Matrix3x3 rotation;
    int angle;
    Vector3i position;
};

extern "C" BmdjScriptNode* Zone3D_GetScriptNode(Zone3D* zone, int depth);
extern "C" void GrottoTileMapRecord_Reset(GrottoTileMapRecord* record);
extern "C" void BmdjScriptNode_Init(BmdjScriptNode* node);
extern "C" void BmdjScriptState_Reset(BmdjScriptState* state);
extern "C" void func_0201aedc(Zone3D* zone);
extern "C" TileFeaturePlacementData* func_0201e434(ZoneFeatures* features, const char* name);
extern "C" TileFeaturePlacementData* func_02019f24(TileFeaturePlacementData* destination, const TileFeaturePlacementData* source);
extern "C" int func_02019728(Zone3D* zone, int unused, ZoneFeatures* features, TileFeaturePlacementData* grid, FloorMap* map);

