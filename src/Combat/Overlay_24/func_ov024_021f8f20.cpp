#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_02053c6c(unsigned char* obj);

struct Struct_ov024_021f8f20;
typedef void (Struct_ov024_021f8f20::*Type_ov024_021f8f20)(unsigned short id, GameObject* combatant, unsigned short* state);
struct Struct_ov024_021ff054 { Type_ov024_021f8f20 e[6]; };

struct Struct_ov024_021f8f20 {
    int owner;
    short id;
    unsigned char mode;
    char unknown_7_[0x124 - 0x7];
    float weight;
};

extern "C" void func_ov024_021f8628(Struct_ov024_021f8f20* obj, unsigned short id, GameObject* combatant, unsigned short* state);
extern "C" void func_ov024_021f7478(Struct_ov024_021f8f20* obj);

extern Struct_ov024_021ff054 data_ov024_021ff054;
extern Type_ov024_021f8f20 __ptmf_null;

// USA: func_ov024_021f8f20
extern "C" ARM void func_ov024_021f8f20(Struct_ov024_021f8f20* obj, int owner, int id, unsigned short* state) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), id);
    void* field = func_02053c6c((unsigned char*)combatant);
    if (*state != 1) {
        return;
    }
    obj->owner = owner;
    obj->id = id;
#if defined(jpn)
    unsigned char mode = (signed char)*(int*)((char*)field + 0x8b4);
#else
    unsigned char mode = (signed char)*(int*)((char*)field + 0x94c);
#endif
    if (mode == 5) {
        return;
    }
    if (mode > 5) {
        func_ov024_021f8628(obj, id, combatant, state);
        return;
    }
    obj->weight = 0.5f;
    obj->mode = mode;
    func_ov024_021f7478(obj);
    Struct_ov024_021ff054 table = data_ov024_021ff054;
    table.e[5] = __ptmf_null;
    Type_ov024_021f8f20 fn = table.e[mode];
    if (fn != 0) {
        (obj->*fn)(id, combatant, state);
    }
}
