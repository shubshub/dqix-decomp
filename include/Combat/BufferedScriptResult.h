#pragma once

struct Struct_02074060 {
    unsigned short key;
    unsigned short values[3];
    unsigned short attributes[3];
    unsigned short unknown_e_;
    unsigned short unknown10;
    unsigned short unknown12;
};

extern "C" int func_0207416c(Struct_02074060* result, int key, const void* bytecode, unsigned int length);
extern "C" int func_02074114(Struct_02074060* result, int key);

