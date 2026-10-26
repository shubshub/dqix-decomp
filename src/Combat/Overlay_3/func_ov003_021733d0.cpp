#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov003_021733d0_238 = 0xea };
enum { Enum_ov003_021733d0_204 = 0xca };
enum { kRegionValue840_860 = 0x860 };
enum { Enum_ov003_021733d0_213 = 0xd1 };
enum { Enum_ov003_021733d0_208 = 0xcc };
enum { Enum_ov003_021733d0_1120 = 0x35c };
enum { Enum_ov003_021733d0_236 = 0xe8 };
#else
enum { Enum_ov003_021733d0_238 = 0xee };
enum { Enum_ov003_021733d0_204 = 0xcc };
enum { kRegionValue840_860 = 0x840 };
enum { Enum_ov003_021733d0_213 = 0xd5 };
enum { Enum_ov003_021733d0_208 = 0xd0 };
enum { Enum_ov003_021733d0_1120 = 0x460 };
enum { Enum_ov003_021733d0_236 = 0xec };
#endif

struct GameResources;
void SetMainBrightness(GameResources*, int, int);
extern "C" int Zone3D_GetInstance(void);
extern "C" void func_02098630(void* obj, void* addr, int a, int b);

int IsMainBrightnessTransitionActive(GameResources*);
extern "C" void func_ov003_0216fb6c(char* obj);

// USA: func_ov003_021733d0
extern "C" ARM void func_ov003_021733d0(unsigned char* self) {
    GameResources* p = GetGameResources();
    if (self[Enum_ov003_021733d0_238] == 0) {
        SetMainBrightness(p, -16, 24);
        self[Enum_ov003_021733d0_238] = 1;
        return;
    }
    if (self[Enum_ov003_021733d0_238] != 1) {
        return;
    }
    if (IsMainBrightnessTransitionActive(p) != 0) {
        return;
    }
    int r4 = Zone3D_GetInstance();
    if (self[Enum_ov003_021733d0_204] == 0) {
        func_ov003_0216fb6c((char*)r4 + kRegionValue840_860);
        for (int i = 0; i < self[Enum_ov003_021733d0_213]; i++) {
            void* addr = (char*)*(int*)(self + Enum_ov003_021733d0_208) + Enum_ov003_021733d0_1120 + (unsigned char)i * 0xe8;
            func_02098630((char*)r4 + kRegionValue840_860, addr, 1, 0);
        }
        func_ov003_0216fb6c((char*)r4 + kRegionValue840_860);
    }
    self[Enum_ov003_021733d0_236] = 6;
    self[Enum_ov003_021733d0_238] = 0;
}
