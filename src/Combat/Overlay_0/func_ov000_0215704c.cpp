#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_02088418;

struct Struct_ov000_0215704c {
    char pad0[0x22];
    unsigned short unknown_22_0_ : 12;
    unsigned short unknown_23_4_ : 2;
    char pad24[0x28 - 0x24];
    short targetId;
    char unknown_2a_[0x4a - 0x2a];
    unsigned char unknown_4a_;
    char unknown_4b_[0x4e - 0x4b];
    unsigned char unknown_4e_;
    char unknown_4f_[0x53 - 0x4f];
    unsigned char rate;
};

struct Struct_ov000_0215704c_2 {
    char pad0[0x138];
    struct Struct_ov000_0215704c* action;
};

struct Struct_ov000_02182a64 {
    short ids[4];
};

struct Struct_ov000_0215704c_3 {
    unsigned char weight;
    unsigned char enabled;
    unsigned char mode;
    unsigned char unknown_3_;
};

struct Struct_ov000_02182aa0 {
    struct Struct_ov000_0215704c_3 choices[3];
};

extern struct Struct_ov000_02182a64 data_ov000_02182a64;
extern struct Struct_ov000_02182aa0 data_ov000_02182aa0;

extern "C" int func_ov000_0215e9fc(struct Random* battle, short* buf, int max, int start);
extern "C" int func_ov000_02155f9c(struct Random* battle, int combatantId, int arg2);
extern "C" float func_ov000_0215641c(struct Random* battle, int id);
int NextRandomMax(struct Random* random, int maximum);
extern "C" int func_02088418(struct Struct_02088418* c, int index, int arg2);
extern "C" int func_0208824c(unsigned char* obj);
extern "C" int func_020883ac(unsigned char* obj);

static inline int inline_ov000_02156cc4_2(int index) {
    return index >= 0 && index <= 3;
}

// USA: func_ov000_0215704c
extern "C" ARM int func_ov000_0215704c(struct Random* battle, int index) {
    int count;
    GameState* gs;
    if (inline_ov000_02156cc4_2(index)) {
        return 0;
    }
    struct Struct_ov000_02182a64 targets = data_ov000_02182a64;
    count = func_ov000_0215e9fc(battle, targets.ids, 4, 1);
    struct Struct_ov000_0215704c_2* self = (struct Struct_ov000_0215704c_2*)GameState::GetInstance()->GetCombatantByIndex(index);
    if (self == NULL) {
        return 0;
    }
    if (func_ov000_02155f9c(battle, index, 0)) {
        return 0;
    }
    if (self->action->rate == 0) {
        return 0;
    }
    gs = GameState::GetInstance();
    for (int i = 0; i < count; i++) {
        if (func_0200ff1c(gs, targets.ids[i]) == NULL) {
            continue;
        }
        float var5 = func_ov000_0215641c(battle, targets.ids[i]);
        var5 *= self->action->rate / 100.0f;
        if (var5 > NextRandomMax(battle, 100)) {
            struct Struct_ov000_02182aa0 table = data_ov000_02182aa0;
            table.choices[0].unknown_3_ = func_02088418((struct Struct_02088418*)self->action, 10, 0);
            table.choices[1].enabled = self->action->unknown_4e_;
            table.choices[1].unknown_3_ = func_0208824c((unsigned char*)self->action);
            table.choices[2].enabled = self->action->unknown_4a_;
            table.choices[2].unknown_3_ = func_020883ac((unsigned char*)self->action);
            int roll = NextRandomMax(battle, 100);
            for (int j = 0; j < 3; j++) {
                if (table.choices[j].weight > roll) {
                    if (table.choices[j].enabled && table.choices[j].unknown_3_) {
                        self->action->unknown_23_4_ = table.choices[j].mode;
                        self->action->targetId = targets.ids[i];
                        return 1;
                    }
                }
                roll -= table.choices[j].weight;
            }
        }
    }
    return 0;
}
