#include <globaldefs.h>
#include "GameState/GameState.h"

struct Random;

struct Struct_ov000_0215833c {
    char unk0[0x3c];
    unsigned char unknown_3c_0_ : 6;
    unsigned char unknown_3c_6_ : 1;
    unsigned char unknown_3c_7_ : 1;
    char unknown_3d_[0x7f - 0x3d];
    unsigned char turns[3];
};

struct Struct_ov000_0215767c_10 {
    unsigned short action;
    char unk2[7];
    unsigned char unknown_9_;
    char unknown_a_;
    unsigned char flag : 1;
    unsigned char other : 7;
};

#define SLEEP(combatant) ((struct Struct_ov000_0215833c*)(combatant)->currentStats_)

extern float data_ov000_02182ad4[];
extern float data_ov000_02182bd4[];

int NextRandomMax(struct Random* random, int max);
extern "C" int func_ov000_02156038(GameObject* combatant);
extern "C" void func_020882dc(void* stats);
extern "C" int func_020882f8(unsigned char* stats);
extern "C" void func_02088390(void* stats);
extern "C" int func_ov000_021543f4(GameObject* combatant);
extern "C" void func_020883fc(void* stats);

// USA: func_ov000_0215833c
extern "C" ARM int func_ov000_0215833c(struct Random* arg0, int index, Struct_ov000_0215767c_10* node) {
    unsigned char* turns;
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(index);
    if (combatant == 0) {
        return 0;
    }
    if (SLEEP(combatant)->unknown_3c_6_) {
        node->flag = 1;
    }
    float r = (float)NextRandomMax(arg0, 100) / 100.0f;
    turns = SLEEP(combatant)->turns;

    if (func_ov000_02156038(combatant)) {
        if (turns[0] != 0) {
            int remaining = turns[0] - 1;
            float var4 = data_ov000_02182ad4[remaining & 0xff];
            turns[0] = remaining;
            if (var4 > r) {
                turns[0] = 0;
                func_020882dc(combatant->currentStats_);
                node->action = 0x384;
                node->unknown_9_ = 0;
                return 1;
            }
        }
    } else if (func_020882f8((unsigned char*)combatant->currentStats_)) {
        if (turns[1] != 0) {
            int remaining = turns[1] - 1;
            float var6 = data_ov000_02182bd4[remaining & 0xff];
            turns[1] = remaining;
            if (var6 > r) {
                turns[1] = 0;
                func_02088390(combatant->currentStats_);
                node->action = 0x385;
                node->unknown_9_ = 0;
                return 1;
            }
        }
    } else if (func_ov000_021543f4(combatant) && turns[2] != 0) {
        int remaining = turns[2] - 1;
        float var8 = data_ov000_02182ad4[remaining & 0xff];
        turns[2] = remaining;
        if (var8 > r) {
            turns[2] = 0;
            func_020883fc(combatant->currentStats_);
            node->action = 0x3aa;
            node->unknown_9_ = 0;
            return 1;
        }
    }
    return 0;
}
