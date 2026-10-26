#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

class GameState {
public:
    static GameState* GetInstance();
};

struct Struct_ov024_021f9030_3 {
    unsigned short unknown_0_;
    char pad2[0x16];
    unsigned int unknown_18_;
};

struct GameObject {
    char pad0[4];
    short id;
    char pad6[0x12a];
    unsigned int* status;
    char unknown_134_[4];
    struct Struct_ov024_021f9030_3* stats;
    char unknown_13c_[0x40];
    unsigned char unknown_17c_;
};

struct Struct_02053dc0;

struct Struct_ov024_021f9030_4 {
    unsigned short action;
    signed char target;
    unsigned char unknown_3_;
};

struct Struct_ov024_021f9030_5 {
    char pad0[0x8e18];
    unsigned char* party;
};

struct Struct_ov024_021f9030_6 {
#if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int mode;
};

struct Struct_ov024_021f9030_7 {
    char field_0[4];
    unsigned int id : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int field_8 : 20;
    unsigned int excluded : 1;
    unsigned int unknown_b_5_ : 3;
    char unknown_c_[0xc];
    unsigned int field_18 : 5;
    unsigned int type : 7;
    unsigned int unknown_19_4_ : 20;
    char field_1c[0x10];
    unsigned int unknown_2c_0_ : 14;
    unsigned int unknown_2d_6_ : 6;
    unsigned int unknown_2e_4_ : 12;
};

struct Struct_ov024_021f9030 {
    short id;
    char flags;
    unsigned char unknown_3_;
};

struct Struct_ov024_021f9030_2 {
    struct Struct_ov024_021f9030_5* owner;
    short id;
    unsigned char mode;
    unsigned char active;
    struct GameObject* combatant;
    int unknown_c_;
    char unknown_10_[0x6c];
    struct GameObject* targets[8];
    int unknown_9c_;
    char unknown_a0_[0x64];
    int power[4];
    float ratio[4];
    float weight;
    int target;
    char unknown_12c_[4];
    int unknown_130_;
    char unknown_134_[0x40];
    int count;
    struct Struct_ov024_021f9030 unknown_178_[0x134];
    struct Struct_ov024_021f9030* selected;
    struct Struct_ov024_021f9030_7* selectedSkill;
    int unknown_650_;
};

struct Struct_ov024_021fefc2 {
    unsigned short ids[10];
};

extern "C" void __clear(void* dst, int size);
extern "C" void* func_02053c6c(unsigned char* obj);
extern "C" GameObject* func_0200ff1c(GameState* gameState, int combatantId);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" int func_ov024_021e6798(GameObject* combatant);
extern "C" Struct_ov024_021f9030_4* func_02053dc0(Struct_02053dc0* p);
extern "C" Struct_ov024_021f9030_7* func_02079e2c(char* table, int id);
extern "C" int func_ov000_02155f9c(Struct_ov024_021f9030_5* battle, int combatantId, int arg2);
extern "C" void func_ov024_021f7478(Struct_ov024_021f9030_2* obj);
extern "C" int func_ov024_021f8874(Struct_ov024_021f9030_2* obj, Struct_ov024_021f9030_7* skill, GameObject* combatant, int* arg3);
extern "C" void func_ov024_021fa7ec(Struct_ov024_021f9030_2* self, float* arg1, float* arg2, float* arg3,
                                    int* outIndex, float arg5, float arg6, int arg7,
                                    GameObject* target, int index);
extern "C" float func_ov024_021db358(GameObject* obj);

extern Struct_ov024_021fefc2 data_ov024_021fefc2;

