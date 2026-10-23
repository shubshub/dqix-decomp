#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_020dfec0_2 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 19;
    unsigned int unknown_3_7_ : 1;
};

extern "C" int func_020dffb8(struct Struct_020dfec0_2* arg0);

struct Struct_020dfec0 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 19;
    unsigned int unknown_3_7_ : 1;
    void* unknown_4_;
    void* unknown_8_;
};

struct Struct_020dffc8;
typedef int (*Type_020dfec0)(struct Struct_020dfec0*, struct Struct_020dffc8*);
extern "C" int func_020dffc8(struct Struct_020dfec0* arg0, Type_020dfec0 arg1);

struct Struct_020dfbdc;
extern "C" int func_020dfbdc(void* arg0, struct Struct_020dfbdc* arg1);

// Main, originally func_020dfec0 (USA 0x020dfec0, EUR 0x020dfed0, JPN 0x020e1a94)
extern "C" ARM int KeyTable_Load(struct Container020dffc8* self, SafeAllocator* alloc, void* fileData, unsigned int size) {
    ElementCallback020dffc8 cb;
    unsigned int bytes;
    unsigned int arrSize;

    if (arg1 == 0 || arg2 == 0 || arg3 == 0) {
        return 0;
    }
    if (arg1 == 0 || arg2 == 0) {
        return 0;
    }
    memcpy(arg0, arg2, 4);
    var1 = func_020dffb8((struct Struct_020dfec0_2*)arg0);
    var2 = arg0->unknown_1_4_;
    if (var1) {
        arg0->unknown_4_ = arg1->Allocate(var1);
    } else {
        arg0->unknown_4_ = 0;
    }
    arg0->unknown_8_ = var2 ? arg1->Allocate(var2) : 0;
    if (arg0->unknown_4_) {
        memcpy(arg0->unknown_4_, (char*)arg2 + 4, var1);
    }
    if (arg0->unknown_8_) {
        memcpy(arg0->unknown_8_, (char*)arg2 + (func_020dffb8((struct Struct_020dfec0_2*)arg0) + 4), var2);
    }
    var0 = (Type_020dfec0)func_020dfbdc;
    if (var0) {
        func_020dffc8(arg0, var0);
    }
    arg0->unknown_3_7_ = 1;
    return 1;
}
