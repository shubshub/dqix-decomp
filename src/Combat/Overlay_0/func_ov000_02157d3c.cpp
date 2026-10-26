#include <globaldefs.h>

struct ActionEntry {
    char pad0[0x20];
    short combatantId;
};

struct Struct_ov000_0215440c_2 {
    char pad0[8];
    unsigned char unknown_8_;
};

struct Struct_ov000_02182c74 {
    short v[8];
};

struct Struct_ov000_0215767c_2 {
    char pad0[0x81b1];
    unsigned char unknown_81b1_0_ : 4;
    unsigned char groupCount : 2;
    char unknown_81b2_[0x8e14 - 0x81b2];
    signed char result;
};

extern Struct_ov000_02182c74 data_ov000_02182c74;

extern "C" void func_ov000_02155e94(Struct_ov000_0215767c_2* battle);
extern "C" int func_ov000_0215e9fc(Struct_ov000_0215767c_2* battle, short* buf, int max, int start);
extern "C" void func_ov000_0215858c(Struct_ov000_0215767c_2* battle, int combatantId, ActionEntry* entry);
extern "C" void func_ov000_021599f4(Struct_ov000_0215767c_2* battle, int combatantId);
extern "C" ActionEntry* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);

// USA: func_ov000_02157d3c
extern "C" ARM void func_ov000_02157d3c(Struct_ov000_0215767c_2* battle, Struct_ov000_0215440c_2* action, int flag) {
    func_ov000_02155e94(battle);
    Struct_ov000_02182c74 ids = data_ov000_02182c74;
    if (func_ov000_0215e9fc(battle, ids.v, 8, 9) <= 0) {
        battle->result = 2;
    } else if (battle->unknown_81b1_0_ == 0) {
        battle->result = 1;
    } else {
        battle->result = 0;
    }
    if (battle->result == 0 && flag == 0) {
        int i;
        for (i = 0; i < action->unknown_8_; i++) {
            ActionEntry* entry = func_ov000_02160094(action, i);
            if (entry != 0) {
                func_ov000_0215858c(battle, entry->combatantId, entry);
                func_ov000_021599f4(battle, entry->combatantId);
            }
        }
    }
}
