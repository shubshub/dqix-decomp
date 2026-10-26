#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* obj, int value);
extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f14(void* obj);
extern "C" void GameState_SetCamera(GameState* battleStruct, int value);
extern "C" void func_0200fd48(GameState* battleStruct, int id);
struct Struct_ov001_0215bcc0;
struct Struct_0208f410;

struct Struct_ov025_021e8bc4 {
    unsigned char type;
    unsigned char priority;
    unsigned short id2;
    unsigned short unknown_4_;
    struct Struct_ov025_021e8bc4* next;
};
struct Struct_ov025_021e8bc4_2 {
    char pad[0x1d8];
    struct Struct_ov025_021e8bc4* head;
};

// USA: func_ov025_021e8bc4
extern "C" ARM void func_ov025_021e8bc4(struct Struct_ov025_021e8bc4_2* obj, int priority) {
    if (!obj->head) return;

    GameState* battle = GameState::GetInstance();
    void* g = func_02057924();
    battle->GetCamera();

    struct Struct_ov025_021e8bc4* node = obj->head;
    while (node != 0 && priority <= node->priority) {
        switch (node->type) {
        case 0: {
            GameObject* combatant = battle->GetGameObjectByIndex(node->id2);
            if (combatant) {
                char* name = *(char**)((char*)combatant + 0x14);
                char buf[0x28];
                if (name) strcpy(buf, name);
                unsigned char b = combatant->obj3D_.animationFlags_;
                unsigned int saved = combatant->obj3D_.animationTime_;
                ((Object3D*)((struct Struct_ov001_0215bcc0*)combatant))->RemoveAnimationPackageByID(node->unknown_4_);
                combatant->obj3D_.SetAnimationByName((char const*)buf, b);
                ((Object3D*)((struct Struct_0208f410*)combatant))->SetCurrentAnimationTime(saved);
            }
            break;
        }
        case 1:
            func_02057f00(g, node->unknown_4_);
            break;
        case 3:
            GameState_SetCamera(battle, (int)func_ov000_02160f14(func_ov000_02160130()));
            break;
        case 4: {
            GameObject* combatant = battle->GetGameObjectByIndex(node->id2);
            if (combatant) {
                ((Object3D*)((unsigned char*)combatant))->Destroy();
                func_0200fd48(battle, node->id2);
            }
            break;
        }
        default:
            break;
        }
        node = node->next;
    }
    obj->head = node;
}
