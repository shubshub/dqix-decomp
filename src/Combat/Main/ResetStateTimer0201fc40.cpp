#include <globaldefs.h>
#include "NitroSDK/Timing.h"

// MapDisplayMemberPanel::state
enum MemberPanelState {
    MemberPanelState_Hidden = 1,
    MemberPanelState_Shown = 2,
    MemberPanelState_SlidingIn = 3,
    MemberPanelState_SlidingOut = 4,
};

// One of the four party member panels at the bottom of the map screen (data_020fdc60)
struct StateObj0201fc40 {
    unsigned char state;            // MemberPanelState
    unsigned char nextState;
    unsigned char holdFlags;        // while set the panel stays up
    unsigned char unknown3;
    unsigned short showDuration;    // milliseconds to stay up after shownAt
    unsigned short pad6;
    long long shownAt;
};

// USA: func_0201fc40
ARM void ResetStateTimer0201fc40(struct StateObj0201fc40* panel, int showDuration) {
    if (panel->holdFlags != 0) return;
    if (panel->state == MemberPanelState_Hidden || panel->state == MemberPanelState_SlidingOut) {
        panel->nextState = MemberPanelState_SlidingIn;
        panel->showDuration = showDuration;
        panel->shownAt = GetCurrentTimestamp();
        return;
    }
    if (panel->state == MemberPanelState_SlidingIn || panel->state == MemberPanelState_Shown) {
        panel->showDuration = showDuration;
        panel->shownAt = GetCurrentTimestamp();
    }
}
