#include <globaldefs.h>
#include "Resource/Brightness.h"
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_02094654(void* obj);
extern "C" void func_020947f0(void* obj);

extern "C" int LinkSession_IsActive(int* obj);

struct ListHead02046b60;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);

extern "C" void* GlobalFlags_GetInstance(void);

struct FlagWord02046708;
extern "C" int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);

struct Struct_02093f68 {
    char pad[(IS_JPN ? 0x139 : 0x3c9)];
    bool flag1 : 1;
};

// USA: func_02093f68
extern "C" ARM void func_02093f68(char* obj) {
    int base1 = (int)GetGameResources();
    int var1 = *(int*)(base1 + (IS_JPN ? 0x34ec : 0x36fc));

    if (IsScreenFullyFaded((GameResources*)base1, true)) return;
    if (((unsigned char*)obj)[(IS_JPN ? 0x13d : 0x3cd)] & 2) return;

    int base2 = (int)GetGameResources();

    if (LinkSession_IsActive((int*)LinkSession_GetInstance())
        || *(int*)(base2 + (IS_JPN ? 0x41e4 : 0x4494))
        || func_02046b60((struct ListHead02046b60*)var1, 0x26)) {
        func_02094654(obj);
    }

    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 0x8020)) return;
    if (!((struct Struct_02093f68*)obj)->flag1) return;
    if (obj[(IS_JPN ? 0x13b : 0x3cb)] <= 0) return;

    unsigned char v = obj[(IS_JPN ? 0x13d : 0x3cd)];
    if (v & 1) return;
    if (!(v & 4)) return;

    func_020947f0(obj);
}
