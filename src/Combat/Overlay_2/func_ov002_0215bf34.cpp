#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { WindowOffset = 0xe20, TextOffset = 0x1a98, Enum_ov002_0215bf34_2400 = 0x800, Enum_ov002_0215bf34_41 = 44 };
#else
enum { WindowOffset = 0xec8, TextOffset = 0x1bd0, Enum_ov002_0215bf34_2400 = 0x960, Enum_ov002_0215bf34_41 = 41 };
#endif

namespace {
struct Struct_ov002_0215bf34 {
    unsigned char unknown0[WindowOffset];
    CreationWindow window;
    unsigned char unknown_f84_[TextOffset - WindowOffset - sizeof(CreationWindow)];
    char* text;
};

struct PartyResourceCounter {
    unsigned char unknown0[0xf6c];
    int value;
};
}

struct StoreStruct;
extern "C" int MessageSystem_GetInstance();
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" int StandardStrings_Get(int);
extern "C" void func_ov002_0215be00(void*, int, short, short);
extern "C" void func_02046380(void*);
extern "C" void Window_Update(void*, int);
#if defined(jpn)
extern const char data_ov002_0216d908[];
extern "C" void func_020474a8(void*, unsigned char, const char*, char*);
#else
extern "C" void MessageSystem_FormatText(void*, int, int, int, int, int, int);
#endif
extern "C" void Window_OpenPane(void*, const char*, int, unsigned char, unsigned char, unsigned char, void*
#if !defined(jpn)
                            , unsigned char
#endif
);

// USA: func_ov002_0215bf34
// JPN: func_ov002_0215d060
extern "C" ARM void func_ov002_0215bf34(char* base) {
    Struct_ov002_0215bf34* state = ((Struct_ov002_0215bf34*)(base));
    func_ov002_0215be00(state, Enum_ov002_0215bf34_41, 0x15, 0x15);

    PartyResourceCounter* party = static_cast<PartyResourceCounter*>(GameState_GetParty(GameState::GetInstance()));
    StoreStruct* messages = ((StoreStruct*)(MessageSystem_GetInstance()));
    func_02046380(messages);
    func_020465c0(messages, 0, party->value);
    unsigned char* var3 = ((unsigned char*)(messages));
    func_020465d8(var3, 0, 1);
    func_020465f0(var3, 0, 7);
    memset(state->text, 0, Enum_ov002_0215bf34_2400);
#if defined(jpn)
    func_020474a8(messages, 8, data_ov002_0216d908, state->text);
#else
    int format = StandardStrings_Get(0x3f1);
    MessageSystem_FormatText(messages, 8, format, ((int)(state->text)), 0x100, 0, 0);
#endif
    Window_OpenPane(&state->window, state->text, 0, 0, 0,
#if defined(jpn)
                 1, 0);
#else
                 0, 0, 0);
#endif
    Window_Update(&state->window, 4);
}
