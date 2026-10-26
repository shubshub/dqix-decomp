#pragma once

#include "Memory/SafeAllocator.h"
#include "Graphics/Vector.h"

struct TailNode020469b4;
struct Foo02048004;

struct Obj021ae800 {
    signed char type;
    unsigned char unknown_1_, inList, unknown3;
    TailNode020469b4* next;
    unsigned char stage, mode;
    unsigned short timer;
    short itemId, unknownE;
    int task;
    Vector3fix position;
    int angle, fade;
    Foo02048004* sprite;
    SafeAllocator allocator;
};

extern "C" void func_ov017_021ae800(Obj021ae800* event);

