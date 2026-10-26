#pragma once

#include "World/Zone3D.h"

void ZoneChest_Init(ZoneChestRenderRecord* record);
void Zone3D_SetSearchedLootables(Zone3D* zone, unsigned int mask);
ZoneFeatures::Opcode6aEntry* Zone3D_GetDoor(Zone3D* zone, int ordinal);
int Zone3D_GetDoorIndex(Zone3D* zone, ZoneFeatures::Opcode6aEntry* target);
void Zone3D_OpenDoorsByMask(Zone3D* zone, unsigned int flags);
extern "C" void Zone3D_SetUpContainers(Zone3D* zone);
extern "C" int func_0201afd0(Zone3D* zone, const void* treasureArchive, unsigned int sourceSize, int unused);
BmdjSceneElement* Zone3D_FindDoorElement(Zone3D* zone, ZoneFeatures::Opcode6aEntry* parameter);
void Zone3D_MarkDoorElements(Zone3D* zone);
extern "C" void Zone3D_OpenDoor(Zone3D*, ZoneFeatures::Opcode6aEntry*, int, int, int);
extern "C" void func_0201874c(Zone3D*, ZoneFeatures::Opcode6aEntry*);
extern "C" void func_02018918(Zone3D*, ZoneFeatures::Opcode6aEntry*);
