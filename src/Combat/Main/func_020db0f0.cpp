#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory.h"


extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" char* func_020467c0(void* a, char* b, unsigned int* outSize);
extern "C" int func_020b01a4(void* file, void** out);
struct Hdr02b0288;
extern "C" int func_020b01f0(struct Hdr02b0288* h, void** out);
extern "C" void HaltSystem(void);

extern AllocatorUnion g_mainAllocator;
extern unsigned char g_fileLoadBuffer[0x30000];
extern const char data_020f290c;
extern const char data_020f2925;
extern const char data_020f2936;

struct Struct_020db0f0 {
    char pad[0x10];
    unsigned int size;
    void* data;
};

struct Struct_020db0f0_2 {
    char pad[0xc];
    void* data;
};

struct Manager020db0f0 {
    SafeAllocator allocator;
    char pad[0x40 - sizeof(SafeAllocator)];
    void* unknown_40_;
    unsigned int unknown_44_;
    void* unknown_48_;
    unsigned int unknown_4c_;
};

// USA: func_020db0f0
extern "C" ARM void func_020db0f0(Manager020db0f0* mgr) {
    unsigned int fileLength;
    unsigned int var1;
    unsigned int var2;
    char* var3;
    Hdr02b0288* var4;
    Struct_020db0f0* var5;
    Struct_020db0f0_2* var6;
    void* buf;

    mgr->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x300), 0x300);
    mgr->allocator.Reset();
    BackgroundLoader::AddLockGlobal();

    buf = g_fileLoadBuffer;

    fileLength = 0;
    LoadFileIntoMemory(&data_020f290c, buf, &fileLength);

    var1 = 0;
    var2 = 0;
    var3 = func_020467c0(buf, (char*)&data_020f2925, &var1);
    var4 = (Hdr02b0288*)func_020467c0(buf, (char*)&data_020f2936, &var2);

    var5 = NULL;
    if (!func_020b01a4(var3, (void**)&var5)) {
        HaltSystem();
    }

    mgr->unknown_44_ = var5->size;
    mgr->unknown_40_ = mgr->allocator.Allocate(mgr->unknown_44_);
    VectorizedInvertedMemcpy(var5->data, mgr->unknown_40_, mgr->unknown_44_);

    var6 = NULL;
    if (!func_020b01f0(var4, (void**)&var6)) {
        HaltSystem();
    }

    mgr->unknown_4c_ = 0x20;
    mgr->unknown_48_ = mgr->allocator.Allocate(mgr->unknown_4c_);
    VectorizedInvertedMemcpy(var6->data, mgr->unknown_48_, mgr->unknown_4c_);

    BackgroundLoader::RemoveLockGlobal();
}
