#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct* s, int val);
void* MessageSystem_GetInstance(void);
extern "C" void* func_ov017_021b8478(void* obj);
struct ListHead02046b60;
int ListContainsId(ListHead02046b60* list, int id);
int IsField0Null_02046b08(void** p);
int CheckSubstructByte0x7cPositive_020535c8(signed char* p);
int GetByteField0x252_02039820(void* obj);
int GetByte0x26c_02039d7c(char* p);
void EnqueueEventTag57WithAB_021cf4b0(int a, int b);
void ClearSubstructBytes_0200fb40(void* obj);
int* GetGlobal02109030_020936f8(void);
extern "C" void func_02094030(int*, short, short, int);
struct Struct_ov017_021c0124;
extern "C" void func_ov017_021c0124(Struct_ov017_021c0124* arg0, unsigned char arg1);
struct Struct_0201bdac_2;
struct Struct_0201bdac;
extern "C" void func_020469b4(Struct_0201bdac_2* arg0, Struct_0201bdac* arg1);

struct Struct_ov017_021bff8c {
#if defined(jpn)
    char unknown_0_[0x34ec];
#else
    char unknown1_0_[0x36fc];
#endif
    Struct_0201bdac_2* unknown_36fc_;
    char unknown_3700_[0x3718 - 0x3700];
    void* unknown_3718_;
#if defined(jpn)
    char unknown_350c_[0x38fc - 0x350c];
#else
    char unknown_371c_[0x3b1c - 0x371c];
#endif
    Struct_ov017_021c0124* unknown_3b1c_;
};

// USA: func_ov017_021bff8c
extern "C" ARM void func_ov017_021bff8c(Struct_ov017_021bff8c* arg0, unsigned char arg1) {
#if defined(jpn)
 enum {Enum_ov017_021bff8c_434=0x1a6,Enum_ov017_021bff8c_2456=0x868};
#else
 enum {Enum_ov017_021bff8c_434=0x1b2,Enum_ov017_021bff8c_2456=0x998};
#endif
    if (ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance()), 0) == 0) {
        int match = 0;
        int blocked = 0;
        GameState* gs = GameState::GetInstance();
        GameObject* leader = gs->GetPartyMemberByIndex(0);
        GameObject* hero = gs->GetProtagonist();
        char* g = (char*)MessageSystem_GetInstance();
        Ctx021bff8c* base = (Ctx021bff8c*)GetGameResources();
        void* table = NULL;
        if (base != NULL) {
            table = base->table;
        }
        if (var7 != NULL) {
            func_ov017_021b8478(var7);
        }
        unsigned short var8 = *(unsigned short*)((char*)var4 + Enum_ov017_021bff8c_434);
        if (var8 != 0) {
            if (*(unsigned short*)((char*)var3 + Enum_ov017_021bff8c_434) == var8) {
                var0 = 1;
            } else {
                var1 = 1;
            }
        } else if (func_02046b60((Struct_02038598_5*)arg0->unknown_36fc_, 3)) {
            var1 = 1;
        }
        if (func_02046b08((void**)arg0->unknown_36fc_) == 0) {
            var1 = 1;
        } else if (func_020535c8((signed char*)var4) != 0) {
            var1 = 1;
        } else if (func_02039820(var4) == 0) {
            var1 = 1;
        } else if (*(int*)(var5 + Enum_ov017_021bff8c_2456) != 0) {
            var1 = 1;
        } else if (func_02039d7c((char*)var4) != 0) {
            var1 = 1;
        }
        unsigned char heroIndex = hero->obj3D_.actorIndex_;
        if (match) {
            EnqueueEventTag57WithAB_021cf4b0(heroIndex, 5);
            ClearSubstructBytes_0200fb40(gs);
            return;
        }
        if (var1) {
            func_ov017_021cf4b0(var9, 4);
            func_0200fb40(var2);
            return;
        }
        func_ov017_021cf4b0(var9, 1);
        func_02094030(func_020936f8(), 0x2712, -1, arg1);
    }
    func_ov017_021c0124(arg0->unknown_3b1c_, arg1);
    func_020469b4(arg0->unknown_36fc_, (Struct_0201bdac*)arg0->unknown_3b1c_);
}
