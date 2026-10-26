#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#include "Combat/CombatantRecovery.h"
#include "GameState/PartyMember.h"

// What a party member's status panel last showed (data_020fdcb0, one per party member). stateChanged makes
// func_02026f34 redraw the panel (MapDisplay_RefreshMemberPanel); MapDisplay_SetPartyOrder sets reset for the members it lists.
struct State_1f9b8 {
    int hp;
    int mp;
    int maxHP;
    int maxMP;
    int vocation;
    unsigned char level;
    unsigned char unknown_15_[3];
    int status;
    unsigned char statsChanged;
    unsigned char stateChanged;
    unsigned char reset;
    unsigned char unknown_1f_;
};
struct Struct_020fdc60_3 { unsigned char fields[0x14]; };
struct PartyMember02022dc8 : GameObject {
#if defined(jpn)
    unsigned char unknown_13c_[0x144 - 0x13c];
#else
    unsigned char unknown1_13c_[0x150 - 0x13c];
#endif
    PartyMemberData* memberData;
    unsigned char unknown_154_[0x38];
    unsigned int recoveryFlags;
};
struct FlagWord02046708;
struct Obj020214f0;
extern State_1f9b8 data_020fdcb0[4];
extern Struct_020fdc60_3 data_020fdc60[4];
extern "C" void MapDisplayPanelStatus_Reset(State_1f9b8*);
extern "C" void func_0201f9e8(Struct_020fdc60_3*);
extern "C" unsigned short GameObject_GetPartyMemberLevel(void*); // the member's level in its current vocation
extern "C" FlagWord02046708* GlobalFlags_GetInstance(void);
extern "C" int FlagWord_TestBits(FlagWord02046708*, unsigned int);
#if defined(jpn)
extern "C" void MapDisplay_CancelLoading(MapDisplay*);
#else
extern "C" void MapDisplay_CancelLoading(MapDisplay*);
#endif
extern "C" void func_020e0688(MapDisplay*);
extern "C" void MapDisplay_LoadRedChests(MapDisplay*);
extern "C" void MapDisplay_RunModeLoader(Obj020214f0*);
extern "C" void MapDisplay_PlaceMembers(MapDisplay*, int);

// Main, originally func_02022dc8 (USA 0x02022dc8, EUR 0x02022dd8, JPN 0x02022848)
extern "C" ARM void MapDisplay_Update(MapDisplay* self) {
    GameState* game = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        if (!game->GetPartyMemberByIndex(i)) MapDisplayPanelStatus_Reset(&data_020fdcb0[i]);
    }
    // The panels follow the party order MapDisplay_SetPartyOrder stored (flags758, count field75c)
    int panelCount = self->field75c;
    if (panelCount) {
        for (int i = panelCount; i < 4; ++i) func_0201f9e8(&data_020fdc60[i]);
    }
    for (int i = 0; i < self->field75c; ++i) {
        int memberIndex = self->flags758[i];
        unsigned char memberBit = 1 << memberIndex;
        State_1f9b8* shown = &data_020fdcb0[memberIndex];
        PartyMember02022dc8* member = (PartyMember02022dc8*)game->GetPartyMemberByIndex(memberIndex);
        if (!member || !(self->mask55d & memberBit)) continue;
        int hp = member->combatFields_.savedState_130_->hp;
        int maxHP = member->baseStats_->primaryStats.maxHP;
        int mp = member->combatFields_.savedState_130_->mp;
        int maxMP = member->baseStats_->primaryStats.maxMP;
        int vocation = member->memberData->vocation_;
        unsigned char level = GameObject_GetPartyMemberLevel(member);
        int status = member->combatFields_.savedState_130_->flags;
        shown->stateChanged |= shown->vocation != vocation;
        shown->stateChanged |= shown->level != level;
        shown->stateChanged |= shown->status != status;
        if (shown->hp >= 0) {
            shown->statsChanged |= shown->stateChanged;
            shown->statsChanged |= shown->hp != hp;
            shown->statsChanged |= shown->mp != mp;
            shown->statsChanged |= shown->maxHP != maxHP;
            shown->statsChanged |= shown->maxMP != maxMP;
        }
        shown->hp = hp;
        shown->mp = mp;
        shown->maxHP = maxHP;
        shown->maxMP = maxMP;
        shown->vocation = vocation;
        shown->level = level;
        shown->status = status;
        if (shown->hp > 0) member->recoveryFlags &= ~1;
        if (shown->reset) {
            shown->statsChanged = 0;
            shown->reset = 0;
        }
    }
    if (FlagWord_TestBits(GlobalFlags_GetInstance(), 1)) {
#if defined(jpn)
        MapDisplay_CancelLoading(self);
#else
        MapDisplay_CancelLoading(self);
#endif
    } else {
        if (self->field9c5 && self->field764) func_020e0688(self);
        if (self->field9b8) MapDisplay_LoadRedChests(self);             // load the red chests (treasure.nsarc)
        if (self->field9c3) MapDisplay_RunModeLoader((Obj020214f0*)self); // a mode is loading
        else MapDisplay_PlaceMembers(self, 1);                                      // which members the map shows
    }
}
