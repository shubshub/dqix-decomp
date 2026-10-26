#pragma once

#include "World/ZoneFeatures.h"

class GameObject;

struct ActorActionFlags {
    unsigned char active : 1;
    unsigned char unknown : 7;
};

struct SubBlock02038508 {
    unsigned char active;
    unsigned char command;
    unsigned char unknown2;
    unsigned char reversed;
    unsigned short unknown4;
    short heading;
    short startHeading;
    short endHeading;
    Struct_02014900 start;
    Struct_02014900 end;
    Struct_02014900 unknown24;
    Struct_02014900 startControl;
    Struct_02014900 endControl;
    int unknown48;
    int unknown4c;
    short unknown50;
    unsigned char unknown52;
    unsigned char unknown53;
    unsigned char unknown54;
    ZoneFeatures::Opcode6aEntry* startNode;
    ZoneFeatures::Opcode6aEntry* endNode;
    ZoneFeatures::Opcode6aEntry* unknown60;
};

extern "C" void LadderClimb_Reset(SubBlock02038508* block);
extern "C" SubBlock02038508* GameObject_GetLadderClimb(void* object);
extern "C" void GameObject_SetLadderClimb(GameObject* object, SubBlock02038508* source);
extern "C" void LinkMessageQueue_SendLadderClimb(SubBlock02038508* block, unsigned char first, unsigned char second);
