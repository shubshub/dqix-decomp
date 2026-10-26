#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021fe970 {
    float unknown_0_;
    unsigned char rank;
};

struct Struct_ov024_021fe974 {
    unsigned char rank;
    char pad[7];
};

extern Struct_ov024_021fe970 data_ov024_021fe970[9];
extern Struct_ov024_021fe974 data_ov024_021fe974[9];

static inline unsigned short inline_ov024_021dc700(GameObject* obj) {
    return obj->currentStats_->primaryStats.maxHP;
}

// USA: func_ov024_021eb344
extern "C" ARM int func_ov024_021eb344(void* self, int id, int arg2) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), id);
    if (combatant == 0) return 0;
    if (arg2 <= 0) return 0;
    unsigned short maxHP = inline_ov024_021dc700(combatant);
    float ratio = (float)arg2 / (float)maxHP;
    for (int i = 0; i < 9; i++) {
        if (ratio >= data_ov024_021fe970[i].unknown_0_) return data_ov024_021fe974[i].rank;
    }
    return 0;
}
