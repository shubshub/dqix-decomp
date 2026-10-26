#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Foo02033b58;
extern "C" void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);
extern "C" void func_ov017_02195540(unsigned char* obj);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_ov025_021ed124(unsigned char* obj);
extern "C" void func_ov025_021e8a4c(char* obj, int v);
extern "C" void func_ov025_021e8d14(void* obj);
extern "C" void func_ov025_021df9b0(void* obj);
extern "C" void func_ov025_021eed58(char* obj);

extern "C" ARM void func_ov025_021e88d8(void* obj);
extern "C" ARM void func_ov025_021dfbfc(void* obj);
extern "C" int func_ov000_0215ec1c(void* obj, short* buf, int max, int start);

#if defined(jpn)
enum { RegionOffset2a8 = 0x224, RegionOffset29c = 0x218, Enum_ov025_021db6dc_23216 = 0x5ca0, Enum_ov025_021db6dc_2864 = 0xaac, Enum_ov025_021db6dc_3760 = 0xe2c, Enum_ov025_021db6dc_6590 = 0x17ee, Enum_ov025_021db6dc_672 = 0x21c, Enum_ov025_021db6dc_2192 = 0x80c, Enum_ov025_021db6dc_3756 = 0xe28, Enum_ov025_021db6dc_28629 = 0x71c5 };
#else
enum { RegionOffset2a8 = 0x2a8, RegionOffset29c = 0x29c, Enum_ov025_021db6dc_23216 = 0x5ab0, Enum_ov025_021db6dc_2864 = 0xb30, Enum_ov025_021db6dc_3760 = 0xeb0, Enum_ov025_021db6dc_6590 = 0x19be, Enum_ov025_021db6dc_672 = 0x2a0, Enum_ov025_021db6dc_2192 = 0x890, Enum_ov025_021db6dc_3756 = 0xeac, Enum_ov025_021db6dc_28629 = 0x6fd5 };
#endif

// USA: func_ov025_021db6dc
extern "C" ARM void func_ov025_021db6dc(void* arg) {
    char* obj = (char*)arg;
    GameState* bs = GameState::GetInstance();
    int g = MessageSystem_GetInstance();
    int handle = ((int)GetGameResources());

    func_ov025_021e88d8(obj + RegionOffset2a8);
    func_ov025_021e8a4c(obj + RegionOffset2a8, *(int*)(obj + RegionOffset29c));
    func_ov025_021e8d14(obj + RegionOffset2a8);
    func_ov025_021df9b0(obj + Enum_ov025_021db6dc_23216);
    func_ov025_021eed58(obj + Enum_ov025_021db6dc_2864);
    *(int*)(obj + Enum_ov025_021db6dc_3760) = 0;
    func_ov017_02195540((unsigned char*)handle);
    *(unsigned char*)((char*)g + Enum_ov025_021db6dc_6590) = 1;
    *(unsigned char*)(*(char**)(obj + RegionOffset29c) + 0x8e49) = 0;
    *(unsigned char*)(*(char**)(obj + Enum_ov025_021db6dc_672) + 0x35) = 0;
    func_ov025_021dfbfc(obj);

    short buf[16];
    int n = 0;
    n = n + func_ov000_0215ec1c(*(void**)(obj + RegionOffset29c), buf, 0x10, n);
    for (int i = 0; i < n; i++) {
        GameObject* c = bs->GetCombatantByIndex(buf[i]);
        if (c != 0) {
            int f = *(int*)((char*)c->currentStats_ + 0x14);
            if (!(f & 1)) {
                GameObject_StoreMotionState((struct Foo02033b58*)c, 0);
            }
        }
    }

    func_ov025_021ed124((unsigned char*)(obj + Enum_ov025_021db6dc_2192));
    *(int*)(obj + Enum_ov025_021db6dc_3756) = 1;
    *(unsigned char*)(obj + Enum_ov025_021db6dc_28629) = 0;
}
