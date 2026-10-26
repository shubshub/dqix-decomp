#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205a148;
extern "C" void func_0205a148(struct Struct_0205a148* obj);

struct Struct_020d7638 {
    unsigned char pad0[0xd0];
    int field_d0;
    unsigned char pad1[4];
};

struct Struct_020d7638_2 {
    unsigned char pad0[0x41];
    unsigned char lo5 : 5;
    unsigned char unknown_41_5_ : 1;
    unsigned char unknown_41_6_ : 2;
};

// USA: func_020d7638
extern "C" ARM void func_020d7638(struct Struct_020d7638* obj) {
    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 0xc; i++) {
        GameObject* combatant;
        int id;
        if (obj[i].field_d0 < 0) continue;
        id = i;
        if (i > 3) id = i + 0xbc;
        combatant = bs->GetGameObjectByIndex(id);
        if (!combatant) continue;
        if (!((Object3D*)((unsigned char*)combatant))->IsVisible()) continue;
        if (!((struct Struct_020d7638_2*)combatant)->unknown_41_5_) continue;
        func_0205a148((struct Struct_0205a148*)&obj[i]);
    }
}
