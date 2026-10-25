#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* obj, int value);
void* GetActiveCombatWork_ov000_02160130(void);
extern "C" void* func_ov000_02160f14(void* obj);
void GameState_SetCamera(GameState* battleStruct, int value);
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);
struct Container02037364;
struct S1a0;

struct Struct_ov025_021e8bc4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    struct Struct_ov025_021e8bc4* unknown_8_;
};
struct Struct_ov025_021e8bc4_2 {
    char unknown_0_[0x1d8];
    struct Struct_ov025_021e8bc4* unknown_1d8_;
};

// USA: func_ov025_021e8bc4
extern "C" ARM void func_ov025_021e8bc4(struct Struct_ov025_021e8bc4_2* arg0, int arg1) {
    if (!arg0->unknown_1d8_) return;

    GameState* battle = GameState::GetInstance();
    void* g = func_02057924();
    battle->GetCamera();

    struct Struct_ov025_021e8bc4* var2 = arg0->unknown_1d8_;
    while (var2 != 0 && arg1 <= var2->unknown_1_) {
        switch (var2->unknown_0_) {
        case 0: {
            GameObject* combatant = battle->GetGameObjectByIndex(node->id2);
            if (combatant) {
                char* name = *(char**)((char*)combatant + 0x14);
                char buf[0x28];
                if (name) strcpy(buf, name);
                unsigned char b = combatant->obj3D_.animationFlags_;
                unsigned int saved = combatant->obj3D_.animationTime_;
                ((Object3D*)((struct Container02037364*)combatant))->RemoveAnimationPackageByID(node->id4);
                combatant->obj3D_.SetAnimationByName((char const*)buf, b);
                ((Object3D*)((struct S1a0*)combatant))->SetCurrentAnimationTime(saved);
            }
            break;
        }
        case 1:
            func_02057f00(var1, var2->unknown_4_);
            break;
        case 3:
            GameState_SetCamera(battle, (int)func_ov000_02160f14(GetActiveCombatWork_ov000_02160130()));
            break;
        case 4: {
            GameObject* var8 = var0->GetGameObjectByIndex(var2->unknown_2_);
            if (var8) {
                ((Object3D*)((unsigned char*)var8))->Destroy();
                func_0200fd48(var0, var2->unknown_2_);
            }
            break;
        }
        default:
            break;
        }
        var2 = var2->unknown_8_;
    }
    arg0->unknown_1d8_ = var2;
}
