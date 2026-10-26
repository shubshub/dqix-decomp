#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_ov000_0215eb1c_2 {
    char pad[6];
    unsigned char members[8];
    unsigned char count : 4;
    unsigned char flags : 4;
    char tail[9];
};
struct Struct_ov000_0215eb1c {
    char pad[0x81b0];
    union {
        struct {
            unsigned char unknown_81b0_;
            unsigned char unknown_81b1_0_ : 4;
            unsigned char groupCount : 2;
            unsigned char unknown_81b1_6_ : 2;
        };
        Struct_ov000_0215eb1c_2 groups[3];
    };
};
struct S_10088;
extern "C" int func_ov000_02153c0c(GameObject*);
extern "C" int func_02010088(S_10088*);

// USA: func_ov000_0215eb1c
extern "C" ARM int func_ov000_0215eb1c(Struct_ov000_0215eb1c* roster, short* output, int capacity, int flags) {
    int count = 0;
    for (int group = 0; group < roster->groupCount; group++) {
        for (int member = 0; member < roster->groups[group].count; member++) {
            short id = roster->groups[group].members[member] + 0xc0;
            GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(id);
            if (!combatant) continue;
            if (!(flags & 0x10) && func_ov000_02153c0c(combatant)) continue;
            if ((flags & 1) && func_02010088((S_10088*)combatant)) continue;
            output[count++] = id;
            if (count == capacity) return count;
        }
    }
    return count;
}
