#include <globaldefs.h>

#if defined(jpn)
enum { timerAccumulatorOffset = 0x910 };
#else
enum { timerAccumulatorOffset = 0x9bc };
#endif
#include "GameState/GameState.h"

// The map icons' blink (MapDisplay field9bc and the byte after it): MapIcon_IsShownInBlinkPhase hides blinking icons in
// phase 1, when MapDisplay_DrawBattleMarkers draws the battle markers
struct BattleTimer0202441c {
    char pad[timerAccumulatorOffset];
    unsigned int blinkTimer;
    unsigned char blinkPhase;
};

enum {
    kBlinkPhase1Start = 500, // ms
    kBlinkPeriod = 1200,
};

// Main, originally AccumulateBattleTimer0202441c (USA 0x0202441c, EUR 0x0202442c, JPN 0x02023df0)
ARM void MapDisplay_UpdateBlink(struct BattleTimer0202441c* self) {
    self->blinkTimer += ((GameState*)(GameState::GetInstance()))->GetTrueDeltaTime();
    if (self->blinkTimer >= kBlinkPeriod) {
        self->blinkPhase = 0;
        self->blinkTimer = 0;
        return;
    }
    if (self->blinkTimer >= kBlinkPhase1Start) {
        self->blinkPhase = 1;
    }
}
