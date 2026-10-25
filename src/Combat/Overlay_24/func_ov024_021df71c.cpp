#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_02053f7c;
struct Struct_ov000_021626a0_2 { char unknown_0_[8]; short unknown_8_; };
struct Struct_ov000_0215ab88 : GameObject { char unknown_13c_[8]; Struct_ov000_021626a0_2* unknown_144_; };
struct Struct_ov024_021df71c { char unknown_0_[0x22]; unsigned short unknown_22_0_ : 2; unsigned short unknown_22_2_ : 4; unsigned short unknown_22_6_ : 10; };
struct Struct_ov024_021df71c_2 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 5;
    unsigned int unknown_1_6_ : 1;
    unsigned int unknown_1_7_ : 1;
    unsigned int unknown_2_0_ : 16;
    int unknown_4_[3];
};
struct Struct_ov024_021df71c_3 { unsigned char unknown_0_; char unknown_1_[3]; Struct_ov024_021df71c_2 unknown_4_[1]; };
struct Struct_ov024_021fe9b8 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
};
extern ActionRule data_ov024_021fe9b8[];
int* GetGlobal02109418_02094d6c();
int Party_CountItem(Obj02086aec*, int);
int CheckFlag0x14Bit0x10Set_020882f8(unsigned char*);

// USA: func_ov024_021df71c
extern "C" ARM int func_ov024_021df71c(Combatant* self, unsigned int actionID, int alternate, unsigned short* resultID, unsigned short* combatantKey, unsigned short* entryID) {
    GlobalEntries* global = (GlobalEntries*)GetGlobal02109418_02094d6c();
    if (!global->count_) return 0;
    Obj02086aec* battle = (Obj02086aec*)GameState_GetParty(GameState::GetInstance());
    int key = 0;
    if (self->info_) key = self->info_->key_;
    for (int i = 0; i < global->count_; ++i) {
        GlobalEntry* entries = global->entries_;
        if (entries[i].removed_) continue;
        if (entries[i].disabled_) continue;
        for (int j = 0; j < 7; ++j) {
            ActionRule* rule = &data_ov024_021fe9b8[j];
            if (rule->entryID_ != entries[i].id_ || key != rule->combatantKey_) continue;
            if (alternate != 0 && rule->alternate_ == 0) continue;
            if (alternate == 0 && rule->alternate_ != 0) continue;
            if (Party_CountItem(battle, (short)rule->resultID_) > 0) continue;
            if (rule->condition_ != 0) {
                if (rule->condition_ == 1) {
                    if (!CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)self->currentStats_)) continue;
                } else if (rule->condition_ == 2) {
                    if (self->currentStats_->primaryStats.currHP > 700) continue;
                } else if (rule->condition_ == 3) {
                    if (((ConditionStats*)self->currentStats_)->condition_ != 3) continue;
                }
            }
            unsigned int var7 = var6->unknown_6_;
            if (var7) {
                if (var7 >= 40000) {
                    var7 = 40000;
                    if (arg1 < var7) continue;
                } else if ((int)var7 / 100 != (int)arg1 / 100) continue;
            }
            if (var6->unknown_8_ != 0 && var6->unknown_8_ != arg1) continue;
            *arg3 = var6->unknown_a_;
            *arg4 = var6->unknown_2_;
            *arg5 = var6->unknown_0_;
            return 1;
        }
    }
    return 0;
}
