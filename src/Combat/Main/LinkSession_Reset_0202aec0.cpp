#include <globaldefs.h>
#include "Resource/TextEncoding.h"

extern "C" void* memset(void* dst, int c, unsigned long n);
extern "C" void OS_GetOwnerInfo(void* out);

// Session block at +0x1000 of the link session (data_020fefec).
struct SubState_0202aec0 {
    int f0;
    int f4;
    int f8;
    unsigned char memberMask;     // +0x100c: aid bits of the joined members (LinkSession_AddMember sets, LinkSession_RemoveMember clears)
    unsigned char memberCount;    // +0x100d: LinkSession_UpdateMemberCount counts memberMask's bits; 1 when there is no session
    unsigned char lostMask;       // +0x100e: aid bits of members whose console stopped answering (LinkSession_Update)
    unsigned char ff;
    unsigned char lostAnnouncedMask; // +0x1010: func_ov017_021941fc sets a lost member's bit once it has posted its loss
    unsigned char assignSlots;    // +0x1011: LinkSession_Update gives newly connected aids a free party slot while set
    unsigned char pad12[2];
    // +0x1014: the 0x24-byte user game info a parent's beacon carries (func_0202ae4c reads it from a WMBssDesc).
    unsigned char playerName[0x13];
    unsigned char partySize;      // +0x1027: LinkSession_UpdatePartySize (party member objects)
    unsigned char playerNameLength;
    unsigned char beaconFlags;    // +0x1029: LinkSession_UpdateBeacon puts the connected console count - 1 in bits 0-2
    unsigned char pad2a[2];       // +0x102a: a u16 LinkSession_UpdateBeacon increments on each beacon update
    unsigned char pad2c[8];
    int f34;
    signed char slotOfAid[0x10];         // +0x1038: each wireless aid's party slot (LinkSession_FindAidOfSlot)
    signed char previousSlotOfAid[0x10]; // +0x1048: the slot each aid last held (LinkSession_FindPreviousAidOfSlot)
};

// The link session (data_020fefec, size 0x1058).
struct Obj_0202aec0 {
    int state;          // nonzero while a session runs (LinkSession_IsActive)
    short tgid;         // LinkSession_Update increments it and passes it to WH_ParentConnect (WH_ParentConnect)
    short pad6;
    int f8;
    int scanResultCount;                  // LinkSession_AgeScanResults ages and removes the 0xc0-byte records below
    unsigned char scanResults[10][0xc0];
    int scanResultLifetimes[10];
    unsigned char pad7b8[8];
    unsigned char sendBuffer[0x400];      // +0x7c0: this console's record (LinkSession_GetOwnRecord)
    unsigned char receiveBuffer[0x400];   // +0xbc0: each aid's 0x74-byte record (LinkSession_GetReceivedRecord)
    int busy;                             // +0xfc0: func_0205e57c and FieldTask_LeaveMultiplayer wait while it is set
    unsigned char ffc4[0x3c];
    SubState_0202aec0 sub;
};

// NitroSDK OSOwnerInfo (OS_GetOwnerInfo): the DS user settings.
struct OSOwnerInfo {
    unsigned char language;
    unsigned char favoriteColor;
    unsigned char birthdayMonth;
    unsigned char birthdayDay;
    unsigned short nickName[11];
    unsigned short nickNameLength;
    unsigned short comment[27];
    unsigned short commentLength;
};

extern "C" int _ZZ14GetTurnCountervE1s;

// Main, originally func_0202aec0 (USA 0x0202aec0, EUR 0x0202aed0, JPN 0x0202aa70)
extern "C" ARM void LinkSession_Reset(Obj_0202aec0* session) {
    OSOwnerInfo owner;

    session->state = 0;
    session->tgid = 0;
    session->f8 = 0;
    session->scanResultCount = 0;
    session->busy = 0;
    session->sub.f4 = 0;
    session->sub.f8 = -1;
    memset(session->sub.playerName, 0, 0x24);
    memset(session->scanResults, 0, sizeof(session->scanResults));
    memset(session->scanResultLifetimes, 0, sizeof(session->scanResultLifetimes));
    memset(session->sendBuffer, 0, sizeof(session->sendBuffer));
    memset(session->receiveBuffer, 0, sizeof(session->receiveBuffer));
    memset(session->ffc4, 0, 0x40);

    OS_GetOwnerInfo(&owner);
    session->sub.playerNameLength = owner.nickNameLength;
    Text_Utf16ToShiftJis(session->sub.playerName, owner.nickName, session->sub.playerNameLength);

    session->sub.beaconFlags = session->sub.beaconFlags & ~8;
    session->sub.f34 = 0;
    session->sub.memberMask = 1;
    session->sub.memberCount = 1;
    session->sub.lostMask = 0;
    session->sub.ff = 0;
    session->sub.lostAnnouncedMask = 0;
    (&_ZZ14GetTurnCountervE1s)[1] = 0;
    memset(session->sub.slotOfAid, 0, sizeof(session->sub.slotOfAid));
    memset(session->sub.previousSlotOfAid, 0, sizeof(session->sub.previousSlotOfAid));
    session->sub.assignSlots = 1;
}
