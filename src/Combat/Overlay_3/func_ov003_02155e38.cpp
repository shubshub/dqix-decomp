#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02155e38_503 = 0x1f3 };
enum { Enum_ov003_02155e38_336 = 0x144 };
enum { Enum_ov003_02155e38_2384 = 0x8b8 };
#else
enum { Enum_ov003_02155e38_503 = 0x1f7 };
enum { Enum_ov003_02155e38_336 = 0x150 };
enum { Enum_ov003_02155e38_2384 = 0x950 };
#endif

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void PartyMember_ApplyLevelStats(void* a, void* obj, void* tail);
extern "C" void PartyMember_RecalculateStats(void* a, int arg1);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

extern "C" void func_ov017_021cc730(int id, unsigned char arg1, unsigned char arg2, unsigned char arg3);
extern "C" void func_ov017_021cf078(int combatantId, unsigned short slot, unsigned char flag);
extern "C" void func_ov017_021ccc34(int combatantId);
extern "C" void func_ov017_021c9e00(int id, int flagA, int arg2, int flagC);

// USA: func_ov003_02155e38
extern "C" ARM void func_ov003_02155e38(void* p) {
    char* obj = (char*)p;
    GameState* bs = GameState::GetInstance();
    signed char idx = *(signed char*)(obj + Enum_ov003_02155e38_503);
    GameObject* c = bs->GetPartyMemberByIndex(idx);
    if (c == 0) {
        return;
    }
    int t = *(int*)((char*)c + Enum_ov003_02155e38_336);
    int slot = *(int*)((char*)t + Enum_ov003_02155e38_2384);
    int field150 = func_02053c6c((unsigned char*)c);
    char* arr = (char*)field150;
    *(short*)(arr + slot * 2 + 0x16c) = 1;
    unsigned char* var8 = (unsigned char*)(arr + 0x186);
    *(int*)(arr + slot * 4 + 0x138) = 0;
    unsigned char v = ++var8[slot];
    if (v > 10) {
        var8[slot] = v = 10;
    }
    PartyMember_ApplyLevelStats(arr, obj + 0x90, obj + 0xcc);
    PartyMember_RecalculateStats(arr, 0);
    *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x30);
    *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x32);
    if (LinkSession_IsActive((int*)LinkSession_GetInstance()) == 0) {
        return;
    }
    signed char id2 = *(signed char*)(obj + Enum_ov003_02155e38_503);
    func_ov017_021cc730(id2, 1, 0, 0);
    func_ov017_021cf078(id2, (unsigned char)slot, 0);
    func_ov017_021ccc34(id2);
    func_ov017_021c9e00(id2, 1, 0, 1);
}
