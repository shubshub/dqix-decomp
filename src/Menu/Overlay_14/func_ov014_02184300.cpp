#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
#else
#define R(j,u) (u)
#endif
#include "globaldefs.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct Struct_ov014_02184300 { char unknown[0x28]; };
struct BestiaryList {
    char unknown_0_[0x40];
    Struct_ov014_02184300* items;
    char unknown44[8];
    short count;
    char unknown_4e_[2];
    unsigned char flags;
    char unknown_51_[3];
};
struct Struct_ov014_02184300_3 {
    void** unknown_0_;
    BestiaryList* list;
    Struct_ov014_02184300* items;
    char unknown_c_[0x30];
    SafeAllocator* allocators;
    Object3D* model;
    void* unknown_44_;
    char unknown48[0x10];
    void* labels;
    void* unknown_5c_;
    void* name;
    void* description;
    void* extra;
    char unknown_6c_[0x16];
    unsigned char unknown_82_0_ : 2;
    unsigned char unknown_82_2_ : 1;
    unsigned char unknown_82_3_ : 5;
};
struct Struct_ov014_02189498 { unsigned int values[6]; };
extern "C" {
extern const Struct_ov014_02189498 data_ov014_02189498;
extern const unsigned int data_ov014_02189480[3];
extern "C" void Sprite_Init(void*);
extern "C" void SpriteContext_Init(BestiaryList*);
}

extern "C" ARM void func_ov014_02184300(Struct_ov014_02184300_3* state, SafeAllocator* allocator) {
    if (allocator) {
        Struct_ov014_02189498 sizes = data_ov014_02189498;
        state->allocators = (SafeAllocator*)allocator->Allocate(0x78);
        state->unknown_0_ = (void**)allocator->Allocate(0xc);
        for (int i = 0; i < 3; ++i) {
            state->unknown_0_[i] = allocator->Allocate(data_ov014_02189480[i]);
        }
        state->model = (Object3D*)allocator->Allocate(0xac);
        state->unknown_44_ = allocator->Allocate(0x2c8);
        state->labels = allocator->Allocate(R(0x48, 0x4c));
        state->name = allocator->Allocate(R(0x40, 0x48));
        state->description = allocator->Allocate(R(0x40, 0x48));
        state->extra = allocator->Allocate(R(0xc0, 0x200));
        state->list = (BestiaryList*)allocator->Allocate(0x54);
        state->items = (Struct_ov014_02184300*)allocator->Allocate(0x78);
        for (unsigned char i = 0; i < 3; ++i) Sprite_Init(&state->items[i]);
        SpriteContext_Init(state->list);
        state->list->flags = 0;
        BestiaryList* list = state->list;
        list->items = state->items;
        list->count = 3;
        for (int i = 0; i < 6; ++i) {
            unsigned int size;
            unsigned int offset = i * sizeof(SafeAllocator);
            size = sizes.values[i];
            void* buffer = allocator->Allocate(size);
            ((SafeAllocator*)((char*)state->allocators + offset))->CreateTypeA(buffer, size);
            ((SafeAllocator*)((char*)state->allocators + offset))->Reset();
        }
        state->model->Initialize();
        state->model->EnableFlag(4);
        state->unknown_82_2_ = 1;
    }
}
