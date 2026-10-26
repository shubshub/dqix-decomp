#include <globaldefs.h>

#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"

extern "C" void *Zone3D_GetInstance(void);
struct Struct_02053f4c;
extern "C" void func_02053f4c(CombatantRecovery*, int, int);
extern "C" void func_02053f6c(void *, unsigned char);
extern "C" int ZoneId_IsGrottoBossFloor(int);

// One entry of the map's zone list (the map script builds it): its zones, and for a type other than 0 the point
// where members in those zones are drawn and the group id their icons share
struct Node02021f88 {
    unsigned char type;
    unsigned char id;
    unsigned char zoneCount;
    unsigned char pad3;
    short *zoneIds;
    int x;
    int y;
    struct Node02021f88 *next;
};

// The MapDisplay fields this uses (header field754 and the byte at 0xa96)
struct Struct_02026bdc {
#if defined(jpn)
    char pad0[0x6a8];
#else
    char pad0[0x754];
#endif
    Node02021f88 *zoneList;
#if defined(jpn)
    char unknown_6ac_[0x9ca - 0x6ac];
#else
    char unknown_758_[0xa96 - 0x758];
#endif
    unsigned char recheckMembers; // MapDisplay_RecheckMember, MapDisplay_RecheckAllMembers
};

enum {
    kShipWorldZoneId = 10000,       // the world map zones FieldTask_BoardVehicle sends the ship (10000) and the
    kStarflightWorldZoneId = 10100, // Starflight (10100) to
    kFirstExactZoneId = 20000,      // there, zone ids outside 20000-29999 match by the hundred
    kLastExactZoneId = 29999,
    kObjectFlag1000 = 0x1000,       // obj3D_.unknown_0_; such members get no icon on the world map
    kRecoveryOnMap = 8,             // recoveryFlags: MapDisplay_CollectIcons gives the member an icon
    kRecoveryAtListPoint = 0x10,    // recoveryFlags: the icon goes at the zone list entry's point (x, y, group id)
};

// USA: MapDisplay_PlaceMembers
// For each party member whose recheck bit is set, finds the zone list entry holding its zone and sets its icon
// flags (clearRecheck clears the bit)
// Main, originally func_02026bdc (USA 0x02026bdc, EUR 0x02026bec, JPN 0x02026540)
extern "C" ARM void MapDisplay_PlaceMembers(void *object, int clearRecheck) {
    Struct_02026bdc *state = static_cast<Struct_02026bdc *>(object);
    GameState *gameState             = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        if (gameState->GetGameObjectByIndex(i) == 0) {
            continue;
        }
        if ((state->recheckMembers & (1 << i)) == 0) {
            continue;
        }
        GetGameResources();
        CombatantRecovery *member = static_cast<CombatantRecovery *>(func_0200ff1c(gameState, i));
        if (member == 0) {
            continue;
        }
        Zone3D *zone = static_cast<Zone3D *>(Zone3D_GetInstance());
        if (&zone->substruct_c_ == 0 || zone->pUnknownStruct_8_ == 0) {
            return;
        }
        if ((member->obj3D_.unknown_0_ & kObjectFlag1000) != 0) {
            if (zone->currentZoneID_ == kShipWorldZoneId || zone->currentZoneID_ == kStarflightWorldZoneId) {
                member->recoveryFlags &= ~kRecoveryOnMap;
                continue;
            }
        }
        Node02021f88 *node;
        int found = 0;
        if (clearRecheck != 0) {
            state->recheckMembers &= ~(1 << i);
        }
        node      = state->zoneList;
        int memberZoneId = member->obj3D_.GetField06();
        if (zone->currentZoneID_ == kShipWorldZoneId || zone->currentZoneID_ == kStarflightWorldZoneId) {
            if (memberZoneId < kFirstExactZoneId || memberZoneId > kLastExactZoneId) {
                memberZoneId = memberZoneId / 100 * 100;
            }
            while (node != 0 && found == 0) {
                for (int j = 0; j < node->zoneCount && found == 0; j++) {
                    int listedZoneId = static_cast<unsigned short>(node->zoneIds[j]);
                    if (listedZoneId < kFirstExactZoneId || listedZoneId > kLastExactZoneId) {
                        listedZoneId = listedZoneId / 100 * 100;
                    }
                    if (listedZoneId == memberZoneId) {
                        member->recoveryFlags |= kRecoveryOnMap;
                        if (node->type == 0) {
                            member->recoveryFlags &= ~kRecoveryAtListPoint;
                        } else {
                            member->recoveryFlags |= kRecoveryAtListPoint;
                            func_02053f4c(member, node->x, node->y);
                            func_02053f6c(member, node->id);
                        }
                        found = 1;
                    }
                }
                node = node->next;
            }
        } else if (ZoneId_IsGrottoBossFloor(memberZoneId) != 0) {
            GameObject *leader = gameState->GetLeader();
            if (leader != 0) {
                int leaderZoneId = leader->obj3D_.GetField06();
                if (leaderZoneId == memberZoneId) {
                    member->recoveryFlags |= kRecoveryOnMap;
                    member->recoveryFlags &= ~kRecoveryAtListPoint;
                    found = 1;
                }
            }
        } else {
            while (node != 0 && found == 0) {
                for (int j = 0; j < node->zoneCount && found == 0; j++) {
                    if (memberZoneId == static_cast<unsigned short>(node->zoneIds[j])) {
                        member->recoveryFlags |= kRecoveryOnMap;
                        if (node->type == 0) {
                            member->recoveryFlags &= ~kRecoveryAtListPoint;
                        } else {
                            member->recoveryFlags |= kRecoveryAtListPoint;
                            func_02053f4c(member, node->x, node->y);
                            func_02053f6c(member, node->id);
                        }
                        found = 1;
                    }
                }
                node = node->next;
            }
        }
        if (found == 0) {
            member->recoveryFlags &= ~kRecoveryOnMap;
        }
    }
}
