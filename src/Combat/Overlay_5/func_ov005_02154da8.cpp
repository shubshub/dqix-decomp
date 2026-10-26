#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov005_02154da8_6636 = 0x1964 };
#else
enum { Enum_ov005_02154da8_6636 = 0x19ec };
#endif

struct Struct_ov023_021dad8c_3;
struct Struct_ov005_02154da8;
struct Struct_ov023_021dad8c_2 {
    Struct_ov023_021dad8c_3* entries;
    unsigned short count;
    unsigned short used;
};

struct Struct_ov005_02154da8_2 {
    char unknown0[0x26c];
    SafeAllocator allocator;
    char unknown_280_[Enum_ov005_02154da8_6636 - 0x280];
    Struct_ov023_021dad8c_2 slots;
};

extern "C" void func_ov023_021dad78(Struct_ov023_021dad8c_2* slots);
extern "C" void func_ov023_021dad8c(Struct_ov023_021dad8c_2* slots, SafeAllocator* allocator, Struct_ov005_02154da8* source, void* context);

// USA: func_ov005_02154da8
extern "C" ARM void func_ov005_02154da8(Struct_ov005_02154da8_2* menu, int arg1, int arg2) {
    SafeAllocator* allocator = &menu->allocator;
    allocator->Reset();
    func_ov023_021dad78(&menu->slots);
    func_ov023_021dad8c(&menu->slots, allocator, (Struct_ov005_02154da8*)arg1, (void*)arg2);
}
