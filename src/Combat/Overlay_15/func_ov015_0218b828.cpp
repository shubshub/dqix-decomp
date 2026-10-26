#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct_ov015_0218b828_3
{
    char* name_;
    char* file_;
    unsigned short id_;
    unsigned char page_;
    unsigned char unknown_b_;
};

struct Struct_ov015_0218b828
{
    char* file_;
    unsigned short id_;
    unsigned char kind_;
    Struct_ov015_0218b828* unknown_8_;
};

struct Struct_ov015_0218b828_2
{
    char* name_;
    Struct_ov015_0218b828* items_;
};

struct Struct_ov015_0218b810
{
    Struct_ov015_0218b828_3* entries_;
    Struct_ov015_0218b828_2* presets_;
    int unknown_8_;
    int unknown_c_;
};

extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_ov015_0218b810(Struct_ov015_0218b810* s);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov015_0218b828
extern "C" ARM void func_ov015_0218b828(Struct_ov015_0218b810* self)
{
    for (int i = 0; i < self->unknown_8_; i++)
    {
        if (self->entries_[i].name_ != NULL)
        {
            AllocatorUnion_Free(&g_mainAllocator, self->entries_[i].name_);
            self->entries_[i].name_ = NULL;
        }
        if (self->entries_[i].file_ != NULL)
        {
            AllocatorUnion_Free(&g_mainAllocator, self->entries_[i].file_);
            self->entries_[i].file_ = NULL;
        }
    }
    for (int i = 0; i < self->unknown_c_; i++)
    {
        if (self->presets_[i].name_ != NULL)
        {
            AllocatorUnion_Free(&g_mainAllocator, self->presets_[i].name_);
            self->presets_[i].name_ = NULL;
        }
        Struct_ov015_0218b828* item = self->presets_[i].items_;
        while (item != NULL)
        {
            Struct_ov015_0218b828* next = item->unknown_8_;
            if (item->file_ != NULL)
            {
                AllocatorUnion_Free(&g_mainAllocator, item->file_);
                item->file_ = NULL;
            }
            AllocatorUnion_Free(&g_mainAllocator, item);
            item = next;
        }
    }
    if (self->entries_ != NULL)
    {
        AllocatorUnion_Free(&g_mainAllocator, self->entries_);
        self->entries_ = NULL;
    }
    if (self->presets_ != NULL)
    {
        AllocatorUnion_Free(&g_mainAllocator, self->presets_);
        self->presets_ = NULL;
    }
    func_ov015_0218b810(self);
}
