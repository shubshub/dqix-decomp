#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021ce704_3 {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int unused : 2;
};
struct Struct_ov017_021ce704 {
    char pad0[0x800];
    Struct_ov017_021ce704_3 values[3];
    unsigned int unknown_80c_0_ : 10;
};
#if defined(jpn)
struct Struct_ov017_021ce704_2 { char pad0[4]; Struct_ov017_021ce704 stats; };
#else
struct Struct_ov017_021ce704_2 { char pad0[0x1c]; Struct_ov017_021ce704 stats; };
#endif
#if defined(jpn)
struct Struct_ov000_02179cdc_3 { char pad0[0x80]; Struct_ov017_021ce704_2 region; };
#else
struct Struct_ov000_02179cdc_3 { char pad0[0x100]; Struct_ov017_021ce704_2 region; };
#endif
static inline Struct_ov017_021ce704_2* inline_ov017_021ce704(Struct_ov000_02179cdc_3* stats) { return &stats->region; }
static inline Struct_ov017_021ce704* inline_ov017_021ce704_2(Struct_ov017_021ce704_2* region) { return &region->stats; }
struct Struct_ov017_021ce704_4 {
    Struct_ov017_021ce704_3 values[3];
    unsigned int unknown_c_0_ : 10;
    unsigned int partyIndex : 3;
};
struct Struct_ov017_021ce704_5 { unsigned char type; unsigned char pad1[3]; unsigned int payload[4]; };
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" Struct_ov000_02179cdc_3* func_02053c6c(unsigned char*);
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021ce704
extern "C" ARM void func_ov017_021ce704(int index) {
    void* context = LinkMessageQueue_GetInstance();
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), index);
    if (!combatant) return;
    Struct_ov000_02179cdc_3* stats = func_02053c6c((unsigned char*)combatant);
    if (!stats) return;
    Struct_ov017_021ce704_5 message;
    message.type = 0x12;
    Struct_ov017_021ce704_4* payload = (Struct_ov017_021ce704_4*)message.payload;
    payload->values[0].first = stats->region.stats.values[0].first;
    payload->values[0].second = stats->region.stats.values[0].second;
    payload->values[0].third = stats->region.stats.values[0].third;
    Struct_ov017_021ce704* block = inline_ov017_021ce704_2(inline_ov017_021ce704(stats));
    payload->values[1].first = block->values[1].first;
    payload->values[1].second = block->values[1].second;
    payload->values[1].third = block->values[1].third;
    payload->values[2].first = block->values[2].first;
    payload->values[2].second = block->values[2].second;
    payload->values[2].third = block->values[2].third;
    payload->unknown_c_0_ = block->unknown_80c_0_;
    payload->partyIndex = index;
    func_0205e330(context, &message, 0);
}
