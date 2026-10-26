#pragma once

#include <globaldefs.h>

struct BackgroundGraphics;
struct Node0207f7f0 {
    Node0207f7f0* prev;
    BackgroundGraphics* lists;
    unsigned char unknown8[0xd8];
};

struct Manager0207f7f0 {
    int field0;
    unsigned char sub4[8];
    unsigned char unknown_c_[8];
    int field14;
    int field18;
    int field1c;
#if !defined(jpn)
    int tasks[3];
#endif
    BackgroundGraphics* lists;
    Node0207f7f0* nodes;
    short field34;
    short unknown_36_;
    unsigned char mode;
    unsigned char count;
    unsigned char active;
    unsigned char unknown_3b_;
    unsigned char field3c;
};

extern "C" void func_0207f84c(Manager0207f7f0*);
extern "C" void func_0207f7f0(Manager0207f7f0*, Node0207f7f0*, int);

extern "C" void func_0207f8bc(Manager0207f7f0*);
