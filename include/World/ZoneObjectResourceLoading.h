#pragma once

#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/ZoneResourceInitialization.h"

struct Struct_020151cc {
    unsigned int mask;
    int slot;
    char extension[8];
};

struct Struct_020e6f48 {
    Struct_020151cc entries[6];
};

struct ZoneLoadState {
    char unknown0[0x20];
    int unknown20;
};

extern "C" void *GameState_GetZoneTransition(GameState *state);
extern "C" void Zone3D_FormatElementFilePath(int id, char *extension, char *buffer);
extern "C" void VramState_Restore(char *tables);
extern "C" void VramState_Save(char *tables);
extern char data_020ef1e8[];
extern const Struct_020e6f48 data_020e6f48;
