#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
unsigned long long GetCurrentTimestamp(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);

struct Struct_ov017_021ce054 {
    unsigned char pad0[4];
    unsigned short field4;
    short field6;
    unsigned short field8;
};

// USA: func_ov017_021ce054
extern "C" ARM void func_ov017_021ce054(int arg0, struct Struct_ov017_021ce054* src, GameState* battleStruct, char* obj) {
    int inRange = (arg0 >= 0) && (arg0 <= 3);
    if (!inRange) return;
    GameObject* c = func_0200ff1c(battleStruct, src->field8);
    if (!c) return;
    unsigned char* p = (unsigned char*)func_02053c6c((unsigned char*)c);
    void* g = LinkSession_GetInstance();
    if (src->field4 != 1) return;
    if (src->field6 > 0) {
        func_ov017_02191aac(obj, 1, c->obj3D_.actorIndex_, 2);
        p[0x56c] = 1;
        if (LinkSession_IsGuest(g)) return;
        unsigned long long var4 = GetCurrentTimestamp();
        *(unsigned int*)(p + 0x480) = (unsigned int)var4;
        *(unsigned int*)(p + 0x484) = (unsigned int)(var4 >> 32);
    } else {
        p[0x56c] = 0;
        func_ov017_02191aac(obj, 0, c->obj3D_.actorIndex_, 2);
    }
}
