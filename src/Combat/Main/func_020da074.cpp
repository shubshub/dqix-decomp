#include <globaldefs.h>
#include "Resource/QuestScript.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/HPXEAllocator.h"
#include "Filesystem/BackgroundLoader.h"
struct Struct_020da034 { char unknown0[8]; unsigned short unknown_8_; char unknown_a_[2]; int slots[1]; int scriptId; };
struct Struct02012dd0 { void* field0; HPXEAllocator* alloc; };
extern "C" int* func_02094d6c();
extern "C" unsigned int AllocatorUnion_GetMaxPossibleAllocation(Struct02012dd0*);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" void func_020da034(Struct_020da034*, int);
extern "C" void func_02095d30(int*, int, int);
extern AllocatorUnion g_mainAllocator;

// USA: func_020da074
extern "C" ARM void func_020da074(Struct_020da034* manager) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* var1 = func_02094d6c();
    void* data;
    unsigned int length;
    loader->GetLoadedFileByID(manager->slots[0], &data, &length);
    if (AllocatorUnion_GetMaxPossibleAllocation((Struct02012dd0*)&g_mainAllocator) > 0x400) {
        SafeAllocator allocator;
        allocator.ResetAllocatorPointer();
        allocator.ResetAllocatorPointer();
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x400);
        allocator.CreateTypeA(buffer, 0x400);
        allocator.Reset();
        func_0209576c((Struct_020956b8*)var1, &allocator, data, length, 0);
        func_02095d30(var1, manager->scriptId, 0);
        SignedAllocatorHeader* memory = allocator.GetSignedAllocator();
        if (memory) {
            allocator.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, memory);
        }
    }
    func_020da034(manager, 0);
}
