#include <globaldefs.h>
#include "GameState/GameState.h"

struct Random;

struct Struct_ov000_02157e1c {
    char unk0[0x18];
    unsigned int unknown_18_;
    char unknown_1c_[0x3b - 0x1c];
    unsigned char unknown_3b_0_ : 3;
    unsigned char unknown_3b_3_ : 1;
    unsigned char countdown : 4;
    char unk3c[0x68 - 0x3c];
    unsigned char unknown_68_;
    unsigned char unknown_69_;
    char unknown_6a_[0x7a - 0x6a];
    unsigned char unknown_7a_;
    char unknown_7b_;
    unsigned char unknown_7c_;
    char unknown_7d_[0x8b - 0x7d];
    unsigned char unknown_8b_;
    unsigned char unknown_8c_;
    char unknown_8d_[0x9d - 0x8d];
    unsigned char unknown_9d_;
    char unknown_9e_;
    unsigned char unknown_9f_;
};

struct Struct_ov000_02182cb4 {
    short v[16];
};

#define TIMERS(combatant) ((struct Struct_ov000_02157e1c*)(combatant)->currentStats_)

extern Struct_ov000_02182cb4 data_ov000_02182cb4;
extern Struct_ov000_02182cb4 data_ov000_02182cd4;
extern float data_ov000_02182ad4[];
extern float data_ov000_02182bd4[];

extern "C" int func_ov000_02153e40(struct Random* arg0, short* buf, int max, int start);
extern "C" void func_ov000_0215cac8(struct Random* arg0, short* ids, int count, short action,
                                    unsigned short* values, unsigned char* arg5);
extern "C" void __clear(void* dst, unsigned int size);
int NextRandomMax(struct Random* random, int max);
extern "C" void func_02088dc8(unsigned char* stats);
extern "C" int func_ov000_0215830c(GameObject* combatant);
extern "C" void func_02088b84(unsigned char* stats);
extern "C" int func_ov000_02158324(GameObject* combatant);
extern "C" void func_02088bd4(unsigned char* stats);
extern "C" int func_ov000_02156af0(GameObject* combatant);
extern "C" void func_02089194(unsigned char* stats);
extern "C" int func_ov000_02156b08(GameObject* combatant);
extern "C" void func_020890a4(unsigned char* stats);
extern "C" int func_ov000_0215fd24(int unused, int id);

static inline short inline_ov000_0215440c(short* list, int index) { return list[index]; }

// USA: func_ov000_02157e1c
extern "C" ARM void func_ov000_02157e1c(struct Random* arg0) {
    Struct_ov000_02182cb4 var0 = data_ov000_02182cb4;
    short* var1 = var0.v;
    short var2 = 0;
    Struct_ov000_02182cb4 ids = data_ov000_02182cd4;
    short* var4 = ids.v;
    int count = func_ov000_02153e40(arg0, var4, 16, 1);
    struct Struct_ov000_02157e1c* var6;
    unsigned short messages[40];
    unsigned char var8[8];
    unsigned char var9;
    int i;
    __clear(messages, sizeof(messages));
    var9 = 0;
    unsigned short* var11 = messages;
    __clear(var8, sizeof(var8));
    unsigned char* var12 = var8;
    GameObject* combatant;
    float roll = (float)NextRandomMax(arg0, 100) / 100.0f;

    for (i = 0; i < count; i++) {
        short id = inline_ov000_0215440c(var4, i);
        combatant = GameState::GetInstance()->GetCombatantByIndex(id);
        if (combatant == 0) {
            continue;
        }
        var12[var2] = 0;
        unsigned char var16 = 0;
        if (TIMERS(combatant)->unknown_18_ & 0x20) {
            func_02088dc8((unsigned char*)combatant->currentStats_);
        }
        var6 = TIMERS(combatant);

        if (func_ov000_0215830c(combatant)) {
            float r = (float)NextRandomMax(arg0, 100) / 100.0f;
            if (var6->unknown_8b_ != 0) {
                var6->unknown_8b_--;
                if (data_ov000_02182ad4[var6->unknown_8b_] > r) {
                    var6->unknown_8b_ = 0;
                    func_02088b84((unsigned char*)combatant->currentStats_);
                    var11[var9] = 0x1c8;
                    var9++;
                    var12[var2]++;
                    var16 = 1;
                }
            } else if (var6->unknown_68_ != 0) {
                var6->unknown_68_--;
                if (var6->unknown_68_ == 0) {
                    var6->unknown_68_ = 0;
                    var6->unknown_8b_ = 4;
                }
            }
        }

        if (func_ov000_02158324(combatant)) {
            float r = (float)NextRandomMax(arg0, 100) / 100.0f;
            if (var6->unknown_8c_ != 0) {
                var6->unknown_8c_--;
                if (data_ov000_02182ad4[var6->unknown_8c_] > r) {
                    var6->unknown_8c_ = 0;
                    func_02088bd4((unsigned char*)combatant->currentStats_);
                    var11[var9] = 0x24c;
                    var9++;
                    var12[var2]++;
                    var16 = 1;
                }
            } else if (var6->unknown_69_ != 0) {
                var6->unknown_69_--;
                if (var6->unknown_69_ == 0) {
                    var6->unknown_69_ = 0;
                    var6->unknown_8c_ = 4;
                }
            }
        }

        if (func_ov000_02156af0(combatant)) {
            float r = (float)NextRandomMax(arg0, 100) / 100.0f;
            if (var6->unknown_9f_ != 0) {
                var6->unknown_9f_--;
                if (data_ov000_02182ad4[var6->unknown_9f_] > r) {
                    var6->unknown_9f_ = 0;
                    func_02089194((unsigned char*)combatant->currentStats_);
                    var11[var9] = 0x249;
                    var9++;
                    var12[var2]++;
                    var16 = 1;
                }
            } else if (var6->unknown_7c_ != 0) {
                var6->unknown_7c_--;
                if (var6->unknown_7c_ == 0) {
                    var6->unknown_7c_ = 0;
                    var6->unknown_9f_ = 1;
                }
            }
        }

        if (func_ov000_02156b08(combatant)) {
            if (var6->unknown_9d_ != 0) {
                var6->unknown_9d_--;
                if (data_ov000_02182bd4[var6->unknown_9d_] > roll) {
                    var6->unknown_9d_ = 0;
                    func_020890a4((unsigned char*)combatant->currentStats_);
                    var11[var9] = 0x1c6;
                    var9++;
                    var12[var2]++;
                    var16 = 1;
                }
            } else if (var6->unknown_7a_ != 0) {
                var6->unknown_7a_--;
                if (var6->unknown_7a_ == 0) {
                    var6->unknown_7a_ = 0;
                    var6->unknown_9d_ = 1;
                }
            }
        }

        if (TIMERS(combatant)->unknown_3b_3_) {
            TIMERS(combatant)->countdown--;
            int remaining = TIMERS(combatant)->countdown;
            if (remaining <= 0) {
                TIMERS(combatant)->unknown_3b_3_ = 0;
                if (func_ov000_0215fd24((int)arg0, var4[i])) {
                    var11[var9] = 0x25b;
                    var9++;
                    var12[var2]++;
                    var16 = 1;
                }
            }
        }

        if (var16 != 0) {
            var1[var2] = var4[i];
            var2++;
        }
    }

    if (var2 > 0) {
        func_ov000_0215cac8(arg0, var1, var2, 0x3a8, messages, var8);
    }
}
