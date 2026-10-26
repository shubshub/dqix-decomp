#include <globaldefs.h>
#include "Combat/CombatantDisplay.h"
// MapDisplay::flags758 (member id per panel row), field75c (row count), field75d (members whose panel is not drawn)
#if defined(jpn)
enum { kMemberIdsOffset = 0x6ac, kRowCountOffset = 0x6b0, kHiddenMaskOffset = 0x6b1 };
#else
enum { kMemberIdsOffset = 0x758, kRowCountOffset = 0x75c, kHiddenMaskOffset = 0x75d };
#endif
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

enum { kPanelWidth = 64, kPanelSpriteOamSlot = 0x3c, kNoAffineMatrix = 0xff, kScaleOne = 0x1000 };

extern "C" void OamManager_GetInstance(void);
extern "C" int func_02053c6c(unsigned char* member);
extern "C" void MapDisplay_DrawSprite(void* display, int x, int y, int spriteIndex,
        unsigned char oamSlot, unsigned char priority, unsigned short palette, unsigned char matrixIndex, int scaleX, int scaleY);
extern Display0201fdd0 data_020fdc60[];
extern int data_020fdcb0;

// Main, originally ProcessCombatantElements02027100 (USA 0x02027100, EUR 0x02027110, JPN 0x02026a64)
extern "C" ARM void MapDisplay_DrawMemberPanels(unsigned char* display) {
    GameState* gameState = GameState::GetInstance();
    OamManager_GetInstance();
    ((int)GetGameResources());
    for (int row = 0; row < display[kRowCountOffset]; row++) {
        unsigned char* rowIds = display + row;
        int memberId = rowIds[kMemberIdsOffset];
        if (display[kHiddenMaskOffset] & (1 << memberId)) {
            continue;
        }
        GameObject* member = func_0200ff1c(gameState, memberId);
        if (member == NULL) {
            continue;
        }
        if (func_02053c6c((unsigned char*)member) == 0) {
            continue;
        }
        if (*(int*)((char*)&data_020fdcb0 + (memberId << 5)) < 0) {
            continue;
        }
        Display0201fdd0* panel = &data_020fdc60[row];
        MapDisplayMemberPanel_DrawHp(panel, row, memberId);
        MapDisplayMemberPanel_DrawMp(panel, row, memberId);
        int panelY = (int)panel->y;
        MapDisplay_DrawSprite(display, (row * kPanelWidth) << 12, panelY << 12, (memberId + 1) & 0xff,
            (memberId + kPanelSpriteOamSlot) & 0xff, 0, (unsigned short)memberId, kNoAffineMatrix, kScaleOne, kScaleOne);
    }
}
