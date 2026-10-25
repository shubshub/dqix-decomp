#include <globaldefs.h>
#include "Resource/QuestScript.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/HPXEAllocator.h"
#include "Filesystem/BackgroundLoader.h"
struct SlotManager020da034 { char unknown0[8]; unsigned short usedMask; char unknowna[2]; int slots[1]; int scriptId; };
struct Struct02012dd0 { void* field0; HPXEAllocator* alloc; };
int* GetGlobal02109418_02094d6c();
unsigned int GetMaxAlloc02012dd0(Struct02012dd0*);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void AllocatorUnion_Free(AllocatorUnion*, void*);
void ReleaseSlot020da034(SlotManager020da034*, int);
extern "C" void func_02095d30(int*, int, int);
extern AllocatorUnion g_mainAllocator;

// USA: func_020da074
extern "C" ARM void func_020da074(SlotManager020da034* manager) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* interpreter = GetGlobal02109418_02094d6c();
    void* data;
    unsigned int length;
    loader->GetLoadedFileByID(manager->slots[0], &data, &length);
    if (GetMaxAlloc02012dd0((Struct02012dd0*)&g_mainAllocator) > 0x400) {
        SafeAllocator allocator;
        allocator.ResetAllocatorPointer();
        allocator.ResetAllocatorPointer();
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x400);
        allocator.CreateTypeA(buffer, 0x400);
        allocator.Reset();
        func_0209576c((Header020956b8*)interpreter, &allocator, data, length, 0);
        func_02095d30(interpreter, manager->scriptId, 0);
        SignedAllocatorHeader* memory = allocator.GetSignedAllocator();
        if (memory) {
            allocator.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, memory);
        }
    }
    func_020da034(arg0, 0);
}
