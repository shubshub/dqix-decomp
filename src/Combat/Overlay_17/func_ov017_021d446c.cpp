#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);
struct Entry_02028bd0;
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

struct Struct_020fdd44 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 2;
};

struct Struct_ov017_021d446c {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_0_ : 4;
};

struct Struct_ov017_021d446c_2 {
    int unknown_0_;
    Struct_020fdd44* unknown_4_;
    GameObject* unknown_8_;
};

// USA: func_ov017_021d446c
extern "C" ARM int func_ov017_021d446c(Src021d446c* p0, Out021d446c* out, int p2) {
    GameState* bs = GameState::GetInstance();
    void* tbl = Zone3D_GetInstance();
    struct Entry_02028bd0* entryBase = ZoneRecords_GetInstance();

    if (arg0->unknown_0_ != *(unsigned short*)var1 && arg2 != 1) {
        return 0;
    }

    struct Entry_02028bd0* entry = ZoneRecords_Find(entryBase, p0->field0);
    out->field4 = entry;
    if (entry == 0) return 0;

    int idx = 112 + entry->field2 * 12 + p0->field3;
    out->field0 = idx;
    GameObject* combatant = bs->GetFieldMonsterByIndex(idx);
    out->field8 = combatant;
    if (combatant == 0) return 0;

    int var6 = *(int*)((char*)var5 + 0x130);
    if (var6 == 8) return 0;
    if (var6 == 9) return 0;
    return 1;
}
