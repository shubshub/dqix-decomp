#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_020541a4_330 = 0x13e };
#else
enum { Enum_020541a4_330 = 0x14a };
#endif

extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
unsigned long long GetCurrentTimestamp(void);
extern "C" void func_ov017_021ce014(int a, unsigned short b, unsigned short c, unsigned short d);

struct Struct_020541a4 {
    unsigned char pad0[4];
    short field4;
    unsigned char pad6[Enum_020541a4_330];
    unsigned char* field150;
};

// USA: func_020541a4
extern "C" ARM void func_020541a4(struct Struct_020541a4* p, unsigned char b) {
    unsigned char* q = p->field150;
    if (q == 0) return;
    GameState::GetInstance();
    void* base = GetGameResources();
    q = p->field150;
    q[0x56c] = 1;
    q = p->field150;
    q[0x56d] = b;
    func_ov017_02191aac((char*)base, 1, p->field4, 2);
    unsigned long long var2 = GetCurrentTimestamp();
    q = p->field150;
    *(unsigned int*)(q + 0x480) = (unsigned int)var2;
    *(unsigned int*)(q + 0x484) = (unsigned int)(var2 >> 32);
    func_ov017_021ce014(0, 1, 1, (unsigned short)p->field4);
}
