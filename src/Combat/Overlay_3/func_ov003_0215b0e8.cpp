#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kRegionValue998_868 = 0x868 };
enum { Enum_ov003_0215b0e8_2464 = 0x870 };
enum { Enum_ov003_0215b0e8_2478 = 0x7de };
#else
enum { kRegionValue998_868 = 0x998 };
enum { Enum_ov003_0215b0e8_2464 = 0x9a0 };
enum { Enum_ov003_0215b0e8_2478 = 0x9ae };
#endif

extern "C" void* MessageSystem_GetInstance(void);
struct Container020e0310;
extern "C" void* KeyTable_Get(Container020e0310*, int);
extern "C" void func_ov003_02159250(void*, void*);
extern "C" void MessageSystem_Stop(void*);
struct Struct0209c830;
extern "C" void func_0209c830(Struct0209c830*, int);
extern "C" int func_0209ca2c(void*);

extern unsigned char g_bgmPlayer;

// USA: func_ov003_0215b0e8
extern "C" ARM void func_ov003_0215b0e8(void* self) {
    unsigned char* s = (unsigned char*)self;
    GameState::GetInstance();
    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();
    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        if (*(unsigned char*)(s + 0x59d) != 0) return;

        void* val0 = KeyTable_Get((Container020e0310*)(s + 0x64), 0x44c);
        if (val0 != 0 && strlen((char*)val0) != 0) {
            *(int*)(g + kRegionValue998_868) = 1;
            void* val1 = KeyTable_Get((Container020e0310*)(s + 0x64), 0x44c);
            func_ov003_02159250(self, val1);
        } else {
            MessageSystem_Stop(g);
        }
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 1) {
        if (*(int*)(g + kRegionValue998_868) != 0) return;
        func_0209c830((Struct0209c830*)&g_bgmPlayer, 0x3b);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state != 2) return;

    if (*(int*)(g + Enum_ov003_0215b0e8_2464) == 3) {
        *(unsigned char*)(g + 0x1000 + Enum_ov003_0215b0e8_2478) = 0;
    }
    if (func_0209ca2c(&g_bgmPlayer) == 0) {
        *(unsigned char*)(s + 0x588) = 1;
        *(unsigned char*)(s + 0x580) = 0;
    }
}
