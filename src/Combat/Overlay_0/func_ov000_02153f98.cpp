#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

struct Struct_ov000_02153f98 {
    char pad0[0x14];
    unsigned int : 28;
    unsigned int kind : 4;
};

struct Struct_ov000_02182b24 {
    short v[8];
};

extern "C" struct Struct_ov000_02153f98* func_02079e2c(char* p, int key);
extern "C" int func_ov000_0215e9fc(struct Random* arg0, short* buf, int max, int start);

extern struct Struct_ov000_02182b24 data_ov000_02182b24;

// USA: func_ov000_02153f98
extern "C" ARM int func_ov000_02153f98(struct Random* arg0, int id, int action, short* out) {
    GameState* gs = GameState::GetInstance();
    struct Struct_ov000_02153f98* entry = func_02079e2c((char*)func_020797dc(), (short)action);
    if (entry == NULL) {
        return 0;
    }
    if (func_0200ff1c(gs, id) == NULL) {
        return 0;
    }
    unsigned int kind = entry->kind;
    int count = func_ov000_0215e9fc(arg0, out, 8, 1);
    if (kind == 2) {
        *out = out[NextRandomMax(arg0, count)];
        count = 1;
    } else if (kind == 8) {
        struct Struct_ov000_02182b24 list = data_ov000_02182b24;
        short n = 0;
        short* p = list.v;
        for (int i = 0; i < count; i++) {
            if (id != out[i]) {
                p[n] = out[i];
                n++;
            }
        }
        *out = p[NextRandomMax(arg0, n)];
        count = 1;
    } else {
        *out = id;
        count = 1;
    }
    return count;
}
