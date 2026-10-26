#pragma once

#include <globaldefs.h>
#include "Resource/Font.h"

struct Struct_0204166c {
    unsigned char* pixels;
    unsigned int unknown_4_;
    int unknown_8_;
    int x;
    int y;
#if defined(jpn)
    int depth;
    union {
        unsigned char encodedCharacter[2];
        unsigned short unknown1_18_;
    };
    unsigned char unknown_1a_;
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_16_1_ : 1;
    unsigned char unknown_16_2_ : 1;
    unsigned char unknown_1b_3_ : 5;
#else
    unsigned short depth;
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_16_1_ : 1;
    unsigned char unknown_16_2_ : 1;
    unsigned char fontIndex : 1;
    unsigned char unknown_16_4_ : 4;
    unsigned char characterIndex;
    FontCharacter* character;
#endif
};

typedef Struct_0204166c Struct_0204166c;

extern "C" void func_0204166c(Struct_0204166c* slot);
