#pragma once

#include "Resource/Script.h"

struct ResourceScriptPackedTriple {
    unsigned int low : 10;
    unsigned int middle : 10;
    unsigned int high : 10;
    unsigned int reserved : 2;
};

struct Struct_0201099c {
    unsigned int value0 : 32;
    unsigned short unknown_4_0_ : 7;
    unsigned short value4High : 9;
    unsigned short unknown6;
    ResourceScriptPackedTriple value8;
    ResourceScriptPackedTriple valueC;
    ResourceScriptPackedTriple value10;
};

struct ResourceScriptEntry {
    Struct_0201099c initial;
    Struct_0201099c unknown_14_;
    Struct_0201099c difference;
    unsigned char variants[0x16];
};

extern Script::OpcodeLookupEntry data_020f0ff8[];

extern "C" int ResourceScriptEntry_LoadLevel(void *output, void *resource, unsigned int size, int selection, int extra);
