#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov017_021c3194_92 = 0x28, Enum_ov017_021c3194_6578 = 0x17e2, Enum_ov017_021c3194_2456 = 0x868 };
#else
enum { Enum_ov017_021c3194_92 = 0x5c, Enum_ov017_021c3194_6578 = 0x19b2, Enum_ov017_021c3194_2456 = 0x998 };
#endif

struct CombatantMessageController {
    char unknown0[0x10];
    void* unknown_10_;
    char unknown14[Enum_ov017_021c3194_92 - 0x14];
    char* textBuffer;
    char unknown_60_[Enum_ov017_021c3194_2456 - Enum_ov017_021c3194_92 - sizeof(char*)];
    int status;
    char unknown_99c_[Enum_ov017_021c3194_6578 - Enum_ov017_021c3194_2456 - sizeof(int)];
    unsigned char unknown_19b2_;
};

extern "C" CombatantMessageController* MessageSystem_GetInstance(void);
extern "C" void func_020531f0(void* obj);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" void func_02046380(void* obj);
extern "C" int StandardStrings_Get(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
#if !defined(jpn)
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
extern char data_ov017_021d882c[];
#endif
extern "C" void GameObject_EnableControl(void* obj);

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
        controller->unknown_10_ = localBuf;
        func_0204500c(controller, buf, 0, 0xe3);

#endif
        controller->unknown_19b2_ = 0;
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
