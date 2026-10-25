#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct_ov015_0218b828_3
{
    char* unknown_0_;
    char* unknown_4_;
    unsigned short unknown_8_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
};

struct Struct_ov015_0218b828
{
    char* unknown_0_;
    unsigned short unknown_4_;
    unsigned char unknown_6_;
    Struct_ov015_0218b828* unknown_8_;
};

struct Struct_ov015_0218b828_2
{
    char* unknown_0_;
    Struct_ov015_0218b828* unknown_4_;
};

struct Struct_ov015_0218b810
{
    Struct_ov015_0218b828_3* unknown_0_;
    Struct_ov015_0218b828_2* unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void ZeroFourFields0218b810(Struct0218b810* s);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov015_0218b828
extern "C" ARM void func_ov015_0218b828(Struct_ov015_0218b810* arg0)
{
    for (int var0 = 0; var0 < arg0->unknown_8_; var0++)
    {
        if (arg0->unknown_0_[var0].unknown_0_ != NULL)
        {
            AllocatorUnion_Free(&g_mainAllocator, self->entries_[i].name_);
            self->entries_[i].name_ = NULL;
        }
        if (arg0->unknown_0_[var0].unknown_4_ != NULL)
        {
            AllocatorUnion_Free(&g_mainAllocator, self->entries_[i].file_);
            self->entries_[i].file_ = NULL;
        }
    }
    for (int var1 = 0; var1 < arg0->unknown_c_; var1++)
    {
        if (arg0->unknown_4_[var1].unknown_0_ != NULL)
        {
            AllocatorUnion_Free(&g_mainAllocator, self->presets_[i].name_);
            self->presets_[i].name_ = NULL;
        }
        Struct_ov015_0218b828* var2 = arg0->unknown_4_[var1].unknown_4_;
        while (var2 != NULL)
        {
            Struct_ov015_0218b828* var3 = var2->unknown_8_;
            if (var2->unknown_0_ != NULL)
            {
                AllocatorUnion_Free(&g_mainAllocator, item->file_);
                item->file_ = NULL;
            }
            AllocatorUnion_Free(&g_mainAllocator, item);
            item = next;
        }
    }
    if (arg0->unknown_0_ != NULL)
    {
        AllocatorUnion_Free(&g_mainAllocator, self->entries_);
        self->entries_ = NULL;
    }
    if (arg0->unknown_4_ != NULL)
    {
        AllocatorUnion_Free(&g_mainAllocator, self->presets_);
        self->presets_ = NULL;
    }
    func_ov015_0218b810(arg0);
}
