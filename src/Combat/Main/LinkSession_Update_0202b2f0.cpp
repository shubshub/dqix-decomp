#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Combat/SearchEntry.h"
#include "Resource/GameResources.h"
// The link session (data_020fefec), as far as this function reads it.
struct SearchStruct {
    int state;
    unsigned short tgid;
    unsigned char padding6[0x7ba];
    SearchEntry0202c178 ownRecord;      // +0x7c0: this console's record (LinkSession_GetOwnRecord)
    unsigned char padding7d0[0x7f0];
    int busy;                           // +0xfc0
    unsigned char paddingfc4[0x4a];
    unsigned char lostMask;             // +0x100e: aid bits of members whose console stopped answering
    unsigned char activeMask;           // +0x100f: SetSearchFlagBit0202c660 sets, ClearSearchFlagBit0202c69c clears
    unsigned char padding1010;
    unsigned char assignSlots;          // +0x1011: give newly connected aids a free party slot
    unsigned char padding1012[0x26];
    signed char slotOfAid[16];          // +0x1038: each wireless aid's party slot
    signed char previousSlotOfAid[16];  // +0x1048: the slot each aid last held
    int IsActive() const {
        return state != 0;
    }
};
// NitroSDK wh library values: WH_GetSystemState states, WH_ParentConnect's connect mode,
// WH_GetLastError error code.
enum {
    WH_SYSSTATE_MEASURECHANNEL = 7,
    WH_SYSSTATE_ERROR = 9,
    WH_CONNECTMODE_DS_PARENT = 4,
    WH_ERRCODE_DISCONNECTED = 20,
};
// GlobalFlags bit LinkSession_WaitForIdle sets when the wireless gave up and it ended the session.
enum { kGlobalFlag_LinkFailed = 0x1000000 };
enum { kSessionState_Failed = -1 };
struct FlagWord02046708;
unsigned short WH_GetCurrentAid();
void* GlobalFlags_GetInstance();
int FlagWord_TestBits(FlagWord02046708*, unsigned int);
int WH_GetSystemState();
extern "C" int WH_GetMeasureChannel();
extern "C" void WH_ParentConnect(int, int, int);
extern "C" void LinkSession_UpdateBeacon(SearchStruct*, int);
extern "C" void LinkSession_ShareRecords(SearchStruct*);
extern "C" void func_0202c04c(SearchStruct*);
extern "C" int LinkSession_IsHostOrSolo(SearchStruct*);
unsigned short LinkSession_GetConnectedAids(SearchStruct*);
signed char LinkSession_FindAidOfSlot(SearchStruct*, int);
int LinkSession_IsSlotConnected(SearchStruct*, int);
void LinkSession_RemoveMember(SearchStruct*, int);
int LinkSession_IsSlotMember(SearchStruct*, int);
void LinkSession_MarkSlotLost(SearchStruct*, int);
void LinkSession_AddMember(SearchStruct*, int);
void SetSearchFlagBit0202c660(SearchStruct*, int);
int WH_GetLastError();

