#include <globaldefs.h>
#include "GameState/GameState.h"

// The link session's member block at +0x1000.
struct MemberBlock_0202c288 {
    char padding0[0xd];
    unsigned char memberCount;  // +0x100d
};
// The link session (data_020fefec), as far as this function reads it.
struct SearchStruct {
    int state;
    char padding4[0x1000 - 4];
    struct MemberBlock_0202c288 members;
};

extern "C" void VCountIrq_PushDisable(void);
extern "C" void VCountIrq_PopDisable(void);
extern "C" int LinkSession_IsSlotMember(struct SearchStruct* session, int slot);
extern "C" void LinkSession_UpdatePartySize(void* session);
extern "C" void GameState_UpdatePlayClocks(int commit);
unsigned long long GetCurrentTimestamp(void);

// Main, originally func_0202c288 (USA 0x0202c288, EUR 0x0202c298, JPN 0x0202be38)
extern "C" ARM void LinkSession_UpdateMemberCount(struct SearchStruct* session) {
    VCountIrq_PushDisable();
    int active = (session->state != 0);
    unsigned char previousCount = session->members.memberCount;

    if (!active) {
        session->members.memberCount = 1;
    } else {
        session->members.memberCount = 0;
        int slot;
        for (slot = 0; slot < 4; slot++) {
            if (LinkSession_IsSlotMember(session, slot)) {
                session->members.memberCount++;
            }
        }
        LinkSession_UpdatePartySize(session);
    }

    if (session->state == 5) {
        unsigned char count = session->members.memberCount;
        if (count == 1) {
            if (previousCount > 1) {
                GameState_UpdatePlayClocks(1);
                goto done;
            }
        }

        if (count > 1) {
            if (previousCount == 1) {
                GameState* gameState = GameState::GetInstance();
                gameState->altTimestamp_ = GetCurrentTimestamp();
            }
        }
    }

done:
    VCountIrq_PopDisable();
}
