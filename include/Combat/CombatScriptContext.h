#pragma once

#include "Memory/SafeAllocator.h"



struct CombatScriptContext {
    unsigned short unknown_0_;
    unsigned short unknown2;
#if !defined(jpn)
    const char* nameOverride;
#endif
    SafeAllocator* allocator;
    unsigned int unknown_c_;
    char* currentObject;
};

extern CombatScriptContext data_020fdc4c;
