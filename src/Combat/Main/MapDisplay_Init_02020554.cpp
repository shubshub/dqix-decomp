#include <globaldefs.h>

#include "Combat/ActionState.h"
#include "Combat/MapDisplay.h"
#include "NitroSDK/Memory.h"

// One party member's entry in the status snapshot table data_020fdcb0 (MapDisplayPanelStatus_Reset.cpp)
struct State_1f9b8 {
    int hp;
    int mp;
    int maxHp;
    int maxMp;
    int vocation;
    unsigned char level;
    char pad15[0x3];
    int statusFlags;
    unsigned char statsChanged;
    unsigned char stateChanged;
};

// The head of a party member's map screen panel (data_020fdc60)
struct MapDisplayMemberPanel {
    unsigned char state;
    unsigned char nextState;
    unsigned char holdFlags;
    unsigned char unknown3;
};

enum { kAllMembers = 0xf };     // MapDisplay::mask55d: one bit per party member 0-3

void MapDisplayPanelStatus_Reset(State_1f9b8 *status);
extern "C" void InitStopwatch0201f9e8(MapDisplayMemberPanel *panel);
void MapDisplay_ClearRedChests(char *display);

extern State_1f9b8 data_020fdcb0[4];
// data_020fdcb0[0] + 0x1e: each entry's reset byte (stride 0x20)
#if defined(jpn)
extern unsigned char data_020fda36;
#define data_020fdcce data_020fda36
#else
extern unsigned char data_020fdcce;
#endif

// Main, originally func_02020554 (USA 0x02020554, EUR 0x02020564, JPN 0x020201a0)
extern "C" ARM void MapDisplay_Init(MapDisplay *display) {
    VectorizedMemset(display, 0, sizeof(MapDisplay));
    display->field9c1 = 0;
    display->loadStage = 0;
    display->field9c3 = 0;
    display->field9c4 = 0;
    display->field9c6 = 0;
    display->fielda96 = 0;
    MapDisplay_ResetMap(display);

    for (int i = 0; i < 4; i++) {
        MapDisplayPanelStatus_Reset(&data_020fdcb0[i]);
        (&data_020fdcce)[i * 0x20] = 0;
        InitStopwatch0201f9e8((MapDisplayMemberPanel *) &data_020fdc60[i]);
    }

    display->flags |= 1;
    display->field765 = 1;
    display->field5a8 = 0;
    display->field12  = 0;
    display->failed = 0;
    display->field778 = 0;
    display->field9c5 = 0;
    display->field76c = 0;
    display->field770 = 0;
    display->field774 = 0;
    display->refreshRecords = 0;
    display->field9ba = 0;
    display->field77c = 0;
    display->field780 = 0;
    MapDisplay_ClearRedChests((char *) display);

    display->field9b8  = 0;
    display->field9b9  = 0;
    display->field9c8  = 0;
    display->mask55d   = kAllMembers;
    display->field55e  = 0;
    display->fileTask920 = -1;
#if !defined(jpn)
    display->scriptTask = -1;
#endif
    display->namesTask = -1;
    display->fileTask928 = -1;
    display->task9fc = -1;
    display->taska00 = -1;
    display->taska04 = -1;
    display->taska08 = -1;
    display->taska0c = -1;
    display->taska10 = -1;
    display->taska14 = -1;
    display->taska18 = -1;
    display->taska1c = -1;
    display->taska20 = -1;
    display->taska24 = -1;
    display->taska28 = -1;
    display->taska2c = -1;
    display->fileTask984 = -1;
    for (int i = 0; i < 8; i++) {
        display->nameTasks[i] = -1;
    }
    display->fielda34 = 0xff;
    VectorizedMemset(display->bytesa35, 0, 0x10);
    VectorizedMemset(display->bytesa45, 0, 0x10);
    VectorizedMemset(display->bytesa55, 0, 0x20);
    display->fielda95 = 0;
    display->fielda97 = 0;
#if !defined(jpn)
    VectorizedMemset(display->scriptName, 0, 0x40);
    display->scriptNameWidth = 0;
    display->fieldb3c = 0;
    display->fieldb40 = 0;
    display->fieldb42 = 0;
#endif
}
