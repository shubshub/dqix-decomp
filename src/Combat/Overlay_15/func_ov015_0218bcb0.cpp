#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Combat/Overlay15ViewerContext.h"

struct Struct_ov015_0218bcb0_2
{
    void* unknown_0_;
    unsigned char unknown_4_;
    char unknown_5_[3];
};

struct Struct_0205563c;

struct Struct_ov015_02193d80
{
    unsigned int unknown_0_[7];
};

struct Struct_ov015_02193df0
{
    unsigned int unknown_0_[11][2];
};

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
ViewerSlot* FindFreeSlot021931f8(char* viewer);
ViewerSlot* FindFreeSlot0219322c(char* viewer);
ViewerSlot* FindFreeSlot02193260(char* viewer);
void ClearSevenWords_0205563c(Struct205563c* obj);

extern AllocatorUnion g_mainAllocator;
extern const ObjectSizes data_ov015_02193d80;
extern const PartSizes data_ov015_02193df0;

// USA: func_ov015_0218bcb0
extern "C" ARM int func_ov015_0218bcb0(void* arg0)
{
    Struct_ov015_0218bcb0* var0 = static_cast<Struct_ov015_0218bcb0*>(arg0);
    if (var0->unknown_1c_ == 0 || var0->unknown_1c_ == 1)
    {
        PartSizes sizes = data_ov015_02193df0;
        self->allocators_ = (SafeAllocator*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 10 * sizeof(SafeAllocator));
        if (self->allocators_ == NULL)
        {
            func_ov015_0218f0c4(var0);
            return 0;
        }
        self->objects_ = (Object3D*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 10 * sizeof(Object3D));
        if (self->objects_ == NULL)
        {
            func_ov015_0218f0c4(var0);
            return 0;
        }
        for (int var2 = 0; var2 < 10; var2++)
        {
            self->allocators_[i].ResetAllocatorPointer();
            void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, sizes.sizes_[i][self->kind_]);
            if (buffer == NULL)
                return 0;
            var0->unknown_8_[var2].CreateTypeA(var3, var1.unknown_0_[var2][var0->unknown_1c_]);
            var0->unknown_8_[var2].Reset();
            var0->unknown_24_[var2].Initialize();
        }
        self->parts_ = (int*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 10 * sizeof(int));
        if (self->parts_ == NULL)
        {
            func_ov015_0218f0c4(var0);
            return 0;
        }
        memset(var0->unknown_20_, -1, 10 * sizeof(int));
        var0->unknown_20_[0] = 0x32cf;
        var0->unknown_20_[1] = 0x3f57;
        var0->unknown_20_[2] = 0x233c;
        var0->unknown_20_[3] = 0x2328;
        var0->unknown_20_[4] = 0x2328;
        var0->unknown_20_[5] = 0x36b7;
        var0->unknown_20_[6] = 0x42e0;
        if (var0->unknown_1c_ == 0)
            var0->unknown_4_ = func_ov015_021931f8(var0->unknown_0_);
        else
            var0->unknown_4_ = func_ov015_0219322c(var0->unknown_0_);
        if (var0->unknown_4_ == NULL)
        {
            func_ov015_0218f0c4(var0);
            return 0;
        }
        self->slot_->used_ = 1;
        self->bufferSize_ = sizes.sizes_[10][self->kind_];
        self->buffer_ = AllocatorUnion_AllocateRounded(&g_mainAllocator, self->bufferSize_);
        if (self->buffer_ == NULL)
        {
            func_ov015_0218f0c4(var0);
            return 0;
        }
    }
    else
    {
        ObjectSizes sizes = data_ov015_02193d80;
        self->allocators_ = (SafeAllocator*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(SafeAllocator));
        if (self->allocators_ == NULL)
        {
            func_ov015_0218f0c4(var0);
            return 0;
        }
        self->allocators_->ResetAllocatorPointer();
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, sizes.sizes_[self->kind_]);
        if (buffer == NULL)
            return 0;
        var0->unknown_8_->CreateTypeA(var5, var4.unknown_0_[var0->unknown_1c_]);
        var0->unknown_8_->Reset();
        var0->unknown_4_ = func_ov015_02193260(var0->unknown_0_);
        if (var0->unknown_4_ == NULL)
        {
            func_ov015_0218f0c4(var0);
            return 0;
        }
        var0->unknown_4_->unknown_4_ = 1;
        if (var0->unknown_1c_ == 2 || var0->unknown_1c_ == 3)
        {
            self->bufferSize_ = 0xc000;
            self->buffer_ = AllocatorUnion_AllocateRounded(&g_mainAllocator, self->bufferSize_);
            if (self->buffer_ == NULL)
            {
                func_ov015_0218f0c4(var0);
                return 0;
            }
        }
        self->objects_ = (Object3D*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(Object3D));
        if (self->objects_ == NULL)
        {
            func_ov015_0218f0c4(var0);
            return 0;
        }
        var0->unknown_24_->Initialize();
        if (var0->unknown_1c_ == 4)
        {
            self->effect_ = (Struct205563c*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x1c);
            if (self->effect_ == NULL)
            {
                func_ov015_0218f0c4(var0);
                return 0;
            }
            func_0205563c(var0->unknown_28_);
        }
    }
    return 1;
}
