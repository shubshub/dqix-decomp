#pragma once

#include "World/Zone3D.h"

struct Struct_02012ff0 {
    short unknown_0_;
    short unknown_2_;
    Object3D* unknown_4_;
    Animation3D* unknown_8_;
    Animation3D* unknown_c_;
    Animation3D* unknown_10_;
    Animation3D* unknown_14_;
};

struct Struct_02015134 {
    char unknown_0_[0x68];
    void *unknown_68_;
};
struct Struct_02015134_2 {
    unsigned short unknown_0_;
    void *unknown_4_;
};
struct Struct_02014a24 {
    char unknown_0_[4];
    int unknown_4_;
};

struct Struct_02014a24_2 {
    int unknown_0_;
    unsigned char *unknown_4_;
    int unknown_8_;
    int unknown_c_;
    char unknown_10_[0x30];
    Struct_02012ff0 *unknown_40_;
};

void *BmdjScriptState_GetResourceRecord(unsigned char *obj, int index);
void BmdjElementResource_Init(Struct02012ff0 *s);
extern "C" int Zone3D_LoadElementTerrainMesh(Zone3D* ctx, Struct02012ff0* out, Src02015134* src);
extern "C" int Zone3D_LoadElementObject(Zone3D *zone, Struct02012ff0 *tracker, Src02015134 *source);
extern "C" int Zone3D_LoadElementModel(Zone3D *zone, void *node, Struct02012ff0 *tracker, Src02015134 *source);
extern "C" void Zone3D_BuildSceneElements(Zone3D *zone, void *node, SafeAllocator *allocator);

extern "C" int Zone3D_SetUpScriptNode(Zone3D *zone, void *data);
