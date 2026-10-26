#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02010604_2428 = 0x71c, Enum_02010604_396 = 0x180, Enum_02010604_2432 = 0x720, Enum_02010604_2416 = 0x710, Enum_02010604_3248 = 0xa50, Enum_02010604_3252 = 0xa54, Enum_02010604_3256 = 0xa58, Enum_02010604_1833 = 0x4c9 };
#else
enum { Enum_02010604_2428 = 0x97c, Enum_02010604_396 = 0x18c, Enum_02010604_2432 = 0x980, Enum_02010604_2416 = 0x970, Enum_02010604_3248 = 0xcb0, Enum_02010604_3252 = 0xcb4, Enum_02010604_3256 = 0xcb8, Enum_02010604_1833 = 0x729 };
#endif

#include "GameState/GameState.h"



extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_ov017_021d2400(void);
extern "C" void func_02048150(void* combatant, int a, int b);
extern "C" void func_ov017_021cedf4(int a, int b, int c);
extern "C" void func_ov017_021c9e00(int a, int b, int c, int d);
extern "C" void func_ov017_0219bfb4(int a, int b);

extern "C" int LinkSession_IsActive(int* obj);

struct Struct_02010604_3;
extern "C" int func_020482bc(struct Struct_02010604_3* c);

struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);

extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

extern int data_020f83d8;

struct Struct_02010604_2 {
    char pad0[0x130];
    unsigned int* current;
    char unknown_134_[Enum_02010604_396 - 0x134];
    unsigned int unknown_18c_;
};

// USA: func_02010604
extern "C" ARM void func_02010604(GameState* obj, int arg1, int arg2, int arg3) {
    void* g = LinkSession_GetInstance();
    int i;

    if (arg1 != 0) {
        if (LinkSession_IsActive((int*)g)) {
            func_ov017_021d2400();
        }
    }

    for (i = 0; i < *((unsigned char*)((char*)obj + 0x3000) + Enum_02010604_2432); i++) {
        int id = *((unsigned char*)((char*)obj + i + 0x3000) + Enum_02010604_2428);
        GameObject* combatant = obj->GetPartyMemberByIndex(id);
        struct Struct_02010604_2* view;
        if (combatant == NULL) continue;
        view = (struct Struct_02010604_2*)combatant;
        if ((*view->current & 1) == 0) continue;
        func_02048150(combatant, 0, 1);
        func_020482bc((struct Struct_02010604_3*)combatant);
        view->unknown_18c_ &= ~1;
        GameObject_ForceMotionState((struct Bytes02033b88*)combatant, 0);
        if (LinkSession_IsActive((int*)g)) {
            func_ov017_021cedf4(id, 1, 0);
            func_ov017_021c9e00(id, 0, 0, 1);
        }
    }

    if (arg2 != 0) {
        unsigned int* var5 = (unsigned int*)((char*)obj + 0x3000 + Enum_02010604_2416);
        *var5 = *var5 >> 1;
    }

    func_ov017_0219bfb4(2, arg3);

    if (*(int*)((char*)obj + 0x5000 + Enum_02010604_3248) == 0x10 && *(int*)((char*)obj + 0x5000 + Enum_02010604_3252) == 2 &&
        *(int*)((char*)obj + 0x5000 + Enum_02010604_3256) == 1) {
        void* g2 = Scenario_GetInstance();
        Scenario_SetFlag(g2, (unsigned char*)((char*)g2 + 0x8c), 0x113a, 0);
    }

    *((unsigned char*)&data_020f83d8 + Enum_02010604_1833) = 0;
}
