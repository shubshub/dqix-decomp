#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Owner_0218b978 { void* ptr; int pad4; int field8; };

extern "C" void func_ov015_0218b828(struct Owner_0218b978* o, int count);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

// USA: func_ov015_0218b978
ARM void Init0218b978(struct Owner_0218b978* o, int count) {
    func_ov015_0218b828(o, count);
    o->ptr = AllocatorUnion_AllocateRounded(&g_mainAllocator, count * 0xc);
    o->field8 = 0;
}
