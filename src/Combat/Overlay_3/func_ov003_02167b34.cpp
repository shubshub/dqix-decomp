#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02167b34_2384 = 0x8b8 };
enum { Enum_ov003_02167b34_118 = 0x46 };
#else
enum { Enum_ov003_02167b34_2384 = 0x950 };
enum { Enum_ov003_02167b34_118 = 0x76 };
#endif
#include "GameState/GameState.h"

struct Struct_ov003_02167b34 {
    unsigned int value0 : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_4_0_ : 10;
    unsigned int unknown_5_2_ : 10;
    unsigned int unknown_6_4_ : 10;
    unsigned int unknown_8_0_ : 10;
    unsigned int unknown_9_2_ : 10;
    unsigned int value8 : 10;
    unsigned int unknown_c_0_ : 10;
    unsigned char pad10[0x138 - 0x10];
    int unknown_138_[0xd];
    unsigned short unknown_16c_[0xd];
    unsigned char unknown_186_[0x464 - 0x186];
    unsigned char entryTable[0x49c - 0x464];
    unsigned char flag : 1;
    unsigned char unknown_49d_[Enum_ov003_02167b34_2384 - 0x49d];
    int index;
};

struct Struct_ov003_02167b34_2;
struct Struct_ov003_02167b34_3 {
    unsigned char pad0[0x10];
    void* list;
    unsigned char unknown_14_[Enum_ov003_02167b34_118 - 0x14];
    signed char combatantId;
};

extern "C" void* func_02053c6c(unsigned char* obj);
extern "C" void PartyMember_RecalculateStats(void* data, int arg);
extern "C" void func_ov003_02167e28(Struct_ov003_02167b34_3* menu, BaseCombatStats* stats, int flag, unsigned char index, int arg4, int arg5, int arg6);
extern "C" void func_ov003_02167fa4(Struct_ov003_02167b34_3* menu, int flag, unsigned char* table);
extern "C" void func_ov003_02168088(struct Struct_ov003_02167b34_2* obj, int* arr);
extern "C" void func_020813ec(void* list, int arg);

static inline BaseCombatStats* inline_02069120(GameObject* c) { SDK_NULL_ASSERT(c); return c->baseStats_; }

// USA: func_ov003_02167b34
extern "C" ARM void func_ov003_02167b34(Struct_ov003_02167b34_3* menu) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), menu->combatantId);
    if (combatant == 0) return;
    Struct_ov003_02167b34* data = (Struct_ov003_02167b34*)func_02053c6c((unsigned char*)combatant);
    PartyMember_RecalculateStats(data, 0);
    func_ov003_02167e28(menu, inline_02069120(combatant), data->flag, data->index, data->unknown_186_[data->index], data->unknown_16c_[data->index], data->unknown_138_[data->index]);
    func_ov003_02167fa4(menu, data->index & 0xff, data->entryTable);
    int values[12];
    values[0] = data->value0;
    values[1] = data->unknown_1_2_;
    values[2] = data->unknown_2_4_;
    values[3] = data->unknown_4_0_;
    values[4] = data->unknown_5_2_;
    values[5] = data->unknown_6_4_;
    values[6] = data->unknown_8_0_;
    values[7] = data->unknown_9_2_;
    values[8] = data->value8;
    values[9] = combatant->baseStats_->primaryStats.attack;
    values[10] = combatant->baseStats_->primaryStats.defense;
    values[11] = data->unknown_c_0_;
    func_ov003_02168088((struct Struct_ov003_02167b34_2*)menu, values);
    func_020813ec(menu->list, 0);
}
