#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov015_0218c03c_2;
struct Struct_ov005_02155d6c;

struct Struct_ov015_02190e88
{
    Struct_ov015_0218c03c_2* object_;
    Struct_ov015_02190e88* unknown_4_;
};

struct Struct_ov015_0218bcb0_2
{
    Struct_ov005_02155d6c* states_;
    unsigned char unknown_4_;
    char unk_5[3];
};

struct Struct_02000c9c_53
{
    void* entries_;
    void* presets_;
    int unknown_8_;
    int unknown_c_;
};

struct Struct_ov015_02190acc
{
    char unk_0[0x2c];
    Struct_ov015_02190e88* objects_;
    char unknown_30_[0x3c - 0x30];
    Struct_02000c9c_53 unknown_3c_;
    char unknown_4c_[0x84 - 0x4c];
    void* buffer_;
    SafeAllocator partsAllocator_;
    SafeAllocator monstersAllocator_;
    SafeAllocator soundsAllocator_;
    Struct_ov015_0218bcb0_2 playerSlots_[4];
    Struct_ov015_0218bcb0_2 dollSlots_[4];
    Struct_ov015_0218bcb0_2 slots_[4];
    char unk_124[0x344 - 0x124];
    void* items_;
};

extern "C" void func_ov015_0218f0c4(Struct_ov015_0218c03c_2* object);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_ov015_0218b828(Struct_02000c9c_53* config);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov015_021933bc
extern "C" ARM void func_ov015_021933bc(Struct_ov015_02190acc* self)
{
    Struct_ov015_02190e88* node = self->objects_;
    while (node != NULL)
    {
        func_ov015_0218f0c4(node->object_);
        AllocatorUnion_Free(&g_mainAllocator, node->object_);
        Struct_ov015_02190e88* next = node;
        node = node->unknown_4_;
        AllocatorUnion_Free(&g_mainAllocator, next);
    }
    for (int i = 0; i < 4; i++)
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
    func_ov015_0218b828(&self->unknown_3c_);
    if (self->buffer_ != NULL)
    {
        AllocatorUnion_Free(&g_mainAllocator, self->buffer_);
        self->buffer_ = NULL;
    }
    if (self->items_ == NULL)
        return;
    AllocatorUnion_Free(&g_mainAllocator, self->items_);
    self->items_ = NULL;
}
