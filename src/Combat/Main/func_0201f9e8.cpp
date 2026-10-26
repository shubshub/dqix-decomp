#include <globaldefs.h>

// One of the four party member panels at the bottom of the map screen (data_020fdc60): their head
struct MapDisplayMemberPanel {
    unsigned char state;      // MemberPanelState
    unsigned char nextState;
    unsigned char holdFlags;  // func_02026f34's PanelHold_*: while set the panel stays up
    unsigned char unknown3;
};

extern "C" void MapDisplayMemberPanel_Reset(void*);

// USA: func_0201f9e8
extern "C" ARM void func_0201f9e8(struct MapDisplayMemberPanel* panel) {
    panel->holdFlags = 0;
    panel->unknown3 = 0;
    MapDisplayMemberPanel_Reset(panel);
}
