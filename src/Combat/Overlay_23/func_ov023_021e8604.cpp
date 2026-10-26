#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

namespace {
struct Struct_ov023_021e8604 {
    unsigned char unknown0[0x4c];
    Container020e0310 messages;
    unsigned char unknown54[0x5d8 - 0x54];
    char* text;
};
}

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" int MessageSystem_GetInstance(void);

struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);

#if defined(jpn)
extern "C" void func_020474a8(void* messages, unsigned char font, const char* format, char* output);
#else
extern "C" void MessageSystem_FormatText(int a, int b, void* c, void* d, int e, int f, int g);
#endif

struct Combatant021e8604 { char pad[0xf74]; int val; };

// USA: func_ov023_021e8604
// JPN: func_ov023_021e8574
extern "C" ARM void func_ov023_021e8604(void* obj) {
    Struct_ov023_021e8604* state = static_cast<Struct_ov023_021e8604*>(obj);
    GameState* battleStruct = GameState::GetInstance();
    Combatant021e8604* combatant = static_cast<Combatant021e8604*>(GameState_GetParty(battleStruct));
    int field = MessageSystem_GetInstance();
    func_020465c0((struct StoreStruct*)field, 0, combatant->val);
    func_020465d8((unsigned char*)field, 0, 1);
    func_020465f0((unsigned char*)field, 0, 0xa);
    int key = KeyTable_Get(&state->messages, 2);
#if defined(jpn)
    func_020474a8(((void*)(field)), 0xa, ((const char*)(key)), state->text);
#else
    MessageSystem_FormatText(field, 0xa, ((void*)(key)), state->text, 0x100, 0, 0);
#endif
}
