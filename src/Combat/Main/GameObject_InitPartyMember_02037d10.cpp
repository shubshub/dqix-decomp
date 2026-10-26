#include <globaldefs.h>
#include "Combat/ActorAction.h"
#if defined(jpn)
#define COMBAT_FIELD(x) ((x) - 12)
#else
#define COMBAT_FIELD(x) (x)
#endif

void InitCombatantExtendedFields02052a4c(void*);

// The party member fields (usa offsets), as the functions that use them show
enum {
    ObjectKind_PartyMember = 0x800,                // Object3D::unknown_0_ bit GameState::GetPartyMemberByIndex requires
    PartyMember_followedIndex = 0x1c8,             // the member it walks behind, -1 for none (func_ov017_02190884)
    PartyMember_linePosition = 0x1c9,              // its place in the walking line, 0 = the line's leader
    PartyMember_lineLeader = 0x1ca,                // the line leader's index
    PartyMember_trailWriteIndex = 0x1cb,           // the 16-point trail GameObject_UpdateFollower follows
    PartyMember_trailReadIndex = 0x1cc,
    PartyMember_trailStarted = 0x1cd,
    PartyMember_followFlags = 0x1ce,
    PartyMember_walkDirection = 0x250,             // GameObject_HandleWalkInput: 8-15 while a direction is held, 0-7 after
    PartyMember_unknown251 = 0x251,
    PartyMember_controlEnabled = 0x252,            // GameObject_DisableControl clears both
    PartyMember_controlPending = 0x253,
    PartyMember_unknown254 = 0x254,
    PartyMember_lockedDirection = 0x255,           // GameObject_HandleWalkInput's heading lock: the direction held into it,
    PartyMember_lockedAngle = 0x256,               // and the angle it locked to
    PartyMember_gestureSlot = 0x260,               // GameObject_UpdatePartyMember: B + D-pad this frame, -1 for none
    PartyMember_unknown264 = 0x264,
    PartyMember_followFade = 0x268,                // GameObject_UpdateFollower's fade-in while the leader is on a ladder
    PartyMember_ladderClimb = 0x26c,               // the SubBlock02038508 GameObject_UpdateLadderClimb climbs ladders with
};

// Main, originally func_02037d10 (USA 0x02037d10, EUR 0x02037d20, JPN 0x0203776c)
extern "C" ARM void GameObject_InitPartyMember(void* object) {
    signed char* bytes = (signed char*)object;
    InitCombatantExtendedFields02052a4c(object);
    *(unsigned short*)(bytes + 0x0) |= ObjectKind_PartyMember;
    bytes[COMBAT_FIELD(PartyMember_trailWriteIndex)] = -1;
    bytes[COMBAT_FIELD(PartyMember_trailReadIndex)] = 0;
    bytes[COMBAT_FIELD(PartyMember_followedIndex)] = -1;
    bytes[COMBAT_FIELD(PartyMember_linePosition)] = 0;
    bytes[COMBAT_FIELD(PartyMember_lineLeader)] = -1;
    bytes[COMBAT_FIELD(PartyMember_trailStarted)] = 0;
    bytes[COMBAT_FIELD(PartyMember_followFlags)] = 0;
    bytes[COMBAT_FIELD(PartyMember_walkDirection)] = 1;
    bytes[COMBAT_FIELD(PartyMember_unknown251)] = 0;
    bytes[COMBAT_FIELD(PartyMember_controlEnabled)] = 1;
    bytes[COMBAT_FIELD(PartyMember_controlPending)] = 1;
    bytes[COMBAT_FIELD(PartyMember_unknown254)] = 0;
    *(int*)(bytes + COMBAT_FIELD(PartyMember_unknown264)) = 0;
    *(int*)(bytes + COMBAT_FIELD(PartyMember_gestureSlot)) = -1;
    bytes[COMBAT_FIELD(PartyMember_lockedDirection)] = -1;
    *(unsigned short*)(bytes + COMBAT_FIELD(PartyMember_lockedAngle)) = 0;
    struct SubBlock02038508* ladderClimb = (struct SubBlock02038508*)(bytes + COMBAT_FIELD(PartyMember_ladderClimb));
    *(int*)(bytes + COMBAT_FIELD(PartyMember_followFade)) = 0;
    LadderClimb_Reset(ladderClimb);
}
