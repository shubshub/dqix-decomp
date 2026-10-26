#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern const char data_020f2889[];
extern const char data_020f28a1[];
extern const char data_020f28a6[];
extern const char data_020f28ac[];
extern const char data_020f28bb[];

extern "C" int sprintf(char*, const char*, ...);

struct Struct_020da1ac {
    int field0;
    unsigned char field4;
    char pad0[3];
    int taskId;
};

struct Struct_020da77c {
    int field0;
    unsigned char field4;
};

struct Struct_020da77c_2 {
    SafeAllocator* allocator;
    char unknown_4_[9];
    unsigned char flags;
    unsigned char unknown_e_;
};

extern "C" void func_020dabd0(void*);
extern "C" Struct_020da1ac* func_020daa20(unsigned char*);
extern "C" void func_020da22c(Struct_020da1ac*);

// USA: func_020da77c
extern "C" ARM int func_020da77c(Struct_020da77c_2* state, unsigned char kind, Struct_020da77c* req) {
    BackgroundLoader* loader;
    Struct_020da1ac* entry;
    SafeAllocator* allocator;
    int result;
    char path[0x80];
    loader = BackgroundLoader::GetInstance();
    if (!loader) return 0;
    if (state->flags & 1) return 0;
    if (state->unknown_e_ != 0) {
        func_020dabd0(state);
    }
    allocator = state->allocator;
    if (!allocator) return 0;
    allocator->Reset();
    state->flags = 0;
    state->unknown_e_ = kind;
    entry = func_020daa20((unsigned char*)state);
    if (!entry) return 0;
    entry->field0 = req->field0;
    entry->field4 = req->field4;
    result = -1;
    switch (state->unknown_e_) {
    case 1:
        sprintf(path, data_020f2889, data_020f28a1);
        result = loader->QueueLoadGP1(path, allocator);
        break;
    case 2:
        sprintf(path, data_020f2889, data_020f28a6);
        result = loader->QueueLoadGP1(path, allocator);
        break;
    case 3:
        sprintf(path, data_020f28ac, data_020f28bb);
        result = loader->QueueLoadFile(path, allocator);
        break;
    }
    if (result == -1) {
        func_020da22c(entry);
        return 0;
    }
    entry->taskId = result;
    state->flags |= 1;
    return 1;
}
