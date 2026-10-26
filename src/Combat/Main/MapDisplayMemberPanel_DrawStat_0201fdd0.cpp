#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Combat/CombatantDisplay.h"
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"

// MapDisplay sprite records (MapDisplay_DrawSprite's spriteIndex): the digits 0-9 start here
enum { kDigitSprite0 = 13 };
// OAM slots: each member's digits (3 per member, 12 per gauge), its gauge fills and its gauge frames (8 per gauge)
enum { kDigitOamSlot = 20, kFillOamSlot = 44, kFrameOamSlot = 48 };
enum { kPanelWidth = 64, kDigitWidth = 8, kGaugePalette = 6, kNoAffineMatrix = 0xff, kScaleOne = 0x1000 };
enum { kMinimumFill = 40 };     // a gauge with anything left never shrinks below this 4.12 scale

extern "C" int MapDisplay_GetMemberHpTier(int);
extern "C" void MapDisplay_DrawSprite(void*, int, int, int, unsigned char, unsigned char, unsigned short, unsigned char, int, int);
#if defined(jpn)
#define data_020e7034 data_020e78d5
#endif
extern unsigned char data_020e7034[];   // the digits' palette for each HP tier (ROM {0, 4, 7, 6, 5})

// Main, originally func_0201fdd0 (USA 0x0201fdd0, EUR 0x0201fde0, JPN 0x0201faf4)
extern "C" ARM void MapDisplayMemberPanel_DrawStat(Display0201fdd0* panel, int row, int memberId, int amount, int maximum, int digitX, int digitY, int barX, int barY, int fillSprite, int frameSprite, unsigned int gauge) {
    int remaining;
    int digit;
    void* mapDisplay;
    int gaugeSlotOffset;
    int memberSlotOffset;
    int startX;
    int startY;
    unsigned short digitPalette;
    GameState* game = GameState::GetInstance();
    mapDisplay = GetGameResources()->unknown_ptr_36d0;
    if (!game->GetPartyMemberByIndex(memberId)) return;
    startX = digitX;
    startY = digitY;
    digit = 0;
    remaining = amount;
    digitPalette = data_020e7034[MapDisplay_GetMemberHpTier(memberId)];
    do {
        gaugeSlotOffset = gauge * 12;
        memberSlotOffset = memberId * 3 + kDigitOamSlot;
        int value = remaining % 10;
        remaining /= 10;
        int y = (int)(panel->y + (float)startY);
        int oamSlot = digit + memberSlotOffset;
        oamSlot += gaugeSlotOffset;
        MapDisplay_DrawSprite(mapDisplay, (startX + (row * kPanelWidth - digit * kDigitWidth)) << 12, y << 12, (value + kDigitSprite0) & 0xff, oamSlot & 0xff, 0, digitPalette, kNoAffineMatrix, kScaleOne, kScaleOne);
        ++digit;
    } while (remaining > 0);
    if (amount <= 0) return;
    fix32_t ratio = fix32_Divide(amount << 12, maximum << 12);
    fix32_t fullScale = fix32_Divide(0x31000, 0x20000);
    fix32_t fillScale = FIX32_MULTIPLY(ratio, fullScale);
    if (fillScale < kMinimumFill) fillScale = kMinimumFill;
    fix32_t gaugeX = (barX + row * kPanelWidth) << 12;
    fix32_t gaugeY = (int)(4096.0f * (panel->y + (float)barY));
    MapDisplay_DrawSprite(mapDisplay, gaugeX, gaugeY, fillSprite & 0xff, (memberId + kFillOamSlot + gauge * 8) & 0xff, 0, kGaugePalette, (memberId + gauge * 4) & 0xff, fillScale, kScaleOne);
    MapDisplay_DrawSprite(mapDisplay, gaugeX, gaugeY, frameSprite & 0xff, (memberId + kFrameOamSlot + gauge * 8) & 0xff, 0, kGaugePalette, kNoAffineMatrix, kScaleOne, kScaleOne);
}
