#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);

struct Struct_ov000_0215ae80 {
    char pad0[0x20];
    short combatantId;
};

struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
extern "C" Struct_ov000_0215ae80* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
extern "C" void* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);

struct Struct_ov000_0215ae80_2 {
    char pad0[0x28];
};

extern "C" void* func_ov000_0215e9d8(void* work);
extern "C" void func_ov000_02160030(void* obj);

struct Struct_ov000_0215ae80_3 {
    char pad0[0x7770];
    Struct_ov000_0215ae80_2 actions[0x40];
    char unknown_8170_[0x8e0a - 0x8170];
    unsigned char unknown_8e0a_;
    char unknown_8e0b_[0x8e0f - 0x8e0b];
    unsigned char unknown_8e0f_;
    char unknown_8e10_[0x8e24 - 0x8e10];
    int unknown_8e24_;
};

// USA: func_ov000_0215ae80
extern "C" ARM void func_ov000_0215ae80(Struct_ov000_0215ae80_3* self) {
    int i;
    for (i = self->unknown_8e0a_; i < self->unknown_8e0f_; i++) {
        void* work = func_ov000_0215e9d8(self);
        if (work == NULL) return;
        func_ov000_02160030(work);
        Struct_ov000_0215ae80_2* node = &self->actions[i];
        Struct_ov000_0215ae80* entry = func_ov000_02160094((struct Struct_ov000_0215440c_2*)node, 0);
        if (entry != NULL && func_ov000_021600f8((struct Struct_ov000_0215440c*)node, 0) != NULL) {
            short id = entry->combatantId;
            GameState* gs = GameState::GetInstance();
            GameObject* c = gs->GetCombatantByIndex(id);
            if (c == NULL) return;
            if (func_02010088((struct S_10088*)c)) return;
            if (func_ov000_02153c0c(c)) return;
            memcpy(work, node, sizeof(Struct_ov000_0215ae80_2));
            self->unknown_8e24_++;
        }
    }
    self->unknown_8e0a_ = self->unknown_8e0f_;
}
