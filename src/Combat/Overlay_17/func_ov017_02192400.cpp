#if defined(jpn)
enum { Enum_ov017_02192400_17500 = 0x41ac };
#else
enum { Enum_ov017_02192400_17500 = 0x445c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021923e0(void* obj, unsigned int value);

struct Struct_ov017_021d619e {
    short v[8];
};
struct Struct_ov017_021d6186 {
    signed char v[8];
};
extern Struct_ov017_021d619e data_ov017_021d619e;
extern Struct_ov017_021d6186 data_ov017_021d6186;

// USA: func_ov017_02192400
extern "C" ARM void func_ov017_02192400(unsigned char* self, int idx) {
    int ok;
    if (idx >= 0 && idx <= 3) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (!ok) {
        return;
    }

    GameState* battle = GameState::GetInstance();
    Struct_ov017_021d619e objs = data_ov017_021d619e;
    objs.v[0] = idx;
    objs.v[1] = idx * 0xc + 0x13;
    objs.v[2] = idx * 0xc + 0x14;
    objs.v[3] = idx * 0xc + 0x15;
    objs.v[4] = idx * 0xc + 0x1b;
    objs.v[5] = idx * 0xc + 0x1c;
    objs.v[6] = idx * 0xc + 0x1d;
    signed char* row = (signed char*)(self + Enum_ov017_02192400_17500) + idx * 11;

    Struct_ov017_021d6186 ids = data_ov017_021d6186;
    ids.v[0] = row[0];
    ids.v[1] = row[1];
    ids.v[2] = row[2];
    ids.v[3] = row[3];
    ids.v[4] = row[7];
    ids.v[5] = row[8];
    ids.v[6] = row[9];

    int i;
    for (i = 0; objs.v[i] > -1; i++) {
        GameObject* c = battle->GetGameObjectByIndex(objs.v[i]);
        if (c && ids.v[i] >= 0) {
            func_ov017_021923e0(c, ids.v[i]);
        }
    }
}
