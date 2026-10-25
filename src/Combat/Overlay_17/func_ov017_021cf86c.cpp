#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0202c1a4;
struct Struct_02038598_5;
struct Struct_02015438;
struct Struct_020113e0;
struct Struct_ov017_021cf730_2 {
    char unknown_0_[4]; unsigned short unknown_4_; unsigned char unknown_6_;
    union {
        unsigned char unknown_0_;
        struct { unsigned char unknown_0_0_ : 1; unsigned char unknown_0_1_ : 1; unsigned char unknown_0_2_ : 1; signed char unknown_0_3_ : 5; } unknown1_0_;
    } unknown_7_;
    unsigned char unknown_8_; unsigned char unknown_9_; unsigned short unknown_a_;
    unsigned short unknown_c_; unsigned short unknown_e_; unsigned short unknown_10_; unsigned char unknown_12_;
    union { unsigned char unknown_0_; struct { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; } unknown1_0_; } unknown_13_;
};
struct Struct_ov017_021cf86c_4 {
    char unknown_0_[0x39]; unsigned char unknown_39_;
    unsigned short unknown_3a_; unsigned char unknown_3c_; unsigned char unknown_3d_;
    unsigned char unknown_3e_; unsigned char unknown_3f_; unsigned short unknown_40_;
    short unknown_42_; short unknown_44_; short unknown_46_; unsigned char unknown_48_; unsigned char unknown_49_;
};
struct Struct_ov017_021cf86c {
#if defined(jpn)
    char unknown_0_[0x34ec]; Struct_02038598_5* unknown_36fc_;
#else
    char unknown1_0_[0x36fc]; Struct_02038598_5* unknown_36fc_;
#endif
#if defined(jpn)
    char unknown_34f0_[0x3a84 - 0x34f0]; Struct_ov017_021cf86c_4* unknown_3ca4_;
#else
    char unknown_3700_[0x3ca4 - 0x3700]; Struct_ov017_021cf86c_4* unknown_3ca4_;
#endif
};
#if defined(jpn)
struct Struct_ov017_021cf86c_2 { char unknown_0_[0x26a4]; char unknown_2664_[4]; };
#else
struct Struct_ov017_021cf86c_2 { char unknown_0_[0x2664]; char unknown_2664_[4]; };
#endif
struct GrottoZoneStorage { char pad0[0xc]; int zone_; };
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" WorldSettings* Zone3D_GetInstance();
void* GetField0x3f8Address_0200fd0c(GameState*);
int ListContainsId(ListHead02046b60*, int);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" void func_0208f748(void*, int);
extern "C" void func_020113e0(Struct_020113e0*);
extern "C" int func_0201b588(int);

// USA: func_ov017_021cf86c
extern "C" ARM void func_ov017_021cf86c(void*, GrottoPacket* packet, GameState* state, GrottoOverlay* overlay, SearchStruct0202c1a4* search) {
    if (packet->control_.bits_.player_ >= 0 && GetSearchStructCurrentArrEntry(search) != packet->control_.bits_.player_) return;
    WorldSettings* settings = Zone3D_GetInstance();
    GrottoStruct* grotto;
    ListHead02046b60* list = overlay->list_;
    GetField0x3f8Address_0200fd0c(state);
    grotto = state->GetGrottoStruct();
    if (ListContainsId(list, 0x4e)) {
        PendingGrotto* pending = overlay->pending_;
        pending->zone_ = packet->zone_;
        pending->mapState_ = packet->mapState_;
        pending->flags_ = packet->control_.flags_;
        pending->quality_ = packet->quality_;
        pending->level_ = packet->level_;
        pending->seed_ = packet->seed_;
        pending->x_ = packet->x_;
        pending->y_ = packet->y_;
        pending->z_ = packet->z_;
        pending->field48_ = packet->field12_;
        pending->ranks_ = packet->ranks_.raw_;
        pending->pending_ = 1;
    } else {
        ((Struct_ov017_021cf86c_3*)var1)->unknown_c_ = arg1->unknown_4_;
        var1->activeMapData.DiscoveryStateAndMapTypeAndUnknown = arg1->unknown_6_;
        var1->unknown_0[0] = arg1->unknown_7_.unknown1_0_.unknown_0_0_ != 0;
        var1->entranceX = (short)arg1->unknown_c_ << 7;
        var1->entranceY = (short)arg1->unknown_e_ << 7;
        var1->entranceZ = (short)arg1->unknown_10_ << 7;
        var1->activeMapData.QualityOrLegacyBossID = arg1->unknown_8_;
        var1->activeMapData.LegacyBossLevel = arg1->unknown_9_;
        var1->activeMapData.SeedOrMinTurns = arg1->unknown_a_;
        var1->activeStartingMonsterRank = arg1->unknown_13_.unknown1_0_.unknown_0_0_;
        var1->activeEnviron = arg1->unknown_13_.unknown1_0_.unknown_0_4_;
        var1->unknown_8 = arg1->unknown_12_;
        var1->unknown_0[1] = 0;
    }
    if (var1->unknown_0[0] && (var1->activeMapData.GetDiscoveryState() == 2 || var1->activeMapData.GetDiscoveryState() == 3)) {
        if (((Struct_ov017_021cf86c_3*)var1)->unknown_c_ == arg2->GetProtagonist()->obj3D_.GetField06() && func_02046b24((Struct_02015438**)var2) != 10) {
            func_0208f748(var0->unknown_2664_, 0);
        }
    }
    if (var1->unknown_0[0] && arg1->unknown_7_.unknown1_0_.unknown_0_2_ && (var1->activeMapData.GetDiscoveryState() == 2 || var1->activeMapData.GetDiscoveryState() == 3)) func_020113e0((Struct_020113e0*)arg2);
    if (func_0201b588(arg2->GetPartyMemberByIndex(0)->obj3D_.GetField06()) && arg1->unknown_7_.unknown1_0_.unknown_0_2_) func_020113e0((Struct_020113e0*)arg2);
}
