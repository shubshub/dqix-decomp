#include <globaldefs.h>
#include "GameState/GameState.h"

struct Random;
struct S_10088;
struct Struct_02088660;
struct Struct_02088674;

struct Struct_ov000_0215858c {
    char unk0[0x22];
    unsigned short unknown_22_0_ : 9;
    unsigned short unknown_23_1_ : 3;
    unsigned short unknown_23_4_ : 4;
    char unknown_24_[0xa];
    short unknown_2e_;
    char unk30[0xb];
    unsigned char unknown_3b_0_ : 1;
    unsigned char unknown_3b_1_ : 1;
    unsigned char unknown_3b_2_ : 6;
    unsigned char unknown_3c_;
    char unknown_3d_[0x41];
    unsigned char unknown_7e_;
    char unknown_7f_[3];
    unsigned char unknown_82_;
    unsigned char unknown_83_;
    unsigned char unknown_84_;
    unsigned char unknown_85_;
    unsigned char unknown_86_;
    unsigned char unknown_87_;
    char unknown_88_;
    unsigned char unknown_89_;
    unsigned char unknown_8a_;
    char unknown_8b_[2];
    unsigned char unknown_8d_;
    unsigned char unknown_8e_;
    unsigned char unknown_8f_;
    unsigned char unknown_90_;
    unsigned char unknown_91_;
    unsigned char unknown_92_;
    unsigned char unknown_93_;
    unsigned char unknown_94_;
    unsigned char unknown_95_;
    unsigned char unknown_96_;
    unsigned char unknown_97_;
    unsigned char unknown_98_;
    unsigned char unknown_99_;
    unsigned char unknown_9a_;
    unsigned char unknown_9b_;
    unsigned char unknown_9c_;
    char unknown_9d_;
    unsigned char unknown_9e_;
    char unknown_9f_;
    unsigned char unknown_a0_;
    unsigned char unknown_a1_;
};

#define AILMENTS(combatant) ((struct Struct_ov000_0215858c*)(combatant)->currentStats_)

int NextRandomMax(struct Random* random, int max);

extern "C" void* func_ov000_0215e958(struct Random* arg0);
extern "C" void func_ov000_021584e8(struct Random* arg0, void* entry, GameObject* combatant, int arg3, int kind, int param);

extern "C" void func_020884f8(unsigned char* stats);
extern "C" int func_ov000_02155154(GameObject* combatant);
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);
extern "C" void func_02088e64(unsigned char* stats);
extern "C" void func_020488cc(unsigned char* combatant, int value);
extern "C" int func_02088660(struct Struct_02088660* stats);
extern "C" void func_02088674(struct Struct_02088674* stats);
void UpdateCombatantAttack(int random, int combatantId);
void UpdateCombatantDefense(int random, int combatantId);
void UpdateCombatantAgility(int random, int combatantId);
void UpdateCombatantCharm(int random, int combatantId);
void UpdateCombatantMagicalMight(int random, int combatantId);
void UpdateCombatantMagicalMending(int random, int combatantId);
extern "C" int func_ov000_02156b20(GameObject* combatant);
extern "C" void func_02088874(unsigned char* stats);
extern "C" int func_ov000_0215985c(GameObject* combatant);
extern "C" void func_020888c4(unsigned char* stats);
extern "C" int func_ov000_02159874(GameObject* combatant);
extern "C" void func_02088914(unsigned char* stats);
extern "C" int func_ov000_0215516c(GameObject* combatant);
extern "C" void func_020889b4(void* stats);
extern "C" int func_ov000_0215988c(GameObject* combatant);
extern "C" void func_02088a04(void* stats);
extern "C" int func_ov000_021598a4(GameObject* combatant);
extern "C" void func_02088a54(unsigned char* stats);
extern "C" int func_ov000_021598bc(GameObject* combatant);
extern "C" void func_02088964(unsigned char* stats);
extern "C" int func_ov000_021598d4(GameObject* combatant);
extern "C" void func_02088b34(unsigned char* stats);
extern "C" int func_ov000_02156c94(GameObject* combatant);
extern "C" void func_02088cf4(unsigned char* stats);
extern "C" int func_ov000_02156cac(GameObject* combatant);
extern "C" void func_02088d4c(unsigned char* stats);
extern "C" int func_ov000_021598ec(GameObject* combatant);
extern "C" void func_02088c38(unsigned char* stats);
extern "C" int func_ov000_02159904(GameObject* combatant);
extern "C" void func_02088c9c(unsigned char* stats);
extern "C" int func_ov000_0215991c(GameObject* combatant);
extern "C" void func_02087838(void* stats);
extern "C" int func_ov000_02159934(GameObject* combatant);
extern "C" void func_0208792c(void* stats);
extern "C" int func_ov000_0215994c(GameObject* combatant);
extern "C" void func_02087a20(void* stats);
extern "C" int func_ov000_02159964(GameObject* combatant);
extern "C" void func_02087b14(void* stats);
extern "C" int func_ov000_0215997c(GameObject* combatant);
extern "C" void func_02087c08(void* stats);
extern "C" int func_ov000_02159994(GameObject* combatant);
extern "C" void func_02087cfc(void* stats);
extern "C" int func_ov000_021599ac(GameObject* combatant);
extern "C" void func_02087df0(void* stats);
extern "C" int func_ov000_021599c4(GameObject* combatant);
extern "C" void func_02087efc(unsigned char* stats);
extern "C" int func_ov000_02156258(GameObject* combatant);
extern "C" void func_020880e4(void* stats);
extern "C" int func_ov000_021563ec(GameObject* combatant);
extern "C" void func_02087ff0(void* stats);
extern "C" int func_ov000_02153a8c(GameObject* combatant);
extern "C" void func_020890f4(unsigned char* stats);
extern "C" int func_ov000_02156404(GameObject* combatant);
extern "C" void func_02089144(unsigned char* stats);
extern "C" int func_ov000_021599dc(GameObject* combatant);
extern "C" void func_02088d9c(unsigned char* stats);

