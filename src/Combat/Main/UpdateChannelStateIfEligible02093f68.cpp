#include <globaldefs.h>
#include "Resource/Brightness.h"
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

extern "C" void* func_0202ae18(void);
extern "C" void func_02094654(void* obj);
extern "C" void func_020947f0(void* obj);

int CheckField0NonZero_0202b7d8(int* obj);

struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);

void* GlobalFlags_GetInstance(void);

struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);

struct FlagBits02093f68 {
    char pad[(IS_JPN ? 0x139 : 0x3c9)];
    bool flag1 : 1;
};

// USA: func_02093f68
ARM void UpdateChannelStateIfEligible02093f68(char* obj) {
    int base1 = (int)GetGameResources();
    int chVal = *(int*)(base1 + (IS_JPN ? 0x34ec : 0x36fc));

    if (IsBrightnessOutsideValidRange((GameResources*)base1, true)) return;
    if (((unsigned char*)obj)[(IS_JPN ? 0x13d : 0x3cd)] & 2) return;

    int base2 = (int)GetGameResources();

    if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())
        || *(int*)(base2 + (IS_JPN ? 0x41e4 : 0x4494))
        || ListContainsId((struct ListHead02046b60*)chVal, 0x26)) {
        func_02094654(obj);
    }

    if (TestFlags02046708((struct FlagWord02046708*)GlobalFlags_GetInstance(), 0x8020)) return;
    if (!((struct FlagBits02093f68*)obj)->flag1) return;
    if (obj[(IS_JPN ? 0x13b : 0x3cb)] <= 0) return;

    unsigned char v = obj[(IS_JPN ? 0x13d : 0x3cd)];
    if (v & 1) return;
    if (!(v & 4)) return;

    func_020947f0(obj);
}
