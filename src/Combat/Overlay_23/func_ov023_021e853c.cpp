#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

namespace {
struct Struct_ov023_021e853c_2 {
    unsigned char unknown0[0x4c];
    Container020e0310 messages;
    unsigned char unknown54[0x5d8 - 0x54];
    char* text;
};
}

extern "C" int MessageSystem_GetInstance(void);
#if defined(jpn)
extern "C" int func_0204234c(char* dst, int a1);
#define func_02041cc0 func_0204234c
#else
extern "C" int func_02041cc0(char* dst, int a1);
#endif

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

struct Combatant021e853c { char pad[0xf68]; int f68; int f6c; };

// USA: func_ov023_021e853c
// JPN: func_ov023_021e84c0
extern "C" ARM void func_ov023_021e853c(void* obj) {
    Struct_ov023_021e853c_2* state = static_cast<Struct_ov023_021e853c_2*>(obj);
    Combatant021e853c* combatant = static_cast<Combatant021e853c*>(GameState_GetParty(GameState::GetInstance()));
    int field = MessageSystem_GetInstance();
    func_02041cc0(state->text, 0x18);
    int arr[2] = { combatant->f6c, combatant->f68 };
    for (int i = 0; i < 2; i++) {
        func_020465c0((struct StoreStruct*)field, i, arr[i]);
        func_020465d8((unsigned char*)field, i, 1);
        func_020465f0((unsigned char*)field, i, 0xa);
    }
    int key = KeyTable_Get(&state->messages, 1);
#if defined(jpn)
    func_020474a8(((void*)(field)), 0xa, ((const char*)(key)), state->text);
#else
    MessageSystem_FormatText(field, 0xa, ((void*)(key)), state->text, 0x100, 0, 0);
#endif
}

#if defined(jpn)
#undef func_02041cc0
#endif
