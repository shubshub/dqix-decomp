#pragma once

#include "World/ZoneFeatures.h"

class GameObject;

struct Struct_02038598 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 7;
};

struct Struct_02037d10 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
    Struct_02014900 unknown_c_;
    Struct_02014900 unknown_18_;
    Struct_02014900 unknown_24_;
    Struct_02014900 unknown_30_;
    Struct_02014900 unknown_3c_;
    int unknown_48_;
    int unknown_4c_;
    short unknown_50_;
    unsigned char unknown_52_;
    unsigned char unknown_53_;
    unsigned char unknown_54_;
    Struct_020134e0::Struct_02018300* unknown_58_;
    Struct_020134e0::Struct_02018300* unknown_5c_;
    Struct_020134e0::Struct_02018300* unknown_60_;
};

void LadderClimb_Reset(SubBlock02038508* block);
SubBlock02038508* GameObject_GetLadderClimb(void* object);
void GameObject_SetLadderClimb(GameObject* object, SubBlock02038508* source);
extern "C" void LinkMessageQueue_SendLadderClimb(SubBlock02038508* block, unsigned char first, unsigned char second);
