#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_0202c1a4;
struct Struct_0205e854;

struct Struct_ov017_021b0288 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
};

struct Struct_ov017_021b0288_2 {
    char unknown_0_[0x4];
    signed char* unknown_4_;
    char unknown_8_[0x1];
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    char unknown_b_[0x10];
    unsigned char unknown_1b_[4];
    char unknown_1f_[0x24];
    unsigned char unknown_43_[4];
    unsigned char unknown_47_;
};

extern "C" SearchStruct0202c1a4* LinkSession_GetInstance(void);
unsigned char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
void SetField0x2d0_020546a0(void* obj, int value);
extern "C" void func_ov017_021c32b0(SlotPair_021b0288* pairs, int count);
void GameState_SetProtagonistIndex(GameState* gs, int value);
extern "C" void Party_ReformLine(void* unused, int c, int d, int e, int flag);
extern "C" void func_ov017_021b0a7c(SlotState_021b0288* obj);
extern "C" void func_ov017_021d0b30(int a, int b, int c);
void* LinkMessageQueue_GetInstance(void);
void* FillBitArray0x1524WithFF(struct BitArrayObj0205e854* obj);

// USA: func_ov017_021b0288
extern "C" ARM int func_ov017_021b0288(SlotState_021b0288* obj) {
    if (obj->slots[0] != 0) {
        if (obj->mode == 2) {
            GameObject* combatant;
            int j;
            int i;
            int count;
            GameResources* resources;
            SearchStruct0202c1a4* search;
            GameState* battle;
            unsigned char slots[4];
            SlotPair_021b0288 pairs[4];
            battle = GameState::GetInstance();
            search = LinkSession_GetInstance();
            resources = GetGameResources();
            count = 0;
            pairs[count].combatant = 0;
            pairs[count].slot = LinkSession_GetOwnSlot(search);
            count++;
            memcpy(slots, obj->slots, 4);
            for (i = 3; i >= 1; i--) {
                combatant = GetCombatantWithFlag0x1000_0200ff58(battle, i);
                if (combatant == 0) continue;
                for (j = 3; j >= 1; j--) {
                    if (slots[j] == 3) {
                        pairs[count].combatant = i;
                        pairs[count].slot = j;
                        SetField0x2d0_020546a0(combatant, LinkSession_GetOwnSlot(search));
                        slots[j] = 0;
                        count++;
                        break;
                    }
                }
            }
            func_ov017_021c32b0(var8, var3);
            arg0->unknown_47_ = var3;
            for (int var9 = 0; var9 < var3; var9++) {
                arg0->unknown_43_[var9] = var8[var9].unknown_1_;
            }
            GameState_SetProtagonistIndex(battle, LinkSession_GetOwnSlot(search));
            int flag = 1;
            if (obj->command != 0 && *obj->command == 10) flag = 0;
            Party_ReformLine(resources, 1, flag, 1, 1);
        }
        func_ov017_021b0a7c(arg0);
        func_ov017_021d0b30(2, 0, 0);
        if (obj->mode != 2) return 0xb;
        FillBitArray0x1524WithFF((BitArrayObj0205e854*)LinkMessageQueue_GetInstance());
        return 6;
    }
    return arg0->unknown_a_;
}
