#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct ListHead02046b60;
struct HeadNode02046b24;
struct S_020113e0;
struct Struct_ov017_021cf730_2 {
    char pad0[4]; unsigned short zone_; unsigned char unknown_6_;
    union {
        unsigned char flags_;
        struct { unsigned char active_ : 1; unsigned char unknown_ : 1; unsigned char refresh_ : 1; signed char player_ : 5; } bits_;
    } control_;
    unsigned char unknown_8_; unsigned char level_; unsigned short unknown_a_;
    unsigned short x_; unsigned short y_; unsigned short unknown_10_; unsigned char unknown_12_;
    union { unsigned char unknown_0_; struct { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; } bits_; } unknown_13_;
};
struct Struct_ov017_021cf86c_4 {
    char pad0[0x39]; unsigned char unknown_39_;
    unsigned short zone_; unsigned char unknown_3c_; unsigned char flags_;
    unsigned char unknown_3e_; unsigned char level_; unsigned short unknown_40_;
    short x_; short y_; short unknown_46_; unsigned char unknown_48_; unsigned char unknown_49_;
};
struct Struct_ov017_021cf86c {
#if defined(jpn)
    char pad0[0x34ec]; ListHead02046b60* list_;
#else
    char pad0[0x36fc]; ListHead02046b60* list_;
#endif
#if defined(jpn)
    char unknown_34f0_[0x3a84 - 0x34f0]; Struct_ov017_021cf86c_4* unknown_3ca4_;
#else
    char unknown_3700_[0x3ca4 - 0x3700]; Struct_ov017_021cf86c_4* unknown_3ca4_;
#endif
};
#if defined(jpn)
struct WorldSettings { char pad0[0x26a4]; char unknown_2664_[4]; };
#else
struct WorldSettings { char pad0[0x2664]; char unknown_2664_[4]; };
#endif
struct GrottoZoneStorage { char pad0[0xc]; int zone_; };
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" WorldSettings* Zone3D_GetInstance();
extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void func_0208f748(void*, int);
extern "C" void func_020113e0(S_020113e0*);
extern "C" int ZoneId_IsGrotto(int);

// USA: func_ov017_021cf86c
extern "C" ARM void func_ov017_021cf86c(void*, Struct_ov017_021cf730_2* packet, GameState* state, Struct_ov017_021cf86c* overlay, SearchStruct0202c1a4* search) {
    if (packet->control_.bits_.player_ >= 0 && LinkSession_GetOwnSlot(search) != packet->control_.bits_.player_) return;
    WorldSettings* settings = Zone3D_GetInstance();
    GrottoStruct* grotto;
    ListHead02046b60* list = overlay->list_;
    GameState_GetZoneTransition(state);
    grotto = state->GetGrottoStruct();
    if (func_02046b60(list, 0x4e)) {
        Struct_ov017_021cf86c_4* pending = overlay->unknown_3ca4_;
        pending->zone_ = packet->zone_;
        pending->unknown_3c_ = packet->unknown_6_;
        pending->flags_ = packet->control_.flags_;
        pending->unknown_3e_ = packet->unknown_8_;
        pending->level_ = packet->level_;
        pending->unknown_40_ = packet->unknown_a_;
        pending->x_ = packet->x_;
        pending->y_ = packet->y_;
        pending->unknown_46_ = packet->unknown_10_;
        pending->unknown_48_ = packet->unknown_12_;
        pending->unknown_49_ = packet->unknown_13_.unknown_0_;
        pending->unknown_39_ = 1;
    } else {
        ((GrottoZoneStorage*)grotto)->zone_ = packet->zone_;
        grotto->activeMapData.DiscoveryStateAndMapTypeAndUnknown = packet->unknown_6_;
        grotto->unknown_0[0] = packet->control_.bits_.active_ != 0;
        grotto->entranceX = (short)packet->x_ << 7;
        grotto->entranceY = (short)packet->y_ << 7;
        grotto->entranceZ = (short)packet->unknown_10_ << 7;
        grotto->activeMapData.QualityOrLegacyBossID = packet->unknown_8_;
        grotto->activeMapData.LegacyBossLevel = packet->level_;
        grotto->activeMapData.SeedOrMinTurns = packet->unknown_a_;
        grotto->activeStartingMonsterRank = packet->unknown_13_.bits_.unknown_0_0_;
        grotto->activeEnviron = packet->unknown_13_.bits_.unknown_0_4_;
        grotto->unknown_8 = packet->unknown_12_;
        grotto->unknown_0[1] = 0;
    }
    if (grotto->unknown_0[0] && (grotto->activeMapData.GetDiscoveryState() == 2 || grotto->activeMapData.GetDiscoveryState() == 3)) {
        if (((GrottoZoneStorage*)grotto)->zone_ == state->GetProtagonist()->obj3D_.GetField06() && FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)list) != 10) {
            func_0208f748(settings->unknown_2664_, 0);
        }
    }
    if (grotto->unknown_0[0] && packet->control_.bits_.refresh_ && (grotto->activeMapData.GetDiscoveryState() == 2 || grotto->activeMapData.GetDiscoveryState() == 3)) func_020113e0((S_020113e0*)state);
    if (ZoneId_IsGrotto(state->GetPartyMemberByIndex(0)->obj3D_.GetField06()) && packet->control_.bits_.refresh_) func_020113e0((S_020113e0*)state);
}
