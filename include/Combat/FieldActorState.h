#pragma once

#include "Combat/ObjectStateInitialization.h"

// Shared prefix of the field actors initialized by FieldMonsterState_Init and updated
// by TickActorAndDispatchPhase02076b58. The type name is part of the existing
// dispatcher and member-function-table ABI.
struct Struct_02076a8c_2 {
    Struct_02032e58 unknown_0_;
    int unknown_130_;
    int unknown_134_;
    unsigned char unknown_138_;
    unsigned char unknown_139_;
    unsigned char unknown_13a_;
    unsigned char unknown_13b_;
    unsigned char unknown_13c_;
    unsigned char unknown_13d_[3];
    int unknown_140_;
    int unknown_144_;
    int unknown_148_;
    int unknown_14c_;
    int unknown_150_;
    int unknown_154_;
};


extern "C" void func_02076b58(Struct_02076a8c_2* arg0);

struct Struct_ov017_021a1d98;
struct Struct_02078998;

// Extent initialized by FieldMonsterState_Init. This does not assert the full actor size.
struct FieldMonsterState {
    Obj02076b58 actor;
    Vector3fix targetPosition;
    unsigned short unknown164;
    unsigned short combatantId;
    unsigned short unknown168;
    unsigned short unknown16a;
    unsigned char unknown16c[4];
    fix32_t height;
    short rise;
    unsigned short unknown176;
    unsigned char unknown178[2];
    unsigned char rising;
    unsigned char unknown17b;
    unsigned char unknown17c;
    unsigned char flags;
    unsigned char unknown17e;
    unsigned char unknown17f;
    ShadowInfo* shadowInfo;
    Attributes02078998* attributes;
};


extern "C" void FieldMonsterState_Init(FieldMonsterState* monster);
