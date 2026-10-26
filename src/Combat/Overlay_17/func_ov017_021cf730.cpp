#include <globaldefs.h>
#include "GameState/GameState.h"
struct Struct_ov017_021cf730_2 {
    unsigned short unknown_0_; unsigned char unknown_2_;
    union {
        unsigned char unknown_0_;
        struct { unsigned char unknown_0_0_ : 1; unsigned char unknown_0_1_ : 1; unsigned char unknown_0_2_ : 1; signed char unknown_0_3_ : 5; } unknown1_0_;
    } unknown_3_;
    unsigned char unknown_4_; unsigned char unknown_5_; unsigned short unknown_6_;
    unsigned short unknown_8_; unsigned short unknown_a_; unsigned short unknown_c_; signed char unknown_e_;
    union { unsigned char unknown_0_; struct { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; } unknown1_0_; } unknown_f_;
};

struct ZoneWord { char pad[0xc]; int zone; };
extern "C" int* LinkSession_GetInstance();
int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsGuest(int*);
void* LinkMessageQueue_GetInstance();
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021cf730
extern "C" ARM void func_ov017_021cf730(signed char player, unsigned char refresh) {
    int* control = LinkSession_GetInstance();
    if (!LinkSession_IsActive(control) || LinkSession_IsGuest(control)) return;
    GameState* state = GameState::GetInstance();
    void* destination = LinkMessageQueue_GetInstance();
    unsigned char buffer[0x14];
    GrottoPacket* packet = (GrottoPacket*)(buffer + 4);
    GrottoStruct* grotto = state->GetGrottoStruct();
    buffer[0] = 0xa0;
    packet->zone_ = ((ZoneWord*)grotto)->zone;
    packet->mapState_ = grotto->activeMapData.DiscoveryStateAndMapTypeAndUnknown;
    packet->control_.bits_.active_ = grotto->unknown_0[0] != 0;
    packet->control_.bits_.refresh_ = refresh;
    packet->x_ = grotto->entranceX >> 7;
    packet->y_ = grotto->entranceY >> 7;
    packet->z_ = grotto->entranceZ >> 7;
    packet->quality_ = grotto->activeMapData.QualityOrLegacyBossID;
    packet->level_ = grotto->activeMapData.LegacyBossLevel;
    packet->seed_ = grotto->activeMapData.SeedOrMinTurns;
    packet->ranks_.bits_.rank_ = grotto->activeStartingMonsterRank;
    packet->ranks_.bits_.environment_ = grotto->activeEnviron;
    packet->field12_ = *((signed char*)grotto + 8);
    packet->control_.bits_.player_ = player;
    func_0205e330(destination, buffer, 0);
}
