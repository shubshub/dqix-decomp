#include "Combat/MenuNodeChain.h"
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define R(j, u) (j)
#else
#define R(j, u) (u)
#endif

struct Struct_ov006_02154348;
struct Struct_ov006_021576a0 {
#if defined(jpn)
    char unknown_0_[0x24];
#else
    char unknown1_0_[0x1a4];
#endif
    void* data;
    char unknown_1a8_[4];
    void* unknown_1ac_;
    void* unknown_1b0_;
};
struct Struct_ov006_021576a0_2 {
    short item;
    unsigned short selected : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};
struct Struct_ov006_021576a0_3 {
    char unknown_0_[0x3e];
    unsigned char flag;
    inline unsigned char inline_ov006_021576a0() { return flag = 1; }
};
struct Struct_ov006_021576a0_4 {
    char unknown_0_[0xc];
    Struct_ov006_021576a0_3* list;
};
struct Struct_ov006_021576a0_5 {
#if !defined(jpn)
    char unknown_0_[4];
    unsigned char** unknown_4_;
#endif
    void* data;
    SafeAllocator* allocators;
    Struct_ov006_02154348* buffers;
    Manager0207f7f0* unknown_14_;
    Struct_ov006_021576a0_4* unknown_18_;
    char (*pairBuffer)[0x20];
    char (*sevenBuffer)[0xe0];
    char (*entryBuffer)[0x28];
    void* unknown_28_;
    char unknown_2c_[0xc];
    Struct_ov006_021576a0_2* unknown_38_;
    char unknown_3c_[0xc];
    short** unknown_48_;
    unsigned char** unknown_4c_;
    unsigned short* unknown_50_;
#if defined(jpn)
    char unknown54[0x100];
#else
    char unknown54[0x104];
#endif
    char unknown_158_[0x18];
#if defined(jpn)
    char unknown_170_[0x230];
#else
    char unknown_170_[0x224];
#endif
    unsigned short flags;
};
extern "C" {
extern unsigned short data_ov006_0215fffe[];
extern unsigned int data_ov006_02160054[];
void* memcpy(void*, const void*, unsigned int);
void* memset(void*, int, unsigned int);
extern "C" void func_020e2490(void*, int, int, void*, SafeAllocator*, int, int);
extern "C" void Background_Init(void*);
void WindowPane_Init(void*);
extern "C" void Sprite_Init(void*);
void func_ov006_02154614(void*);
void func_ov006_02154348(Struct_ov006_02154348*, SafeAllocator*, void*);
extern "C" void func_ov006_021553a8(void*);
void func_020ac234(Struct_ov006_021576a0_2*);
}
extern "C" ARM void func_ov006_021576a0(Struct_ov006_021576a0_5* state, SafeAllocator* allocator, void* context)
{
    unsigned short sizes[9];
    memcpy(sizes, data_ov006_0215fffe, 0x12);
    state->unknown_48_ = (short**)allocator->Allocate(0x24);
    state->unknown_4c_ = (unsigned char**)allocator->Allocate(0x24);
    state->unknown_50_ = (unsigned short*)allocator->Allocate(0x12);
    for (unsigned char index = 0; index < 9; index++) {
        unsigned int size = sizes[index];
        state->unknown_48_[index] = (short*)allocator->Allocate(size * 2);
        state->unknown_4c_[index] = (unsigned char*)allocator->Allocate(size);
        memset(state->unknown_48_[index], -1, size * 2);
        memset(state->unknown_4c_[index], 0, size);
        state->unknown_50_[index] = 0;
    }
    state->data = allocator->Allocate(0x4000);
    state->allocators = (SafeAllocator*)allocator->Allocate(0xc8);
    state->unknown_14_ = static_cast<Manager0207f7f0*>(allocator->Allocate(R(0x34, 0x40)));
    state->pairBuffer = (char (*)[0x20])allocator->Allocate(0x40);
    state->sevenBuffer = (char (*)[0xe0])allocator->Allocate(0x620);
    state->entryBuffer = (char (*)[0x28])allocator->Allocate(0x488);
    state->unknown_28_ = allocator->Allocate(8);
    state->buffers = (Struct_ov006_02154348*)allocator->Allocate(R(0x10bc, 0x12c0));
    state->unknown_38_ = (Struct_ov006_021576a0_2*)allocator->Allocate(0x75c);
    state->unknown_18_ = (Struct_ov006_021576a0_4*)allocator->Allocate(0x24);
    func_020e2490(state->unknown_18_, 1, 1, state->unknown_28_, allocator, R(3, 4), 0x40);
    Struct_ov006_021576a0_3* list = state->unknown_18_->list;
    list->inline_ov006_021576a0();
    for (unsigned char index = 0; index < 10; index++) {
        state->allocators[index].ResetAllocatorPointer();
        unsigned int size = data_ov006_02160054[index];
        state->allocators[index].CreateTypeA(allocator->Allocate(size), size);
        state->allocators[index].Reset();
    }
    func_0207f84c(state->unknown_14_);
    for (unsigned char index = 0; index < 2; index++) Background_Init(state->pairBuffer[index]);
    for (unsigned char index = 0; index < 7; index++) WindowPane_Init(state->sevenBuffer[index]);
    for (unsigned char index = 0; index < 29; index++) Sprite_Init(state->entryBuffer[index]);
    for (unsigned short index = 0; index < 471; index++) {
        Struct_ov006_021576a0_2* record = &state->unknown_38_[index];
        record->item = -1;
        record->selected = 0;
        record->unknown_2_1_ = 0;
        record->unknown_2_2_ = 0;
    }
    func_ov006_02154614(state->buffers);
    func_ov006_02154348(state->buffers, allocator, context);
    ((Struct_ov006_021576a0*)state->buffers)->data = state->data;
    ((Struct_ov006_021576a0*)state->buffers)->unknown_1ac_ = state->unknown_170_;
    ((Struct_ov006_021576a0*)state->buffers)->unknown_1b0_ = state->unknown_158_;
    if (state->flags & 2) func_ov006_021553a8(state->buffers);
    func_020ac234(state->unknown_38_);
#if !defined(jpn)
    state->unknown_4_ = (unsigned char**)allocator->Allocate(0x40);
    for (int index = 0; index < 16; index++) {
        state->unknown_4_[index] = (unsigned char*)allocator->Allocate(0x80);
        memset(state->unknown_4_[index], 0, 0x80);
    }
#endif
}
