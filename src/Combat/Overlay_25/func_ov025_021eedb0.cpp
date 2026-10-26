#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_02000c9c_80 { unsigned int v[4]; };

struct Struct_ov025_021eedb0 {
    unsigned int f0;
    unsigned int f4;
    struct Struct_02000c9c_80 unknown_8_;
    struct Struct_ov025_021eedb0* next;
};

struct Struct_ov025_021eedb0_2 {
    char pad0[0xe0];
    struct Struct_ov025_021eedb0* unknown_e0_;
    struct Struct_ov025_021eedb0* unknown_e4_;
};

typedef int (*Type_02000c9c_4)(struct Struct_ov025_021eedb0*);
extern Type_02000c9c_4 data_ov025_021ef93c[];

// USA: func_ov025_021eedb0
extern "C" ARM void func_ov025_021eedb0(struct Struct_ov025_021eedb0_2* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned int elapsed = battle->GetEffectiveDeltaTime();
    struct Struct_ov025_021eedb0* node = obj->unknown_e0_;
    struct Struct_ov025_021eedb0* prev = 0;
    while (node != 0) {
        if (elapsed < node->f4) {
            node->f4 -= elapsed;
        } else {
            node->f4 = 0;
            if (data_ov025_021ef93c[node->f0](node) != 0) {
                if (prev != 0) prev->next = node->next;
                else obj->unknown_e0_ = node->next;
                struct Struct_ov025_021eedb0* next = node->next;
                node->next = obj->unknown_e4_;
                obj->unknown_e4_ = node;
                node = next;
                continue;
            }
        }
        prev = node;
        node = node->next;
    }
}
