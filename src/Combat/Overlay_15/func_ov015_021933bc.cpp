#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov015_0218c03c_2;
struct Struct_ov005_02155d6c;

struct Struct_ov015_02190e88
{
    Struct_ov015_0218c03c_2* unknown_0_;
    Struct_ov015_02190e88* unknown_4_;
};

struct Struct_ov015_0218bcb0_2
{
    Struct_ov005_02155d6c* unknown_0_;
    unsigned char unknown_4_;
    char unknown_5_[3];
};

struct Struct_02000c9c_53
{
    void* unknown_0_;
    void* unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

struct Struct_ov015_02190acc
{
    char unknown_0_[0x2c];
    Struct_ov015_02190e88* unknown_2c_;
    char unknown_30_[0x3c - 0x30];
    Struct_02000c9c_53 unknown_3c_;
    char unknown_4c_[0x84 - 0x4c];
    void* unknown_84_;
    SafeAllocator unknown_88_;
    SafeAllocator unknown_9c_;
    SafeAllocator unknown_b0_;
    Struct_ov015_0218bcb0_2 unknown_c4_[4];
    Struct_ov015_0218bcb0_2 unknown_e4_[4];
    Struct_ov015_0218bcb0_2 unknown_104_[4];
    char unknown_124_[0x344 - 0x124];
    void* unknown_344_;
};

extern "C" void func_ov015_0218f0c4(ViewObject* object);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_ov015_0218b828(ViewerConfig* config);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov015_021933bc
extern "C" ARM void func_ov015_021933bc(Struct_ov015_02190acc* arg0)
{
    Struct_ov015_02190e88* var0 = arg0->unknown_2c_;
    while (var0 != NULL)
    {
        func_ov015_0218f0c4(node->object_);
        AllocatorUnion_Free(&g_mainAllocator, node->object_);
        ViewObjectNode* next = node;
        node = node->next_;
        AllocatorUnion_Free(&g_mainAllocator, next);
    }
    for (int var2 = 0; var2 < 4; var2++)
    {
        if (self->playerSlots_[i].states_ != NULL)
            AllocatorUnion_Free(&g_mainAllocator, self->playerSlots_[i].states_);
        if (self->dollSlots_[i].states_ != NULL)
            AllocatorUnion_Free(&g_mainAllocator, self->dollSlots_[i].states_);
        if (self->slots_[i].states_ != NULL)
            AllocatorUnion_Free(&g_mainAllocator, self->slots_[i].states_);
    }
    AllocatorUnion_Free(&g_mainAllocator, self->partsAllocator_.GetSignedAllocator());
    AllocatorUnion_Free(&g_mainAllocator, self->monstersAllocator_.GetSignedAllocator());
    AllocatorUnion_Free(&g_mainAllocator, self->soundsAllocator_.GetSignedAllocator());
    self->partsAllocator_.Destroy();
    self->monstersAllocator_.Destroy();
    self->soundsAllocator_.Destroy();
    func_ov015_0218b828(&self->config_);
    if (self->buffer_ != NULL)
    {
        AllocatorUnion_Free(&g_mainAllocator, self->buffer_);
        self->buffer_ = NULL;
    }
    if (arg0->unknown_344_ == NULL)
        return;
    AllocatorUnion_Free(&g_mainAllocator, self->items_);
    self->items_ = NULL;
}
