#include <globaldefs.h>
#include "GameState/GameState.h"
struct Struct_ov017_021cf730_2 {
    unsigned short zone_; unsigned char unknown_2_;
    union {
        unsigned char flags_;
        struct { unsigned char active_ : 1; unsigned char unknown_ : 1; unsigned char refresh_ : 1; signed char player_ : 5; } bits_;
    } control_;
    unsigned char unknown_4_; unsigned char level_; unsigned short unknown_6_;
    unsigned short x_; unsigned short y_; unsigned short unknown_c_; signed char unknown_e_;
    union { unsigned char unknown_0_; struct { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; } bits_; } unknown_f_;
};

struct Struct_ov017_021cf730 { char pad[0xc]; int zone; };
extern "C" int* LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsGuest(int*);
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021cf730
extern "C" ARM void func_ov017_021cf730(signed char player, unsigned char arg1) {
    int* control = LinkSession_GetInstance();
    if (!LinkSession_IsActive(control) || LinkSession_IsGuest(control)) return;
    GameState* state = GameState::GetInstance();
    void* destination = LinkMessageQueue_GetInstance();
    unsigned char buffer[0x14];
    Struct_ov017_021cf730_2* packet = (Struct_ov017_021cf730_2*)(buffer + 4);
    GrottoStruct* grotto = state->GetGrottoStruct();
    buffer[0] = 0xa0;
    packet->zone_ = ((Struct_ov017_021cf730*)grotto)->zone;
    packet->unknown_2_ = grotto->activeMapData.DiscoveryStateAndMapTypeAndUnknown;
    packet->control_.bits_.active_ = grotto->unknown_0[0] != 0;
    packet->control_.bits_.refresh_ = arg1;
    packet->x_ = grotto->entranceX >> 7;
    packet->y_ = grotto->entranceY >> 7;
    packet->unknown_c_ = grotto->entranceZ >> 7;
    packet->unknown_4_ = grotto->activeMapData.QualityOrLegacyBossID;
    packet->level_ = grotto->activeMapData.LegacyBossLevel;
    packet->unknown_6_ = grotto->activeMapData.SeedOrMinTurns;
    packet->unknown_f_.bits_.unknown_0_0_ = grotto->activeStartingMonsterRank;
    packet->unknown_f_.bits_.unknown_0_4_ = grotto->activeEnviron;
    packet->unknown_e_ = *((signed char*)grotto + 8);
    packet->control_.bits_.player_ = player;
    func_0205e330(destination, buffer, 0);
}
