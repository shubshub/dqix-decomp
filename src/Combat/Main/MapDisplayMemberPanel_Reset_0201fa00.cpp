#include <globaldefs.h>

// MapDisplayMemberPanel::state (MapDisplayMemberPanel_Update moves the panel between them)
enum MemberPanelState {
    MemberPanelState_Hidden = 1,
};

#define MEMBER_PANEL_HIDDEN_Y 176.0f

// One of the four party member panels at the bottom of the map screen (data_020fdc60)
struct MapDisplayMemberPanel {
    unsigned char state;            // MemberPanelState
    unsigned char nextState;
    unsigned char holdFlags;
    unsigned char unknown3;
    unsigned short showDuration;    // milliseconds to stay up after shownAt, 0 = until told
    unsigned short pad6;
    int shownAtLow;                 // the GetCurrentTimestamp() it was shown at
    int shownAtHigh;
    float y;                        // screen y of its top edge
};

extern "C" {
// Main, originally ResetStopwatch0201fa00 (USA 0x0201fa00, EUR 0x0201fa10, JPN 0x0201f724)
ARM void MapDisplayMemberPanel_Reset(struct MapDisplayMemberPanel* panel) {
    panel->state = MemberPanelState_Hidden;
    panel->nextState = 0;
    panel->showDuration = 0;
    panel->y = MEMBER_PANEL_HIDDEN_Y;
    panel->shownAtLow = 0;
    panel->shownAtHigh = 0;
}
}
