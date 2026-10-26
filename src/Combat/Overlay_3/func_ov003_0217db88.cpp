#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue90_8C = 0x8c };
enum { kRegionValue94_90 = 0x90 };
enum { Enum_ov003_0217db88_152 = 0x94 };
enum { Enum_ov003_0217db88_56 = 0x34 };
enum { Enum_ov003_0217db88_164 = 0xa0 };
enum { Enum_ov003_0217db88_184 = 0xb4 };
enum { kRegionValue3C_38 = 0x38 };
enum { kRegionValueCC_C8 = 0xc8 };
#else
enum { kRegionValue90_8C = 0x90 };
enum { kRegionValue94_90 = 0x94 };
enum { Enum_ov003_0217db88_152 = 0x98 };
enum { Enum_ov003_0217db88_56 = 0x38 };
enum { Enum_ov003_0217db88_164 = 0xa4 };
enum { Enum_ov003_0217db88_184 = 0xb8 };
enum { kRegionValue3C_38 = 0x3c };
enum { kRegionValueCC_C8 = 0xcc };
#endif


extern "C" void Window_Destroy(void* obj);
struct BackgroundGraphics;
extern "C" void Background_Destroy(struct BackgroundGraphics* obj);
struct Struct_0204c754;
extern "C" void func_0204c754(struct Struct_0204c754* obj);
struct Struct_0205a244;
extern "C" void func_0205a244(struct Struct_0205a244* target);
extern "C" void SpriteContext_Destroy(void* obj);
struct Struct020dfc40;
extern "C" void KeyTable_Destroy(struct Struct020dfc40* p);

// USA: func_ov003_0217db88
extern "C" ARM void func_ov003_0217db88(void* obj) {
    unsigned char* o = (unsigned char*)obj;

    Window_Destroy(*(void**)(o + kRegionValue90_8C));

    int i;
    for (i = 0; i < 2; i++) {
        Background_Destroy((struct BackgroundGraphics*)(*(char**)(o + kRegionValue94_90) + i * 0x20));
    }

    int j;
    for (j = 0; j < 1; j++) {
        func_0204c754((struct Struct_0204c754*)(*(char**)(o + Enum_ov003_0217db88_152) + j * 0xe0));
    }

    func_0205a244((struct Struct_0205a244*)(*(void**)(o + Enum_ov003_0217db88_56)));

    if (((SafeAllocator*)(o + Enum_ov003_0217db88_164))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + Enum_ov003_0217db88_164))->Destroy();
    }
    if (((SafeAllocator*)(o + Enum_ov003_0217db88_184))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + Enum_ov003_0217db88_184))->Destroy();
    }
    SpriteContext_Destroy(o + kRegionValue3C_38);
    KeyTable_Destroy((struct Struct020dfc40*)(o + kRegionValueCC_C8));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | ((unsigned int)*(int*)o << 8);
}