// Main, originally func_0202b2f0 (USA 0x0202b2f0, EUR 0x0202b300, JPN 0x0202aea0)
extern "C" ARM void LinkSession_Update(SearchStruct* session) {
    unsigned short savedSelected[4];
    unsigned short savedMask[4];
    for (int slot = 0; slot < 4; slot++) {
        if (slot == session->slotOfAid[WH_GetCurrentAid()]) {
            continue;
        }
        SearchEntry0202c178* record = LinkSession_GetReceivedRecord(session, slot);
        if (!record) {
            continue;
        }
        unsigned int selected = record->flags.selected;
        record->flags.selected = 0;
        unsigned short mask = record->mask;
        savedSelected[slot] = selected;
        savedMask[slot] = record->mask;
        record->mask = mask & ~0xffff;
    }
    GameState::GetInstance();
    if (FlagWord_TestBits((FlagWord02046708*)GlobalFlags_GetInstance(), kGlobalFlag_LinkFailed)) {
        session->state = kSessionState_Failed;
        return;
    }
    switch (WH_GetSystemState()) {
    case WH_SYSSTATE_MEASURECHANNEL: {
        int channel = WH_GetMeasureChannel();
        session->tgid++;
        WH_ParentConnect(WH_CONNECTMODE_DS_PARENT, session->tgid, channel);
        break;
    }
    case WH_SYSSTATE_ERROR:
        session->state = kSessionState_Failed;
        break;
    }
    switch (session->state) {
    case 2:
        LinkSession_UpdateBeacon(session, 1);
        break;
    case 3:
        LinkSession_AgeScanResults(session);
        break;
    case 5:
        LinkSession_UpdateBeacon(session, 1);
        LinkSession_ShareRecords(session);
        func_0202c04c(session);
        break;
    case 6:
        LinkSession_ShareRecords(session);
        func_0202c04c(session);
        break;
    }
    if (session->busy) {
        for (int slot = 0; slot < 4; slot++) {
            if (slot == session->slotOfAid[WH_GetCurrentAid()]) {
                continue;
            }
            SearchEntry0202c178* record = LinkSession_GetReceivedRecord(session, slot);
            if (!record) {
                continue;
            }
            record->flags.selected = savedSelected[slot];
            record->mask = (record->mask & ~0xffff) | savedMask[slot];
        }
    } else if (LinkSession_IsHostOrSolo(session)) {
        SearchEntry0202c178* ownRecord;
        if (session->assignSlots) {
            unsigned int connected = LinkSession_GetConnectedAids(session);
            ownRecord = &session->ownRecord;
            unsigned int partyMembers = ownRecord->members;
            for (int aid = 1; aid < 4; aid++) {
                if (!(connected & (1 << aid)) || session->slotOfAid[aid] != 0) {
                    continue;
                }
                for (int slot = 1; slot < 4; slot++) {
                    if (partyMembers & (1 << slot)) {
                        continue;
                    }
                    int taken;
                    for (int other = 1; other < 4; other++) {
                        if ((signed char)slot == session->slotOfAid[other]) {
                            taken = 1;
                            goto slotChecked;
                        }
                    }
                    taken = 0;
slotChecked:
                    if (!taken) {
                        session->slotOfAid[aid] = slot;
                        break;
                    }
                }
            }
        }
        session->lostMask = 0;
        int hostAid = LinkSession_FindAidOfSlot(session, 0);
        if (!(session->activeMask & (1 << hostAid))) {
            ownRecord = &session->ownRecord;
            for (int slot = 1; slot < 4; slot++) {
                int aid = LinkSession_FindAidOfSlot(session, slot);
                if ((session->activeMask & (1 << aid)) && !(ownRecord->members & (1 << slot))) {
                    if (!LinkSession_IsSlotConnected(session, slot)) {
                        LinkSession_RemoveMember(session, slot);
                    }
                } else if (LinkSession_IsSlotMember(session, slot)) {
                    if (!LinkSession_IsSlotConnected(session, slot)) {
                        LinkSession_MarkSlotLost(session, slot);
                    }
                } else if (LinkSession_IsSlotConnected(session, slot)) {
                    LinkSession_AddMember(session, slot);
                    SetSearchFlagBit0202c660(session, slot);
                    if (session->IsActive()) {
                        GameResources* resources = GetGameResources();
                        memset(resources->partyNames[slot], 0, sizeof(resources->partyNames[slot]));
                    }
                }
            }
        } else {
            for (int slot = 1; slot < 4; slot++) {
                if (LinkSession_IsSlotMember(session, slot) && !LinkSession_IsSlotConnected(session, slot)) {
                    LinkSession_RemoveMember(session, slot);
                }
            }
        }
    } else {
        SearchEntry0202c178* hostRecord = LinkSession_GetReceivedRecord(session, 0);
        session->slotOfAid[1] = hostRecord->selector1;
        session->slotOfAid[2] = hostRecord->selector2;
        session->slotOfAid[3] = hostRecord->selector3;
        if (hostRecord->selector1) {
            session->previousSlotOfAid[1] = hostRecord->selector1;
        }
        if (hostRecord->selector2) {
            session->previousSlotOfAid[2] = hostRecord->selector2;
        }
        if (hostRecord->selector3) {
            session->previousSlotOfAid[3] = hostRecord->selector3;
        }
    }
    if (session->slotOfAid[WH_GetCurrentAid()] != 0 && WH_GetLastError() == WH_ERRCODE_DISCONNECTED) {
        LinkSession_MarkSlotLost(session, 0);
    }
}
