#pragma once

#include "Resource/Script.h"
#include "World/ZoneFeatures.h"

struct Struct_020fdc20 {
    ZoneFeatures::Opcode6aEntry *currentEntry;
    SafeAllocator *allocator;
    ZoneFeatures *warp;
    // Float accumulators at +0x0c..+0x1c, initialized by __sinit_020e5a74.
    float unknown_c_[5];
};

extern Struct_020fdc20 data_020fdc20;

extern "C" void ZoneFeaturesScript_Run(const void* data, unsigned int length, ZoneFeatures* features, SafeAllocator* allocator);

extern "C" bool ZoneFeaturesScript_ParseExitDestination(Script::Parameter *param, int numParams, ZoneFeatures::Opcode68Entry &entry);
extern "C" int ZoneFeaturesScript_AddExit(Script::Parameter *params, int numParams);
extern "C" int ZoneFeaturesScript_AddRotatedExit(Script::Parameter *params, int numParams);
extern "C" int ZoneFeaturesScript_AddOpcode66Entry(Script::Parameter *params, int numParams);
