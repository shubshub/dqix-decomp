#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* func_02027ccc(int key);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void FieldMonsterState_Init(void* obj);
extern "C" void func_ov017_021c9544(int a0, int a1, int a2, int a3);

struct Struct_ov017_021a33e0 { unsigned char pad0[2]; unsigned short field2 : 2; unsigned short pad3 : 14; };

// USA: func_ov017_021a33e0
extern "C" ARM void func_ov017_021a33e0(void* unused, int key) {
    GameState* battleStruct = GameState::GetInstance();
    Zone3D_GetInstance();
    void* search = LinkSession_GetInstance();
    struct Entry_02028bd0* entry = func_02027ccc(key);
    if (entry == NULL) return;

    *(int*)((char*)entry + 8) = 0;

    int i;
    for (i = 0; i < 0xc; i++) {
        int idx = ((struct Struct_ov017_021a33e0*)entry)->field2;
        int base = idx * 0xc + 0x70;
        GameObject* combatant = battleStruct->GetFieldMonsterByIndex(i + base);
        if (combatant) {
            FieldMonsterState_Init(combatant);
            ((Object3D*)((unsigned char*)combatant))->MakeHidden();
            if (LinkSession_IsActive((int*)search) && LinkSession_IsHostOrSolo(search)) {
                func_ov017_021c9544(key, i, combatant->obj3D_.unknown_2_, -1);
            }
        }
    }
}
