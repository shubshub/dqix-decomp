#pragma once

class SafeAllocator;

struct Struct_0208d550 {
    void* entries;
    short count;
    short capacity;
    const short* unknown_8_;
    short unknown_c_;
    unsigned short flags;
};

struct Struct_02108fc0 {
    SafeAllocator* allocator;
    Struct_0208d550* header;
};

extern Struct_02108fc0 data_02108fc0;

extern "C" void func_0208d860(Struct_0208d550* header, SafeAllocator* allocator,
                                           const void* bytecode, unsigned int length,
                                           const short* arg4, short arg5,
                                           unsigned short flags);
