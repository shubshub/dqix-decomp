#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021ce704_3 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};
struct Struct_ov017_021ce704 {
    char unknown_0_[0x800];
    Struct_ov017_021ce704_3 unknown_800_[3];
    unsigned int unknown_80c_0_ : 10;
};
#if defined(jpn)
struct Struct_ov017_021ce704_2 { char unknown_0_[4]; Struct_ov017_021ce704 unknown_1c_; };
#else
struct Struct_ov017_021ce704_2 { char unknown_0_[0x1c]; Struct_ov017_021ce704 unknown_1c_; };
#endif
#if defined(jpn)
struct Struct_ov000_02179cdc_3 { char unknown_0_[0x80]; Struct_ov017_021ce704_2 unknown_100_; };
#else
struct Struct_ov000_02179cdc_3 { char unknown_0_[0x100]; Struct_ov017_021ce704_2 unknown_100_; };
#endif
static inline Struct_ov017_021ce704_2* inline_ov017_021ce704(Struct_ov000_02179cdc_3* arg0) { return &arg0->unknown_100_; }
static inline Struct_ov017_021ce704* inline_ov017_021ce704_2(Struct_ov017_021ce704_2* arg0) { return &arg0->unknown_1c_; }
struct Struct_ov017_021ce704_4 {
    Struct_ov017_021ce704_3 unknown_0_[3];
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 3;
};
struct StatsMessage { unsigned char type; unsigned char pad1[3]; unsigned int payload[4]; };
void* LinkMessageQueue_GetInstance();
PartyStats* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021ce704
extern "C" ARM void func_ov017_021ce704(int index) {
    void* context = LinkMessageQueue_GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), index);
    if (!combatant) return;
    PartyStats* stats = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (!stats) return;
    StatsMessage message;
    message.type = 0x12;
    StatsPayload* payload = (StatsPayload*)message.payload;
    payload->values[0].first = stats->region.stats.values[0].first;
    payload->values[0].second = stats->region.stats.values[0].second;
    payload->values[0].third = stats->region.stats.values[0].third;
    StatBlock* block = GetStatBlock(GetStatRegion(stats));
    payload->values[1].first = block->values[1].first;
    payload->values[1].second = block->values[1].second;
    payload->values[1].third = block->values[1].third;
    payload->values[2].first = block->values[2].first;
    payload->values[2].second = block->values[2].second;
    payload->values[2].third = block->values[2].third;
    payload->finalValue = block->finalValue;
    payload->partyIndex = index;
    func_0205e330(context, &message, 0);
}
