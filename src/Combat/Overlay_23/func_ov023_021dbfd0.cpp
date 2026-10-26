#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02075cdc;
extern "C" void func_02075cdc(struct Struct_02075cdc* s);

struct Struct_ov023_021dbfd0 {
    SafeAllocator unknown_0_;                  // 0x00
    SafeAllocator unknown_14_;                  // 0x14
    SafeAllocator unknown_28_;                  // 0x28
    SafeAllocator* unknown_3c_;                    // 0x3c
    SafeAllocator* unknown_40_;                    // 0x40
    SafeAllocator* unknown_44_;                    // 0x44
    unsigned char unknown_48_[0xc4 - 0x48];
    struct Struct_02075cdc* unknown_c4_;    // 0xc4
    struct Struct_02075cdc* unknown_c8_;    // 0xc8
};

struct Struct_ov023_021dbfd0_2 {
    unsigned char pad0[0x38];
    int unknown_38_;
    int f3c;
    unsigned char unknown_40_[0x5e - 0x40];
    unsigned char unknown_5e_;
};

// USA: func_ov023_021dbfd0
extern "C" ARM void func_ov023_021dbfd0(Struct_ov023_021dbfd0* obj, SafeAllocator* alloc) {
#if defined(jpn)
 enum {regionalOffset0=0x6f8};
#else
 enum {regionalOffset0=0x77c};
#endif
    if (alloc == NULL) return;

    obj->unknown_0_.CreateTypeA(alloc->Allocate(0xd33), 0xd33);
    obj->unknown_14_.CreateTypeA(alloc->Allocate(0x4cc), 0x4cc);
    obj->unknown_28_.CreateTypeA(alloc->Allocate(0x400), 0x400);

    obj->unknown_c4_ = (struct Struct_02075cdc*)alloc->Allocate(0x70);
    obj->unknown_c8_ = (struct Struct_02075cdc*)alloc->Allocate(0x70);
    obj->unknown_3c_ = (SafeAllocator*)alloc->Allocate(0x14);
    obj->unknown_40_ = (SafeAllocator*)alloc->Allocate(0x14);
    obj->unknown_44_ = (SafeAllocator*)alloc->Allocate(0x14);
    obj->unknown_44_->CreateTypeA(alloc->Allocate(0x180), 0x180);

    func_02075cdc(obj->unknown_c4_);
    func_02075cdc(obj->unknown_c8_);

    ((Struct_ov023_021dbfd0_2*)obj->unknown_c4_)->unknown_5e_ = *(signed char*)((char*)obj + regionalOffset0);
    ((Struct_ov023_021dbfd0_2*)obj->unknown_c4_)->f3c = 0;
    ((Struct_ov023_021dbfd0_2*)obj->unknown_c8_)->unknown_5e_ = *(signed char*)((char*)obj + regionalOffset0);
    ((Struct_ov023_021dbfd0_2*)obj->unknown_c8_)->unknown_38_ = 0x120;
    ((Struct_ov023_021dbfd0_2*)obj->unknown_c8_)->f3c = 1;

    obj->unknown_3c_->CreateTypeA(alloc->Allocate(0x280), 0x280);
    obj->unknown_40_->CreateTypeA(alloc->Allocate(0x280), 0x280);
}
