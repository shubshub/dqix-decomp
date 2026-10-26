#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov024_021f5c80
#define data_ov023_021ff5b4 data_ov023_021fe83c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned char func_0200fb9c(char* obj);
extern "C" unsigned char func_02012034(void* obj);
extern "C" int _s32_div_f(int a, int b);
extern "C" int func_ov017_021d4df8(void* obj, int key);
extern "C" void func_ov017_021d4ce4(void* obj, int key);
extern "C" void func_ov017_021d4ccc(void* obj);

// USA: func_ov011_021848a8
extern "C" ARM void func_ov011_021848a8(void* obj) {
    GameState* battle = GameState::GetInstance();
    if (func_0200fb9c((char*)battle) == 6) {
        if (func_02012034(battle) == 1) {
            unsigned int sum = *(unsigned int*)((char*)obj + 0x1d0) + battle->GetTickCount();
            *(unsigned int*)((char*)obj + 0x1d0) = sum;
            if (sum > 0xe10) {
                *(unsigned int*)((char*)obj + 0x1d0) = 0;
                *(int*)((char*)obj + 0x10c) = 999;
                unsigned char* p = (unsigned char*)battle + R(0x7c9d, 0x7f71);
                unsigned char v = *p + 1;
                *p = v % 3;
            }
        } else {
            *(unsigned int*)((char*)obj + 0x1d0) = 0;
        }
    }

    if (*(int*)((char*)obj + 0x10c) >= 0) {
        if (func_ov017_021d4df8((char*)obj + 0xb8, *(int*)((char*)obj + 0x10c)) == 0) {
            *(int*)((char*)obj + 0x10c) = -1;
            return;
        }
        *(int*)((char*)obj + 0x110) = *(int*)((char*)obj + 0x10c);
        *(int*)((char*)obj + 0x10c) = -1;
        func_ov017_021d4ce4((char*)obj + 0xb8, *(int*)((char*)obj + 0x110));
        if (*(int*)((char*)obj + 0xf4) != 0) {
            *(int*)((char*)obj + 0x110) = -1;
        }
        return;
    }

    if (*(int*)((char*)obj + 0x110) < 0) {
        return;
    }
    func_ov017_021d4ccc((char*)obj + 0xb8);
    if (*(int*)((char*)obj + 0xf4) != 0) {
        *(int*)((char*)obj + 0x110) = -1;
    }
}
