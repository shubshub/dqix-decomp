#pragma once

#include "Util/ElementIndexTable.h"
#include "World/Object3D.h"
#include "World/ZoneResourceInitialization.h"

struct Struct_02013018;
struct Struct_020130b0;
struct Struct_020130e0;
struct Struct_020177d4_3;

void BmdjSceneElement_Init(InitTarget02013018 *self);
void BmdjSceneElement_AddChild(ListNode *parent, ListNode *child);
void BmdjSceneElement_AppendSibling(Node020130e0 *list, Node020130e0 *node);
int BmdjScriptState_FindResourceIndex(Table_1f1b0 *table, int key);
void BmdjSceneElement_ComputeTreeTransforms(void *node);
int IsField600B4Zero_021b8b54(void *object);

struct Struct_020177d4_4 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    unsigned short unknown_6_;
    Vector3i unknown_8_;
    char unknown_14_[0xc];
};

struct Struct_02015554 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    signed char unknown_4_0_ : 7;
    unsigned char unknown_4_7_ : 1;
    unsigned char unknown_5_[3];
    Vector3i unknown_8_;
    char unknown_14_[0xc];
    Struct_020177d4_4 *unknown_20_;
    Struct_02012ff0 *unknown_24_;
    Struct_02015554 *unknown_28_;
    Struct_02015554 *unknown_2c_;
    Struct_02015554 *unknown_30_;
    union {
        short unknown_34_;
        unsigned short unknown1_34_;
    };
    union {
        short unknown_36_;
        unsigned short unknown1_36_;
    };
    short unknown_38_;
    union {
        unsigned short unknown_3a_;
        short unknown1_3a_;
    };
    Vector3i unknown_3c_;
    Vector3i unknown_48_;
    Object3D *unknown_54_;
    char unknown_58_[0x18];
};

struct Struct_020177d4_2 {
    Struct_02014a24_2 unknown_0_;
    Struct_02015554 *unknown_44_;
    Vector3i unknown_48_;
};

extern "C" void *func_ov017_021b8478(void *arg0);
