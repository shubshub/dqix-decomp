#pragma once

#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"
#include "Combat/MenuNodeChain.h"

struct Struct_020e2490;
struct ClearTarget0205a234;
struct Struct_ov003_02173f70 {
    Struct_020e2490* manager;
    SafeAllocator* allocators;
    unsigned char unknown8[0x38 - 8];
    int unknown_38_;
#if defined(jpn)
    unsigned char unknown_3c_[0x790 - 0x3c];
#else
    unsigned char unknown1_3c_[0x814 - 0x3c];
#endif
    ClearTarget0205a234* list;
    Struct0205a198* records;
    unsigned char unknown_81c_[8];
    unsigned short count;
    unsigned char unknown_826_[2];
    unsigned char active;
    unsigned char unknown_829_[3];
    ClearTarget0205a234* unknown_82c_;
    Struct0205a198* allocatedRecords;
    unsigned char unknown834[0x89c - 0x834];
    Manager0207f7f0* menu;
    BackgroundGraphics entries[2];
    Node0207f7f0 nodes[8];
};

extern "C" void func_ov003_02173f70(Struct_ov003_02173f70*, SafeAllocator*);
extern Struct_ov003_02173f70* data_ov017_021d840c;
