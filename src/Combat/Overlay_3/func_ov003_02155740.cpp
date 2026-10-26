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
int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021c9e00(int id, int flagA, int flagB, int flagC);

// USA: func_ov003_02155740
extern "C" ARM void func_ov003_02155740(char* arg0) {
    GameState* var0 = GameState::GetInstance();
    signed char var1 = *(signed char*)(arg0 + Enum_ov003_02155740_503);
    GameObject* var2 = var0->GetPartyMemberByIndex(var1);
    if (var2 == 0) {
        return;
    }

    if (*(int*)(arg0 + Enum_ov003_02155740_508) & 1) {
        unsigned short* var3 = *(unsigned short**)((char*)var2 + 0x134);
        unsigned short var4 = var3[0x30 / 2];
        int var5 = _ffix(_fmul(*(float*)(arg0 + Enum_ov003_02155740_816), _fflt(var4)));
        unsigned short var6 = var3[0x32 / 2];
        int var7 = _ffix(_fmul(*(float*)(arg0 + Enum_ov003_02155740_820), _fflt(var6)));

        if (var5 <= 0) var5 = 1;
        if (var7 <= 0) var7 = 0;
        if (var4 < var5) var5 = var4;
        *(unsigned short*)(*(char**)((char*)var2 + 0x130) + 4) = (unsigned short)var5;
        if (var6 < var7) var7 = var6;
        *(unsigned short*)(*(char**)((char*)var2 + 0x130) + 6) = (unsigned short)var7;
    } else {
        *(unsigned short*)(*(char**)((char*)var2 + 0x130) + 4) = *(unsigned short*)(*(char**)((char*)var2 + 0x134) + 0x30);
        *(unsigned short*)(*(char**)((char*)var2 + 0x130) + 6) = *(unsigned short*)(*(char**)((char*)var2 + 0x134) + 0x32);
    }

    void* ptr = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)ptr) == 0) {
        return;
    }
    signed char var9 = *(signed char*)(arg0 + Enum_ov003_02155740_503);
    func_ov017_021c9e00(var9, 1, 0, 1);
}
