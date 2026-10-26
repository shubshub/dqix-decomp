#pragma once

class SafeAllocator;
struct Struct_02094d88;
struct Struct_020951d8;

struct Struct_020956b8 {
    char unknown0[0xa0];
    Struct_02094d88* listHead;
    Struct_020951d8* unknown_a4_;
};

extern "C" void func_020956b8(Struct_020956b8* header, SafeAllocator* allocator);
extern "C" void func_0209576c(Struct_020956b8* header, SafeAllocator* allocator,
                             const void* buffer, unsigned int length, unsigned char mode);
