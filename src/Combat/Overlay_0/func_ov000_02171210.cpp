#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0217538c(void* list);
extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" int func_ov000_02175f80(void* obj);
extern "C" int func_ov000_0217608c(void* obj);

struct Struct_ov000_02184288 {
    int field0;
    int field4;
    void* list;
};
extern struct Struct_ov000_02184288 data_ov000_02184288;
extern int data_ov000_02183ff0;

struct Struct_ov000_02171210 {
    char pad0[4];
    unsigned int id : 12;
    unsigned int pad4 : 20;
    unsigned int pad8 : 8;
    unsigned int mode : 2;
    unsigned int unknown_9_2_ : 22;
    char unknown_c_[0x14 - 0xc];
    unsigned int unknown_14_0_ : 28;
    unsigned int kind : 4;
};

struct Struct_ov000_02171210_2 {
    char pad0[0x1d];
    signed char unknown_1d_;
    char pad1e[0x21 - 0x1e];
    signed char unknown_21_;
    char unknown_22_[0x2e - 0x22];
    signed char unknown_2e_;
    char unknown_2f_[0x4c - 0x2f];
    int combatantId;
#if defined(jpn)
    char unknown1_50_[0x474 - 0x50];
#else
    char unknown_50_[0x434 - 0x50];
#endif
    int unknown_434_;
};

// USA: func_ov000_02171210
extern "C" ARM int func_ov000_02171210(struct Struct_ov000_02171210* action, struct Struct_ov000_02171210_2* target) {
    if (action->mode == 1) {
        target->unknown_1d_ = 0;
        target->unknown_21_ = -1;
        target->unknown_2e_ = -1;
        int kind = action->kind;
        if (kind == 3) {
            return 100;
        }
        if (kind == 4) {
            if (data_ov000_02184288.list != NULL && func_ov000_0217538c(data_ov000_02184288.list) == 1) {
                return 100;
            }
        } else if (data_ov000_02184288.field4 == 1) {
            return 100;
        }
        target->unknown_434_ = 0;
        return 0xe;
    } else if (action->mode == 2) {
        GameState::GetInstance();
        target->unknown_1d_ = -1;
        target->unknown_21_ = 0;
        int kind = action->kind;
        if (kind == 6) {
            GameObject* combatant = func_0200ff1c(GameState::GetInstance(), target->combatantId);
            if (combatant != NULL) {
#if defined(jpn)
                if (func_02083b00(*(unsigned char**)((char*)combatant + 0x144), 0xe6)) {
                    kind = 3;
                } else {
                    kind = 2;
                }
#else
                kind = 2;
                if (func_02083b00(*(unsigned char**)((char*)combatant + 0x150), 0xe6)) {
                    kind = 3;
                }
#endif
            }
        }
        int countA = 1;
        int countB = 1;
        if (data_ov000_02184288.list != NULL) {
            countA = func_ov000_02175f80(data_ov000_02184288.list);
            countB = func_ov000_0217608c(data_ov000_02184288.list);
        }
        switch (kind) {
        case 3:
        case 4:
            target->unknown_2e_ = target->combatantId;
            return 100;
        case 8:
            if (data_ov000_02184288.list != NULL) {
                if (data_ov000_02183ff0 == 1 || countA == 1 || countB == 1) {
                    return 0x1e;
                }
            }
            return 0x14;
        case 1:
            if ((action->id == 0xb9 || action->id == 0xb6) && data_ov000_02184288.list != NULL) {
                if (data_ov000_02183ff0 == 1 || countA == 1 || countB == 1) {
                    return 0x1e;
                }
            }
            target->unknown_21_ = 0;
            target->unknown_2e_ = target->combatantId;
            return 100;
        case 7:
            if (countB != 1) {
                return 0x13;
            }
            target->unknown_21_ = 0;
            target->unknown_2e_ = target->combatantId;
            return 100;
        default:
            if (countB != 1) {
                return 0x12;
            }
            target->unknown_21_ = 0;
            target->unknown_2e_ = target->combatantId;
            return 100;
        }
    }
    return 100;
}
