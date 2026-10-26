#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_0216d77c_4860 = 0x118c };
enum { Enum_ov003_0216d77c_4880 = 0x11a0 };
enum { kRegionValue126C_10FC = 0x10fc };
#else
enum { Enum_ov003_0216d77c_4860 = 0x12fc };
enum { Enum_ov003_0216d77c_4880 = 0x1310 };
enum { kRegionValue126C_10FC = 0x126c };
#endif


extern "C" void SpriteContext_Destroy(void* obj);

// USA: func_ov003_0216d77c
extern "C" ARM void func_ov003_0216d77c(void* obj) {
    unsigned char* o = (unsigned char*)obj;

    if (((SafeAllocator*)(o + Enum_ov003_0216d77c_4860))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + Enum_ov003_0216d77c_4860))->Destroy();
    }
    if (((SafeAllocator*)(o + Enum_ov003_0216d77c_4880))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + Enum_ov003_0216d77c_4880))->Destroy();
    }
    SpriteContext_Destroy(o + kRegionValue126C_10FC);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | ((unsigned int)*(int*)o << 8);
}