extern float data_ov000_02182ad4[];
extern float data_ov000_02182bd4[];

// USA: func_ov000_0215858c
extern "C" ARM void func_ov000_0215858c(struct Random* arg0, int combatantId, int arg2) {
    struct Struct_ov000_0215858c* var0;
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(combatantId);
    if (combatant == 0) {
        return;
    }

    float roll = (float)NextRandomMax(arg0, 100) / 100.0f;
    var0 = AILMENTS(combatant);

    if (var0->unknown_3b_1_ != 0) {
        func_020884f8((unsigned char*)combatant->currentStats_);
        AILMENTS(combatant)->unknown_3c_ |= 0x40;
    }
    if (func_ov000_02155154(combatant) != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        if (var0->unknown_7e_ != 0) {
            var0->unknown_7e_ = var0->unknown_7e_ - 1;
            if (var0->unknown_7e_ == 0) {
                var0->unknown_7e_ = 0;
                var0->unknown_a1_ = 1;
            }
        }

        int var4 = 0;
        short var5 = AILMENTS(combatant)->unknown_2e_;
        GameState* state = GameState::GetInstance();
        GameObject* caster = state->GetCombatantByIndex(var5);
        if (caster == 0) {
            var4 = 1;
        }
        if (caster != 0 && func_02010088((struct S_10088*)caster) != 0) {
            var4 = 1;
        }
        if (caster != 0 && func_ov000_02153c0c(caster) != 0) {
            var4 = 1;
        }
        if (var4 != 0) {
            var0->unknown_a1_ = 0;
            func_02088e64((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x164, 0);
        } else if (var0->unknown_a1_ != 0) {
            int remaining = var0->unknown_a1_ - 1;
            float var9 = data_ov000_02182ad4[remaining & 0xff];
            float limit = roll;
            var0->unknown_a1_ = remaining;
            if (var9 > limit) {
                var0->unknown_a1_ = 0;
                func_02088e64((unsigned char*)combatant->currentStats_);
                int var11 = (combatantId >= 0 && combatantId <= 3);
                if (var11 == 0) {
                    func_020488cc((unsigned char*)combatant, 1);
                }
                func_ov000_021584e8(arg0, entry, combatant, arg2, 0x164, 0);
            }
        }
    }

    if (func_ov000_02156b20(combatant) != 0 && var0->unknown_82_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_82_ = var0->unknown_82_ - 1;
        if (data_ov000_02182bd4[var0->unknown_82_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_82_ = 0;
            func_02088874((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1c7, 0);
        }
    }

    if (func_ov000_0215985c(combatant) != 0 && var0->unknown_83_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_83_ = var0->unknown_83_ - 1;
        if (data_ov000_02182ad4[var0->unknown_83_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_83_ = 0;
            func_020888c4((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d6, 0x2d);
        }
    }

    if (func_ov000_02159874(combatant) != 0 && var0->unknown_84_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_84_ = var0->unknown_84_ - 1;
        if (data_ov000_02182ad4[var0->unknown_84_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_84_ = 0;
            func_02088914((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1c3, 0);
        }
    }

    if (func_ov000_0215516c(combatant) != 0 && var0->unknown_85_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_85_ = var0->unknown_85_ - 1;
        if (data_ov000_02182bd4[var0->unknown_85_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_85_ = 0;
            func_020889b4(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1c9, 0x28);
        }
    }

    if (func_ov000_0215988c(combatant) != 0 && var0->unknown_86_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_86_ = var0->unknown_86_ - 1;
        if (data_ov000_02182bd4[var0->unknown_86_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_86_ = 0;
            func_02088a04(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d7, 0);
        }
    }

    if (func_ov000_021598a4(combatant) != 0 && var0->unknown_87_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_87_ = var0->unknown_87_ - 1;
        if (data_ov000_02182bd4[var0->unknown_87_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_87_ = 0;
            func_02088a54((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d8, 0);
        }
    }

    if (func_ov000_021598bc(combatant) != 0 && var0->unknown_89_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_89_ = var0->unknown_89_ - 1;
        if (data_ov000_02182ad4[var0->unknown_89_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_89_ = 0;
            func_02088964((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1c4, 0);
        }
    }

    if (func_ov000_021598d4(combatant) != 0 && var0->unknown_8a_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_8a_ = var0->unknown_8a_ - 1;
        if (data_ov000_02182ad4[var0->unknown_8a_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_8a_ = 0;
            func_02088b34((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1cb, 0);
        }
    }

    if (func_02088660((struct Struct_02088660*)combatant->currentStats_) != 0 && var0->unknown_8d_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_8d_ = var0->unknown_8d_ - 1;
        if (data_ov000_02182bd4[var0->unknown_8d_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_8d_ = 0;
            unsigned int var21 = AILMENTS(combatant)->unknown_23_1_;
            func_02088674((struct Struct_02088674*)combatant->currentStats_);
            switch (var21) {
            case 1:
                func_ov000_021584e8(arg0, entry, combatant, arg2, 0x219, 0);
                break;
            case 2:
                func_ov000_021584e8(arg0, entry, combatant, arg2, 0x21a, 0);
                break;
            case 3:
                func_ov000_021584e8(arg0, entry, combatant, arg2, 0x21b, 0);
                break;
            case 4:
                func_ov000_021584e8(arg0, entry, combatant, arg2, 0x21c, 0);
                break;
            case 5:
                func_ov000_021584e8(arg0, entry, combatant, arg2, 0x21d, 0);
                break;
            }
        }
    }

    if (func_ov000_02156c94(combatant) != 0 && var0->unknown_8e_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_8e_ = var0->unknown_8e_ - 1;
        if (data_ov000_02182ad4[var0->unknown_8e_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_8e_ = 0;
            func_02088cf4((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x25d, 0);
        }
    }

    if (func_ov000_02156cac(combatant) != 0 && var0->unknown_9e_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_9e_ = var0->unknown_9e_ - 1;
        if (data_ov000_02182ad4[var0->unknown_9e_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_9e_ = 0;
            func_02088d4c((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x25e, 0);
        }
    }

    if (func_ov000_021598ec(combatant) != 0 && var0->unknown_8f_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_8f_ = var0->unknown_8f_ - 1;
        if (data_ov000_02182ad4[var0->unknown_8f_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_8f_ = 0;
            func_02088c38((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1cc, 0);
        }
    }

    if (func_ov000_02159904(combatant) != 0 && var0->unknown_90_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_90_ = var0->unknown_90_ - 1;
        if (data_ov000_02182ad4[var0->unknown_90_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_90_ = 0;
            func_02088c9c((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1cd, 0);
        }
    }

    if (func_ov000_0215991c(combatant) != 0 && var0->unknown_91_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_91_ = var0->unknown_91_ - 1;
        if (data_ov000_02182ad4[var0->unknown_91_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_91_ = 0;
            func_02087838(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1ce, 0);
            UpdateCombatantAttack((int)arg0, combatantId);
        }
    }

    if (func_ov000_02159934(combatant) != 0 && var0->unknown_92_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_92_ = var0->unknown_92_ - 1;
        if (data_ov000_02182ad4[var0->unknown_92_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_92_ = 0;
            func_0208792c(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1cf, 0);
            UpdateCombatantDefense((int)arg0, combatantId);
        }
    }

    if (func_ov000_0215994c(combatant) != 0 && var0->unknown_93_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_93_ = var0->unknown_93_ - 1;
        if (data_ov000_02182ad4[var0->unknown_93_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_93_ = 0;
            func_02087a20(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1db, 0);
            UpdateCombatantAgility((int)arg0, combatantId);
        }
    }

    if (func_ov000_02159964(combatant) != 0 && var0->unknown_94_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_94_ = var0->unknown_94_ - 1;
        if (data_ov000_02182ad4[var0->unknown_94_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_94_ = 0;
            func_02087b14(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d0, 0);
            UpdateCombatantCharm((int)arg0, combatantId);
        }
    }

    if (func_ov000_0215997c(combatant) != 0 && var0->unknown_95_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_95_ = var0->unknown_95_ - 1;
        if (data_ov000_02182ad4[var0->unknown_95_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_95_ = 0;
            func_02087c08(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d1, 0);
            UpdateCombatantMagicalMight((int)arg0, combatantId);
        }
    }

    if (func_ov000_02159994(combatant) != 0 && var0->unknown_96_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_96_ = var0->unknown_96_ - 1;
        if (data_ov000_02182ad4[var0->unknown_96_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_96_ = 0;
            func_02087cfc(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d2, 0);
            UpdateCombatantMagicalMending((int)arg0, combatantId);
        }
    }

    if (func_ov000_021599ac(combatant) != 0 && var0->unknown_97_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_97_ = var0->unknown_97_ - 1;
        if (data_ov000_02182bd4[var0->unknown_97_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_97_ = 0;
            func_02087df0(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d3, 0);
        }
    }

    if (func_ov000_021599c4(combatant) != 0 && var0->unknown_98_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_98_ = var0->unknown_98_ - 1;
        if (data_ov000_02182ad4[var0->unknown_98_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_98_ = 0;
            func_02087efc((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d4, 0);
        }
    }

    if (func_ov000_02156258(combatant) != 0 && var0->unknown_99_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_99_ = var0->unknown_99_ - 1;
        if (data_ov000_02182bd4[var0->unknown_99_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_99_ = 0;
            func_020880e4(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d5, 0);
        }
    }

    if (func_ov000_021563ec(combatant) != 0 && var0->unknown_9a_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_9a_ = var0->unknown_9a_ - 1;
        if (data_ov000_02182bd4[var0->unknown_9a_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_9a_ = 0;
            func_02087ff0(combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1d9, 0);
        }
    }

    if (func_ov000_02153a8c(combatant) != 0 && var0->unknown_9b_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_9b_ = var0->unknown_9b_ - 1;
        if (data_ov000_02182bd4[var0->unknown_9b_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_9b_ = 0;
            func_020890f4((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1c5, 0);
        }
    }

    if (func_ov000_02156404(combatant) != 0 && var0->unknown_9c_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_9c_ = var0->unknown_9c_ - 1;
        if (data_ov000_02182bd4[var0->unknown_9c_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_9c_ = 0;
            func_02089144((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x1da, 0);
        }
    }

    if (func_ov000_021599dc(combatant) != 0 && var0->unknown_a0_ != 0) {
        void* entry = func_ov000_0215e958(arg0);
        if (entry == 0) {
            return;
        }
        var0->unknown_a0_ = var0->unknown_a0_ - 1;
        if (data_ov000_02182ad4[var0->unknown_a0_] > (float)NextRandomMax(arg0, 100) / 100.0f) {
            var0->unknown_a0_ = 0;
            func_02088d9c((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(arg0, entry, combatant, arg2, 0x24b, 0);
        }
    }
}
