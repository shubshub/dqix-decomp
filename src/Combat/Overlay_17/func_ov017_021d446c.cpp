#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);
struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short field2 : 2;
};

struct Struct_ov017_021d446c {
    unsigned short field0;
    unsigned char pad2;
    unsigned char unknown_3_0_ : 4;
};

struct Struct_ov017_021d446c_2 {
    int field0;
    Entry_02028bd0* field4;
    GameObject* field8;
};

// USA: func_ov017_021d446c
extern "C" ARM int func_ov017_021d446c(Struct_ov017_021d446c* p0, Struct_ov017_021d446c_2* out, int p2) {
    GameState* bs = GameState::GetInstance();
    void* tbl = Zone3D_GetInstance();
    struct Entry_02028bd0* entryBase = ZoneRecords_GetInstance();

    if (p0->field0 != *(unsigned short*)tbl && p2 != 1) {
        return 0;
    }

    struct Entry_02028bd0* entry = ZoneRecords_Find(entryBase, p0->field0);
    out->field4 = entry;
    if (entry == 0) return 0;

    int idx = 112 + entry->field2 * 12 + p0->unknown_3_0_;
    out->field0 = idx;
    GameObject* combatant = bs->GetFieldMonsterByIndex(idx);
    out->field8 = combatant;
    if (combatant == 0) return 0;

    int state = *(int*)((char*)combatant + 0x130);
    if (state == 8) return 0;
    if (state == 9) return 0;
    return 1;
}
