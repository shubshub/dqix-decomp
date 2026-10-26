#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_0218466c(void* obj, unsigned short id);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
struct ObjectArchiveLoadInfo;
struct Struct_0203d028_18;

struct Struct_ov023_021fd120 { char pad[8]; unsigned short unknown_8_; unsigned short unknown_a_; };

// USA: func_ov023_021fd120
extern "C" ARM void func_ov023_021fd120(struct Struct_ov023_021fd120* obj, void* ctx, int p2, int p3) {
    if (p2 == 0 || p3 == 0) return;
    void* base = func_ov011_021845f8(ctx, obj->unknown_8_);
    void* node = func_ov011_0218466c(ctx, obj->unknown_a_);
    if (base == NULL || node == NULL) return;
    SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
    alloc->GetSizeWithLargestBlockRemoved();
    VramState_Restore((char*)node + 4);
    ((Object3D*)((char*)obj + 0x20))->Initialize();
    struct Struct_ov023_021fd120_2 { int f0; int f4; int f8; void* fc; int f10; int f14; int f18; int f1c; } local;
    local.f4 = p2;
    local.f8 = p3;
    local.fc = alloc;
    ((Object3D*)((int)((char*)obj + 0x20)))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)((int)&local));
    ((Object3D*)((char*)obj + 0x20))->SetAnimationByIndex(0, 0);
    ((Object3D*)((struct Struct_0203d028_18*)((char*)obj + 0x20)))->SetScale(0x10a, 0x10a, 0x10a);
    VramState_Save((char*)node + 4);
    alloc->GetSizeWithLargestBlockRemoved();
}
