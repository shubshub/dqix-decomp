#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Combat/Overlay15ViewerContext.h"

struct Struct_ov015_0218bcb0_2
{
    void* states_;
    unsigned char unknown_4_;
    char unk_5[3];
};

struct Struct205563c;

struct Struct_ov015_02193d80
{
    unsigned int sizes_[7];
};

struct Struct_ov015_02193df0
{
    unsigned int sizes_[11][2];
};

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" Struct_ov015_0218bcb0_2* func_ov015_021931f8(char* arg0);
extern "C" Struct_ov015_0218bcb0_2* func_ov015_0219322c(char* arg0);
extern "C" Struct_ov015_0218bcb0_2* func_ov015_02193260(char* arg0);
extern "C" void func_0205563c(Struct205563c* obj);

extern AllocatorUnion g_mainAllocator;
extern const Struct_ov015_02193d80 data_ov015_02193d80;
extern const Struct_ov015_02193df0 data_ov015_02193df0;

// USA: func_ov015_0218bcb0
extern "C" ARM int func_ov015_0218bcb0(void* context)
{
    Struct_ov015_0218bcb0* self = static_cast<Struct_ov015_0218bcb0*>(context);
    if (self->kind_ == 0 || self->kind_ == 1)
    {
        Struct_ov015_02193df0 sizes = data_ov015_02193df0;
        self->allocators_ = (SafeAllocator*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 10 * sizeof(SafeAllocator));
        if (self->allocators_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->objects_ = (Object3D*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 10 * sizeof(Object3D));
        if (self->objects_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        for (int i = 0; i < 10; i++)
        {
            self->allocators_[i].ResetAllocatorPointer();
            void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, sizes.sizes_[i][self->kind_]);
            if (buffer == NULL)
                return 0;
            self->allocators_[i].CreateTypeA(buffer, sizes.sizes_[i][self->kind_]);
            self->allocators_[i].Reset();
            self->objects_[i].Initialize();
        }
        self->parts_ = (int*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 10 * sizeof(int));
        if (self->parts_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        memset(self->parts_, -1, 10 * sizeof(int));
        self->parts_[0] = 0x32cf;
        self->parts_[1] = 0x3f57;
        self->parts_[2] = 0x233c;
        self->parts_[3] = 0x2328;
        self->parts_[4] = 0x2328;
        self->parts_[5] = 0x36b7;
        self->parts_[6] = 0x42e0;
        if (self->kind_ == 0)
            self->slot_ = func_ov015_021931f8(self->viewer_);
        else
            self->slot_ = func_ov015_0219322c(self->viewer_);
        if (self->slot_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->slot_->unknown_4_ = 1;
        self->bufferSize_ = sizes.sizes_[10][self->kind_];
        self->buffer_ = AllocatorUnion_AllocateRounded(&g_mainAllocator, self->bufferSize_);
        if (self->buffer_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
    }
    else
    {
        Struct_ov015_02193d80 sizes = data_ov015_02193d80;
        self->allocators_ = (SafeAllocator*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(SafeAllocator));
        if (self->allocators_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->allocators_->ResetAllocatorPointer();
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, sizes.sizes_[self->kind_]);
        if (buffer == NULL)
            return 0;
        self->allocators_->CreateTypeA(buffer, sizes.sizes_[self->kind_]);
        self->allocators_->Reset();
        self->slot_ = func_ov015_02193260(self->viewer_);
        if (self->slot_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->slot_->unknown_4_ = 1;
        if (self->kind_ == 2 || self->kind_ == 3)
        {
            self->bufferSize_ = 0xc000;
            self->buffer_ = AllocatorUnion_AllocateRounded(&g_mainAllocator, self->bufferSize_);
            if (self->buffer_ == NULL)
            {
                func_ov015_0218f0c4(self);
                return 0;
            }
        }
        self->objects_ = (Object3D*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(Object3D));
        if (self->objects_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->objects_->Initialize();
        if (self->kind_ == 4)
        {
            self->effect_ = (Struct205563c*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x1c);
            if (self->effect_ == NULL)
            {
                func_ov015_0218f0c4(self);
                return 0;
            }
            func_0205563c(self->effect_);
        }
    }
    return 1;
}
