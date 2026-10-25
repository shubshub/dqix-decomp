#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/CharacterCreationUI.h"
struct Struct_02092e0c {
    SafeAllocator unknown_0_;
    Struct_0201099c_3 unknown_14_;
    char unknown_1c_[0x10];
    int unknown_2c_;
    short unknown_30_;
    short unknown_32_;
    char unknown_34_[3];
    unsigned char unknown_37_;
    signed char unknown_38_;
};
struct Struct_02046574_2 {
    void* unknown_0_;
#if defined(jpn)
    char unknown_4_[0x868 - 4];
#else
    char unknown1_4_[0x998-4];
#endif
    int unknown_998_;
#if defined(jpn)
    char unknown_86c_[0x1730 - 0x86c];
    int unknown_1730_;
    int unknown_1734_;
    char unknown_1738_[0x1789 - 0x1738];
#else
    char unknown_99c_[0x195b - 0x99c];
#endif
    unsigned char unknown_195b_;
#if defined(jpn)
    char unknown_178a_[0x17e1 - 0x178a];
#else
    char unknown_195c_[0x19b1-0x195c];
#endif
    unsigned char unknown_19b1_;
};
struct CombatantInfo02092e0c { int fields[3]; };
Obj02046574* MessageSystem_GetInstance();
extern "C" void func_02046380(void*);
int GameState_GetProtagonistIndex(GameState*);
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
void NameText_InitFromPartyMember(void*, int);
int KeyTable_Get(Container020e0310*, int);
#if !defined(jpn)
extern "C" void func_0204500c(Struct_02046574_2*, int, int, int);
#endif
extern "C" void func_02042b98(Struct_02046574_2*, int, int, int, int);
#if defined(jpn)
extern "C" void func_0204500c(Struct_02046574_2*, int, int);
extern "C" void func_02043270(Struct_02046574_2*, int, int, int, int);
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
            display->unknown1730 = 12;
            display->unknown1734 = 16;
            func_02043270(display, display->unknown1730, 0x90, 0x100, 0x30);
            display->flags |= 2;
        }
#else
        CombatantInfo02092e0c info;
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
        arg0->unknown_30_ = -1;
        arg0->unknown_32_ = 0x78;
    }
}
