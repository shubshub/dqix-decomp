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

void* GetField0x74deForValidIndex_020120a0(char* base, unsigned int index);
extern "C" int func_0202c508(struct SearchStruct0202c1a4* search);
extern "C" void func_ov017_021d360c(int a, unsigned char b, int c, Vector3s d);
GameObject* FindCombatantByField0x16a_0200ffe0(GameState* battleStruct, int id);
void SetField0xc4Low15Bits_02034044(unsigned char* obj, int val);
void GameObject_EnableControl(void* obj);
unsigned char GetByte0x26c_02039d7c(char* obj);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

// USA: func_ov017_021d36b4
extern "C" ARM void func_ov017_021d36b4(int arg0, struct Struct_ov017_021d36b4* arg1, GameState* arg2, int arg3,
                                        struct Struct_0202c1a4* arg4) {
    struct Struct_ov017_021d36b4_2* var0 = (struct Struct_ov017_021d36b4_2*)func_020120a0((char*)arg2, arg1->unknown_5_);
    if (var0 == 0) return;

    if (arg1->unknown_4_ == 0) {
        if (func_0202c508(arg4)) {
            var0->unknown_0_ = arg1->unknown_6_;
            Vector3fix16Copy(&var0->unknown_2_, &arg1->unknown_8_);
            func_ov017_021d360c(arg1->unknown_4_, arg1->unknown_5_, arg1->unknown_6_, arg1->unknown_8_);
        } else if (arg0 == 0) {
            var0->unknown_0_ = arg1->unknown_6_;
            Vector3fix16Copy(&var0->unknown_2_, &arg1->unknown_8_);
        }
    } else if (evt->mode == 1) {
        int isParty = evt->id <= 3;
        if (!isParty) {
            GameObject* combatant = FindCombatantByField0x16a_0200ffe0(bs, evt->id - 4);
            if (combatant == 0) return;
            evt->id = combatant->obj3D_.actorIndex_;
        }
        GameObject* var3 = arg2->GetMaybeWanderingMonsterByIndex(arg1->unknown_6_);
        GameObject* var4 = arg2->GetPartyMemberByIndex(arg1->unknown_6_);
        if (var3 == 0) return;

        if (func_0202c508(search)) {
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
                if (index == GetSearchStructCurrentArrEntry(search) && member != 0 && GetByte0x26c_02039d7c((char*)member) == 0) {
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
