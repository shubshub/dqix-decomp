#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "Combat/CombatantRecovery.h"
#include "Combat/MapDisplay.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"


struct Member020236dc : CombatantRecovery {
    unsigned char padding190[0x1b2 - 0x190];
    unsigned short field1b2;
};
struct Node02021f88 {
    unsigned char type;
    unsigned char id;
    unsigned char count;
    unsigned char pad3;
    short* data;
    int x;
    int y;
    Node02021f88* next;
};
struct Container02021394;
struct SaveFlags020236dc {
    unsigned char padding[0x8c];
    unsigned char flags[1];
};
struct FlagWord02046708;
struct S3f58;
extern "C" void* Zone3D_GetInstance();
extern "C" void* LinkSession_GetInstance();
extern "C" void* Scenario_GetInstance();
void* GlobalFlags_GetInstance();
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
int FlagWord_TestBits(FlagWord02046708*, unsigned int);
void GetFields1a8And1ac_02053f58(S3f58*, int*, int*);
unsigned char GetField0x1b0_02053f74(void*);
int GameState_GetProtagonistIndex(GameState*);
int GameObject_GetLinePosition(void*);
int Scenario_TestFlag(int, unsigned char*, int);
int MapDisplay_FindShipPosition(Container02021394*, int, int, short*, short*);
#if defined(jpn)
#define data_020e704c data_020e78e8
#endif
// 4100, 4300, 4500, 6401, 0: Zone3D::unknown_4_ values where members with object flag 0x1000 get no icon
extern unsigned short data_020e704c[];

struct IconList_020236dc {
    CombatActionPosition* entries;
    int count;
};

// The icons' sprites (MapDisplay::records), palettes and OAM slots (CombatActionPosition elementId, palette, type;
// MapDisplay_DrawSprite writes the sprite into OAM from that slot)
enum {
    kMemberSprite = 5,
    kMemberPaletteBase = 4,     // + the member's actorIndex_
    kDeadMemberSprite = 6,      // savedState flags bit 0, which heals skip (func_ov017_0218d2f0)
    kDeadMemberPalette = 6,
    kHeroOamSlotBase = 0x58,       // + the party object's byte +0x1c9
    kMemberOamSlotBase = 0x5b,     // + actorIndex_
    kShipSprite = 0x1b,
    kShipPalette = 7,
    kShipOamSlot = 0x74,           // the first OAM slot IsNonCombatantAction counts as not a party member
};

// USA: MapDisplay_CollectIcons
// Fills entries with the map icons (the party members on this map, then the ship) and returns how many.
// groupCounts counts the members drawn at each zone list point (by its id); heroPosition gets that point when the
// hero is drawn at one.
// Main, originally func_020236dc (USA 0x020236dc, EUR 0x020236ec, JPN 0x020230a4)
extern "C" ARM int MapDisplay_CollectIcons(CombatActionPosition* entries, unsigned char* groupCounts, Vector3i* heroPosition) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    GameObject* protagonist = game->GetProtagonist();
    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    LinkSession_GetInstance();
    SaveFlags020236dc* scenario = (SaveFlags020236dc*)Scenario_GetInstance();
    FlagWord02046708* globalFlags = (FlagWord02046708*)GlobalFlags_GetInstance();
    Container02021394* shipPositions = (Container02021394*)resources->unknown_ptr_36d0;
    IconList_020236dc icons;
    icons.entries = entries;
    icons.count = 0;
    for (int i = 0; i < 4; ++i) {
        Member020236dc* member = (Member020236dc*)GetCombatantWithFlag0x100_0200ff1c(game, i);
        if (!member || !(member->recoveryFlags & 8)) continue; // MapDisplay_PlaceMembers: the member is on this map
        if (GetCombatantWithFlag0x1000_0200ff58(game, i)) {
            unsigned char index = 0;
            unsigned short zoneValue = zone->unknown_4_;
            int excluded = 0;
            for (; data_020e704c[index]; ++index) {
                if (zoneValue == data_020e704c[index]) {
                    excluded = 1;
                    break;
                }
            }
            if (excluded) continue;
        }
        CombatActionPosition* entry = &icons.entries[icons.count];
        entry->combatantId = i;
        ++icons.count;
        entry->flag11 = member->field1b2 && !FlagWord_TestBits(globalFlags, 0x80000) ? 1 : 0;
        entry->flag12 = protagonist ? protagonist->obj3D_.GetField06() == member->obj3D_.GetField06() : 0;
        if (member->recoveryFlags & 0x10) { // MapDisplay_PlaceMembers: drawn at its zone list entry's point
            GetFields1a8And1ac_02053f58((S3f58*)member, &entry->position.x, &entry->position.z);
            entry->group = GetField0x1b0_02053f74(member);
            entry->variant = groupCounts[entry->group];
            ++groupCounts[entry->group];
            if (i == GameState_GetProtagonistIndex(game)) {
                heroPosition->x = entry->position.x;
                heroPosition->z = entry->position.z;
            }
        } else {
            Vector3i memberPosition = member->obj3D_.position_;
            entry->position.x = memberPosition.x;
            entry->position.y = memberPosition.y;
            entry->position.z = memberPosition.z;
            entry->variant = -1;
        }
        entry->elementId = kMemberSprite;
        entry->palette = member->obj3D_.actorIndex_ + kMemberPaletteBase;
        GameObject* party = game->GetPartyMemberByIndex(i);
        GameObject* active = GetCombatantWithFlag0x1000_0200ff58(game, i);
        if (party && (member->obj3D_.actorIndex_ == 0 || active)) entry->type = GameObject_GetLinePosition(party) + kHeroOamSlotBase;
        else entry->type = member->obj3D_.actorIndex_ + kMemberOamSlotBase;
        if (party) entry->flag13 = GameObject_GetLinePosition(party);
        if (member->combatFields_.savedState_130_->flags & 1) {
            entry->elementId = kDeadMemberSprite;
            entry->palette = kDeadMemberPalette;
        }
    }
    // The ship (saved at Zone3D::savedActor_), when its zone is in this map's zone list
    int shipOnMap = 0;
    MapDisplay* mapDisplay = GetGameResources()->unknown_ptr_36d0;
    if (mapDisplay) {
        for (Node02021f88* node = mapDisplay->field754; node; node = node->next) {
            for (int i = 0; i < node->count; ++i) {
                int listedZoneId = (unsigned short)node->data[i];
                int shipZoneId = zone->savedActor_.zoneId;
                if (listedZoneId == shipZoneId) {
                    shipOnMap = 1;
                    break;
                }
            }
        }
    }
    if (shipOnMap && Scenario_TestFlag((int)scenario, scenario->flags, 0x2b)) {
        short x = 0;
        short z = 0;
        if (MapDisplay_FindShipPosition(shipPositions, zone->savedActor_.zoneId, (unsigned char)zone->savedActor_.nodeId, &x, &z)) {
            CombatActionPosition* entry = &icons.entries[icons.count];
            ++icons.count;
            VectorizedMemset(entry, 0, sizeof(*entry));
            entry->variant = -1;
            entry->combatantId = 0xff;
            entry->position.x = x << 12;
            entry->position.z = z << 12;
            entry->elementId = kShipSprite;
            entry->palette = kShipPalette;
            entry->type = kShipOamSlot;
        }
    }
    return icons.count;
}
