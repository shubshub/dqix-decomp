#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Filesystem/FSInnerDefs.h"

struct FlagWord02046708 { unsigned int flags; };

void* GlobalFlags_GetInstance(void);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
int Forward020bbdcc(int a);
extern "C" int func_020ce89c(int a, int b, int c);
int DispatchIfEquals1_020cedc0(int a);
void CancelActionIfHeadIdMatches_02199e98(void* obj);
int IsPowcntBit0Set_020cede0(void);

// USA: func_02012de8  (semantic: HandleBrightnessOrDispatchState02012de8)
extern "C" ARM void func_02012de8(void) {
    struct FlagWord02046708* p1 = (struct FlagWord02046708*)GlobalFlags_GetInstance();
    int* p2 = (int*)func_0202ae18();

    int bit15 = (*(volatile unsigned short*)0x027fffa8 & 0x8000) >> 15;
    if (bit15) {
        if (CheckField0NonZero_0202b7d8(p2) && !TestFlags02046708(p1, 0x1000000)) {
            goto skipFirst;
        }
        if (!TestFlags02046708(p1, 0x80)) {
            Forward020bbdcc(0);
            func_020ce89c(0xc, 0, 0);
            if (func_020d1198() == 0) {
                Forward020bbdcc(0x7f);
            }
            return;
        }
    skipFirst:
        if (!TestFlags02046708(p1, 0x400000)) {
            DispatchIfEquals1_020cedc0(0);
        }
        if (!CheckField0NonZero_0202b7d8(p2)) return;
        if (TestFlags02046708(p1, 0x1000000)) return;
        {
            int word = (int)GameState::GetInstance()->GetResources();
            if (word == 0) return;
            CancelActionIfHeadIdMatches_02199e98((void*)word);
        }
        return;
    }

    if (IsPowcntBit0Set_020cede0()) return;
    DispatchIfEquals1_020cedc0(1);
    {
        int word = (int)GameState::GetInstance()->GetResources();
        if (word == 0) return;
        WriteBrightnessToHardware((GameResources*)word);
    }
}
