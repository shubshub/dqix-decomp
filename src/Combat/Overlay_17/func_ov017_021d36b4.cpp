#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_0202c1a4;

struct Struct_ov017_021d36b4 {
    char unknown_0_[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned short unknown_6_;
    Vector3s unknown_8_;
};

struct Struct_ov017_021d36b4_2 {
    unsigned short unknown_0_;
    Vector3s unknown_2_;
};

void* GameState_GetPlayerLocation(char* base, unsigned int index);
extern "C" int LinkSession_IsHostOrSolo(struct SearchStruct0202c1a4* search);
extern "C" void func_ov017_021d360c(int a, unsigned char b, int c, Vector3s d);
GameObject* FindCombatantByField0x16a_0200ffe0(GameState* battleStruct, int id);
void SetField0xc4Low15Bits_02034044(unsigned char* obj, int val);
void GameObject_EnableControl(void* obj);
unsigned char GameObject_IsClimbingLadder(char* obj);
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

// USA: func_ov017_021d36b4
extern "C" ARM void func_ov017_021d36b4(int remote, struct Evt021d36b4* evt, GameState* bs, int unused,
                                        struct SearchStruct0202c1a4* search) {
    struct Slot021d36b4* slot = (struct Slot021d36b4*)GameState_GetPlayerLocation((char*)bs, evt->slotIndex);
    if (slot == 0) return;

    if (evt->mode == 0) {
        if (LinkSession_IsHostOrSolo(search)) {
            slot->id = evt->id;
            Vector3fix16Copy(&slot->pos, &evt->pos);
            func_ov017_021d360c(evt->mode, evt->slotIndex, evt->id, evt->pos);
        } else if (remote == 0) {
            slot->id = evt->id;
            Vector3fix16Copy(&slot->pos, &evt->pos);
        }
    } else if (evt->mode == 1) {
        int isParty = evt->id <= 3;
        if (!isParty) {
            GameObject* combatant = FindCombatantByField0x16a_0200ffe0(bs, evt->id - 4);
            if (combatant == 0) return;
            evt->id = combatant->obj3D_.actorIndex_;
        }
        GameObject* monster = bs->GetWanderingMonsterByIndex(evt->id);
        GameObject* member = bs->GetPartyMemberByIndex(evt->id);
        if (monster == 0) return;

        if (LinkSession_IsHostOrSolo(search)) {
            if (slot->id == 0) return;
            int inParty = 0;
            if (monster->obj3D_.actorIndex_ >= 0 && monster->obj3D_.actorIndex_ <= 3) inParty = 1;
            if (!inParty) {
                SetField0xc4Low15Bits_02034044((unsigned char*)monster, 5000);
                if (member != 0) GameObject_EnableControl(member);
            }
            slot->id = 0;
            func_ov017_021d360c(evt->mode, evt->slotIndex, evt->id, evt->pos);
        } else if (remote == 0) {
            short index;
            int inParty = 0;
            index = monster->obj3D_.actorIndex_;
            if (index >= 0 && index <= 3) inParty = 1;
            if (inParty) {
                if (index == LinkSession_GetOwnSlot(search) && member != 0 && GameObject_IsClimbingLadder((char*)member) == 0) {
                    SetField0xc4Low15Bits_02034044((unsigned char*)monster, 5000);
                    if (member != 0) GameObject_EnableControl(member);
                }
            } else {
                SetField0xc4Low15Bits_02034044((unsigned char*)monster, 5000);
                if (member != 0) GameObject_EnableControl(member);
            }
            var0->unknown_0_ = 0;
        }
    }
}
