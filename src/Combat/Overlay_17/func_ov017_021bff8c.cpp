#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct* s, int val);
extern "C" void* MessageSystem_GetInstance(void);
extern "C" void* func_ov017_021b8478(void* obj);
struct ListHead02046b60;
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" int FieldTaskQueue_IsEmpty(void** p);
extern "C" int GameObject_IsGesturing(signed char* p);
extern "C" int GameObject_IsControlEnabled(void* obj);
extern "C" int GameObject_IsClimbingLadder(char* p);
extern "C" void func_ov017_021cf4b0(int a, int b);
extern "C" void func_0200fb40(void* obj);
extern "C" int* func_020936f8(void);
extern "C" void func_02094030(int*, short, short, int);
struct Struct_ov017_021c0124;
extern "C" void func_ov017_021c0124(Struct_ov017_021c0124* p, unsigned char flag);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

struct Struct_ov017_021bff8c {
#if defined(jpn)
    char pad[0x34ec];
#else
    char pad[0x36fc];
#endif
    TailList020469b4* list;
    char unknown_3700_[0x3718 - 0x3700];
    void* table;
#if defined(jpn)
    char unknown_350c_[0x38fc - 0x350c];
#else
    char unknown_371c_[0x3b1c - 0x371c];
#endif
    Struct_ov017_021c0124* state;
};

// USA: func_ov017_021bff8c
extern "C" ARM void func_ov017_021bff8c(Struct_ov017_021bff8c* ctx, unsigned char flag) {
#if defined(jpn)
 enum {Enum_ov017_021bff8c_434=0x1a6,Enum_ov017_021bff8c_2456=0x868};
#else
 enum {Enum_ov017_021bff8c_434=0x1b2,Enum_ov017_021bff8c_2456=0x998};
#endif
    if (func_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance()), 0) == 0) {
        int match = 0;
        int blocked = 0;
        GameState* gs = GameState::GetInstance();
        GameObject* leader = gs->GetPartyMemberByIndex(0);
        GameObject* hero = gs->GetProtagonist();
        char* g = (char*)MessageSystem_GetInstance();
        Struct_ov017_021bff8c* base = (Struct_ov017_021bff8c*)GetGameResources();
        void* table = NULL;
        if (base != NULL) {
            table = base->table;
        }
        if (table != NULL) {
            func_ov017_021b8478(table);
        }
        unsigned short var8 = *(unsigned short*)((char*)hero + Enum_ov017_021bff8c_434);
        if (var8 != 0) {
            if (*(unsigned short*)((char*)leader + Enum_ov017_021bff8c_434) == var8) {
                match = 1;
            } else {
                blocked = 1;
            }
        } else if (func_02046b60((ListHead02046b60*)ctx->list, 3)) {
            blocked = 1;
        }
        if (FieldTaskQueue_IsEmpty((void**)ctx->list) == 0) {
            blocked = 1;
        } else if (GameObject_IsGesturing((signed char*)hero) != 0) {
            blocked = 1;
        } else if (GameObject_IsControlEnabled(hero) == 0) {
            blocked = 1;
        } else if (*(int*)(g + Enum_ov017_021bff8c_2456) != 0) {
            blocked = 1;
        } else if (GameObject_IsClimbingLadder((char*)hero) != 0) {
            blocked = 1;
        }
        unsigned char heroIndex = hero->obj3D_.actorIndex_;
        if (match) {
            func_ov017_021cf4b0(heroIndex, 5);
            func_0200fb40(gs);
            return;
        }
        if (blocked) {
            func_ov017_021cf4b0(heroIndex, 4);
            func_0200fb40(gs);
            return;
        }
        func_ov017_021cf4b0(heroIndex, 1);
        func_02094030(func_020936f8(), 0x2712, -1, flag);
    }
    func_ov017_021c0124(ctx->state, flag);
    func_020469b4(ctx->list, (TailNode020469b4*)ctx->state);
}
