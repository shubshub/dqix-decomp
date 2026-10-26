#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02155740_503 = 0x1f3 };
enum { Enum_ov003_02155740_508 = 0x1f8 };
enum { Enum_ov003_02155740_816 = 0x32c };
enum { Enum_ov003_02155740_820 = 0x330 };
#else
enum { Enum_ov003_02155740_503 = 0x1f7 };
enum { Enum_ov003_02155740_508 = 0x1fc };
enum { Enum_ov003_02155740_816 = 0x330 };
enum { Enum_ov003_02155740_820 = 0x334 };
#endif

extern "C" float _fflt(int v);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float v);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021c9e00(int id, int flagA, int arg2, int flagC);

// USA: func_ov003_02155740
extern "C" ARM void func_ov003_02155740(char* obj) {
    GameState* battle = GameState::GetInstance();
    signed char idx = *(signed char*)(obj + Enum_ov003_02155740_503);
    GameObject* c = battle->GetPartyMemberByIndex(idx);
    if (c == 0) {
        return;
    }

    if (*(int*)(obj + Enum_ov003_02155740_508) & 1) {
        unsigned short* src = *(unsigned short**)((char*)c + 0x134);
        unsigned short w = src[0x30 / 2];
        int v1 = _ffix(_fmul(*(float*)(obj + Enum_ov003_02155740_816), _fflt(w)));
        unsigned short h = src[0x32 / 2];
        int v2 = _ffix(_fmul(*(float*)(obj + Enum_ov003_02155740_820), _fflt(h)));

        if (v1 <= 0) v1 = 1;
        if (v2 <= 0) v2 = 0;
        if (w < v1) v1 = w;
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = (unsigned short)v1;
        if (h < v2) v2 = h;
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = (unsigned short)v2;
    } else {
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x30);
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x32);
    }

    void* ptr = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)ptr) == 0) {
        return;
    }
    signed char id2 = *(signed char*)(obj + Enum_ov003_02155740_503);
    func_ov017_021c9e00(id2, 1, 0, 1);
}
