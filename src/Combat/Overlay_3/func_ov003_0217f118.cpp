#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void func_ov003_0216d77c(void* arg);
extern "C" void func_020a1e54(int flag);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);
extern "C" int GetMainBGAssignedVRAMSize(void);
extern "C" void MIi_CpuClearFast(int a, int b, int c);
extern "C" void ROMFilesystem_InitFileTables(void);
extern AllocatorUnion g_mainAllocator;

// USA: func_ov003_0217f118
extern "C" ARM void func_ov003_0217f118(char* self) {
    if (*(void**)(self + 0xc) != 0) {
        func_ov003_0216d77c(*(void**)(self + 0xc));
        *(void**)(self + 0xc) = 0;
        func_020a1e54(1);
    }
    SafeAllocator* var0 = (SafeAllocator*)(self + 0x14);
    void* p = var0->GetSignedAllocator();
    if (p != 0) {
        var0->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, p);
    }
    func_02074bd0((struct Struct_02074bd0*)(self + 0x2a));
    int size = GetMainBGAssignedVRAMSize();
    MIi_CpuClearFast(0, 0x6000000, size);
    ROMFilesystem_InitFileTables();
    self[1] = 1;
}
