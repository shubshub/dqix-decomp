#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void func_ov023_021db2e4(volatile int* p);
extern "C" int FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(void* obj);
struct Struct_02075cdc;
extern "C" void func_02075d58(struct Struct_02075cdc* s);
extern "C" void func_ov023_021dcd18(void* obj);
extern "C" void func_ov023_021dc134(void* a, int key, int flag);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator;

#if defined(jpn)
struct Struct_ov023_021ff9e0_4 { unsigned int pad0[5]; void* field4; };
#else
struct Struct_ov023_021ff9e0_4 { unsigned int pad0; void* field4; };
#endif

extern struct Struct_ov023_021ff9e0_4 data_ov023_021ff9e0;

struct Struct_ov023_021dc354 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator* unknown_3c_;
    SafeAllocator* unknown_40_;
    SafeAllocator* unknown_44_;
    unsigned char unknown_48_[0xc4 - 0x48];
    struct Struct_02075cdc* unknown_c4_;
    struct Struct_02075cdc* unknown_c8_;
#if defined(jpn)
    unsigned char unknown_cc_[0x6b0 - 0xcc];
#else
    unsigned char unknown1_cc_[0x734 - 0xcc];
#endif

    int unknown_734_;
    int unknown_738_[7];
    unsigned char unknown_754_[0x774 - 0x754];
    unsigned short unknown_774_;
    unsigned char unknown_776_[0x77b - 0x776];
    signed char unknown_77b_;
    unsigned char unknown_77c_[0x77e - 0x77c];
    signed char unknown_77e_;
    unsigned char unknown_77f_[0x780 - 0x77f];
    int field780;
    unsigned char unknown_784_[0x79b - 0x784];
    unsigned char unknown_79b_0_ : 1;
};

// USA: func_ov023_021dc354
extern "C" ARM void func_ov023_021dc354(struct Struct_ov023_021dc354* obj) {
    func_ov023_021db2e4((volatile int*)&obj->field780);
    obj->unknown_77e_ = -1;

    if (!(obj->unknown_774_ & 0x10)) {
        FontBankLoader_CancelLoads((void*)FontBankLoader_GetInstance());
    }

    func_ov023_021db2e4((volatile int*)&obj->unknown_734_);
    for (int i = 0; i < 7; i++) {
        func_ov023_021db2e4((volatile int*)&obj->unknown_738_[i]);
    }

    if (obj->unknown_c8_) {
        func_02075d58(obj->unknown_c8_);
    }
    if (obj->unknown_c4_) {
        func_02075d58(obj->unknown_c4_);
    }

    if (obj->unknown_77b_ != 1) {
        func_ov023_021dcd18(obj);
    }

    if (obj->unknown_44_) {
        obj->unknown_44_->Destroy();
    }
    if (obj->unknown_40_) {
        obj->unknown_40_->Destroy();
    }
    if (obj->unknown_3c_) {
        obj->unknown_3c_->Destroy();
    }
    obj->unknown_28_.Destroy();
    obj->unknown_14_.Destroy();
    obj->unknown_0_.Destroy();

    if (data_ov023_021ff9e0.field4) {
        if (!obj->unknown_79b_0_) {
            AllocatorUnion_Free(&g_mainAllocator, data_ov023_021ff9e0.field4);
        }
        data_ov023_021ff9e0.field4 = 0;
    }

    func_ov023_021dc134(obj, -1, obj->unknown_77b_);
}
