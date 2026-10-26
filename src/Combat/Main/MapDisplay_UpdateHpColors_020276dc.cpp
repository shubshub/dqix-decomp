#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int memberId);
int MapDisplay_GetMemberHpTier(int memberId);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToSubObjStandardPalette(int source, int offset, unsigned int size);

// Colour index by HP tier: {-, 0, 3, 2, 1}
extern unsigned char data_020e703e[];
// RGB555 white, yellow, orange, red
extern unsigned short data_020e7044[] __attribute__((aligned(4)));

struct Global020fdc4c_020276dc {
    unsigned short uploadColor;
    char pad[0x12];
};
extern struct Global020fdc4c_020276dc data_020fdc4c;
#if defined(jpn)
#define data_020fdc50 data_020fdc54
#endif
extern char data_020fdc50[];

// MapDisplay::state, two bits per party member: the colour index last written for that member
struct MapDisplayHpColors {
    unsigned char hpColors;
};

enum { kPaletteSize = 32, kHpColorOffset = 15 * 2 };

// Main, originally func_020276dc (USA 0x020276dc, EUR 0x020276ec, JPN 0x02026f48)
extern "C" ARM void MapDisplay_UpdateHpColors(MapDisplayHpColors* self) {
    GameState* gameState = GameState::GetInstance();
    unsigned memberId;
    unsigned short colors[4];
    for (memberId = 0; memberId < 4; memberId++) {
        int allColors;
        int shift;
        int currentColor;
        unsigned char wantedColor;

        int k;

        if (GetCombatantWithFlag0x100_0200ff1c(gameState, memberId) == 0) continue;
        wantedColor = data_020e703e[MapDisplay_GetMemberHpTier(memberId)];
        allColors = self->hpColors;
        shift = memberId << 1;
        currentColor = (allColors >> shift) & 3;
        if (currentColor == wantedColor) continue;

        self->hpColors &= ~(3 << shift);
        self->hpColors |= wantedColor << shift;
        {
            const unsigned short* source = data_020e7044;
            unsigned short* destination = colors;
            k = 4;
            do { *destination++ = *source++; } while (--k);
        }
        data_020fdc4c.uploadColor = colors[wantedColor];
        CleanInvalidateCacheRange(data_020fdc50 - 4, 2);
        LoadToSubObjStandardPalette((int)(data_020fdc50 - 4), memberId * kPaletteSize + kHpColorOffset, 2);
    }
}
