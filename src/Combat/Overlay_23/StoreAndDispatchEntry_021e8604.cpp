#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

namespace {
struct ProfileValueState {
    unsigned char unknown0[0x4c];
    Container020e0310 messages;
    unsigned char unknown54[0x5d8 - 0x54];
    char* text;
};
}

void* GameState_GetParty(GameState* battleStruct);
int MessageSystem_GetInstance(void);

struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);

#if defined(jpn)
extern "C" void func_020474a8(void* messages, unsigned char font, const char* format, char* output);
#else
extern "C" void MessageSystem_FormatText(int a, int b, void* c, void* d, int e, int f, int g);
#endif

struct Combatant021e8604 { char pad[0xf74]; int val; };

// USA: func_ov023_021e8604  (semantic: StoreAndDispatchEntry_021e8604)
// JPN: func_ov023_021e8574
extern "C" ARM void func_ov023_021e8604(void* obj) {
    ProfileValueState* state = static_cast<ProfileValueState*>(obj);
    GameState* battleStruct = GameState::GetInstance();
    Combatant021e8604* combatant = static_cast<Combatant021e8604*>(GameState_GetParty(battleStruct));
    int field = MessageSystem_GetInstance();
    StoreInArray0x8b0_020465c0((struct StoreStruct*)field, 0, combatant->val);
    SetByteAtIndex_020465d8((unsigned char*)field, 0, 1);
    SetByteInRange_020465f0((unsigned char*)field, 0, 0xa);
    int key = KeyTable_Get(&state->messages, 2);
#if defined(jpn)
    func_020474a8(((void*)(field)), 0xa, ((const char*)(key)), state->text);
#else
    MessageSystem_FormatText(field, 0xa, ((void*)(key)), state->text, 0x100, 0, 0);
#endif
}
