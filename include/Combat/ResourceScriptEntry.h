#pragma once

#include "Resource/Script.h"

struct Struct_02082064 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_0201099c {
    unsigned int unknown_0_0_ : 32;
    unsigned short unknown_4_0_ : 7;
    unsigned short unknown_4_7_ : 9;
    unsigned short unknown_6_;
    Struct_02082064 unknown_8_;
    Struct_02082064 unknown_c_;
    Struct_02082064 unknown_10_;
};

struct Struct_0201099c_2 {
    Struct_0201099c unknown_0_;
    Struct_0201099c unknown_14_;
    Struct_0201099c unknown_28_;
    unsigned char unknown_3c_[0x16];
};

extern Script::OpcodeLookupEntry data_020f0ff8[];

extern "C" int ResourceScriptEntry_LoadLevel(void *output, void *resource, unsigned int size, int selection, int extra);
