#include <globaldefs.h>

#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"

struct FlagWord02046708;
void *GlobalFlags_GetInstance();
int FlagWord_TestBits(FlagWord02046708 *word, unsigned int mask);
void MapDisplay_DrawSprite(void *receiver, int x, int y, int spriteIndex, unsigned char oamSlot, unsigned char priority,
                              unsigned short palette, unsigned char matrixIndex, int scaleX, int scaleY);

// The battles already marked this frame; data_020e7064 is {-1, -1, -1, -1}
struct MarkedBattleList {
    int values[4];
};

extern const MarkedBattleList data_020e7064;

enum {
    kBattleMarkerSprite = 8,
    kBattleMarkerOamSlotBase = 0x54, // + the party index
};

struct MapDisplayBlinkPrefix {
    unsigned char unknown0[0x38];
    fix32_t scale;
#if defined(jpn)
    unsigned char unknown3c[0x914 - 0x3c];
#else
    unsigned char unknown3c[0x9c0 - 0x3c];
#endif
    unsigned char blinkPhase; // MapDisplay_UpdateBlink: 0 for 500 ms, then 1 until 1200 ms
};

// The battle a party member is in, 0 if none: at its end FieldTask_Battle clears it on every member whose id
// matches the leader's, and func_ov017_0219ad84 draws a field marker over members that have one
struct PartyMemberBattlePrefix {
#if defined(jpn)
    unsigned char unknown0[0x1a6];
#else
    unsigned char unknown0[0x1b2];
#endif
    unsigned short battleId;
};

// On the members in a battle (one per battle), draws the battle marker over their icon, in the blink phase when
// MapIcon_IsShownInBlinkPhase hides the icon itself
// Main, originally func_02023d84 (USA 0x02023d84, EUR 0x02023d94, JPN 0x0202374c)
extern "C" ARM void MapDisplay_DrawBattleMarkers(void *receiver, CombatActionPosition *entries, int count, int originX, int originY, int xOffset,
                                  int yOffset, int useHeight) {
    MapDisplayBlinkPrefix *state = static_cast<MapDisplayBlinkPrefix *>(receiver);
    if (!state->blinkPhase) return;
    MarkedBattleList markedBattles = data_020e7064;
    unsigned char markedCount       = 0;
    GameState *game                 = GameState::GetInstance();
    GameObject *protagonist         = game->GetProtagonist();
    if (!protagonist) return;
    FlagWord02046708 *word = static_cast<FlagWord02046708 *>(GlobalFlags_GetInstance());
    for (int partyIndex = 0; partyIndex < 4; partyIndex++) {
        GameObject *member = game->GetPartyMemberByIndex(partyIndex);
        if (!member) continue;
        unsigned short battleId = reinterpret_cast<PartyMemberBattlePrefix *>(member)->battleId;
        if (!battleId) continue;
        if (FlagWord_TestBits(word, 0x80000)) continue;
        if (protagonist->obj3D_.GetField06() != member->obj3D_.GetField06()) continue;
        bool unique = true;
        for (int index = 0; index < markedCount; index++) {
            if (battleId == markedBattles.values[index]) unique = false;
        }
        if (!unique) continue;
        markedBattles.values[markedCount] = battleId;
        markedCount++;
        CombatActionPosition *entry = entries;
        for (int index = 0; index < count; index++, entry++) {
            if (partyIndex != entry->combatantId) continue;
            fix32_t scale = state->scale;
            int x         = static_cast<int>(static_cast<float>(FIX32_MULTIPLY(entry->position.x, scale)) / 4096.0f) - originX;
            int y         = static_cast<int>(static_cast<float>(FIX32_MULTIPLY(entry->position.z, scale)) / 4096.0f) - originY;
            if (useHeight) {
                y = -(static_cast<int>(static_cast<float>(FIX32_MULTIPLY(entry->position.y, scale)) / 4096.0f) - originY);
            }
            MapDisplay_DrawSprite(receiver, (x + xOffset - 1) << 12, (y + yOffset - 1) << 12, kBattleMarkerSprite,
                                     static_cast<unsigned char>(partyIndex + kBattleMarkerOamSlotBase), 0, 0xff, 0xff, 0x1000, 0x1000);
        }
    }
}
