#include <globaldefs.h>
#include "Combat/MapDisplay.h"

// Sets one of nine OBJ palette presets (6 and 7 here) for one party slot, or all four with -1
extern "C" void func_020dc7e8(int preset, int partyIndex);
// Draws party member partyIndex's status panel into sub-screen OBJ VRAM, laid out by the sprite's cells
extern "C" void MapDisplay_RefreshMemberPanel(int partyIndex, void* panelSprite);

// Main, originally InitFourEntrySlots02020aa0 (USA 0x02020aa0, EUR 0x02020ab0, JPN 0x020206c4)
ARM void MapDisplay_RefreshAllMemberPanels(void* mapDisplay) {
    char partyIndex;
    func_020dc7e8(6, -1);
    func_020dc7e8(7, -1);
    for (partyIndex = 0; partyIndex < 4; partyIndex++) {
        MapDisplay_RefreshMemberPanel(partyIndex, &((MapDisplay*)mapDisplay)->records[0]);
    }
}
