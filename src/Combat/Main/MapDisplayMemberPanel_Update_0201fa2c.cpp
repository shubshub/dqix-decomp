#include <globaldefs.h>
#include "NitroSDK/Timing.h"

extern "C" unsigned long long _ll_udiv(unsigned long long arg0, unsigned int arg1, unsigned int flag);

// MapDisplayMemberPanel::state: hidden (only the top strip shows), sliding up, shown, sliding down
enum MemberPanelState {
    MemberPanelState_Hidden = 1,
    MemberPanelState_Shown = 2,
    MemberPanelState_SlidingIn = 3,
    MemberPanelState_SlidingOut = 4,
};

#define MEMBER_PANEL_HIDDEN_Y 176.0f
#define MEMBER_PANEL_SHOWN_Y 136.0f
#define MEMBER_PANEL_SLIDE_PER_FRAME 6.0f      // pixels per 30 fps frame
#define FRAME_MILLISECONDS 33.333332f

// One of the four party member panels at the bottom of the map screen (data_020fdc60)
struct StateObj0201fa2c {
    unsigned char state;            // MemberPanelState
    unsigned char nextState;
    unsigned char holdFlags;        // while set the panel stays up
    unsigned char unknown3;
    unsigned short showDuration;    // milliseconds to stay up after shownAt, 0 = until told
    unsigned short pad6;
    unsigned long long shownAt;     // GetCurrentTimestamp() when it was last shown
    float y;                        // screen y of its top edge
};

// Main, originally UpdateStateTimer0201fa2c (USA 0x0201fa2c, EUR 0x0201fa3c, JPN 0x0201f750)
extern "C" ARM void MapDisplayMemberPanel_Update(StateObj0201fa2c* panel, unsigned int deltaTime) {
    if (panel->state == MemberPanelState_Hidden) {
        if (panel->nextState == MemberPanelState_SlidingIn) {
            panel->state = MemberPanelState_SlidingIn;
            panel->nextState = 0;
            return;
        } else {
            panel->y = MEMBER_PANEL_HIDDEN_Y;
            panel->nextState = 0;
            return;
        }
    }
    if (panel->state == MemberPanelState_Shown) {
        if (panel->holdFlags != 0) return;
        if (panel->showDuration != 0) {
            unsigned long long elapsed = GetCurrentTimestamp() - panel->shownAt;
            unsigned long long elapsedMs = _ll_udiv(elapsed << 6, TIMER_TICKS_PER_MILLISECOND, 0);
            if (elapsedMs >= panel->showDuration) panel->nextState = MemberPanelState_SlidingOut;
        }
        if (panel->nextState == MemberPanelState_SlidingOut) {
            panel->state = MemberPanelState_SlidingOut;
            panel->nextState = MemberPanelState_SlidingOut;
            panel->showDuration = 0;
        }
        panel->y = MEMBER_PANEL_SHOWN_Y;
        return;
    }
    if (panel->state == MemberPanelState_SlidingIn) {
        panel->y = panel->y - MEMBER_PANEL_SLIDE_PER_FRAME * ((float)deltaTime / FRAME_MILLISECONDS);
        if (panel->y < MEMBER_PANEL_SHOWN_Y) {
            panel->y = MEMBER_PANEL_SHOWN_Y;
            panel->state = MemberPanelState_Shown;
        }
        return;
    }
    if (panel->state != MemberPanelState_SlidingOut) return;
    panel->y = panel->y + MEMBER_PANEL_SLIDE_PER_FRAME * ((float)deltaTime / FRAME_MILLISECONDS);
    if (MEMBER_PANEL_HIDDEN_Y < panel->y) {
        panel->y = MEMBER_PANEL_HIDDEN_Y;
        panel->state = MemberPanelState_Hidden;
    }
}
