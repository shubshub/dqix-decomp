#pragma once

#include "std_library_functions.h"

// Shared text layout and display mode state. The first halfword is also
// initialized by DebugMenu_Init; the following two bytes remain unidentified.
struct Struct_020ef74c {
    unsigned short unknown0;
    unsigned char unknown2[2];
    int rowHeight;
    int unknown_8_;
    int displayMode;
};

extern Struct_020ef74c data_020ef74c;

