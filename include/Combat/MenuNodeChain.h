#pragma once

#include <globaldefs.h>

struct BackgroundGraphics;
struct Node0207f7f0 {
    Node0207f7f0* prev;
    BackgroundGraphics* lists;
    unsigned char unknown8[0xd8];
};

struct Struct_0207f7f0 {
    int unknown_0_;
    unsigned char unknown_4_[8];
    unsigned char unknown_c_[8];
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
#if !defined(jpn)
    int unknown_20_[3];
#endif
    BackgroundGraphics* lists;
    Node0207f7f0* nodes;
    short field34;
    short field36;
    unsigned char mode;
    unsigned char count;
    unsigned char active;
    unsigned char field3b;
    unsigned char field3c;
};

extern "C" void func_0207f84c(Struct_0207f7f0*);
extern "C" void func_0207f7f0(Struct_0207f7f0*, Struct_0207f7f0_2*, int);

extern "C" void func_0207f8bc(Struct_0207f7f0*);
