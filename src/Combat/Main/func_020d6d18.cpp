#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_02059cc8(unsigned char* obj);

struct Struct_020d6d18 {
    unsigned char body[0xd4];
    int unknown_d4_;
};

struct Struct_020d6d18_2 {
    Struct_020d6d18 entries[12];
    int unknown_a20_;
    short unknown_a24_;
    short unknown_a26_;
    SafeAllocator allocator;
    unsigned char unknown_a3c_;
    unsigned char unknown_a3d_;
    float unknown_a40_;
    float unknown_a44_;
};

// USA: func_020d6d18
extern "C" ARM void func_020d6d18(Struct_020d6d18_2* c) {
    for (int i = 0; i < 12; i++) {
        func_02059cc8((unsigned char*)&c->entries[i]);
        c->entries[i].unknown_d4_ = 0;
    }
    c->allocator.ResetAllocatorPointer();
    c->unknown_a20_ = 0;
    c->unknown_a24_ = 0;
    c->unknown_a26_ = 0;
    c->unknown_a3c_ = 0;
    c->unknown_a3d_ = 0;
    c->unknown_a40_ = 1.0f;
    c->unknown_a44_ = -0.2f;
}
