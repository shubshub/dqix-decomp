#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { kTextBufferOffset = 0x28, kMessageFlagOffset = 0x17e2, kStatusOffset = 0x868 };
#else
enum { kTextBufferOffset = 0x5c, kMessageFlagOffset = 0x19b2, kStatusOffset = 0x998 };
#endif

struct CombatantMessageController {
    char unknown0[0x10];
    void* substitutions;
    char unknown14[kTextBufferOffset - 0x14];
    char* textBuffer;
    char unknownAfterBuffer[kStatusOffset - kTextBufferOffset - sizeof(char*)];
    int status;
    char unknownAfterStatus[kMessageFlagOffset - kStatusOffset - sizeof(int)];
    unsigned char messageFlag;
};

CombatantMessageController* MessageSystem_GetInstance(void);
extern "C" void func_020531f0(void* obj);
struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" void func_02046380(void* obj);
int StandardStrings_Get(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
void NameText_InitFromPartyMember(void* obj, int combatantId);
#if !defined(jpn)
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
extern char data_ov017_021d882c[];
#endif
void GameObject_EnableControl(void* obj);

struct CombatantMessageRequest {
    unsigned char unknown0;
    unsigned char done;
    unsigned char unknown2[6];
    unsigned char state;
    unsigned char partyMemberId;
};

// Overlay 17, originally func_ov017_021c3194 (USA/EUR 0x021c3194, JPN 0x021c3690)
extern "C" ARM void FieldTask_TalkToDeadMember(CombatantMessageRequest* request) {
    GameState* battleStruct = GameState::GetInstance();
    GetGameResources();
    GameObject* unknownActor = battleStruct->GetLeader();
    GameObject* partyMember = battleStruct->GetPartyMemberByIndex(request->partyMemberId);
    CombatantMessageController* controller = MessageSystem_GetInstance();

    if (partyMember == NULL) {
        request->state = 2;
    }

    unsigned char state = request->state;
    if (state == 0) {
        if (unknownActor != NULL) {
            func_020531f0(unknownActor);
            GameObject_DisableControl((struct Obj020397cc*)unknownActor, 1);
        }
        func_02046380(controller);
        char* buf = controller->textBuffer;
#if defined(jpn)
        sprintf(buf, data_ov017_021d882c, (char*)partyMember->baseStats_);
        func_0204500c(controller, buf, 0);

#else
        sprintf(buf, (const char*)StandardStrings_Get(0x25));
        char localBuf[0xc];
        NameText_InitFromPartyMember(localBuf, request->partyMemberId);
        controller->substitutions = localBuf;
        func_0204500c(controller, buf, 0, 0xe3);

#endif
        controller->messageFlag = 0;
        controller->status = 1;
        request->state = 1;
        return;
    }
    if (state == 1) {
        if (controller->status == 0) {
            request->state = 2;
        }
        return;
    }
    if (state == 2) {
        GameObject_EnableControl(unknownActor);
        request->done = 1;
    }
}
