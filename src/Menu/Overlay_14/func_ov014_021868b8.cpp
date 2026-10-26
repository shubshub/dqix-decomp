#include "Combat/MenuNodeChain.h"
#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include "globaldefs.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov014_021868b8 { char data[0x28]; };
struct Struct_ov014_021868b8_2 { char data[0x20]; };
struct Struct_ov014_021868b8_3 { char data[0xe0]; };
struct Struct_ov014_021868b8_4 {
    unsigned int index : 10;
    unsigned int flag : 1;
    unsigned int category : 7;
    unsigned int subtype : 7;
    unsigned int remaining : 7;
};
struct Struct_ov014_021868b8_5 {
    char unknown[0xb4];
    SafeAllocator* allocators;
    char unknown_b8_[8];
    Manager0207f7f0* renderer;
    Struct_ov014_021868b8_2* groups;
    Struct_ov014_021868b8_3* objects;
    void* unknown_cc_;
    void* unknown_d0_;
    Struct_ov014_021868b8* items;
    void* list;
    Struct_ov014_021868b8_4* records;
};
struct Struct_ov014_02184300_3;
extern "C" {
extern "C" void Sprite_Init(void*);
extern "C" void func_0205a234(void*);
extern "C" void Background_Init(void*);
void WindowPane_Init(void*);
void func_ov014_02184300(Struct_ov014_02184300_3*, SafeAllocator*);
extern const unsigned int data_ov014_021894b8[5];
}

extern "C" ARM void func_ov014_021868b8(Struct_ov014_021868b8_5* state, SafeAllocator* allocator) {
    if (!allocator) return;
    state->unknown_cc_ = allocator->Allocate(0x4000);
    state->items = (Struct_ov014_021868b8*)allocator->Allocate(0x140);
    state->list = allocator->Allocate(8);
    state->allocators = (SafeAllocator*)allocator->Allocate(0x64);
    state->records = (Struct_ov014_021868b8_4*)allocator->Allocate(0x4d0);
    for (unsigned char i = 0; i < 8; ++i) Sprite_Init(&state->items[i]);
    func_0205a234(state->list);
    for (int i = 0; i < 5; ++i) {
        unsigned int size;
        unsigned int offset = i * sizeof(SafeAllocator);
        size = data_ov014_021894b8[i];
        void* buffer = allocator->Allocate(size);
        ((SafeAllocator*)((char*)state->allocators + offset))->CreateTypeA(buffer, size);
        ((SafeAllocator*)((char*)state->allocators + offset))->Reset();
    }
    for (unsigned short i = 0; i < 0x134; ++i) {
        Struct_ov014_021868b8_4* record = &state->records[i];
        record->index = 0;
        record->flag = 0;
        record->category = 0;
        record->subtype = 0;
    }
    state->renderer = static_cast<Manager0207f7f0*>(allocator->Allocate(R(0x34,0x40)));
    state->groups = (Struct_ov014_021868b8_2*)allocator->Allocate(0x40);
    state->objects = (Struct_ov014_021868b8_3*)allocator->Allocate(0x380);
    func_0207f84c(state->renderer);
    for (unsigned char i = 0; i < 2; ++i) Background_Init(&state->groups[i]);
    for (unsigned char i = 0; i < 4; ++i) WindowPane_Init(&state->objects[i]);
    func_ov014_02184300((Struct_ov014_02184300_3*)state, allocator);
}
