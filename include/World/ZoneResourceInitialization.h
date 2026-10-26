#pragma once

#include "World/Zone3D.h"

struct Struct02012ff0 {
    short field0;
    short field2;
    Object3D* field4;
    Animation3D* field8;
    Animation3D* fieldc;
    Animation3D* field10;
    Animation3D* field14;
};

struct Struct_02015134 {
    char pad[0x68];
    void *allocator;
};
struct Out02015134 {
    unsigned short flag;
    void *field4;
};
struct Src02015134 {
    char pad[4];
    int id;
};

struct Struct_02014a24_2 {
    int unknown0;
    unsigned char *records;
    int elementCount;
    int unknown_c_;
    char unknown10[0x30];
    Struct02012ff0 *trackers;
};

extern "C" void *BmdjScriptState_GetResourceRecord(unsigned char *obj, int index);
extern "C" void BmdjElementResource_Init(Struct02012ff0 *s);
extern "C" int Zone3D_LoadElementTerrainMesh(Zone3D* ctx, Struct02012ff0* out, Src02015134* src);
extern "C" int Zone3D_LoadElementObject(Zone3D *zone, Struct02012ff0 *tracker, Src02015134 *source);
extern "C" int Zone3D_LoadElementModel(Zone3D *zone, void *node, Struct02012ff0 *tracker, Src02015134 *source);
extern "C" void Zone3D_BuildSceneElements(Zone3D *zone, void *node, SafeAllocator *allocator);

extern "C" int Zone3D_SetUpScriptNode(Zone3D *zone, void *data);
