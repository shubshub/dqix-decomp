#include <globaldefs.h>
#include "GameState/GameState.h"

extern int data_ov025_021ef82b;

struct Struct_ov025_021e6910 { char pad[0x10]; unsigned char* node; };

// USA: func_ov025_021e6910
extern "C" ARM int func_ov025_021e6910(void* unused, struct Struct_ov025_021e6910* p2) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetGameObjectByIndex(0xc8);
    if (!c) return 1;
    ((Object3D*)((unsigned char*)c))->MakeVisible();
    c->obj3D_.SetAnimationByName((char const*)&data_ov025_021ef82b, 1);
    unsigned short idx = *(unsigned short*)(p2->node + 0x20);
    GameObject* c2 = bs->GetGameObjectByIndex(idx * 0xc + 0x1c);
    if (c2) {
        ((Object3D*)((unsigned char*)c2))->MakeHidden();
    }
    return 1;
}
