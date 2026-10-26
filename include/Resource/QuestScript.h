#pragma once

#include "Resource/QuestScriptOwner.h"

// Existing 20-byte script state at data_02109404.
struct Struct_02109404 {
    unsigned char f0;
    unsigned char unknown_1_;
    unsigned char selected;
    unsigned char f3;
    unsigned char f4;
    unsigned char pad5;
    unsigned short index;
    unsigned short f8;
    unsigned char padA[2];
    SafeAllocator* allocator;
    unsigned char* table;
};

extern Struct_02109404 data_02109404;
