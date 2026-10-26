#include <globaldefs.h>

#if defined(jpn)
#define func_02026f34 func_02026898
#endif
#include "GameState/GameState.h"

struct Struct_02012de8;

void* GlobalFlags_GetInstance();
int FlagWord_TestBits(FlagWord02046708* flags, unsigned int mask);

struct StateObj0201fa2c {
    unsigned char state;
    unsigned char nextState;
    unsigned char holdFlags;
    unsigned char pad3;
    unsigned short showDuration;
    char pad6[0x14 - 6];
};

struct StateObj0201fc40 {
    unsigned char state;
    unsigned char nextState;
    unsigned char holdFlags;
    unsigned char pad3;
    unsigned short showDuration;
    char pad6[0x14 - 6];
};

struct Stopwatch0201fbac {
    unsigned char state;
    unsigned char nextState;
    unsigned char holdFlags;
    unsigned char pad3;
    unsigned short showDuration;
    char pad6[0x14 - 6];
};

struct MapDisplayMemberStatus {
    char pad[0x1c];
    unsigned char statsChanged;
    unsigned char stateChanged;
};

struct MapDisplayMember {
#if defined(jpn)
    char unknown1_0_[0x1a6];
#else
    char unknown_0_[0x1b2];
#endif
    unsigned short uniqueId;
};

enum {
    PanelHold_UniqueId = 1,
    PanelHold_All = 2,
};

enum { kPanelShowAfterChangeMs = 2000 };

// MapDisplay::flags758, field75c, recordVisible, mask55d, field55e, records
#if defined(jpn)
enum { kMemberIdsOffset = 0x6ac, kRowCountOffset = 0x6b0 };
#else
enum { kMemberIdsOffset = 0x758, kRowCountOffset = 0x75c };
#endif
enum { kRecordVisibleOffset = 0x558, kUpdateMaskOffset = 0x55d, kRedrawMaskOffset = 0x55e, kSpritesOffset = 0xe8 };

extern StateObj0201fa2c data_020fdc60[4];
extern MapDisplayMemberStatus data_020fdcb0[4];

void UpdateStopwatchState0201fbac(struct Stopwatch0201fbac* panel);
void ResetStateTimer0201fc40(struct StateObj0201fc40* panel, int showDuration);
void MapDisplayMemberPanel_Update(StateObj0201fa2c* panel, unsigned int deltaTime);
extern "C" void MapDisplay_RefreshMemberPanel(int memberId, void* sprite);

typedef void (*UpdateStateTimer0201fa2cFn)(StateObj0201fa2c* panel, unsigned int deltaTime, unsigned char memberId);

// USA: func_02026f34
extern "C" ARM void func_02026f34(void* displayPtr) {
    unsigned char* display = (unsigned char*)displayPtr;
    if (FlagWord_TestBits((FlagWord02046708*)GlobalFlags_GetInstance(), 0x41)) return;

    GameState* gameState = GameState::GetInstance();
    unsigned int deltaTime = gameState->GetEffectiveDeltaTime();

    for (int row = 0; row < display[kRowCountOffset]; row++) {
        unsigned char* rowIds = display + row;
        unsigned char memberId = rowIds[kMemberIdsOffset];
        StateObj0201fa2c* panel;
        MapDisplayMemberStatus* status;
        unsigned int memberBit = (unsigned char)(1 << memberId);

        if (!(display[kUpdateMaskOffset] & memberBit)) continue;

        panel = (StateObj0201fa2c*)((char*)data_020fdc60 + row * 0x14);
        status = (MapDisplayMemberStatus*)((char*)data_020fdcb0 + (memberId << 5));
        void* member = gameState->GetPartyMemberByIndex(memberId);
        if (member == NULL) continue;

        int showDuration = 0;
        if (status->statsChanged) showDuration = kPanelShowAfterChangeMs;

        if (status->stateChanged || (display[kRedrawMaskOffset] & memberBit)) {
            MapDisplay_RefreshMemberPanel((signed char)memberId, (char*)display + kSpritesOffset + memberId * 0x28);
            display[kRedrawMaskOffset] &= ~memberBit;
        }

        if (data_020fdc60[0].holdFlags & PanelHold_All) {
            UpdateStopwatchState0201fbac((struct Stopwatch0201fbac*)panel);
        } else {
            if ((panel->holdFlags & PanelHold_UniqueId) && ((MapDisplayMember*)member)->uniqueId == 0) {
                panel->holdFlags &= ~PanelHold_UniqueId;
                panel->showDuration = kPanelShowAfterChangeMs;
            } else if (((MapDisplayMember*)member)->uniqueId != 0) {
                UpdateStopwatchState0201fbac((struct Stopwatch0201fbac*)panel);
                panel->holdFlags |= PanelHold_UniqueId;
            } else if (showDuration > 0 && (display + memberId)[kRecordVisibleOffset]) {
                ResetStateTimer0201fc40((struct StateObj0201fc40*)panel, showDuration);
            }
        }
        ((UpdateStateTimer0201fa2cFn)MapDisplayMemberPanel_Update)(panel, deltaTime, memberId);

        if (status->statsChanged) {
            (display + memberId)[kRecordVisibleOffset] = 1;
        }
        status->stateChanged = 0;
        status->statsChanged = 0;
    }
}
