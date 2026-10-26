#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c9954 {
    Object3D obj3D;
    char unknown_ac_[0x17d - 0xac];
    unsigned char unknown_17d_0_ : 7;
    unsigned char active : 1;
};

struct Struct_ov017_021c9954_2 {
    char pad0[3];
    unsigned char locked;
};

struct Struct_ov017_021c9954_3 {
    char pad0[8];
    unsigned short id;
};

struct Struct_ov017_021c9954_4 {
    char pad0[4];
    unsigned short id;
};

struct Struct_ov017_021c9954_5 {
    char pad0[2];
    unsigned char active;
};

struct Struct_ov017_021c9954_6 {
    unsigned short id;
    unsigned short arg;
};

struct Struct_ov017_021c9954_7 {
#if defined(jpn)
    char pad0[0x3508];
#else
    char pad0[0x3718];
#endif
    Struct_ov017_021c9954_2* party;
#if defined(jpn)
    char unknown_350c_[0x3978 - 0x350c];
#else
    char unknown_371c_[0x3b98 - 0x371c];
#endif
    Struct_ov017_021c9954_5* cursor;
#if defined(jpn)
    char unknown_397c_[0x41fe - 0x397c];
#else
    char unknown_3b9c_[0x44ae - 0x3b9c];
#endif
    Struct_ov017_021c9954_6 target;
};

extern "C" void func_ov017_021b86f8(Struct_ov017_021c9954_2* party, int id, int flag, int keep);
extern "C" void FieldMonsterState_Init(void* obj);
extern "C" Struct_ov017_021c9954_3* func_ov017_021b8478(Struct_ov017_021c9954_2* party);
extern "C" Struct_ov017_021c9954_3* func_ov017_021b8468(Struct_ov017_021c9954_2* party);
extern "C" void func_ov000_02163778(void* current);
extern "C" void func_020dc548(signed char id, signed char* out, signed char* count);
extern "C" void func_ov017_021917f0(int id, int flag);
extern "C" Struct_ov017_021c9954* func_ov017_021a278c(void* unused, int val);
extern "C" void func_ov017_021c98f4(int id, int value);
extern "C" void func_02076ccc(void* obj, int mode);
extern "C" Struct_ov017_021c9954_4* func_ov017_021a7c8c(void* obj);
extern "C" void func_ov017_021a7c1c(unsigned char* obj);

// USA: func_ov017_021c9954
extern "C" ARM void func_ov017_021c9954(int id, int arg1, int keep, int group) {
    GameState::GetInstance();
    Struct_ov017_021c9954_7* battle = (Struct_ov017_021c9954_7*)GetGameResources();
    Struct_ov017_021c9954* combatant;
    Struct_ov017_021c9954_2* party = battle->party;
    func_ov017_021b86f8(party, id, 1, keep);

    combatant = func_ov017_021a278c(battle, id);
    if (combatant != 0 && keep == 0) {
        FieldMonsterState_Init(combatant);
        combatant->obj3D.MakeHidden();
    }
    func_ov017_021c98f4(id, 0);

    if (arg1 != 0) {
        Struct_ov017_021c9954_3* leader = func_ov017_021b8478(party);
        Struct_ov017_021c9954_3* current = func_ov017_021b8468(party);
        if (current != 0 && leader != 0 && leader->id == id) {
            func_ov000_02163778(current);
        }
    }

    Struct_ov017_021c9954_6* target = &battle->target;
    if (battle->target.id == id) {
        target->id = 0;
        target->arg = 0;
    }

    if (combatant != 0 && keep != 0) {
        func_02076ccc(combatant, 1);
        combatant->active = 0;
    }

    Struct_ov017_021c9954_5* cursor = battle->cursor;
    if (cursor->active != 0) {
        Struct_ov017_021c9954_4* slot = func_ov017_021a7c8c(cursor);
        if (slot->id == id) {
            func_ov017_021a7c1c((unsigned char*)cursor);
        }
    }

    if (group > -1 && party->locked == 0) {
        signed char count;
        signed char members[7];
        func_020dc548(group, members, &count);
        for (int i = 0; i < count; i++) {
            func_ov017_021917f0(members[i], 0);
        }
    }
}
