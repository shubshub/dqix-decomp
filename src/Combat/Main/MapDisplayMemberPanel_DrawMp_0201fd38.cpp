#include <globaldefs.h>
#include "Combat/CombatantDisplay.h"

// Where the MP number and gauge sit on a member's panel (MapDisplay_RefreshMemberPanel draws the "MP" label at y 0x1a and the
// gauge box from y 0x1c to 0x24), the gauge's fill and frame sprites, and the gauge index
#if defined(jpn)
enum { kMpDigitY = 0x1d, kMpBarY = 0x26 };
#else
enum { kMpDigitY = 0x1c, kMpBarY = 0x24 };
#endif
enum { kDigitX = 0x30, kBarX = 7, kMpFillSprite = 0xb, kMpFrameSprite = 0xc, kMpGauge = 1 };

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

// Main, originally SubmitFlag0x800CombatantDataB0201fd38 (USA 0x0201fd38, EUR 0x0201fd48, JPN 0x0201fa5c)
ARM void MapDisplayMemberPanel_DrawMp(Display0201fdd0* panel, int row, int memberId) {
    if (GameState::GetInstance()->GetPartyMemberByIndex(memberId) != NULL) {
        struct MapDisplayMemberStatus* status = &data_020fdcb0[memberId];
        int mp = status->mp;
        if (mp >= 0) {
            MapDisplayMemberPanel_DrawStat(panel, row, memberId, mp, status->maxMp, kDigitX, kMpDigitY, kBarX, kMpBarY, kMpFillSprite, kMpFrameSprite, kMpGauge);
        }
    }
}
