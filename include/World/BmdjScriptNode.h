#pragma once

#include "NitroSDK/Matrix.h"
#include "Grotto/Main/TileFeatures.h"

class Zone3D;
class Model3D;
class Struct_020134e0;
class FloorMap;

struct Struct_02016874 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    union {
        void* unknown_4_;
        Model3D* unknown1_4_;
    };
};

// BmdjSceneElement::flags bits. Zone3D_CollectTerrainPolygons skips an element with Hidden set on it or on any
// parent, and (outside grotto floors) one with Open set; the renderers (Zone3D_Draw, ProcessNode0201aedc) skip
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

struct Struct_02018b34 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    unsigned char unknown_18_[0x20];
    unsigned char unknown_38_;
    unsigned char unknown_39_[3];
};

struct Struct_02013454 {
    int unknown_0_;
    Struct_02018b34 unknown_4_;
    int unknown_40_;
    Struct_02016874_2* unknown_44_;
    Vector3i unknown_48_;
    Struct_02013454* unknown_54_;
};

struct Struct_02013490 {
    Struct_02013454* unknown_0_;
    TileFeaturePlacementData unknown_4_;
    Matrix3x3 unknown_14_;
    int unknown_38_;
    Vector3i unknown_3c_;
};

BmdjScriptNode* Zone3D_GetScriptNode(Zone3D* zone, int depth);
void GrottoTileMapRecord_Reset(GrottoTileMapRecord* record);
void BmdjScriptNode_Init(BmdjScriptNode* node);
void BmdjScriptState_Reset(BmdjScriptState* state);
void ProcessNode0201aedc(Zone3D* zone);
TileFeaturePlacementData* FindEntryByNameSubstr0201e434(ZoneFeatures* features, const char* name);
TileFeaturePlacementData* CopyStruct02019f24(TileFeaturePlacementData* destination, const TileFeaturePlacementData* source);
extern "C" int func_02019728(Zone3D* zone, int unused, ZoneFeatures* features, TileFeaturePlacementData* grid, FloorMap* map);

