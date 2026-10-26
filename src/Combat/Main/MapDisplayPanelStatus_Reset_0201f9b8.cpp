#include <globaldefs.h>

// One party member's entry in the status snapshot table data_020fdcb0: what its map screen panel last showed
// (MapDisplay_Update copies these from the member each frame and sets the changed flags when one differs)
struct State_1f9b8 {
    int hp;                         // -1: no snapshot yet
    int mp;
    int maxHp;
    int maxMp;
    int vocation;
    unsigned char level;
    char pad15[0x3];
    int statusFlags;                // CombatantStatus::flags
    unsigned char statsChanged;     // shows the panel for 2 s (func_02026f34)
    unsigned char stateChanged;     // redraws the member's card (MapDisplay_RefreshMemberPanel)
};

// Main, originally InitStruct_0201f9b8 (USA 0x0201f9b8, EUR 0x0201f9c8, JPN 0x0201f6dc)
extern "C" ARM void MapDisplayPanelStatus_Reset(struct State_1f9b8* status) {
    status->hp = -1;
    status->mp = -1;
    status->maxHp = -1;
    status->maxMp = -1;
    status->vocation = 0;
    status->level = 0;
    status->statusFlags = 0;
    status->statsChanged = 0;
    status->stateChanged = 0;
}
