#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct SearchStruct0202c1a4;
struct BitArrayObj0205e854;

struct Struct_ov017_021b0288 {
    unsigned char combatant;
    unsigned char slot;
};

struct Struct_ov017_021b0288_2 {
    char unk0[0x4];
    signed char* command;
    char unknown_8_[0x1];
    unsigned char mode;
    unsigned char result;
    char unknown_b_[0x10];
    unsigned char slots[4];
    char unknown_1f_[0x24];
    unsigned char order[4];
    unsigned char unknown_47_;
};

extern "C" SearchStruct0202c1a4* LinkSession_GetInstance(void);
extern "C" unsigned char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" void func_020546a0(void* obj, int value);
extern "C" void func_ov017_021c32b0(Struct_ov017_021b0288* pairs, int count);
extern "C" void GameState_SetProtagonistIndex(GameState* gs, int value);
extern "C" void Party_ReformLine(void* unused, int c, int d, int e, int flag);
extern "C" void func_ov017_021b0a7c(Struct_ov017_021b0288_2* obj);
extern "C" void func_ov017_021d0b30(int a, int b, int c);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* func_0205e854(struct BitArrayObj0205e854* obj);

// USA: func_ov017_021b0288
extern "C" ARM int func_ov017_021b0288(Struct_ov017_021b0288_2* obj) {
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
            Struct_ov017_021b0288 pairs[4];
            battle = GameState::GetInstance();
            search = LinkSession_GetInstance();
            resources = GetGameResources();
            count = 0;
            pairs[count].combatant = 0;
            pairs[count].slot = LinkSession_GetOwnSlot(search);
            count++;
            memcpy(slots, obj->slots, 4);
            for (i = 3; i >= 1; i--) {
                combatant = func_0200ff58(battle, i);
                if (combatant == 0) continue;
                for (j = 3; j >= 1; j--) {
                    if (slots[j] == 3) {
                        pairs[count].combatant = i;
                        pairs[count].slot = j;
                        func_020546a0(combatant, LinkSession_GetOwnSlot(search));
                        slots[j] = 0;
                        count++;
                        break;
                    }
                }
            }
            func_ov017_021c32b0(pairs, count);
            obj->unknown_47_ = count;
            for (int k = 0; k < count; k++) {
                obj->order[k] = pairs[k].slot;
            }
            GameState_SetProtagonistIndex(battle, LinkSession_GetOwnSlot(search));
            int flag = 1;
            if (obj->command != 0 && *obj->command == 10) flag = 0;
            Party_ReformLine(resources, 1, flag, 1, 1);
        }
        func_ov017_021b0a7c(obj);
        func_ov017_021d0b30(2, 0, 0);
        if (obj->mode != 2) return 0xb;
        func_0205e854((BitArrayObj0205e854*)LinkMessageQueue_GetInstance());
        return 6;
    }
    return obj->result;
}
