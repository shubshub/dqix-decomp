#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_0218466c(void* obj, unsigned short id);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" void SprSprite_Init(void* obj);
extern "C" void SprSprite_LoadFile(void* a, int b, int c, int d);

struct Struct_ov023_021f7290 { char pad[8]; unsigned short unknown_8_; unsigned short unknown_a_; };

// USA: func_ov023_021f7290
extern "C" ARM void func_ov023_021f7290(struct Struct_ov023_021f7290* obj, void* ctx, int p2, int p3) {
    if (p2 == 0 || p3 == 0) return;
    void* base = func_ov011_021845f8(ctx, obj->unknown_8_);
    void* node = func_ov011_0218466c(ctx, obj->unknown_a_);
    if (base == NULL || node == NULL) return;
    SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
    alloc->GetSizeWithLargestBlockRemoved();
    VramState_Restore((char*)node + 4);
    SprSprite_Init((char*)obj + 0x20);
    SprSprite_LoadFile((char*)obj + 0x20, p2, p3, (int)((char*)base + 4));
    VramState_Save((char*)node + 4);
    alloc->GetSizeWithLargestBlockRemoved();
}
