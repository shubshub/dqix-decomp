#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" void __clear(void* buf, int size);

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);

struct Struct_ov000_02153aa4 {
    unsigned short value;
    unsigned char members[8];
    unsigned char total : 4;
    unsigned char unknown_a_4_ : 4;
    char pad[0x18 - 0xb];
};

struct Struct_ov000_02153aa4_2 {
    unsigned char counter : 4;
    unsigned char groupCount : 2;
    unsigned char unused : 2;
};

struct Struct_ov000_02153aa4_3 {
    Random unknown_0_;
    char pad0[0x81b1 - sizeof(Random)];
    Struct_ov000_02153aa4_2 counts;
    char pad1[2];
    Struct_ov000_02153aa4 groups[3];
};

static inline GameObject* inline_ov000_02153aa4(short idx) {
    return GameState::GetInstance()->GetCombatantByIndex(idx);
}

// USA: func_ov000_02153aa4
extern "C" ARM void func_ov000_02153aa4(Struct_ov000_02153aa4_3* arg0, int arg1, int* target) {
    short idx = *target;
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(idx);
    if (c == NULL) {
        return;
    }
    if (!func_02010088((struct S_10088*)c) && !func_ov000_02153c0c(c)) {
        return;
    }
    Struct_ov000_02153aa4* groups = arg0->groups;
    int var4[3];
    __clear(var4, 0xc);
    int* var5 = var4;
    int count = 0;
    if (groups[arg1].unknown_a_4_ == 0) {
        for (int i = 0; i < arg0->counts.groupCount; i++) {
            if (groups[i].unknown_a_4_ != 0) {
                var5[count++] = i;
            }
        }
        arg1 = var5[NextRandomMax(&arg0->unknown_0_, count)];
    }

    int n;
    unsigned char* members;
    int j;
    int id;
    Struct_ov000_02153aa4* group;
    int* var13;
    int ids[8];
    __clear(ids, 0x20);
    n = 0;
    group = &groups[arg1];
    members = group->members;
    var13 = ids;
    for (j = 0; j < group->total; j++) {
        id = members[j] + 0xc0;
        GameObject* m = inline_ov000_02153aa4(id);
        if (m != NULL && !func_02010088((struct S_10088*)m) && !func_ov000_02153c0c(m)) {
            var13[n] = id;
            n++;
        }
    }
    *target = var13[NextRandomMax(&arg0->unknown_0_, n)];
}
