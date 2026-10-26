#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
enum { Enum_ov000_02166978_22289 = 0x5901, Enum_ov000_02166978_14176 = 0x371c, Enum_ov000_02166978_21076 = 0x5310, Enum_ov000_02166978_22008 = 0x57e8 };
#else
enum { Enum_ov000_02166978_22289 = 0x5711, Enum_ov000_02166978_14176 = 0x3760, Enum_ov000_02166978_21076 = 0x5254, Enum_ov000_02166978_22008 = 0x55f8 };
#endif
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Graphics.h"
#include "Resource/GameResources.h"

extern "C" void Main_HandleLid(void);
extern "C" void func_ov000_021723a8(void* obj, void* src);
extern "C" void func_ov000_02172128(void* obj, void* src);
extern "C" int func_ov000_021729ac(void* obj);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* work, int mask);

// USA: func_ov000_02166978
extern "C" ARM void func_ov000_02166978(unsigned char* arg0) {
    char* var0 = (char*)GetGameResources();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    *(signed char*)(arg0 + Enum_ov000_02166978_22289) = 0;
    for (;;) {
        signed char state = *(signed char*)(obj + stateOffset);
        if (state == 0) {
            FontBankLoader* g = FontBankLoader_GetInstance();
            BlankFunction02094b40(g);
            BlankFunction02094b34(g, 0x65, 500, 0, 0);
            *(signed char*)(obj + stateOffset) = 1;
        } else if (state == 1) {
            if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()) != 0) {
                *(signed char*)(obj + stateOffset) = -1;
                break;
            }
        }
        loader->RemoveAllLocks();
        Main_HandleLid();
    }
    func_ov000_021723a8(obj + workOffset, res + 0x128);
    func_ov000_02172128(obj + workOffset, obj + 0x1c);
    *(unsigned char**)(obj + pointerOffset) = obj + 0x30;
    while (func_ov000_021729ac(obj + workOffset) == 0) {
        loader->RemoveAllLocks();
        Main_HandleLid();
    }
    DISPCNT = (DISPCNT & ~0x1f00) | 0x1100;
    *(int*)(arg0 + Enum_ov000_02166978_22008) = 1;
    func_ov000_02160fa8(arg0, 0x20);
}