// USA: func_ov024_021f9030
extern "C" ARM void func_ov024_021f9030(Struct_ov024_021f9030_2* obj, Struct_ov024_021f9030_5* owner, int id, unsigned short* state) {
    GameState* gameState = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(gameState, id);
    Struct_ov024_021f9030_6* field = (Struct_ov024_021f9030_6*)func_02053c6c((unsigned char*)combatant);
    ActionDataTables* var3 = func_020797dc();
    unsigned char mode = (signed char)field->mode;
    if (mode >= 5) {
        return;
    }
    if (func_ov000_02155f9c(owner, id, 0) != 0 || *state != 1) {
        return;
    }
    obj->owner = owner;
    obj->id = id;
    obj->weight = 0.4f;
    if (obj->mode == 2) {
        obj->weight = 0.25f;
    }
    obj->mode = mode;
    obj->active = 1;
    Struct_ov024_021fefc2 ids = data_ov024_021fefc2;
    unsigned char found[10];
    __clear(found, sizeof(found));
    short var7[10];
    __clear(var7, sizeof(var7));
    unsigned char disabled;
    unsigned char var9;
    unsigned char var10;
    int var11 = 0;
    int var12 = obj->mode == 0;
    int var13 = 1;
    if (obj->mode != 1 && obj->mode != 4) {
        var13 = 0;
    }
    int var14 = obj->mode == 2;
    int var15 = obj->mode == 3;
    func_ov024_021f7478(obj);
    int i;
    disabled = 0;
    var9 = 0;
    var10 = 0;
    for (i = 0; i < 4; i++) {
        GameObject* var17 = func_0200ff1c(gameState, i);
        if (var17 == 0) continue;
        if (!func_020a35e0(obj->owner->party, i)) continue;
        if (func_ov024_021e6798(var17)) continue;
        if (*var17->status & 1) continue;
        if (var17->stats->unknown_18_ & 0x800) {
            disabled = 1;
        }
        Struct_ov024_021f9030_4* command = func_02053dc0((Struct_02053dc0*)var17);
        if (command == 0) continue;
        unsigned short action = command->action;
        if (action == 0x201) {
            var9 = 1;
            continue;
        }
        if (action == 0xb9 || action == 0x92 || action == 0xb6) {
            var10 = 1;
        }
    }
    for (i = 0; i < obj->count; i++) {
        Struct_ov024_021f9030* slot = &obj->unknown_178_[i];
        Struct_ov024_021f9030_7* skill = func_02079e2c((char*)var3, slot->id);
        int var22 = 0;
        if (skill->type == 2) {
            if (func_ov024_021f8874(obj, skill, combatant, &var22)) {
                if (slot->unknown_3_ == 0) {
                    var11 = 1;
                }
            }
            continue;
        }
        if (!skill->excluded && skill->unknown_2d_6_ == 0) continue;
        if (!func_ov024_021f8874(obj, skill, combatant, &var22)) continue;
        if (obj->mode == 4 && var22 != 0) continue;
        for (int j = 0; j < 10; j++) {
            if (ids.ids[j] == skill->id) {
                found[j] = 1;
                var7[j] = var22;
                break;
            }
        }
    }
    if (found[0] && !disabled && !var9 && !var12 && (!var13 || obj->unknown_c_ > 2)) {
        if (var11) {
            float weight = obj->weight;
            if (obj->target != obj->id && obj->ratio[obj->target] < weight) goto skipRevive;
        }
        Struct_ov024_021f9030_4* command = func_02053dc0((Struct_02053dc0*)combatant);
        command->action = 0x201;
        *state = 0x201;
        command->unknown_3_ = 0;
        command->target = combatant->id;
        return;
    }
skipRevive:
    if (found[1] && obj->unknown_9c_ <= 1 && (var12 || var13 || var14)) {
        GameObject* target = obj->targets[0];
        obj->selectedSkill = func_02079e2c((char*)var3, 0x45);
        obj->unknown_650_ = obj->selectedSkill->unknown_8_0_;
        float hi;
        float lo;
        float var29;
        int index;
        hi = 0;
        lo = 0;
        var29 = 0;
        index = -1;
        func_ov024_021fa7ec(obj, &hi, &lo, &var29, &index, 0, 0, 0, target, 0);
        if (lo > target->stats->unknown_0_) {
            Struct_ov024_021f9030_4* command = func_02053dc0((Struct_02053dc0*)combatant);
            command->action = 0x45;
            *state = 0x45;
            command->unknown_3_ = target->unknown_17c_;
            command->target = target->id;
            return;
        }
    }
    if (!(func_ov024_021db358(obj->combatant) > 0.25f) && !disabled && !var9 && var15 && !var11) {
        int action = 3;
        if (found[5]) {
            action = 0x87;
        }
        Struct_ov024_021f9030_4* command = func_02053dc0((Struct_02053dc0*)combatant);
        command->action = (unsigned short)action;
        *state = (unsigned short)action;
        command->unknown_3_ = 0;
        command->target = combatant->id;
        return;
    }
    if (!found[7] && !found[8] && !found[6]) return;
    if (!var15 || obj->unknown_130_ == 0) return;
    if (disabled || var9 || var10 || var11) return;
    if (func_ov024_021db358(combatant) < 0.5f) return;
    int self = obj->id;
    int target = obj->target;
    if (target == self) return;
    if (target < 0 || target > 4) return;
    if (self < 0 || self > 4) return;
    if (obj->power[self] < obj->power[target] * 2) return;
    int action = 0;
    if (obj->unknown_130_ >= 2 && found[7]) {
        action = 0xb6;
    } else if (found[8]) {
        action = 0xb9;
    } else if (found[6]) {
        action = 0x92;
    } else if (found[7]) {
        action = 0xb6;
    }
    if (action == 0) return;
    Struct_ov024_021f9030_4* command = func_02053dc0((Struct_02053dc0*)combatant);
    command->action = (unsigned short)action;
    *state = (unsigned short)action;
    command->unknown_3_ = 0;
    command->target = action == 0xb6 ? combatant->id : obj->target;
}
