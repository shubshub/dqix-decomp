#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/CharacterCreationUI.h"
struct MessageController {
    SafeAllocator allocator;
    Container020e0310 messages;
    char unknown_1c_[0x10];
    int loadTask;
    short messageKey;
    short unknown_32_;
    char unknown34[3];
    unsigned char flags;
    signed char namedPartySlot;
};
struct Obj02046574 {
    void* combatant;
#if defined(jpn)
    char unknown4[0x868 - 4];
#else
    char pad4[0x998-4];
#endif
    int active;
#if defined(jpn)
    char unknown_86c_[0x1730 - 0x86c];
    int unknown_1730_;
    int unknown_1734_;
    char unknown_1738_[0x1789 - 0x1738];
#else
    char unknown_99c_[0x195b - 0x99c];
#endif
    unsigned char flags;
#if defined(jpn)
    char unknown_178a_[0x17e1 - 0x178a];
#else
    char unknown_195c_[0x19b1-0x195c];
#endif
    unsigned char state;
};
struct Struct_02092e0c_2 { int fields[3]; };
extern "C" Obj02046574* MessageSystem_GetInstance();
extern "C" void func_02046380(void*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" int KeyTable_Get(Container020e0310*, int);
#if !defined(jpn)
extern "C" void func_0204500c(Obj02046574*, int, int, int);
#endif
extern "C" void func_02042b98(Obj02046574*, int, int, int, int);
#if defined(jpn)
extern "C" void func_0204500c(Obj02046574*, int, int);
extern "C" void func_02043270(Obj02046574*, int, int, int, int);
#endif
// USA: func_02092e0c
extern "C" ARM void func_02092e0c(MessageController* messages) {
    if (messages->messageKey >= 0) {
        Obj02046574* display = MessageSystem_GetInstance();
        func_02046380(display);
        GameState* state = GameState::GetInstance();
        GameObject* member = state->GetPartyMemberByIndex(GameState_GetProtagonistIndex(state));
        if (member) MessageSystem_SetStringArgument(display, 0, member->baseStats_->name);
#if defined(jpn)
        member = state->GetPartyMemberByIndex(messages->namedPartySlot);
        if (member) MessageSystem_SetStringArgument(display, 1, member->baseStats_->name);
        func_0204500c(display, KeyTable_Get(&messages->messages, messages->messageKey), 0);
        display->active = 1;
        if ((messages->flags & 1) && (messages->flags & 2)) {
            display->state = 0;
            display->unknown_1730_ = 12;
            display->unknown_1734_ = 16;
            func_02043270(display, display->unknown_1730_, 0x90, 0x100, 0x30);
            display->flags |= 2;
        }
#else
        Struct_02092e0c_2 info;
        NameText_InitFromPartyMember(&info, messages->namedPartySlot);
        display->combatant = &info;
        func_0204500c(display, KeyTable_Get(&messages->messages, messages->messageKey), 0, 0xe3);
        display->active = 1;
        if ((messages->flags & 1) && (messages->flags & 2)) {
            display->state = 0;
            func_02042b98(display, 2, 0x92, 0xfc, 0x4a);
            display->flags |= 2;
        }
#endif
        messages->messageKey = -1;
        messages->unknown_32_ = 0x78;
    }
}
