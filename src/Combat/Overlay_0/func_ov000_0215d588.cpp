#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0208977c;
extern "C" void func_0208977c(struct Struct_0208977c* p);

struct Struct_ov000_0215d588 {
    char pad0[0x138];
    struct Struct_0208977c* stats;
};

struct Struct_ov000_0215d588_2 {
    char pad0[0xf];
    unsigned char active;
    char pad10[0x18 - 0x10];
};

struct Struct_ov000_0215d588_3 {
    char pad0[0x81b0];
    struct Struct_ov000_0215d588_2 slots[3];
};

struct Struct_ov000_02182c74 { short v[16]; };
extern Struct_ov000_02182c74 data_ov000_02182d14;

extern "C" void func_ov000_0215d090(struct Struct_ov000_0215d588_3* self);
extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);

// USA: func_ov000_0215d588
extern "C" ARM void func_ov000_0215d588(struct Struct_ov000_0215d588_3* self) {
    func_ov000_0215d090(self);
    for (int i = 0; i < 3; i++) {
        self->slots[i].active = 0;
    }
    Struct_ov000_02182c74 ids = data_ov000_02182d14;
    int count = func_ov000_02153e40(self, ids.v, 0x10, 0);
    for (int i = 0; i < count; i++) {
        int id = ids.v[i];
        GameState* gs = GameState::GetInstance();
        Struct_ov000_0215d588* c = (Struct_ov000_0215d588*)gs->GetCombatantByIndex(id);
        if (c != NULL) {
            func_0208977c(c->stats);
        }
    }
}
