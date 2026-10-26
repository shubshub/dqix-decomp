#include <globaldefs.h>
#include "Combat/CombatantDisplay.h"

// Where the HP number and gauge sit on a member's panel (MapDisplay_RefreshMemberPanel draws the "HP" label at y 0xe and the
// gauge box from y 0x10 to 0x18), the gauge's fill and frame sprites, and the gauge index
#if defined(jpn)
enum { kHpBarY = 0x19 };
#else
enum { kHpBarY = 0x18 };
#endif
enum { kDigitX = 0x30, kHpDigitY = 0x10, kBarX = 7, kHpFillSprite = 9, kHpFrameSprite = 0xa, kHpGauge = 0 };

#include "GameState/GameState.h"

// One party member's entry in the status snapshot table data_020fdcb0 (MapDisplay_Update fills it)
struct MapDisplayMemberStatus {
    int hp;
    int mp;
    int maxHp;
    int maxMp;
    int unk10[4];
};

extern struct MapDisplayMemberStatus data_020fdcb0[];

// Main, originally SubmitFlag0x800CombatantDataA0201fca0 (USA 0x0201fca0, EUR 0x0201fcb0, JPN 0x0201f9c4)
ARM void MapDisplayMemberPanel_DrawHp(Display0201fdd0* panel, int row, int memberId) {
    if (GameState::GetInstance()->GetPartyMemberByIndex(memberId) != NULL) {
        struct MapDisplayMemberStatus* status = &data_020fdcb0[memberId];
        int hp = status->hp;
        if (hp >= 0) {
            MapDisplayMemberPanel_DrawStat(panel, row, memberId, hp, status->maxHp, kDigitX, kHpDigitY, kBarX, kHpBarY, kHpFillSprite, kHpFrameSprite, kHpGauge);
        }
    }
}
