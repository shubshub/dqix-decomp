#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct_ov015_0218b5a0 { void* ptr; int pad4; int field8; };

extern "C" void func_ov015_0218b828(struct Struct_ov015_0218b5a0* o, int count);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

// USA: func_ov015_0218b978
extern "C" ARM void func_ov015_0218b978(struct Struct_ov015_0218b5a0* o, int count) {
    func_ov015_0218b828(o, count);
    o->ptr = AllocatorUnion_AllocateRounded(&g_mainAllocator, count * 0xc);
    o->field8 = 0;
}
