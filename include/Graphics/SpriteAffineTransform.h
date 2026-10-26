#pragma once

#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_0205ac40_3 {
    fix32_t values[4];
};

struct SpriteContext0205ac40 {
    char unknown0[0x50];
    unsigned char subScreen;
};

struct Struct_0205b174 {
    unsigned short flag;
};

struct B174Outer {
    unsigned short count;
    unsigned short unknown2;
    Struct_0205b174* inner;
    char unknown8[4];
    fix32_t scaleX;
    fix32_t scaleY;
    fix32_t position[2];
    unsigned short angle;
    unsigned short unknown_1e_;
    unsigned short matrixIndex;
    unsigned char firstObject;
    unsigned char transformed;
    unsigned char unknown_24_;
    signed char palette;
    signed char priority;
};


extern "C" void func_020c111c(Struct_0205ac40_3* rotation, fix32_t sine, fix32_t cosine);
extern "C" void func_020c1128(const Struct_0205ac40_3* source, Struct_0205ac40_3* destination,
                           fix32_t scaleX, fix32_t scaleY);
extern "C" void func_0205b0d8(SpriteContext0205ac40* context, Struct_0205ac40_3* transform,
                             Struct_0205ac40_3* arg2, B174Outer* sprite);
extern "C" int func_0205b174(SpriteContext0205ac40* unused, B174Outer* sprite);
