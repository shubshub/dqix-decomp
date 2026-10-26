#include <globaldefs.h>
#include "GameState/GameState.h"

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short field2 : 2;
    unsigned short : 14;
};
extern "C" struct Entry_02028bd0* ZoneRecords_FindCurrent(void);
extern "C" GameObject* func_ov017_021a2738(void* unused, int value);
struct Struct_02072adc;
extern "C" void func_02072adc(struct Struct_02072adc* src, struct Struct_02072adc* dst);
struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);

// USA: func_ov017_021a2b1c
extern "C" ARM void func_ov017_021a2b1c(void* param) {
    GameState* bs = GameState::GetInstance();
    struct Entry_02028bd0* entry = ZoneRecords_FindCurrent();
    if (!entry) return;

    int i;
    for (i = 0; i < 0xc; i++) {
        int t = entry->field2 * 0xc;
        t = t + 0x70;
        int idx = i + t;
        GameObject* combatant = bs->GetFieldMonsterByIndex(idx);
        if (!combatant) continue;
        GameObject* found = func_ov017_021a2738(param, combatant->obj3D_.unknown_2_);
        if (!found) continue;
        func_02072adc((struct Struct_02072adc*)found, (struct Struct_02072adc*)combatant);
        switch (*(int*)((char*)combatant + 0x130)) {
            case 0:
                GameObject_ForceMotionState((struct Bytes02033b88*)combatant, 5);
                break;
            case 2: case 4: case 5: case 6:
                GameObject_ForceMotionState((struct Bytes02033b88*)combatant, 1);
                break;
            case 9:
                GameObject_ForceMotionState((struct Bytes02033b88*)combatant, 2);
                break;
            default:
                GameObject_ForceMotionState((struct Bytes02033b88*)combatant, 0);
                break;
        }
    }
}
