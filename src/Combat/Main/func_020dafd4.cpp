#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020dafd4_3;
extern "C" void func_020dde3c(Struct_020dafd4_3* obj);
extern "C" void func_020dde90(void* obj, short value);
extern "C" void func_020dde98(void* obj, short value);
extern "C" void func_020dde84(char* obj, int a, int b);
extern "C" void func_020ddff4(void* obj, int value);

struct Struct_020dafd4;
extern "C" void func_020db0c4(Struct_020dafd4* p);

extern unsigned char data_020ee688[];
extern unsigned char data_020ee68b[];

struct Struct_020dafd4_2 {
    unsigned short field0;
    unsigned short field2;
    char pad4[4];
    int field8;
    int fieldc;
    char pad10[0x10];
    int field20;
    char pad24[4];
};

struct Struct_020dafd4_4 {
    SafeAllocator allocator;
    char unknown_14_[0x3c - sizeof(SafeAllocator)];
    unsigned char unknown_3c_;
    char unknown_3d_[0x40 - 0x3d];
    void* unknown_40_;
    unsigned int unknown_44_;
    void* unknown_48_;
    unsigned int unknown_4c_;
    char unknown_50_[4];
    unsigned char unknown_54_;
    char pad55[0x5c - 0x55];
    int unknown_5c_;
    int f60;
    char unknown_64_[2];
    short unknown_66_;
    char pad68[4];
    unsigned char unknown_6c_;
    char unknown_6d_;
    short unknown_6e_;
    Struct_020dafd4_2 slots[3];
};

// USA: func_020dafd4
extern "C" ARM void func_020dafd4(Struct_020dafd4_4* mgr) {
    mgr->allocator.ResetAllocatorPointer();
    mgr->unknown_40_ = 0;
    mgr->unknown_44_ = 0;
    mgr->unknown_48_ = 0;
    mgr->unknown_4c_ = 0;
    mgr->unknown_3c_ = 0;
    mgr->unknown_5c_ = 0;
    mgr->f60 = 0;
    mgr->unknown_66_ = 0;
    mgr->unknown_6c_ = 1;
    mgr->unknown_54_ = 0;
    for (int i = 0; i < 3; i++) {
        Struct_020dafd4_2* slot = &mgr->slots[i];
        func_020dde3c((Struct_020dafd4_3*)slot);
        func_020dde90(slot, data_020ee688[i]);
        func_020dde98(slot, data_020ee68b[i]);
        func_020dde84((char*)slot, (i * 0x12 + 0xbc) & 0xff, 0xa4);
        func_020ddff4(slot, (int)(((long long)(i << 12) * 0x28 + 0x800) >> 12) + 0x85 + 0x300);
    }
    mgr->unknown_6e_ = 0;
    func_020db0c4((Struct_020dafd4*)mgr);
}
