#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"

#if defined(jpn)
#define func_020c9be0 func_020cb6ac
#endif

struct AllocatorUnion;

#if defined(jpn)
#define func_ov008_021842a0 func_ov010_021842a0
#endif
extern "C" int func_ov010_02184354(void* obj);
void ForwardAndClearField8_021c2710(unsigned char* self);
extern "C" void func_020a1940(unsigned int id);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020c9be0(void);
extern "C" void func_ov008_021842a0(void* obj);
extern char g_mainAllocator;

// Overlay 17, originally func_ov017_021c26ac (USA/EUR 0x021c26ac, JPN 0x021c2c18)
extern "C" ARM void FieldTask_DigPitfall(unsigned char* self) {
    if (*(void**)(self + 8) != NULL) {
        if (func_ov010_02184354(*(void**)(self + 8)) == 0) {
            return;
        }
        func_ov017_021c2710(arg0);
        return;
    }
    func_020a1940(OVERLAY_ID(10));
    *(void**)(self + 8) = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x28);
    if (*(void**)(self + 8) == NULL) {
        func_020c9be0();
    }
    func_ov008_021842a0(*(void**)(arg0 + 8));
}
