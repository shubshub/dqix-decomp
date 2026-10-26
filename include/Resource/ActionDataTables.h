#pragma once

#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_02079808;
struct Struct_02079bac;

struct Struct_02079a58 {
    unsigned int count : 12;
    unsigned int size : 19;
    unsigned int flag : 1;
    void* p1;
    void* p2;
};

struct Struct_02079bac_2 {
    unsigned int count : 12;
    unsigned int hi : 19;
    unsigned int flag : 1;
    Struct_02079bac* arr;
    unsigned char* extra;
};

typedef int (*Type_02079900)(void*, Struct_02079808*);
typedef void (*Type_02079bac)(Struct_02079bac_2*, void*);
typedef void (*Type_02079bac_2)(Struct_02079bac_2*);

extern "C" int func_02079a58(Struct_02079a58* table, SafeAllocator* allocator, void* data,
                            Type_02079900 relocate,
                            void (*arg4)(Struct_02079a58*)
#if !defined(jpn)
                            , SafeAllocator* arg5
#endif
);

extern "C" int func_02079bac(Struct_02079bac_2* table, SafeAllocator* allocator, void* data,
                            Type_02079bac relocate, Type_02079bac_2 arg4
#if !defined(jpn)
                            , SafeAllocator* arg5
#endif
);

extern "C" int func_02079808(void* table, Struct_02079808* record);

struct ActionDataTables {
    Struct_02079a58 actions;
    Struct_02079a58 unknown_c_;
    Struct_02079bac_2 unknown_18_;
    Struct_02079bac_2 unknown_24_;
};

extern "C" ActionDataTables* func_020797dc();

extern "C" void func_02079900(ActionDataTables* tables, SafeAllocator* allocator);
extern "C" void func_02079cf8(ActionDataTables* tables, SafeAllocator* allocator, SafeAllocator* arg2);

