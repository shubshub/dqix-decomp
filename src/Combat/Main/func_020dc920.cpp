#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0202b2f0;

struct Struct_020dc920 {
    unsigned char unknown_0_0_ : 5;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 2;
};

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
int GameState_GetProtagonistIndex(GameState* gameState);
int IsEntryFlagBit11Set_0202be08(struct SearchStruct* search, int id);
int IsEntryFlagBit13Set_0202be70(struct SearchStruct* search, int id);
int IsEntryFlagBit14Set_0202bed8(struct SearchStruct* search, int id);
char* GetCombatantWithFlag0x1000_0200ff58(GameState* gameState, int index);
int GetSignedByte0x2d0_020546a8(void* obj);

// USA: func_020dc920
extern "C" ARM int func_020dc920(int a, int b, int c, int d) {
    GameState* battle = GameState::GetInstance();
    GameObject* protagonist = battle->GetProtagonist();
    struct SearchStruct* search = (struct SearchStruct*)LinkSession_GetInstance();
    if (protagonist != NULL) {
        GameObject* party = battle->GetPartyMemberByIndex(a);
        if (party != NULL) {
            if (LinkSession_IsActive((int*)search) && d) {
                int id = a;
                if (party->obj3D_.unknown_0_ & 0x1000)
                    id = 0;
                if (id != GameState_GetProtagonistIndex(battle)) {
                    if (!IsEntryFlagBit13Set_0202be70(search, id))
                        return 0;
                }
            }
            if (b != 0 && a != GameState_GetProtagonistIndex(battle)) {
                if (IsEntryFlagBit11Set_0202be08(search, a))
                    return 0;
                char* combatant = GetCombatantWithFlag0x1000_0200ff58(battle, a);
                if (combatant != NULL) {
                    int id = GetSignedByte0x2d0_020546a8(combatant);
                    if (IsEntryFlagBit11Set_0202be08(search, id)) {
                        if (id != GameState_GetProtagonistIndex(battle))
                            return 0;
                    }
                }
                if (func_0202bed8(var2, arg0))
                    return 0;
                combatant = GetCombatantWithFlag0x1000_0200ff58(battle, a);
                if (combatant != NULL) {
                    int id = GetSignedByte0x2d0_020546a8(combatant);
                    if (IsEntryFlagBit14Set_0202bed8(search, id)) {
                        if (id != GameState_GetProtagonistIndex(battle))
                            return 0;
                    }
                }
            }
            int var8 = 0;
            if (var1->obj3D_.GetField06() == var3->obj3D_.GetField06()) {
                var8 = 1;
            } else if (arg2 != 0 && ((var1->obj3D_.GetField06() == 10000 && var3->obj3D_.GetField06() == 5900) ||
                                  (var1->obj3D_.GetField06() == 5900 && var3->obj3D_.GetField06() == 10000))) {
                var8 = 1;
            } else if (arg2 != 0 && ((var1->obj3D_.GetField06() == 10100 && var3->obj3D_.GetField06() == 6401) ||
                                  (var1->obj3D_.GetField06() == 6401 && var3->obj3D_.GetField06() == 10100))) {
                var8 = 1;
            }
            if (var8 != 0) {
                if (((struct Struct_020dc920*)((unsigned char*)var1 + 0xc2))->unknown_0_5_)
                    return ((struct Struct_020dc920*)((unsigned char*)var3 + 0xc2))->unknown_0_5_ != 0;
                return ((struct Struct_020dc920*)((unsigned char*)var3 + 0xc2))->unknown_0_5_ == 0;
            }
        }
    }
    return 0;
}
