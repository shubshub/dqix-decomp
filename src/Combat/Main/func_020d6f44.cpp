#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_02059cc8(unsigned char* obj);

struct Struct_020d6f44 {
    unsigned char body[0xd4];
    int unknown_d4_;
};

struct Struct_020d6ec8 {
    Struct_020d6f44 entries[12];
    unsigned char unknown_a20_[4];
    short unknown_a24_;
    short unknown_a26_;
    SafeAllocator allocator;
};

// USA: func_020d6f44
extern "C" ARM void func_020d6f44(Struct_020d6ec8* c) {
    c->allocator.Reset();
    for (int i = 0; i < 12; i++) {
        func_02059cc8((unsigned char*)&c->entries[i]);
        c->entries[i].unknown_d4_ = 0;
    }
    c->unknown_a24_ = 0;
    c->unknown_a26_ = 0;
}
