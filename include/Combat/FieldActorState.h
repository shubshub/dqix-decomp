#pragma once

#include "Combat/ObjectStateInitialization.h"

// Shared prefix of the field actors initialized by FieldMonsterState_Init and updated
// by func_02076b58. The type name is part of the existing
// dispatcher and member-function-table ABI.
struct Struct_02076a8c_2 {
    ObjectStatePrefix base;
    int phase;
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


extern "C" void func_02076b58(Struct_02076a8c_2* actor);

struct Struct_ov017_021a1d98;
struct Struct_02078998;

// Extent initialized by FieldMonsterState_Init. This does not assert the full actor size.
struct FieldMonsterState {
    Struct_02076a8c_2 actor;
    Vector3fix targetPosition;
    unsigned short unknown_164_;
    unsigned short combatantId;
    unsigned short unknown_168_;
    unsigned short unknown_16a_;
    unsigned char unknown_16c_[4];
    fix32_t height;
    short unknown_174_;
    unsigned short unknown_176_;
    unsigned char unknown_178_[2];
    unsigned char unknown_17a_;
    unsigned char unknown_17b_;
    unsigned char unknown_17c_;
    unsigned char flags;
    unsigned char unknown_17e_;
    unsigned char unknown_17f_;
    Struct_ov017_021a1d98* unknown_180_;
    Struct_02078998* attributes;
};


extern "C" void FieldMonsterState_Init(FieldMonsterState* monster);
