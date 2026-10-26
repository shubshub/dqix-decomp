#pragma once

#include "Resource/Script.h"
#include "World/ZoneFeatures.h"

struct Struct_020fdc20 {
    Struct_020134e0::Struct_02018300 *unknown_0_;
    SafeAllocator *unknown_4_;
    Struct_020134e0 *unknown_8_;
    // Float accumulators at +0x0c..+0x1c, initialized by __sinit_020e5a74.
    float unknown_c_[5];
};

extern Struct_020fdc20 data_020fdc20;

void ZoneFeaturesScript_Run(const void* data, unsigned int length, ZoneFeatures* features, SafeAllocator* allocator);

bool ZoneFeaturesScript_ParseExitDestination(Script::Parameter *param, int numParams, ZoneFeatures::Opcode68Entry &entry);
int ZoneFeaturesScript_AddExit(Script::Parameter *params, int numParams);
int ZoneFeaturesScript_AddRotatedExit(Script::Parameter *params, int numParams);
int ZoneFeaturesScript_AddOpcode66Entry(Script::Parameter *params, int numParams);
