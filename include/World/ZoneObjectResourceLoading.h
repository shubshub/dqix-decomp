#pragma once

#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/ZoneResourceInitialization.h"

struct Struct_020151cc {
    unsigned int unknown_0_;
    int unknown_4_;
    char unknown_8_[8];
};

struct Struct_020e6f48 {
    Struct_020151cc unknown_0_[6];
};

struct Struct_02014d80 {
    char unknown_0_[0x20];
    int unknown_20_;
};

void *GameState_GetZoneTransition(GameState *state);
void Zone3D_FormatElementFilePath(int id, char *extension, char *buffer);
void VramState_Restore(char *tables);
void VramState_Save(char *tables);
extern char data_020ef1e8[];
extern const Struct_020e6f48 data_020e6f48;
