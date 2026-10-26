#include <globaldefs.h>
#include <GameState/GameState.h>

struct Obj02086aec;
struct Struct_ov000_021626a0_2 { char pad0[8]; short key_; };
struct Struct_ov000_0215ab88 : GameObject { char unknown_13c_[8]; Struct_ov000_021626a0_2* info_; };
struct Struct_ov024_021df71c { char pad0[0x22]; unsigned short unused : 2; unsigned short unknown_22_2_ : 4; unsigned short rest : 10; };
struct Struct_ov024_021df71c_2 {
    unsigned int id_ : 9;
    unsigned int unknown_1_1_ : 5;
    unsigned int disabled_ : 1;
    unsigned int unknown_1_7_ : 1;
    unsigned int rest : 16;
    int unknown_4_[3];
};
struct Struct_ov024_021df71c_3 { unsigned char count_; char pad1[3]; Struct_ov024_021df71c_2 entries_[1]; };
struct Struct_ov024_021fe9b8 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short category_;
    unsigned short unknown_8_;
    unsigned short resultID_;
    unsigned char unknown_c_;
    unsigned char padD;
};
extern Struct_ov024_021fe9b8 data_ov024_021fe9b8[];
extern "C" int* func_02094d6c();
extern "C" int Party_CountItem(Obj02086aec*, int);
extern "C" int func_020882f8(unsigned char*);

// USA: func_ov024_021df71c
extern "C" ARM int func_ov024_021df71c(Struct_ov000_0215ab88* self, unsigned int arg1, int alternate, unsigned short* arg3, unsigned short* arg4, unsigned short* arg5) {
    Struct_ov024_021df71c_3* global = (Struct_ov024_021df71c_3*)func_02094d6c();
    if (!global->count_) return 0;
    Obj02086aec* battle = (Obj02086aec*)GameState_GetParty(GameState::GetInstance());
    int key = 0;
    if (self->info_) key = self->info_->key_;
    for (int i = 0; i < global->count_; ++i) {
        Struct_ov024_021df71c_2* entries = global->entries_;
        if (entries[i].unknown_1_7_) continue;
        if (entries[i].disabled_) continue;
        for (int j = 0; j < 7; ++j) {
            Struct_ov024_021fe9b8* rule = &data_ov024_021fe9b8[j];
            if (rule->unknown_0_ != entries[i].id_ || key != rule->unknown_2_) continue;
            if (alternate != 0 && rule->unknown_c_ == 0) continue;
            if (alternate == 0 && rule->unknown_c_ != 0) continue;
            if (Party_CountItem(battle, (short)rule->resultID_) > 0) continue;
            if (rule->unknown_4_ != 0) {
                if (rule->unknown_4_ == 1) {
                    if (!func_020882f8((unsigned char*)self->currentStats_)) continue;
                } else if (rule->unknown_4_ == 2) {
                    if (self->currentStats_->primaryStats.currHP > 700) continue;
                } else if (rule->unknown_4_ == 3) {
                    if (((Struct_ov024_021df71c*)self->currentStats_)->unknown_22_2_ != 3) continue;
                }
            }
            unsigned int category = rule->category_;
            if (category) {
                if (category >= 40000) {
                    category = 40000;
                    if (arg1 < category) continue;
                } else if ((int)category / 100 != (int)arg1 / 100) continue;
            }
            if (rule->unknown_8_ != 0 && rule->unknown_8_ != arg1) continue;
            *arg3 = rule->resultID_;
            *arg4 = rule->unknown_2_;
            *arg5 = rule->unknown_0_;
            return 1;
        }
    }
    return 0;
}
